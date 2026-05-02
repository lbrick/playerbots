#pragma once
#include "playerbot/strategy/triggers/DungeonTriggers.h"

namespace ai
{
    // ── Instance enter/leave (Map ID 229) ───────────────────────────────────────
    class BlackrockSpireEnterDungeonTrigger : public EnterDungeonTrigger
    {
    public:
        BlackrockSpireEnterDungeonTrigger(PlayerbotAI* ai)
            : EnterDungeonTrigger(ai, "enter blackrock spire", "blackrock spire", 229) {}
    };

    class BlackrockSpireLeaveDungeonTrigger : public LeaveDungeonTrigger
    {
    public:
        BlackrockSpireLeaveDungeonTrigger(PlayerbotAI* ai)
            : LeaveDungeonTrigger(ai, "leave blackrock spire", "blackrock spire", 229) {}
    };

    // ── LBRS Bosses ─────────────────────────────────────────────────────────────

    // Highlord Omokk (9196) — DB verified; War Stomp ~8yd AoE
    class HigdlordOmokkStartFightTrigger : public StartBossFightTrigger
    {
    public:
        HigdlordOmokkStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start highlord omokk fight", "highlord omokk", 9196) {}
    };

    class HigdlordOmokkEndFightTrigger : public EndBossFightTrigger
    {
    public:
        HigdlordOmokkEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end highlord omokk fight", "highlord omokk", 9196) {}
    };

    class OmokkWarStompTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        OmokkWarStompTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "omokk war stomp", 9196, 8.0f, 3) {}
    };

    // Shadow Hunter Vosh'gajin (9236) — DB verified; no positional AoE
    class VoshgajinStartFightTrigger : public StartBossFightTrigger
    {
    public:
        VoshgajinStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start shadow hunter vosh'gajin fight", "shadow hunter vosh'gajin", 9236) {}
    };

    class VoshgajinEndFightTrigger : public EndBossFightTrigger
    {
    public:
        VoshgajinEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end shadow hunter vosh'gajin fight", "shadow hunter vosh'gajin", 9236) {}
    };

    // War Master Voone (9237) — DB verified; no positional AoE
    class WarMasterVooneStartFightTrigger : public StartBossFightTrigger
    {
    public:
        WarMasterVooneStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start war master voone fight", "war master voone", 9237) {}
    };

    class WarMasterVooneEndFightTrigger : public EndBossFightTrigger
    {
    public:
        WarMasterVooneEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end war master voone fight", "war master voone", 9237) {}
    };

    // Mother Smolderweb (10596) — DB verified; no positional AoE
    class MotherSmolderwebStartFightTrigger : public StartBossFightTrigger
    {
    public:
        MotherSmolderwebStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start mother smolderweb fight", "mother smolderweb", 10596) {}
    };

    class MotherSmolderwebEndFightTrigger : public EndBossFightTrigger
    {
    public:
        MotherSmolderwebEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end mother smolderweb fight", "mother smolderweb", 10596) {}
    };

    // Urok Doomhowl (10584) — DB verified; War Stomp ~8yd AoE; optional event boss
    class UrokDoomhowlStartFightTrigger : public StartBossFightTrigger
    {
    public:
        UrokDoomhowlStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start urok doomhowl fight", "urok doomhowl", 10584) {}
    };

    class UrokDoomhowlEndFightTrigger : public EndBossFightTrigger
    {
    public:
        UrokDoomhowlEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end urok doomhowl fight", "urok doomhowl", 10584) {}
    };

    class UrokWarStompTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        UrokWarStompTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "urok war stomp", 10584, 8.0f, 3) {}
    };

    // Quartermaster Zigris (9736) — DB verified; no positional AoE
    class QuartermasterZigrisStartFightTrigger : public StartBossFightTrigger
    {
    public:
        QuartermasterZigrisStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start quartermaster zigris fight", "quartermaster zigris", 9736) {}
    };

    class QuartermasterZigrisEndFightTrigger : public EndBossFightTrigger
    {
    public:
        QuartermasterZigrisEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end quartermaster zigris fight", "quartermaster zigris", 9736) {}
    };

    // Halycon (10220) — DB verified; AoE fear handled by break strategy; no movement trigger
    class HalyconStartFightTrigger : public StartBossFightTrigger
    {
    public:
        HalyconStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start halycon fight", "halycon", 10220) {}
    };

    class HalyconEndFightTrigger : public EndBossFightTrigger
    {
    public:
        HalyconEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end halycon fight", "halycon", 10220) {}
    };

    // Overlord Wyrmthalak (9568) — DB verified; War Stomp ~8yd + Blizzard ~10yd AoE
    class OverlordWyrmthalakStartFightTrigger : public StartBossFightTrigger
    {
    public:
        OverlordWyrmthalakStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start overlord wyrmthalak fight", "overlord wyrmthalak", 9568) {}
    };

    class OverlordWyrmthalakEndFightTrigger : public EndBossFightTrigger
    {
    public:
        OverlordWyrmthalakEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end overlord wyrmthalak fight", "overlord wyrmthalak", 9568) {}
    };

    class WyrmthalakBlizzardTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        WyrmthalakBlizzardTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "wyrmthalak blizzard", 9568, 10.0f, 3) {}
    };

    // ── UBRS Bosses ─────────────────────────────────────────────────────────────

    // Pyroguard Emberseer (9816) — DB verified; Ignite ~8yd fire aura after freed
    class PyroguardEmberseerStartFightTrigger : public StartBossFightTrigger
    {
    public:
        PyroguardEmberseerStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start pyroguard emberseer fight", "pyroguard emberseer", 9816) {}
    };

    class PyroguardEmberseerEndFightTrigger : public EndBossFightTrigger
    {
    public:
        PyroguardEmberseerEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end pyroguard emberseer fight", "pyroguard emberseer", 9816) {}
    };

    class EmberseerIgniteTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        EmberseerIgniteTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "emberseer ignite", 9816, 8.0f, 3) {}
    };

    // Solakar Flamewreath (10264) — DB verified; no radial AoE
    class SolakarFlamewreathStartFightTrigger : public StartBossFightTrigger
    {
    public:
        SolakarFlamewreathStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start solakar flamewreath fight", "solakar flamewreath", 10264) {}
    };

    class SolakarFlamewreathEndFightTrigger : public EndBossFightTrigger
    {
    public:
        SolakarFlamewreathEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end solakar flamewreath fight", "solakar flamewreath", 10264) {}
    };

    // Jed Runewatcher (10509) — DB verified; rare spawn; no positional AoE
    class JedRunewatcherStartFightTrigger : public StartBossFightTrigger
    {
    public:
        JedRunewatcherStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start jed runewatcher fight", "jed runewatcher", 10509) {}
    };

    class JedRunewatcherEndFightTrigger : public EndBossFightTrigger
    {
    public:
        JedRunewatcherEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end jed runewatcher fight", "jed runewatcher", 10509) {}
    };

    // The Beast (10430) — DB verified; Conflagration ~10yd AoE splash
    class TheBeastStartFightTrigger : public StartBossFightTrigger
    {
    public:
        TheBeastStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start the beast fight", "the beast", 10430) {}
    };

    class TheBeastEndFightTrigger : public EndBossFightTrigger
    {
    public:
        TheBeastEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end the beast fight", "the beast", 10430) {}
    };

    class TheBeastConflagrationTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        TheBeastConflagrationTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "the beast conflagration", 10430, 10.0f, 4) {}
    };

    // General Drakkisath (10363) — DB verified; Conflagration ~8yd AoE cone
    class GeneralDrakkisathStartFightTrigger : public StartBossFightTrigger
    {
    public:
        GeneralDrakkisathStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start general drakkisath fight", "general drakkisath", 10363) {}
    };

    class GeneralDrakkisathEndFightTrigger : public EndBossFightTrigger
    {
    public:
        GeneralDrakkisathEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end general drakkisath fight", "general drakkisath", 10363) {}
    };

    class DrakkisathConflagrationTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        DrakkisathConflagrationTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "drakkisath conflagration", 10363, 8.0f, 3) {}
    };
}
