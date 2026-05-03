#include "playerbot/playerbot.h"
#include "DmStrategy.h"

using namespace ai;

// ── DireMaulDungeonStrategy ───────────────────────────────────────────────────

void DireMaulDungeonStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // East
    triggers.push_back(new TriggerNode(
        "start zevrim thornhoof fight",
        NextAction::array(0, new NextAction("enable zevrim thornhoof fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start hydrospawn fight",
        NextAction::array(0, new NextAction("enable hydrospawn fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start lethtendris fight",
        NextAction::array(0, new NextAction("enable lethtendris fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start alzzin the wildshaper fight",
        NextAction::array(0, new NextAction("enable alzzin the wildshaper fight strategy", 100.0f), NULL)));

    // West
    triggers.push_back(new TriggerNode(
        "start tendris warpwood fight",
        NextAction::array(0, new NextAction("enable tendris warpwood fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start illyanna ravenoak fight",
        NextAction::array(0, new NextAction("enable illyanna ravenoak fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start magister kalendris fight",
        NextAction::array(0, new NextAction("enable magister kalendris fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start immol'thar fight",
        NextAction::array(0, new NextAction("enable immol'thar fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start prince tortheldrin fight",
        NextAction::array(0, new NextAction("enable prince tortheldrin fight strategy", 100.0f), NULL)));

    // North
    triggers.push_back(new TriggerNode(
        "start guard mol'dar fight",
        NextAction::array(0, new NextAction("enable guard mol'dar fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start stomper kreeg fight",
        NextAction::array(0, new NextAction("enable stomper kreeg fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start guard fengus fight",
        NextAction::array(0, new NextAction("enable guard fengus fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start guard slip'kik fight",
        NextAction::array(0, new NextAction("enable guard slip'kik fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start captain kromcrush fight",
        NextAction::array(0, new NextAction("enable captain kromcrush fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start king gordok fight",
        NextAction::array(0, new NextAction("enable king gordok fight strategy", 100.0f), NULL)));
}

void DireMaulDungeonStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // East
    triggers.push_back(new TriggerNode(
        "start zevrim thornhoof fight",
        NextAction::array(0, new NextAction("enable zevrim thornhoof fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start hydrospawn fight",
        NextAction::array(0, new NextAction("enable hydrospawn fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start lethtendris fight",
        NextAction::array(0, new NextAction("enable lethtendris fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start alzzin the wildshaper fight",
        NextAction::array(0, new NextAction("enable alzzin the wildshaper fight strategy", 100.0f), NULL)));

    // West
    triggers.push_back(new TriggerNode(
        "start tendris warpwood fight",
        NextAction::array(0, new NextAction("enable tendris warpwood fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start illyanna ravenoak fight",
        NextAction::array(0, new NextAction("enable illyanna ravenoak fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start magister kalendris fight",
        NextAction::array(0, new NextAction("enable magister kalendris fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start immol'thar fight",
        NextAction::array(0, new NextAction("enable immol'thar fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start prince tortheldrin fight",
        NextAction::array(0, new NextAction("enable prince tortheldrin fight strategy", 100.0f), NULL)));

    // North
    triggers.push_back(new TriggerNode(
        "start guard mol'dar fight",
        NextAction::array(0, new NextAction("enable guard mol'dar fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start stomper kreeg fight",
        NextAction::array(0, new NextAction("enable stomper kreeg fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start guard fengus fight",
        NextAction::array(0, new NextAction("enable guard fengus fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start guard slip'kik fight",
        NextAction::array(0, new NextAction("enable guard slip'kik fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start captain kromcrush fight",
        NextAction::array(0, new NextAction("enable captain kromcrush fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start king gordok fight",
        NextAction::array(0, new NextAction("enable king gordok fight strategy", 100.0f), NULL)));
}

// ── ZevrimThornhoofFightStrategy ──────────────────────────────────────────────

void ZevrimThornhoofFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end zevrim thornhoof fight",
        NextAction::array(0, new NextAction("disable zevrim thornhoof fight strategy", 100.0f), NULL)));
}

void ZevrimThornhoofFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end zevrim thornhoof fight",
        NextAction::array(0, new NextAction("disable zevrim thornhoof fight strategy", 100.0f), NULL)));
}

// ── HydrospawnFightStrategy ───────────────────────────────────────────────────

void HydrospawnFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end hydrospawn fight",
        NextAction::array(0, new NextAction("disable hydrospawn fight strategy", 100.0f), NULL)));
}

void HydrospawnFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end hydrospawn fight",
        NextAction::array(0, new NextAction("disable hydrospawn fight strategy", 100.0f), NULL)));
}

// ── LehtendrisFightStrategy ───────────────────────────────────────────────────

void LehtendrisFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end lethtendris fight",
        NextAction::array(0, new NextAction("disable lethtendris fight strategy", 100.0f), NULL)));
}

void LehtendrisFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end lethtendris fight",
        NextAction::array(0, new NextAction("disable lethtendris fight strategy", 100.0f), NULL)));
}

// ── AlzzinTheWildshaperFightStrategy ─────────────────────────────────────────

void AlzzinTheWildshaperFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Earthgrip ~10yd AoE root — stay >12yd
    triggers.push_back(new TriggerNode(
        "alzzin earthgrip",
        NextAction::array(0, new NextAction("alzzin move away from earthgrip", ACTION_MOVE + 5), NULL)));
}

void AlzzinTheWildshaperFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end alzzin the wildshaper fight",
        NextAction::array(0, new NextAction("disable alzzin the wildshaper fight strategy", 100.0f), NULL)));
}

void AlzzinTheWildshaperFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end alzzin the wildshaper fight",
        NextAction::array(0, new NextAction("disable alzzin the wildshaper fight strategy", 100.0f), NULL)));
}

// ── TendrisWarpwoodFightStrategy ──────────────────────────────────────────────

void TendrisWarpwoodFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Entangle ~8yd AoE root — stay >10yd
    triggers.push_back(new TriggerNode(
        "tendris entangle",
        NextAction::array(0, new NextAction("tendris move away from entangle", ACTION_MOVE + 5), NULL)));
}

void TendrisWarpwoodFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end tendris warpwood fight",
        NextAction::array(0, new NextAction("disable tendris warpwood fight strategy", 100.0f), NULL)));
}

void TendrisWarpwoodFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end tendris warpwood fight",
        NextAction::array(0, new NextAction("disable tendris warpwood fight strategy", 100.0f), NULL)));
}

// ── IllyannaRavenoakFightStrategy ─────────────────────────────────────────────

void IllyannaRavenoakFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end illyanna ravenoak fight",
        NextAction::array(0, new NextAction("disable illyanna ravenoak fight strategy", 100.0f), NULL)));
}

void IllyannaRavenoakFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end illyanna ravenoak fight",
        NextAction::array(0, new NextAction("disable illyanna ravenoak fight strategy", 100.0f), NULL)));
}

// ── MagisterKalendrisFightStrategy ───────────────────────────────────────────

void MagisterKalendrisFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end magister kalendris fight",
        NextAction::array(0, new NextAction("disable magister kalendris fight strategy", 100.0f), NULL)));
}

void MagisterKalendrisFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end magister kalendris fight",
        NextAction::array(0, new NextAction("disable magister kalendris fight strategy", 100.0f), NULL)));
}

// ── ImmoltharFightStrategy ────────────────────────────────────────────────────

void ImmoltharFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Disease Cloud ~10yd persistent AoE — stay >12yd
    triggers.push_back(new TriggerNode(
        "immol'thar disease cloud",
        NextAction::array(0, new NextAction("immol'thar move away from disease cloud", ACTION_MOVE + 5), NULL)));
}

void ImmoltharFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end immol'thar fight",
        NextAction::array(0, new NextAction("disable immol'thar fight strategy", 100.0f), NULL)));
}

void ImmoltharFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end immol'thar fight",
        NextAction::array(0, new NextAction("disable immol'thar fight strategy", 100.0f), NULL)));
}

// ── PrinceTortheldrinFightStrategy ────────────────────────────────────────────

void PrinceTortheldrinFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Arcane Blast + Whirlwind ~8yd AoE — stay >10yd
    triggers.push_back(new TriggerNode(
        "tortheldrin arcane blast",
        NextAction::array(0, new NextAction("tortheldrin move away from arcane blast", ACTION_MOVE + 5), NULL)));
}

void PrinceTortheldrinFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end prince tortheldrin fight",
        NextAction::array(0, new NextAction("disable prince tortheldrin fight strategy", 100.0f), NULL)));
}

void PrinceTortheldrinFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end prince tortheldrin fight",
        NextAction::array(0, new NextAction("disable prince tortheldrin fight strategy", 100.0f), NULL)));
}

// ── GuardMoldarFightStrategy ──────────────────────────────────────────────────

void GuardMoldarFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // War Stomp ~8yd AoE — stay >10yd
    triggers.push_back(new TriggerNode(
        "mol'dar war stomp",
        NextAction::array(0, new NextAction("mol'dar move away from war stomp", ACTION_MOVE + 5), NULL)));
}

void GuardMoldarFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end guard mol'dar fight",
        NextAction::array(0, new NextAction("disable guard mol'dar fight strategy", 100.0f), NULL)));
}

void GuardMoldarFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end guard mol'dar fight",
        NextAction::array(0, new NextAction("disable guard mol'dar fight strategy", 100.0f), NULL)));
}

// ── StomperKreegFightStrategy ─────────────────────────────────────────────────

void StomperKreegFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Knock Away ~8yd AoE knockback — stay >10yd
    triggers.push_back(new TriggerNode(
        "kreeg knock away",
        NextAction::array(0, new NextAction("kreeg move away from knock away", ACTION_MOVE + 5), NULL)));
}

void StomperKreegFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end stomper kreeg fight",
        NextAction::array(0, new NextAction("disable stomper kreeg fight strategy", 100.0f), NULL)));
}

void StomperKreegFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end stomper kreeg fight",
        NextAction::array(0, new NextAction("disable stomper kreeg fight strategy", 100.0f), NULL)));
}

// ── GuardFengusFightStrategy ──────────────────────────────────────────────────

void GuardFengusFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end guard fengus fight",
        NextAction::array(0, new NextAction("disable guard fengus fight strategy", 100.0f), NULL)));
}

void GuardFengusFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end guard fengus fight",
        NextAction::array(0, new NextAction("disable guard fengus fight strategy", 100.0f), NULL)));
}

// ── GuardSlipkikFightStrategy ─────────────────────────────────────────────────

void GuardSlipkikFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Frost Nova ~8yd AoE freeze — stay >10yd
    triggers.push_back(new TriggerNode(
        "slip'kik frost nova",
        NextAction::array(0, new NextAction("slip'kik move away from frost nova", ACTION_MOVE + 5), NULL)));
}

void GuardSlipkikFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end guard slip'kik fight",
        NextAction::array(0, new NextAction("disable guard slip'kik fight strategy", 100.0f), NULL)));
}

void GuardSlipkikFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end guard slip'kik fight",
        NextAction::array(0, new NextAction("disable guard slip'kik fight strategy", 100.0f), NULL)));
}

// ── CaptainKromcrushFightStrategy ─────────────────────────────────────────────

void CaptainKromcrushFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // War Stomp ~8yd AoE — stay >10yd
    triggers.push_back(new TriggerNode(
        "kromcrush war stomp",
        NextAction::array(0, new NextAction("kromcrush move away from war stomp", ACTION_MOVE + 5), NULL)));
}

void CaptainKromcrushFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end captain kromcrush fight",
        NextAction::array(0, new NextAction("disable captain kromcrush fight strategy", 100.0f), NULL)));
}

void CaptainKromcrushFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end captain kromcrush fight",
        NextAction::array(0, new NextAction("disable captain kromcrush fight strategy", 100.0f), NULL)));
}

// ── KingGordokFightStrategy ───────────────────────────────────────────────────

void KingGordokFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Thunderclap ~8yd AoE physical — stay >10yd
    triggers.push_back(new TriggerNode(
        "gordok thunderclap",
        NextAction::array(0, new NextAction("gordok move away from thunderclap", ACTION_MOVE + 5), NULL)));
}

void KingGordokFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end king gordok fight",
        NextAction::array(0, new NextAction("disable king gordok fight strategy", 100.0f), NULL)));
}

void KingGordokFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end king gordok fight",
        NextAction::array(0, new NextAction("disable king gordok fight strategy", 100.0f), NULL)));
}
