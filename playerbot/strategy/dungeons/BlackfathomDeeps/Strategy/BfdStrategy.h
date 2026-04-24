#pragma once
#include "playerbot/strategy/Strategy.h"

namespace ai
{
    // Loaded while group is in Blackfathom Deeps (map 48). Registers boss start triggers.
    class BlackfathomDeepsDungeonStrategy : public Strategy
    {
    public:
        BlackfathomDeepsDungeonStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "blackfathom deeps"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Ghamoo-ra (4887) — Trample ~5yd melee AoE
    class GhamooRaFightStrategy : public Strategy
    {
    public:
        GhamooRaFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "ghamoo-ra"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Lady Sarevess (4831) — pulls with two naga adds
    class LadySarevessFightStrategy : public Strategy
    {
    public:
        LadySarevessFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "lady sarevess"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Gelihast (6243) — simple boss, dangerous murloc room
    class GelihastFightStrategy : public Strategy
    {
    public:
        GelihastFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "gelihast"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Lorgus Jett (12902) — shaman caster, interrupt candidate pending spell verify
    class LorgusJettFightStrategy : public Strategy
    {
    public:
        LorgusJettFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "lorgus jett"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Baron Aquanis (12876) — event-spawn elemental boss
    class BaronAquanisFightStrategy : public Strategy
    {
    public:
        BaronAquanisFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "baron aquanis"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Twilight Lord Kelris (4832) — Sleep on healer, interrupt pending spell verify
    class KelrisFightStrategy : public Strategy
    {
    public:
        KelrisFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "kelris"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Aku'mai (4829) — Poison Cloud ~8yd + Frenzied Rage tank pressure
    class AkuMaiFightStrategy : public Strategy
    {
    public:
        AkuMaiFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "aku'mai"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };
}
