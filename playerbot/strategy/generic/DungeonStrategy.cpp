
#include "playerbot/playerbot.h"
#include "DungeonStrategy.h"

using namespace ai;

void DungeonStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Add this combat triggers in case the bot gets summoned into the dungeon and goes straight into combat
    triggers.push_back(new TriggerNode(
        "enter ragefire chasm",
        NextAction::array(0, new NextAction("enable ragefire chasm strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "enter wailing caverns",
        NextAction::array(0, new NextAction("enable wailing caverns strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "enter deadmines",
        NextAction::array(0, new NextAction("enable deadmines strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "enter shadowfang keep",
        NextAction::array(0, new NextAction("enable shadowfang keep strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "enter blackfathom deeps",
        NextAction::array(0, new NextAction("enable blackfathom deeps strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "enter stockade",
        NextAction::array(0, new NextAction("enable stockade strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "enter gnomeregan",
        NextAction::array(0, new NextAction("enable gnomeregan strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "enter razorfen kraul",
        NextAction::array(0, new NextAction("enable razorfen kraul strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "enter scarlet monastery",
        NextAction::array(0, new NextAction("enable scarlet monastery strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "enter onyxia's lair",
        NextAction::array(0, new NextAction("enable onyxia's lair strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "enter molten core",
        NextAction::array(0, new NextAction("enable molten core strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "enter blackwing lair",
        NextAction::array(0, new NextAction("enable blackwing lair strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "enter karazhan",
        NextAction::array(0, new NextAction("enable karazhan strategy", 100.0f), NULL)));
}

void DungeonStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "enter ragefire chasm",
        NextAction::array(0, new NextAction("enable ragefire chasm strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "leave ragefire chasm",
        NextAction::array(0, new NextAction("disable ragefire chasm strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "enter wailing caverns",
        NextAction::array(0, new NextAction("enable wailing caverns strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "leave wailing caverns",
        NextAction::array(0, new NextAction("disable wailing caverns strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "enter deadmines",
        NextAction::array(0, new NextAction("enable deadmines strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "leave deadmines",
        NextAction::array(0, new NextAction("disable deadmines strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "enter shadowfang keep",
        NextAction::array(0, new NextAction("enable shadowfang keep strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "leave shadowfang keep",
        NextAction::array(0, new NextAction("disable shadowfang keep strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "enter blackfathom deeps",
        NextAction::array(0, new NextAction("enable blackfathom deeps strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "leave blackfathom deeps",
        NextAction::array(0, new NextAction("disable blackfathom deeps strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "enter stockade",
        NextAction::array(0, new NextAction("enable stockade strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "leave stockade",
        NextAction::array(0, new NextAction("disable stockade strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "enter gnomeregan",
        NextAction::array(0, new NextAction("enable gnomeregan strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "leave gnomeregan",
        NextAction::array(0, new NextAction("disable gnomeregan strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "enter razorfen kraul",
        NextAction::array(0, new NextAction("enable razorfen kraul strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "leave razorfen kraul",
        NextAction::array(0, new NextAction("disable razorfen kraul strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "enter scarlet monastery",
        NextAction::array(0, new NextAction("enable scarlet monastery strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "leave scarlet monastery",
        NextAction::array(0, new NextAction("disable scarlet monastery strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "enter onyxia's lair",
        NextAction::array(0, new NextAction("enable onyxia's lair strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "leave onyxia's lair",
        NextAction::array(0, new NextAction("disable onyxia's lair strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "enter molten core",
        NextAction::array(0, new NextAction("enable molten core strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "leave molten core",
        NextAction::array(0, new NextAction("disable molten core strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "enter blackwing lair",
        NextAction::array(0, new NextAction("enable blackwing lair strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "leave blackwing lair",
        NextAction::array(0, new NextAction("disable blackwing lair strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "enter karazhan",
        NextAction::array(0, new NextAction("enable karazhan strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "leave karazhan",
        NextAction::array(0, new NextAction("disable karazhan strategy", 100.0f), NULL)));
}
