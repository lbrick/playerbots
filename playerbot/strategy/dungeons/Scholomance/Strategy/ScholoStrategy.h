#pragma once
#include "playerbot/strategy/Strategy.h"

namespace ai
{
    // Loaded while group is in Scholomance (map 289).
    class ScholomanceDungeonStrategy : public Strategy
    {
    public:
        ScholomanceDungeonStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "scholomance"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Kirtonos the Herald (10506) — Blood Offering ~8yd AoE shadow
    class KirtonostheHeraldFightStrategy : public Strategy
    {
    public:
        KirtonostheHeraldFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "kirtonos the herald"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Jandice Barov (10503) — no positional AoE
    class JandiceBarovFightStrategy : public Strategy
    {
    public:
        JandiceBarovFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "jandice barov"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Rattlegore (11622) — no radial AoE
    class RattlegoreFightStrategy : public Strategy
    {
    public:
        RattlegoreFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "rattlegore"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Marduk Blackpool (10433) — no positional trigger
    class MardukBlackpoolFightStrategy : public Strategy
    {
    public:
        MardukBlackpoolFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "marduk blackpool"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Vectus (10432) — Blizzard ~10yd AoE frost
    class VectusFightStrategy : public Strategy
    {
    public:
        VectusFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "vectus"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Ras Frostwhisper (10508) — Frost Nova ~8yd AoE freeze
    class RasFrostwhisperFightStrategy : public Strategy
    {
    public:
        RasFrostwhisperFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "ras frostwhisper"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Instructor Malicia (10505) — Poison Nova ~10yd AoE poison
    class InstructorMaliciaFightStrategy : public Strategy
    {
    public:
        InstructorMaliciaFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "instructor malicia"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Doctor Theolen Krastinov (11261) — no radial AoE
    class DoctorTheolenKrastinovFightStrategy : public Strategy
    {
    public:
        DoctorTheolenKrastinovFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "doctor theolen krastinov"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // The Ravenian (11439) — Trample ~8yd AoE physical
    class TheRavenianFightStrategy : public Strategy
    {
    public:
        TheRavenianFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "the ravenian"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Lord Alexei Barov (10504) — no positional AoE
    class LordAlexeiBarovFightStrategy : public Strategy
    {
    public:
        LordAlexeiBarovFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "lord alexei barov"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Lady Illucia Barov (10502) — no positional AoE
    class LadyIlluciaBarovFightStrategy : public Strategy
    {
    public:
        LadyIlluciaBarovFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "lady illucia barov"; }

    private:
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Darkmaster Gandling (1853) — Curse of Dissolution ~8yd AoE on expiry
    class DarkmasterGandlingFightStrategy : public Strategy
    {
    public:
        DarkmasterGandlingFightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "darkmaster gandling"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
    };
}
