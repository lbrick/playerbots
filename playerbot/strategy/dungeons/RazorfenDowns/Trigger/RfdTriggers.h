#pragma once
#include "playerbot/strategy/triggers/DungeonTriggers.h"

namespace ai
{
    // ── Instance enter/leave (Map ID 129) ───────────────────────────────────────
    class RazorfenDownsEnterDungeonTrigger : public EnterDungeonTrigger
    {
    public:
        RazorfenDownsEnterDungeonTrigger(PlayerbotAI* ai)
            : EnterDungeonTrigger(ai, "enter razorfen downs", "razorfen downs", 129) {}
    };

    class RazorfenDownsLeaveDungeonTrigger : public LeaveDungeonTrigger
    {
    public:
        RazorfenDownsLeaveDungeonTrigger(PlayerbotAI* ai)
            : LeaveDungeonTrigger(ai, "leave razorfen downs", "razorfen downs", 129) {}
    };

    // ── Boss: Tuten'kash (7355) — no positional mechanic ────────────────────────
    class TutenkashStartFightTrigger : public StartBossFightTrigger
    {
    public:
        TutenkashStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start tuten'kash fight", "tuten'kash", 7355) {}
    };

    class TutenkashEndFightTrigger : public EndBossFightTrigger
    {
    public:
        TutenkashEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end tuten'kash fight", "tuten'kash", 7355) {}
    };

    // ── Boss: Mordresh Fire Eye (7357) — Fire Nova ~10yd AoE ────────────────────
    class MordreshStartFightTrigger : public StartBossFightTrigger
    {
    public:
        MordreshStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start mordresh fire eye fight", "mordresh fire eye", 7357) {}
    };

    class MordreshEndFightTrigger : public EndBossFightTrigger
    {
    public:
        MordreshEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end mordresh fire eye fight", "mordresh fire eye", 7357) {}
    };

    class MordreshFireNovaTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        MordreshFireNovaTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "mordresh fire nova", 7357, 10.0f, 3) {}
    };

    // ── Boss: Glutton (7354) — no positional mechanic ───────────────────────────
    class GluttonStartFightTrigger : public StartBossFightTrigger
    {
    public:
        GluttonStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start glutton fight", "glutton", 7354) {}
    };

    class GluttonEndFightTrigger : public EndBossFightTrigger
    {
    public:
        GluttonEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end glutton fight", "glutton", 7354) {}
    };

    // ── Boss: Amnennar the Coldbringer (7358) — Frost Nova ~8yd AoE ─────────────
    class AmnennarStartFightTrigger : public StartBossFightTrigger
    {
    public:
        AmnennarStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start amnennar the coldbringer fight", "amnennar the coldbringer", 7358) {}
    };

    class AmnennarEndFightTrigger : public EndBossFightTrigger
    {
    public:
        AmnennarEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end amnennar the coldbringer fight", "amnennar the coldbringer", 7358) {}
    };

    class AmnennarFrostNovaTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        AmnennarFrostNovaTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "amnennar frost nova", 7358, 8.0f, 3) {}
    };
}
