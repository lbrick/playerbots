#pragma once
#include "playerbot/strategy/triggers/DungeonTriggers.h"

namespace ai
{
    // ── Instance enter/leave (Map ID 34) ────────────────────────────────────────
    class StocksEnterDungeonTrigger : public EnterDungeonTrigger
    {
    public:
        StocksEnterDungeonTrigger(PlayerbotAI* ai)
            : EnterDungeonTrigger(ai, "enter stockade", "stockade", 34) {}
    };

    class StocksLeaveDungeonTrigger : public LeaveDungeonTrigger
    {
    public:
        StocksLeaveDungeonTrigger(PlayerbotAI* ai)
            : LeaveDungeonTrigger(ai, "leave stockade", "stockade", 34) {}
    };

    // ── Boss: Targorr the Dread (1696) — Slam knockback ~5yd ────────────────────
    class TargorrStartFightTrigger : public StartBossFightTrigger
    {
    public:
        TargorrStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start targorr fight", "targorr", 1696) {}
    };

    class TargorrEndFightTrigger : public EndBossFightTrigger
    {
    public:
        TargorrEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end targorr fight", "targorr", 1696) {}
    };

    class TargorrSlamTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        TargorrSlamTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "targorr slam", 1696, 8.0f, 3) {}
    };

    // ── Boss: Kam Deepfury (1666) — Earthbolt/Earth Shock, no positional ────────
    class KamDeepfuryStartFightTrigger : public StartBossFightTrigger
    {
    public:
        KamDeepfuryStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start kam deepfury fight", "kam deepfury", 1666) {}
    };

    class KamDeepfuryEndFightTrigger : public EndBossFightTrigger
    {
    public:
        KamDeepfuryEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end kam deepfury fight", "kam deepfury", 1666) {}
    };

    // ── Boss: Hamhock (1717) — Chain Lightning ~10yd, must spread ───────────────
    class HamhockStartFightTrigger : public StartBossFightTrigger
    {
    public:
        HamhockStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start hamhock fight", "hamhock", 1717) {}
    };

    class HamhockEndFightTrigger : public EndBossFightTrigger
    {
    public:
        HamhockEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end hamhock fight", "hamhock", 1717) {}
    };

    class HamhockChainLightningTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        HamhockChainLightningTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "hamhock chain lightning", 1717, 12.0f, 3) {}
    };

    // ── Boss: Bazil Thredd (1716) — Backstab, no positional ─────────────────────
    class BazilThreddStartFightTrigger : public StartBossFightTrigger
    {
    public:
        BazilThreddStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start bazil thredd fight", "bazil thredd", 1716) {}
    };

    class BazilThreddEndFightTrigger : public EndBossFightTrigger
    {
    public:
        BazilThreddEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end bazil thredd fight", "bazil thredd", 1716) {}
    };

    // ── Boss: Dextren Ward (1663) — Intimidating Shout AoE fear 10yd ───────────
    class DextrenWardStartFightTrigger : public StartBossFightTrigger
    {
    public:
        DextrenWardStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start dextren ward fight", "dextren ward", 1663) {}
    };

    class DextrenWardEndFightTrigger : public EndBossFightTrigger
    {
    public:
        DextrenWardEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end dextren ward fight", "dextren ward", 1663) {}
    };

    // Pre-position bots >12yd to stay outside Intimidating Shout fear radius
    class DextrenWardIntimidatingShoutTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        DextrenWardIntimidatingShoutTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "dextren ward intimidating shout", 1663, 12.0f, 3) {}
    };
}
