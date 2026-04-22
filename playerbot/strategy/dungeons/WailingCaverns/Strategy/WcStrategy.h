#pragma once
#include "playerbot/strategy/Strategy.h"

namespace ai
{
    // Loaded while group is in WC (map 43). Registers boss start triggers.
    class WailingCavernsDungeonStrategy : public Strategy
    {
    public:
        WailingCavernsDungeonStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "wailing caverns"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Kresh — no dangerous mechanic
    class KreshFightStrategy : public Strategy
    {
    public:
        KreshFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "kresh"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Lady Anacondra — Sleep AoE (not positional)
    class AnacondraFightStrategy : public Strategy
    {
    public:
        AnacondraFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "anacondra"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Lord Cobrahn — no positional mechanic
    class CobrahnFightStrategy : public Strategy
    {
    public:
        CobrahnFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "cobrahn"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Lord Pythas — no positional mechanic
    class PythasFightStrategy : public Strategy
    {
    public:
        PythasFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "pythas"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Lord Serpentis — no positional mechanic
    class SerpenatisFightStrategy : public Strategy
    {
    public:
        SerpenatisFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "serpentis"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Verdan the Everliving — Grasping Vines roots ~8yd
    class VerdanFightStrategy : public Strategy
    {
    public:
        VerdanFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "verdan"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Mutanus the Devourer — Thundercrack + Terrify AoE ~10yd
    class MutanusFightStrategy : public Strategy
    {
    public:
        MutanusFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "mutanus"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };
}
