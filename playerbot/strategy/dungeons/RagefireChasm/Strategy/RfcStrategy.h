#pragma once
#include "playerbot/strategy/Strategy.h"

namespace ai
{
    // Loaded while group is in RFC (map 389). Registers boss start triggers.
    class RagefireChasmDungeonStrategy : public Strategy
    {
    public:
        RagefireChasmDungeonStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "ragefire chasm"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Oggleflint — simple melee, no dangerous mechanics
    class OggleflintFightStrategy : public Strategy
    {
    public:
        OggleflintFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "oggleflint"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Taragaman — Firenova AoE avoidance
    class TaragamanFightStrategy : public Strategy
    {
    public:
        TaragamanFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "taragaman"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Jergosh — Immolate/Curse handled by existing cure strategies
    class JergoshFightStrategy : public Strategy
    {
    public:
        JergoshFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "jergosh"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Bazzalan — Poison DoT handled by existing cure strategies
    class BazzalanFightStrategy : public Strategy
    {
    public:
        BazzalanFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "bazzalan"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };
}
