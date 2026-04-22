#pragma once
#include "playerbot/strategy/triggers/DungeonTriggers.h"

namespace ai
{
    // ── Instance enter/leave (Map ID 36) ────────────────────────────────────────
    class DeadminesEnterDungeonTrigger : public EnterDungeonTrigger
    {
    public:
        DeadminesEnterDungeonTrigger(PlayerbotAI* ai)
            : EnterDungeonTrigger(ai, "enter deadmines", "deadmines", 36) {}
    };

    class DeadminesLeaveDungeonTrigger : public LeaveDungeonTrigger
    {
    public:
        DeadminesLeaveDungeonTrigger(PlayerbotAI* ai)
            : LeaveDungeonTrigger(ai, "leave deadmines", "deadmines", 36) {}
    };

    // ── Boss: Rhahk'Zor (644) — Rhahk'Zor's Slam knockback ──────────────────────
    class RhahkzorStartFightTrigger : public StartBossFightTrigger
    {
    public:
        RhahkzorStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start rhahkzor fight", "rhahkzor", 644) {}
    };

    class RhahkzorEndFightTrigger : public EndBossFightTrigger
    {
    public:
        RhahkzorEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end rhahkzor fight", "rhahkzor", 644) {}
    };

    // Fires when bot is within 8 yards of Rhahk'Zor — Slam knockback ~5yd
    class RhahkzorSlamTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        RhahkzorSlamTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "rhahkzor slam", 644, 8.0f, 3) {}
    };

    // ── Boss: Sneed's Shredder (642) — Saw Blade AoE ────────────────────────────
    class SneedShredderStartFightTrigger : public StartBossFightTrigger
    {
    public:
        SneedShredderStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start sneed shredder fight", "sneed shredder", 642) {}
    };

    class SneedShredderEndFightTrigger : public EndBossFightTrigger
    {
    public:
        SneedShredderEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end sneed shredder fight", "sneed shredder", 642) {}
    };

    // Fires when bot is within 10 yards of Shredder — Saw Blade hits ~8yd
    class SneedShredderSawBladeTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        SneedShredderSawBladeTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "sneed shredder saw blade", 642, 10.0f, 3) {}
    };

    // ── Boss: Sneed (643) — spawns when Shredder dies, simple melee ─────────────
    class SneedStartFightTrigger : public StartBossFightTrigger
    {
    public:
        SneedStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start sneed fight", "sneed", 643) {}
    };

    class SneedEndFightTrigger : public EndBossFightTrigger
    {
    public:
        SneedEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end sneed fight", "sneed", 643) {}
    };

    // ── Boss: Gilnid (1763) — Molten Metal AoE puddle ───────────────────────────
    class GilnidStartFightTrigger : public StartBossFightTrigger
    {
    public:
        GilnidStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start gilnid fight", "gilnid", 1763) {}
    };

    class GilnidEndFightTrigger : public EndBossFightTrigger
    {
    public:
        GilnidEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end gilnid fight", "gilnid", 1763) {}
    };

    // Fires when bot is within 8 yards of Gilnid — Molten Metal puddle ~6yd
    class GilnidMoltenMetalTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        GilnidMoltenMetalTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "gilnid molten metal", 1763, 8.0f, 3) {}
    };

    // ── Boss: Mr. Smite (646) — stun + weapon switch phases ─────────────────────
    class SmiteStartFightTrigger : public StartBossFightTrigger
    {
    public:
        SmiteStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start smite fight", "smite", 646) {}
    };

    class SmiteEndFightTrigger : public EndBossFightTrigger
    {
    public:
        SmiteEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end smite fight", "smite", 646) {}
    };

    // Fires when bot is within 12 yards — Smite's Mighty Blow knockback ~10yd (hammer phase)
    class SmiteHammerPhaseTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        SmiteHammerPhaseTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "smite hammer phase", 646, 12.0f, 3) {}
    };

    // ── Boss: Cookie (645) — Throw Food debuffs, no positional mechanic ─────────
    class CookieStartFightTrigger : public StartBossFightTrigger
    {
    public:
        CookieStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start cookie fight", "cookie", 645) {}
    };

    class CookieEndFightTrigger : public EndBossFightTrigger
    {
    public:
        CookieEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end cookie fight", "cookie", 645) {}
    };

    // ── Boss: Edwin VanCleef (639) — adds spawn at 50% ──────────────────────────
    class VanCleefStartFightTrigger : public StartBossFightTrigger
    {
    public:
        VanCleefStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start vancleef fight", "vancleef", 639) {}
    };

    class VanCleefEndFightTrigger : public EndBossFightTrigger
    {
    public:
        VanCleefEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end vancleef fight", "vancleef", 639) {}
    };
}
