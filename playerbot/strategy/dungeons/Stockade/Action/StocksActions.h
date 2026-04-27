#pragma once
#include "playerbot/strategy/actions/DungeonActions.h"

namespace ai
{
    // ── Instance strategy enable/disable ────────────────────────────────────────
    class StocksEnableStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        StocksEnableStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable stockade strategy", "+stockade") {}
    };

    class StocksDisableStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        StocksDisableStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable stockade strategy", "-stockade") {}
    };

    // ── Targorr the Dread ────────────────────────────────────────────────────────
    class TargorrEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        TargorrEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable targorr fight strategy", "+targorr") {}
    };

    class TargorrDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        TargorrDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable targorr fight strategy", "-targorr") {}
    };

    // Slam knockback avoidance — stay >8 yards
    class TargorrMoveAwayFromSlamAction : public MoveAwayFromCreature
    {
    public:
        TargorrMoveAwayFromSlamAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "targorr move away from slam", 1696, 8.0f) {}
    };

    // ── Kam Deepfury ─────────────────────────────────────────────────────────────
    class KamDeepfuryEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        KamDeepfuryEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable kam deepfury fight strategy", "+kam deepfury") {}
    };

    class KamDeepfuryDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        KamDeepfuryDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable kam deepfury fight strategy", "-kam deepfury") {}
    };

    // ── Hamhock ───────────────────────────────────────────────────────────────────
    class HamhockEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        HamhockEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable hamhock fight strategy", "+hamhock") {}
    };

    class HamhockDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        HamhockDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable hamhock fight strategy", "-hamhock") {}
    };

    // Chain Lightning avoidance — stay >12 yards to break chain jump
    class HamhockMoveAwayFromChainLightningAction : public MoveAwayFromCreature
    {
    public:
        HamhockMoveAwayFromChainLightningAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "hamhock move away from chain lightning", 1717, 12.0f) {}
    };

    // ── Bazil Thredd ──────────────────────────────────────────────────────────────
    class BazilThreddEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        BazilThreddEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable bazil thredd fight strategy", "+bazil thredd") {}
    };

    class BazilThreddDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        BazilThreddDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable bazil thredd fight strategy", "-bazil thredd") {}
    };

    // ── Dextren Ward ──────────────────────────────────────────────────────────────
    class DextrenWardEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        DextrenWardEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable dextren ward fight strategy", "+dextren ward") {}
    };

    class DextrenWardDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        DextrenWardDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable dextren ward fight strategy", "-dextren ward") {}
    };

    // Intimidating Shout fear avoidance — pre-position >12 yards
    class DextrenWardMoveAwayFromIntimidatingShoutAction : public MoveAwayFromCreature
    {
    public:
        DextrenWardMoveAwayFromIntimidatingShoutAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "dextren ward move away from intimidating shout", 1663, 12.0f) {}
    };
}
