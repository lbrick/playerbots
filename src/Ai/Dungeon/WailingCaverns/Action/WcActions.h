#pragma once
#include "src/Ai/Base/actions/DungeonActions.h"
#include "src/Ai/Base/actions/ChangeStrategyAction.h"

namespace ai
{
    // ── Instance strategy enable/disable ────────────────────────────────────────
    class WailingCavernsEnableStrategyAction : public ChangeAllStrategyAction
    {
    public:
        WailingCavernsEnableStrategyAction(PlayerbotAI* ai)
            : ChangeAllStrategyAction(ai, "enable wailing caverns strategy", "+wailing caverns") {}
    };

    class WailingCavernsDisableStrategyAction : public ChangeAllStrategyAction
    {
    public:
        WailingCavernsDisableStrategyAction(PlayerbotAI* ai)
            : ChangeAllStrategyAction(ai, "disable wailing caverns strategy", "-wailing caverns") {}
    };

    // ── Kresh ────────────────────────────────────────────────────────────────────
    class KreshEnableFightStrategyAction : public ChangeAllStrategyAction
    {
    public:
        KreshEnableFightStrategyAction(PlayerbotAI* ai)
            : ChangeAllStrategyAction(ai, "enable kresh fight strategy", "+kresh") {}
    };

    class KreshDisableFightStrategyAction : public ChangeAllStrategyAction
    {
    public:
        KreshDisableFightStrategyAction(PlayerbotAI* ai)
            : ChangeAllStrategyAction(ai, "disable kresh fight strategy", "-kresh") {}
    };

    // ── Lady Anacondra ────────────────────────────────────────────────────────────
    class AnacondraEnableFightStrategyAction : public ChangeAllStrategyAction
    {
    public:
        AnacondraEnableFightStrategyAction(PlayerbotAI* ai)
            : ChangeAllStrategyAction(ai, "enable anacondra fight strategy", "+anacondra") {}
    };

    class AnacondraDisableFightStrategyAction : public ChangeAllStrategyAction
    {
    public:
        AnacondraDisableFightStrategyAction(PlayerbotAI* ai)
            : ChangeAllStrategyAction(ai, "disable anacondra fight strategy", "-anacondra") {}
    };

    // ── Lord Cobrahn ─────────────────────────────────────────────────────────────
    class CobrahnEnableFightStrategyAction : public ChangeAllStrategyAction
    {
    public:
        CobrahnEnableFightStrategyAction(PlayerbotAI* ai)
            : ChangeAllStrategyAction(ai, "enable cobrahn fight strategy", "+cobrahn") {}
    };

    class CobrahnDisableFightStrategyAction : public ChangeAllStrategyAction
    {
    public:
        CobrahnDisableFightStrategyAction(PlayerbotAI* ai)
            : ChangeAllStrategyAction(ai, "disable cobrahn fight strategy", "-cobrahn") {}
    };

    // ── Lord Pythas ───────────────────────────────────────────────────────────────
    class PythasEnableFightStrategyAction : public ChangeAllStrategyAction
    {
    public:
        PythasEnableFightStrategyAction(PlayerbotAI* ai)
            : ChangeAllStrategyAction(ai, "enable pythas fight strategy", "+pythas") {}
    };

    class PythasDisableFightStrategyAction : public ChangeAllStrategyAction
    {
    public:
        PythasDisableFightStrategyAction(PlayerbotAI* ai)
            : ChangeAllStrategyAction(ai, "disable pythas fight strategy", "-pythas") {}
    };

    // ── Lord Serpentis ────────────────────────────────────────────────────────────
    class SerpentisEnableFightStrategyAction : public ChangeAllStrategyAction
    {
    public:
        SerpentisEnableFightStrategyAction(PlayerbotAI* ai)
            : ChangeAllStrategyAction(ai, "enable serpentis fight strategy", "+serpentis") {}
    };

    class SerpentisDisableFightStrategyAction : public ChangeAllStrategyAction
    {
    public:
        SerpentisDisableFightStrategyAction(PlayerbotAI* ai)
            : ChangeAllStrategyAction(ai, "disable serpentis fight strategy", "-serpentis") {}
    };

    // ── Verdan the Everliving ─────────────────────────────────────────────────────
    class VerdanEnableFightStrategyAction : public ChangeAllStrategyAction
    {
    public:
        VerdanEnableFightStrategyAction(PlayerbotAI* ai)
            : ChangeAllStrategyAction(ai, "enable verdan fight strategy", "+verdan") {}
    };

    class VerdanDisableFightStrategyAction : public ChangeAllStrategyAction
    {
    public:
        VerdanDisableFightStrategyAction(PlayerbotAI* ai)
            : ChangeAllStrategyAction(ai, "disable verdan fight strategy", "-verdan") {}
    };

    // Verdan Grasping Vines avoidance — stay >10 yards (vines root ~8yd)
    class VerdanMoveAwayFromGraspingVinesAction : public MoveAwayFromCreature
    {
    public:
        VerdanMoveAwayFromGraspingVinesAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "verdan move away from grasping vines", 5775, 10.0f) {}
    };

    // ── Mutanus the Devourer ──────────────────────────────────────────────────────
    class MutanusEnableFightStrategyAction : public ChangeAllStrategyAction
    {
    public:
        MutanusEnableFightStrategyAction(PlayerbotAI* ai)
            : ChangeAllStrategyAction(ai, "enable mutanus fight strategy", "+mutanus") {}
    };

    class MutanusDisableFightStrategyAction : public ChangeAllStrategyAction
    {
    public:
        MutanusDisableFightStrategyAction(PlayerbotAI* ai)
            : ChangeAllStrategyAction(ai, "disable mutanus fight strategy", "-mutanus") {}
    };

    // Mutanus AoE avoidance — stay >12 yards (Thundercrack + Terrify ~10yd)
    class MutanusMoveAwayFromAoeAction : public MoveAwayFromCreature
    {
    public:
        MutanusMoveAwayFromAoeAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "mutanus move away from aoe", 3654, 12.0f) {}
    };
}
