#pragma once
#include "playerbot/strategy/Strategy.h"

namespace ai
{
    // Loaded while group is in Gnomeregan (map 90). Registers boss start triggers.
    class GnomereganDungeonStrategy : public Strategy
    {
    public:
        GnomereganDungeonStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "gnomeregan"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Grubbis (7361) — simple melee, no positional mechanic
    class GrubbisFightStrategy : public Strategy
    {
    public:
        GrubbisFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "grubbis"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Viscous Fallout (7079) — Acid Splash puddle + Corrosive Aura
    class ViscousFalloutFightStrategy : public Strategy
    {
    public:
        ViscousFalloutFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "viscous fallout"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Electrocutioner 6000 (6235) — Lightning Arc chain + Megavolt stun
    class ElectrocutionerFightStrategy : public Strategy
    {
    public:
        ElectrocutionerFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "electrocutioner"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Crowd Pummeler 9-60 (6229) — Arcing Smash frontal + Trample
    class CrowdPummelerFightStrategy : public Strategy
    {
    public:
        CrowdPummelerFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "crowd pummeler"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Mekgineer Thermaplugg (7800) — Leper Gnome bomb spread
    class ThermapluggFightStrategy : public Strategy
    {
    public:
        ThermapluggFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "thermaplugg"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };
}
