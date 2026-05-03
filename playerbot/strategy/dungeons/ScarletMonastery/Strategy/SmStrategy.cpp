#include "playerbot/playerbot.h"
#include "SmStrategy.h"

using namespace ai;

// ── ScarletMonasteryDungeonStrategy ──────────────────────────────────────────

void ScarletMonasteryDungeonStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "start vishas fight",
        NextAction::array(0, new NextAction("enable vishas fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start fallen champion fight",
        NextAction::array(0, new NextAction("enable fallen champion fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start ironspine fight",
        NextAction::array(0, new NextAction("enable ironspine fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start thalnos fight",
        NextAction::array(0, new NextAction("enable thalnos fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start loksey fight",
        NextAction::array(0, new NextAction("enable loksey fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start doan fight",
        NextAction::array(0, new NextAction("enable doan fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start herod fight",
        NextAction::array(0, new NextAction("enable herod fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start mograine fight",
        NextAction::array(0, new NextAction("enable mograine fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start whitemane fight",
        NextAction::array(0, new NextAction("enable whitemane fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start fairbanks fight",
        NextAction::array(0, new NextAction("enable fairbanks fight strategy", 100.0f), NULL)));
}

void ScarletMonasteryDungeonStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "start vishas fight",
        NextAction::array(0, new NextAction("enable vishas fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start fallen champion fight",
        NextAction::array(0, new NextAction("enable fallen champion fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start ironspine fight",
        NextAction::array(0, new NextAction("enable ironspine fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start thalnos fight",
        NextAction::array(0, new NextAction("enable thalnos fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start loksey fight",
        NextAction::array(0, new NextAction("enable loksey fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start doan fight",
        NextAction::array(0, new NextAction("enable doan fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start herod fight",
        NextAction::array(0, new NextAction("enable herod fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start mograine fight",
        NextAction::array(0, new NextAction("enable mograine fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start whitemane fight",
        NextAction::array(0, new NextAction("enable whitemane fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start fairbanks fight",
        NextAction::array(0, new NextAction("enable fairbanks fight strategy", 100.0f), NULL)));
}

// ── VishasFightStrategy ───────────────────────────────────────────────────────

void VishasFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end vishas fight",
        NextAction::array(0, new NextAction("disable vishas fight strategy", 100.0f), NULL)));
}

void VishasFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end vishas fight",
        NextAction::array(0, new NextAction("disable vishas fight strategy", 100.0f), NULL)));
}

// ── FallenChampionFightStrategy ───────────────────────────────────────────────

void FallenChampionFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end fallen champion fight",
        NextAction::array(0, new NextAction("disable fallen champion fight strategy", 100.0f), NULL)));
}

void FallenChampionFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end fallen champion fight",
        NextAction::array(0, new NextAction("disable fallen champion fight strategy", 100.0f), NULL)));
}

// ── IronspineFightStrategy ────────────────────────────────────────────────────

void IronspineFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end ironspine fight",
        NextAction::array(0, new NextAction("disable ironspine fight strategy", 100.0f), NULL)));
}

void IronspineFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end ironspine fight",
        NextAction::array(0, new NextAction("disable ironspine fight strategy", 100.0f), NULL)));
}

// ── ThalnsosFightStrategy ─────────────────────────────────────────────────────

void ThalnsosFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Shadowbolt Volley wide AoE — stay >22yd
    triggers.push_back(new TriggerNode(
        "thalnos shadowbolt volley",
        NextAction::array(0, new NextAction("thalnos move away from shadowbolt volley", ACTION_MOVE + 5), NULL)));
}

void ThalnsosFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end thalnos fight",
        NextAction::array(0, new NextAction("disable thalnos fight strategy", 100.0f), NULL)));
}

void ThalnsosFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end thalnos fight",
        NextAction::array(0, new NextAction("disable thalnos fight strategy", 100.0f), NULL)));
}

// ── LokseyFightStrategy ───────────────────────────────────────────────────────

void LokseyFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end loksey fight",
        NextAction::array(0, new NextAction("disable loksey fight strategy", 100.0f), NULL)));
}

void LokseyFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end loksey fight",
        NextAction::array(0, new NextAction("disable loksey fight strategy", 100.0f), NULL)));
}

// ── DoanFightStrategy ─────────────────────────────────────────────────────────

void DoanFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Arcane Explosion ~30yd when low HP — stay >32yd
    triggers.push_back(new TriggerNode(
        "doan arcane explosion",
        NextAction::array(0, new NextAction("doan move away from arcane explosion", ACTION_MOVE + 5), NULL)));
}

void DoanFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end doan fight",
        NextAction::array(0, new NextAction("disable doan fight strategy", 100.0f), NULL)));
}

void DoanFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end doan fight",
        NextAction::array(0, new NextAction("disable doan fight strategy", 100.0f), NULL)));
}

// ── HerodFightStrategy ────────────────────────────────────────────────────────

void HerodFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Whirlwind melee AoE ~8yd — stay >10yd
    triggers.push_back(new TriggerNode(
        "herod whirlwind",
        NextAction::array(0, new NextAction("herod move away from whirlwind", ACTION_MOVE + 5), NULL)));
}

void HerodFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end herod fight",
        NextAction::array(0, new NextAction("disable herod fight strategy", 100.0f), NULL)));
}

void HerodFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end herod fight",
        NextAction::array(0, new NextAction("disable herod fight strategy", 100.0f), NULL)));
}

// ── MograineFightStrategy ─────────────────────────────────────────────────────

void MograineFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end mograine fight",
        NextAction::array(0, new NextAction("disable mograine fight strategy", 100.0f), NULL)));
}

void MograineFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end mograine fight",
        NextAction::array(0, new NextAction("disable mograine fight strategy", 100.0f), NULL)));
}

// ── WhitemaneFightStrategy ────────────────────────────────────────────────────

void WhitemaneFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "target casting whitemane heal",
        NextAction::array(0, new NextAction("interrupt enemy cast", ACTION_HIGH + 5), NULL)));
}

void WhitemaneFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end whitemane fight",
        NextAction::array(0, new NextAction("disable whitemane fight strategy", 100.0f), NULL)));
}

void WhitemaneFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end whitemane fight",
        NextAction::array(0, new NextAction("disable whitemane fight strategy", 100.0f), NULL)));
}

// ── FairbanksFightStrategy ────────────────────────────────────────────────────

void FairbanksFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end fairbanks fight",
        NextAction::array(0, new NextAction("disable fairbanks fight strategy", 100.0f), NULL)));
}

void FairbanksFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end fairbanks fight",
        NextAction::array(0, new NextAction("disable fairbanks fight strategy", 100.0f), NULL)));
}
