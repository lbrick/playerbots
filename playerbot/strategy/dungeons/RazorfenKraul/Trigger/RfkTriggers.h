#pragma once
#include "playerbot/strategy/triggers/DungeonTriggers.h"

namespace ai
{
    // ── Instance enter/leave (Map ID 47) ────────────────────────────────────────
    class RazorfenKraulEnterDungeonTrigger : public EnterDungeonTrigger
    {
    public:
        RazorfenKraulEnterDungeonTrigger(PlayerbotAI* ai)
            : EnterDungeonTrigger(ai, "enter razorfen kraul", "razorfen kraul", 47) {}
    };

    class RazorfenKraulLeaveDungeonTrigger : public LeaveDungeonTrigger
    {
    public:
        RazorfenKraulLeaveDungeonTrigger(PlayerbotAI* ai)
            : LeaveDungeonTrigger(ai, "leave razorfen kraul", "razorfen kraul", 47) {}
    };

    // ── Boss: Roogug (6168) — no positional mechanic ─────────────────────────────
    class RoogugStartFightTrigger : public StartBossFightTrigger
    {
    public:
        RoogugStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start roogug fight", "roogug", 6168) {}
    };

    class RoogugEndFightTrigger : public EndBossFightTrigger
    {
    public:
        RoogugEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end roogug fight", "roogug", 6168) {}
    };

    // ── Boss: Aggem Thorncurse (4424) — no positional mechanic ───────────────────
    class AggEmThorncurseStartFightTrigger : public StartBossFightTrigger
    {
    public:
        AggEmThorncurseStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start aggem thorncurse fight", "aggem thorncurse", 4424) {}
    };

    class AggEmThorncurseEndFightTrigger : public EndBossFightTrigger
    {
    public:
        AggEmThorncurseEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end aggem thorncurse fight", "aggem thorncurse", 4424) {}
    };

    // ── Boss: Death Speaker Jargba (4428) — no positional mechanic ───────────────
    class DeathSpeakerJargbaStartFightTrigger : public StartBossFightTrigger
    {
    public:
        DeathSpeakerJargbaStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start death speaker jargba fight", "death speaker jargba", 4428) {}
    };

    class DeathSpeakerJargbaEndFightTrigger : public EndBossFightTrigger
    {
    public:
        DeathSpeakerJargbaEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end death speaker jargba fight", "death speaker jargba", 4428) {}
    };

    // ── Boss: Overlord Ramtusk (4420) — Thunderclap ~8yd AoE ────────────────────
    class OverlordRamtuskStartFightTrigger : public StartBossFightTrigger
    {
    public:
        OverlordRamtuskStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start overlord ramtusk fight", "overlord ramtusk", 4420) {}
    };

    class OverlordRamtuskEndFightTrigger : public EndBossFightTrigger
    {
    public:
        OverlordRamtuskEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end overlord ramtusk fight", "overlord ramtusk", 4420) {}
    };

    class RamtuskThunderclapTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        RamtuskThunderclapTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "ramtusk thunderclap", 4420, 8.0f, 3) {}
    };

    // ── Boss: Agathelos the Raging (4422) — Rampage ~8yd AoE ───────────────────
    class AgathelosStartFightTrigger : public StartBossFightTrigger
    {
    public:
        AgathelosStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start agathelos fight", "agathelos", 4422) {}
    };

    class AgathelosEndFightTrigger : public EndBossFightTrigger
    {
    public:
        AgathelosEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end agathelos fight", "agathelos", 4422) {}
    };

    class AgathelosRampageTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        AgathelosRampageTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "agathelos rampage", 4422, 8.0f, 3) {}
    };

    // ── Boss: Charlga Razorflank (4421) — Chain Bolt jumps to allies within ~8yd ─
    class CharlgaRazorflankStartFightTrigger : public StartBossFightTrigger
    {
    public:
        CharlgaRazorflankStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start charlga razorflank fight", "charlga razorflank", 4421) {}
    };

    class CharlgaRazorflankEndFightTrigger : public EndBossFightTrigger
    {
    public:
        CharlgaRazorflankEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end charlga razorflank fight", "charlga razorflank", 4421) {}
    };

    // Fires when bot is within 8yd of an ally — Chain Bolt jumps to targets within ~8yd
    class CharlgaChainBoltSpreadTrigger : public TooCloseToAllyTrigger
    {
    public:
        CharlgaChainBoltSpreadTrigger(PlayerbotAI* ai)
            : TooCloseToAllyTrigger(ai, "charlga chain bolt spread", 8.0f) {}
    };
}
