#pragma once
#include "src/Ai/Base/triggers/DungeonTriggers.h"

namespace ai
{
    // ── Instance enter/leave (Map ID 43) ────────────────────────────────────────
    class WailingCavernsEnterDungeonTrigger : public EnterDungeonTrigger
    {
    public:
        WailingCavernsEnterDungeonTrigger(PlayerbotAI* ai)
            : EnterDungeonTrigger(ai, "enter wailing caverns", "wailing caverns", 43) {}
    };

    class WailingCavernsLeaveDungeonTrigger : public LeaveDungeonTrigger
    {
    public:
        WailingCavernsLeaveDungeonTrigger(PlayerbotAI* ai)
            : LeaveDungeonTrigger(ai, "leave wailing caverns", "wailing caverns", 43) {}
    };

    // ── Druid's Slumber interrupt (ID 8040) — boss + trash ─────────────────────
    // Fires when current target is casting Druid's Slumber.
    // Registered in instance strategy so it covers trash as well as bosses.
    class DruidSlumberCastingTrigger : public TargetCastingSpellTrigger
    {
    public:
        DruidSlumberCastingTrigger(PlayerbotAI* ai)
            : TargetCastingSpellTrigger(ai, "target casting druid slumber", 8040) {}
    };

    // ── Boss: Kresh (3653) — optional; no dangerous mechanic ────────────────────
    class KreshStartFightTrigger : public StartBossFightTrigger
    {
    public:
        KreshStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start kresh fight", "kresh", 3653) {}
    };

    class KreshEndFightTrigger : public EndBossFightTrigger
    {
    public:
        KreshEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end kresh fight", "kresh", 3653) {}
    };

    // ── Boss: Lady Anacondra (3671) — Sleep AoE, not positional ─────────────────
    class AnacondraStartFightTrigger : public StartBossFightTrigger
    {
    public:
        AnacondraStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start anacondra fight", "anacondra", 3671) {}
    };

    class AnacondraEndFightTrigger : public EndBossFightTrigger
    {
    public:
        AnacondraEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end anacondra fight", "anacondra", 3671) {}
    };

    // ── Boss: Lord Cobrahn (3669) — Drain Life, handled by healers ──────────────
    class CobrahnStartFightTrigger : public StartBossFightTrigger
    {
    public:
        CobrahnStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start cobrahn fight", "cobrahn", 3669) {}
    };

    class CobrahnEndFightTrigger : public EndBossFightTrigger
    {
    public:
        CobrahnEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end cobrahn fight", "cobrahn", 3669) {}
    };

    // ── Boss: Lord Pythas (3670) — Entangling Roots, targeted ───────────────────
    class PythasStartFightTrigger : public StartBossFightTrigger
    {
    public:
        PythasStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start pythas fight", "pythas", 3670) {}
    };

    class PythasEndFightTrigger : public EndBossFightTrigger
    {
    public:
        PythasEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end pythas fight", "pythas", 3670) {}
    };

    // ── Boss: Lord Serpentis (3673) — Cause Insanity, not positional ────────────
    class SerpentisStartFightTrigger : public StartBossFightTrigger
    {
    public:
        SerpentisStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start serpentis fight", "serpentis", 3673) {}
    };

    class SerpentisEndFightTrigger : public EndBossFightTrigger
    {
    public:
        SerpentisEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end serpentis fight", "serpentis", 3673) {}
    };

    // ── Boss: Verdan the Everliving (5775) — Grasping Vines roots ~8yd ──────────
    class VerdanStartFightTrigger : public StartBossFightTrigger
    {
    public:
        VerdanStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start verdan fight", "verdan", 5775) {}
    };

    class VerdanEndFightTrigger : public EndBossFightTrigger
    {
    public:
        VerdanEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end verdan fight", "verdan", 5775) {}
    };

    // Fires when bot is within 10 yards of Verdan — Grasping Vines hits ~8yd
    class VerdanGraspingVinesTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        VerdanGraspingVinesTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "verdan grasping vines", 5775, 10.0f, 3) {}
    };

    // ── Boss: Mutanus the Devourer (3654) — Thundercrack + Terrify AoE ~10yd ────
    class MutanusStartFightTrigger : public StartBossFightTrigger
    {
    public:
        MutanusStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start mutanus fight", "mutanus", 3654) {}
    };

    class MutanusEndFightTrigger : public EndBossFightTrigger
    {
    public:
        MutanusEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end mutanus fight", "mutanus", 3654) {}
    };

    // Fires when bot is within 12 yards of Mutanus — Thundercrack/Terrify hit ~10yd
    class MutanusAoeTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        MutanusAoeTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "mutanus aoe", 3654, 12.0f, 3) {}
    };
}
