#pragma once
#include "playerbot/strategy/triggers/DungeonTriggers.h"

namespace ai
{
    // ── Instance enter/leave (Map ID 70) ────────────────────────────────────────
    class UldamanEnterDungeonTrigger : public EnterDungeonTrigger
    {
    public:
        UldamanEnterDungeonTrigger(PlayerbotAI* ai)
            : EnterDungeonTrigger(ai, "enter uldaman", "uldaman", 70) {}
    };

    class UldamanLeaveDungeonTrigger : public LeaveDungeonTrigger
    {
    public:
        UldamanLeaveDungeonTrigger(PlayerbotAI* ai)
            : LeaveDungeonTrigger(ai, "leave uldaman", "uldaman", 70) {}
    };

    // ── Boss: Revelosh (6910) — no positional mechanic ───────────────────────────
    class ReveloshStartFightTrigger : public StartBossFightTrigger
    {
    public:
        ReveloshStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start revelosh fight", "revelosh", 6910) {}
    };

    class ReveloshEndFightTrigger : public EndBossFightTrigger
    {
    public:
        ReveloshEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end revelosh fight", "revelosh", 6910) {}
    };

    // ── Boss: Baelog / Lost Dwarves (6913) — no positional mechanic ──────────────
    class BaelogStartFightTrigger : public StartBossFightTrigger
    {
    public:
        BaelogStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start baelog fight", "baelog", 6913) {}
    };

    class BaelogEndFightTrigger : public EndBossFightTrigger
    {
    public:
        BaelogEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end baelog fight", "baelog", 6913) {}
    };

    // ── Boss: Ironaya (7228) — War Stomp ~8yd AoE ───────────────────────────────
    class IronayaStartFightTrigger : public StartBossFightTrigger
    {
    public:
        IronayaStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start ironaya fight", "ironaya", 7228) {}
    };

    class IronayaEndFightTrigger : public EndBossFightTrigger
    {
    public:
        IronayaEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end ironaya fight", "ironaya", 7228) {}
    };

    class IronayaWarStompTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        IronayaWarStompTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "ironaya war stomp", 7228, 8.0f, 3) {}
    };

    // ── Boss: Obsidian Sentinel (7023) — no positional mechanic ─────────────────
    class ObsidianSentinelStartFightTrigger : public StartBossFightTrigger
    {
    public:
        ObsidianSentinelStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start obsidian sentinel fight", "obsidian sentinel", 7023) {}
    };

    class ObsidianSentinelEndFightTrigger : public EndBossFightTrigger
    {
    public:
        ObsidianSentinelEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end obsidian sentinel fight", "obsidian sentinel", 7023) {}
    };

    // ── Boss: Ancient Stone Keeper (4857) — War Stomp ~8yd AoE ─────────────────
    class AncientStoneKeeperStartFightTrigger : public StartBossFightTrigger
    {
    public:
        AncientStoneKeeperStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start ancient stone keeper fight", "ancient stone keeper", 4857) {}
    };

    class AncientStoneKeeperEndFightTrigger : public EndBossFightTrigger
    {
    public:
        AncientStoneKeeperEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end ancient stone keeper fight", "ancient stone keeper", 4857) {}
    };

    class AncientStoneKeeperWarStompTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        AncientStoneKeeperWarStompTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "ancient stone keeper war stomp", 4857, 8.0f, 3) {}
    };

    // ── Boss: Galgann Firehammer (7291) — Fire Nova ~10yd AoE ───────────────────
    class GalgannFirehammerStartFightTrigger : public StartBossFightTrigger
    {
    public:
        GalgannFirehammerStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start galgann firehammer fight", "galgann firehammer", 7291) {}
    };

    class GalgannFirehammerEndFightTrigger : public EndBossFightTrigger
    {
    public:
        GalgannFirehammerEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end galgann firehammer fight", "galgann firehammer", 7291) {}
    };

    class GalgannFireNovaTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        GalgannFireNovaTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "galgann fire nova", 7291, 10.0f, 3) {}
    };

    // ── Boss: Grimlok (4854) — War Stomp ~8yd AoE ───────────────────────────────
    class GrimlokStartFightTrigger : public StartBossFightTrigger
    {
    public:
        GrimlokStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start grimlok fight", "grimlok", 4854) {}
    };

    class GrimlokEndFightTrigger : public EndBossFightTrigger
    {
    public:
        GrimlokEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end grimlok fight", "grimlok", 4854) {}
    };

    class GrimlokWarStompTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        GrimlokWarStompTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "grimlok war stomp", 4854, 8.0f, 3) {}
    };

    // ── Boss: Archaedas (2748) — Earth Tremor ~15yd AoE ─────────────────────────
    class ArchaedasStartFightTrigger : public StartBossFightTrigger
    {
    public:
        ArchaedasStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start archaedas fight", "archaedas", 2748) {}
    };

    class ArchaedasEndFightTrigger : public EndBossFightTrigger
    {
    public:
        ArchaedasEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end archaedas fight", "archaedas", 2748) {}
    };

    class ArchaedasEarthTremorTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        ArchaedasEarthTremorTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "archaedas earth tremor", 2748, 15.0f, 3) {}
    };
}
