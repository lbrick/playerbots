#pragma once
#include "playerbot/strategy/actions/DungeonActions.h"

namespace ai
{
    // ── Instance strategy enable/disable ────────────────────────────────────────
    class ZulFarrakEnableStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        ZulFarrakEnableStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable zul'farrak strategy", "+zul'farrak") {}
    };

    class ZulFarrakDisableStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        ZulFarrakDisableStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable zul'farrak strategy", "-zul'farrak") {}
    };

    // ── Theka the Martyr ──────────────────────────────────────────────────────────
    class ThekaEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        ThekaEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable theka the martyr fight strategy", "+theka the martyr") {}
    };

    class ThekaDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        ThekaDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable theka the martyr fight strategy", "-theka the martyr") {}
    };

    // ── Witch Doctor Zum'rah ───────────────────────────────────────────────────────
    class ZumrahEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        ZumrahEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable witch doctor zum'rah fight strategy", "+witch doctor zum'rah") {}
    };

    class ZumrahDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        ZumrahDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable witch doctor zum'rah fight strategy", "-witch doctor zum'rah") {}
    };

    // ── Antu'sul ──────────────────────────────────────────────────────────────────
    class AntusulEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        AntusulEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable antu'sul fight strategy", "+antu'sul") {}
    };

    class AntusulDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        AntusulDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable antu'sul fight strategy", "-antu'sul") {}
    };

    // ── Shadowpriest Sezz'ziz ─────────────────────────────────────────────────────
    class SezzizEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        SezzizEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable shadowpriest sezz'ziz fight strategy", "+shadowpriest sezz'ziz") {}
    };

    class SezzizDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        SezzizDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable shadowpriest sezz'ziz fight strategy", "-shadowpriest sezz'ziz") {}
    };

    // ── Sergeant Bly ──────────────────────────────────────────────────────────────
    class SergeantBlyEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        SergeantBlyEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable sergeant bly fight strategy", "+sergeant bly") {}
    };

    class SergeantBlyDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        SergeantBlyDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable sergeant bly fight strategy", "-sergeant bly") {}
    };

    // ── Gahz'rilla ────────────────────────────────────────────────────────────────
    class GahzrillaEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        GahzrillaEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable gahz'rilla fight strategy", "+gahz'rilla") {}
    };

    class GahzrillaDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        GahzrillaDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable gahz'rilla fight strategy", "-gahz'rilla") {}
    };

    // Freeze ~10yd AoE avoidance — stay >12 yards
    class GahzrillaMoveAwayFromFreezeAction : public MoveAwayFromCreature
    {
    public:
        GahzrillaMoveAwayFromFreezeAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "gahz'rilla move away from freeze", 7273, 12.0f) {}
    };

    // ── Chief Ukorz Sandscalp ─────────────────────────────────────────────────────
    class ChiefUkorzEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        ChiefUkorzEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable chief ukorz sandscalp fight strategy", "+chief ukorz sandscalp") {}
    };

    class ChiefUkorzDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        ChiefUkorzDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable chief ukorz sandscalp fight strategy", "-chief ukorz sandscalp") {}
    };
}
