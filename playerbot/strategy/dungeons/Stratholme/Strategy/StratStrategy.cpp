#include "playerbot/playerbot.h"
#include "StratStrategy.h"

using namespace ai;

// ── StratholmeDungeonStrategy ─────────────────────────────────────────────────

void StratholmeDungeonStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Scarlet side
    triggers.push_back(new TriggerNode(
        "start hearthsinger forresten fight",
        NextAction::array(0, new NextAction("enable hearthsinger forresten fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start timmy the cruel fight",
        NextAction::array(0, new NextAction("enable timmy the cruel fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start cannon master willey fight",
        NextAction::array(0, new NextAction("enable cannon master willey fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start archivist galford fight",
        NextAction::array(0, new NextAction("enable archivist galford fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start balnazzar fight",
        NextAction::array(0, new NextAction("enable balnazzar fight strategy", 100.0f), NULL)));

    // Undead side
    triggers.push_back(new TriggerNode(
        "start magistrate barthilas fight",
        NextAction::array(0, new NextAction("enable magistrate barthilas fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start maleki the pallid fight",
        NextAction::array(0, new NextAction("enable maleki the pallid fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start ramstein the gorger fight",
        NextAction::array(0, new NextAction("enable ramstein the gorger fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start baron rivendare fight",
        NextAction::array(0, new NextAction("enable baron rivendare fight strategy", 100.0f), NULL)));
}

void StratholmeDungeonStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Scarlet side
    triggers.push_back(new TriggerNode(
        "start hearthsinger forresten fight",
        NextAction::array(0, new NextAction("enable hearthsinger forresten fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start timmy the cruel fight",
        NextAction::array(0, new NextAction("enable timmy the cruel fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start cannon master willey fight",
        NextAction::array(0, new NextAction("enable cannon master willey fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start archivist galford fight",
        NextAction::array(0, new NextAction("enable archivist galford fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start balnazzar fight",
        NextAction::array(0, new NextAction("enable balnazzar fight strategy", 100.0f), NULL)));

    // Undead side
    triggers.push_back(new TriggerNode(
        "start magistrate barthilas fight",
        NextAction::array(0, new NextAction("enable magistrate barthilas fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start maleki the pallid fight",
        NextAction::array(0, new NextAction("enable maleki the pallid fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start ramstein the gorger fight",
        NextAction::array(0, new NextAction("enable ramstein the gorger fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start baron rivendare fight",
        NextAction::array(0, new NextAction("enable baron rivendare fight strategy", 100.0f), NULL)));
}

// ── HearthsingerForrestenFightStrategy ────────────────────────────────────────

void HearthsingerForrestenFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end hearthsinger forresten fight",
        NextAction::array(0, new NextAction("disable hearthsinger forresten fight strategy", 100.0f), NULL)));
}

void HearthsingerForrestenFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end hearthsinger forresten fight",
        NextAction::array(0, new NextAction("disable hearthsinger forresten fight strategy", 100.0f), NULL)));
}

// ── TimmytheCruelFightStrategy ────────────────────────────────────────────────

void TimmytheCruelFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end timmy the cruel fight",
        NextAction::array(0, new NextAction("disable timmy the cruel fight strategy", 100.0f), NULL)));
}

void TimmytheCruelFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end timmy the cruel fight",
        NextAction::array(0, new NextAction("disable timmy the cruel fight strategy", 100.0f), NULL)));
}

// ── CannonMasterWilleyFightStrategy ──────────────────────────────────────────

void CannonMasterWilleyFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end cannon master willey fight",
        NextAction::array(0, new NextAction("disable cannon master willey fight strategy", 100.0f), NULL)));
}

void CannonMasterWilleyFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end cannon master willey fight",
        NextAction::array(0, new NextAction("disable cannon master willey fight strategy", 100.0f), NULL)));
}

// ── ArchivistGalfordFightStrategy ─────────────────────────────────────────────

void ArchivistGalfordFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Flame Buffet ~8yd AoE fire — stay >10yd
    triggers.push_back(new TriggerNode(
        "galford flame buffet",
        NextAction::array(0, new NextAction("galford move away from flame buffet", ACTION_MOVE + 5), NULL)));
}

void ArchivistGalfordFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end archivist galford fight",
        NextAction::array(0, new NextAction("disable archivist galford fight strategy", 100.0f), NULL)));
}

void ArchivistGalfordFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end archivist galford fight",
        NextAction::array(0, new NextAction("disable archivist galford fight strategy", 100.0f), NULL)));
}

// ── BalnazzarFightStrategy ────────────────────────────────────────────────────

void BalnazzarFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Thunderclap ~8yd AoE — stay >10yd
    triggers.push_back(new TriggerNode(
        "balnazzar thunderclap",
        NextAction::array(0, new NextAction("balnazzar move away from thunderclap", ACTION_MOVE + 5), NULL)));

    triggers.push_back(new TriggerNode(
        "target casting balnazzar sleep",
        NextAction::array(0, new NextAction("interrupt enemy cast", ACTION_HIGH + 5), NULL)));
}

void BalnazzarFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end balnazzar fight",
        NextAction::array(0, new NextAction("disable balnazzar fight strategy", 100.0f), NULL)));
}

void BalnazzarFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end balnazzar fight",
        NextAction::array(0, new NextAction("disable balnazzar fight strategy", 100.0f), NULL)));
}

// ── MagistrateBarthilasFightStrategy ─────────────────────────────────────────

void MagistrateBarthilasFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end magistrate barthilas fight",
        NextAction::array(0, new NextAction("disable magistrate barthilas fight strategy", 100.0f), NULL)));
}

void MagistrateBarthilasFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end magistrate barthilas fight",
        NextAction::array(0, new NextAction("disable magistrate barthilas fight strategy", 100.0f), NULL)));
}

// ── MalekithePallidFightStrategy ──────────────────────────────────────────────

void MalekithePallidFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Frost Nova ~8yd AoE freeze — stay >10yd
    triggers.push_back(new TriggerNode(
        "maleki frost nova",
        NextAction::array(0, new NextAction("maleki move away from frost nova", ACTION_MOVE + 5), NULL)));

    triggers.push_back(new TriggerNode(
        "target casting maleki ice tomb",
        NextAction::array(0, new NextAction("interrupt enemy cast", ACTION_HIGH + 5), NULL)));

    triggers.push_back(new TriggerNode(
        "target casting maleki frostbolt",
        NextAction::array(0, new NextAction("interrupt enemy cast", ACTION_HIGH + 5), NULL)));
}

void MalekithePallidFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end maleki the pallid fight",
        NextAction::array(0, new NextAction("disable maleki the pallid fight strategy", 100.0f), NULL)));
}

void MalekithePallidFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end maleki the pallid fight",
        NextAction::array(0, new NextAction("disable maleki the pallid fight strategy", 100.0f), NULL)));
}

// ── RamsteintheGorgerFightStrategy ────────────────────────────────────────────

void RamsteintheGorgerFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Trample ~8yd AoE physical knockback — stay >10yd
    triggers.push_back(new TriggerNode(
        "ramstein trample",
        NextAction::array(0, new NextAction("ramstein move away from trample", ACTION_MOVE + 5), NULL)));
}

void RamsteintheGorgerFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end ramstein the gorger fight",
        NextAction::array(0, new NextAction("disable ramstein the gorger fight strategy", 100.0f), NULL)));
}

void RamsteintheGorgerFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end ramstein the gorger fight",
        NextAction::array(0, new NextAction("disable ramstein the gorger fight strategy", 100.0f), NULL)));
}

// ── BaronRivendareFightStrategy ───────────────────────────────────────────────

void BaronRivendareFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Unholy Aura ~10yd persistent shadow AoE — stay >12yd
    triggers.push_back(new TriggerNode(
        "baron unholy aura",
        NextAction::array(0, new NextAction("baron move away from unholy aura", ACTION_MOVE + 5), NULL)));
}

void BaronRivendareFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end baron rivendare fight",
        NextAction::array(0, new NextAction("disable baron rivendare fight strategy", 100.0f), NULL)));
}

void BaronRivendareFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end baron rivendare fight",
        NextAction::array(0, new NextAction("disable baron rivendare fight strategy", 100.0f), NULL)));
}
