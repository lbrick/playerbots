#pragma once
#include "playerbot/strategy/actions/DungeonActions.h"

namespace ai
{
    // ── Instance strategy enable/disable ────────────────────────────────────────
    class ScholomanceEnableStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        ScholomanceEnableStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable scholomance strategy", "+scholomance") {}
    };

    class ScholomanceDisableStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        ScholomanceDisableStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable scholomance strategy", "-scholomance") {}
    };

    // ── Kirtonos the Herald ───────────────────────────────────────────────────────
    class KirtonostheHeraldEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        KirtonostheHeraldEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable kirtonos the herald fight strategy", "+kirtonos the herald") {}
    };

    class KirtonostheHeraldDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        KirtonostheHeraldDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable kirtonos the herald fight strategy", "-kirtonos the herald") {}
    };

    // Blood Offering ~8yd AoE shadow — stay >10yd
    class KirtonosMoveAwayFromBloodOfferingAction : public MoveAwayFromCreature
    {
    public:
        KirtonosMoveAwayFromBloodOfferingAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "kirtonos move away from blood offering", 10506, 10.0f) {}
    };

    // ── Jandice Barov ─────────────────────────────────────────────────────────────
    class JandiceBarovEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        JandiceBarovEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable jandice barov fight strategy", "+jandice barov") {}
    };

    class JandiceBarovDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        JandiceBarovDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable jandice barov fight strategy", "-jandice barov") {}
    };

    // ── Rattlegore ────────────────────────────────────────────────────────────────
    class RattlegoreEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        RattlegoreEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable rattlegore fight strategy", "+rattlegore") {}
    };

    class RattlegoreDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        RattlegoreDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable rattlegore fight strategy", "-rattlegore") {}
    };

    // ── Marduk Blackpool ──────────────────────────────────────────────────────────
    class MardukBlackpoolEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        MardukBlackpoolEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable marduk blackpool fight strategy", "+marduk blackpool") {}
    };

    class MardukBlackpoolDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        MardukBlackpoolDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable marduk blackpool fight strategy", "-marduk blackpool") {}
    };

    // ── Vectus ────────────────────────────────────────────────────────────────────
    class VectusEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        VectusEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable vectus fight strategy", "+vectus") {}
    };

    class VectusDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        VectusDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable vectus fight strategy", "-vectus") {}
    };

    // Blizzard ~10yd AoE frost — stay >12yd
    class VectusMoveAwayFromBlizzardAction : public MoveAwayFromCreature
    {
    public:
        VectusMoveAwayFromBlizzardAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "vectus move away from blizzard", 10432, 12.0f) {}
    };

    // ── Ras Frostwhisper ──────────────────────────────────────────────────────────
    class RasFrostwhisperEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        RasFrostwhisperEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable ras frostwhisper fight strategy", "+ras frostwhisper") {}
    };

    class RasFrostwhisperDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        RasFrostwhisperDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable ras frostwhisper fight strategy", "-ras frostwhisper") {}
    };

    // Frost Nova ~8yd AoE freeze — stay >10yd
    class RasMoveAwayFromFrostNovaAction : public MoveAwayFromCreature
    {
    public:
        RasMoveAwayFromFrostNovaAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "ras move away from frost nova", 10508, 10.0f) {}
    };

    // ── Instructor Malicia ────────────────────────────────────────────────────────
    class InstructorMaliciaEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        InstructorMaliciaEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable instructor malicia fight strategy", "+instructor malicia") {}
    };

    class InstructorMaliciaDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        InstructorMaliciaDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable instructor malicia fight strategy", "-instructor malicia") {}
    };

    // Poison Nova ~10yd AoE poison — stay >12yd
    class MaliciaMoveAwayFromPoisonNovaAction : public MoveAwayFromCreature
    {
    public:
        MaliciaMoveAwayFromPoisonNovaAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "malicia move away from poison nova", 10505, 12.0f) {}
    };

    // ── Doctor Theolen Krastinov ──────────────────────────────────────────────────
    class DoctorTheolenKrastinovEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        DoctorTheolenKrastinovEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable doctor theolen krastinov fight strategy", "+doctor theolen krastinov") {}
    };

    class DoctorTheolenKrastinovDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        DoctorTheolenKrastinovDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable doctor theolen krastinov fight strategy", "-doctor theolen krastinov") {}
    };

    // ── The Ravenian ──────────────────────────────────────────────────────────────
    class TheRavenianEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        TheRavenianEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable the ravenian fight strategy", "+the ravenian") {}
    };

    class TheRavenianDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        TheRavenianDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable the ravenian fight strategy", "-the ravenian") {}
    };

    // Trample ~8yd AoE physical — stay >10yd
    class RavenianMoveAwayFromTrampleAction : public MoveAwayFromCreature
    {
    public:
        RavenianMoveAwayFromTrampleAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "the ravenian move away from trample", 11439, 10.0f) {}
    };

    // ── Lord Alexei Barov ─────────────────────────────────────────────────────────
    class LordAlexeiBarovEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        LordAlexeiBarovEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable lord alexei barov fight strategy", "+lord alexei barov") {}
    };

    class LordAlexeiBarovDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        LordAlexeiBarovDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable lord alexei barov fight strategy", "-lord alexei barov") {}
    };

    // ── Lady Illucia Barov ────────────────────────────────────────────────────────
    class LadyIlluciaBarovEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        LadyIlluciaBarovEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable lady illucia barov fight strategy", "+lady illucia barov") {}
    };

    class LadyIlluciaBarovDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        LadyIlluciaBarovDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable lady illucia barov fight strategy", "-lady illucia barov") {}
    };

    // ── Darkmaster Gandling ───────────────────────────────────────────────────────
    class DarkmasterGandlingEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        DarkmasterGandlingEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable darkmaster gandling fight strategy", "+darkmaster gandling") {}
    };

    class DarkmasterGandlingDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        DarkmasterGandlingDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable darkmaster gandling fight strategy", "-darkmaster gandling") {}
    };

    // Curse of Dissolution ~8yd AoE on expiry — stay >10yd
    class GandlingMoveAwayFromCurseAoeAction : public MoveAwayFromCreature
    {
    public:
        GandlingMoveAwayFromCurseAoeAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "gandling move away from curse aoe", 1853, 10.0f) {}
    };
}
