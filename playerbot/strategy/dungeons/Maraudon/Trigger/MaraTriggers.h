#pragma once
#include "playerbot/strategy/triggers/DungeonTriggers.h"

namespace ai
{
    // ── Instance enter/leave (Map ID 349) ───────────────────────────────────────
    class MaraudonEnterDungeonTrigger : public EnterDungeonTrigger
    {
    public:
        MaraudonEnterDungeonTrigger(PlayerbotAI* ai)
            : EnterDungeonTrigger(ai, "enter maraudon", "maraudon", 349) {}
    };

    class MaraudonLeaveDungeonTrigger : public LeaveDungeonTrigger
    {
    public:
        MaraudonLeaveDungeonTrigger(PlayerbotAI* ai)
            : LeaveDungeonTrigger(ai, "leave maraudon", "maraudon", 349) {}
    };

    // ── Boss: Noxxion (13282) — Noxious Fumes ~8yd AoE ─────────────────────────
    class NoxxionStartFightTrigger : public StartBossFightTrigger
    {
    public:
        NoxxionStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start noxxion fight", "noxxion", 13282) {}
    };

    class NoxxionEndFightTrigger : public EndBossFightTrigger
    {
    public:
        NoxxionEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end noxxion fight", "noxxion", 13282) {}
    };

    class NoxxionNoxiousFumesTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        NoxxionNoxiousFumesTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "noxxion noxious fumes", 13282, 8.0f, 4) {}
    };

    // ── Boss: Razorlash (12258) — no positional mechanic ────────────────────────
    class RazorlashStartFightTrigger : public StartBossFightTrigger
    {
    public:
        RazorlashStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start razorlash fight", "razorlash", 12258) {}
    };

    class RazorlashEndFightTrigger : public EndBossFightTrigger
    {
    public:
        RazorlashEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end razorlash fight", "razorlash", 12258) {}
    };

    // ── Boss: Lord Vyletongue (12236) — DB verified; no positional mechanic ─────
    class LordVyletongueStartFightTrigger : public StartBossFightTrigger
    {
    public:
        LordVyletongueStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start lord vyletongue fight", "lord vyletongue", 12236) {}
    };

    class LordVyletongueEndFightTrigger : public EndBossFightTrigger
    {
    public:
        LordVyletongueEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end lord vyletongue fight", "lord vyletongue", 12236) {}
    };

    // ── Boss: Celebras the Cursed (12225) — DB verified; no positional mechanic ─
    class CelebrasStartFightTrigger : public StartBossFightTrigger
    {
    public:
        CelebrasStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start celebras the cursed fight", "celebras the cursed", 12225) {}
    };

    class CelebrasEndFightTrigger : public EndBossFightTrigger
    {
    public:
        CelebrasEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end celebras the cursed fight", "celebras the cursed", 12225) {}
    };

    // ── Celebras interrupt — Wrath (ID 21807, DB-verified) ──────────────────────
    class CelebrasWrathCastingTrigger : public TargetCastingSpellTrigger
    {
    public:
        CelebrasWrathCastingTrigger(PlayerbotAI* ai)
            : TargetCastingSpellTrigger(ai, "target casting celebras wrath", 21807) {}
    };

    // ── Celebras interrupt — Entangling Roots (ID 12747, DB-verified) ───────────
    class CelebrasRootsCastingTrigger : public TargetCastingSpellTrigger
    {
    public:
        CelebrasRootsCastingTrigger(PlayerbotAI* ai)
            : TargetCastingSpellTrigger(ai, "target casting celebras roots", 12747) {}
    };

    // ── Boss: Landslide (12203) — DB verified; no positional mechanic ───────────
    class LandslideStartFightTrigger : public StartBossFightTrigger
    {
    public:
        LandslideStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start landslide fight", "landslide", 12203) {}
    };

    class LandslideEndFightTrigger : public EndBossFightTrigger
    {
    public:
        LandslideEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end landslide fight", "landslide", 12203) {}
    };

    // ── Boss: Tinkerer Gizlock (13601) — Smoke Bomb ~8yd AoE ────────────────────
    class GizlockStartFightTrigger : public StartBossFightTrigger
    {
    public:
        GizlockStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start tinkerer gizlock fight", "tinkerer gizlock", 13601) {}
    };

    class GizlockEndFightTrigger : public EndBossFightTrigger
    {
    public:
        GizlockEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end tinkerer gizlock fight", "tinkerer gizlock", 13601) {}
    };

    class GizlockSmokeBombTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        GizlockSmokeBombTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "gizlock smoke bomb", 13601, 8.0f, 3) {}
    };

    // ── Boss: Rotgrip (13596) — no positional mechanic ──────────────────────────
    class RotgripStartFightTrigger : public StartBossFightTrigger
    {
    public:
        RotgripStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start rotgrip fight", "rotgrip", 13596) {}
    };

    class RotgripEndFightTrigger : public EndBossFightTrigger
    {
    public:
        RotgripEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end rotgrip fight", "rotgrip", 13596) {}
    };

    // ── Boss: Princess Theradras (12201) — Dust Field ~10yd AoE ─────────────────
    class TheradrasStartFightTrigger : public StartBossFightTrigger
    {
    public:
        TheradrasStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start princess theradras fight", "princess theradras", 12201) {}
    };

    class TheradrasEndFightTrigger : public EndBossFightTrigger
    {
    public:
        TheradrasEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end princess theradras fight", "princess theradras", 12201) {}
    };

    class TheradrasDustFieldTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        TheradrasDustFieldTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "theradras dust field", 12201, 10.0f, 3) {}
    };
}
