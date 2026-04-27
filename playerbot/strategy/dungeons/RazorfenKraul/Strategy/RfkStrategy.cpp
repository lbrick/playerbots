#include "playerbot/playerbot.h"
#include "RfkStrategy.h"

using namespace ai;

// ── RazorfenKraulDungeonStrategy ──────────────────────────────────────────────

void RazorfenKraulDungeonStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "start roogug fight",
        NextAction::array(0, new NextAction("enable roogug fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start aggem thorncurse fight",
        NextAction::array(0, new NextAction("enable aggem thorncurse fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start death speaker jargba fight",
        NextAction::array(0, new NextAction("enable death speaker jargba fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start overlord ramtusk fight",
        NextAction::array(0, new NextAction("enable overlord ramtusk fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start agathelos fight",
        NextAction::array(0, new NextAction("enable agathelos fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start charlga razorflank fight",
        NextAction::array(0, new NextAction("enable charlga razorflank fight strategy", 100.0f), NULL)));
}

void RazorfenKraulDungeonStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "start roogug fight",
        NextAction::array(0, new NextAction("enable roogug fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start aggem thorncurse fight",
        NextAction::array(0, new NextAction("enable aggem thorncurse fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start death speaker jargba fight",
        NextAction::array(0, new NextAction("enable death speaker jargba fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start overlord ramtusk fight",
        NextAction::array(0, new NextAction("enable overlord ramtusk fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start agathelos fight",
        NextAction::array(0, new NextAction("enable agathelos fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start charlga razorflank fight",
        NextAction::array(0, new NextAction("enable charlga razorflank fight strategy", 100.0f), NULL)));
}

// ── RoogugFightStrategy ───────────────────────────────────────────────────────

void RoogugFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end roogug fight",
        NextAction::array(0, new NextAction("disable roogug fight strategy", 100.0f), NULL)));
}

void RoogugFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end roogug fight",
        NextAction::array(0, new NextAction("disable roogug fight strategy", 100.0f), NULL)));
}

// ── AggEmThorncurseFightStrategy ──────────────────────────────────────────────

void AggEmThorncurseFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end aggem thorncurse fight",
        NextAction::array(0, new NextAction("disable aggem thorncurse fight strategy", 100.0f), NULL)));
}

void AggEmThorncurseFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end aggem thorncurse fight",
        NextAction::array(0, new NextAction("disable aggem thorncurse fight strategy", 100.0f), NULL)));
}

// ── DeathSpeakerJargbaFightStrategy ──────────────────────────────────────────

void DeathSpeakerJargbaFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end death speaker jargba fight",
        NextAction::array(0, new NextAction("disable death speaker jargba fight strategy", 100.0f), NULL)));
}

void DeathSpeakerJargbaFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end death speaker jargba fight",
        NextAction::array(0, new NextAction("disable death speaker jargba fight strategy", 100.0f), NULL)));
}

// ── OverlordRamtuskFightStrategy ──────────────────────────────────────────────

void OverlordRamtuskFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Thunderclap ~8yd AoE — stay >10yd
    triggers.push_back(new TriggerNode(
        "ramtusk thunderclap",
        NextAction::array(0, new NextAction("overlord ramtusk move away from thunderclap", ACTION_MOVE + 5), NULL)));
}

void OverlordRamtuskFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end overlord ramtusk fight",
        NextAction::array(0, new NextAction("disable overlord ramtusk fight strategy", 100.0f), NULL)));
}

void OverlordRamtuskFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end overlord ramtusk fight",
        NextAction::array(0, new NextAction("disable overlord ramtusk fight strategy", 100.0f), NULL)));
}

// ── AgathelosFightStrategy ────────────────────────────────────────────────────

void AgathelosFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Rampage ~8yd AoE — stay >10yd
    triggers.push_back(new TriggerNode(
        "agathelos rampage",
        NextAction::array(0, new NextAction("agathelos move away from rampage", ACTION_MOVE + 5), NULL)));
}

void AgathelosFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end agathelos fight",
        NextAction::array(0, new NextAction("disable agathelos fight strategy", 100.0f), NULL)));
}

void AgathelosFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end agathelos fight",
        NextAction::array(0, new NextAction("disable agathelos fight strategy", 100.0f), NULL)));
}

// ── CharlgaRazorflankFightStrategy ────────────────────────────────────────────

void CharlgaRazorflankFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Chain Bolt jumps to allies within ~8yd — spread >10yd
    triggers.push_back(new TriggerNode(
        "charlga chain bolt spread",
        NextAction::array(0, new NextAction("charlga spread from chain bolt", ACTION_MOVE + 5), NULL)));
}

void CharlgaRazorflankFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end charlga razorflank fight",
        NextAction::array(0, new NextAction("disable charlga razorflank fight strategy", 100.0f), NULL)));
}

void CharlgaRazorflankFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end charlga razorflank fight",
        NextAction::array(0, new NextAction("disable charlga razorflank fight strategy", 100.0f), NULL)));
}
