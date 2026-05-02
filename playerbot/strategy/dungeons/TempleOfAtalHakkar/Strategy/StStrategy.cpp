#include "playerbot/playerbot.h"
#include "StStrategy.h"

using namespace ai;

// ── TempleOfAtalHakkarDungeonStrategy ─────────────────────────────────────────

void TempleOfAtalHakkarDungeonStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "start zolo fight",
        NextAction::array(0, new NextAction("enable zolo fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start hukku fight",
        NextAction::array(0, new NextAction("enable hukku fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start gasher fight",
        NextAction::array(0, new NextAction("enable gasher fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start loro fight",
        NextAction::array(0, new NextAction("enable loro fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start mijan fight",
        NextAction::array(0, new NextAction("enable mijan fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start zul'lor fight",
        NextAction::array(0, new NextAction("enable zul'lor fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start jammal'an the prophet fight",
        NextAction::array(0, new NextAction("enable jammal'an the prophet fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start ogom the wretched fight",
        NextAction::array(0, new NextAction("enable ogom the wretched fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start morphaz fight",
        NextAction::array(0, new NextAction("enable morphaz fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start hazzas fight",
        NextAction::array(0, new NextAction("enable hazzas fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start shade of eranikus fight",
        NextAction::array(0, new NextAction("enable shade of eranikus fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start avatar of hakkar fight",
        NextAction::array(0, new NextAction("enable avatar of hakkar fight strategy", 100.0f), NULL)));
}

void TempleOfAtalHakkarDungeonStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "start zolo fight",
        NextAction::array(0, new NextAction("enable zolo fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start hukku fight",
        NextAction::array(0, new NextAction("enable hukku fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start gasher fight",
        NextAction::array(0, new NextAction("enable gasher fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start loro fight",
        NextAction::array(0, new NextAction("enable loro fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start mijan fight",
        NextAction::array(0, new NextAction("enable mijan fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start zul'lor fight",
        NextAction::array(0, new NextAction("enable zul'lor fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start jammal'an the prophet fight",
        NextAction::array(0, new NextAction("enable jammal'an the prophet fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start ogom the wretched fight",
        NextAction::array(0, new NextAction("enable ogom the wretched fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start morphaz fight",
        NextAction::array(0, new NextAction("enable morphaz fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start hazzas fight",
        NextAction::array(0, new NextAction("enable hazzas fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start shade of eranikus fight",
        NextAction::array(0, new NextAction("enable shade of eranikus fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start avatar of hakkar fight",
        NextAction::array(0, new NextAction("enable avatar of hakkar fight strategy", 100.0f), NULL)));
}

// ── ZoloFightStrategy ─────────────────────────────────────────────────────────

void ZoloFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end zolo fight",
        NextAction::array(0, new NextAction("disable zolo fight strategy", 100.0f), NULL)));
}

void ZoloFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end zolo fight",
        NextAction::array(0, new NextAction("disable zolo fight strategy", 100.0f), NULL)));
}

// ── HukkuFightStrategy ────────────────────────────────────────────────────────

void HukkuFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end hukku fight",
        NextAction::array(0, new NextAction("disable hukku fight strategy", 100.0f), NULL)));
}

void HukkuFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end hukku fight",
        NextAction::array(0, new NextAction("disable hukku fight strategy", 100.0f), NULL)));
}

// ── GasherFightStrategy ───────────────────────────────────────────────────────

void GasherFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end gasher fight",
        NextAction::array(0, new NextAction("disable gasher fight strategy", 100.0f), NULL)));
}

void GasherFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end gasher fight",
        NextAction::array(0, new NextAction("disable gasher fight strategy", 100.0f), NULL)));
}

// ── LoroFightStrategy ─────────────────────────────────────────────────────────

void LoroFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end loro fight",
        NextAction::array(0, new NextAction("disable loro fight strategy", 100.0f), NULL)));
}

void LoroFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end loro fight",
        NextAction::array(0, new NextAction("disable loro fight strategy", 100.0f), NULL)));
}

// ── MijanFightStrategy ────────────────────────────────────────────────────────

void MijanFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end mijan fight",
        NextAction::array(0, new NextAction("disable mijan fight strategy", 100.0f), NULL)));
}

void MijanFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end mijan fight",
        NextAction::array(0, new NextAction("disable mijan fight strategy", 100.0f), NULL)));
}

// ── ZulLorFightStrategy ───────────────────────────────────────────────────────

void ZulLorFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end zul'lor fight",
        NextAction::array(0, new NextAction("disable zul'lor fight strategy", 100.0f), NULL)));
}

void ZulLorFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end zul'lor fight",
        NextAction::array(0, new NextAction("disable zul'lor fight strategy", 100.0f), NULL)));
}

// ── JammalanTheProphetFightStrategy ───────────────────────────────────────────

void JammalanTheProphetFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end jammal'an the prophet fight",
        NextAction::array(0, new NextAction("disable jammal'an the prophet fight strategy", 100.0f), NULL)));
}

void JammalanTheProphetFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end jammal'an the prophet fight",
        NextAction::array(0, new NextAction("disable jammal'an the prophet fight strategy", 100.0f), NULL)));
}

// ── OgomTheWretchedFightStrategy ──────────────────────────────────────────────

void OgomTheWretchedFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end ogom the wretched fight",
        NextAction::array(0, new NextAction("disable ogom the wretched fight strategy", 100.0f), NULL)));
}

void OgomTheWretchedFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end ogom the wretched fight",
        NextAction::array(0, new NextAction("disable ogom the wretched fight strategy", 100.0f), NULL)));
}

// ── MorphazFightStrategy ──────────────────────────────────────────────────────

void MorphazFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end morphaz fight",
        NextAction::array(0, new NextAction("disable morphaz fight strategy", 100.0f), NULL)));
}

void MorphazFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end morphaz fight",
        NextAction::array(0, new NextAction("disable morphaz fight strategy", 100.0f), NULL)));
}

// ── HazzasFightStrategy ───────────────────────────────────────────────────────

void HazzasFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end hazzas fight",
        NextAction::array(0, new NextAction("disable hazzas fight strategy", 100.0f), NULL)));
}

void HazzasFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end hazzas fight",
        NextAction::array(0, new NextAction("disable hazzas fight strategy", 100.0f), NULL)));
}

// ── ShadeOfEranikusFightStrategy ──────────────────────────────────────────────

void ShadeOfEranikusFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // War Stomp ~8yd AoE — stay >10yd
    triggers.push_back(new TriggerNode(
        "eranikus war stomp",
        NextAction::array(0, new NextAction("eranikus move away from war stomp", ACTION_MOVE + 5), NULL)));
}

void ShadeOfEranikusFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end shade of eranikus fight",
        NextAction::array(0, new NextAction("disable shade of eranikus fight strategy", 100.0f), NULL)));
}

void ShadeOfEranikusFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end shade of eranikus fight",
        NextAction::array(0, new NextAction("disable shade of eranikus fight strategy", 100.0f), NULL)));
}

// ── AvatarOfHakkarFightStrategy ───────────────────────────────────────────────

void AvatarOfHakkarFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end avatar of hakkar fight",
        NextAction::array(0, new NextAction("disable avatar of hakkar fight strategy", 100.0f), NULL)));
}

void AvatarOfHakkarFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end avatar of hakkar fight",
        NextAction::array(0, new NextAction("disable avatar of hakkar fight strategy", 100.0f), NULL)));
}
