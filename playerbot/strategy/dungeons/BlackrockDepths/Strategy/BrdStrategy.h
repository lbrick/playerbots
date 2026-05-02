#pragma once
#include "playerbot/strategy/Strategy.h"

namespace ai
{
    // Loaded while group is in Blackrock Depths (map 230). Registers boss start triggers.
    class BlackrockDepthsDungeonStrategy : public Strategy
    {
    public:
        BlackrockDepthsDungeonStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "blackrock depths"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // ── Ring of Law Champions ────────────────────────────────────────────────────

    // Gorosh the Dervish (9027) — no positional AoE
    class GoroshFightStrategy : public Strategy
    {
    public:
        GoroshFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "gorosh"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Grizzle (9023) — Ground Tremor ~10yd AoE
    class GrizzleFightStrategy : public Strategy
    {
    public:
        GrizzleFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "grizzle"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Eviscerator (9024) — Whirlwind ~8yd AoE
    class EviscerratorFightStrategy : public Strategy
    {
    public:
        EviscerratorFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "eviscerator"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Ok'thor the Breaker (9026) — War Stomp ~8yd AoE
    class OkthorTheBreakerFightStrategy : public Strategy
    {
    public:
        OkthorTheBreakerFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "ok'thor the breaker"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Anub'shiah (9028) — no positional AoE
    class AnubshiahFightStrategy : public Strategy
    {
    public:
        AnubshiahFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "anub'shiah"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Hedrum the Creeper (9029) — ranged AoE, no movement trigger
    class HedrumTheCreepFightStrategy : public Strategy
    {
    public:
        HedrumTheCreepFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "hedrum the creeper"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // ── Main Dungeon Bosses ──────────────────────────────────────────────────────

    // High Interrogator Gerstahn (9018) — fear handled by break strategy
    class HighInterrogatorGerstanFightStrategy : public Strategy
    {
    public:
        HighInterrogatorGerstanFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "high interrogator gerstahn"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Lord Roccor (9025) — Earthquake ~10yd AoE
    class LordRoccorFightStrategy : public Strategy
    {
    public:
        LordRoccorFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "lord roccor"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Houndmaster Grebmar (9319) — no positional AoE
    class HoundmasterGrebmarFightStrategy : public Strategy
    {
    public:
        HoundmasterGrebmarFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "houndmaster grebmar"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Pyromancer Loregrain (9024) — Fire Nova ~10yd AoE
    class PyromancerLoregrainFightStrategy : public Strategy
    {
    public:
        PyromancerLoregrainFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "pyromancer loregrain"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Warder Stilgiss (9017) — Frost Nova ~8yd AoE
    class WarderStiglissFightStrategy : public Strategy
    {
    public:
        WarderStiglissFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "warder stilgiss"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Verek (9216) — no positional AoE
    class VerekFightStrategy : public Strategy
    {
    public:
        VerekFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "verek"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Plugger Spazzring (9499) — no positional AoE
    class PluggerSpazzringFightStrategy : public Strategy
    {
    public:
        PluggerSpazzringFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "plugger spazzring"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Phalanx (9502) — no positional AoE
    class PhalanxFightStrategy : public Strategy
    {
    public:
        PhalanxFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "phalanx"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Ambassador Flamelash (9156) — no positional AoE
    class AmbassadorFlamelashFightStrategy : public Strategy
    {
    public:
        AmbassadorFlamelashFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "ambassador flamelash"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // The Seven (8903) — no positional AoE
    class TheSevenFightStrategy : public Strategy
    {
    public:
        TheSevenFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "the seven"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Golem Lord Argelmach (8983) — Static Field ~8yd AoE
    class GolemLordArgelmachFightStrategy : public Strategy
    {
    public:
        GolemLordArgelmachFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "golem lord argelmach"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Bael'Gar (9016) — Fire Nova ~10yd AoE
    class BaelGarFightStrategy : public Strategy
    {
    public:
        BaelGarFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "bael'gar"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // General Angerforge (9033) — no radial AoE
    class GeneralAngerforgeFightStrategy : public Strategy
    {
    public:
        GeneralAngerforgeFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "general angerforge"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Magmus (9938) — War Stomp ~8yd AoE
    class MagmusFightStrategy : public Strategy
    {
    public:
        MagmusFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "magmus"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Emperor Dagran Thaurissan (9019) — no movement mechanic
    class EmperorDagranThaurissanFightStrategy : public Strategy
    {
    public:
        EmperorDagranThaurissanFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "emperor dagran thaurissan"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };
}
