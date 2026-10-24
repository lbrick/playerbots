#pragma once

#include "NewRpgBaseAction.h"

namespace ai
{

/// Evaluates RPG state transitions. Runs at priority 11.0f (above grind).
/// Phase 4 implementation.
class NewRpgStatusUpdateAction : public NewRpgBaseAction
{
public:
    NewRpgStatusUpdateAction(PlayerbotAI* ai) : NewRpgBaseAction(ai, "new rpg status update") {}
    bool Execute(Event& event) override;

protected:
    const int32 statusWanderNpcDuration    = 5 * 60 * 1000;
    const int32 statusWanderRandomDuration = 5 * 60 * 1000;
    const int32 statusRestDuration         = 30 * 1000;
    const int32 statusDoQuestDuration      = 30 * 60 * 1000;
};

class NewRpgGoGrindAction : public NewRpgBaseAction
{
public:
    NewRpgGoGrindAction(PlayerbotAI* ai) : NewRpgBaseAction(ai, "new rpg go grind") {}
    bool Execute(Event& event) override;
};

class NewRpgGoCampAction : public NewRpgBaseAction
{
public:
    NewRpgGoCampAction(PlayerbotAI* ai) : NewRpgBaseAction(ai, "new rpg go camp") {}
    bool Execute(Event& event) override;
};

class NewRpgWanderRandomAction : public NewRpgBaseAction
{
public:
    NewRpgWanderRandomAction(PlayerbotAI* ai) : NewRpgBaseAction(ai, "new rpg wander random") {}
    bool Execute(Event& event) override;
};

class NewRpgWanderNpcAction : public NewRpgBaseAction
{
public:
    NewRpgWanderNpcAction(PlayerbotAI* ai) : NewRpgBaseAction(ai, "new rpg wander npc") {}
    bool Execute(Event& event) override;

    const uint32 npcStayTime = 8 * 1000;
};

// Walks to herbs, ore or skinnable creatures and stays while the legacy loot actions gather
// (lbrick/cmangos-dev#87).
class NewRpgGatherAction : public NewRpgBaseAction
{
public:
    NewRpgGatherAction(PlayerbotAI* ai) : NewRpgBaseAction(ai, "new rpg gather") {}
    bool Execute(Event& event) override;

    const uint32 stayTime = 3 * MINUTE * IN_MILLISECONDS;
};

// Walks to an undiscovered area (lbrick/cmangos-dev#87).
class NewRpgExploreAction : public NewRpgBaseAction
{
public:
    NewRpgExploreAction(PlayerbotAI* ai) : NewRpgBaseAction(ai, "new rpg explore") {}
    bool Execute(Event& event) override;
};

// Walks to a vendor for a need (repair, sale, ammunition) and deals with it (lbrick/cmangos-dev#86).
class NewRpgErrandAction : public NewRpgBaseAction
{
public:
    NewRpgErrandAction(PlayerbotAI* ai) : NewRpgBaseAction(ai, "new rpg errand") {}
    bool Execute(Event& event) override;

    const uint32 npcVisitTime = 8 * 1000;
    const float errandNpcRange = 60.0f;  // vendor search around the destination spawn
};

class NewRpgDoQuestAction : public NewRpgBaseAction
{
public:
    NewRpgDoQuestAction(PlayerbotAI* ai) : NewRpgBaseAction(ai, "new rpg do quest") {}
    bool Execute(Event& event) override;

protected:
    bool DoIncompleteQuest(NewRpgInfo::DoQuest& data);
    bool DoCompletedQuest(NewRpgInfo::DoQuest& data);

    const uint32 poiStayTime = 5 * 60 * 1000;
};

class NewRpgTravelFlightAction : public NewRpgBaseAction
{
public:
    NewRpgTravelFlightAction(PlayerbotAI* ai) : NewRpgBaseAction(ai, "new rpg travel flight") {}
    bool Execute(Event& event) override;
};

class NewRpgGoChangeZoneAction : public NewRpgBaseAction
{
public:
    NewRpgGoChangeZoneAction(PlayerbotAI* ai) : NewRpgBaseAction(ai, "new rpg go change zone") {}
    bool Execute(Event& event) override;
};

/// Runs the routine StartPostQuest sets after a quest accept or turn-in (lbrick/cmangos-dev#45).
class NewRpgPostQuestAction : public NewRpgBaseAction
{
public:
    NewRpgPostQuestAction(PlayerbotAI* ai) : NewRpgBaseAction(ai, "new rpg post quest") {}
    bool Execute(Event& event) override;

protected:
    bool EndPostQuest(char const* result);

    const uint32 npcVisitTime = 3 * 1000;
};

} // namespace ai
