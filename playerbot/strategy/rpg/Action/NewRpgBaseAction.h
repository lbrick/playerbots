#pragma once

#include <unordered_map>
#include "playerbot/strategy/actions/MovementActions.h"
#include "playerbot/strategy/rpg/NewRpgInfo.h"

namespace ai
{

/// Base class for all NewRpg state actions.
/// Shared helpers: pathfinding, quest POI lookup, NPC interaction, taxi.
/// Full implementation: Phase 3 of World/RPG migration plan.
class NewRpgBaseAction : public MovementAction
{
public:
    NewRpgBaseAction(PlayerbotAI* ai, std::string const& name)
        : MovementAction(ai, name) {}

protected:
    /* MOVEMENT */
    bool MoveFarTo(WorldPosition dest);
    bool TryMount();
    bool MoveWorldObjectTo(ObjectGuid guid, float distance = INTERACTION_DISTANCE);
    bool MoveRandomNear(float moveStep = 50.0f);
    bool ForceToWait(uint32 duration);
    // Walks toward dest for a status that ends when it cannot get there. One false from MoveFarTo
    // is not a failure: it also returns false on arrival and for a move refused this tick. The
    // status gives up only when MoveFarTo abandons the target, or after moveGiveUpTime of
    // failures in a row (lbrick/cmangos-dev#86).
    enum class MoveResult { Moving, Arrived, Failed };
    MoveResult MoveToward(WorldPosition dest, float arriveRange);
    // The nearest live, non-hostile creature with the NPC flag within range, by grid search:
    // the cached "nearest npcs" list can predate the bot's arrival.
    Creature* FindNearestNpc(uint32 npcFlag, float range);

    /* QUEST */
    ObjectGuid ChooseNpcOrGoToInteract(bool questgiverOnly = false, float distanceLimit = 0.0f);
    bool HasQuestToAcceptOrReward(WorldObject* object);
    bool InteractWithNpcOrGoForQuest(ObjectGuid guid);
    bool CanInteractWithQuestGiver(Object* questGiver);
    bool IsInQuestInteractRange(WorldObject* questGiver);
    bool IsQuestGiverBackedOff(WorldObject* questGiver);
    void RecordQuestGiverFailure(ObjectGuid guid);
    void LogQuestEvent(char const* event, uint32 questId, ObjectGuid guid, WorldObject* questGiver);
    void LogTravelEvent(char const* event, WorldPosition const& from, WorldPosition const& to, char const* detail = "");
    // Hands an NPC or object the bot has reached to the legacy RPG sub-actions (repair, sell,
    // train, emote ...): the one that fits is chosen as legacy RPG chooses it, and run now.
    // Returns the sub-action run, or an empty string (lbrick/cmangos-dev#85).
    std::string HandOverToLegacyRpg(ObjectGuid target);
    // Clears the legacy RPG target the hand-over set.
    void EndLegacyRpgHandOver();
    // Errands (lbrick/cmangos-dev#86): the bot's most pressing need, the nearest vendor spawn that
    // serves it, and the end of an errand with its log line.
    NewRpgErrandNeed CurrentErrandNeed();
    bool SelectErrandDestination(NewRpgErrandNeed need, WorldPosition& out);
    bool TryStartErrand();
    bool EndErrand(char const* reason);
    // Appended to a status's timeout line: distance left, the last MoveFarTo step, combat, and
    // the last actions run, to tell a walk that is slow from one that never ran (#86).
    std::string TimeoutDetail(WorldPosition const& dest);
    uint32 FreeBagSlots();
    uint32 LowestDurabilityPct();
    void CheckStuckTeleport();
    uint32 BestRewardIndex(Quest const* quest);
    bool IsQuestWorthDoing(Quest const* quest);
    bool IsQuestCapableDoing(Quest const* quest);
    bool SearchQuestGiverAndAcceptOrReward();
    bool AcceptQuest(Quest const* quest, ObjectGuid guid);
    bool TurnInQuest(Quest const* quest, ObjectGuid guid);
    bool OrganizeQuestLog();
    void StartPostQuest(bool turnedIn, ObjectGuid giver);
    static char const* PostQuestKindName(uint8 kind);
    static char const* PostQuestRoutineName(uint8 routine);

    /* INTERNAL HELPERS */
    bool GetQuestPOIPosAndObjectiveIdx(uint32 questId, WorldPosition& outPos, int32& outObjIdx);
    WorldPosition SelectRandomGrindPos(Player* bot);
    WorldPosition SelectRandomCampPos(Player* bot);
    bool SelectRandomFlightTaxiNode(ObjectGuid& flightMaster, std::vector<uint32>& path);
    bool IsPosBad(const WorldPosition& pos) const;
    Player* GetRealPlayerInRange(float range) const;
    bool StuckTeleport(WorldPosition const& dest);
    void PushBadPosition(const WorldPosition& pos);
    bool RandomChangeStatus(std::vector<NewRpgStatus> candidateStatus);
    bool CheckRpgStatusAvailable(NewRpgStatus status);

    std::unordered_map<uint32, float> ScoreZonesForBot(Player* bot);
    WorldPosition SelectBestZoneForBot(Player* bot);

protected:
    const float  pathFinderDis = 70.0f;
    const uint32 stuckTime     = 90 * 1000;  // ms before teleport stuck-recovery fires
    const uint32 moveGiveUpTime = 30 * 1000; // MoveToward: failures in a row before a status gives up
    const float stuckObserverRange = 60.0f;  // no stuck teleport with a real player this close
    // Quest givers: retry delay doubles from this after each failed approach or game object
    // interaction; after questGiverMaxFailures the giver is skipped for the session.
    const uint32 questGiverBackoffBase  = 30 * 1000;
    const uint32 questGiverMaxFailures  = 4;
    // Post-quest routine (lbrick/cmangos-dev#45): vendor or trainer search range and the cap.
    const float  postQuestNpcRange = 50.0f;
    const uint32 postQuestMaxTime  = 60 * 1000;
    const uint32 postQuestStallTime = 15 * 1000; // late beyond the requested wait: the bot was throttled
};

} // namespace ai
