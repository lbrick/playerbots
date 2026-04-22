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

    /* QUEST */
    ObjectGuid ChooseNpcOrGoToInteract(bool questgiverOnly = false, float distanceLimit = 0.0f);
    bool HasQuestToAcceptOrReward(WorldObject* object);
    bool InteractWithNpcOrGoForQuest(ObjectGuid guid);
    bool CanInteractWithQuestGiver(Object* questGiver);
    uint32 BestRewardIndex(Quest const* quest);
    bool IsQuestWorthDoing(Quest const* quest);
    bool IsQuestCapableDoing(Quest const* quest);
    bool SearchQuestGiverAndAcceptOrReward();
    bool AcceptQuest(Quest const* quest, ObjectGuid guid);
    bool TurnInQuest(Quest const* quest, ObjectGuid guid);
    bool OrganizeQuestLog();

    /* INTERNAL HELPERS */
    bool GetQuestPOIPosAndObjectiveIdx(uint32 questId, WorldPosition& outPos, int32& outObjIdx);
    WorldPosition SelectRandomGrindPos(Player* bot);
    WorldPosition SelectRandomCampPos(Player* bot);
    bool SelectRandomFlightTaxiNode(ObjectGuid& flightMaster, std::vector<uint32>& path);
    bool IsPosBad(const WorldPosition& pos) const;
    void PushBadPosition(const WorldPosition& pos);
    bool RandomChangeStatus(std::vector<NewRpgStatus> candidateStatus);
    bool CheckRpgStatusAvailable(NewRpgStatus status);

    std::unordered_map<uint32, float> ScoreZonesForBot(Player* bot);
    WorldPosition SelectBestZoneForBot(Player* bot);

protected:
    const float  pathFinderDis = 70.0f;
    const uint32 stuckTime     = 90 * 1000;  // ms before teleport stuck-recovery fires
};

} // namespace ai
