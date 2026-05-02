#pragma once
#include "playerbot/strategy/actions/DungeonActions.h"

namespace ai
{
    // ── Instance strategy enable/disable ────────────────────────────────────────
    class UldamanEnableStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        UldamanEnableStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable uldaman strategy", "+uldaman") {}
    };

    class UldamanDisableStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        UldamanDisableStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable uldaman strategy", "-uldaman") {}
    };

    // ── Revelosh ──────────────────────────────────────────────────────────────────
    class ReveloshEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        ReveloshEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable revelosh fight strategy", "+revelosh") {}
    };

    class ReveloshDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        ReveloshDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable revelosh fight strategy", "-revelosh") {}
    };

    // ── Baelog (Lost Dwarves) ─────────────────────────────────────────────────────
    class BaelogEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        BaelogEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable baelog fight strategy", "+baelog") {}
    };

    class BaelogDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        BaelogDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable baelog fight strategy", "-baelog") {}
    };

    // ── Ironaya ───────────────────────────────────────────────────────────────────
    class IronayaEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        IronayaEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable ironaya fight strategy", "+ironaya") {}
    };

    class IronayaDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        IronayaDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable ironaya fight strategy", "-ironaya") {}
    };

    // War Stomp ~8yd AoE avoidance — stay >10 yards
    class IronayaMoveAwayFromWarStompAction : public MoveAwayFromCreature
    {
    public:
        IronayaMoveAwayFromWarStompAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "ironaya move away from war stomp", 7228, 10.0f) {}
    };

    // ── Obsidian Sentinel ─────────────────────────────────────────────────────────
    class ObsidianSentinelEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        ObsidianSentinelEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable obsidian sentinel fight strategy", "+obsidian sentinel") {}
    };

    class ObsidianSentinelDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        ObsidianSentinelDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable obsidian sentinel fight strategy", "-obsidian sentinel") {}
    };

    // ── Ancient Stone Keeper ──────────────────────────────────────────────────────
    class AncientStoneKeeperEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        AncientStoneKeeperEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable ancient stone keeper fight strategy", "+ancient stone keeper") {}
    };

    class AncientStoneKeeperDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        AncientStoneKeeperDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable ancient stone keeper fight strategy", "-ancient stone keeper") {}
    };

    // War Stomp ~8yd AoE avoidance — stay >10 yards
    class AncientStoneKeeperMoveAwayFromWarStompAction : public MoveAwayFromCreature
    {
    public:
        AncientStoneKeeperMoveAwayFromWarStompAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "ancient stone keeper move away from war stomp", 4857, 10.0f) {}
    };

    // ── Galgann Firehammer ────────────────────────────────────────────────────────
    class GalgannFirehammerEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        GalgannFirehammerEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable galgann firehammer fight strategy", "+galgann firehammer") {}
    };

    class GalgannFirehammerDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        GalgannFirehammerDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable galgann firehammer fight strategy", "-galgann firehammer") {}
    };

    // Fire Nova ~10yd AoE avoidance — stay >12 yards
    class GalgannMoveAwayFromFireNovaAction : public MoveAwayFromCreature
    {
    public:
        GalgannMoveAwayFromFireNovaAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "galgann move away from fire nova", 7291, 12.0f) {}
    };

    // ── Grimlok ───────────────────────────────────────────────────────────────────
    class GrimlokEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        GrimlokEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable grimlok fight strategy", "+grimlok") {}
    };

    class GrimlokDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        GrimlokDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable grimlok fight strategy", "-grimlok") {}
    };

    // War Stomp ~8yd AoE avoidance — stay >10 yards
    class GrimlokMoveAwayFromWarStompAction : public MoveAwayFromCreature
    {
    public:
        GrimlokMoveAwayFromWarStompAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "grimlok move away from war stomp", 4854, 10.0f) {}
    };

    // ── Archaedas ─────────────────────────────────────────────────────────────────
    class ArchaedasEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        ArchaedasEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable archaedas fight strategy", "+archaedas") {}
    };

    class ArchaedasDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        ArchaedasDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable archaedas fight strategy", "-archaedas") {}
    };

    // Earth Tremor ~15yd AoE avoidance — stay >17 yards
    class ArchaedasMoveAwayFromEarthTremorAction : public MoveAwayFromCreature
    {
    public:
        ArchaedasMoveAwayFromEarthTremorAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "archaedas move away from earth tremor", 2748, 17.0f) {}
    };
}
