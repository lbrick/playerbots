#pragma once
#include "src/Ai/Base/actions/DungeonActions.h"

namespace ai
{
    // ── Instance strategy enable/disable ────────────────────────────────────────
    class RagefireChasmEnableStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        RagefireChasmEnableStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable ragefire chasm strategy", "+ragefire chasm") {}
    };

    class RagefireChasmDisableStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        RagefireChasmDisableStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable ragefire chasm strategy", "-ragefire chasm") {}
    };

    // ── Oggleflint ───────────────────────────────────────────────────────────────
    class OggleflintEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        OggleflintEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable oggleflint fight strategy", "+oggleflint") {}
    };

    class OggleflintDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        OggleflintDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable oggleflint fight strategy", "-oggleflint") {}
    };

    // ── Taragaman ────────────────────────────────────────────────────────────────
    class TaragamanEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        TaragamanEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable taragaman fight strategy", "+taragaman") {}
    };

    class TaragamanDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        TaragamanDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable taragaman fight strategy", "-taragaman") {}
    };

    // Taragaman Firenova AoE avoidance — move >12 yards away (AoE ~10yd + buffer)
    class TaragamanMoveAwayFromFirenovaAction : public MoveAwayFromCreature
    {
    public:
        TaragamanMoveAwayFromFirenovaAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "taragaman move away from firenova", 11520, 12.0f) {}
    };

    // ── Jergosh ──────────────────────────────────────────────────────────────────
    class JergoshEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        JergoshEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable jergosh fight strategy", "+jergosh") {}
    };

    class JergoshDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        JergoshDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable jergosh fight strategy", "-jergosh") {}
    };

    // ── Bazzalan ─────────────────────────────────────────────────────────────────
    class BazzalanEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        BazzalanEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable bazzalan fight strategy", "+bazzalan") {}
    };

    class BazzalanDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        BazzalanDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable bazzalan fight strategy", "-bazzalan") {}
    };
}
