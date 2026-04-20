#pragma once
#include "src/Ai/Base/actions/DungeonActions.h"
#include "src/Ai/Base/actions/ChangeStrategyAction.h"

namespace ai
{
    // ── Instance strategy enable/disable ────────────────────────────────────────
    class RagefireChasmEnableStrategyAction : public ChangeAllStrategyAction
    {
    public:
        RagefireChasmEnableStrategyAction(PlayerbotAI* ai)
            : ChangeAllStrategyAction(ai, "enable ragefire chasm strategy", "+ragefire chasm") {}
    };

    class RagefireChasmDisableStrategyAction : public ChangeAllStrategyAction
    {
    public:
        RagefireChasmDisableStrategyAction(PlayerbotAI* ai)
            : ChangeAllStrategyAction(ai, "disable ragefire chasm strategy", "-ragefire chasm") {}
    };

    // ── Oggleflint ───────────────────────────────────────────────────────────────
    class OggleflintEnableFightStrategyAction : public ChangeAllStrategyAction
    {
    public:
        OggleflintEnableFightStrategyAction(PlayerbotAI* ai)
            : ChangeAllStrategyAction(ai, "enable oggleflint fight strategy", "+oggleflint") {}
    };

    class OggleflintDisableFightStrategyAction : public ChangeAllStrategyAction
    {
    public:
        OggleflintDisableFightStrategyAction(PlayerbotAI* ai)
            : ChangeAllStrategyAction(ai, "disable oggleflint fight strategy", "-oggleflint") {}
    };

    // ── Taragaman ────────────────────────────────────────────────────────────────
    class TaragamanEnableFightStrategyAction : public ChangeAllStrategyAction
    {
    public:
        TaragamanEnableFightStrategyAction(PlayerbotAI* ai)
            : ChangeAllStrategyAction(ai, "enable taragaman fight strategy", "+taragaman") {}
    };

    class TaragamanDisableFightStrategyAction : public ChangeAllStrategyAction
    {
    public:
        TaragamanDisableFightStrategyAction(PlayerbotAI* ai)
            : ChangeAllStrategyAction(ai, "disable taragaman fight strategy", "-taragaman") {}
    };

    // Taragaman Firenova AoE avoidance — move >12 yards away (AoE ~10yd + buffer)
    class TaragamanMoveAwayFromFirenovaAction : public MoveAwayFromCreature
    {
    public:
        TaragamanMoveAwayFromFirenovaAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "taragaman move away from firenova", 11520, 12.0f) {}
    };

    // ── Jergosh ──────────────────────────────────────────────────────────────────
    class JergoshEnableFightStrategyAction : public ChangeAllStrategyAction
    {
    public:
        JergoshEnableFightStrategyAction(PlayerbotAI* ai)
            : ChangeAllStrategyAction(ai, "enable jergosh fight strategy", "+jergosh") {}
    };

    class JergoshDisableFightStrategyAction : public ChangeAllStrategyAction
    {
    public:
        JergoshDisableFightStrategyAction(PlayerbotAI* ai)
            : ChangeAllStrategyAction(ai, "disable jergosh fight strategy", "-jergosh") {}
    };

    // ── Bazzalan ─────────────────────────────────────────────────────────────────
    class BazzalanEnableFightStrategyAction : public ChangeAllStrategyAction
    {
    public:
        BazzalanEnableFightStrategyAction(PlayerbotAI* ai)
            : ChangeAllStrategyAction(ai, "enable bazzalan fight strategy", "+bazzalan") {}
    };

    class BazzalanDisableFightStrategyAction : public ChangeAllStrategyAction
    {
    public:
        BazzalanDisableFightStrategyAction(PlayerbotAI* ai)
            : ChangeAllStrategyAction(ai, "disable bazzalan fight strategy", "-bazzalan") {}
    };
}
