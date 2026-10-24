#include "playerbot/playerbot.h"
#include "NewRpgStrategy.h"

using namespace ai;

// Default actions are queued 200 below their relevance, so this runs only on ticks where no
// trigger action succeeds; the "new rpg status due" trigger below queues it ahead of the status
// actions while an abandon or a cross-map drop is pending, and at least every 5 s otherwise, so
// status timeouts apply (lbrick/cmangos-dev#66).
NextAction** NewRpgStrategy::GetDefaultNonCombatActions()
{
    return NextAction::array(0, new NextAction("new rpg status update", 11.0f), NULL);
}

void NewRpgStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // The post-quest routine runs before the bot's next activity and lasts at most 60 s
    // (lbrick/cmangos-dev#45).
    triggers.push_back(new TriggerNode(
        "new rpg post quest",
        NextAction::array(0, new NextAction("new rpg post quest", 4.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "new rpg status due",
        NextAction::array(0, new NextAction("new rpg status update", 3.5f), NULL)));

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

    triggers.push_back(new TriggerNode(
        "gather status",
        NextAction::array(0, new NextAction("new rpg gather", 3.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "explore status",
        NextAction::array(0, new NextAction("new rpg explore", 3.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "errand status",
        NextAction::array(0, new NextAction("new rpg errand", 3.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "change zone status",
        NextAction::array(0, new NextAction("new rpg go change zone", 3.0f), NULL)));

    // Above every status action, so looting is not starved while a status is active (#87).
    triggers.push_back(new TriggerNode(
        "often",
        NextAction::array(0, new NextAction("new rpg loot", 3.5f), NULL)));
}
