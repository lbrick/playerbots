#include "playerbot/playerbot.h"
#include "NewRpgAction.h"

#define NEWRPG_LOG(...) do { if (!sPlayerbotAIConfig.logFilterPlayerBot) sLog.outDebug(__VA_ARGS__); } while(0)
#include "playerbot/strategy/rpg/NewRpgInfo.h"
#include "playerbot/BroadcastHelper.h"
#include "playerbot/TravelNode.h"
#include "MotionGenerators/MoveMap.h"
#include "Server/DBCStructure.h"
#include "Server/DBCStores.h"
#include "playerbot/ServerFacade.h"

using namespace ai;

// ─── NewRpgStatusUpdateAction ────────────────────────────────────────────────

bool NewRpgStatusUpdateAction::Execute(Event& /*event*/)
{
    CheckStuckTeleport();

    NewRpgInfo& info = ai->rpgInfo;
    info.statusUpdateTs = WorldTimer::getMSTime();
    NewRpgStatus status = info.GetStatus();

    if (info.abandonMoveFar)
    {
        info.abandonMoveFar = false;
        if (info.abandonStartT == info.startT && status != RPG_IDLE)
        {
            // A quest whose objective cannot be reached is not picked again this session.
            if (auto* quest = std::get_if<NewRpgInfo::DoQuest>(&info.data))
            {
                ai->lowPriorityQuest.insert(quest->questId);
                ai->rpgStatistic.questAbandoned++;
            }
            NEWRPG_LOG("[New RPG] %s gave up an unreachable move target", bot->GetName());
            info.tripEndReason = "stuck_abandoned";
            info.ChangeToIdle();
            return true;
        }
    }

    if (info.crossMapMoveFar)
    {
        info.crossMapMoveFar = false;
        if (info.crossMapStartT == info.startT && status != RPG_IDLE)
        {
            // The target is valid on the map the bot left, so a quest is not marked low priority.
            NEWRPG_LOG("[New RPG] %s dropped a move target on another map", bot->GetName());
            info.tripEndReason = "cross_map";
            info.ChangeToIdle();
            return true;
        }
    }

    // A need outranks grinding, camping, wandering and resting, not a quest or a trip (#86).
    if ((status == RPG_GO_GRIND || status == RPG_GO_CAMP || status == RPG_WANDER_RANDOM ||
         status == RPG_WANDER_NPC || status == RPG_REST) && TryStartErrand())
        return true;

    switch (status)
    {
        case RPG_IDLE:
            if (TryStartErrand())
                return true;
            return RandomChangeStatus({RPG_GO_CAMP, RPG_GO_GRIND, RPG_WANDER_RANDOM, RPG_WANDER_NPC,
                                       RPG_DO_QUEST, RPG_TRAVEL_FLIGHT, RPG_REST, RPG_CHANGE_ZONE,
                                       RPG_GATHER, RPG_EXPLORE});

        case RPG_GO_GRIND:
        {
            auto& data = std::get<NewRpgInfo::GoGrind>(info.data);
            if (WorldPosition(bot).distance(data.pos) < 10.0f)
            {
                info.ChangeToWanderRandom();
                return true;
            }
            break;
        }
        case RPG_GO_CAMP:
        {
            auto& data = std::get<NewRpgInfo::GoCamp>(info.data);
            if (WorldPosition(bot).distance(data.pos) < 10.0f)
            {
                info.ChangeToWanderNpc();
                return true;
            }
            break;
        }
        case RPG_WANDER_RANDOM:
        {
            if (info.HasStatusPersisted(statusWanderRandomDuration))
            {
                info.ChangeToIdle();
                return true;
            }
            break;
        }
        case RPG_WANDER_NPC:
        {
            if (info.HasStatusPersisted(statusWanderNpcDuration))
            {
                info.ChangeToIdle();
                return true;
            }
            break;
        }
        case RPG_DO_QUEST:
        {
            if (info.HasStatusPersisted(statusDoQuestDuration))
            {
                info.ChangeToIdle();
                return true;
            }
            break;
        }
        case RPG_TRAVEL_FLIGHT:
        {
            auto& data = std::get<NewRpgInfo::TravelFlight>(info.data);
            if (data.inFlight && !bot->IsTaxiFlying())
            {
                info.ChangeToIdle();
                return true;
            }
            break;
        }
        case RPG_ERRAND:
        {
            if (info.HasStatusPersisted(20 * MINUTE * IN_MILLISECONDS))
                return EndErrand("timeout");
            break;
        }
        case RPG_GATHER:
        {
            if (info.HasStatusPersisted(20 * MINUTE * IN_MILLISECONDS))
                return EndGather("timeout");
            break;
        }
        case RPG_EXPLORE:
        {
            auto& data = std::get<NewRpgInfo::Explore>(info.data);
            if (AreaDiscovered(data.areaId))
                return EndExplore("discovered");
            if (info.HasStatusPersisted(15 * MINUTE * IN_MILLISECONDS))
                return EndExplore("timeout");
            break;
        }
        case RPG_REST:
        {
            if (info.HasStatusPersisted(statusRestDuration))
            {
                info.ChangeToIdle();
                return true;
            }
            break;
        }
        case RPG_CHANGE_ZONE:
        {
            // Never end the trip on a transport: the bot would be left riding it (lbrick/cmangos-dev#51).
            if (bot->GetTransport())
                break;

            // The limit counts from the last completed waypoint or transport leg, so a long trip
            // that keeps moving is not cut short (lbrick/cmangos-dev#71).
            auto& data = std::get<NewRpgInfo::ChangeZone>(info.data);
            uint32 now = WorldTimer::getMSTime();

            // Closing 100 yards on the current waypoint (a transport leg's source dock) is progress
            // too: a long walk between two waypoints is not a stall (lbrick/cmangos-dev#83).
            if (!data.waypoints.empty() && !data.waypoints.front().spell)
            {
                auto const& front = data.waypoints.front();
                WorldPosition target = front.teleport && front.from != WorldPosition() ? front.from : front.pos;
                if (target.getMapId() == bot->GetMapId())
                {
                    float distance = WorldPosition(bot).distance(target);
                    if (target != data.progressTarget)
                    {
                        data.progressTarget = target;
                        data.progressDist = distance;
                    }
                    else if (distance + 100.0f < data.progressDist)
                    {
                        data.progressDist = distance;
                        data.progressT = now;
                    }
                }
            }

            if (WorldTimer::getMSTimeDiff(data.progressT, now) > 30 * 60 * 1000)
            {
                NEWRPG_LOG("[New RPG] %s CHANGE_ZONE timed out, returning to idle", bot->GetName());
                if (sPlayerbotAIConfig.logRpgTravelEvents)
                {
                    std::string detail = "trip_min=" + std::to_string(WorldTimer::getMSTimeDiff(info.startT, now) / 60000) +
                        " waypoints_left=" + std::to_string(data.waypoints.size());
                    LogTravelEvent("change_zone_timeout", WorldPosition(bot), data.dest, detail.c_str());
                }
                info.tripEndReason = "timeout";
                info.ChangeToIdle();
                return true;
            }
            break;
        }
        default:
            break;
    }
    return false;
}

// ─── NewRpgGoGrindAction ─────────────────────────────────────────────────────

bool NewRpgGoGrindAction::Execute(Event& /*event*/)
{
    if (SearchQuestGiverAndAcceptOrReward())
        return true;

    if (auto* data = std::get_if<NewRpgInfo::GoGrind>(&ai->rpgInfo.data))
    {
        if (MoveFarTo(data->pos))
            return true;
        return MoveRandomNear(10.0f);
    }

    return false;
}

// ─── NewRpgGoCampAction ──────────────────────────────────────────────────────

bool NewRpgGoCampAction::Execute(Event& /*event*/)
{
    if (SearchQuestGiverAndAcceptOrReward())
        return true;

    if (auto* data = std::get_if<NewRpgInfo::GoCamp>(&ai->rpgInfo.data))
    {
        if (MoveFarTo(data->pos))
            return true;
        return MoveRandomNear(10.0f);
    }

    return false;
}

// ─── NewRpgWanderRandomAction ────────────────────────────────────────────────

bool NewRpgWanderRandomAction::Execute(Event& /*event*/)
{
    if (SearchQuestGiverAndAcceptOrReward())
        return true;

    return MoveRandomNear();
}

// ─── NewRpgWanderNpcAction ───────────────────────────────────────────────────

bool NewRpgWanderNpcAction::Execute(Event& /*event*/)
{
    NewRpgInfo& info = ai->rpgInfo;
    auto* dataPtr = std::get_if<NewRpgInfo::WanderNpc>(&info.data);
    if (!dataPtr)
        return false;
    auto& data = *dataPtr;

    if (data.npcOrGo.IsEmpty())
    {
        ObjectGuid npcOrGo = ChooseNpcOrGoToInteract();
        if (npcOrGo.IsEmpty())
        {
            info.ChangeToIdle();
            return true;
        }
        data.npcOrGo = npcOrGo;
        data.lastReach = 0;
        return true;
    }

    WorldObject* object = bot->GetMap()->GetWorldObject(data.npcOrGo);
    if (object && bot->GetDistance(object) <= INTERACTION_DISTANCE)
    {
        if (!data.lastReach)
        {
            data.lastReach = WorldTimer::getMSTime();
            if (CanInteractWithQuestGiver(object))
                InteractWithNpcOrGoForQuest(data.npcOrGo);
            // Whatever else the NPC offers (repair, sale, training, a flight path, a chat) is the
            // legacy RPG sub-actions' to do (lbrick/cmangos-dev#85).
            HandOverToLegacyRpg(data.npcOrGo);
            return true;
        }

        if (WorldTimer::getMSTimeDiff(data.lastReach, WorldTimer::getMSTime()) < npcStayTime)
            return false;

        // stayed long enough — pick next target
        EndLegacyRpgHandOver();
        data.npcOrGo = ObjectGuid();
        data.lastReach = 0;
    }
    else
    {
        if (MoveWorldObjectTo(data.npcOrGo))
            return true;
        return MoveRandomNear(15.0f);
    }

    return true;
}

// ─── NewRpgGatherAction ──────────────────────────────────────────────────────

bool NewRpgGatherAction::Execute(Event& /*event*/)
{
    auto* g = std::get_if<NewRpgInfo::Gather>(&ai->rpgInfo.data);
    if (!g)
        return false;

    uint32 now = WorldTimer::getMSTime();
    WorldPosition here(bot);
    if (!g->arriveT)
    {
        if (here.getMapId() == g->pos.getMapId() && here.distance(g->pos) < 40.0f)
        {
            g->arriveT = now;
            return true;
        }
        WorldPosition target = g->pos;
        if (sServerFacade.isMoving(bot) || MoveFarTo(target))
            return true;
        return EndGather("no_path");
    }

    if (WorldTimer::getMSTimeDiff(g->arriveT, now) >= stayTime)
        return EndGather("done");

    // Roam the spot: the legacy gather and grind actions take any node or creature in sight.
    if (sServerFacade.isMoving(bot))
        return false;
    return MoveRandomNear(40.0f);
}

// ─── NewRpgExploreAction ─────────────────────────────────────────────────────

bool NewRpgExploreAction::Execute(Event& /*event*/)
{
    auto* e = std::get_if<NewRpgInfo::Explore>(&ai->rpgInfo.data);
    if (!e)
        return false;

    WorldPosition here(bot);
    if (here.getMapId() == e->pos.getMapId() && here.distance(e->pos) < 20.0f)
        return EndExplore(AreaDiscovered(e->areaId) ? "discovered" : "reached");

    WorldPosition target = e->pos;
    if (sServerFacade.isMoving(bot) || MoveFarTo(target))
        return true;
    return EndExplore("no_path");
}

// ─── NewRpgErrandAction ──────────────────────────────────────────────────────

bool NewRpgErrandAction::Execute(Event& /*event*/)
{
    auto* errand = std::get_if<NewRpgInfo::Errand>(&ai->rpgInfo.data);
    if (!errand)
        return false;

    uint32 now = WorldTimer::getMSTime();
    if (errand->reachT)
    {
        if (WorldTimer::getMSTimeDiff(errand->reachT, now) < npcVisitTime)
            return false;
        return EndErrand("done");
    }

    Creature* npc = errand->npc ? ai->GetCreature(errand->npc) : nullptr;
    if (!npc)
    {
        switch (MoveToward(errand->pos, 40.0f))
        {
            case MoveResult::Moving: return true;
            case MoveResult::Failed: return EndErrand("no_path");
            case MoveResult::Arrived: break;
        }

        npc = FindNearestNpc(errand->need == ERRAND_REPAIR ? UNIT_NPC_FLAG_REPAIR : UNIT_NPC_FLAG_VENDOR, errandNpcRange);
        if (!npc)
            return EndErrand("no_npc");
        errand->npc = npc->GetObjectGuid();
    }

    if (!npc->IsAlive())
        return EndErrand("no_npc");

    if (bot->GetDistance(npc) > INTERACTION_DISTANCE)
    {
        if (sServerFacade.isMoving(bot) || MoveWorldObjectTo(errand->npc))
            return true;
        return EndErrand("unreachable");
    }

    errand->reachT = now;
    bot->SetSelectionGuid(errand->npc);
    bot->SetFacingToObject(npc);
    // The legacy sub-action for the need first, then whatever else legacy RPG picks there (#85).
    SET_AI_VALUE(GuidPosition, "rpg target", GuidPosition(npc));
    char const* action = errand->need == ERRAND_REPAIR ? "rpg repair" : (errand->need == ERRAND_SELL ? "rpg sell" : "rpg buy");
    bool done = ai->DoSpecificAction(action, Event("new rpg"), true);
    if (sPlayerbotAIConfig.logRpgStatusEvents)
        sLog.outString("[New RPG status] bot=%s event=errand_action entry=%u action=%s done=%d",
            bot->GetName(), npc->GetEntry(), action, done ? 1 : 0);
    HandOverToLegacyRpg(errand->npc);
    return true;
}

// ─── NewRpgDoQuestAction ─────────────────────────────────────────────────────

bool NewRpgDoQuestAction::Execute(Event& /*event*/)
{
    if (SearchQuestGiverAndAcceptOrReward())
        return true;

    NewRpgInfo& info = ai->rpgInfo;
    auto* dataPtr = std::get_if<NewRpgInfo::DoQuest>(&info.data);
    if (!dataPtr)
        return false;
    auto& data = *dataPtr;

    uint32 questId = data.questId;
    QuestStatus questStatus = bot->GetQuestStatus(questId);
    switch (questStatus)
    {
        case QUEST_STATUS_INCOMPLETE:
            return DoIncompleteQuest(data);
        case QUEST_STATUS_COMPLETE:
            return DoCompletedQuest(data);
        default:
            break;
    }
    info.ChangeToIdle();
    return true;
}

bool NewRpgDoQuestAction::DoIncompleteQuest(NewRpgInfo::DoQuest& data)
{
    uint32 questId = data.questId;
    if (data.pos != WorldPosition())
    {
        int32 currentObjective = data.objectiveIdx;
        Quest const* quest = sObjectMgr.GetQuestTemplate(questId);
        const QuestStatusData& q_status = bot->getQuestStatusMap().at(questId);
        bool completed = true;
        if (currentObjective < QUEST_OBJECTIVES_COUNT)
        {
            if (q_status.m_creatureOrGOcount[currentObjective] < quest->ReqCreatureOrGOCount[currentObjective])
                completed = false;
        }
        else if (currentObjective < QUEST_OBJECTIVES_COUNT + QUEST_ITEM_OBJECTIVES_COUNT)
        {
            int32 itemIdx = currentObjective - QUEST_OBJECTIVES_COUNT;
            if (q_status.m_itemcount[itemIdx] < quest->ReqItemCount[itemIdx])
                completed = false;
        }
        if (completed)
        {
            data.lastReachPOI = 0;
            data.pos = WorldPosition();
            data.objectiveIdx = 0;
        }
    }

    if (data.pos == WorldPosition())
    {
        WorldPosition poiPos;
        int32 objectiveIdx = 0;
        if (!GetQuestPOIPosAndObjectiveIdx(questId, poiPos, objectiveIdx))
        {
            // No travel destination for this quest — mark low priority so it won't be
            // re-selected or re-accepted until the bot resets (e.g. logs out).
            ai->lowPriorityQuest.insert(questId);
            ai->rpgStatistic.questAbandoned++;
            NEWRPG_LOG("[New RPG] %s no POI for quest %u, marked low priority", bot->GetName(), questId);
            ai->rpgInfo.ChangeToIdle();
            return true;
        }
        data.lastReachPOI = 0;
        data.pos = poiPos;
        data.objectiveIdx = objectiveIdx;
    }

    if (WorldPosition(bot).distance(data.pos) > 10.0f && !data.lastReachPOI)
    {
        if (MoveFarTo(data.pos))
            return true;
        return MoveRandomNear(10.0f);
    }

    if (!data.lastReachPOI)
    {
        data.lastReachPOI = WorldTimer::getMSTime();
        return true;
    }

    if (WorldTimer::getMSTimeDiff(data.lastReachPOI, WorldTimer::getMSTime()) >= poiStayTime)
    {
        bool hasProgression = false;
        int32 currentObjective = data.objectiveIdx;
        Quest const* quest = sObjectMgr.GetQuestTemplate(questId);
        const QuestStatusData& q_status = bot->getQuestStatusMap().at(questId);
        if (currentObjective < QUEST_OBJECTIVES_COUNT)
        {
            if (q_status.m_creatureOrGOcount[currentObjective] != 0 && quest->ReqCreatureOrGOCount[currentObjective])
                hasProgression = true;
        }
        else if (currentObjective < QUEST_OBJECTIVES_COUNT + QUEST_ITEM_OBJECTIVES_COUNT)
        {
            int32 itemIdx = currentObjective - QUEST_OBJECTIVES_COUNT;
            if (q_status.m_itemcount[itemIdx] != 0 && quest->ReqItemCount[itemIdx])
                hasProgression = true;
        }
        if (!hasProgression)
        {
            ai->lowPriorityQuest.insert(questId);
            ai->rpgStatistic.questAbandoned++;
            NEWRPG_LOG("[New RPG] %s marked as abandoned quest %u", bot->GetName(), questId);
            ai->rpgInfo.ChangeToIdle();
            return true;
        }
        data.lastReachPOI = 0;
        data.pos = WorldPosition();
        data.objectiveIdx = 0;
        return true;
    }

    return MoveRandomNear(8.0f);
}

bool NewRpgDoQuestAction::DoCompletedQuest(NewRpgInfo::DoQuest& data)
{
    uint32 questId = data.questId;

    if (data.objectiveIdx != -1)
    {
        BroadcastHelper::BroadcastQuestUpdateComplete(ai, bot, data.quest);
        ai->rpgStatistic.questCompleted++;

        WorldPosition poiPos;
        int32 objectiveIdx = 0;
        if (!GetQuestPOIPosAndObjectiveIdx(questId, poiPos, objectiveIdx))
        {
            ai->rpgInfo.ChangeToIdle();
            return false;
        }
        data.lastReachPOI = 0;
        data.pos = poiPos;
        data.objectiveIdx = -1;
    }

    if (data.pos == WorldPosition())
        return false;

    if (WorldPosition(bot).distance(data.pos) > 10.0f && !data.lastReachPOI)
    {
        if (MoveFarTo(data.pos))
            return true;
        return MoveRandomNear(10.0f);
    }

    if (!data.lastReachPOI)
    {
        data.lastReachPOI = WorldTimer::getMSTime();
        return true;
    }

    if (WorldTimer::getMSTimeDiff(data.lastReachPOI, WorldTimer::getMSTime()) >= poiStayTime)
    {
        ai->lowPriorityQuest.insert(questId);
        ai->rpgStatistic.questAbandoned++;
        NEWRPG_LOG("[New RPG] %s marked as abandoned quest (reward) %u", bot->GetName(), questId);
        ai->rpgInfo.ChangeToIdle();
        return true;
    }
    return false;
}

// ─── NewRpgTravelFlightAction ────────────────────────────────────────────────

bool NewRpgTravelFlightAction::Execute(Event& /*event*/)
{
    NewRpgInfo& info = ai->rpgInfo;
    auto* dataPtr = std::get_if<NewRpgInfo::TravelFlight>(&info.data);
    if (!dataPtr)
        return false;

    auto& data = *dataPtr;
    if (bot->IsTaxiFlying())
    {
        data.inFlight = true;
        return false;
    }

    Creature* flightMaster = bot->GetMap()->GetCreature(data.fromFlightMaster);
    if (!flightMaster || !flightMaster->IsAlive())
    {
        ai->rpgInfo.ChangeToIdle();
        return true;
    }

    if (bot->GetDistance(flightMaster) > INTERACTION_DISTANCE)
        return MoveFarTo(WorldPosition(flightMaster));

    std::vector<uint32> nodes = data.path;

    ai->RemoveShapeshift();
    if (bot->IsMounted())
        bot->Unmount();

    if (!bot->ActivateTaxiPathTo(nodes, flightMaster, 0))
    {
        NEWRPG_LOG("[New RPG] %s activate taxi path (from node %u to %u) failed",
                      bot->GetName(), nodes.empty() ? 0 : nodes[0],
                      nodes.empty() ? 0 : nodes[nodes.size() - 1]);
        ai->rpgInfo.ChangeToIdle();
    }
    return true;
}

// ─── NewRpgGoChangeZoneAction ─────────────────────────────────────────────────

bool NewRpgGoChangeZoneAction::Execute(Event& /*event*/)
{
    auto* dataPtr = std::get_if<NewRpgInfo::ChangeZone>(&ai->rpgInfo.data);
    if (!dataPtr)
        return false;

    WorldPosition dest = dataPtr->dest;
    float dist = WorldPosition(bot).distance(dest);
    NEWRPG_LOG("[New RPG] %s change zone action: dist=%.1f to Map:%u %.1f %.1f %.1f",
                  bot->GetName(), dist, dest.getMapId(), dest.getX(), dest.getY(), dest.getZ());

    if (dist < 50.0f)
    {
        uint32 newZone = bot->GetZoneId();
        std::vector<uint32> toRemove;
        for (uint32 qId : ai->lowPriorityQuest)
        {
            Quest const* q = sObjectMgr.GetQuestTemplate(qId);
            if (!q) continue;
            int32 zoneSort = q->GetZoneOrSort();
            if (zoneSort <= 0 || (uint32)zoneSort == newZone)
                toRemove.push_back(qId);
        }
        for (uint32 qId : toRemove)
            ai->lowPriorityQuest.erase(qId);

        NEWRPG_LOG("[New RPG] %s arrived zone %u, cleared %zu lowPriorityQuest entries",
                      bot->GetName(), newZone, toRemove.size());
        if (sPlayerbotAIConfig.logRpgTravelEvents)
        {
            std::string zone = "zone=" + std::to_string(newZone);
            LogTravelEvent("zone_arrived", WorldPosition(bot), dest, zone.c_str());
        }

        // Reset per-stay bad count for the new zone (7.1)
        ai->currentStayZoneId = newZone;
        ai->currentStayBadCount = 0;

        // Learn nearby taxi nodes on zone arrival (7.5)
        WorldPosition botPos(bot);
        for (uint32 i = 1; i < sTaxiNodesStore.GetNumRows(); ++i)
        {
            TaxiNodesEntry const* node = sTaxiNodesStore.LookupEntry(i);
            if (!node || node->map_id != bot->GetMapId())
                continue;
            WorldPosition nodePos(node->map_id, node->x, node->y, node->z);
            if (botPos.distance(nodePos) > 500.0f)
                continue;
            if (!bot->m_taxi.IsTaximaskNodeKnown(i))
            {
                bot->m_taxi.SetTaximaskNode(i);
                NEWRPG_LOG("[New RPG] %s learned taxi node %u on arrival zone %u",
                              bot->GetName(), i, newZone);
            }
        }

        ai->zoneScoreCache = {};
        ai->rpgInfo.tripEndReason = "arrived";
        ai->rpgInfo.ChangeToIdle();
        return true;
    }

    // Another action (unstuck, a group invitation, a summon) moved the bot to another map mid-trip.
    // The next waypoint lies on the map it left, so the cross-map check would drop the trip; rebuild
    // the route from here instead, at most three times a trip (lbrick/cmangos-dev#83).
    if (!dataPtr->waypoints.empty() && !dataPtr->waypoints.front().spell && dataPtr->reroutes < 3)
    {
        auto const& front = dataPtr->waypoints.front();
        WorldPosition next = front.teleport && front.from != WorldPosition() ? front.from : front.pos;
        if (next.getMapId() != bot->GetMapId())
        {
            ++dataPtr->reroutes;
            if (sPlayerbotAIConfig.logRpgTravelEvents)
            {
                std::string detail = "reason=moved_map reroutes=" + std::to_string(dataPtr->reroutes);
                LogTravelEvent("route_rebuilt", WorldPosition(bot), next, detail.c_str());
            }
            dataPtr->waypoints.clear();
            dataPtr->waypointsBuilt = false;
            dataPtr->progressT = WorldTimer::getMSTime();
            ai->rpgInfo.SetMoveFarTo(WorldPosition());
            return true;
        }
    }

    // 5.2 — mount up when far from dest
    // Not while a teleport-spell leg is next: mounting would interrupt the cast (#76).
    bool castLegNext = !dataPtr->waypoints.empty() && dataPtr->waypoints.front().spell;
    if (dist > 50.0f && !castLegNext)
        TryMount();

    // Populate TravelNode waypoints once when not near dest (no rebuild — prevents bad node re-entry)
    // BUG-1: reduced from 500→150 yards — bots at 150-500 now get TravelNode route built instead
    // of falling through to direct MoveFarTo, which caused looping at up to 479-yard distances
    if (!dataPtr->waypointsBuilt && dist > 150.0f)
    {
        dataPtr->waypointsBuilt = true;
        std::vector<WorldPosition> startPath, endPath;
        TravelNodeRoute route = sTravelNodeMap.getRoute(WorldPosition(bot), dest, startPath, endPath, bot, !dataPtr->noTeleportSpells);
        std::vector<TravelNode*>& nodes = route.getNodes();
        if (!nodes.empty())
        {
            for (const WorldPosition& bad : ai->badPositions)
                NEWRPG_LOG("[New RPG] %s badPos (%.1f %.1f %.1f mapId=%u)",
                              bot->GetName(), bad.getX(), bad.getY(), bad.getZ(), bad.getMapId());

            // The map of the route segment being walked: the bot's map until a transport leg
            // crosses to another one (lbrick/cmangos-dev#67).
            uint32 segmentMapId = bot->GetMapId();
            for (size_t i = 0; i < nodes.size(); ++i)
            {
                TravelNode* node = nodes[i];
                WorldPosition nodePos = *node->getPosition();
                NEWRPG_LOG("[New RPG] %s TravelNode candidate (%.1f %.1f %.1f mapId=%u)",
                              bot->GetName(), nodePos.getX(), nodePos.getY(), nodePos.getZ(), nodePos.getMapId());

                // BOAT-3: detect a teleport link to the next node: a transport (boat, zeppelin,
                // elevator) or an area trigger (a portal such as Darnassus -> Rut'theran). Bots
                // never fire area triggers by walking into them, so both become teleport legs.
                // Area triggers into instanceable maps (dungeon entrances) stay walk links.
                auto isTransportLink = [](TravelNode* from, TravelNode* to)
                {
                    auto* links = from->getLinks();
                    auto linkIt = links->find(to);
                    if (linkIt == links->end())
                        return false;
                    TravelNodePathType type = linkIt->second->getPathType();
                    if (type == TravelNodePathType::transport)
                        return true;
                    if (type != TravelNodePathType::areaTrigger)
                        return false;
                    MapEntry const* mapEntry = sMapStore.LookupEntry(to->getPosition()->getMapId());
                    return mapEntry && !mapEntry->Instanceable();
                };
                TravelNode* nextNode = (i + 1 < nodes.size()) ? nodes[i + 1] : nullptr;
                bool isTransportLeg = nextNode && isTransportLink(node, nextNode);

                // A teleport-spell link (hearthstone, class teleport) is a leg the bot completes by
                // casting the spell where it stands. Walked, it relabelled the nodes after it with
                // the bot's map and dropped the trip at the next cross-map walk (#76).
                if (nextNode && !isTransportLeg)
                {
                    auto linkIt = node->getLinks()->find(nextNode);
                    if (linkIt != node->getLinks()->end() &&
                        linkIt->second->getPathType() == TravelNodePathType::teleportSpell &&
                        linkIt->second->getPathObject())
                    {
                        WorldPosition landPos = *nextNode->getPosition();
                        NewRpgInfo::ChangeZone::Waypoint leg{landPos, true, nodePos};
                        leg.spell = uint32(linkIt->second->getPathObject());
                        dataPtr->waypoints.push_back(leg);
                        std::string detail = "spell=" + std::to_string(leg.spell);
                        LogTravelEvent("spell_leg_built", nodePos, landPos, detail.c_str());
                        segmentMapId = landPos.getMapId();
                        ++i;  // the landing node is the leg's end
                        continue;
                    }
                }

                // Links the waypoints walk across although they are not walks: flight paths,
                // teleport spells such as the hearthstone, and map changes (lbrick/cmangos-dev#76).
                if (nextNode && !isTransportLeg && sPlayerbotAIConfig.logRpgTravelEvents)
                {
                    auto linkIt = node->getLinks()->find(nextNode);
                    bool hasLink = linkIt != node->getLinks()->end();
                    uint32 type = hasLink ? uint32(linkIt->second->getPathType()) : 0;
                    WorldPosition nextPos = *nextNode->getPosition();
                    if (type != uint32(TravelNodePathType::walk) || nextPos.getMapId() != nodePos.getMapId())
                    {
                        std::string detail = "type=" + std::to_string(type) +
                            " object=" + std::to_string(hasLink ? linkIt->second->getPathObject() : 0) +
                            " segment_map=" + std::to_string(segmentMapId) + " index=" + std::to_string(i) +
                            " nodes=" + std::to_string(nodes.size());
                        LogTravelEvent("route_link", nodePos, nextPos, detail.c_str());
                    }
                }

                if (!isTransportLeg)
                {
                    // Normal node: normalize mapId to the segment's map, then coordinate sanity +
                    // IsPosBad + isMmapLoaded.
                    // No absolute height bound: real terrain runs from below Z 0 (Thousand Needles,
                    // Undercity) to above Z 1,300 (Teldrassil). Unreachable nodes are caught by
                    // isMmapLoaded and by stuck recovery, which marks the target bad.
                    nodePos.setMapId(segmentMapId);
                    if (!nodePos.isValid())
                    {
                        NEWRPG_LOG("[New RPG] %s TravelNode candidate filtered (invalid coordinates Z %.1f)",
                                      bot->GetName(), nodePos.getZ());
                        continue;
                    }
                    if (IsPosBad(nodePos))
                    {
                        NEWRPG_LOG("[New RPG] %s TravelNode candidate filtered (IsPosBad after mapId normalize to %u)",
                                      bot->GetName(), bot->GetMapId());
                        continue;
                    }
                    if (!nodePos.isMmapLoaded(0))
                        continue;
                    dataPtr->waypoints.push_back({nodePos, false});
                }
                else
                {
                    // Transport leg: preserve real mapId, skip mmap check (dock at water/air level)
                    if (IsPosBad(nodePos)) continue;

                    // TRANSPORT-1/2: validate dest dock before committing — reject bad DB nodes
                    // Only a sea-level end on the main world (Z~0, a boat stop) is bad.
                    // Underground elevator docks (Z~-40) are legitimate and must pass through.
                    if (nextNode)
                    {
                        // A crossing is a chain of transport links: in the travel-node data a boat
                        // route runs dock -> boat -> boat -> dock, where the boat nodes are the
                        // transport's stop positions at sea level (TaxiPathNode). Walk to the first
                        // node of the chain and teleport to the last one, never to a boat node.
                        size_t last = i + 1;
                        while (last + 1 < nodes.size() && isTransportLink(nodes[last], nodes[last + 1]))
                            ++last;
                        WorldPosition destDock = *nodes[last]->getPosition();

                        // BUG-2: skip previously rejected destDocks (persists across waypoint rebuilds)
                        bool alreadyRejected = false;
                        for (const auto& rej : dataPtr->rejectedTransportDocks)
                            if (rej.distance(destDock) < 1.0f) { alreadyRejected = true; break; }
                        if (alreadyRejected)
                        {
                            segmentMapId = destDock.getMapId();
                            i = last;
                            continue;
                        }

                        bool onMainWorld = (destDock.getMapId() == 0 || destDock.getMapId() == 1);
                        // Only a sea-level end on the main world is bad (a boat stop, #35); high
                        // ends such as the Darnassus portal exit (Z 1,316) are real.
                        bool badDest = !destDock.isValid() ||
                                       (onMainWorld && destDock.getZ() > -5.0f && destDock.getZ() < 2.0f);
                        if (badDest)
                        {
                            NEWRPG_LOG("[New RPG] %s TravelNode transport dest dock invalid Z=%.1f (%.1f %.1f map=%u) — skipping leg",
                                          bot->GetName(), destDock.getZ(), destDock.getX(), destDock.getY(), destDock.getMapId());
                            LogTravelEvent("leg_rejected", nodePos, destDock, "reason=dest_z");
                            dataPtr->rejectedTransportDocks.push_back(destDock);  // BUG-2: cache rejection
                            segmentMapId = destDock.getMapId();
                            i = last;  // consume the rest of the chain
                            continue;
                        }

                        bool isElevator = (destDock.getZ() < -5.0f);
                        dataPtr->waypoints.push_back({nodePos, false});

                        // The chain is dock -> stop -> ... -> stop -> dock. The stop-to-stop links
                        // carry the transport GO entry; a portal chain has no stops and no entry.
                        NewRpgInfo::ChangeZone::Waypoint leg{destDock, true, nodePos};
                        for (size_t j = i + 1; j + 1 < last; ++j)
                        {
                            auto linkIt = nodes[j]->getLinks()->find(nodes[j + 1]);
                            if (linkIt != nodes[j]->getLinks()->end() && linkIt->second->getPathObject())
                            {
                                leg.transportEntry = uint32(linkIt->second->getPathObject());
                                leg.boardStop = *nodes[i + 1]->getPosition();
                                leg.alightStop = *nodes[last - 1]->getPosition();
                                break;
                            }
                        }
                        if (isElevator)
                            NEWRPG_LOG("[New RPG] %s elevator route: walking to lift at (%.1f %.1f %.1f map=%u)",
                                          bot->GetName(), nodePos.getX(), nodePos.getY(), nodePos.getZ(), nodePos.getMapId());
                        else
                            NEWRPG_LOG("[New RPG] %s TravelNode transport source dock (%.1f %.1f %.1f map=%u)",
                                          bot->GetName(), nodePos.getX(), nodePos.getY(), nodePos.getZ(), nodePos.getMapId());
                        dataPtr->waypoints.push_back(leg);
                        LogTravelEvent("leg_built", nodePos, destDock, leg.transportEntry ? ("entry=" + std::to_string(leg.transportEntry)).c_str() : "");
                        segmentMapId = destDock.getMapId();
                        if (isElevator)
                            NEWRPG_LOG("[New RPG] %s elevator route: dest platform (%.1f %.1f %.1f map=%u) [teleport]",
                                          bot->GetName(), destDock.getX(), destDock.getY(), destDock.getZ(), destDock.getMapId());
                        else
                            NEWRPG_LOG("[New RPG] %s TravelNode transport dest dock (%.1f %.1f %.1f map=%u) [teleport]",
                                          bot->GetName(), destDock.getX(), destDock.getY(), destDock.getZ(), destDock.getMapId());
                        i = last;
                    }
                }
            }
            dataPtr->waypoints.push_back({dest, false});
            NEWRPG_LOG("[New RPG] %s CHANGE_ZONE built %zu waypoints via TravelNode",
                          bot->GetName(), dataPtr->waypoints.size());
        }
        // The waypoints hold copies of the node positions; free the route's portal nodes.
        route.cleanTempNodes();
    }

    // Prune waypoints that became bad since list was built.
    // Normalize mapId before IsPosBad — TravelNode waypoints may carry different mapId
    // than what stuck-teleport wrote into badPositions (7.3.2 fix).
    // Skip teleport waypoints — they have valid cross-map mapIds by design.
    while (!dataPtr->waypoints.empty())
    {
        auto& front = dataPtr->waypoints.front();
        if (front.teleport)
            break;
        WorldPosition check = front.pos;
        check.setMapId(bot->GetMapId());
        if (!IsPosBad(check))
            break;
        dataPtr->waypoints.erase(dataPtr->waypoints.begin());
    }

    // 8.3 BUG-C guard: if waypoints were built but fully pruned, reset to rebuild next tick
    if (dataPtr->waypoints.empty() && dataPtr->waypointsBuilt)
    {
        dataPtr->waypointsBuilt = false;
        NEWRPG_LOG("[New RPG] %s CHANGE_ZONE waypoints empty after prune — resetting to rebuild",
                      bot->GetName());
        return false;
    }

    if (!dataPtr->waypoints.empty())
    {
        auto& front = dataPtr->waypoints.front();
        WorldPosition& wp = front.pos;

        // Teleport-spell leg: cast the spell where the bot stands, then wait for the teleport.
        // A spell that cannot be cast, or a cast that does not move the bot, rebuilds the route
        // without teleport spells (lbrick/cmangos-dev#76).
        if (front.teleport && front.spell)
        {
            uint32 now = WorldTimer::getMSTime();
            WorldPosition here(bot);
            std::string detail = "spell=" + std::to_string(front.spell) + " tries=" + std::to_string(front.castTries);
            if (here.getMapId() == wp.getMapId() && here.distance(wp) < 60.0f)
            {
                LogTravelEvent("spell_teleport_arrived", here, wp, detail.c_str());
                dataPtr->progressT = now;
                dataPtr->waypoints.erase(dataPtr->waypoints.begin());
                ai->rpgInfo.SetMoveFarTo(WorldPosition());
                return true;
            }

            if (bot->IsBeingTeleported() || bot->IsNonMeleeSpellCasted(true))
                return true;
            if (front.castT && WorldTimer::getMSTimeDiff(front.castT, now) < 15 * IN_MILLISECONDS)
                return true;

            bool cast = false;
            if (front.castTries < 2)
            {
                if (front.spell == 8690)
                {
                    if (AI_VALUE2(bool, "action useful", "hearthstone"))
                        cast = ai->DoSpecificAction("hearthstone", Event("new rpg go change zone"), true);
                }
                else if (sServerFacade.IsSpellReady(bot, front.spell) && AI_VALUE2(uint32, "has reagents for", front.spell) > 0)
                {
                    if (AI_VALUE2(uint32, "current mount speed", "self target"))
                        ai->Unmount();
                    ai->RemoveShapeshift();
                    cast = ai->DoSpecificAction("cast", Event("rpg action", chat->formatWorldobject(bot) + " " + std::to_string(front.spell)), true);
                }
            }

            if (cast)
            {
                front.castT = now;
                ++front.castTries;
                detail = "spell=" + std::to_string(front.spell) + " tries=" + std::to_string(front.castTries);
                LogTravelEvent("spell_teleport_cast", here, wp, detail.c_str());
                return true;
            }

            LogTravelEvent("spell_teleport_failed", here, wp, detail.c_str());
            dataPtr->noTeleportSpells = true;
            dataPtr->waypoints.clear();
            dataPtr->waypointsBuilt = false;
            ai->rpgInfo.SetMoveFarTo(WorldPosition());
            return true;
        }

        // BOAT-4: transport teleport handler — walk to source dock, then TeleportTo dest dock
        if (front.teleport)
        {
            // The source dock, not the destination: the destination is across the water or on
            // another map, so a bot measured against it would walk toward it and never teleport.
            WorldPosition sourceDock = front.from != WorldPosition() ? front.from : wp;

            // Under TransportTeleportType 0 or 1 the bot rides the transport as a passenger
            // (lbrick/cmangos-dev#51); mode 2 keeps the dock-to-dock teleport below.
            bool ride = sPlayerbotAIConfig.transportTeleportType < 2 && front.transportEntry;
            bool doTeleport = sPlayerbotAIConfig.transportTeleportType > 0;
            std::string entryDetail = "entry=" + std::to_string(front.transportEntry);

            if (ride && bot->GetTransport())
            {
                // Riding: step off once the transport reaches the destination stop.
                if (!UseTransport(ai, front.transportEntry, front.alightStop, wp, doTeleport) || bot->GetTransport())
                    return true;

                LogTravelEvent("transport_disembarked", WorldPosition(bot), wp, entryDetail.c_str());
                dataPtr->progressT = WorldTimer::getMSTime();
                dataPtr->waypoints.erase(dataPtr->waypoints.begin());
                ai->rpgInfo.SetMoveFarTo(WorldPosition());
                return true;
            }

            float distToDock = WorldPosition(bot).distance(sourceDock);
            if (distToDock > 20.0f)
                return MoveFarTo(sourceDock);

            // TRANSPORT-1/2: second-layer guard — reject bad sea-level docks (Z~0 on main world)
            // Elevator docks (Z~-40) are legitimate and must pass through
            bool onMainWorld = (wp.getMapId() == 0 || wp.getMapId() == 1);
            if (!wp.isValid() || (onMainWorld && wp.getZ() > -5.0f && wp.getZ() < 2.0f))
            {
                NEWRPG_LOG("[New RPG] %s transport teleport dest invalid Z=%.1f (%.1f %.1f map=%u) — resetting",
                              bot->GetName(), wp.getZ(), wp.getX(), wp.getY(), wp.getMapId());
                LogTravelEvent("teleport_rejected", WorldPosition(bot), wp, "reason=dest_z");
                dataPtr->waypoints.erase(dataPtr->waypoints.begin());
                ai->rpgInfo.tripEndReason = "teleport_rejected";
                ai->rpgInfo.Reset();
                return false;
            }

            if (ride)
            {
                // At the dock: wait for the transport and board it. After 10 minutes without
                // boarding, fall back to the teleport so the bot never strands at a pier.
                uint32 now = WorldTimer::getMSTime();
                if (!front.waitStartT)
                {
                    // Reaching the dock is progress; the wait and the ride must not use up the limit.
                    front.waitStartT = now;
                    dataPtr->progressT = now;
                    LogTravelEvent("transport_waiting", WorldPosition(bot), wp, entryDetail.c_str());
                }

                uint32 waited = WorldTimer::getMSTimeDiff(front.waitStartT, now);
                if (waited <= 10 * MINUTE * IN_MILLISECONDS)
                {
                    if (UseTransport(ai, front.transportEntry, front.boardStop, wp, doTeleport) && bot->GetTransport())
                        LogTravelEvent("transport_boarded", WorldPosition(bot), wp, entryDetail.c_str());
                    return true;
                }

                std::string detail = entryDetail + " waited_s=" + std::to_string(waited / IN_MILLISECONDS);
                LogTravelEvent("transport_fallback", WorldPosition(bot), wp, detail.c_str());
            }

            bool isElevator = (wp.getZ() < -5.0f);
            if (isElevator)
                NEWRPG_LOG("[New RPG] %s elevator teleport to platform (%.1f %.1f %.1f map=%u)",
                              bot->GetName(), wp.getX(), wp.getY(), wp.getZ(), wp.getMapId());
            else
                NEWRPG_LOG("[New RPG] %s transport teleport to (%.1f %.1f %.1f map=%u)",
                              bot->GetName(), wp.getX(), wp.getY(), wp.getZ(), wp.getMapId());
            LogTravelEvent("teleported", WorldPosition(bot), wp);
            dataPtr->progressT = WorldTimer::getMSTime();
            // wp refers into waypoints, so copy the destination dock before the erase.
            WorldPosition destDock = wp;
            // HandleTeleportAck logs where the bot lands (lbrick/cmangos-dev#79).
            if (sPlayerbotAIConfig.logRpgTravelEvents)
                ai->rpgInfo.legTeleportTo = destDock;
            dataPtr->waypoints.erase(dataPtr->waypoints.begin());
            ai->rpgInfo.SetMoveFarTo(WorldPosition());
            bool teleported = bot->TeleportTo(destDock.getMapId(), destDock.getX(), destDock.getY(), destDock.getZ(), bot->GetOrientation());
            if (!teleported)
                ai->rpgInfo.legTeleportTo = WorldPosition();
            return teleported;
        }

        if (WorldPosition(bot).distance(wp) < 30.0f)
        {
            dataPtr->progressT = WorldTimer::getMSTime();
            // wp refers to the erased element, so read the next target only after the erase.
            dataPtr->waypoints.erase(dataPtr->waypoints.begin());
            WorldPosition next = dataPtr->waypoints.empty() ? dest : dataPtr->waypoints.front().pos;
            std::string detail = "waypoints_left=" + std::to_string(dataPtr->waypoints.size());
            LogTravelEvent("waypoint_reached", WorldPosition(bot), next, detail.c_str());
            return true;
        }
        // A failed stuck teleport inside MoveFarTo has already erased this waypoint; erase it
        // here only if it is still at the front, so the trip does not skip the next one (#79).
        WorldPosition target = wp;
        if (MoveFarTo(target))
            return true;
        if (!dataPtr->waypoints.empty() && dataPtr->waypoints.front().pos.getMapId() == target.getMapId() &&
            dataPtr->waypoints.front().pos.fDist(target) < 0.1f)
            dataPtr->waypoints.erase(dataPtr->waypoints.begin());
        return true;
    }

    // BUG-E: if dest itself is bad (short-dist path, no waypoints built), reset to IDLE
    if (IsPosBad(dest))
    {
        NEWRPG_LOG("[New RPG] %s CHANGE_ZONE dest is bad — resetting to IDLE", bot->GetName());
        ai->rpgInfo.tripEndReason = "dest_bad";
        ai->rpgInfo.Reset();
        return false;
    }

    if (MoveFarTo(dest))
        return true;

    return MoveRandomNear(10.0f);
}

// ─── NewRpgPostQuestAction ───────────────────────────────────────────────────

bool NewRpgPostQuestAction::Execute(Event& /*event*/)
{
    NewRpgInfo::PostQuest& pq = ai->rpgInfo.postQuest;
    if (pq.kind == NewRpgInfo::PostQuest::NONE)
        return false;

    uint32 now = WorldTimer::getMSTime();
    // A bot that fell to minimal activity skips this action until it is active again; the gap is
    // not time spent in the routine, so end it rather than report it as a timeout.
    if (WorldTimer::getMSTimeDiff(pq.lastT, now) > pq.lastWait + postQuestStallTime)
        return EndPostQuest("inactive");
    if (WorldTimer::getMSTimeDiff(pq.startT, now) >= postQuestMaxTime)
        return EndPostQuest("timeout");

    pq.lastT = now;
    pq.lastWait = 0;
    auto wait = [&](uint32 ms) { pq.lastWait = ms; return ForceToWait(ms); };

    if (pq.routine != NewRpgInfo::PostQuest::PAUSE)
    {
        Creature* npc = ai->GetCreature(pq.target);
        if (!npc || !npc->IsAlive())
            return EndPostQuest("lost");

        if (!pq.reachT)
        {
            float distance = bot->GetDistance(npc);
            if (distance > INTERACTION_DISTANCE)
            {
                // The next run may come as late as the walk takes, which is not a throttle gap.
                float speed = bot->GetSpeed(MOVE_RUN);
                pq.lastWait = uint32(distance / (speed > 1.0f ? speed : 1.0f) * IN_MILLISECONDS);
                // MoveWorldObjectTo refuses while the bot moves; a walk already under way is progress.
                if (sServerFacade.isMoving(bot) || MoveWorldObjectTo(pq.target))
                    return true;
                return EndPostQuest("unreachable");
            }

            pq.reachT = now;
            bot->SetSelectionGuid(pq.target);
            bot->SetFacingToObject(npc);
            // The legacy RPG sub-actions' own actions, called directly so the routine does not
            // depend on the legacy "rpg target" value.
            if (pq.routine == NewRpgInfo::PostQuest::VENDOR)
                ai->DoSpecificAction("sell", Event("rpg action", "vendor"), true);
            else
                ai->DoSpecificAction("trainer", Event("rpg action", pq.target), true);
            // Then whatever else the NPC offers, through the legacy sub-actions (#85).
            HandOverToLegacyRpg(pq.target);
            return wait(npcVisitTime);
        }

        uint32 stayed = WorldTimer::getMSTimeDiff(pq.reachT, now);
        if (stayed < npcVisitTime)
            return wait(npcVisitTime - stayed);
        EndLegacyRpgHandOver();
        return EndPostQuest("done");
    }

    if (!pq.reachT)
    {
        pq.reachT = now;
        if (pq.kind == NewRpgInfo::PostQuest::TURN_IN)
        {
            static uint32 const emotes[] = { EMOTE_ONESHOT_TALK, EMOTE_ONESHOT_BOW, EMOTE_ONESHOT_WAVE,
                EMOTE_ONESHOT_CHEER, EMOTE_ONESHOT_LAUGH };
            bot->HandleEmoteCommand(emotes[urand(0, 4)]);
        }
        else if (WorldObject* giver = bot->GetMap()->GetWorldObject(pq.giver))
            bot->SetFacingToObject(giver);
        return wait(pq.pauseMs);
    }

    uint32 paused = WorldTimer::getMSTimeDiff(pq.reachT, now);
    if (paused < pq.pauseMs)
        return wait(pq.pauseMs - paused);

    // After an accept the bot turns from the quest giver before it leaves.
    if (pq.kind == NewRpgInfo::PostQuest::ACCEPT)
        bot->SetFacingTo(bot->GetOrientation() + M_PI_F);

    return EndPostQuest("done");
}

bool NewRpgPostQuestAction::EndPostQuest(char const* result)
{
    NewRpgInfo::PostQuest& pq = ai->rpgInfo.postQuest;
    if (sPlayerbotAIConfig.logRpgQuestEvents)
        sLog.outString("[New RPG quest] bot=%s event=post_quest_end kind=%s routine=%s result=%s duration_ms=%u",
            bot->GetName(), PostQuestKindName(pq.kind), PostQuestRoutineName(pq.routine), result,
            WorldTimer::getMSTimeDiff(pq.startT, WorldTimer::getMSTime()));
    pq = NewRpgInfo::PostQuest{};
    return true;
}
