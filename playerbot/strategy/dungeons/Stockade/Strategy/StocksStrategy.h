#pragma once
#include "playerbot/strategy/Strategy.h"

namespace ai
{
    // Loaded while group is in The Stockade (map 34). Registers boss start triggers.
    class StocksDungeonStrategy : public Strategy
    {
    public:
        StocksDungeonStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "stockade"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Targorr the Dread (1696) — Slam knockback
    class TargorrFightStrategy : public Strategy
    {
    public:
        TargorrFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "targorr"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Kam Deepfury (1666) — Earthbolt/Earth Shock, no positional mechanic
    class KamDeepfuryFightStrategy : public Strategy
    {
    public:
        KamDeepfuryFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "kam deepfury"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Hamhock (1717) — Chain Lightning, bots must spread
    class HamhockFightStrategy : public Strategy
    {
    public:
        HamhockFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "hamhock"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Bazil Thredd (1716) — Backstab, no positional mechanic
    class BazilThreddFightStrategy : public Strategy
    {
    public:
        BazilThreddFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "bazil thredd"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Dextren Ward (1663) — Intimidating Shout AoE fear, pre-position >12yd
    class DextrenWardFightStrategy : public Strategy
    {
    public:
        DextrenWardFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "dextren ward"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };
}
