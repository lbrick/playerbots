#pragma once
#include "playerbot/strategy/triggers/DungeonTriggers.h"

namespace ai
{
    // ── Instance enter/leave (Map ID 389) ───────────────────────────────────────
    class RagefireChasmEnterDungeonTrigger : public EnterDungeonTrigger
    {
    public:
        RagefireChasmEnterDungeonTrigger(PlayerbotAI* ai)
            : EnterDungeonTrigger(ai, "enter ragefire chasm", "ragefire chasm", 389) {}
    };

    class RagefireChasmLeaveDungeonTrigger : public LeaveDungeonTrigger
    {
    public:
        RagefireChasmLeaveDungeonTrigger(PlayerbotAI* ai)
            : LeaveDungeonTrigger(ai, "leave ragefire chasm", "ragefire chasm", 389) {}
    };

    // ── Boss: Oggleflint (11517) — no dangerous mechanic ────────────────────────
    class OggleflintStartFightTrigger : public StartBossFightTrigger
    {
    public:
        OggleflintStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start oggleflint fight", "oggleflint", 11517) {}
    };

    class OggleflintEndFightTrigger : public EndBossFightTrigger
    {
    public:
        OggleflintEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end oggleflint fight", "oggleflint", 11517) {}
    };

    // ── Boss: Taragaman the Hungerer (11520) — Firenova AoE ~10yd ───────────────
    class TaragamanStartFightTrigger : public StartBossFightTrigger
    {
    public:
        TaragamanStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start taragaman fight", "taragaman", 11520) {}
    };

    class TaragamanEndFightTrigger : public EndBossFightTrigger
    {
    public:
        TaragamanEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end taragaman fight", "taragaman", 11520) {}
    };

    // Fires when bot is within 12 yards of Taragaman — Firenova hits ~10yd
    class TaragamanFirenovaTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        TaragamanFirenovaTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "taragaman firenova", 11520, 12.0f, 3) {}
    };

    // ── Boss: Jergosh the Invoker (11518) — DoTs handled by cure strategy ────────
    class JergoshStartFightTrigger : public StartBossFightTrigger
    {
    public:
        JergoshStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start jergosh fight", "jergosh", 11518) {}
    };

    class JergoshEndFightTrigger : public EndBossFightTrigger
    {
    public:
        JergoshEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end jergosh fight", "jergosh", 11518) {}
    };

    // ── Boss: Bazzalan (11519) — Poison DoT handled by cure strategy ─────────────
    class BazzalanStartFightTrigger : public StartBossFightTrigger
    {
    public:
        BazzalanStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start bazzalan fight", "bazzalan", 11519) {}
    };

    class BazzalanEndFightTrigger : public EndBossFightTrigger
    {
    public:
        BazzalanEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end bazzalan fight", "bazzalan", 11519) {}
    };

    // ── Jergosh interrupt — Immolate (ID 20800, DB-verified) ────────────────────
    class JergoshImmolateCastingTrigger : public TargetCastingSpellTrigger
    {
    public:
        JergoshImmolateCastingTrigger(PlayerbotAI* ai)
            : TargetCastingSpellTrigger(ai, "target casting jergosh immolate", 20800) {}
    };
}
