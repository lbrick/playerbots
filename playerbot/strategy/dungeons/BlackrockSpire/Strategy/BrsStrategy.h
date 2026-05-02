#pragma once
#include "playerbot/strategy/Strategy.h"

namespace ai
{
    // Loaded while group is in Blackrock Spire (map 229). Covers both LBRS and UBRS.
    class BlackrockSpireDungeonStrategy : public Strategy
    {
    public:
        BlackrockSpireDungeonStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "blackrock spire"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // ── LBRS Bosses ─────────────────────────────────────────────────────────────

    // Highlord Omokk (9196) — War Stomp ~8yd AoE
    class HigdlordOmokkFightStrategy : public Strategy
    {
    public:
        HigdlordOmokkFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "highlord omokk"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Shadow Hunter Vosh'gajin (9236) — no positional AoE
    class ShadowHunterVoshgajinFightStrategy : public Strategy
    {
    public:
        ShadowHunterVoshgajinFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "shadow hunter vosh'gajin"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // War Master Voone (9237) — no positional AoE
    class WarMasterVooneFightStrategy : public Strategy
    {
    public:
        WarMasterVooneFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "war master voone"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Mother Smolderweb (10596) — no positional AoE
    class MotherSmolderwebFightStrategy : public Strategy
    {
    public:
        MotherSmolderwebFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "mother smolderweb"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Urok Doomhowl (10584) — War Stomp ~8yd AoE; optional event boss
    class UrokDoomhowlFightStrategy : public Strategy
    {
    public:
        UrokDoomhowlFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "urok doomhowl"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Quartermaster Zigris (9736) — no positional AoE
    class QuartermasterZigisFightStrategy : public Strategy
    {
    public:
        QuartermasterZigisFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "quartermaster zigris"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Halycon (10220) — AoE fear handled by break strategy; no movement trigger
    class HalyconFightStrategy : public Strategy
    {
    public:
        HalyconFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "halycon"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Overlord Wyrmthalak (9568) — War Stomp ~8yd + Blizzard ~10yd AoE
    class OverlordWyrmthalakFightStrategy : public Strategy
    {
    public:
        OverlordWyrmthalakFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "overlord wyrmthalak"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // ── UBRS Bosses ─────────────────────────────────────────────────────────────

    // Pyroguard Emberseer (9816) — Ignite ~8yd fire aura after freed
    class PyroguardEmberseerFightStrategy : public Strategy
    {
    public:
        PyroguardEmberseerFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "pyroguard emberseer"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Solakar Flamewreath (10264) — no radial AoE
    class SolakarFlamewreathFightStrategy : public Strategy
    {
    public:
        SolakarFlamewreathFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "solakar flamewreath"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Jed Runewatcher (10509) — rare spawn; no positional AoE
    class JedRunewatcherFightStrategy : public Strategy
    {
    public:
        JedRunewatcherFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "jed runewatcher"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // The Beast (10430) — Conflagration ~10yd AoE splash
    class TheBeastFightStrategy : public Strategy
    {
    public:
        TheBeastFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "the beast"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // General Drakkisath (10363) — Conflagration ~8yd AoE cone
    class GeneralDrakkisathFightStrategy : public Strategy
    {
    public:
        GeneralDrakkisathFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "general drakkisath"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };
}
