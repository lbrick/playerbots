#pragma once
#include "src/Ai/Base/actions/DungeonActions.h"

namespace ai
{
    // ── Instance strategy enable/disable ────────────────────────────────────────
    class DeadminesEnableStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        DeadminesEnableStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable deadmines strategy", "+deadmines") {}
    };

    class DeadminesDisableStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        DeadminesDisableStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable deadmines strategy", "-deadmines") {}
    };

    // ── Rhahk'Zor ────────────────────────────────────────────────────────────────
    class RhahkzorEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        RhahkzorEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable rhahkzor fight strategy", "+rhahkzor") {}
    };

    class RhahkzorDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        RhahkzorDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable rhahkzor fight strategy", "-rhahkzor") {}
    };

    // Slam knockback avoidance — stay >8 yards
    class RhahkzorMoveAwayFromSlamAction : public MoveAwayFromCreature
    {
    public:
        RhahkzorMoveAwayFromSlamAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "rhahkzor move away from slam", 644, 8.0f) {}
    };

    // ── Sneed's Shredder ──────────────────────────────────────────────────────────
    class SneedShredderEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        SneedShredderEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable sneed shredder fight strategy", "+sneed shredder") {}
    };

    class SneedShredderDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        SneedShredderDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable sneed shredder fight strategy", "-sneed shredder") {}
    };

    // Saw Blade avoidance — stay >10 yards
    class SneedShredderMoveAwayFromSawBladeAction : public MoveAwayFromCreature
    {
    public:
        SneedShredderMoveAwayFromSawBladeAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "sneed shredder move away from saw blade", 642, 10.0f) {}
    };

    // ── Sneed ─────────────────────────────────────────────────────────────────────
    class SneedEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        SneedEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable sneed fight strategy", "+sneed") {}
    };

    class SneedDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        SneedDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable sneed fight strategy", "-sneed") {}
    };

    // ── Gilnid ────────────────────────────────────────────────────────────────────
    class GilnidEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        GilnidEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable gilnid fight strategy", "+gilnid") {}
    };

    class GilnidDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        GilnidDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable gilnid fight strategy", "-gilnid") {}
    };

    // Molten Metal avoidance — stay >8 yards
    class GilnidMoveAwayFromMoltenMetalAction : public MoveAwayFromCreature
    {
    public:
        GilnidMoveAwayFromMoltenMetalAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "gilnid move away from molten metal", 1763, 8.0f) {}
    };

    // ── Mr. Smite ─────────────────────────────────────────────────────────────────
    class SmiteEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        SmiteEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable smite fight strategy", "+smite") {}
    };

    class SmiteDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        SmiteDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable smite fight strategy", "-smite") {}
    };

    // Smite's Mighty Blow avoidance (hammer phase) — stay >12 yards
    class SmiteMoveAwayFromHammerAction : public MoveAwayFromCreature
    {
    public:
        SmiteMoveAwayFromHammerAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "smite move away from hammer", 646, 12.0f) {}
    };

    // ── Cookie ────────────────────────────────────────────────────────────────────
    class CookieEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        CookieEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable cookie fight strategy", "+cookie") {}
    };

    class CookieDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        CookieDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable cookie fight strategy", "-cookie") {}
    };

    // ── Edwin VanCleef ────────────────────────────────────────────────────────────
    class VanCleefEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        VanCleefEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable vancleef fight strategy", "+vancleef") {}
    };

    class VanCleefDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        VanCleefDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable vancleef fight strategy", "-vancleef") {}
    };
}
