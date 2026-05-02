#pragma once
#include "playerbot/strategy/actions/DungeonActions.h"

namespace ai
{
    // ── Instance strategy enable/disable ────────────────────────────────────────
    class BlackrockDepthsEnableStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        BlackrockDepthsEnableStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable blackrock depths strategy", "+blackrock depths") {}
    };

    class BlackrockDepthsDisableStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        BlackrockDepthsDisableStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable blackrock depths strategy", "-blackrock depths") {}
    };

    // ── Gorosh ────────────────────────────────────────────────────────────────────
    class GoroshEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        GoroshEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable gorosh fight strategy", "+gorosh") {}
    };

    class GoroshDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        GoroshDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable gorosh fight strategy", "-gorosh") {}
    };

    // ── Grizzle ───────────────────────────────────────────────────────────────────
    class GrizzleEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        GrizzleEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable grizzle fight strategy", "+grizzle") {}
    };

    class GrizzleDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        GrizzleDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable grizzle fight strategy", "-grizzle") {}
    };

    // Ground Tremor ~10yd AoE avoidance — stay >12 yards
    class GrizzleMoveAwayFromGroundTremorAction : public MoveAwayFromCreature
    {
    public:
        GrizzleMoveAwayFromGroundTremorAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "grizzle move away from ground tremor", 9028, 12.0f) {}
    };

    // ── Eviscerator ───────────────────────────────────────────────────────────────
    class EviscerratorEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        EviscerratorEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable eviscerator fight strategy", "+eviscerator") {}
    };

    class EviscerratorDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        EviscerratorDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable eviscerator fight strategy", "-eviscerator") {}
    };

    // Whirlwind ~8yd AoE avoidance — stay >10 yards
    class EviscerratorMoveAwayFromWhirlwindAction : public MoveAwayFromCreature
    {
    public:
        EviscerratorMoveAwayFromWhirlwindAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "eviscerator move away from whirlwind", 9029, 10.0f) {}
    };

    // ── Ok'thor the Breaker ───────────────────────────────────────────────────────
    class OkthorEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        OkthorEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable ok'thor the breaker fight strategy", "+ok'thor the breaker") {}
    };

    class OkthorDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        OkthorDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable ok'thor the breaker fight strategy", "-ok'thor the breaker") {}
    };

    // War Stomp ~8yd AoE avoidance — stay >10 yards
    class OkthorMoveAwayFromWarStompAction : public MoveAwayFromCreature
    {
    public:
        OkthorMoveAwayFromWarStompAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "ok'thor move away from war stomp", 9030, 10.0f) {}
    };

    // ── Anub'shiah ────────────────────────────────────────────────────────────────
    class AnubshiahEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        AnubshiahEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable anub'shiah fight strategy", "+anub'shiah") {}
    };

    class AnubshiahDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        AnubshiahDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable anub'shiah fight strategy", "-anub'shiah") {}
    };

    // ── Hedrum the Creeper ────────────────────────────────────────────────────────
    class HedrumEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        HedrumEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable hedrum the creeper fight strategy", "+hedrum the creeper") {}
    };

    class HedrumDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        HedrumDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable hedrum the creeper fight strategy", "-hedrum the creeper") {}
    };

    // ── High Interrogator Gerstahn ────────────────────────────────────────────────
    class GerstanEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        GerstanEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable high interrogator gerstahn fight strategy", "+high interrogator gerstahn") {}
    };

    class GerstanDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        GerstanDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable high interrogator gerstahn fight strategy", "-high interrogator gerstahn") {}
    };

    // ── Lord Roccor ───────────────────────────────────────────────────────────────
    class LordRoccorEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        LordRoccorEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable lord roccor fight strategy", "+lord roccor") {}
    };

    class LordRoccorDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        LordRoccorDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable lord roccor fight strategy", "-lord roccor") {}
    };

    // Earthquake ~10yd AoE avoidance — stay >12 yards
    class LordRoccorMoveAwayFromEarthquakeAction : public MoveAwayFromCreature
    {
    public:
        LordRoccorMoveAwayFromEarthquakeAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "lord roccor move away from earthquake", 9025, 12.0f) {}
    };

    // ── Houndmaster Grebmar ───────────────────────────────────────────────────────
    class GrebmarEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        GrebmarEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable houndmaster grebmar fight strategy", "+houndmaster grebmar") {}
    };

    class GrebmarDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        GrebmarDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable houndmaster grebmar fight strategy", "-houndmaster grebmar") {}
    };

    // ── Pyromancer Loregrain ──────────────────────────────────────────────────────
    class PyromancerLoregrainEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        PyromancerLoregrainEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable pyromancer loregrain fight strategy", "+pyromancer loregrain") {}
    };

    class PyromancerLoregrainDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        PyromancerLoregrainDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable pyromancer loregrain fight strategy", "-pyromancer loregrain") {}
    };

    // Fire Nova ~10yd AoE avoidance — stay >12 yards
    class PyromancerMoveAwayFromFireNovaAction : public MoveAwayFromCreature
    {
    public:
        PyromancerMoveAwayFromFireNovaAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "pyromancer move away from fire nova", 9024, 12.0f) {}
    };

    // ── Warder Stilgiss ───────────────────────────────────────────────────────────
    class WarderStiglissEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        WarderStiglissEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable warder stilgiss fight strategy", "+warder stilgiss") {}
    };

    class WarderStiglissDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        WarderStiglissDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable warder stilgiss fight strategy", "-warder stilgiss") {}
    };

    // Frost Nova ~8yd AoE avoidance — stay >10 yards
    class WarderStiglissMoveAwayFromFrostNovaAction : public MoveAwayFromCreature
    {
    public:
        WarderStiglissMoveAwayFromFrostNovaAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "warder stilgiss move away from frost nova", 9041, 10.0f) {}
    };

    // ── Verek ─────────────────────────────────────────────────────────────────────
    class VerekEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        VerekEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable verek fight strategy", "+verek") {}
    };

    class VerekDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        VerekDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable verek fight strategy", "-verek") {}
    };

    // ── Plugger Spazzring ─────────────────────────────────────────────────────────
    class PluggerSpazzringEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        PluggerSpazzringEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable plugger spazzring fight strategy", "+plugger spazzring") {}
    };

    class PluggerSpazzringDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        PluggerSpazzringDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable plugger spazzring fight strategy", "-plugger spazzring") {}
    };

    // ── Phalanx ───────────────────────────────────────────────────────────────────
    class PhalanxEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        PhalanxEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable phalanx fight strategy", "+phalanx") {}
    };

    class PhalanxDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        PhalanxDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable phalanx fight strategy", "-phalanx") {}
    };

    // ── Ambassador Flamelash ──────────────────────────────────────────────────────
    class FlamelashEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        FlamelashEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable ambassador flamelash fight strategy", "+ambassador flamelash") {}
    };

    class FlamelashDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        FlamelashDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable ambassador flamelash fight strategy", "-ambassador flamelash") {}
    };

    // ── The Seven ─────────────────────────────────────────────────────────────────
    class TheSevenEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        TheSevenEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable the seven fight strategy", "+the seven") {}
    };

    class TheSevenDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        TheSevenDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable the seven fight strategy", "-the seven") {}
    };

    // ── Golem Lord Argelmach ──────────────────────────────────────────────────────
    class ArgelmachEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        ArgelmachEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable golem lord argelmach fight strategy", "+golem lord argelmach") {}
    };

    class ArgelmachDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        ArgelmachDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable golem lord argelmach fight strategy", "-golem lord argelmach") {}
    };

    // Static Field ~8yd AoE avoidance — stay >10 yards
    class ArgelmachMoveAwayFromStaticFieldAction : public MoveAwayFromCreature
    {
    public:
        ArgelmachMoveAwayFromStaticFieldAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "argelmach move away from static field", 8983, 10.0f) {}
    };

    // ── Bael'Gar ──────────────────────────────────────────────────────────────────
    class BaelGarEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        BaelGarEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable bael'gar fight strategy", "+bael'gar") {}
    };

    class BaelGarDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        BaelGarDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable bael'gar fight strategy", "-bael'gar") {}
    };

    // Fire Nova ~10yd AoE avoidance — stay >12 yards
    class BaelGarMoveAwayFromFireNovaAction : public MoveAwayFromCreature
    {
    public:
        BaelGarMoveAwayFromFireNovaAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "bael'gar move away from fire nova", 9016, 12.0f) {}
    };

    // ── General Angerforge ────────────────────────────────────────────────────────
    class GeneralAngerforgeEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        GeneralAngerforgeEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable general angerforge fight strategy", "+general angerforge") {}
    };

    class GeneralAngerforgeDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        GeneralAngerforgeDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable general angerforge fight strategy", "-general angerforge") {}
    };

    // ── Magmus ────────────────────────────────────────────────────────────────────
    class MagmusEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        MagmusEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable magmus fight strategy", "+magmus") {}
    };

    class MagmusDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        MagmusDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable magmus fight strategy", "-magmus") {}
    };

    // War Stomp ~8yd AoE avoidance — stay >10 yards
    class MagmusMoveAwayFromWarStompAction : public MoveAwayFromCreature
    {
    public:
        MagmusMoveAwayFromWarStompAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "magmus move away from war stomp", 9938, 10.0f) {}
    };

    // ── Emperor Dagran Thaurissan ──────────────────────────────────────────────────
    class EmperorThaurissanEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        EmperorThaurissanEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable emperor dagran thaurissan fight strategy", "+emperor dagran thaurissan") {}
    };

    class EmperorThaurissanDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        EmperorThaurissanDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable emperor dagran thaurissan fight strategy", "-emperor dagran thaurissan") {}
    };
}
