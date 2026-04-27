#include "playerbot/playerbot.h"
#include "StocksStrategy.h"

using namespace ai;

// ── StocksDungeonStrategy ─────────────────────────────────────────────────────

void StocksDungeonStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "start targorr fight",
        NextAction::array(0, new NextAction("enable targorr fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start kam deepfury fight",
        NextAction::array(0, new NextAction("enable kam deepfury fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start hamhock fight",
        NextAction::array(0, new NextAction("enable hamhock fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start bazil thredd fight",
        NextAction::array(0, new NextAction("enable bazil thredd fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start dextren ward fight",
        NextAction::array(0, new NextAction("enable dextren ward fight strategy", 100.0f), NULL)));
}

void StocksDungeonStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "start targorr fight",
        NextAction::array(0, new NextAction("enable targorr fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start kam deepfury fight",
        NextAction::array(0, new NextAction("enable kam deepfury fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start hamhock fight",
        NextAction::array(0, new NextAction("enable hamhock fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start bazil thredd fight",
        NextAction::array(0, new NextAction("enable bazil thredd fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start dextren ward fight",
        NextAction::array(0, new NextAction("enable dextren ward fight strategy", 100.0f), NULL)));
}

// ── TargorrFightStrategy ──────────────────────────────────────────────────────

void TargorrFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Slam knockback ~5yd — stay >8yd
    triggers.push_back(new TriggerNode(
        "targorr slam",
        NextAction::array(0, new NextAction("targorr move away from slam", ACTION_MOVE + 5), NULL)));
}

void TargorrFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end targorr fight",
        NextAction::array(0, new NextAction("disable targorr fight strategy", 100.0f), NULL)));
}

void TargorrFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end targorr fight",
        NextAction::array(0, new NextAction("disable targorr fight strategy", 100.0f), NULL)));
}

// ── KamDeepfuryFightStrategy ──────────────────────────────────────────────────

void KamDeepfuryFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end kam deepfury fight",
        NextAction::array(0, new NextAction("disable kam deepfury fight strategy", 100.0f), NULL)));
}

void KamDeepfuryFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end kam deepfury fight",
        NextAction::array(0, new NextAction("disable kam deepfury fight strategy", 100.0f), NULL)));
}

// ── HamhockFightStrategy ──────────────────────────────────────────────────────

void HamhockFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Chain Lightning jumps ~10yd — spread >12yd to break chain
    triggers.push_back(new TriggerNode(
        "hamhock chain lightning",
        NextAction::array(0, new NextAction("hamhock move away from chain lightning", ACTION_MOVE + 5), NULL)));
}

void HamhockFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end hamhock fight",
        NextAction::array(0, new NextAction("disable hamhock fight strategy", 100.0f), NULL)));
}

void HamhockFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end hamhock fight",
        NextAction::array(0, new NextAction("disable hamhock fight strategy", 100.0f), NULL)));
}

// ── BazilThreddFightStrategy ──────────────────────────────────────────────────

void BazilThreddFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end bazil thredd fight",
        NextAction::array(0, new NextAction("disable bazil thredd fight strategy", 100.0f), NULL)));
}

void BazilThreddFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end bazil thredd fight",
        NextAction::array(0, new NextAction("disable bazil thredd fight strategy", 100.0f), NULL)));
}

// ── DextrenWardFightStrategy ──────────────────────────────────────────────────

void DextrenWardFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Intimidating Shout fear 10yd — pre-position >12yd to stay outside radius
    triggers.push_back(new TriggerNode(
        "dextren ward intimidating shout",
        NextAction::array(0, new NextAction("dextren ward move away from intimidating shout", ACTION_MOVE + 5), NULL)));
}

void DextrenWardFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end dextren ward fight",
        NextAction::array(0, new NextAction("disable dextren ward fight strategy", 100.0f), NULL)));
}

void DextrenWardFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end dextren ward fight",
        NextAction::array(0, new NextAction("disable dextren ward fight strategy", 100.0f), NULL)));
}
