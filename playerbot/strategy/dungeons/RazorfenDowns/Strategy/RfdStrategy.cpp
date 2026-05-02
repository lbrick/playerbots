#include "playerbot/playerbot.h"
#include "RfdStrategy.h"

using namespace ai;

// ── RazorfenDownsDungeonStrategy ──────────────────────────────────────────────

void RazorfenDownsDungeonStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "start tuten'kash fight",
        NextAction::array(0, new NextAction("enable tuten'kash fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start mordresh fire eye fight",
        NextAction::array(0, new NextAction("enable mordresh fire eye fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start glutton fight",
        NextAction::array(0, new NextAction("enable glutton fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start amnennar the coldbringer fight",
        NextAction::array(0, new NextAction("enable amnennar the coldbringer fight strategy", 100.0f), NULL)));
}

void RazorfenDownsDungeonStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "start tuten'kash fight",
        NextAction::array(0, new NextAction("enable tuten'kash fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start mordresh fire eye fight",
        NextAction::array(0, new NextAction("enable mordresh fire eye fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start glutton fight",
        NextAction::array(0, new NextAction("enable glutton fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start amnennar the coldbringer fight",
        NextAction::array(0, new NextAction("enable amnennar the coldbringer fight strategy", 100.0f), NULL)));
}

// ── TutenkashFightStrategy ────────────────────────────────────────────────────

void TutenkashFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end tuten'kash fight",
        NextAction::array(0, new NextAction("disable tuten'kash fight strategy", 100.0f), NULL)));
}

void TutenkashFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end tuten'kash fight",
        NextAction::array(0, new NextAction("disable tuten'kash fight strategy", 100.0f), NULL)));
}

// ── MordreshFireEyeFightStrategy ──────────────────────────────────────────────

void MordreshFireEyeFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Fire Nova ~10yd AoE — stay >12yd
    triggers.push_back(new TriggerNode(
        "mordresh fire nova",
        NextAction::array(0, new NextAction("mordresh move away from fire nova", ACTION_MOVE + 5), NULL)));
}

void MordreshFireEyeFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end mordresh fire eye fight",
        NextAction::array(0, new NextAction("disable mordresh fire eye fight strategy", 100.0f), NULL)));
}

void MordreshFireEyeFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end mordresh fire eye fight",
        NextAction::array(0, new NextAction("disable mordresh fire eye fight strategy", 100.0f), NULL)));
}

// ── GluttonFightStrategy ──────────────────────────────────────────────────────

void GluttonFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end glutton fight",
        NextAction::array(0, new NextAction("disable glutton fight strategy", 100.0f), NULL)));
}

void GluttonFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end glutton fight",
        NextAction::array(0, new NextAction("disable glutton fight strategy", 100.0f), NULL)));
}

// ── AmnennarTheColdbringerFightStrategy ───────────────────────────────────────

void AmnennarTheColdbringerFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Frost Nova ~8yd AoE — stay >10yd
    triggers.push_back(new TriggerNode(
        "amnennar frost nova",
        NextAction::array(0, new NextAction("amnennar move away from frost nova", ACTION_MOVE + 5), NULL)));
}

void AmnennarTheColdbringerFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end amnennar the coldbringer fight",
        NextAction::array(0, new NextAction("disable amnennar the coldbringer fight strategy", 100.0f), NULL)));
}

void AmnennarTheColdbringerFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end amnennar the coldbringer fight",
        NextAction::array(0, new NextAction("disable amnennar the coldbringer fight strategy", 100.0f), NULL)));
}
