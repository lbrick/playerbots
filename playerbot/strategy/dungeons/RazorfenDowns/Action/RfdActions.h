#pragma once
#include "playerbot/strategy/actions/DungeonActions.h"

namespace ai
{
    // ── Instance strategy enable/disable ────────────────────────────────────────
    class RazorfenDownsEnableStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        RazorfenDownsEnableStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable razorfen downs strategy", "+razorfen downs") {}
    };

    class RazorfenDownsDisableStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        RazorfenDownsDisableStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable razorfen downs strategy", "-razorfen downs") {}
    };

    // ── Tuten'kash ────────────────────────────────────────────────────────────────
    class TutenkashEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        TutenkashEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable tuten'kash fight strategy", "+tuten'kash") {}
    };

    class TutenkashDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        TutenkashDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable tuten'kash fight strategy", "-tuten'kash") {}
    };

    // ── Mordresh Fire Eye ─────────────────────────────────────────────────────────
    class MordreshEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        MordreshEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable mordresh fire eye fight strategy", "+mordresh fire eye") {}
    };

    class MordreshDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        MordreshDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable mordresh fire eye fight strategy", "-mordresh fire eye") {}
    };

    // Fire Nova ~10yd AoE avoidance — stay >12 yards
    class MordreshMoveAwayFromFireNovaAction : public MoveAwayFromCreature
    {
    public:
        MordreshMoveAwayFromFireNovaAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "mordresh move away from fire nova", 7357, 12.0f) {}
    };

    // ── Glutton ───────────────────────────────────────────────────────────────────
    class GluttonEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        GluttonEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable glutton fight strategy", "+glutton") {}
    };

    class GluttonDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        GluttonDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable glutton fight strategy", "-glutton") {}
    };

    // ── Amnennar the Coldbringer ──────────────────────────────────────────────────
    class AmnennarEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        AmnennarEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable amnennar the coldbringer fight strategy", "+amnennar the coldbringer") {}
    };

    class AmnennarDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        AmnennarDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable amnennar the coldbringer fight strategy", "-amnennar the coldbringer") {}
    };

    // Frost Nova ~8yd AoE avoidance — stay >10 yards
    class AmnennarMoveAwayFromFrostNovaAction : public MoveAwayFromCreature
    {
    public:
        AmnennarMoveAwayFromFrostNovaAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "amnennar move away from frost nova", 7358, 10.0f) {}
    };
}
