#pragma once
#include "playerbot/strategy/actions/DungeonActions.h"

namespace ai
{
    // ── Instance strategy enable/disable ────────────────────────────────────────
    class BlackfathomDeepsEnableStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        BlackfathomDeepsEnableStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable blackfathom deeps strategy", "+blackfathom deeps") {}
    };

    class BlackfathomDeepsDisableStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        BlackfathomDeepsDisableStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable blackfathom deeps strategy", "-blackfathom deeps") {}
    };

    // ── Ghamoo-ra ────────────────────────────────────────────────────────────────
    class GhamooRaEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        GhamooRaEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable ghamoo-ra fight strategy", "+ghamoo-ra") {}
    };

    class GhamooRaDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        GhamooRaDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable ghamoo-ra fight strategy", "-ghamoo-ra") {}
    };

    // Trample avoidance — stay >8 yards
    class GhamooRaMoveAwayFromTrampleAction : public MoveAwayFromCreature
    {
    public:
        GhamooRaMoveAwayFromTrampleAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "ghamoo-ra move away from trample", 4887, 8.0f) {}
    };

    // ── Lady Sarevess ─────────────────────────────────────────────────────────────
    class LadySarevessEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        LadySarevessEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable lady sarevess fight strategy", "+lady sarevess") {}
    };

    class LadySarevessDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        LadySarevessDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable lady sarevess fight strategy", "-lady sarevess") {}
    };

    // ── Gelihast ──────────────────────────────────────────────────────────────────
    class GelihastEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        GelihastEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable gelihast fight strategy", "+gelihast") {}
    };

    class GelihastDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        GelihastDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable gelihast fight strategy", "-gelihast") {}
    };

    // ── Lorgus Jett ───────────────────────────────────────────────────────────────
    class LorgusJettEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        LorgusJettEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable lorgus jett fight strategy", "+lorgus jett") {}
    };

    class LorgusJettDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        LorgusJettDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable lorgus jett fight strategy", "-lorgus jett") {}
    };

    // ── Baron Aquanis ─────────────────────────────────────────────────────────────
    class BaronAquanisEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        BaronAquanisEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable baron aquanis fight strategy", "+baron aquanis") {}
    };

    class BaronAquanisDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        BaronAquanisDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable baron aquanis fight strategy", "-baron aquanis") {}
    };

    // ── Twilight Lord Kelris ──────────────────────────────────────────────────────
    class KelrisEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        KelrisEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable kelris fight strategy", "+kelris") {}
    };

    class KelrisDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        KelrisDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable kelris fight strategy", "-kelris") {}
    };

    // ── Aku'mai ───────────────────────────────────────────────────────────────────
    class AkuMaiEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        AkuMaiEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable aku'mai fight strategy", "+aku'mai") {}
    };

    class AkuMaiDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        AkuMaiDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable aku'mai fight strategy", "-aku'mai") {}
    };

    // Poison Cloud avoidance — stay >10 yards
    class AkuMaiMoveAwayFromPoisonCloudAction : public MoveAwayFromCreature
    {
    public:
        AkuMaiMoveAwayFromPoisonCloudAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "aku'mai move away from poison cloud", 4829, 10.0f) {}
    };
}
