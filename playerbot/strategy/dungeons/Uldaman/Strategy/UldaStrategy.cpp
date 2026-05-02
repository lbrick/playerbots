#include "playerbot/playerbot.h"
#include "UldaStrategy.h"

using namespace ai;

// ── UldamanDungeonStrategy ────────────────────────────────────────────────────

void UldamanDungeonStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "start revelosh fight",
        NextAction::array(0, new NextAction("enable revelosh fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start baelog fight",
        NextAction::array(0, new NextAction("enable baelog fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start ironaya fight",
        NextAction::array(0, new NextAction("enable ironaya fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start obsidian sentinel fight",
        NextAction::array(0, new NextAction("enable obsidian sentinel fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start ancient stone keeper fight",
        NextAction::array(0, new NextAction("enable ancient stone keeper fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start galgann firehammer fight",
        NextAction::array(0, new NextAction("enable galgann firehammer fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start grimlok fight",
        NextAction::array(0, new NextAction("enable grimlok fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start archaedas fight",
        NextAction::array(0, new NextAction("enable archaedas fight strategy", 100.0f), NULL)));
}

void UldamanDungeonStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "start revelosh fight",
        NextAction::array(0, new NextAction("enable revelosh fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start baelog fight",
        NextAction::array(0, new NextAction("enable baelog fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start ironaya fight",
        NextAction::array(0, new NextAction("enable ironaya fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start obsidian sentinel fight",
        NextAction::array(0, new NextAction("enable obsidian sentinel fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start ancient stone keeper fight",
        NextAction::array(0, new NextAction("enable ancient stone keeper fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start galgann firehammer fight",
        NextAction::array(0, new NextAction("enable galgann firehammer fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start grimlok fight",
        NextAction::array(0, new NextAction("enable grimlok fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start archaedas fight",
        NextAction::array(0, new NextAction("enable archaedas fight strategy", 100.0f), NULL)));
}

// ── ReveloshFightStrategy ─────────────────────────────────────────────────────

void ReveloshFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end revelosh fight",
        NextAction::array(0, new NextAction("disable revelosh fight strategy", 100.0f), NULL)));
}

void ReveloshFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end revelosh fight",
        NextAction::array(0, new NextAction("disable revelosh fight strategy", 100.0f), NULL)));
}

// ── BaelogFightStrategy ───────────────────────────────────────────────────────

void BaelogFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end baelog fight",
        NextAction::array(0, new NextAction("disable baelog fight strategy", 100.0f), NULL)));
}

void BaelogFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end baelog fight",
        NextAction::array(0, new NextAction("disable baelog fight strategy", 100.0f), NULL)));
}

// ── IronayaFightStrategy ──────────────────────────────────────────────────────

void IronayaFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // War Stomp ~8yd AoE — stay >10yd
    triggers.push_back(new TriggerNode(
        "ironaya war stomp",
        NextAction::array(0, new NextAction("ironaya move away from war stomp", ACTION_MOVE + 5), NULL)));
}

void IronayaFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end ironaya fight",
        NextAction::array(0, new NextAction("disable ironaya fight strategy", 100.0f), NULL)));
}

void IronayaFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end ironaya fight",
        NextAction::array(0, new NextAction("disable ironaya fight strategy", 100.0f), NULL)));
}

// ── ObsidianSentinelFightStrategy ─────────────────────────────────────────────

void ObsidianSentinelFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end obsidian sentinel fight",
        NextAction::array(0, new NextAction("disable obsidian sentinel fight strategy", 100.0f), NULL)));
}

void ObsidianSentinelFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end obsidian sentinel fight",
        NextAction::array(0, new NextAction("disable obsidian sentinel fight strategy", 100.0f), NULL)));
}

// ── AncientStoneKeeperFightStrategy ───────────────────────────────────────────

void AncientStoneKeeperFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // War Stomp ~8yd AoE — stay >10yd
    triggers.push_back(new TriggerNode(
        "ancient stone keeper war stomp",
        NextAction::array(0, new NextAction("ancient stone keeper move away from war stomp", ACTION_MOVE + 5), NULL)));
}

void AncientStoneKeeperFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end ancient stone keeper fight",
        NextAction::array(0, new NextAction("disable ancient stone keeper fight strategy", 100.0f), NULL)));
}

void AncientStoneKeeperFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end ancient stone keeper fight",
        NextAction::array(0, new NextAction("disable ancient stone keeper fight strategy", 100.0f), NULL)));
}

// ── GalgannFirehammerFightStrategy ────────────────────────────────────────────

void GalgannFirehammerFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Fire Nova ~10yd AoE — stay >12yd
    triggers.push_back(new TriggerNode(
        "galgann fire nova",
        NextAction::array(0, new NextAction("galgann move away from fire nova", ACTION_MOVE + 5), NULL)));
}

void GalgannFirehammerFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end galgann firehammer fight",
        NextAction::array(0, new NextAction("disable galgann firehammer fight strategy", 100.0f), NULL)));
}

void GalgannFirehammerFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end galgann firehammer fight",
        NextAction::array(0, new NextAction("disable galgann firehammer fight strategy", 100.0f), NULL)));
}

// ── GrimlokFightStrategy ──────────────────────────────────────────────────────

void GrimlokFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // War Stomp ~8yd AoE — stay >10yd
    triggers.push_back(new TriggerNode(
        "grimlok war stomp",
        NextAction::array(0, new NextAction("grimlok move away from war stomp", ACTION_MOVE + 5), NULL)));
}

void GrimlokFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end grimlok fight",
        NextAction::array(0, new NextAction("disable grimlok fight strategy", 100.0f), NULL)));
}

void GrimlokFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end grimlok fight",
        NextAction::array(0, new NextAction("disable grimlok fight strategy", 100.0f), NULL)));
}

// ── ArchaedasFightStrategy ────────────────────────────────────────────────────

void ArchaedasFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Earth Tremor ~15yd AoE — stay >17yd
    triggers.push_back(new TriggerNode(
        "archaedas earth tremor",
        NextAction::array(0, new NextAction("archaedas move away from earth tremor", ACTION_MOVE + 5), NULL)));
}

void ArchaedasFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end archaedas fight",
        NextAction::array(0, new NextAction("disable archaedas fight strategy", 100.0f), NULL)));
}

void ArchaedasFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end archaedas fight",
        NextAction::array(0, new NextAction("disable archaedas fight strategy", 100.0f), NULL)));
}
