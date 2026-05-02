#pragma once
#include "playerbot/strategy/Strategy.h"

namespace ai
{
    // Loaded while group is in Zul'Farrak (map 209). Registers boss start triggers.
    class ZulFarrakDungeonStrategy : public Strategy
    {
    public:
        ZulFarrakDungeonStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "zul'farrak"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Theka the Martyr (7272) — no positional mechanic
    class ThekaTheMartyrFightStrategy : public Strategy
    {
    public:
        ThekaTheMartyrFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "theka the martyr"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Witch Doctor Zum'rah (7271) — no positional mechanic
    class WitchDoctorZumrahFightStrategy : public Strategy
    {
    public:
        WitchDoctorZumrahFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "witch doctor zum'rah"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Antu'sul (8127) — no positional mechanic
    class AntusulFightStrategy : public Strategy
    {
    public:
        AntusulFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "antu'sul"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Shadowpriest Sezz'ziz (7275) — no positional mechanic
    class ShadowpriestSezzizFightStrategy : public Strategy
    {
    public:
        ShadowpriestSezzizFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "shadowpriest sezz'ziz"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Sergeant Bly (7604) — staircase event, no positional mechanic
    class SergeantBlyFightStrategy : public Strategy
    {
    public:
        SergeantBlyFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "sergeant bly"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Gahz'rilla (7273) — Freeze ~10yd AoE
    class GahzrillaFightStrategy : public Strategy
    {
    public:
        GahzrillaFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "gahz'rilla"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Chief Ukorz Sandscalp (7267) — no positional mechanic
    class ChiefUkorzSandscalpFightStrategy : public Strategy
    {
    public:
        ChiefUkorzSandscalpFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "chief ukorz sandscalp"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };
}
