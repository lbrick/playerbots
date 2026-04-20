#include "src/Bot/Engine/playerbot.h"
#include "WcStrategy.h"

using namespace ai;

// ── WailingCavernsDungeonStrategy ─────────────────────────────────────────────

void WailingCavernsDungeonStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Druid's Slumber (ID 8040) — cast by Anacondra and trash. Interrupt on sight.
    triggers.push_back(new TriggerNode(
        "target casting druid slumber",
        NextAction::array(0, new NextAction("interrupt enemy cast", ACTION_HIGH + 5), NULL)));

    // Handle bots summoned into instance already in combat
    triggers.push_back(new TriggerNode(
        "start kresh fight",
        NextAction::array(0, new NextAction("enable kresh fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start anacondra fight",
        NextAction::array(0, new NextAction("enable anacondra fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start cobrahn fight",
        NextAction::array(0, new NextAction("enable cobrahn fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start pythas fight",
        NextAction::array(0, new NextAction("enable pythas fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start serpentis fight",
        NextAction::array(0, new NextAction("enable serpentis fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start verdan fight",
        NextAction::array(0, new NextAction("enable verdan fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start mutanus fight",
        NextAction::array(0, new NextAction("enable mutanus fight strategy", 100.0f), NULL)));
}

void WailingCavernsDungeonStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "start kresh fight",
        NextAction::array(0, new NextAction("enable kresh fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start anacondra fight",
        NextAction::array(0, new NextAction("enable anacondra fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start cobrahn fight",
        NextAction::array(0, new NextAction("enable cobrahn fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start pythas fight",
        NextAction::array(0, new NextAction("enable pythas fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start serpentis fight",
        NextAction::array(0, new NextAction("enable serpentis fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start verdan fight",
        NextAction::array(0, new NextAction("enable verdan fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start mutanus fight",
        NextAction::array(0, new NextAction("enable mutanus fight strategy", 100.0f), NULL)));
}

// ── KreshFightStrategy ────────────────────────────────────────────────────────

void KreshFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end kresh fight",
        NextAction::array(0, new NextAction("disable kresh fight strategy", 100.0f), NULL)));
}

void KreshFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end kresh fight",
        NextAction::array(0, new NextAction("disable kresh fight strategy", 100.0f), NULL)));
}

// ── AnacondraFightStrategy ────────────────────────────────────────────────────

void AnacondraFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end anacondra fight",
        NextAction::array(0, new NextAction("disable anacondra fight strategy", 100.0f), NULL)));
}

void AnacondraFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end anacondra fight",
        NextAction::array(0, new NextAction("disable anacondra fight strategy", 100.0f), NULL)));
}

// ── CobrahnFightStrategy ──────────────────────────────────────────────────────

void CobrahnFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end cobrahn fight",
        NextAction::array(0, new NextAction("disable cobrahn fight strategy", 100.0f), NULL)));
}

void CobrahnFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end cobrahn fight",
        NextAction::array(0, new NextAction("disable cobrahn fight strategy", 100.0f), NULL)));
}

// ── PythasFightStrategy ───────────────────────────────────────────────────────

void PythasFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end pythas fight",
        NextAction::array(0, new NextAction("disable pythas fight strategy", 100.0f), NULL)));
}

void PythasFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end pythas fight",
        NextAction::array(0, new NextAction("disable pythas fight strategy", 100.0f), NULL)));
}

// ── SerpenatisFightStrategy ───────────────────────────────────────────────────

void SerpenatisFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end serpentis fight",
        NextAction::array(0, new NextAction("disable serpentis fight strategy", 100.0f), NULL)));
}

void SerpenatisFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end serpentis fight",
        NextAction::array(0, new NextAction("disable serpentis fight strategy", 100.0f), NULL)));
}

// ── VerdanFightStrategy ───────────────────────────────────────────────────────

void VerdanFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Grasping Vines roots ~8yd — stay >10yd
    triggers.push_back(new TriggerNode(
        "verdan grasping vines",
        NextAction::array(0, new NextAction("verdan move away from grasping vines", ACTION_MOVE + 5), NULL)));
}

void VerdanFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end verdan fight",
        NextAction::array(0, new NextAction("disable verdan fight strategy", 100.0f), NULL)));
}

void VerdanFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end verdan fight",
        NextAction::array(0, new NextAction("disable verdan fight strategy", 100.0f), NULL)));
}

// ── MutanusFightStrategy ──────────────────────────────────────────────────────

void MutanusFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Thundercrack AoE knockback + Terrify AoE fear both ~10yd — stay >12yd
    triggers.push_back(new TriggerNode(
        "mutanus aoe",
        NextAction::array(0, new NextAction("mutanus move away from aoe", ACTION_MOVE + 5), NULL)));
}

void MutanusFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end mutanus fight",
        NextAction::array(0, new NextAction("disable mutanus fight strategy", 100.0f), NULL)));
}

void MutanusFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end mutanus fight",
        NextAction::array(0, new NextAction("disable mutanus fight strategy", 100.0f), NULL)));
}
