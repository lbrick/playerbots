#pragma once
#include "playerbot/strategy/actions/DungeonActions.h"

namespace ai
{
    // ── Instance strategy enable/disable ────────────────────────────────────────
    class RazorfenKraulEnableStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        RazorfenKraulEnableStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable razorfen kraul strategy", "+razorfen kraul") {}
    };

    class RazorfenKraulDisableStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        RazorfenKraulDisableStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable razorfen kraul strategy", "-razorfen kraul") {}
    };

    // ── Roogug ────────────────────────────────────────────────────────────────────
    class RoogugEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        RoogugEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable roogug fight strategy", "+roogug") {}
    };

    class RoogugDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        RoogugDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable roogug fight strategy", "-roogug") {}
    };

    // ── Aggem Thorncurse ──────────────────────────────────────────────────────────
    class AggEmThorncurseEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        AggEmThorncurseEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable aggem thorncurse fight strategy", "+aggem thorncurse") {}
    };

    class AggEmThorncurseDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        AggEmThorncurseDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable aggem thorncurse fight strategy", "-aggem thorncurse") {}
    };

    // ── Death Speaker Jargba ──────────────────────────────────────────────────────
    class DeathSpeakerJargbaEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        DeathSpeakerJargbaEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable death speaker jargba fight strategy", "+death speaker jargba") {}
    };

    class DeathSpeakerJargbaDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        DeathSpeakerJargbaDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable death speaker jargba fight strategy", "-death speaker jargba") {}
    };

    // ── Overlord Ramtusk ──────────────────────────────────────────────────────────
    class OverlordRamtuskEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        OverlordRamtuskEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable overlord ramtusk fight strategy", "+overlord ramtusk") {}
    };

    class OverlordRamtuskDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        OverlordRamtuskDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable overlord ramtusk fight strategy", "-overlord ramtusk") {}
    };

    // Thunderclap ~8yd AoE avoidance — stay >10 yards
    class RamtuskMoveAwayFromThunderclapAction : public MoveAwayFromCreature
    {
    public:
        RamtuskMoveAwayFromThunderclapAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "overlord ramtusk move away from thunderclap", 4420, 10.0f) {}
    };

    // ── Agathelos the Raging ──────────────────────────────────────────────────────
    class AgathelosEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        AgathelosEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable agathelos fight strategy", "+agathelos") {}
    };

    class AgathelosDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        AgathelosDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable agathelos fight strategy", "-agathelos") {}
    };

    // Rampage ~8yd AoE avoidance — stay >10 yards
    class AgathellosMoveAwayFromRampageAction : public MoveAwayFromCreature
    {
    public:
        AgathellosMoveAwayFromRampageAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "agathelos move away from rampage", 4422, 10.0f) {}
    };

    // ── Charlga Razorflank ────────────────────────────────────────────────────────
    class CharlgaRazorflankEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        CharlgaRazorflankEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable charlga razorflank fight strategy", "+charlga razorflank") {}
    };

    class CharlgaRazorflankDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        CharlgaRazorflankDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable charlga razorflank fight strategy", "-charlga razorflank") {}
    };

    // Chain Bolt spread — move away from nearest ally to break chain jump
    class CharlgaSpreadFromChainBoltAction : public SpreadFromAlliesAction
    {
    public:
        CharlgaSpreadFromChainBoltAction(PlayerbotAI* ai)
            : SpreadFromAlliesAction(ai, "charlga spread from chain bolt", 10.0f) {}
    };
}
