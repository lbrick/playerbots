#pragma once
#include "playerbot/strategy/triggers/DungeonTriggers.h"

namespace ai
{
    // ── Instance enter/leave (Map ID 48) ────────────────────────────────────────
    class BlackfathomDeepsEnterDungeonTrigger : public EnterDungeonTrigger
    {
    public:
        BlackfathomDeepsEnterDungeonTrigger(PlayerbotAI* ai)
            : EnterDungeonTrigger(ai, "enter blackfathom deeps", "blackfathom deeps", 48) {}
    };

    class BlackfathomDeepsLeaveDungeonTrigger : public LeaveDungeonTrigger
    {
    public:
        BlackfathomDeepsLeaveDungeonTrigger(PlayerbotAI* ai)
            : LeaveDungeonTrigger(ai, "leave blackfathom deeps", "blackfathom deeps", 48) {}
    };

    // ── Boss: Ghamoo-ra (4887) — Trample ~5yd melee AoE ────────────────────────
    class GhamooRaStartFightTrigger : public StartBossFightTrigger
    {
    public:
        GhamooRaStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start ghamoo-ra fight", "ghamoo-ra", 4887) {}
    };

    class GhamooRaEndFightTrigger : public EndBossFightTrigger
    {
    public:
        GhamooRaEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end ghamoo-ra fight", "ghamoo-ra", 4887) {}
    };

    // Trample ~5yd — stay >8yd (tank excepted by role logic in MoveAwayFromCreature)
    class GhamooRaTrampleTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        GhamooRaTrampleTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "ghamoo-ra trample", 4887, 8.0f, 3) {}
    };

    // ── Boss: Lady Sarevess (4831) — adds pull ──────────────────────────────────
    class LadySarevessStartFightTrigger : public StartBossFightTrigger
    {
    public:
        LadySarevessStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start lady sarevess fight", "lady sarevess", 4831) {}
    };

    class LadySarevessEndFightTrigger : public EndBossFightTrigger
    {
    public:
        LadySarevessEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end lady sarevess fight", "lady sarevess", 4831) {}
    };

    // ── Boss: Gelihast (6243) — start/end only ──────────────────────────────────
    class GelihastStartFightTrigger : public StartBossFightTrigger
    {
    public:
        GelihastStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start gelihast fight", "gelihast", 6243) {}
    };

    class GelihastEndFightTrigger : public EndBossFightTrigger
    {
    public:
        GelihastEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end gelihast fight", "gelihast", 6243) {}
    };

    // ── Boss: Lorgus Jett (12902) — start/end only (interrupt pending spell verify)
    class LorgusJettStartFightTrigger : public StartBossFightTrigger
    {
    public:
        LorgusJettStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start lorgus jett fight", "lorgus jett", 12902) {}
    };

    class LorgusJettEndFightTrigger : public EndBossFightTrigger
    {
    public:
        LorgusJettEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end lorgus jett fight", "lorgus jett", 12902) {}
    };

    // ── Boss: Baron Aquanis (12876) — event-spawn, start/end only ───────────────
    class BaronAquanisStartFightTrigger : public StartBossFightTrigger
    {
    public:
        BaronAquanisStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start baron aquanis fight", "baron aquanis", 12876) {}
    };

    class BaronAquanisEndFightTrigger : public EndBossFightTrigger
    {
    public:
        BaronAquanisEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end baron aquanis fight", "baron aquanis", 12876) {}
    };

    // ── Boss: Twilight Lord Kelris (4832) — start/end only (Sleep interrupt pending)
    class KelrisStartFightTrigger : public StartBossFightTrigger
    {
    public:
        KelrisStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start kelris fight", "kelris", 4832) {}
    };

    class KelrisEndFightTrigger : public EndBossFightTrigger
    {
    public:
        KelrisEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end kelris fight", "kelris", 4832) {}
    };

    // ── Boss: Aku'mai (4829) — Poison Cloud ~8yd ground AoE ─────────────────────
    class AkuMaiStartFightTrigger : public StartBossFightTrigger
    {
    public:
        AkuMaiStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start aku'mai fight", "aku'mai", 4829) {}
    };

    class AkuMaiEndFightTrigger : public EndBossFightTrigger
    {
    public:
        AkuMaiEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end aku'mai fight", "aku'mai", 4829) {}
    };

    // Poison Cloud ~8yd — stay >10yd
    class AkuMaiPoisonCloudTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        AkuMaiPoisonCloudTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "aku'mai poison cloud", 4829, 10.0f, 3) {}
    };

    // ── Lorgus Jett interrupt — Lightning Bolt (ID 12167, DB-verified) ──────────
    class LorgusJettLightningBoltCastingTrigger : public TargetCastingSpellTrigger
    {
    public:
        LorgusJettLightningBoltCastingTrigger(PlayerbotAI* ai)
            : TargetCastingSpellTrigger(ai, "target casting lorgus jett lightning bolt", 12167) {}
    };

    // ── Kelris interrupt — Sleep (ID 8399, DB-verified) ─────────────────────────
    class KelrisSleepCastingTrigger : public TargetCastingSpellTrigger
    {
    public:
        KelrisSleepCastingTrigger(PlayerbotAI* ai)
            : TargetCastingSpellTrigger(ai, "target casting kelris sleep", 8399) {}
    };
}
