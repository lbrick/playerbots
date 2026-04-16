#include "src/Bot/Engine/playerbot.h"
#include "NewRpgAction.h"
#include "src/Ai/World/Rpg/NewRpgInfo.h"
#include "src/Util/BroadcastHelper.h"

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
                                       RPG_DO_QUEST, RPG_TRAVEL_FLIGHT, RPG_REST});

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
            sLog.outDebug("[New RPG] %s marked as abandoned quest %u", bot->GetName(), questId);
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
        sLog.outDebug("[New RPG] %s marked as abandoned quest (reward) %u", bot->GetName(), questId);
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
        sLog.outDebug("[New RPG] %s activate taxi path (from node %u to %u) failed",
                      bot->GetName(), nodes.empty() ? 0 : nodes[0],
                      nodes.empty() ? 0 : nodes[nodes.size() - 1]);
        ai->rpgInfo.ChangeToIdle();
    }
    return true;
}
