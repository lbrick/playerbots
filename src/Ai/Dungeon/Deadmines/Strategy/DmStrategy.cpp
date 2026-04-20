#include "src/Bot/Engine/playerbot.h"
#include "DmStrategy.h"

using namespace ai;

// ── DeadminesDungeonStrategy ──────────────────────────────────────────────────

void DeadminesDungeonStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Handle bots summoned into instance already in combat
    triggers.push_back(new TriggerNode(
        "start rhahkzor fight",
        NextAction::array(0, new NextAction("enable rhahkzor fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start sneed shredder fight",
        NextAction::array(0, new NextAction("enable sneed shredder fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start sneed fight",
        NextAction::array(0, new NextAction("enable sneed fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start gilnid fight",
        NextAction::array(0, new NextAction("enable gilnid fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start smite fight",
        NextAction::array(0, new NextAction("enable smite fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start cookie fight",
        NextAction::array(0, new NextAction("enable cookie fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start vancleef fight",
        NextAction::array(0, new NextAction("enable vancleef fight strategy", 100.0f), NULL)));
}

void DeadminesDungeonStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "start rhahkzor fight",
        NextAction::array(0, new NextAction("enable rhahkzor fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start sneed shredder fight",
        NextAction::array(0, new NextAction("enable sneed shredder fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start sneed fight",
        NextAction::array(0, new NextAction("enable sneed fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start gilnid fight",
        NextAction::array(0, new NextAction("enable gilnid fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start smite fight",
        NextAction::array(0, new NextAction("enable smite fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start cookie fight",
        NextAction::array(0, new NextAction("enable cookie fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start vancleef fight",
        NextAction::array(0, new NextAction("enable vancleef fight strategy", 100.0f), NULL)));
}

// ── RhahkzorFightStrategy ─────────────────────────────────────────────────────

void RhahkzorFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Slam knockback ~5yd — stay >8yd
    triggers.push_back(new TriggerNode(
        "rhahkzor slam",
        NextAction::array(0, new NextAction("rhahkzor move away from slam", ACTION_MOVE + 5), NULL)));
}

void RhahkzorFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end rhahkzor fight",
        NextAction::array(0, new NextAction("disable rhahkzor fight strategy", 100.0f), NULL)));
}

void RhahkzorFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end rhahkzor fight",
        NextAction::array(0, new NextAction("disable rhahkzor fight strategy", 100.0f), NULL)));
}

// ── SneedShredderFightStrategy ────────────────────────────────────────────────

void SneedShredderFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Saw Blade AoE ~8yd — stay >10yd
    triggers.push_back(new TriggerNode(
        "sneed shredder saw blade",
        NextAction::array(0, new NextAction("sneed shredder move away from saw blade", ACTION_MOVE + 5), NULL)));
}

void SneedShredderFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end sneed shredder fight",
        NextAction::array(0, new NextAction("disable sneed shredder fight strategy", 100.0f), NULL)));
}

void SneedShredderFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end sneed shredder fight",
        NextAction::array(0, new NextAction("disable sneed shredder fight strategy", 100.0f), NULL)));
}

// ── SneedFightStrategy ────────────────────────────────────────────────────────

void SneedFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end sneed fight",
        NextAction::array(0, new NextAction("disable sneed fight strategy", 100.0f), NULL)));
}

void SneedFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end sneed fight",
        NextAction::array(0, new NextAction("disable sneed fight strategy", 100.0f), NULL)));
}

// ── GilnidFightStrategy ───────────────────────────────────────────────────────

void GilnidFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Molten Metal puddle — stay >8yd
    triggers.push_back(new TriggerNode(
        "gilnid molten metal",
        NextAction::array(0, new NextAction("gilnid move away from molten metal", ACTION_MOVE + 5), NULL)));
}

void GilnidFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end gilnid fight",
        NextAction::array(0, new NextAction("disable gilnid fight strategy", 100.0f), NULL)));
}

void GilnidFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end gilnid fight",
        NextAction::array(0, new NextAction("disable gilnid fight strategy", 100.0f), NULL)));
}

// ── SmiteFightStrategy ────────────────────────────────────────────────────────

void SmiteFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Smite's Mighty Blow knockback ~10yd (hammer phase, <33% HP) — stay >12yd
    triggers.push_back(new TriggerNode(
        "smite hammer phase",
        NextAction::array(0, new NextAction("smite move away from hammer", ACTION_MOVE + 5), NULL)));
}

void SmiteFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end smite fight",
        NextAction::array(0, new NextAction("disable smite fight strategy", 100.0f), NULL)));
}

void SmiteFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end smite fight",
        NextAction::array(0, new NextAction("disable smite fight strategy", 100.0f), NULL)));
}

// ── CookieFightStrategy ───────────────────────────────────────────────────────

void CookieFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end cookie fight",
        NextAction::array(0, new NextAction("disable cookie fight strategy", 100.0f), NULL)));
}

void CookieFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end cookie fight",
        NextAction::array(0, new NextAction("disable cookie fight strategy", 100.0f), NULL)));
}

// ── VanCleefFightStrategy ─────────────────────────────────────────────────────

void VanCleefFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end vancleef fight",
        NextAction::array(0, new NextAction("disable vancleef fight strategy", 100.0f), NULL)));
}

void VanCleefFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end vancleef fight",
        NextAction::array(0, new NextAction("disable vancleef fight strategy", 100.0f), NULL)));
}
