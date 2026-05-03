#pragma once
#include "playerbot/strategy/triggers/DungeonTriggers.h"

namespace ai
{
    // ── Instance enter/leave (Map ID 289) ───────────────────────────────────────
    class ScholomanceEnterDungeonTrigger : public EnterDungeonTrigger
    {
    public:
        ScholomanceEnterDungeonTrigger(PlayerbotAI* ai)
            : EnterDungeonTrigger(ai, "enter scholomance", "scholomance", 289) {}
    };

    class ScholomanceLeaveDungeonTrigger : public LeaveDungeonTrigger
    {
    public:
        ScholomanceLeaveDungeonTrigger(PlayerbotAI* ai)
            : LeaveDungeonTrigger(ai, "leave scholomance", "scholomance", 289) {}
    };

    // ── Kirtonos the Herald (10506) — Blood Offering ~8yd AoE shadow ────────────
    class KirtonostheHeraldStartFightTrigger : public StartBossFightTrigger
    {
    public:
        KirtonostheHeraldStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start kirtonos the herald fight", "kirtonos the herald", 10506) {}
    };

    class KirtonostheHeraldEndFightTrigger : public EndBossFightTrigger
    {
    public:
        KirtonostheHeraldEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end kirtonos the herald fight", "kirtonos the herald", 10506) {}
    };

    class KirtonosBloodOfferingTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        KirtonosBloodOfferingTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "kirtonos blood offering", 10506, 8.0f, 3) {}
    };

    // ── Jandice Barov (10503) — no positional AoE ───────────────────────────────
    class JandiceBarovStartFightTrigger : public StartBossFightTrigger
    {
    public:
        JandiceBarovStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start jandice barov fight", "jandice barov", 10503) {}
    };

    class JandiceBarovEndFightTrigger : public EndBossFightTrigger
    {
    public:
        JandiceBarovEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end jandice barov fight", "jandice barov", 10503) {}
    };

    // ── Rattlegore (11622) — no radial AoE ──────────────────────────────────────
    class RattlegoreStartFightTrigger : public StartBossFightTrigger
    {
    public:
        RattlegoreStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start rattlegore fight", "rattlegore", 11622) {}
    };

    class RattlegoreEndFightTrigger : public EndBossFightTrigger
    {
    public:
        RattlegoreEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end rattlegore fight", "rattlegore", 11622) {}
    };

    // ── Marduk Blackpool (10433) — no positional trigger ────────────────────────
    class MardukBlackpoolStartFightTrigger : public StartBossFightTrigger
    {
    public:
        MardukBlackpoolStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start marduk blackpool fight", "marduk blackpool", 10433) {}
    };

    class MardukBlackpoolEndFightTrigger : public EndBossFightTrigger
    {
    public:
        MardukBlackpoolEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end marduk blackpool fight", "marduk blackpool", 10433) {}
    };

    // ── Vectus (10432) — Blizzard ~10yd AoE frost ───────────────────────────────
    class VectusStartFightTrigger : public StartBossFightTrigger
    {
    public:
        VectusStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start vectus fight", "vectus", 10432) {}
    };

    class VectusEndFightTrigger : public EndBossFightTrigger
    {
    public:
        VectusEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end vectus fight", "vectus", 10432) {}
    };

    class VectusBlizzardTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        VectusBlizzardTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "vectus blizzard", 10432, 10.0f, 4) {}
    };

    // ── Ras Frostwhisper (10508) — Frost Nova ~8yd AoE freeze ───────────────────
    class RasFrostwhisperStartFightTrigger : public StartBossFightTrigger
    {
    public:
        RasFrostwhisperStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start ras frostwhisper fight", "ras frostwhisper", 10508) {}
    };

    class RasFrostwhisperEndFightTrigger : public EndBossFightTrigger
    {
    public:
        RasFrostwhisperEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end ras frostwhisper fight", "ras frostwhisper", 10508) {}
    };

    class RasFrostNovaTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        RasFrostNovaTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "ras frost nova", 10508, 8.0f, 3) {}
    };

    // ── Instructor Malicia (10505) — Poison Nova ~10yd AoE poison ───────────────
    class InstructorMaliciaStartFightTrigger : public StartBossFightTrigger
    {
    public:
        InstructorMaliciaStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start instructor malicia fight", "instructor malicia", 10505) {}
    };

    class InstructorMaliciaEndFightTrigger : public EndBossFightTrigger
    {
    public:
        InstructorMaliciaEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end instructor malicia fight", "instructor malicia", 10505) {}
    };

    class MaliciaPoisonNovaTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        MaliciaPoisonNovaTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "malicia poison nova", 10505, 10.0f, 3) {}
    };

    // ── Doctor Theolen Krastinov (11261) — no radial AoE ────────────────────────
    class DoctorTheolenKrastinovStartFightTrigger : public StartBossFightTrigger
    {
    public:
        DoctorTheolenKrastinovStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start doctor theolen krastinov fight", "doctor theolen krastinov", 11261) {}
    };

    class DoctorTheolenKrastinovEndFightTrigger : public EndBossFightTrigger
    {
    public:
        DoctorTheolenKrastinovEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end doctor theolen krastinov fight", "doctor theolen krastinov", 11261) {}
    };

    // ── The Ravenian (11439) — Trample ~8yd AoE physical ────────────────────────
    class TheRavenianStartFightTrigger : public StartBossFightTrigger
    {
    public:
        TheRavenianStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start the ravenian fight", "the ravenian", 11439) {}
    };

    class TheRavenianEndFightTrigger : public EndBossFightTrigger
    {
    public:
        TheRavenianEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end the ravenian fight", "the ravenian", 11439) {}
    };

    class RavenianTrampleTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        RavenianTrampleTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "the ravenian trample", 11439, 8.0f, 3) {}
    };

    // ── Lord Alexei Barov (10504) — no positional AoE ───────────────────────────
    class LordAlexeiBarovStartFightTrigger : public StartBossFightTrigger
    {
    public:
        LordAlexeiBarovStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start lord alexei barov fight", "lord alexei barov", 10504) {}
    };

    class LordAlexeiBarovEndFightTrigger : public EndBossFightTrigger
    {
    public:
        LordAlexeiBarovEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end lord alexei barov fight", "lord alexei barov", 10504) {}
    };

    // ── Lady Illucia Barov (10502) — no positional AoE ──────────────────────────
    class LadyIlluciaBarovStartFightTrigger : public StartBossFightTrigger
    {
    public:
        LadyIlluciaBarovStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start lady illucia barov fight", "lady illucia barov", 10502) {}
    };

    class LadyIlluciaBarovEndFightTrigger : public EndBossFightTrigger
    {
    public:
        LadyIlluciaBarovEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end lady illucia barov fight", "lady illucia barov", 10502) {}
    };

    // ── Darkmaster Gandling (1853) — Curse of Dissolution ~8yd AoE ──────────────
    class DarkmasterGandlingStartFightTrigger : public StartBossFightTrigger
    {
    public:
        DarkmasterGandlingStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start darkmaster gandling fight", "darkmaster gandling", 1853) {}
    };

    class DarkmasterGandlingEndFightTrigger : public EndBossFightTrigger
    {
    public:
        DarkmasterGandlingEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end darkmaster gandling fight", "darkmaster gandling", 1853) {}
    };

    class GandlingCurseAoeTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        GandlingCurseAoeTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "gandling curse aoe", 1853, 8.0f, 3) {}
    };

    // ── Ras Frostwhisper interrupt — Freeze (ID 18763, DB-verified) ─────────────
    class RasFreezeSpellCastingTrigger : public TargetCastingSpellTrigger
    {
    public:
        RasFreezeSpellCastingTrigger(PlayerbotAI* ai)
            : TargetCastingSpellTrigger(ai, "target casting ras freeze", 18763) {}
    };

    // ── Vectus interrupt — Flamestrike (ID 18399, DB-verified) ──────────────────
    class VectusFlamestrikeSpellCastingTrigger : public TargetCastingSpellTrigger
    {
    public:
        VectusFlamestrikeSpellCastingTrigger(PlayerbotAI* ai)
            : TargetCastingSpellTrigger(ai, "target casting vectus flamestrike", 18399) {}
    };
}
