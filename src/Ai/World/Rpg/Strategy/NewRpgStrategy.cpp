#include "src/Bot/Engine/playerbot.h"
#include "NewRpgStrategy.h"

using namespace ai;

// Relevance 11.0f is greater than grind (10.0f) — status update takes priority.
NextAction** NewRpgStrategy::GetDefaultNonCombatActions()
{
    return NextAction::array(0, new NextAction("new rpg status update", 11.0f), NULL);
}

void NewRpgStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "go grind status",
        NextAction::array(0, new NextAction("new rpg go grind", 3.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "go camp status",
        NextAction::array(0, new NextAction("new rpg go camp", 3.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "wander random status",
        NextAction::array(0, new NextAction("new rpg wander random", 3.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "wander npc status",
        NextAction::array(0, new NextAction("new rpg wander npc", 3.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "do quest status",
        NextAction::array(0, new NextAction("new rpg do quest", 3.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "travel flight status",
        NextAction::array(0, new NextAction("new rpg travel flight", 3.0f), NULL)));
}
