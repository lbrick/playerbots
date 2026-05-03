#pragma once
#include "playerbot/strategy/Strategy.h"

namespace ai
{
    // Loaded while group is in Maraudon (map 349). Registers boss start triggers.
    class MaraudonDungeonStrategy : public Strategy
    {
    public:
        MaraudonDungeonStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "maraudon"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Noxxion (13282) — Noxious Fumes ~8yd AoE
    class NoxxionFightStrategy : public Strategy
    {
    public:
        NoxxionFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "noxxion"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Razorlash (12258) — no positional mechanic
    class RazorlashFightStrategy : public Strategy
    {
    public:
        RazorlashFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "razorlash"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Lord Vyletongue (13280) — no positional mechanic
    class LordVyletongeFightStrategy : public Strategy
    {
    public:
        LordVyletongeFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "lord vyletongue"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Celebras the Cursed (12519) — no positional mechanic
    class CelebrasTheCursedFightStrategy : public Strategy
    {
    public:
        CelebrasTheCursedFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "celebras the cursed"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Landslide (12565) — no positional mechanic
    class LandslideFightStrategy : public Strategy
    {
    public:
        LandslideFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "landslide"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Tinkerer Gizlock (13601) — Smoke Bomb ~8yd AoE
    class TinkererGizlockFightStrategy : public Strategy
    {
    public:
        TinkererGizlockFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "tinkerer gizlock"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Rotgrip (13596) — no positional mechanic
    class RotgripFightStrategy : public Strategy
    {
    public:
        RotgripFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "rotgrip"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Princess Theradras (12201) — Dust Field ~10yd AoE
    class PrincessTheadrasFightStrategy : public Strategy
    {
    public:
        PrincessTheadrasFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "princess theradras"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };
}
