#include "playerbot/playerbot.h"
#include "GnomerStrategy.h"

using namespace ai;

// ── GnomereganDungeonStrategy ─────────────────────────────────────────────────

void GnomereganDungeonStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "start grubbis fight",
        NextAction::array(0, new NextAction("enable grubbis fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start viscous fallout fight",
        NextAction::array(0, new NextAction("enable viscous fallout fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start electrocutioner fight",
        NextAction::array(0, new NextAction("enable electrocutioner fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start crowd pummeler fight",
        NextAction::array(0, new NextAction("enable crowd pummeler fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start thermaplugg fight",
        NextAction::array(0, new NextAction("enable thermaplugg fight strategy", 100.0f), NULL)));
}

void GnomereganDungeonStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "start grubbis fight",
        NextAction::array(0, new NextAction("enable grubbis fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start viscous fallout fight",
        NextAction::array(0, new NextAction("enable viscous fallout fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start electrocutioner fight",
        NextAction::array(0, new NextAction("enable electrocutioner fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start crowd pummeler fight",
        NextAction::array(0, new NextAction("enable crowd pummeler fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start thermaplugg fight",
        NextAction::array(0, new NextAction("enable thermaplugg fight strategy", 100.0f), NULL)));
}

// ── GrubbisFightStrategy ──────────────────────────────────────────────────────

void GrubbisFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end grubbis fight",
        NextAction::array(0, new NextAction("disable grubbis fight strategy", 100.0f), NULL)));
}

void GrubbisFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end grubbis fight",
        NextAction::array(0, new NextAction("disable grubbis fight strategy", 100.0f), NULL)));
}

// ── ViscousFalloutFightStrategy ───────────────────────────────────────────────

void ViscousFalloutFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Acid Splash puddle ~8yd + Corrosive Aura — stay >10yd
    triggers.push_back(new TriggerNode(
        "viscous fallout acid splash",
        NextAction::array(0, new NextAction("viscous fallout move away from acid splash", ACTION_MOVE + 5), NULL)));
}

void ViscousFalloutFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end viscous fallout fight",
        NextAction::array(0, new NextAction("disable viscous fallout fight strategy", 100.0f), NULL)));
}

void ViscousFalloutFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end viscous fallout fight",
        NextAction::array(0, new NextAction("disable viscous fallout fight strategy", 100.0f), NULL)));
}

// ── ElectrocutionerFightStrategy ──────────────────────────────────────────────

void ElectrocutionerFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Lightning Arc chain ~10yd + Megavolt stun ~12yd — spread >12yd
    triggers.push_back(new TriggerNode(
        "electrocutioner lightning arc",
        NextAction::array(0, new NextAction("electrocutioner move away from lightning arc", ACTION_MOVE + 5), NULL)));
}

void ElectrocutionerFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end electrocutioner fight",
        NextAction::array(0, new NextAction("disable electrocutioner fight strategy", 100.0f), NULL)));
}

void ElectrocutionerFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end electrocutioner fight",
        NextAction::array(0, new NextAction("disable electrocutioner fight strategy", 100.0f), NULL)));
}

// ── CrowdPummelerFightStrategy ────────────────────────────────────────────────

void CrowdPummelerFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Arcing Smash frontal ~8yd + Trample — stay >10yd
    triggers.push_back(new TriggerNode(
        "crowd pummeler arcing smash",
        NextAction::array(0, new NextAction("crowd pummeler move away from arcing smash", ACTION_MOVE + 5), NULL)));
}

void CrowdPummelerFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end crowd pummeler fight",
        NextAction::array(0, new NextAction("disable crowd pummeler fight strategy", 100.0f), NULL)));
}

void CrowdPummelerFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end crowd pummeler fight",
        NextAction::array(0, new NextAction("disable crowd pummeler fight strategy", 100.0f), NULL)));
}

// ── ThermapluggFightStrategy ──────────────────────────────────────────────────

void ThermapluggFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Leper Gnome Sappers run to random players and explode ~8yd — spread >10yd
    triggers.push_back(new TriggerNode(
        "thermaplugg bomb spread",
        NextAction::array(0, new NextAction("thermaplugg move away from bombs", ACTION_MOVE + 5), NULL)));
}

void ThermapluggFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end thermaplugg fight",
        NextAction::array(0, new NextAction("disable thermaplugg fight strategy", 100.0f), NULL)));
}

void ThermapluggFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end thermaplugg fight",
        NextAction::array(0, new NextAction("disable thermaplugg fight strategy", 100.0f), NULL)));
}
