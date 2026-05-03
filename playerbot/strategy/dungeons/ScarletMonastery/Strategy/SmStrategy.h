#pragma once
#include "playerbot/strategy/Strategy.h"

namespace ai
{
    // Loaded while group is in Scarlet Monastery (map 189 — all wings). Registers boss start triggers.
    class ScarletMonasteryDungeonStrategy : public Strategy
    {
    public:
        ScarletMonasteryDungeonStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "scarlet monastery"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // ── Graveyard Wing ───────────────────────────────────────────────────────────

    // Interrogator Vishas (3983) — no positional mechanic
    class VishasFightStrategy : public Strategy
    {
    public:
        VishasFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "vishas"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Fallen Champion (6488) — no positional mechanic
    class FallenChampionFightStrategy : public Strategy
    {
    public:
        FallenChampionFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "fallen champion"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Ironspine (6489) — no positional mechanic
    class IronspineFightStrategy : public Strategy
    {
    public:
        IronspineFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "ironspine"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Bloodmage Thalnos (4543) — Shadowbolt Volley wide AoE
    class ThalnsosFightStrategy : public Strategy
    {
    public:
        ThalnsosFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "thalnos"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // ── Library Wing ─────────────────────────────────────────────────────────────

    // Houndmaster Loksey (3974) — no positional mechanic in v1
    class LokseyFightStrategy : public Strategy
    {
    public:
        LokseyFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "loksey"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Arcanist Doan (6487) — Arcane Explosion ~30yd when low HP
    class DoanFightStrategy : public Strategy
    {
    public:
        DoanFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "doan"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // ── Armory Wing ──────────────────────────────────────────────────────────────

    // Herod (3975) — Whirlwind melee AoE ~8yd
    class HerodFightStrategy : public Strategy
    {
    public:
        HerodFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "herod"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // ── Cathedral Wing ───────────────────────────────────────────────────────────

    // Scarlet Commander Mograine (3976) — no positional mechanic in v1
    class MograineFightStrategy : public Strategy
    {
    public:
        MograineFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "mograine"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // High Inquisitor Whitemane (3977) — no positional mechanic in v1
    class WhitemaneFightStrategy : public Strategy
    {
    public:
        WhitemaneFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "whitemane"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // High Inquisitor Fairbanks (4542) — no positional mechanic
    class FairbanksFightStrategy : public Strategy
    {
    public:
        FairbanksFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "fairbanks"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };
}
