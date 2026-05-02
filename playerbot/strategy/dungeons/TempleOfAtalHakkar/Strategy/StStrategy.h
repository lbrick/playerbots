#pragma once
#include "playerbot/strategy/Strategy.h"

namespace ai
{
    // Loaded while group is in Temple of Atal'Hakkar (map 109). Registers boss start triggers.
    class TempleOfAtalHakkarDungeonStrategy : public Strategy
    {
    public:
        TempleOfAtalHakkarDungeonStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "temple of atal'hakkar"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Zolo (5707) — no positional mechanic
    class ZoloFightStrategy : public Strategy
    {
    public:
        ZoloFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "zolo"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Hukku (5708) — no positional mechanic
    class HukkuFightStrategy : public Strategy
    {
    public:
        HukkuFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "hukku"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Gasher (5714) — no positional mechanic
    class GasherFightStrategy : public Strategy
    {
    public:
        GasherFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "gasher"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Loro (5715) — no positional mechanic
    class LoroFightStrategy : public Strategy
    {
    public:
        LoroFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "loro"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Mijan (5709) — no positional mechanic
    class MijanFightStrategy : public Strategy
    {
    public:
        MijanFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "mijan"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Zul'Lor (5710) — no positional mechanic
    class ZulLorFightStrategy : public Strategy
    {
    public:
        ZulLorFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "zul'lor"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Jammal'an the Prophet (5710) — no positional mechanic
    class JammalanTheProphetFightStrategy : public Strategy
    {
    public:
        JammalanTheProphetFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "jammal'an the prophet"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Ogom the Wretched (5711) — no positional mechanic
    class OgomTheWretchedFightStrategy : public Strategy
    {
    public:
        OgomTheWretchedFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "ogom the wretched"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Morphaz (5712) — frontal mechanics deferred
    class MorphazFightStrategy : public Strategy
    {
    public:
        MorphazFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "morphaz"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Hazzas (5713) — frontal mechanics deferred
    class HazzasFightStrategy : public Strategy
    {
    public:
        HazzasFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "hazzas"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Shade of Eranikus (5709) — War Stomp ~8yd AoE
    class ShadeOfEranikusFightStrategy : public Strategy
    {
    public:
        ShadeOfEranikusFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "shade of eranikus"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Avatar of Hakkar (8313) — quest-gated
    class AvatarOfHakkarFightStrategy : public Strategy
    {
    public:
        AvatarOfHakkarFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "avatar of hakkar"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };
}
