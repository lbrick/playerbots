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

} // namespace ai
