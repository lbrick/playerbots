#pragma once
#include "playerbot/strategy/Strategy.h"

namespace ai
{
    // Loaded while group is in Stratholme (map 329). Covers Scarlet and Undead sides.
    class StratholmeDungeonStrategy : public Strategy
    {
    public:
        StratholmeDungeonStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "stratholme"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // ── Scarlet Side Bosses ──────────────────────────────────────────────────────

    // Hearthsinger Forresten (16779) — rare; no positional AoE
    class HearthsingerForrestenFightStrategy : public Strategy
    {
    public:
        HearthsingerForrestenFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "hearthsinger forresten"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Timmy the Cruel (10808) — rare; no radial AoE
    class TimmytheCruelFightStrategy : public Strategy
    {
    public:
        TimmytheCruelFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "timmy the cruel"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Cannon Master Willey (10811) — cannon GO deferred; start/end only
    class CannonMasterWilleyFightStrategy : public Strategy
    {
    public:
        CannonMasterWilleyFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "cannon master willey"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Archivist Galford (10812) — Flame Buffet ~8yd AoE fire
    class ArchivistGalfordFightStrategy : public Strategy
    {
    public:
        ArchivistGalfordFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "archivist galford"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Balnazzar (10813) — Thunderclap ~8yd AoE
    class BalnazzarFightStrategy : public Strategy
    {
    public:
        BalnazzarFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "balnazzar"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // ── Undead Side Bosses ───────────────────────────────────────────────────────

    // Magistrate Barthilas (10435) — no radial AoE
    class MagistrateBarthilasFightStrategy : public Strategy
    {
    public:
        MagistrateBarthilasFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "magistrate barthilas"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Maleki the Pallid (10438) — Frost Nova ~8yd AoE freeze
    class MalekithePallidFightStrategy : public Strategy
    {
    public:
        MalekithePallidFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "maleki the pallid"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Ramstein the Gorger (10439) — Trample ~8yd AoE physical
    class RamsteintheGorgerFightStrategy : public Strategy
    {
    public:
        RamsteintheGorgerFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "ramstein the gorger"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Baron Rivendare (10440) — Unholy Aura ~10yd persistent shadow AoE
    class BaronRivendareFightStrategy : public Strategy
    {
    public:
        BaronRivendareFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "baron rivendare"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };
}
