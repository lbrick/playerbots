#pragma once
#include "playerbot/strategy/Strategy.h"

namespace ai
{
    // Loaded while group is in Uldaman (map 70). Registers boss start triggers.
    class UldamanDungeonStrategy : public Strategy
    {
    public:
        UldamanDungeonStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "uldaman"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Revelosh (6910) — no positional mechanic
    class ReveloshFightStrategy : public Strategy
    {
    public:
        ReveloshFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "revelosh"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Baelog / Lost Dwarves (6913) — no positional mechanic
    class BaelogFightStrategy : public Strategy
    {
    public:
        BaelogFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "baelog"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Ironaya (7228) — War Stomp ~8yd AoE
    class IronayaFightStrategy : public Strategy
    {
    public:
        IronayaFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "ironaya"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Obsidian Sentinel (7023) — no positional mechanic
    class ObsidianSentinelFightStrategy : public Strategy
    {
    public:
        ObsidianSentinelFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "obsidian sentinel"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Ancient Stone Keeper (4857) — War Stomp ~8yd AoE
    class AncientStoneKeeperFightStrategy : public Strategy
    {
    public:
        AncientStoneKeeperFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "ancient stone keeper"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Galgann Firehammer (7291) — Fire Nova ~10yd AoE
    class GalgannFirehammerFightStrategy : public Strategy
    {
    public:
        GalgannFirehammerFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "galgann firehammer"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Grimlok (4854) — War Stomp ~8yd AoE
    class GrimlokFightStrategy : public Strategy
    {
    public:
        GrimlokFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "grimlok"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Archaedas (2748) — Earth Tremor ~15yd AoE
    class ArchaedasFightStrategy : public Strategy
    {
    public:
        ArchaedasFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "archaedas"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };
}
