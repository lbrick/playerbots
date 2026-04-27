#pragma once
#include "playerbot/strategy/Strategy.h"

namespace ai
{
    // Loaded while group is in Razorfen Kraul (map 47). Registers boss start triggers.
    class RazorfenKraulDungeonStrategy : public Strategy
    {
    public:
        RazorfenKraulDungeonStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "razorfen kraul"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Roogug (6168) — no positional mechanic
    class RoogugFightStrategy : public Strategy
    {
    public:
        RoogugFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "roogug"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Aggem Thorncurse (4424) — no positional mechanic
    class AggEmThorncurseFightStrategy : public Strategy
    {
    public:
        AggEmThorncurseFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "aggem thorncurse"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Death Speaker Jargba (4428) — no positional mechanic
    class DeathSpeakerJargbaFightStrategy : public Strategy
    {
    public:
        DeathSpeakerJargbaFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "death speaker jargba"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Overlord Ramtusk (4420) — Thunderclap ~8yd AoE
    class OverlordRamtuskFightStrategy : public Strategy
    {
    public:
        OverlordRamtuskFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "overlord ramtusk"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Agathelos the Raging (4422) — Rampage ~8yd AoE
    class AgathelosFightStrategy : public Strategy
    {
    public:
        AgathelosFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "agathelos"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Charlga Razorflank (4421) — Chain Bolt jumps allies within ~8yd, must spread
    class CharlgaRazorflankFightStrategy : public Strategy
    {
    public:
        CharlgaRazorflankFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "charlga razorflank"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };
}
