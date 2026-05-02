#pragma once
#include "playerbot/strategy/Strategy.h"

namespace ai
{
    // Loaded while group is in Razorfen Downs (map 129). Registers boss start triggers.
    class RazorfenDownsDungeonStrategy : public Strategy
    {
    public:
        RazorfenDownsDungeonStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "razorfen downs"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Tuten'kash (7355) — no positional mechanic
    class TutenkashFightStrategy : public Strategy
    {
    public:
        TutenkashFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "tuten'kash"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Mordresh Fire Eye (7357) — Fire Nova ~10yd AoE
    class MordreshFireEyeFightStrategy : public Strategy
    {
    public:
        MordreshFireEyeFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "mordresh fire eye"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Glutton (7354) — no positional mechanic
    class GluttonFightStrategy : public Strategy
    {
    public:
        GluttonFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "glutton"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Amnennar the Coldbringer (7358) — Frost Nova ~8yd AoE
    class AmnennarTheColdbringerFightStrategy : public Strategy
    {
    public:
        AmnennarTheColdbringerFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "amnennar the coldbringer"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };
}
