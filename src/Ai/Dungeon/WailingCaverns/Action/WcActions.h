#pragma once
#include "src/Ai/Base/actions/DungeonActions.h"

namespace ai
{
    // ── Instance strategy enable/disable ────────────────────────────────────────
    class WailingCavernsEnableStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        WailingCavernsEnableStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable wailing caverns strategy", "+wailing caverns") {}
    };

    class WailingCavernsDisableStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        WailingCavernsDisableStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable wailing caverns strategy", "-wailing caverns") {}
    };

    // ── Kresh ────────────────────────────────────────────────────────────────────
    class KreshEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        KreshEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable kresh fight strategy", "+kresh") {}
    };

    class KreshDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        KreshDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable kresh fight strategy", "-kresh") {}
    };

    // ── Lady Anacondra ────────────────────────────────────────────────────────────
    class AnacondraEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        AnacondraEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable anacondra fight strategy", "+anacondra") {}
    };

    class AnacondraDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        AnacondraDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable anacondra fight strategy", "-anacondra") {}
    };

    // ── Lord Cobrahn ─────────────────────────────────────────────────────────────
    class CobrahnEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        CobrahnEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable cobrahn fight strategy", "+cobrahn") {}
    };

    class CobrahnDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        CobrahnDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable cobrahn fight strategy", "-cobrahn") {}
    };

    // ── Lord Pythas ───────────────────────────────────────────────────────────────
    class PythasEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        PythasEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable pythas fight strategy", "+pythas") {}
    };

    class PythasDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        PythasDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable pythas fight strategy", "-pythas") {}
    };

    // ── Lord Serpentis ────────────────────────────────────────────────────────────
    class SerpentisEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        SerpentisEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable serpentis fight strategy", "+serpentis") {}
    };

    class SerpentisDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        SerpentisDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable serpentis fight strategy", "-serpentis") {}
    };

    // ── Verdan the Everliving ─────────────────────────────────────────────────────
    class VerdanEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        VerdanEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable verdan fight strategy", "+verdan") {}
    };

    class VerdanDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        VerdanDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable verdan fight strategy", "-verdan") {}
    };

    // Verdan Grasping Vines avoidance — stay >10 yards (vines root ~8yd)
    class VerdanMoveAwayFromGraspingVinesAction : public MoveAwayFromCreature
    {
    public:
        VerdanMoveAwayFromGraspingVinesAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "verdan move away from grasping vines", 5775, 10.0f) {}
    };

    // ── Mutanus the Devourer ──────────────────────────────────────────────────────
    class MutanusEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        MutanusEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable mutanus fight strategy", "+mutanus") {}
    };

    class MutanusDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        MutanusDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable mutanus fight strategy", "-mutanus") {}
    };

    // Mutanus AoE avoidance — stay >12 yards (Thundercrack + Terrify ~10yd)
    class MutanusMoveAwayFromAoeAction : public MoveAwayFromCreature
    {
    public:
        MutanusMoveAwayFromAoeAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "mutanus move away from aoe", 3654, 12.0f) {}
    };
}
