#pragma once
#include "playerbot/strategy/triggers/DungeonTriggers.h"

namespace ai
{
    // ── Instance enter/leave (Map ID 209) ───────────────────────────────────────
    class ZulFarrakEnterDungeonTrigger : public EnterDungeonTrigger
    {
    public:
        ZulFarrakEnterDungeonTrigger(PlayerbotAI* ai)
            : EnterDungeonTrigger(ai, "enter zul'farrak", "zul'farrak", 209) {}
    };

    class ZulFarrakLeaveDungeonTrigger : public LeaveDungeonTrigger
    {
    public:
        ZulFarrakLeaveDungeonTrigger(PlayerbotAI* ai)
            : LeaveDungeonTrigger(ai, "leave zul'farrak", "zul'farrak", 209) {}
    };

    // ── Boss: Theka the Martyr (7272) — no positional mechanic ──────────────────
    class ThekaStartFightTrigger : public StartBossFightTrigger
    {
    public:
        ThekaStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start theka the martyr fight", "theka the martyr", 7272) {}
    };

    class ThekaEndFightTrigger : public EndBossFightTrigger
    {
    public:
        ThekaEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end theka the martyr fight", "theka the martyr", 7272) {}
    };

    // ── Boss: Witch Doctor Zum'rah (7271) — no positional mechanic ──────────────
    class ZumrahStartFightTrigger : public StartBossFightTrigger
    {
    public:
        ZumrahStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start witch doctor zum'rah fight", "witch doctor zum'rah", 7271) {}
    };

    class ZumrahEndFightTrigger : public EndBossFightTrigger
    {
    public:
        ZumrahEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end witch doctor zum'rah fight", "witch doctor zum'rah", 7271) {}
    };

    // ── Boss: Antu'sul (8127) — no positional mechanic ──────────────────────────
    class AntusulStartFightTrigger : public StartBossFightTrigger
    {
    public:
        AntusulStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start antu'sul fight", "antu'sul", 8127) {}
    };

    class AntusulEndFightTrigger : public EndBossFightTrigger
    {
    public:
        AntusulEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end antu'sul fight", "antu'sul", 8127) {}
    };

    // ── Boss: Shadowpriest Sezz'ziz (7275) — no positional mechanic ─────────────
    class SezzizStartFightTrigger : public StartBossFightTrigger
    {
    public:
        SezzizStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start shadowpriest sezz'ziz fight", "shadowpriest sezz'ziz", 7275) {}
    };

    class SezzizEndFightTrigger : public EndBossFightTrigger
    {
    public:
        SezzizEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end shadowpriest sezz'ziz fight", "shadowpriest sezz'ziz", 7275) {}
    };

    // ── Boss: Sergeant Bly (7604) — staircase event, no positional mechanic ─────
    class SergeantBlyStartFightTrigger : public StartBossFightTrigger
    {
    public:
        SergeantBlyStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start sergeant bly fight", "sergeant bly", 7604) {}
    };

    class SergeantBlyEndFightTrigger : public EndBossFightTrigger
    {
    public:
        SergeantBlyEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end sergeant bly fight", "sergeant bly", 7604) {}
    };

    // ── Boss: Gahz'rilla (7273) — Freeze ~10yd AoE ──────────────────────────────
    class GahzrillaStartFightTrigger : public StartBossFightTrigger
    {
    public:
        GahzrillaStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start gahz'rilla fight", "gahz'rilla", 7273) {}
    };

    class GahzrillaEndFightTrigger : public EndBossFightTrigger
    {
    public:
        GahzrillaEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end gahz'rilla fight", "gahz'rilla", 7273) {}
    };

    class GahzrillaFreezeTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        GahzrillaFreezeTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "gahz'rilla freeze", 7273, 10.0f, 3) {}
    };

    // ── Boss: Chief Ukorz Sandscalp (7267) — no positional mechanic ─────────────
    class ChiefUkorzStartFightTrigger : public StartBossFightTrigger
    {
    public:
        ChiefUkorzStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start chief ukorz sandscalp fight", "chief ukorz sandscalp", 7267) {}
    };

    class ChiefUkorzEndFightTrigger : public EndBossFightTrigger
    {
    public:
        ChiefUkorzEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end chief ukorz sandscalp fight", "chief ukorz sandscalp", 7267) {}
    };
}
