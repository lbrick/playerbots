#include "playerbot/playerbot.h"
#include "ZfStrategy.h"

using namespace ai;

// ── ZulFarrakDungeonStrategy ──────────────────────────────────────────────────

void ZulFarrakDungeonStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "start theka the martyr fight",
        NextAction::array(0, new NextAction("enable theka the martyr fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start witch doctor zum'rah fight",
        NextAction::array(0, new NextAction("enable witch doctor zum'rah fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start antu'sul fight",
        NextAction::array(0, new NextAction("enable antu'sul fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start shadowpriest sezz'ziz fight",
        NextAction::array(0, new NextAction("enable shadowpriest sezz'ziz fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start sergeant bly fight",
        NextAction::array(0, new NextAction("enable sergeant bly fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start gahz'rilla fight",
        NextAction::array(0, new NextAction("enable gahz'rilla fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start chief ukorz sandscalp fight",
        NextAction::array(0, new NextAction("enable chief ukorz sandscalp fight strategy", 100.0f), NULL)));
}

void ZulFarrakDungeonStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "start theka the martyr fight",
        NextAction::array(0, new NextAction("enable theka the martyr fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start witch doctor zum'rah fight",
        NextAction::array(0, new NextAction("enable witch doctor zum'rah fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start antu'sul fight",
        NextAction::array(0, new NextAction("enable antu'sul fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start shadowpriest sezz'ziz fight",
        NextAction::array(0, new NextAction("enable shadowpriest sezz'ziz fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start sergeant bly fight",
        NextAction::array(0, new NextAction("enable sergeant bly fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start gahz'rilla fight",
        NextAction::array(0, new NextAction("enable gahz'rilla fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start chief ukorz sandscalp fight",
        NextAction::array(0, new NextAction("enable chief ukorz sandscalp fight strategy", 100.0f), NULL)));
}

// ── ThekaTheMartyrFightStrategy ───────────────────────────────────────────────

void ThekaTheMartyrFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end theka the martyr fight",
        NextAction::array(0, new NextAction("disable theka the martyr fight strategy", 100.0f), NULL)));
}

void ThekaTheMartyrFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end theka the martyr fight",
        NextAction::array(0, new NextAction("disable theka the martyr fight strategy", 100.0f), NULL)));
}

// ── WitchDoctorZumrahFightStrategy ────────────────────────────────────────────

void WitchDoctorZumrahFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end witch doctor zum'rah fight",
        NextAction::array(0, new NextAction("disable witch doctor zum'rah fight strategy", 100.0f), NULL)));
}

void WitchDoctorZumrahFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end witch doctor zum'rah fight",
        NextAction::array(0, new NextAction("disable witch doctor zum'rah fight strategy", 100.0f), NULL)));
}

// ── AntusulFightStrategy ──────────────────────────────────────────────────────

void AntusulFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end antu'sul fight",
        NextAction::array(0, new NextAction("disable antu'sul fight strategy", 100.0f), NULL)));
}

void AntusulFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end antu'sul fight",
        NextAction::array(0, new NextAction("disable antu'sul fight strategy", 100.0f), NULL)));
}

// ── ShadowpriestSezzizFightStrategy ──────────────────────────────────────────

void ShadowpriestSezzizFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end shadowpriest sezz'ziz fight",
        NextAction::array(0, new NextAction("disable shadowpriest sezz'ziz fight strategy", 100.0f), NULL)));
}

void ShadowpriestSezzizFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end shadowpriest sezz'ziz fight",
        NextAction::array(0, new NextAction("disable shadowpriest sezz'ziz fight strategy", 100.0f), NULL)));
}

// ── SergeantBlyFightStrategy ──────────────────────────────────────────────────

void SergeantBlyFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end sergeant bly fight",
        NextAction::array(0, new NextAction("disable sergeant bly fight strategy", 100.0f), NULL)));
}

void SergeantBlyFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end sergeant bly fight",
        NextAction::array(0, new NextAction("disable sergeant bly fight strategy", 100.0f), NULL)));
}

// ── GahzrillaFightStrategy ────────────────────────────────────────────────────

void GahzrillaFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Freeze ~10yd AoE — stay >12yd
    triggers.push_back(new TriggerNode(
        "gahz'rilla freeze",
        NextAction::array(0, new NextAction("gahz'rilla move away from freeze", ACTION_MOVE + 5), NULL)));
}

void GahzrillaFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end gahz'rilla fight",
        NextAction::array(0, new NextAction("disable gahz'rilla fight strategy", 100.0f), NULL)));
}

void GahzrillaFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end gahz'rilla fight",
        NextAction::array(0, new NextAction("disable gahz'rilla fight strategy", 100.0f), NULL)));
}

// ── ChiefUkorzSandscalpFightStrategy ─────────────────────────────────────────

void ChiefUkorzSandscalpFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end chief ukorz sandscalp fight",
        NextAction::array(0, new NextAction("disable chief ukorz sandscalp fight strategy", 100.0f), NULL)));
}

void ChiefUkorzSandscalpFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end chief ukorz sandscalp fight",
        NextAction::array(0, new NextAction("disable chief ukorz sandscalp fight strategy", 100.0f), NULL)));
}
