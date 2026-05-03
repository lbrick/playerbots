#include "playerbot/playerbot.h"
#include "RfcStrategy.h"

using namespace ai;

// ── RagefireChasmDungeonStrategy ──────────────────────────────────────────────

void RagefireChasmDungeonStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Handle bots summoned into instance already in combat
    triggers.push_back(new TriggerNode(
        "start oggleflint fight",
        NextAction::array(0, new NextAction("enable oggleflint fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start taragaman fight",
        NextAction::array(0, new NextAction("enable taragaman fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start jergosh fight",
        NextAction::array(0, new NextAction("enable jergosh fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start bazzalan fight",
        NextAction::array(0, new NextAction("enable bazzalan fight strategy", 100.0f), NULL)));
}

void RagefireChasmDungeonStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "start oggleflint fight",
        NextAction::array(0, new NextAction("enable oggleflint fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start taragaman fight",
        NextAction::array(0, new NextAction("enable taragaman fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start jergosh fight",
        NextAction::array(0, new NextAction("enable jergosh fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start bazzalan fight",
        NextAction::array(0, new NextAction("enable bazzalan fight strategy", 100.0f), NULL)));
}

// ── OggleflintFightStrategy ───────────────────────────────────────────────────

void OggleflintFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end oggleflint fight",
        NextAction::array(0, new NextAction("disable oggleflint fight strategy", 100.0f), NULL)));
}

void OggleflintFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end oggleflint fight",
        NextAction::array(0, new NextAction("disable oggleflint fight strategy", 100.0f), NULL)));
}

// ── TaragamanFightStrategy ────────────────────────────────────────────────────

void TaragamanFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Firenova AoE ~10yd — move away at ACTION_MOVE+5 to interrupt normal combat
    triggers.push_back(new TriggerNode(
        "taragaman firenova",
        NextAction::array(0, new NextAction("taragaman move away from firenova", ACTION_MOVE + 5), NULL)));
}

void TaragamanFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end taragaman fight",
        NextAction::array(0, new NextAction("disable taragaman fight strategy", 100.0f), NULL)));
}

void TaragamanFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end taragaman fight",
        NextAction::array(0, new NextAction("disable taragaman fight strategy", 100.0f), NULL)));
}

// ── JergoshFightStrategy ──────────────────────────────────────────────────────

void JergoshFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "target casting jergosh immolate",
        NextAction::array(0, new NextAction("interrupt enemy cast", ACTION_HIGH + 5), NULL)));
}

void JergoshFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end jergosh fight",
        NextAction::array(0, new NextAction("disable jergosh fight strategy", 100.0f), NULL)));
}

void JergoshFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end jergosh fight",
        NextAction::array(0, new NextAction("disable jergosh fight strategy", 100.0f), NULL)));
}

// ── BazzalanFightStrategy ─────────────────────────────────────────────────────

void BazzalanFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end bazzalan fight",
        NextAction::array(0, new NextAction("disable bazzalan fight strategy", 100.0f), NULL)));
}

void BazzalanFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end bazzalan fight",
        NextAction::array(0, new NextAction("disable bazzalan fight strategy", 100.0f), NULL)));
}
