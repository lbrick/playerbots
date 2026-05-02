#pragma once
#include "playerbot/strategy/actions/DungeonActions.h"

namespace ai
{
    // ── Instance strategy enable/disable ────────────────────────────────────────
    class MaraudonEnableStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        MaraudonEnableStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable maraudon strategy", "+maraudon") {}
    };

    class MaraudonDisableStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        MaraudonDisableStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable maraudon strategy", "-maraudon") {}
    };

    // ── Noxxion ───────────────────────────────────────────────────────────────────
    class NoxxionEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        NoxxionEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable noxxion fight strategy", "+noxxion") {}
    };

    class NoxxionDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        NoxxionDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable noxxion fight strategy", "-noxxion") {}
    };

    // Noxious Fumes ~8yd AoE avoidance — stay >10 yards
    class NoxxionMoveAwayFromNoxiousFumesAction : public MoveAwayFromCreature
    {
    public:
        NoxxionMoveAwayFromNoxiousFumesAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "noxxion move away from noxious fumes", 13282, 10.0f) {}
    };

    // ── Razorlash ─────────────────────────────────────────────────────────────────
    class RazorlashEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        RazorlashEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable razorlash fight strategy", "+razorlash") {}
    };

    class RazorlashDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        RazorlashDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable razorlash fight strategy", "-razorlash") {}
    };

    // ── Lord Vyletongue ───────────────────────────────────────────────────────────
    class LordVyletongueEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        LordVyletongueEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable lord vyletongue fight strategy", "+lord vyletongue") {}
    };

    class LordVyletongueDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        LordVyletongueDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable lord vyletongue fight strategy", "-lord vyletongue") {}
    };

    // ── Celebras the Cursed ───────────────────────────────────────────────────────
    class CelebrasEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        CelebrasEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable celebras the cursed fight strategy", "+celebras the cursed") {}
    };

    class CelebrasDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        CelebrasDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable celebras the cursed fight strategy", "-celebras the cursed") {}
    };

    // ── Landslide ─────────────────────────────────────────────────────────────────
    class LandslideEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        LandslideEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable landslide fight strategy", "+landslide") {}
    };

    class LandslideDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        LandslideDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable landslide fight strategy", "-landslide") {}
    };

    // ── Tinkerer Gizlock ──────────────────────────────────────────────────────────
    class GizlockEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        GizlockEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable tinkerer gizlock fight strategy", "+tinkerer gizlock") {}
    };

    class GizlockDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        GizlockDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable tinkerer gizlock fight strategy", "-tinkerer gizlock") {}
    };

    // Smoke Bomb ~8yd AoE avoidance — stay >10 yards
    class GizlockMoveAwayFromSmokeBombAction : public MoveAwayFromCreature
    {
    public:
        GizlockMoveAwayFromSmokeBombAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "gizlock move away from smoke bomb", 13601, 10.0f) {}
    };

    // ── Rotgrip ───────────────────────────────────────────────────────────────────
    class RotgripEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        RotgripEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable rotgrip fight strategy", "+rotgrip") {}
    };

    class RotgripDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        RotgripDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable rotgrip fight strategy", "-rotgrip") {}
    };

    // ── Princess Theradras ────────────────────────────────────────────────────────
    class TheradrasEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        TheradrasEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable princess theradras fight strategy", "+princess theradras") {}
    };

    class TheradrasDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        TheradrasDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable princess theradras fight strategy", "-princess theradras") {}
    };

    // Dust Field ~10yd AoE avoidance — stay >12 yards
    class TheradrasMoveAwayFromDustFieldAction : public MoveAwayFromCreature
    {
    public:
        TheradrasMoveAwayFromDustFieldAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "theradras move away from dust field", 12201, 12.0f) {}
    };
}
