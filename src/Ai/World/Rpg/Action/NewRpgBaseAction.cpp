#include "src/Bot/Engine/playerbot.h"
#include "NewRpgBaseAction.h"

#define NEWRPG_LOG(...) do { if (!sPlayerbotAIConfig.logFilterPlayerBot) sLog.outDebug(__VA_ARGS__); } while(0)

#include "Server/DBCStructure.h"
#include "Server/DBCStores.h"
#include "Server/DBCEnums.h"
#include "MotionGenerators/PathFinder.h"
#include "src/Ai/Base/values/LastMovementValue.h"
#include "src/Ai/Base/values/ItemUsageValue.h"
#include "src/Util/BroadcastHelper.h"
#include "src/Util/ServerFacade.h"
#include "src/Util/ChatHelper.h"
#include "src/Ai/Base/values/TravelValues.h"
#include "src/Mgr/TravelMgr.h"
#include "src/Mgr/TravelNode.h"

using namespace ai;

// ─── Helper: resolve ObjectGuid to WorldObject (creature or GO) ──────────────
static WorldObject* GetWorldObjectByGuid(PlayerbotAI* ai, Player* bot, ObjectGuid guid)
{
    if (Creature* c = ai->GetAnyTypeCreature(guid))
        return c;
    return bot->GetMap()->GetGameObject(guid);
}

// ─── Movement helpers ────────────────────────────────────────────────────────

bool NewRpgBaseAction::MoveFarTo(WorldPosition dest)
{
    if (dest == WorldPosition())
        return false;

    if (dest != ai->rpgInfo.moveFarPos)
        ai->rpgInfo.SetMoveFarTo(dest);

    // Let committed movement finish before recomputing path.
    // If bot is still moving toward its last waypoint, wait.
    {
        LastMovement& lastMove = AI_VALUE(LastMovement&, "last movement");
        if (sServerFacade.isMoving(bot) && lastMove.lastMoveShort.isValid())
        {
            WorldPosition cur(bot);
            float remaining = cur.distance(lastMove.lastMoveShort);
            if (remaining > 10.0f)
                return true;
        }
    }

    // Stuck check: require 5-yd meaningful progress before resetting timer.
    float disToDest = WorldPosition(bot).distance(dest);

    // Already at destination — no movement needed, let caller transition state.
    if (disToDest < 10.0f)
        return false;

    // Short-distance: skip PathFinder and stuck detection to avoid teleport-on-tiny-gap.
    // Just issue a direct MoveTo; caller will fall through to MoveRandomNear if needed.
    if (disToDest < 20.0f)
    {
        MoveTo(dest.getMapId(), dest.getX(), dest.getY(), dest.getZ(), false, false, false, true);
        return false;
    }

    if (disToDest + 5.0f < ai->rpgInfo.nearestMoveFarDis)
    {
        ai->rpgInfo.nearestMoveFarDis = disToDest;
        ai->rpgInfo.stuckTs = WorldTimer::getMSTime();
        ai->rpgInfo.stuckAttempts = 0;
    }
    else if (++ai->rpgInfo.stuckAttempts >= 5 &&
             WorldTimer::getMSTimeDiff(ai->rpgInfo.stuckTs, WorldTimer::getMSTime()) >= stuckTime)
    {
        ai->rpgInfo.stuckTs = WorldTimer::getMSTime();
        ai->rpgInfo.stuckAttempts = 0;

        AreaTableEntry const* areaEntry = GetAreaEntryByAreaID(bot->GetZoneId());
        std::string zoneName = areaEntry ? ai->GetLocalizedAreaName(areaEntry) : "unknown";

        NEWRPG_LOG("[New RPG] Teleport %s from (%.1f,%.1f,%.1f,%u) to (%.1f,%.1f,%.1f,%u) stuck moving far - Zone: %s (%u)",
            bot->GetName(),
            bot->GetPositionX(), bot->GetPositionY(), bot->GetPositionZ(), bot->GetMapId(),
            dest.getX(), dest.getY(), dest.getZ(), dest.getMapId(),
            zoneName.c_str(), bot->GetZoneId());

        PushBadPosition(dest);
        uint32 botZone = bot->GetZoneId();
        if (ai->currentStayZoneId == 0)
            ai->currentStayZoneId = botZone;
        if (botZone == ai->currentStayZoneId)
            ai->currentStayBadCount++;

        // 8.1: evict the failed dest from CHANGE_ZONE waypoints — prevents stuck attractor loop
        if (auto* cz = std::get_if<NewRpgInfo::ChangeZone>(&ai->rpgInfo.data))
        {
            if (!cz->waypoints.empty())
            {
                WorldPosition check = cz->waypoints.front();
                check.setMapId(bot->GetMapId());
                if (check.distance(dest) < 5.0f)
                {
                    cz->waypoints.erase(cz->waypoints.begin());
                    if (cz->waypoints.empty())
                        cz->waypointsBuilt = false;
                }
            }
            else if (cz->waypointsBuilt)
            {
                // No waypoints left but stuck on direct dest — force fresh route build
                cz->waypointsBuilt = false;
            }
        }

        return bot->TeleportTo(dest.getMapId(), dest.getX(), dest.getY(), dest.getZ(), bot->GetOrientation());
    }

    // Close enough: use normal MoveTo.
    if (disToDest < pathFinderDis)
    {
        return MoveTo(dest.getMapId(), dest.getX(), dest.getY(), dest.getZ(), false, false, false, true);
    }

    const uint32 typeOk = PATHFIND_NORMAL | PATHFIND_INCOMPLETE | PATHFIND_SHORT;

    // Primary: ask mmap for the best route it can find.
    {
        PathFinder path(bot);
        path.calculate(dest.getX(), dest.getY(), dest.getZ());
        PathType type = path.getPathType();
        bool canReach = !(type & (~typeOk));
        if (canReach)
        {
            const Vector3& endPos = path.getActualEndPosition();
            WorldPosition endWp(bot->GetMapId(), endPos.x, endPos.y, endPos.z);
            float endDistToDest = endWp.distance(dest);
            if (endDistToDest + 5.0f < disToDest)
                return MoveTo(bot->GetMapId(), endPos.x, endPos.y, endPos.z, false, false, false, true);
        }
    }

    // Fallback: sample forward cone for a reachable stepping stone.
    float minDelta = M_PI_F;
    const float x = bot->GetPositionX();
    const float y = bot->GetPositionY();
    const float z = bot->GetPositionZ();
    const float baseAngle = bot->GetAngle(dest.getX(), dest.getY());
    float rx = 0.f, ry = 0.f, rz = 0.f;
    bool found = false;

    for (int attempt = 0; attempt < 2; ++attempt)
    {
        float delta = (rand_norm_f() - 0.5f) * M_PI_F;  // ±π/2, forward cone
        float sampleDis = (0.5f + rand_norm_f() * 0.5f) * pathFinderDis;
        float angle = baseAngle + delta;
        float dx = x + cos(angle) * sampleDis;
        float dy = y + sin(angle) * sampleDis;
        float dz = z + 0.5f;

        PathFinder path(bot);
        path.calculate(dx, dy, dz);
        PathType type = path.getPathType();
        bool canReach = !(type & (~typeOk));

        if (canReach && fabs(delta) <= minDelta)
        {
            found = true;
            const Vector3& endPos = path.getActualEndPosition();
            rx = endPos.x;
            ry = endPos.y;
            rz = endPos.z;
            minDelta = fabs(delta);
        }
    }
    if (found)
        return MoveTo(bot->GetMapId(), rx, ry, rz, false, false, false, true);

    return false;
}

bool NewRpgBaseAction::IsPosBad(const WorldPosition& pos) const
{
    for (const WorldPosition& bad : ai->badPositions)
        if (bad.getMapId() == pos.getMapId() && bad.distance(pos) < 50.0f)
            return true;
    return false;
}

void NewRpgBaseAction::PushBadPosition(const WorldPosition& pos)
{
    ai->badPositions.push_back(pos);
    if (ai->badPositions.size() > 200)
        ai->badPositions.erase(ai->badPositions.begin(), ai->badPositions.begin() + 50);
}

bool NewRpgBaseAction::TryMount()
{
    if (bot->IsMounted() || bot->IsInCombat() || bot->IsTaxiFlying())
        return false;
    bool result = ai->DoSpecificAction("check mount state");
    if (result)
        NEWRPG_LOG("[New RPG] %s TryMount fired for CHANGE_ZONE", bot->GetName());
    return result;
}

bool NewRpgBaseAction::MoveWorldObjectTo(ObjectGuid guid, float distance)
{
    if (sServerFacade.isMoving(bot))
        return false;

    WorldObject* object = GetWorldObjectByGuid(ai, bot, guid);
    if (!object)
        return false;

    float x = object->GetPositionX();
    float y = object->GetPositionY();
    float z = object->GetPositionZ();
    uint32 mapId = object->GetMapId();
    float angle = 0.f;

    Unit* unit = dynamic_cast<Unit*>(object);
    if (!unit || !unit->IsMoving())
        angle = object->GetAngle(bot) + (M_PI_F * irand(-25, 25) / 100.f);
    else
        angle = object->GetOrientation() + (M_PI_F * irand(-25, 25) / 100.f);

    float rnd = rand_norm_f();
    x += cos(angle) * distance * rnd;
    y += sin(angle) * distance * rnd;
    // No CheckCollisionAndGetValidCoords in cmangos — just use map height to ground target.
    float groundZ = bot->GetMap()->GetHeight(x, y, z + 5.f);
    if (groundZ > INVALID_HEIGHT)
        z = groundZ;

    return MoveTo(mapId, x, y, z, false, false, false, true);
}

bool NewRpgBaseAction::MoveRandomNear(float moveStep)
{
    if (sServerFacade.isMoving(bot))
        return false;

    const float x = bot->GetPositionX();
    const float y = bot->GetPositionY();
    const float z = bot->GetPositionZ();

    const uint32 typeOk = PATHFIND_NORMAL | PATHFIND_INCOMPLETE | PATHFIND_SHORT;

    for (int attempt = 0; attempt < 8; ++attempt)
    {
        float distance = (0.4f + rand_norm_f() * 0.6f) * moveStep;
        float angle = rand_norm_f() * 2.f * M_PI_F;
        float dx = x + distance * cos(angle);
        float dy = y + distance * sin(angle);
        float dz = z;

        PathFinder path(bot);
        path.calculate(dx, dy, dz);
        PathType type = path.getPathType();
        bool canReach = !(type & (~typeOk));
        if (!canReach)
            continue;

        if (bot->IsInWater())  // skip if current position is water — conservative check
            continue;

        if (MoveTo(bot->GetMapId(), dx, dy, dz, false, false, false, true))
            return true;
    }
    return false;
}

bool NewRpgBaseAction::ForceToWait(uint32 duration)
{
    // Signal the engine to idle for ~duration ms by setting action duration.
    SetDuration(duration);
    return true;
}

// ─── Quest helpers ───────────────────────────────────────────────────────────

bool NewRpgBaseAction::InteractWithNpcOrGoForQuest(ObjectGuid guid)
{
    WorldObject* object = GetWorldObjectByGuid(ai, bot, guid);
    if (!object || !CanInteractWithQuestGiver(object))
        return false;

    bot->PrepareQuestMenu(guid);
    QuestMenu& menu = bot->GetPlayerMenu()->GetQuestMenu();
    if (!menu.MenuItemCount())
        return true;

    for (uint32 idx = 0; idx < menu.MenuItemCount(); ++idx)
    {
        QuestMenuItem const& item = menu.GetItem(idx);
        Quest const* quest = sObjectMgr.GetQuestTemplate(item.m_qId);
        if (!quest)
            continue;

        QuestStatus status = bot->GetQuestStatus(item.m_qId);

        if (status == QUEST_STATUS_NONE &&
            !ai->lowPriorityQuest.count(item.m_qId) &&
            bot->CanTakeQuest(quest, false) &&
            bot->CanAddQuest(quest, false) &&
            IsQuestWorthDoing(quest) &&
            IsQuestCapableDoing(quest))
        {
            AcceptQuest(quest, guid);
            // Verify accept succeeded (CMSG handler may reject if cannot interact).
            if (bot->GetQuestStatus(item.m_qId) == QUEST_STATUS_NONE)
            {
                // GameObject failures are distance-based (transient) — bot just wasn't close
                // enough. Don't mark low priority; travel system will re-approach.
                // Creature failures (faction/phase/hostility) are permanent — mark low priority.
                bool isGameObject = (bot->GetMap()->GetGameObject(guid) != nullptr);
                if (!isGameObject)
                {
                    ai->lowPriorityQuest.insert(item.m_qId);
                    NEWRPG_LOG("[New RPG] %s accept quest %u failed (cannot interact), marked low priority",
                                  bot->GetName(), quest->GetQuestId());
                }
                else
                {
                    uint32 failCount = ++ai->questGoFailCount[item.m_qId];
                    if (failCount >= 5)
                    {
                        ai->lowPriorityQuest.insert(item.m_qId);
                        ai->questGoFailCount.erase(item.m_qId);
                        NEWRPG_LOG("[New RPG] %s accept quest %u failed (GO too far) %u times, marked low priority",
                                      bot->GetName(), quest->GetQuestId(), failCount);
                    }
                    else
                    {
                        NEWRPG_LOG("[New RPG] %s accept quest %u failed (GO too far), will retry on approach",
                                      bot->GetName(), quest->GetQuestId());
                    }
                }
            }
            else
            {
                if (ai->GetMaster())
                    ai->TellPlayerNoFacing(GetMaster(),"Quest accepted " + ChatHelper::formatQuest(quest));
                BroadcastHelper::BroadcastQuestAccepted(ai, bot, quest);
                ai->rpgStatistic.questAccepted++;
                ai->questGoFailCount.erase(item.m_qId);
                NEWRPG_LOG("[New RPG] %s accept quest %u", bot->GetName(), quest->GetQuestId());
            }
        }

        if (status == QUEST_STATUS_COMPLETE && bot->CanRewardQuest(quest, false))
        {
            TurnInQuest(quest, guid);
            if (ai->GetMaster())
                ai->TellPlayerNoFacing(GetMaster(),"Quest rewarded " + ChatHelper::formatQuest(quest));
            BroadcastHelper::BroadcastQuestTurnedIn(ai, bot, quest);
            ai->rpgStatistic.questRewarded++;
            NEWRPG_LOG("[New RPG] %s turned in quest %u", bot->GetName(), quest->GetQuestId());
        }
    }
    return true;
}

bool NewRpgBaseAction::CanInteractWithQuestGiver(Object* questGiver)
{
    switch (questGiver->GetTypeId())
    {
        case TYPEID_UNIT:
        {
            ObjectGuid guid = questGiver->GetObjectGuid();
            if (!guid)
                return false;
            if (!bot->IsInWorld() || bot->IsBeingTeleported())
                return false;
            if (bot->IsTaxiFlying())
                return false;

            Creature* creature = ai->GetAnyTypeCreature(guid);
            if (!creature)
                return false;

            if (!bot->IsAlive() &&
                !creature->GetCreatureInfo()->HasFlag(CreatureTypeFlags::VISIBLE_TO_GHOSTS))
                return false;

            if (!creature->IsAlive() &&
                !creature->GetCreatureInfo()->HasFlag(CreatureTypeFlags::INTERACT_WHILE_DEAD))
                return false;

            if (!creature->HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER))
                return false;

            if (sServerFacade.IsCharmed(creature))
                return false;

            if (!sServerFacade.IsFriendlyTo(bot, creature))
                return false;

            return true;
        }
        case TYPEID_GAMEOBJECT:
        {
            ObjectGuid guid = questGiver->GetObjectGuid();
            if (GameObject* go = bot->GetMap()->GetGameObject(guid))
            {
                if (go->GetGoType() == GAMEOBJECT_TYPE_QUESTGIVER)
                    return true;
            }
            return false;
        }
        default:
            break;
    }
    return false;
}

bool NewRpgBaseAction::AcceptQuest(Quest const* quest, ObjectGuid guid)
{
    WorldPacket p(CMSG_QUESTGIVER_ACCEPT_QUEST);
    uint32 unk1 = 0;
    p << guid << quest->GetQuestId() << unk1;
    p.rpos(0);
    bot->GetSession()->HandleQuestgiverAcceptQuestOpcode(p);
    return true;
}

bool NewRpgBaseAction::TurnInQuest(Quest const* quest, ObjectGuid guid)
{
    uint32 questId = quest->GetQuestId();
    if (bot->GetQuestRewardStatus(questId))
        return false;
    if (!bot->CanRewardQuest(quest, false))
        return false;

    bot->PlayDistanceSound(621);

    // Find the quest giver object for RewardQuest.
    WorldObject* questGiverObj = GetWorldObjectByGuid(ai, bot, guid);
    if (!questGiverObj)
        return false;

    Object* questGiverAsObject = dynamic_cast<Object*>(questGiverObj);

    uint32 rewardIdx = (quest->GetRewChoiceItemsCount() <= 1) ? 0 : BestRewardIndex(quest);
    bot->RewardQuest(quest, rewardIdx, questGiverAsObject, false);
    return true;
}

uint32 NewRpgBaseAction::BestRewardIndex(Quest const* quest)
{
    if (quest->GetRewChoiceItemsCount() <= 1)
        return 0;

    // Pick the reward with the best ItemUsage (EQUIP > BAD_EQUIP > others > NONE).
    ItemUsage bestUsage = ItemUsage::ITEM_USAGE_NONE;
    for (uint8 i = 0; i < quest->GetRewChoiceItemsCount(); ++i)
    {
        ItemUsage usage = AI_VALUE2(ItemUsage, "item usage", quest->RewChoiceItemId[i]);
        if (usage == ItemUsage::ITEM_USAGE_EQUIP)
        {
            bestUsage = ItemUsage::ITEM_USAGE_EQUIP;
            break;
        }
        if (usage == ItemUsage::ITEM_USAGE_BAD_EQUIP && bestUsage != ItemUsage::ITEM_USAGE_EQUIP)
            bestUsage = usage;
        else if (usage != ItemUsage::ITEM_USAGE_NONE && bestUsage == ItemUsage::ITEM_USAGE_NONE)
            bestUsage = usage;
    }

    uint32 best = 0;
    for (uint8 i = 0; i < quest->GetRewChoiceItemsCount(); ++i)
    {
        ItemUsage usage = AI_VALUE2(ItemUsage, "item usage", quest->RewChoiceItemId[i]);
        if (usage == bestUsage)
        {
            best = i;
            break;
        }
    }
    return best;
}

bool NewRpgBaseAction::IsQuestWorthDoing(Quest const* quest)
{
    int32 lowLevelDiff = sWorld.getConfig(CONFIG_INT32_QUEST_LOW_LEVEL_HIDE_DIFF);
    if ((int32)bot->GetLevel() > (int32)bot->GetQuestLevelForPlayer(quest) + lowLevelDiff)
        return false;
    if (quest->IsRepeatable())
        return false;
    // No IsSeasonal() in cmangos vanilla — skip seasonal check.
    return true;
}

bool NewRpgBaseAction::IsQuestCapableDoing(Quest const* quest)
{
    if ((int32)bot->GetLevel() + 3 < (int32)bot->GetQuestLevelForPlayer(quest))
        return false;
    if (quest->GetType() != 0)
        return false;
    if (quest->GetSuggestedPlayers() >= 2)
        return false;
    return true;
}

bool NewRpgBaseAction::OrganizeQuestLog()
{
    int32 freeSlots = 0;
    for (uint16 i = 0; i < MAX_QUEST_LOG_SIZE; ++i)
        if (!bot->GetQuestSlotQuestId(i))
            ++freeSlots;

    if (freeSlots >= 2)
        return false;

    int32 dropped = 0;

    // Pass 1: drop quests not worth/capable of doing, or failed.
    for (uint16 i = 0; i < MAX_QUEST_LOG_SIZE; ++i)
    {
        uint32 questId = bot->GetQuestSlotQuestId(i);
        if (!questId)
            continue;
        Quest const* quest = sObjectMgr.GetQuestTemplate(questId);
        if (!quest)
            continue;
        if (!IsQuestWorthDoing(quest) || !IsQuestCapableDoing(quest) ||
            bot->GetQuestStatus(questId) == QUEST_STATUS_FAILED)
        {
            NEWRPG_LOG("[New RPG] %s drop quest %u", bot->GetName(), questId);
            ai->lowPriorityQuest.insert(questId);
            WorldPacket packet(CMSG_QUESTLOG_REMOVE_QUEST);
            packet << (uint8)i;
            bot->GetSession()->HandleQuestLogRemoveQuest(packet);
            if (ai->GetMaster())
                ai->TellPlayerNoFacing(GetMaster(),"Quest dropped " + ChatHelper::formatQuest(quest));
            ai->rpgStatistic.questDropped++;
            ++dropped;
        }
    }
    if (dropped >= 8) return true;

    // Pass 2: drop quests tied to a specific zone that doesn't match the bot's current zone.
    // zoneSort < 0 means a general category (e.g. "Class", "Professions") — keep those.
    // zoneSort == 0 means no zone requirement — keep those.
    // zoneSort > 0 and != botZone means zone-specific quest for another zone — drop.
    for (uint16 i = 0; i < MAX_QUEST_LOG_SIZE; ++i)
    {
        uint32 questId = bot->GetQuestSlotQuestId(i);
        if (!questId)
            continue;
        Quest const* quest = sObjectMgr.GetQuestTemplate(questId);
        if (!quest)
            continue;
        int32 zoneSort = quest->GetZoneOrSort();
        int32 botZone = (int32)bot->GetZoneId();
        if (zoneSort > 0 && zoneSort != botZone)
        {
            NEWRPG_LOG("[New RPG] %s drop quest %u (zone mismatch: quest zone %d, bot zone %d)",
                          bot->GetName(), questId, zoneSort, botZone);
            ai->lowPriorityQuest.insert(questId);
            WorldPacket packet(CMSG_QUESTLOG_REMOVE_QUEST);
            packet << (uint8)i;
            bot->GetSession()->HandleQuestLogRemoveQuest(packet);
            if (ai->GetMaster())
                ai->TellPlayerNoFacing(GetMaster(),"Quest dropped " + ChatHelper::formatQuest(quest));
            ai->rpgStatistic.questDropped++;
            ++dropped;
        }
    }
    if (dropped >= 8) return true;

    // Pass 3: clear remaining quests.
    for (uint16 i = 0; i < MAX_QUEST_LOG_SIZE; ++i)
    {
        uint32 questId = bot->GetQuestSlotQuestId(i);
        if (!questId)
            continue;
        Quest const* quest = sObjectMgr.GetQuestTemplate(questId);
        NEWRPG_LOG("[New RPG] %s drop quest %u (full clear)", bot->GetName(), questId);
        ai->lowPriorityQuest.insert(questId);
        WorldPacket packet(CMSG_QUESTLOG_REMOVE_QUEST);
        packet << (uint8)i;
        bot->GetSession()->HandleQuestLogRemoveQuest(packet);
        if (ai->GetMaster() && quest)
            ai->TellPlayerNoFacing(GetMaster(),"Quest dropped " + ChatHelper::formatQuest(quest));
        ai->rpgStatistic.questDropped++;
    }
    return true;
}

bool NewRpgBaseAction::SearchQuestGiverAndAcceptOrReward()
{
    OrganizeQuestLog();
    if (ObjectGuid npcOrGo = ChooseNpcOrGoToInteract(true, 80.f))
    {
        WorldObject* object = GetWorldObjectByGuid(ai, bot, npcOrGo);
        if (object && CanInteractWithQuestGiver(object))
        {
            InteractWithNpcOrGoForQuest(npcOrGo);
            ForceToWait(5000);
            return true;
        }
        return MoveWorldObjectTo(npcOrGo);
    }
    return false;
}

ObjectGuid NewRpgBaseAction::ChooseNpcOrGoToInteract(bool questgiverOnly, float distanceLimit)
{
    std::list<ObjectGuid> possibleTargets = AI_VALUE(std::list<ObjectGuid>, "possible rpg targets");
    std::list<ObjectGuid> possibleGOs     = AI_VALUE(std::list<ObjectGuid>, "nearest game objects no los");

    if (possibleTargets.empty() && possibleGOs.empty())
        return ObjectGuid();

    WorldObject* nearestObject = nullptr;

    for (ObjectGuid& guid : possibleTargets)
    {
        WorldObject* object = GetWorldObjectByGuid(ai, bot, guid);
        if (!object || !object->IsInWorld())
            continue;
        if (distanceLimit && bot->GetDistance(object) > distanceLimit)
            continue;
        if (CanInteractWithQuestGiver(object) && HasQuestToAcceptOrReward(object))
        {
            if (!nearestObject || bot->GetDistance(nearestObject) > bot->GetDistance(object))
                nearestObject = object;
            break;
        }
    }

    for (ObjectGuid& guid : possibleGOs)
    {
        WorldObject* object = GetWorldObjectByGuid(ai, bot, guid);
        if (!object || !object->IsInWorld())
            continue;
        if (distanceLimit && bot->GetDistance(object) > distanceLimit)
            continue;
        if (CanInteractWithQuestGiver(object) && HasQuestToAcceptOrReward(object))
        {
            if (!nearestObject || bot->GetDistance(nearestObject) > bot->GetDistance(object))
                nearestObject = object;
            break;
        }
    }

    if (nearestObject)
        return nearestObject->GetObjectGuid();

    if (questgiverOnly)
        return ObjectGuid();

    if (possibleTargets.empty())
        return ObjectGuid();

    // Pick a random nearby NPC.
    uint32 idx = urand(0, (uint32)possibleTargets.size() - 1);
    auto it = possibleTargets.begin();
    std::advance(it, idx);
    ObjectGuid guid = *it;
    WorldObject* object = GetWorldObjectByGuid(ai, bot, guid);
    if (object && object->IsInWorld())
        return guid;

    return ObjectGuid();
}

bool NewRpgBaseAction::HasQuestToAcceptOrReward(WorldObject* object)
{
    ObjectGuid guid = object->GetObjectGuid();
    bot->PrepareQuestMenu(guid);
    QuestMenu& menu = bot->GetPlayerMenu()->GetQuestMenu();
    if (!menu.MenuItemCount())
        return false;

    // Check for completable quests first.
    for (uint32 idx = 0; idx < menu.MenuItemCount(); ++idx)
    {
        QuestMenuItem const& item = menu.GetItem(idx);
        Quest const* quest = sObjectMgr.GetQuestTemplate(item.m_qId);
        if (!quest) continue;
        QuestStatus status = bot->GetQuestStatus(item.m_qId);
        if (status == QUEST_STATUS_COMPLETE && bot->CanRewardQuest(quest, 0, false))
            return true;
    }

    // Then check for new quests.
    for (uint32 idx = 0; idx < menu.MenuItemCount(); ++idx)
    {
        QuestMenuItem const& item = menu.GetItem(idx);
        Quest const* quest = sObjectMgr.GetQuestTemplate(item.m_qId);
        if (!quest) continue;
        QuestStatus status = bot->GetQuestStatus(item.m_qId);
        if (status == QUEST_STATUS_NONE &&
            !ai->lowPriorityQuest.count(item.m_qId) &&
            bot->CanTakeQuest(quest, false) &&
            bot->CanAddQuest(quest, false) &&
            IsQuestWorthDoing(quest) &&
            IsQuestCapableDoing(quest))
            return true;
    }
    return false;
}

// ─── Quest POI — cmangos Classic replacement ─────────────────────────────────
// No server-side POI table in vanilla. Use TravelMgr creature/GO spawn positions.

bool NewRpgBaseAction::GetQuestPOIPosAndObjectiveIdx(uint32 questId, WorldPosition& outPos, int32& outObjIdx)
{
    Quest const* quest = sObjectMgr.GetQuestTemplate(questId);
    if (!quest)
        return false;

    auto it = bot->getQuestStatusMap().find(questId);
    if (it == bot->getQuestStatusMap().end())
        return false;

    const QuestStatusData& qsd = it->second;
    WorldPosition botPos(bot);
    PlayerTravelInfo info(bot);

    // QUEST_STATUS_COMPLETE → find QuestTaker (turn-in NPC) destinations.
    if (qsd.m_status == QUEST_STATUS_COMPLETE)
    {
        DestinationList dests = sTravelMgr.GetDestinations(
            info,
            (uint32)TravelDestinationPurpose::QuestTaker,
            { (int32)questId },
            true,
            2000.f);

        for (TravelDestination* dest : dests)
        {
            const std::vector<WorldPosition*>& pts = dest->GetPoints();
            for (WorldPosition* pt : pts)
            {
                if (pt && pt->getMapId() == bot->GetMapId())
                {
                    outPos    = *pt;
                    outObjIdx = -1;  // -1 = turn-in objective
                    return true;
                }
            }
        }
        return false;
    }

    if (qsd.m_status != QUEST_STATUS_INCOMPLETE)
        return false;

    // QUEST_STATUS_INCOMPLETE → find positions for incomplete objectives.
    // Try creature/GO objectives.
    for (int i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
    {
        if (!quest->ReqCreatureOrGOId[i])
            continue;
        if (qsd.m_creatureOrGOcount[i] >= quest->ReqCreatureOrGOCount[i])
            continue;

        // Determine TravelDestinationPurpose bit for objective slot i.
        uint32 purposeBit = (uint32)TravelDestinationPurpose::QuestObjective1 << i;

        DestinationList dests = sTravelMgr.GetDestinations(
            info,
            purposeBit,
            { (int32)questId },
            true,
            2000.f);

        for (TravelDestination* dest : dests)
        {
            const std::vector<WorldPosition*>& pts = dest->GetPoints();
            for (WorldPosition* pt : pts)
            {
                if (pt && pt->getMapId() == bot->GetMapId())
                {
                    outPos    = *pt;
                    outObjIdx = i;
                    return true;
                }
            }
        }
    }

    // Try item collection objectives (map to QuestObjective slots).
    for (int i = 0; i < QUEST_ITEM_OBJECTIVES_COUNT; ++i)
    {
        if (!quest->ReqItemId[i])
            continue;
        if (qsd.m_itemcount[i] >= quest->ReqItemCount[i])
            continue;

        // Item objectives share slots after creature objectives in the QuestObjective purpose bits.
        int slotIdx = QUEST_OBJECTIVES_COUNT + i;
        uint32 purposeBit = (uint32)TravelDestinationPurpose::QuestObjective1 << std::min(i, (int)QUEST_OBJECTIVES_COUNT - 1);

        DestinationList dests = sTravelMgr.GetDestinations(
            info,
            purposeBit,
            { (int32)questId },
            true,
            2000.f);

        for (TravelDestination* dest : dests)
        {
            const std::vector<WorldPosition*>& pts = dest->GetPoints();
            for (WorldPosition* pt : pts)
            {
                if (pt && pt->getMapId() == bot->GetMapId())
                {
                    outPos    = *pt;
                    outObjIdx = slotIdx;
                    return true;
                }
            }
        }
    }

    return false;
}

// ─── Position selectors ──────────────────────────────────────────────────────

static bool IsInCapitalCity(Player* bot)
{
    AreaTableEntry const* zone = GetAreaEntryByAreaID(bot->GetZoneId());
    return zone && (zone->flags & AREA_FLAG_CAPITAL);
}

WorldPosition NewRpgBaseAction::SelectRandomGrindPos(Player* bot)
{
    WorldPosition botPos(bot);
    PlayerTravelInfo info(bot);
    bool inCity = IsInCapitalCity(bot);

    float hiRange = bot->GetLevel() < 5 ? 165.f : 500.f;
    float loRange = bot->GetLevel() < 5 ? 835.f : 2500.f;

    std::vector<uint32> partitions = { (uint32)hiRange, (uint32)loRange };

    PartitionedTravelList parts = sTravelMgr.GetPartitions(
        botPos, partitions, info,
        (uint32)TravelDestinationPurpose::Grind,
        {}, true, loRange);

    std::vector<WorldPosition> hiLocs, loLocs;
    for (auto& [distKey, pointList] : parts)
    {
        for (auto& [dest, wp, dist] : pointList)
        {
            if (!wp || wp->getMapId() != botPos.getMapId())
                continue;
            if (wp->getZ() < 0.0f)
                continue;
            if (!inCity &&
                sTerrainMgr.GetZoneId(botPos.getMapId(), wp->getX(), wp->getY(), wp->getZ()) != bot->GetZoneId())
                continue;
            if (IsPosBad(*wp))
                continue;
            if (dist <= hiRange)
                hiLocs.push_back(*wp);
            if (dist <= loRange)
                loLocs.push_back(*wp);
        }
    }

    WorldPosition dest{};
    if (urand(1, 100) <= 50 && !hiLocs.empty())
        dest = hiLocs[urand(0, (uint32)hiLocs.size() - 1)];
    else if (!loLocs.empty())
        dest = loLocs[urand(0, (uint32)loLocs.size() - 1)];

    if (dest != WorldPosition())
    {
        PathFinder pf(bot);
        pf.calculate(dest.getX(), dest.getY(), dest.getZ(), false);
        if (pf.getPathType() & PATHFIND_NOPATH)
        {
            PushBadPosition(dest);
            NEWRPG_LOG("[New RPG] %s grind pos (%.1f %.1f %.1f) off nav mesh, marked bad",
                          bot->GetName(), dest.getX(), dest.getY(), dest.getZ());
            return WorldPosition();
        }
    }

    NEWRPG_LOG("[New RPG] Bot %s select random grind pos Map:%u X:%.1f Y:%.1f Z:%.1f (%zu+%zu available)",
        bot->GetName(), dest.getMapId(), dest.getX(), dest.getY(), dest.getZ(),
        hiLocs.size(), loLocs.size() > hiLocs.size() ? loLocs.size() - hiLocs.size() : 0);
    return dest;
}

WorldPosition NewRpgBaseAction::SelectRandomCampPos(Player* bot)
{
    WorldPosition botPos(bot);
    PlayerTravelInfo info(bot);
    bool inCity = IsInCapitalCity(bot);

    float range = bot->GetLevel() <= 5 ? 500.f : 2500.f;
    std::vector<uint32> partitions = { (uint32)range };

    PartitionedTravelList parts = sTravelMgr.GetPartitions(
        botPos, partitions, info,
        (uint32)TravelDestinationPurpose::GenericRpg,
        {}, true, range);

    std::vector<WorldPosition> locs;
    for (auto& [distKey, pointList] : parts)
    {
        for (auto& [dest, wp, dist] : pointList)
        {
            if (!wp || wp->getMapId() != botPos.getMapId())
                continue;
            if (wp->getZ() < 0.0f)
                continue;
            if (dist < 50.f)
                continue;
            if (!inCity &&
                sTerrainMgr.GetZoneId(botPos.getMapId(), wp->getX(), wp->getY(), wp->getZ()) != bot->GetZoneId())
                continue;
            if (IsPosBad(*wp))
                continue;
            locs.push_back(*wp);
        }
    }

    WorldPosition dest{};
    if (!locs.empty())
        dest = locs[urand(0, (uint32)locs.size() - 1)];

    if (dest != WorldPosition())
    {
        PathFinder pf(bot);
        pf.calculate(dest.getX(), dest.getY(), dest.getZ(), false);
        if (pf.getPathType() & PATHFIND_NOPATH)
        {
            PushBadPosition(dest);
            NEWRPG_LOG("[New RPG] %s camp pos (%.1f %.1f %.1f) off nav mesh, marked bad",
                          bot->GetName(), dest.getX(), dest.getY(), dest.getZ());
            return WorldPosition();
        }
    }

    NEWRPG_LOG("[New RPG] Bot %s select random camp pos Map:%u X:%.1f Y:%.1f Z:%.1f (%zu available)",
        bot->GetName(), dest.getMapId(), dest.getX(), dest.getY(), dest.getZ(), locs.size());
    return dest;
}

// ─── Flight taxi helpers ─────────────────────────────────────────────────────

bool NewRpgBaseAction::SelectRandomFlightTaxiNode(ObjectGuid& outFlightMaster, std::vector<uint32>& outPath)
{
    // Find a nearby flight master NPC.
    std::list<ObjectGuid> nearNpcs = AI_VALUE(std::list<ObjectGuid>, "nearest npcs");
    Creature* flightNpc = nullptr;
    for (ObjectGuid& g : nearNpcs)
    {
        Creature* npc = bot->GetNPCIfCanInteractWith(g, UNIT_NPC_FLAG_FLIGHTMASTER);
        if (npc)
        {
            flightNpc = npc;
            outFlightMaster = g;
            break;
        }
    }
    if (!flightNpc)
        return false;

    // Resolve the taxi node at this flight master's position.
    uint32 curloc = sObjectMgr.GetNearestTaxiNode(
        flightNpc->GetPositionX(), flightNpc->GetPositionY(), flightNpc->GetPositionZ(),
        flightNpc->GetMapId(), bot->GetTeam());
    if (!curloc)
        return false;

    // Collect all paths that depart from this node and whose destination
    // node is known to the bot.
    std::vector<uint32> availablePathIds;
    for (uint32 i = 1; i < sTaxiPathStore.GetNumRows(); ++i)
    {
        TaxiPathEntry const* entry = sTaxiPathStore.LookupEntry(i);
        if (!entry || entry->from != curloc)
            continue;
        if (!bot->m_taxi.IsTaximaskNodeKnown(entry->to))
            continue;
        availablePathIds.push_back(i);
    }

    if (availablePathIds.empty())
        return false;

    uint32 pathId = availablePathIds[urand(0, (uint32)availablePathIds.size() - 1)];
    TaxiPathEntry const* chosen = sTaxiPathStore.LookupEntry(pathId);
    if (!chosen)
        return false;

    outPath = { chosen->from, chosen->to };

    NEWRPG_LOG("[New RPG] Bot %s select random flight taxi node from:%u (node %u) to:%u (%zu available)",
        bot->GetName(), outFlightMaster.GetEntry(), chosen->from, chosen->to, availablePathIds.size());
    return true;
}

// ─── Status selection helpers ─────────────────────────────────────────────────

static std::vector<float> GenerateRandomWeights(int n)
{
    std::vector<float> weights(n);
    float sum = 0.f;
    for (int i = 0; i < n; ++i) { weights[i] = rand_norm_f(); sum += weights[i]; }
    for (int i = 0; i < n; ++i) weights[i] /= sum;
    return weights;
}

bool NewRpgBaseAction::RandomChangeStatus(std::vector<NewRpgStatus> candidateStatus)
{
    // Classify quest log: any doable quest (questLevel <= botLevel+3) suppresses grind.
    // All-too-high or empty log → grinding legitimate to level up.
    bool hasDoableQuests = false;
    uint8 botLevel = bot->GetLevel();
    for (uint8 slot = 0; slot < MAX_QUEST_LOG_SIZE; ++slot)
    {
        uint32 questId = bot->GetQuestSlotQuestId(slot);
        if (!questId || ai->lowPriorityQuest.count(questId))
            continue;
        Quest const* quest = sObjectMgr.GetQuestTemplate(questId);
        if (quest && (int32)quest->GetQuestLevel() <= (int32)botLevel + 3)
        {
            hasDoableQuests = true;
            break;
        }
    }

    std::vector<NewRpgStatus> available;
    uint32 probSum = 0;

    for (NewRpgStatus status : candidateStatus)
    {
        uint32 weight = sPlayerbotAIConfig.RpgStatusProbWeight[status];
        if (weight == 0)
            continue;
        if (hasDoableQuests && (status == RPG_GO_GRIND || status == RPG_GO_CAMP))
            weight = 1;
        if (CheckRpgStatusAvailable(status))
        {
            available.push_back(status);
            probSum += weight;
        }
    }

    if (available.empty() || probSum == 0)
    {
        ai->rpgInfo.ChangeToRest();
        bot->SetStandState(UNIT_STAND_STATE_SIT);
        return true;
    }

    uint32 roll = urand(1, probSum);
    uint32 acc  = 0;
    NewRpgStatus chosen = RPG_STATUS_END;
    for (NewRpgStatus status : available)
    {
        uint32 w = sPlayerbotAIConfig.RpgStatusProbWeight[status];
        if (hasDoableQuests && (status == RPG_GO_GRIND || status == RPG_GO_CAMP))
            w = 1;
        acc += w;
        if (acc >= roll) { chosen = status; break; }
    }

    switch (chosen)
    {
        case RPG_WANDER_RANDOM:
            ai->rpgInfo.ChangeToWanderRandom();
            return true;

        case RPG_WANDER_NPC:
            ai->rpgInfo.ChangeToWanderNpc();
            return true;

        case RPG_GO_GRIND:
        {
            WorldPosition pos = SelectRandomGrindPos(bot);
            if (pos != WorldPosition()) { ai->rpgInfo.ChangeToGoGrind(pos); return true; }
            return false;
        }

        case RPG_GO_CAMP:
        {
            WorldPosition pos = SelectRandomCampPos(bot);
            if (pos != WorldPosition()) { ai->rpgInfo.ChangeToGoCamp(pos); return true; }
            return false;
        }

        case RPG_DO_QUEST:
        {
            for (uint8 slot = 0; slot < MAX_QUEST_LOG_SIZE; ++slot)
            {
                uint32 questId = bot->GetQuestSlotQuestId(slot);
                if (!questId) continue;
                if (ai->lowPriorityQuest.count(questId)) continue;

                WorldPosition poiPos;
                int32 poiObjIdx;
                if (GetQuestPOIPosAndObjectiveIdx(questId, poiPos, poiObjIdx))
                {
                    Quest const* quest = sObjectMgr.GetQuestTemplate(questId);
                    if (quest) { ai->rpgInfo.ChangeToDoQuest(questId, quest); return true; }
                }
            }
            return false;
        }

        case RPG_TRAVEL_FLIGHT:
        {
            ObjectGuid flightMaster;
            std::vector<uint32> path;
            if (SelectRandomFlightTaxiNode(flightMaster, path))
            {
                ai->rpgInfo.ChangeToTravelFlight(flightMaster, path);
                return true;
            }
            return false;
        }

        case RPG_CHANGE_ZONE:
        {
            WorldPosition dest = SelectBestZoneForBot(bot);
            if (dest != WorldPosition())
            {
                ai->rpgInfo.ChangeToChangeZone(dest);
                return true;
            }
            return false;
        }

        case RPG_IDLE:
            ai->rpgInfo.ChangeToIdle();
            return true;

        case RPG_REST:
        default:
            ai->rpgInfo.ChangeToRest();
            bot->SetStandState(UNIT_STAND_STATE_SIT);
            return true;
    }
    return false;
}

bool NewRpgBaseAction::CheckRpgStatusAvailable(NewRpgStatus status)
{
    switch (status)
    {
        case RPG_IDLE:
        case RPG_REST:
            return true;

        case RPG_WANDER_RANDOM:
        {
            Unit* target = AI_VALUE(Unit*, "grind target");
            return target != nullptr;
        }

        case RPG_GO_GRIND:
        {
            if (ai->currentStayBadCount >= 5)
            {
                NEWRPG_LOG("[New RPG] %s zone %u has %u bad pos this stay, forcing escape",
                              bot->GetName(), ai->currentStayZoneId, ai->currentStayBadCount);
                return false;
            }
            return SelectRandomGrindPos(bot) != WorldPosition();
        }

        case RPG_GO_CAMP:
        {
            if (ai->currentStayBadCount >= 5)
            {
                NEWRPG_LOG("[New RPG] %s zone %u has %u bad pos this stay, forcing escape",
                              bot->GetName(), ai->currentStayZoneId, ai->currentStayBadCount);
                return false;
            }
            return SelectRandomCampPos(bot) != WorldPosition();
        }

        case RPG_WANDER_NPC:
        {
            std::list<ObjectGuid> targets = AI_VALUE(std::list<ObjectGuid>, "possible rpg targets");
            return targets.size() >= 3;
        }

        case RPG_DO_QUEST:
        {
            for (uint8 slot = 0; slot < MAX_QUEST_LOG_SIZE; ++slot)
            {
                uint32 questId = bot->GetQuestSlotQuestId(slot);
                if (!questId) continue;
                if (ai->lowPriorityQuest.count(questId)) continue;
                WorldPosition pos;
                int32 objIdx;
                if (GetQuestPOIPosAndObjectiveIdx(questId, pos, objIdx))
                    return true;
            }
            return false;
        }

        case RPG_TRAVEL_FLIGHT:
        {
            ObjectGuid fm;
            std::vector<uint32> path;
            return SelectRandomFlightTaxiNode(fm, path);
        }

        case RPG_CHANGE_ZONE:
        {
            bool hasDoable = false;
            uint8 bLevel = bot->GetLevel();
            for (uint8 slot = 0; slot < MAX_QUEST_LOG_SIZE; ++slot)
            {
                uint32 qId = bot->GetQuestSlotQuestId(slot);
                if (!qId || ai->lowPriorityQuest.count(qId)) continue;
                Quest const* q = sObjectMgr.GetQuestTemplate(qId);
                if (q && (int32)q->GetQuestLevel() <= (int32)bLevel + 3) { hasDoable = true; break; }
            }
            if (hasDoable) return false;
            WorldPosition dest = SelectBestZoneForBot(bot);
            if (dest == WorldPosition()) return false;
            // If dest is far and a flight master is nearby, suppress CHANGE_ZONE
            // so RPG_TRAVEL_FLIGHT gets selected instead (bot flies toward dest zone).
            if (WorldPosition(bot).distance(dest) > 1000.0f)
            {
                ObjectGuid fm;
                std::vector<uint32> path;
                if (SelectRandomFlightTaxiNode(fm, path))
                    return false;
            }
            return true;
        }

        default:
            return false;
    }
}

// ─── Zone Scoring ─────────────────────────────────────────────────────────────

std::unordered_map<uint32, float> NewRpgBaseAction::ScoreZonesForBot(Player* bot)
{
    WorldPosition botPos(bot);
    PlayerTravelInfo info(bot);
    uint32 mapId = botPos.getMapId();

    float maxRange = 50000.0f;
    std::vector<uint32> partitions = { (uint32)maxRange };

    std::unordered_map<uint32, float> zoneScores;

    // Grind destinations at bot level (IsPossible already level-filters)
    PartitionedTravelList grindParts = sTravelMgr.GetPartitions(
        botPos, partitions, info,
        (uint32)TravelDestinationPurpose::Grind,
        {}, true, maxRange);

    for (auto& [distKey, pointList] : grindParts)
    {
        for (auto& [dest, wp, dist] : pointList)
        {
            if (!wp || wp->getMapId() != mapId) continue;
            if (wp->getZ() < 0.0f) continue;
            uint32 zone = sTerrainMgr.GetZoneId(mapId, wp->getX(), wp->getY(), wp->getZ());
            if (!zone) continue;
            zoneScores[zone] += 3.0f - (dist / 10000.0f);
        }
    }

    // Quest givers with quests bot can pick up
    PartitionedTravelList questGiverParts = sTravelMgr.GetPartitions(
        botPos, partitions, info,
        (uint32)TravelDestinationPurpose::QuestGiver,
        {}, false, maxRange);

    for (auto& [distKey, pointList] : questGiverParts)
    {
        for (auto& [dest, wp, dist] : pointList)
        {
            if (!wp || wp->getMapId() != mapId) continue;
            if (wp->getZ() < 0.0f) continue;
            auto* qDest = dynamic_cast<QuestRelationTravelDestination*>(dest);
            if (!qDest) continue;
            Quest const* quest = sObjectMgr.GetQuestTemplate(qDest->GetQuestId());
            if (!quest) continue;
            uint8 bLevel = bot->GetLevel();
            if ((int32)quest->GetQuestLevel() > (int32)bLevel + 2) continue;
            if ((int32)quest->GetMinLevel() > (int32)bLevel) continue;
            if (bot->GetQuestStatus(qDest->GetQuestId()) != QUEST_STATUS_NONE) continue;
            uint32 zone = sTerrainMgr.GetZoneId(mapId, wp->getX(), wp->getY(), wp->getZ());
            if (!zone) continue;
            zoneScores[zone] += 10.0f - (dist / 10000.0f);
        }
    }

    // Quest objectives in log (incomplete quests at bot level)
    PartitionedTravelList questObjParts = sTravelMgr.GetPartitions(
        botPos, partitions, info,
        (uint32)TravelDestinationPurpose::QuestAllObjective,
        {}, false, maxRange);

    for (auto& [distKey, pointList] : questObjParts)
    {
        for (auto& [dest, wp, dist] : pointList)
        {
            if (!wp || wp->getMapId() != mapId) continue;
            if (wp->getZ() < 0.0f) continue;
            auto* qDest = dynamic_cast<QuestObjectiveTravelDestination*>(dest);
            if (!qDest) continue;
            uint32 qId = qDest->GetQuestId();
            if (ai->lowPriorityQuest.count(qId)) continue;
            if (bot->GetQuestStatus(qId) != QUEST_STATUS_INCOMPLETE) continue;
            Quest const* quest = sObjectMgr.GetQuestTemplate(qId);
            if (!quest) continue;
            if ((int32)quest->GetQuestLevel() > (int32)bot->GetLevel() + 3) continue;
            uint32 zone = sTerrainMgr.GetZoneId(mapId, wp->getX(), wp->getY(), wp->getZ());
            if (!zone) continue;
            zoneScores[zone] += 8.0f - (dist / 10000.0f);
        }
    }

    // Pre-build zone bad count map — O(N) total, not O(zones × N) (8.5 perf fix)
    std::unordered_map<uint32, uint32> zoneBadCounts;
    for (const WorldPosition& bad : ai->badPositions)
    {
        if (bad.getMapId() != mapId) continue;
        uint32 z = sTerrainMgr.GetZoneId(mapId, bad.getX(), bad.getY(), bad.getZ());
        if (z) zoneBadCounts[z]++;
    }

    // Apply penalty — proportional per bad pos + hard floor for heavily trapped zones (8.2 BUG-B fix)
    for (auto& [zone, score] : zoneScores)
    {
        auto it = zoneBadCounts.find(zone);
        if (it == zoneBadCounts.end()) continue;
        uint32 badCount = it->second;
        score -= static_cast<float>(badCount) * 10.0f;
        if (badCount >= 5)
            score = std::min(score, -50.0f);
    }

    return zoneScores;
}

WorldPosition NewRpgBaseAction::SelectBestZoneForBot(Player* bot)
{
    auto& cache = ai->zoneScoreCache;
    uint32 now      = WorldTimer::getMSTime();
    uint32 curLevel = bot->GetLevel();
    uint32 curMap   = WorldPosition(bot).getMapId();

    bool cacheValid = cache.cachedLevel == curLevel
                   && cache.cachedMapId == curMap
                   && WorldTimer::getMSTimeDiff(cache.cachedAt, now) < PlayerbotAI::ZoneScoreCache::TTL;

    if (cacheValid)
    {
        // Invalidate if cached dest was subsequently marked bad (e.g. teleport fired there).
        if (cache.bestZonePos != WorldPosition() && IsPosBad(cache.bestZonePos))
        {
            cache = {};
        }
        else
        {
            NEWRPG_LOG("[New RPG] %s zone score cache hit: zone %u score %.1f",
                          bot->GetName(), cache.bestZoneId, cache.bestZoneScore);
            return cache.bestZonePos;
        }
    }

    std::unordered_map<uint32, float> scores = ScoreZonesForBot(bot);

    uint32 currentZone  = bot->GetZoneId();
    float  currentScore = scores.count(currentZone) ? scores[currentZone] : 0.0f;
    uint32 bestZone     = currentZone;
    float  bestScore    = currentScore;

    for (auto& [zone, score] : scores)
    {
        if (score > bestScore)
        {
            bestScore = score;
            bestZone  = zone;
        }
    }

    constexpr float CHANGE_THRESHOLD = 20.0f;
    if (bestZone == currentZone || bestScore - currentScore < CHANGE_THRESHOLD)
    {
        cache = { curLevel, curMap, currentZone, WorldPosition(), currentScore, now };
        return WorldPosition();
    }

    // Find a WorldPosition in the best zone to travel to
    WorldPosition botPos(bot);
    PlayerTravelInfo info(bot);
    float maxRange = 50000.0f;
    std::vector<uint32> partitions = { (uint32)maxRange };

    PartitionedTravelList grindParts = sTravelMgr.GetPartitions(
        botPos, partitions, info,
        (uint32)TravelDestinationPurpose::Grind,
        {}, true, maxRange);

    std::vector<WorldPosition> candidates;
    for (auto& [distKey, pointList] : grindParts)
    {
        for (auto& [dest, wp, dist] : pointList)
        {
            if (!wp || wp->getMapId() != botPos.getMapId()) continue;
            if (wp->getZ() < 0.0f) continue;
            if (IsPosBad(*wp)) continue;
            uint32 zone = sTerrainMgr.GetZoneId(wp->getMapId(), wp->getX(), wp->getY(), wp->getZ());
            if (zone == bestZone)
                candidates.push_back(*wp);
        }
    }

    if (candidates.empty())
    {
        cache = { curLevel, curMap, currentZone, WorldPosition(), currentScore, now };
        return WorldPosition();
    }

    WorldPosition dest = candidates[urand(0, (uint32)candidates.size() - 1)];

    NEWRPG_LOG("[New RPG] %s zone routing: zone %u (score %.1f) > zone %u (score %.1f), target Map:%u %.1f %.1f %.1f",
                  bot->GetName(), bestZone, bestScore, currentZone, currentScore,
                  dest.getMapId(), dest.getX(), dest.getY(), dest.getZ());

    cache = { curLevel, curMap, bestZone, dest, bestScore, now };
    return dest;
}
