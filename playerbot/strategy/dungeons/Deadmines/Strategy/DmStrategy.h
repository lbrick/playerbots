#pragma once
#include "playerbot/strategy/Strategy.h"

namespace ai
{
    // Loaded while group is in The Deadmines (map 36). Registers boss start triggers.
    class DeadminesDungeonStrategy : public Strategy
    {
    public:
        DeadminesDungeonStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "deadmines"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Rhahk'Zor (644) — Slam knockback
    class RhahkzorFightStrategy : public Strategy
    {
    public:
        RhahkzorFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "rhahkzor"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Sneed's Shredder (642) — Saw Blade AoE
    class SneedShredderFightStrategy : public Strategy
    {
    public:
        SneedShredderFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "sneed shredder"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Sneed (643) — spawns on Shredder death, simple melee
    class SneedFightStrategy : public Strategy
    {
    public:
        SneedFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "sneed"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Gilnid (1763) — Molten Metal puddle
    class GilnidFightStrategy : public Strategy
    {
    public:
        GilnidFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "gilnid"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Mr. Smite (646) — stun + weapon switch, Mighty Blow knockback at hammer phase
    class SmiteFightStrategy : public Strategy
    {
    public:
        SmiteFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "smite"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Cookie (645) — Throw Food debuffs, no positional mechanic
    class CookieFightStrategy : public Strategy
    {
    public:
        CookieFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "cookie"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Edwin VanCleef (639) — adds spawn at 50%
    class VanCleefFightStrategy : public Strategy
    {
    public:
        VanCleefFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "vancleef"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };
}
