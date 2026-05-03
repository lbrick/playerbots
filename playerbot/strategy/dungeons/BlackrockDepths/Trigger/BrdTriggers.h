#pragma once
#include "playerbot/strategy/triggers/DungeonTriggers.h"

namespace ai
{
    // ── Instance enter/leave (Map ID 230) ───────────────────────────────────────
    class BlackrockDepthsEnterDungeonTrigger : public EnterDungeonTrigger
    {
    public:
        BlackrockDepthsEnterDungeonTrigger(PlayerbotAI* ai)
            : EnterDungeonTrigger(ai, "enter blackrock depths", "blackrock depths", 230) {}
    };

    class BlackrockDepthsLeaveDungeonTrigger : public LeaveDungeonTrigger
    {
    public:
        BlackrockDepthsLeaveDungeonTrigger(PlayerbotAI* ai)
            : LeaveDungeonTrigger(ai, "leave blackrock depths", "blackrock depths", 230) {}
    };

    // ── Ring of Law Champions ────────────────────────────────────────────────────

    // Gorosh the Dervish (9027) — DB verified; no positional AoE
    class GoroshStartFightTrigger : public StartBossFightTrigger
    {
    public:
        GoroshStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start gorosh fight", "gorosh", 9027) {}
    };

    class GoroshEndFightTrigger : public EndBossFightTrigger
    {
    public:
        GoroshEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end gorosh fight", "gorosh", 9027) {}
    };

    // Grizzle (9028) — DB verified; Ground Tremor ~10yd AoE
    class GrizzleStartFightTrigger : public StartBossFightTrigger
    {
    public:
        GrizzleStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start grizzle fight", "grizzle", 9028) {}
    };

    class GrizzleEndFightTrigger : public EndBossFightTrigger
    {
    public:
        GrizzleEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end grizzle fight", "grizzle", 9028) {}
    };

    class GrizzleGroundTremorTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        GrizzleGroundTremorTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "grizzle ground tremor", 9028, 10.0f, 3) {}
    };

    // Eviscerator (9029) — DB verified; Whirlwind ~8yd AoE
    class EviscerratorStartFightTrigger : public StartBossFightTrigger
    {
    public:
        EviscerratorStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start eviscerator fight", "eviscerator", 9029) {}
    };

    class EviscerratorEndFightTrigger : public EndBossFightTrigger
    {
    public:
        EviscerratorEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end eviscerator fight", "eviscerator", 9029) {}
    };

    class EviscerratorWhirlwindTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        EviscerratorWhirlwindTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "eviscerator whirlwind", 9029, 8.0f, 3) {}
    };

    // Ok'thor the Breaker (9030) — DB verified; War Stomp ~8yd AoE
    class OkthorStartFightTrigger : public StartBossFightTrigger
    {
    public:
        OkthorStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start ok'thor the breaker fight", "ok'thor the breaker", 9030) {}
    };

    class OkthorEndFightTrigger : public EndBossFightTrigger
    {
    public:
        OkthorEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end ok'thor the breaker fight", "ok'thor the breaker", 9030) {}
    };

    class OkthorWarStompTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        OkthorWarStompTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "ok'thor war stomp", 9030, 8.0f, 3) {}
    };

    // Anub'shiah (9031) — DB verified; no positional AoE
    class AnubshiahStartFightTrigger : public StartBossFightTrigger
    {
    public:
        AnubshiahStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start anub'shiah fight", "anub'shiah", 9031) {}
    };

    class AnubshiahEndFightTrigger : public EndBossFightTrigger
    {
    public:
        AnubshiahEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end anub'shiah fight", "anub'shiah", 9031) {}
    };

    // Hedrum the Creeper (9032) — DB verified; ranged AoE, handled by healer
    class HedrumStartFightTrigger : public StartBossFightTrigger
    {
    public:
        HedrumStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start hedrum the creeper fight", "hedrum the creeper", 9032) {}
    };

    class HedrumEndFightTrigger : public EndBossFightTrigger
    {
    public:
        HedrumEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end hedrum the creeper fight", "hedrum the creeper", 9032) {}
    };

    // ── Main Dungeon Bosses ──────────────────────────────────────────────────────

    // High Interrogator Gerstahn (9018) — DB verified; fear handled by break strategy
    class GerstanStartFightTrigger : public StartBossFightTrigger
    {
    public:
        GerstanStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start high interrogator gerstahn fight", "high interrogator gerstahn", 9018) {}
    };

    class GerstanEndFightTrigger : public EndBossFightTrigger
    {
    public:
        GerstanEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end high interrogator gerstahn fight", "high interrogator gerstahn", 9018) {}
    };

    // ── Gerstahn interrupt — Mana Burn (ID 14033, DB-verified) ──────────────────
    class GersthahnManaBurnCastingTrigger : public TargetCastingSpellTrigger
    {
    public:
        GersthahnManaBurnCastingTrigger(PlayerbotAI* ai)
            : TargetCastingSpellTrigger(ai, "target casting gerstahn mana burn", 14033) {}
    };

    // Lord Roccor (9025) — DB verified; Earthquake ~10yd AoE
    class LordRoccorStartFightTrigger : public StartBossFightTrigger
    {
    public:
        LordRoccorStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start lord roccor fight", "lord roccor", 9025) {}
    };

    class LordRoccorEndFightTrigger : public EndBossFightTrigger
    {
    public:
        LordRoccorEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end lord roccor fight", "lord roccor", 9025) {}
    };

    class LordRoccorEarthquakeTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        LordRoccorEarthquakeTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "lord roccor earthquake", 9025, 10.0f, 3) {}
    };

    // Houndmaster Grebmar (9319) — DB verified; no positional AoE
    class GrebmarStartFightTrigger : public StartBossFightTrigger
    {
    public:
        GrebmarStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start houndmaster grebmar fight", "houndmaster grebmar", 9319) {}
    };

    class GrebmarEndFightTrigger : public EndBossFightTrigger
    {
    public:
        GrebmarEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end houndmaster grebmar fight", "houndmaster grebmar", 9319) {}
    };

    // Pyromancer Loregrain (9024) — DB verified; Fire Nova ~10yd AoE
    class PyromancerLoregrainStartFightTrigger : public StartBossFightTrigger
    {
    public:
        PyromancerLoregrainStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start pyromancer loregrain fight", "pyromancer loregrain", 9024) {}
    };

    class PyromancerLoregrainEndFightTrigger : public EndBossFightTrigger
    {
    public:
        PyromancerLoregrainEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end pyromancer loregrain fight", "pyromancer loregrain", 9024) {}
    };

    class PyromancerFireNovaTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        PyromancerFireNovaTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "pyromancer fire nova", 9024, 10.0f, 3) {}
    };

    // Warder Stilgiss (9041) — DB verified; Frost Nova ~8yd AoE
    class WarderStiglissStartFightTrigger : public StartBossFightTrigger
    {
    public:
        WarderStiglissStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start warder stilgiss fight", "warder stilgiss", 9041) {}
    };

    class WarderStiglissEndFightTrigger : public EndBossFightTrigger
    {
    public:
        WarderStiglissEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end warder stilgiss fight", "warder stilgiss", 9041) {}
    };

    class WarderStiglissFrostNovaTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        WarderStiglissFrostNovaTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "warder stilgiss frost nova", 9041, 8.0f, 3) {}
    };

    // Verek (9042) — DB verified; no positional AoE
    class VerekStartFightTrigger : public StartBossFightTrigger
    {
    public:
        VerekStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start verek fight", "verek", 9042) {}
    };

    class VerekEndFightTrigger : public EndBossFightTrigger
    {
    public:
        VerekEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end verek fight", "verek", 9042) {}
    };

    // Plugger Spazzring (9499) — DB verified; no positional AoE
    class PluggerSpazzringStartFightTrigger : public StartBossFightTrigger
    {
    public:
        PluggerSpazzringStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start plugger spazzring fight", "plugger spazzring", 9499) {}
    };

    class PluggerSpazzringEndFightTrigger : public EndBossFightTrigger
    {
    public:
        PluggerSpazzringEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end plugger spazzring fight", "plugger spazzring", 9499) {}
    };

    // Phalanx (9502) — DB verified; no positional AoE
    class PhalanxStartFightTrigger : public StartBossFightTrigger
    {
    public:
        PhalanxStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start phalanx fight", "phalanx", 9502) {}
    };

    class PhalanxEndFightTrigger : public EndBossFightTrigger
    {
    public:
        PhalanxEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end phalanx fight", "phalanx", 9502) {}
    };

    // Ambassador Flamelash (9156) — DB verified; no positional AoE
    class FlamelashStartFightTrigger : public StartBossFightTrigger
    {
    public:
        FlamelashStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start ambassador flamelash fight", "ambassador flamelash", 9156) {}
    };

    class FlamelashEndFightTrigger : public EndBossFightTrigger
    {
    public:
        FlamelashEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end ambassador flamelash fight", "ambassador flamelash", 9156) {}
    };

    // The Seven (8888) — using Franclorn Forgewright as canonical NPC; verify in DB
    class TheSevenStartFightTrigger : public StartBossFightTrigger
    {
    public:
        TheSevenStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start the seven fight", "the seven", 8888) {}
    };

    class TheSevenEndFightTrigger : public EndBossFightTrigger
    {
    public:
        TheSevenEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end the seven fight", "the seven", 8888) {}
    };

    // Golem Lord Argelmach (8983) — DB verified; Static Field ~8yd AoE
    class ArgelmachStartFightTrigger : public StartBossFightTrigger
    {
    public:
        ArgelmachStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start golem lord argelmach fight", "golem lord argelmach", 8983) {}
    };

    class ArgelmachEndFightTrigger : public EndBossFightTrigger
    {
    public:
        ArgelmachEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end golem lord argelmach fight", "golem lord argelmach", 8983) {}
    };

    class ArgelmachStaticFieldTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        ArgelmachStaticFieldTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "argelmach static field", 8983, 8.0f, 3) {}
    };

    // Bael'Gar (9016) — DB verified; Fire Nova ~10yd AoE
    class BaelGarStartFightTrigger : public StartBossFightTrigger
    {
    public:
        BaelGarStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start bael'gar fight", "bael'gar", 9016) {}
    };

    class BaelGarEndFightTrigger : public EndBossFightTrigger
    {
    public:
        BaelGarEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end bael'gar fight", "bael'gar", 9016) {}
    };

    class BaelGarFireNovaTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        BaelGarFireNovaTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "bael'gar fire nova", 9016, 10.0f, 3) {}
    };

    // General Angerforge (9033) — DB verified; no radial AoE
    class GeneralAngerforgeStartFightTrigger : public StartBossFightTrigger
    {
    public:
        GeneralAngerforgeStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start general angerforge fight", "general angerforge", 9033) {}
    };

    class GeneralAngerforgeEndFightTrigger : public EndBossFightTrigger
    {
    public:
        GeneralAngerforgeEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end general angerforge fight", "general angerforge", 9033) {}
    };

    // Magmus (9938) — DB verified; War Stomp ~8yd AoE
    class MagmusStartFightTrigger : public StartBossFightTrigger
    {
    public:
        MagmusStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start magmus fight", "magmus", 9938) {}
    };

    class MagmusEndFightTrigger : public EndBossFightTrigger
    {
    public:
        MagmusEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end magmus fight", "magmus", 9938) {}
    };

    class MagmusWarStompTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        MagmusWarStompTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "magmus war stomp", 9938, 8.0f, 3) {}
    };

    // Emperor Dagran Thaurissan (9019) — DB verified; no movement mechanic
    class EmperorThaurissanStartFightTrigger : public StartBossFightTrigger
    {
    public:
        EmperorThaurissanStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start emperor dagran thaurissan fight", "emperor dagran thaurissan", 9019) {}
    };

    class EmperorThaurissanEndFightTrigger : public EndBossFightTrigger
    {
    public:
        EmperorThaurissanEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end emperor dagran thaurissan fight", "emperor dagran thaurissan", 9019) {}
    };
}
