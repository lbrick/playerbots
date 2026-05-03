#pragma once
#include "playerbot/strategy/triggers/DungeonTriggers.h"

namespace ai
{
    // ── Instance enter/leave (Map ID 429) ───────────────────────────────────────
    class DireMaulEnterDungeonTrigger : public EnterDungeonTrigger
    {
    public:
        DireMaulEnterDungeonTrigger(PlayerbotAI* ai)
            : EnterDungeonTrigger(ai, "enter dire maul", "dire maul", 429) {}
    };

    class DireMaulLeaveDungeonTrigger : public LeaveDungeonTrigger
    {
    public:
        DireMaulLeaveDungeonTrigger(PlayerbotAI* ai)
            : LeaveDungeonTrigger(ai, "leave dire maul", "dire maul", 429) {}
    };

    // ── East: Zevrim Thornhoof (11490) — no positional AoE ──────────────────────
    class ZevrimThornhoofStartFightTrigger : public StartBossFightTrigger
    {
    public:
        ZevrimThornhoofStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start zevrim thornhoof fight", "zevrim thornhoof", 11490) {}
    };

    class ZevrimThornhoofEndFightTrigger : public EndBossFightTrigger
    {
    public:
        ZevrimThornhoofEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end zevrim thornhoof fight", "zevrim thornhoof", 11490) {}
    };

    // ── East: Hydrospawn (13280) — no positional AoE ────────────────────────────
    class HydrospawnStartFightTrigger : public StartBossFightTrigger
    {
    public:
        HydrospawnStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start hydrospawn fight", "hydrospawn", 13280) {}
    };

    class HydrospawnEndFightTrigger : public EndBossFightTrigger
    {
    public:
        HydrospawnEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end hydrospawn fight", "hydrospawn", 13280) {}
    };

    // ── East: Lethtendris (14327) — no positional AoE ───────────────────────────
    class LethtendrisStartFightTrigger : public StartBossFightTrigger
    {
    public:
        LethtendrisStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start lethtendris fight", "lethtendris", 14327) {}
    };

    class LethtendrisEndFightTrigger : public EndBossFightTrigger
    {
    public:
        LethtendrisEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end lethtendris fight", "lethtendris", 14327) {}
    };

    // ── East: Alzzin the Wildshaper (11492) — Earthgrip ~10yd AoE root ──────────
    class AlzzinTheWildshaperStartFightTrigger : public StartBossFightTrigger
    {
    public:
        AlzzinTheWildshaperStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start alzzin the wildshaper fight", "alzzin the wildshaper", 11492) {}
    };

    class AlzzinTheWildshaperEndFightTrigger : public EndBossFightTrigger
    {
    public:
        AlzzinTheWildshaperEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end alzzin the wildshaper fight", "alzzin the wildshaper", 11492) {}
    };

    class AlzzinEarthgripTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        AlzzinEarthgripTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "alzzin earthgrip", 11492, 10.0f, 3) {}
    };

    // ── West: Tendris Warpwood (11489) — Entangle ~8yd AoE root ─────────────────
    class TendrisWarpwoodStartFightTrigger : public StartBossFightTrigger
    {
    public:
        TendrisWarpwoodStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start tendris warpwood fight", "tendris warpwood", 11489) {}
    };

    class TendrisWarpwoodEndFightTrigger : public EndBossFightTrigger
    {
    public:
        TendrisWarpwoodEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end tendris warpwood fight", "tendris warpwood", 11489) {}
    };

    class TendrisEntangleTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        TendrisEntangleTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "tendris entangle", 11489, 8.0f, 3) {}
    };

    // ── West: Illyanna Ravenoak (11488) — frontal deferred ──────────────────────
    class IllyannaRavenoakStartFightTrigger : public StartBossFightTrigger
    {
    public:
        IllyannaRavenoakStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start illyanna ravenoak fight", "illyanna ravenoak", 11488) {}
    };

    class IllyannaRavenoakEndFightTrigger : public EndBossFightTrigger
    {
    public:
        IllyannaRavenoakEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end illyanna ravenoak fight", "illyanna ravenoak", 11488) {}
    };

    // ── West: Magister Kalendris (11487) — no positional AoE ────────────────────
    class MagisterKalendrisStartFightTrigger : public StartBossFightTrigger
    {
    public:
        MagisterKalendrisStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start magister kalendris fight", "magister kalendris", 11487) {}
    };

    class MagisterKalendrisEndFightTrigger : public EndBossFightTrigger
    {
    public:
        MagisterKalendrisEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end magister kalendris fight", "magister kalendris", 11487) {}
    };

    // ── West: Immol'thar (11496) — Disease Cloud ~10yd persistent AoE ───────────
    class ImmoltharStartFightTrigger : public StartBossFightTrigger
    {
    public:
        ImmoltharStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start immol'thar fight", "immol'thar", 11496) {}
    };

    class ImmoltharEndFightTrigger : public EndBossFightTrigger
    {
    public:
        ImmoltharEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end immol'thar fight", "immol'thar", 11496) {}
    };

    class ImmoltharDiseaseCloudTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        ImmoltharDiseaseCloudTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "immol'thar disease cloud", 11496, 10.0f, 3) {}
    };

    // ── West: Prince Tortheldrin (11486) — Arcane Blast ~8yd AoE ────────────────
    class PrinceTortheldrinStartFightTrigger : public StartBossFightTrigger
    {
    public:
        PrinceTortheldrinStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start prince tortheldrin fight", "prince tortheldrin", 11486) {}
    };

    class PrinceTortheldrinEndFightTrigger : public EndBossFightTrigger
    {
    public:
        PrinceTortheldrinEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end prince tortheldrin fight", "prince tortheldrin", 11486) {}
    };

    class TortheldrinArcaneBlastTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        TortheldrinArcaneBlastTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "tortheldrin arcane blast", 11486, 8.0f, 3) {}
    };

    // ── North: Guard Mol'dar (14326) — War Stomp ~8yd AoE ───────────────────────
    class GuardMoldarStartFightTrigger : public StartBossFightTrigger
    {
    public:
        GuardMoldarStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start guard mol'dar fight", "guard mol'dar", 14326) {}
    };

    class GuardMoldarEndFightTrigger : public EndBossFightTrigger
    {
    public:
        GuardMoldarEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end guard mol'dar fight", "guard mol'dar", 14326) {}
    };

    class MoldarWarStompTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        MoldarWarStompTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "mol'dar war stomp", 14326, 8.0f, 3) {}
    };

    // ── North: Stomper Kreeg (14322) — Knock Away ~8yd AoE ──────────────────────
    class StomperKreegStartFightTrigger : public StartBossFightTrigger
    {
    public:
        StomperKreegStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start stomper kreeg fight", "stomper kreeg", 14322) {}
    };

    class StomperKreegEndFightTrigger : public EndBossFightTrigger
    {
    public:
        StomperKreegEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end stomper kreeg fight", "stomper kreeg", 14322) {}
    };

    class KreegKnockAwayTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        KreegKnockAwayTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "kreeg knock away", 14322, 8.0f, 3) {}
    };

    // ── North: Guard Fengus (14321) — no radial AoE ─────────────────────────────
    class GuardFengusStartFightTrigger : public StartBossFightTrigger
    {
    public:
        GuardFengusStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start guard fengus fight", "guard fengus", 14321) {}
    };

    class GuardFengusEndFightTrigger : public EndBossFightTrigger
    {
    public:
        GuardFengusEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end guard fengus fight", "guard fengus", 14321) {}
    };

    // ── North: Guard Slip'kik (14323) — Frost Nova ~8yd AoE ─────────────────────
    class GuardSlipkikStartFightTrigger : public StartBossFightTrigger
    {
    public:
        GuardSlipkikStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start guard slip'kik fight", "guard slip'kik", 14323) {}
    };

    class GuardSlipkikEndFightTrigger : public EndBossFightTrigger
    {
    public:
        GuardSlipkikEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end guard slip'kik fight", "guard slip'kik", 14323) {}
    };

    class SlipkikFrostNovaTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        SlipkikFrostNovaTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "slip'kik frost nova", 14323, 8.0f, 3) {}
    };

    // ── North: Captain Kromcrush (14325) — War Stomp ~8yd AoE ───────────────────
    class CaptainKromcrushStartFightTrigger : public StartBossFightTrigger
    {
    public:
        CaptainKromcrushStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start captain kromcrush fight", "captain kromcrush", 14325) {}
    };

    class CaptainKromcrushEndFightTrigger : public EndBossFightTrigger
    {
    public:
        CaptainKromcrushEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end captain kromcrush fight", "captain kromcrush", 14325) {}
    };

    class KromcrushWarStompTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        KromcrushWarStompTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "kromcrush war stomp", 14325, 8.0f, 3) {}
    };

    // ── North: King Gordok (11501) — Thunderclap ~8yd AoE ───────────────────────
    class KingGordokStartFightTrigger : public StartBossFightTrigger
    {
    public:
        KingGordokStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start king gordok fight", "king gordok", 11501) {}
    };

    class KingGordokEndFightTrigger : public EndBossFightTrigger
    {
    public:
        KingGordokEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end king gordok fight", "king gordok", 11501) {}
    };

    class GordokThunderclapTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        GordokThunderclapTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "gordok thunderclap", 11501, 8.0f, 3) {}
    };
}
