#include "src/Bot/Engine/playerbot.h"
#include "NewRpgAction.h"

#define NEWRPG_LOG(...) do { if (!sPlayerbotAIConfig.logFilterPlayerBot) sLog.outDebug(__VA_ARGS__); } while(0)
#include "src/Ai/World/Rpg/NewRpgInfo.h"
#include "src/Util/BroadcastHelper.h"
#include "src/Mgr/TravelNode.h"
#include "MotionGenerators/MoveMap.h"
#include "Server/DBCStructure.h"
#include "Server/DBCStores.h"

using namespace ai;

// ─── NewRpgStatusUpdateAction ────────────────────────────────────────────────

bool NewRpgStatusUpdateAction::Execute(Event& /*event*/)
{
    NewRpgInfo& info = ai->rpgInfo;
    NewRpgStatus status = info.GetStatus();
    switch (status)
    {
        case RPG_IDLE:
            return RandomChangeStatus({RPG_GO_CAMP, RPG_GO_GRIND, RPG_WANDER_RANDOM, RPG_WANDER_NPC,
                                       RPG_DO_QUEST, RPG_TRAVEL_FLIGHT, RPG_REST, RPG_CHANGE_ZONE});

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
            if (info.HasStatusPersisted(30 * 60 * 1000))
            {
                NEWRPG_LOG("[New RPG] %s CHANGE_ZONE timed out, returning to idle", bot->GetName());
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
            return true;
        }

        if (WorldTimer::getMSTimeDiff(data.lastReach, WorldTimer::getMSTime()) < npcStayTime)
            return false;

        // stayed long enough — pick next target
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
        ai->rpgInfo.ChangeToIdle();
        return true;
    }

    // 5.2 — mount up when far from dest
    if (dist > 50.0f)
        TryMount();

    // Populate TravelNode waypoints once when not near dest (no rebuild — prevents bad node re-entry)
    // BUG-1: reduced from 500→150 yards — bots at 150-500 now get TravelNode route built instead
    // of falling through to direct MoveFarTo, which caused looping at up to 479-yard distances
    if (!dataPtr->waypointsBuilt && dist > 150.0f)
    {
        dataPtr->waypointsBuilt = true;
        std::vector<WorldPosition> startPath;
        TravelNodeRoute route = sTravelNodeMap.getRoute(WorldPosition(bot), dest, startPath, bot);
        std::vector<TravelNode*>& nodes = route.getNodes();
        if (!nodes.empty())
        {
            for (const WorldPosition& bad : ai->badPositions)
                NEWRPG_LOG("[New RPG] %s badPos (%.1f %.1f %.1f mapId=%u)",
                              bot->GetName(), bad.getX(), bad.getY(), bad.getZ(), bad.getMapId());

            for (size_t i = 0; i < nodes.size(); ++i)
            {
                TravelNode* node = nodes[i];
                WorldPosition nodePos = *node->getPosition();
                NEWRPG_LOG("[New RPG] %s TravelNode candidate (%.1f %.1f %.1f mapId=%u)",
                              bot->GetName(), nodePos.getX(), nodePos.getY(), nodePos.getZ(), nodePos.getMapId());

                // BOAT-3: detect transport link to next node (boat/zeppelin)
                bool isTransportLeg = false;
                TravelNode* nextNode = (i + 1 < nodes.size()) ? nodes[i + 1] : nullptr;
                if (nextNode)
                {
                    auto* links = node->getLinks();
                    auto linkIt = links->find(nextNode);
                    if (linkIt != links->end() && linkIt->second->getPathType() == TravelNodePathType::transport)
                        isTransportLeg = true;
                }

                if (!isTransportLeg)
                {
                    // Normal node: normalize mapId, apply Z guard + IsPosBad + isMmapLoaded
                    nodePos.setMapId(bot->GetMapId());
                    if (nodePos.getZ() < 0.0f || nodePos.getZ() > 450.0f)
                    {
                        NEWRPG_LOG("[New RPG] %s TravelNode candidate filtered (invalid Z %.1f)",
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
                    // (underground Z=-32.5, sea-level Z=0.0 on main world map)
                    if (nextNode)
                    {
                        WorldPosition destDock = *nextNode->getPosition();

                        // BUG-2: skip previously rejected destDocks (persists across waypoint rebuilds)
                        bool alreadyRejected = false;
                        for (const auto& rej : dataPtr->rejectedTransportDocks)
                            if (rej.distance(destDock) < 1.0f) { alreadyRejected = true; break; }
                        if (alreadyRejected)
                        {
                            ++i;
                            continue;
                        }

                        bool onMainWorld = (destDock.getMapId() == 0 || destDock.getMapId() == 1);
                        bool badDest = destDock.getZ() < -5.0f || destDock.getZ() > 450.0f ||
                                       (onMainWorld && destDock.getZ() < 2.0f);
                        if (badDest)
                        {
                            NEWRPG_LOG("[New RPG] %s TravelNode transport dest dock invalid Z=%.1f (%.1f %.1f map=%u) — skipping leg",
                                          bot->GetName(), destDock.getZ(), destDock.getX(), destDock.getY(), destDock.getMapId());
                            dataPtr->rejectedTransportDocks.push_back(destDock);  // BUG-2: cache rejection
                            ++i;  // consume nextNode
                            continue;
                        }

                        dataPtr->waypoints.push_back({nodePos, false});
                        NEWRPG_LOG("[New RPG] %s TravelNode transport source dock (%.1f %.1f %.1f map=%u)",
                                      bot->GetName(), nodePos.getX(), nodePos.getY(), nodePos.getZ(), nodePos.getMapId());
                        dataPtr->waypoints.push_back({destDock, true});
                        NEWRPG_LOG("[New RPG] %s TravelNode transport dest dock (%.1f %.1f %.1f map=%u) [teleport]",
                                      bot->GetName(), destDock.getX(), destDock.getY(), destDock.getZ(), destDock.getMapId());
                        ++i;
                    }
                }
            }
            dataPtr->waypoints.push_back({dest, false});
            NEWRPG_LOG("[New RPG] %s CHANGE_ZONE built %zu waypoints via TravelNode",
                          bot->GetName(), dataPtr->waypoints.size());
        }
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

        // BOAT-4: transport teleport handler — walk to source dock, then TeleportTo dest dock
        if (front.teleport)
        {
            float distToDock = WorldPosition(bot).distance(wp);
            if (distToDock > 20.0f)
                return MoveFarTo(wp);

            // TRANSPORT-1/2: second-layer guard — reject any bad dest that slipped through build
            bool onMainWorld = (wp.getMapId() == 0 || wp.getMapId() == 1);
            if (wp.getZ() < -5.0f || wp.getZ() > 450.0f || (onMainWorld && wp.getZ() < 2.0f))
            {
                NEWRPG_LOG("[New RPG] %s transport teleport dest invalid Z=%.1f (%.1f %.1f map=%u) — resetting",
                              bot->GetName(), wp.getZ(), wp.getX(), wp.getY(), wp.getMapId());
                dataPtr->waypoints.erase(dataPtr->waypoints.begin());
                ai->rpgInfo.Reset();
                return false;
            }

            NEWRPG_LOG("[New RPG] %s transport teleport to (%.1f %.1f %.1f map=%u)",
                          bot->GetName(), wp.getX(), wp.getY(), wp.getZ(), wp.getMapId());
            dataPtr->waypoints.erase(dataPtr->waypoints.begin());
            ai->rpgInfo.SetMoveFarTo(WorldPosition());
            return bot->TeleportTo(wp.getMapId(), wp.getX(), wp.getY(), wp.getZ(), bot->GetOrientation());
        }

        if (WorldPosition(bot).distance(wp) < 30.0f)
        {
            dataPtr->waypoints.erase(dataPtr->waypoints.begin());
            return true;
        }
        if (MoveFarTo(wp))
            return true;
        dataPtr->waypoints.erase(dataPtr->waypoints.begin());
        return true;
    }

    // BUG-E: if dest itself is bad (short-dist path, no waypoints built), reset to IDLE
    if (IsPosBad(dest))
    {
        NEWRPG_LOG("[New RPG] %s CHANGE_ZONE dest is bad — resetting to IDLE", bot->GetName());
        ai->rpgInfo.Reset();
        return false;
    }

    if (MoveFarTo(dest))
        return true;

    return MoveRandomNear(10.0f);
}
