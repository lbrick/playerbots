#pragma once
#include "playerbot/strategy/actions/DungeonActions.h"

namespace ai
{
    // ── Instance strategy enable/disable ────────────────────────────────────────
    class DireMaulEnableStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        DireMaulEnableStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable dire maul strategy", "+dire maul") {}
    };

    class DireMaulDisableStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        DireMaulDisableStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable dire maul strategy", "-dire maul") {}
    };

    // ── East: Zevrim Thornhoof ────────────────────────────────────────────────────
    class ZevrimThornhoofEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        ZevrimThornhoofEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable zevrim thornhoof fight strategy", "+zevrim thornhoof") {}
    };

    class ZevrimThornhoofDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        ZevrimThornhoofDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable zevrim thornhoof fight strategy", "-zevrim thornhoof") {}
    };

    // ── East: Hydrospawn ──────────────────────────────────────────────────────────
    class HydrospawnEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        HydrospawnEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable hydrospawn fight strategy", "+hydrospawn") {}
    };

    class HydrospawnDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        HydrospawnDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable hydrospawn fight strategy", "-hydrospawn") {}
    };

    // ── East: Lethtendris ─────────────────────────────────────────────────────────
    class LethtendrisEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        LethtendrisEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable lethtendris fight strategy", "+lethtendris") {}
    };

    class LethtendrisDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        LethtendrisDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable lethtendris fight strategy", "-lethtendris") {}
    };

    // ── East: Alzzin the Wildshaper ───────────────────────────────────────────────
    class AlzzinTheWildshaperEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        AlzzinTheWildshaperEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable alzzin the wildshaper fight strategy", "+alzzin the wildshaper") {}
    };

    class AlzzinTheWildshaperDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        AlzzinTheWildshaperDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable alzzin the wildshaper fight strategy", "-alzzin the wildshaper") {}
    };

    // Earthgrip ~10yd AoE root — stay >12yd
    class AlzzinMoveAwayFromEarthgripAction : public MoveAwayFromCreature
    {
    public:
        AlzzinMoveAwayFromEarthgripAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "alzzin move away from earthgrip", 11492, 12.0f) {}
    };

    // ── West: Tendris Warpwood ────────────────────────────────────────────────────
    class TendrisWarpwoodEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        TendrisWarpwoodEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable tendris warpwood fight strategy", "+tendris warpwood") {}
    };

    class TendrisWarpwoodDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        TendrisWarpwoodDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable tendris warpwood fight strategy", "-tendris warpwood") {}
    };

    // Entangle ~8yd AoE root — stay >10yd
    class TendrismoveAwayFromEntangleAction : public MoveAwayFromCreature
    {
    public:
        TendrismoveAwayFromEntangleAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "tendris move away from entangle", 11489, 10.0f) {}
    };

    // ── West: Illyanna Ravenoak ───────────────────────────────────────────────────
    class IllyannaRavenoakEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        IllyannaRavenoakEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable illyanna ravenoak fight strategy", "+illyanna ravenoak") {}
    };

    class IllyannaRavenoakDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        IllyannaRavenoakDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable illyanna ravenoak fight strategy", "-illyanna ravenoak") {}
    };

    // ── West: Magister Kalendris ──────────────────────────────────────────────────
    class MagisterKalendrisEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        MagisterKalendrisEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable magister kalendris fight strategy", "+magister kalendris") {}
    };

    class MagisterKalendrisDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        MagisterKalendrisDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable magister kalendris fight strategy", "-magister kalendris") {}
    };

    // ── West: Immol'thar ──────────────────────────────────────────────────────────
    class ImmoltharEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        ImmoltharEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable immol'thar fight strategy", "+immol'thar") {}
    };

    class ImmoltharDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        ImmoltharDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable immol'thar fight strategy", "-immol'thar") {}
    };

    // Disease Cloud ~10yd persistent AoE — stay >12yd
    class ImmoltharMoveAwayFromDiseaseCloudAction : public MoveAwayFromCreature
    {
    public:
        ImmoltharMoveAwayFromDiseaseCloudAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "immol'thar move away from disease cloud", 11496, 12.0f) {}
    };

    // ── West: Prince Tortheldrin ──────────────────────────────────────────────────
    class PrinceTortheldrinEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        PrinceTortheldrinEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable prince tortheldrin fight strategy", "+prince tortheldrin") {}
    };

    class PrinceTortheldrinDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        PrinceTortheldrinDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable prince tortheldrin fight strategy", "-prince tortheldrin") {}
    };

    // Arcane Blast + Whirlwind ~8yd AoE — stay >10yd
    class TortheldrinMoveAwayFromArcaneBlastAction : public MoveAwayFromCreature
    {
    public:
        TortheldrinMoveAwayFromArcaneBlastAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "tortheldrin move away from arcane blast", 11486, 10.0f) {}
    };

    // ── North: Guard Mol'dar ──────────────────────────────────────────────────────
    class GuardMoldarEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        GuardMoldarEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable guard mol'dar fight strategy", "+guard mol'dar") {}
    };

    class GuardMoldarDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        GuardMoldarDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable guard mol'dar fight strategy", "-guard mol'dar") {}
    };

    // War Stomp ~8yd AoE — stay >10yd
    class MoldarMoveAwayFromWarStompAction : public MoveAwayFromCreature
    {
    public:
        MoldarMoveAwayFromWarStompAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "mol'dar move away from war stomp", 14326, 10.0f) {}
    };

    // ── North: Stomper Kreeg ──────────────────────────────────────────────────────
    class StomperKreegEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        StomperKreegEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable stomper kreeg fight strategy", "+stomper kreeg") {}
    };

    class StomperKreegDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        StomperKreegDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable stomper kreeg fight strategy", "-stomper kreeg") {}
    };

    // Knock Away ~8yd AoE knockback — stay >10yd
    class KreegMoveAwayFromKnockAwayAction : public MoveAwayFromCreature
    {
    public:
        KreegMoveAwayFromKnockAwayAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "kreeg move away from knock away", 14322, 10.0f) {}
    };

    // ── North: Guard Fengus ───────────────────────────────────────────────────────
    class GuardFengusEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        GuardFengusEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable guard fengus fight strategy", "+guard fengus") {}
    };

    class GuardFengusDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        GuardFengusDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable guard fengus fight strategy", "-guard fengus") {}
    };

    // ── North: Guard Slip'kik ─────────────────────────────────────────────────────
    class GuardSlipkikEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        GuardSlipkikEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable guard slip'kik fight strategy", "+guard slip'kik") {}
    };

    class GuardSlipkikDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        GuardSlipkikDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable guard slip'kik fight strategy", "-guard slip'kik") {}
    };

    // Frost Nova ~8yd AoE freeze — stay >10yd
    class SlipkikMoveAwayFromFrostNovaAction : public MoveAwayFromCreature
    {
    public:
        SlipkikMoveAwayFromFrostNovaAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "slip'kik move away from frost nova", 14323, 10.0f) {}
    };

    // ── North: Captain Kromcrush ──────────────────────────────────────────────────
    class CaptainKromcrushEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        CaptainKromcrushEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable captain kromcrush fight strategy", "+captain kromcrush") {}
    };

    class CaptainKromcrushDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        CaptainKromcrushDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable captain kromcrush fight strategy", "-captain kromcrush") {}
    };

    // War Stomp ~8yd AoE — stay >10yd
    class KromcrushMoveAwayFromWarStompAction : public MoveAwayFromCreature
    {
    public:
        KromcrushMoveAwayFromWarStompAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "kromcrush move away from war stomp", 14325, 10.0f) {}
    };

    // ── North: King Gordok ────────────────────────────────────────────────────────
    class KingGordokEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        KingGordokEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable king gordok fight strategy", "+king gordok") {}
    };

    class KingGordokDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        KingGordokDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable king gordok fight strategy", "-king gordok") {}
    };

    // Thunderclap ~8yd AoE physical — stay >10yd
    class GordokMoveAwayFromThunderclapAction : public MoveAwayFromCreature
    {
    public:
        GordokMoveAwayFromThunderclapAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "gordok move away from thunderclap", 11501, 10.0f) {}
    };
}
