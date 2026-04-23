#pragma once
#include "playerbot/strategy/Strategy.h"

namespace ai
{
    // Loaded while group is in SFK (map 33). Registers boss start triggers.
    class ShadowfangKeepDungeonStrategy : public Strategy
    {
    public:
        ShadowfangKeepDungeonStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "shadowfang keep"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
    };

    class RethilgoreFightStrategy : public Strategy
    {
    public:
        RethilgoreFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "rethilgore"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    class RazorclawFightStrategy : public Strategy
    {
    public:
        RazorclawFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "razorclaw"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    class SilverlaineFightStrategy : public Strategy
    {
    public:
        SilverlaineFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "silverlaine"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    class SpringvaleFightStrategy : public Strategy
    {
    public:
        SpringvaleFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "springvale"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    class OdoFightStrategy : public Strategy
    {
    public:
        OdoFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "odo"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    class FenrusFightStrategy : public Strategy
    {
    public:
        FenrusFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "fenrus"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    class NandosFightStrategy : public Strategy
    {
    public:
        NandosFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "nandos"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    class ArugalFightStrategy : public Strategy
    {
    public:
        ArugalFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "arugal"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };
}
