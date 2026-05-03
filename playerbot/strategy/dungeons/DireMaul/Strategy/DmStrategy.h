#pragma once
#include "playerbot/strategy/Strategy.h"

namespace ai
{
    // Loaded while group is in Dire Maul (map 429). Covers East, West, and North.
    class DireMaulDungeonStrategy : public Strategy
    {
    public:
        DireMaulDungeonStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "dire maul"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // ── East Bosses ──────────────────────────────────────────────────────────────

    // Zevrim Thornhoof (11490) — no positional AoE
    class ZevrimThornhoofFightStrategy : public Strategy
    {
    public:
        ZevrimThornhoofFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "zevrim thornhoof"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Hydrospawn (13280) — no positional AoE
    class HydrospawnFightStrategy : public Strategy
    {
    public:
        HydrospawnFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "hydrospawn"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Lethtendris (14327) — no positional AoE
    class LehtendrisFightStrategy : public Strategy
    {
    public:
        LehtendrisFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "lethtendris"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Alzzin the Wildshaper (11492) — Earthgrip ~10yd AoE root
    class AlzzinTheWildshaperFightStrategy : public Strategy
    {
    public:
        AlzzinTheWildshaperFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "alzzin the wildshaper"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // ── West Bosses ──────────────────────────────────────────────────────────────

    // Tendris Warpwood (11489) — Entangle ~8yd AoE root
    class TendrisWarpwoodFightStrategy : public Strategy
    {
    public:
        TendrisWarpwoodFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "tendris warpwood"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Illyanna Ravenoak (11488) — frontal deferred; no positional trigger
    class IllyannaRavenoakFightStrategy : public Strategy
    {
    public:
        IllyannaRavenoakFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "illyanna ravenoak"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Magister Kalendris (11487) — no positional AoE
    class MagisterKalendrisFightStrategy : public Strategy
    {
    public:
        MagisterKalendrisFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "magister kalendris"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Immol'thar (11496) — Disease Cloud ~10yd persistent AoE
    class ImmoltharFightStrategy : public Strategy
    {
    public:
        ImmoltharFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "immol'thar"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Prince Tortheldrin (11486) — Arcane Blast ~8yd AoE
    class PrinceTortheldrinFightStrategy : public Strategy
    {
    public:
        PrinceTortheldrinFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "prince tortheldrin"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // ── North Bosses ─────────────────────────────────────────────────────────────

    // Guard Mol'dar (14326) — War Stomp ~8yd AoE
    class GuardMoldarFightStrategy : public Strategy
    {
    public:
        GuardMoldarFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "guard mol'dar"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Stomper Kreeg (14322) — Knock Away ~8yd AoE knockback
    class StomperKreegFightStrategy : public Strategy
    {
    public:
        StomperKreegFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "stomper kreeg"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Guard Fengus (14321) — no radial AoE
    class GuardFengusFightStrategy : public Strategy
    {
    public:
        GuardFengusFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "guard fengus"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Guard Slip'kik (14323) — Frost Nova ~8yd AoE freeze
    class GuardSlipkikFightStrategy : public Strategy
    {
    public:
        GuardSlipkikFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "guard slip'kik"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Captain Kromcrush (14325) — War Stomp ~8yd AoE
    class CaptainKromcrushFightStrategy : public Strategy
    {
    public:
        CaptainKromcrushFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "captain kromcrush"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // King Gordok (11501) — Thunderclap ~8yd AoE physical
    class KingGordokFightStrategy : public Strategy
    {
    public:
        KingGordokFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "king gordok"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };
}
