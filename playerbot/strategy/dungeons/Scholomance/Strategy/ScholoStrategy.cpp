#include "playerbot/playerbot.h"
#include "ScholoStrategy.h"

using namespace ai;

// ── ScholomanceDungeonStrategy ────────────────────────────────────────────────

void ScholomanceDungeonStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "start kirtonos the herald fight",
        NextAction::array(0, new NextAction("enable kirtonos the herald fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start jandice barov fight",
        NextAction::array(0, new NextAction("enable jandice barov fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start rattlegore fight",
        NextAction::array(0, new NextAction("enable rattlegore fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start marduk blackpool fight",
        NextAction::array(0, new NextAction("enable marduk blackpool fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start vectus fight",
        NextAction::array(0, new NextAction("enable vectus fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start ras frostwhisper fight",
        NextAction::array(0, new NextAction("enable ras frostwhisper fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start instructor malicia fight",
        NextAction::array(0, new NextAction("enable instructor malicia fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start doctor theolen krastinov fight",
        NextAction::array(0, new NextAction("enable doctor theolen krastinov fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start the ravenian fight",
        NextAction::array(0, new NextAction("enable the ravenian fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start lord alexei barov fight",
        NextAction::array(0, new NextAction("enable lord alexei barov fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start lady illucia barov fight",
        NextAction::array(0, new NextAction("enable lady illucia barov fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start darkmaster gandling fight",
        NextAction::array(0, new NextAction("enable darkmaster gandling fight strategy", 100.0f), NULL)));
}

void ScholomanceDungeonStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "start kirtonos the herald fight",
        NextAction::array(0, new NextAction("enable kirtonos the herald fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start jandice barov fight",
        NextAction::array(0, new NextAction("enable jandice barov fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start rattlegore fight",
        NextAction::array(0, new NextAction("enable rattlegore fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start marduk blackpool fight",
        NextAction::array(0, new NextAction("enable marduk blackpool fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start vectus fight",
        NextAction::array(0, new NextAction("enable vectus fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start ras frostwhisper fight",
        NextAction::array(0, new NextAction("enable ras frostwhisper fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start instructor malicia fight",
        NextAction::array(0, new NextAction("enable instructor malicia fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start doctor theolen krastinov fight",
        NextAction::array(0, new NextAction("enable doctor theolen krastinov fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start the ravenian fight",
        NextAction::array(0, new NextAction("enable the ravenian fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start lord alexei barov fight",
        NextAction::array(0, new NextAction("enable lord alexei barov fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start lady illucia barov fight",
        NextAction::array(0, new NextAction("enable lady illucia barov fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start darkmaster gandling fight",
        NextAction::array(0, new NextAction("enable darkmaster gandling fight strategy", 100.0f), NULL)));
}

// ── KirtonostheHeraldFightStrategy ────────────────────────────────────────────

void KirtonostheHeraldFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Blood Offering ~8yd AoE shadow — stay >10yd
    triggers.push_back(new TriggerNode(
        "kirtonos blood offering",
        NextAction::array(0, new NextAction("kirtonos move away from blood offering", ACTION_MOVE + 5), NULL)));
}

void KirtonostheHeraldFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end kirtonos the herald fight",
        NextAction::array(0, new NextAction("disable kirtonos the herald fight strategy", 100.0f), NULL)));
}

void KirtonostheHeraldFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end kirtonos the herald fight",
        NextAction::array(0, new NextAction("disable kirtonos the herald fight strategy", 100.0f), NULL)));
}

// ── JandiceBarovFightStrategy ─────────────────────────────────────────────────

void JandiceBarovFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end jandice barov fight",
        NextAction::array(0, new NextAction("disable jandice barov fight strategy", 100.0f), NULL)));
}

void JandiceBarovFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end jandice barov fight",
        NextAction::array(0, new NextAction("disable jandice barov fight strategy", 100.0f), NULL)));
}

// ── RattlegoreFightStrategy ───────────────────────────────────────────────────

void RattlegoreFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end rattlegore fight",
        NextAction::array(0, new NextAction("disable rattlegore fight strategy", 100.0f), NULL)));
}

void RattlegoreFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end rattlegore fight",
        NextAction::array(0, new NextAction("disable rattlegore fight strategy", 100.0f), NULL)));
}

// ── MardukBlackpoolFightStrategy ──────────────────────────────────────────────

void MardukBlackpoolFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end marduk blackpool fight",
        NextAction::array(0, new NextAction("disable marduk blackpool fight strategy", 100.0f), NULL)));
}

void MardukBlackpoolFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end marduk blackpool fight",
        NextAction::array(0, new NextAction("disable marduk blackpool fight strategy", 100.0f), NULL)));
}

// ── VectusFightStrategy ───────────────────────────────────────────────────────

void VectusFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Blizzard ~10yd AoE frost — stay >12yd
    triggers.push_back(new TriggerNode(
        "vectus blizzard",
        NextAction::array(0, new NextAction("vectus move away from blizzard", ACTION_MOVE + 5), NULL)));
}

void VectusFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end vectus fight",
        NextAction::array(0, new NextAction("disable vectus fight strategy", 100.0f), NULL)));
}

void VectusFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end vectus fight",
        NextAction::array(0, new NextAction("disable vectus fight strategy", 100.0f), NULL)));
}

// ── RasFrostwhisperFightStrategy ──────────────────────────────────────────────

void RasFrostwhisperFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Frost Nova ~8yd AoE freeze — stay >10yd
    triggers.push_back(new TriggerNode(
        "ras frost nova",
        NextAction::array(0, new NextAction("ras move away from frost nova", ACTION_MOVE + 5), NULL)));
}

void RasFrostwhisperFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end ras frostwhisper fight",
        NextAction::array(0, new NextAction("disable ras frostwhisper fight strategy", 100.0f), NULL)));
}

void RasFrostwhisperFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end ras frostwhisper fight",
        NextAction::array(0, new NextAction("disable ras frostwhisper fight strategy", 100.0f), NULL)));
}

// ── InstructorMaliciaFightStrategy ────────────────────────────────────────────

void InstructorMaliciaFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Poison Nova ~10yd AoE poison — stay >12yd
    triggers.push_back(new TriggerNode(
        "malicia poison nova",
        NextAction::array(0, new NextAction("malicia move away from poison nova", ACTION_MOVE + 5), NULL)));
}

void InstructorMaliciaFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end instructor malicia fight",
        NextAction::array(0, new NextAction("disable instructor malicia fight strategy", 100.0f), NULL)));
}

void InstructorMaliciaFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end instructor malicia fight",
        NextAction::array(0, new NextAction("disable instructor malicia fight strategy", 100.0f), NULL)));
}

// ── DoctorTheolenKrastinovFightStrategy ──────────────────────────────────────

void DoctorTheolenKrastinovFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end doctor theolen krastinov fight",
        NextAction::array(0, new NextAction("disable doctor theolen krastinov fight strategy", 100.0f), NULL)));
}

void DoctorTheolenKrastinovFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end doctor theolen krastinov fight",
        NextAction::array(0, new NextAction("disable doctor theolen krastinov fight strategy", 100.0f), NULL)));
}

// ── TheRavenianFightStrategy ──────────────────────────────────────────────────

void TheRavenianFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Trample ~8yd AoE physical — stay >10yd
    triggers.push_back(new TriggerNode(
        "the ravenian trample",
        NextAction::array(0, new NextAction("the ravenian move away from trample", ACTION_MOVE + 5), NULL)));
}

void TheRavenianFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end the ravenian fight",
        NextAction::array(0, new NextAction("disable the ravenian fight strategy", 100.0f), NULL)));
}

void TheRavenianFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end the ravenian fight",
        NextAction::array(0, new NextAction("disable the ravenian fight strategy", 100.0f), NULL)));
}

// ── LordAlexeiBarovFightStrategy ──────────────────────────────────────────────

void LordAlexeiBarovFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end lord alexei barov fight",
        NextAction::array(0, new NextAction("disable lord alexei barov fight strategy", 100.0f), NULL)));
}

void LordAlexeiBarovFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end lord alexei barov fight",
        NextAction::array(0, new NextAction("disable lord alexei barov fight strategy", 100.0f), NULL)));
}

// ── LadyIlluciaBarovFightStrategy ─────────────────────────────────────────────

void LadyIlluciaBarovFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end lady illucia barov fight",
        NextAction::array(0, new NextAction("disable lady illucia barov fight strategy", 100.0f), NULL)));
}

void LadyIlluciaBarovFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end lady illucia barov fight",
        NextAction::array(0, new NextAction("disable lady illucia barov fight strategy", 100.0f), NULL)));
}

// ── DarkmasterGandlingFightStrategy ──────────────────────────────────────────

void DarkmasterGandlingFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Curse of Dissolution ~8yd AoE on expiry — stay >10yd; dispel strategy handles primary
    triggers.push_back(new TriggerNode(
        "gandling curse aoe",
        NextAction::array(0, new NextAction("gandling move away from curse aoe", ACTION_MOVE + 5), NULL)));
}

void DarkmasterGandlingFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end darkmaster gandling fight",
        NextAction::array(0, new NextAction("disable darkmaster gandling fight strategy", 100.0f), NULL)));
}

void DarkmasterGandlingFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end darkmaster gandling fight",
        NextAction::array(0, new NextAction("disable darkmaster gandling fight strategy", 100.0f), NULL)));
}
