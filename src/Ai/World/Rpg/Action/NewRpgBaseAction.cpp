#include "src/Bot/Engine/playerbot.h"
#include "NewRpgBaseAction.h"

using namespace ai;

// ─── Phase 3 TODO — implement each method ────────────────────────────────────
// Replace each stub return with the real implementation per WORLD_RPG_MIGRATION_PLAN.md

bool NewRpgBaseAction::MoveFarTo(WorldPosition /*dest*/)               { return false; }
bool NewRpgBaseAction::MoveWorldObjectTo(ObjectGuid /*guid*/, float)   { return false; }
bool NewRpgBaseAction::MoveRandomNear(float)                           { return false; }
bool NewRpgBaseAction::ForceToWait(uint32)                             { return false; }

ObjectGuid NewRpgBaseAction::ChooseNpcOrGoToInteract(bool, float)      { return ObjectGuid(); }
bool NewRpgBaseAction::HasQuestToAcceptOrReward(WorldObject*)          { return false; }
bool NewRpgBaseAction::InteractWithNpcOrGoForQuest(ObjectGuid)         { return false; }
bool NewRpgBaseAction::CanInteractWithQuestGiver(Object*)              { return false; }
uint32 NewRpgBaseAction::BestRewardIndex(Quest const*)                 { return 0; }
bool NewRpgBaseAction::IsQuestWorthDoing(Quest const*)                 { return false; }
bool NewRpgBaseAction::IsQuestCapableDoing(Quest const*)               { return false; }
bool NewRpgBaseAction::SearchQuestGiverAndAcceptOrReward()             { return false; }
bool NewRpgBaseAction::AcceptQuest(Quest const*, ObjectGuid)           { return false; }
bool NewRpgBaseAction::TurnInQuest(Quest const*, ObjectGuid)           { return false; }
bool NewRpgBaseAction::OrganizeQuestLog()                              { return false; }

bool NewRpgBaseAction::GetQuestPOIPosAndObjectiveIdx(uint32, WorldPosition&, int32&) { return false; }

WorldPosition NewRpgBaseAction::SelectRandomGrindPos(Player*)          { return WorldPosition(); }
WorldPosition NewRpgBaseAction::SelectRandomCampPos(Player*)           { return WorldPosition(); }
bool NewRpgBaseAction::SelectRandomFlightTaxiNode(ObjectGuid&, std::vector<uint32>&) { return false; }

bool NewRpgBaseAction::RandomChangeStatus(std::vector<NewRpgStatus> /*candidateStatus*/)
{
    return false;  // TODO Phase 3
}

bool NewRpgBaseAction::CheckRpgStatusAvailable(NewRpgStatus /*status*/)
{
    return false;  // TODO Phase 3
}
