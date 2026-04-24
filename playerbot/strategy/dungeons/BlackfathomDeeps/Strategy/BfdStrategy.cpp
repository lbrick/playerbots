#include "playerbot/playerbot.h"
#include "BfdStrategy.h"

using namespace ai;

// ── BlackfathomDeepsDungeonStrategy ──────────────────────────────────────────

void BlackfathomDeepsDungeonStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Handle bots summoned into instance already in combat
    triggers.push_back(new TriggerNode(
        "start ghamoo-ra fight",
        NextAction::array(0, new NextAction("enable ghamoo-ra fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start lady sarevess fight",
        NextAction::array(0, new NextAction("enable lady sarevess fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start gelihast fight",
        NextAction::array(0, new NextAction("enable gelihast fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start lorgus jett fight",
        NextAction::array(0, new NextAction("enable lorgus jett fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start baron aquanis fight",
        NextAction::array(0, new NextAction("enable baron aquanis fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start kelris fight",
        NextAction::array(0, new NextAction("enable kelris fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start aku'mai fight",
        NextAction::array(0, new NextAction("enable aku'mai fight strategy", 100.0f), NULL)));
}

void BlackfathomDeepsDungeonStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "start ghamoo-ra fight",
        NextAction::array(0, new NextAction("enable ghamoo-ra fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start lady sarevess fight",
        NextAction::array(0, new NextAction("enable lady sarevess fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start gelihast fight",
        NextAction::array(0, new NextAction("enable gelihast fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start lorgus jett fight",
        NextAction::array(0, new NextAction("enable lorgus jett fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start baron aquanis fight",
        NextAction::array(0, new NextAction("enable baron aquanis fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start kelris fight",
        NextAction::array(0, new NextAction("enable kelris fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start aku'mai fight",
        NextAction::array(0, new NextAction("enable aku'mai fight strategy", 100.0f), NULL)));
}

// ── GhamooRaFightStrategy ─────────────────────────────────────────────────────

void GhamooRaFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Trample ~5yd — non-tanks stay >8yd
    triggers.push_back(new TriggerNode(
        "ghamoo-ra trample",
        NextAction::array(0, new NextAction("ghamoo-ra move away from trample", ACTION_MOVE + 5), NULL)));
}

void GhamooRaFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end ghamoo-ra fight",
        NextAction::array(0, new NextAction("disable ghamoo-ra fight strategy", 100.0f), NULL)));
}

void GhamooRaFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end ghamoo-ra fight",
        NextAction::array(0, new NextAction("disable ghamoo-ra fight strategy", 100.0f), NULL)));
}

// ── LadySarevessFightStrategy ─────────────────────────────────────────────────

void LadySarevessFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end lady sarevess fight",
        NextAction::array(0, new NextAction("disable lady sarevess fight strategy", 100.0f), NULL)));
}

void LadySarevessFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end lady sarevess fight",
        NextAction::array(0, new NextAction("disable lady sarevess fight strategy", 100.0f), NULL)));
}

// ── GelihastFightStrategy ─────────────────────────────────────────────────────

void GelihastFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end gelihast fight",
        NextAction::array(0, new NextAction("disable gelihast fight strategy", 100.0f), NULL)));
}

void GelihastFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end gelihast fight",
        NextAction::array(0, new NextAction("disable gelihast fight strategy", 100.0f), NULL)));
}

// ── LorgusJettFightStrategy ───────────────────────────────────────────────────

void LorgusJettFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end lorgus jett fight",
        NextAction::array(0, new NextAction("disable lorgus jett fight strategy", 100.0f), NULL)));
}

void LorgusJettFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end lorgus jett fight",
        NextAction::array(0, new NextAction("disable lorgus jett fight strategy", 100.0f), NULL)));
}

// ── BaronAquanisFightStrategy ─────────────────────────────────────────────────

void BaronAquanisFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end baron aquanis fight",
        NextAction::array(0, new NextAction("disable baron aquanis fight strategy", 100.0f), NULL)));
}

void BaronAquanisFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end baron aquanis fight",
        NextAction::array(0, new NextAction("disable baron aquanis fight strategy", 100.0f), NULL)));
}

// ── KelrisFightStrategy ───────────────────────────────────────────────────────

void KelrisFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end kelris fight",
        NextAction::array(0, new NextAction("disable kelris fight strategy", 100.0f), NULL)));
}

void KelrisFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end kelris fight",
        NextAction::array(0, new NextAction("disable kelris fight strategy", 100.0f), NULL)));
}

// ── AkuMaiFightStrategy ───────────────────────────────────────────────────────

void AkuMaiFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Poison Cloud ~8yd ground AoE — stay >10yd
    triggers.push_back(new TriggerNode(
        "aku'mai poison cloud",
        NextAction::array(0, new NextAction("aku'mai move away from poison cloud", ACTION_MOVE + 5), NULL)));
}

void AkuMaiFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end aku'mai fight",
        NextAction::array(0, new NextAction("disable aku'mai fight strategy", 100.0f), NULL)));
}

void AkuMaiFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end aku'mai fight",
        NextAction::array(0, new NextAction("disable aku'mai fight strategy", 100.0f), NULL)));
}
