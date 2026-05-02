#pragma once
#include "playerbot/strategy/actions/DungeonActions.h"

namespace ai
{
    // ── Instance strategy enable/disable ────────────────────────────────────────
    class BlackrockSpireEnableStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        BlackrockSpireEnableStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable blackrock spire strategy", "+blackrock spire") {}
    };

    class BlackrockSpireDisableStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        BlackrockSpireDisableStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable blackrock spire strategy", "-blackrock spire") {}
    };

    // ── Highlord Omokk ────────────────────────────────────────────────────────────
    class HigdlordOmokkEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        HigdlordOmokkEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable highlord omokk fight strategy", "+highlord omokk") {}
    };

    class HigdlordOmokkDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        HigdlordOmokkDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable highlord omokk fight strategy", "-highlord omokk") {}
    };

    // War Stomp ~8yd AoE avoidance — stay >10 yards
    class OmokkMoveAwayFromWarStompAction : public MoveAwayFromCreature
    {
    public:
        OmokkMoveAwayFromWarStompAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "omokk move away from war stomp", 9196, 10.0f) {}
    };

    // ── Shadow Hunter Vosh'gajin ──────────────────────────────────────────────────
    class VoshgajinEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        VoshgajinEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable shadow hunter vosh'gajin fight strategy", "+shadow hunter vosh'gajin") {}
    };

    class VoshgajinDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        VoshgajinDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable shadow hunter vosh'gajin fight strategy", "-shadow hunter vosh'gajin") {}
    };

    // ── War Master Voone ──────────────────────────────────────────────────────────
    class WarMasterVooneEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        WarMasterVooneEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable war master voone fight strategy", "+war master voone") {}
    };

    class WarMasterVooneDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        WarMasterVooneDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable war master voone fight strategy", "-war master voone") {}
    };

    // ── Mother Smolderweb ─────────────────────────────────────────────────────────
    class MotherSmolderwebEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        MotherSmolderwebEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable mother smolderweb fight strategy", "+mother smolderweb") {}
    };

    class MotherSmolderwebDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        MotherSmolderwebDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable mother smolderweb fight strategy", "-mother smolderweb") {}
    };

    // ── Urok Doomhowl ─────────────────────────────────────────────────────────────
    class UrokDoomhowlEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        UrokDoomhowlEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable urok doomhowl fight strategy", "+urok doomhowl") {}
    };

    class UrokDoomhowlDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        UrokDoomhowlDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable urok doomhowl fight strategy", "-urok doomhowl") {}
    };

    // War Stomp ~8yd AoE avoidance — stay >10 yards
    class UrokMoveAwayFromWarStompAction : public MoveAwayFromCreature
    {
    public:
        UrokMoveAwayFromWarStompAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "urok move away from war stomp", 10584, 10.0f) {}
    };

    // ── Quartermaster Zigris ──────────────────────────────────────────────────────
    class QuartermasterZigrisEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        QuartermasterZigrisEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable quartermaster zigris fight strategy", "+quartermaster zigris") {}
    };

    class QuartermasterZigrisDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        QuartermasterZigrisDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable quartermaster zigris fight strategy", "-quartermaster zigris") {}
    };

    // ── Halycon ───────────────────────────────────────────────────────────────────
    class HalyconEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        HalyconEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable halycon fight strategy", "+halycon") {}
    };

    class HalyconDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        HalyconDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable halycon fight strategy", "-halycon") {}
    };

    // ── Overlord Wyrmthalak ───────────────────────────────────────────────────────
    class OverlordWyrmthalakEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        OverlordWyrmthalakEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable overlord wyrmthalak fight strategy", "+overlord wyrmthalak") {}
    };

    class OverlordWyrmthalakDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        OverlordWyrmthalakDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable overlord wyrmthalak fight strategy", "-overlord wyrmthalak") {}
    };

    // War Stomp + Blizzard ~10yd AoE avoidance — stay >12 yards
    class WyrmthalakMoveAwayFromBlizzardAction : public MoveAwayFromCreature
    {
    public:
        WyrmthalakMoveAwayFromBlizzardAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "wyrmthalak move away from blizzard", 9568, 12.0f) {}
    };

    // ── Pyroguard Emberseer ───────────────────────────────────────────────────────
    class PyroguardEmberseerEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        PyroguardEmberseerEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable pyroguard emberseer fight strategy", "+pyroguard emberseer") {}
    };

    class PyroguardEmberseerDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        PyroguardEmberseerDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable pyroguard emberseer fight strategy", "-pyroguard emberseer") {}
    };

    // Ignite ~8yd fire aura avoidance — stay >10 yards
    class EmberseerMoveAwayFromIgniteAction : public MoveAwayFromCreature
    {
    public:
        EmberseerMoveAwayFromIgniteAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "emberseer move away from ignite", 9816, 10.0f) {}
    };

    // ── Solakar Flamewreath ───────────────────────────────────────────────────────
    class SolakarFlamewreathEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        SolakarFlamewreathEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable solakar flamewreath fight strategy", "+solakar flamewreath") {}
    };

    class SolakarFlamewreathDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        SolakarFlamewreathDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable solakar flamewreath fight strategy", "-solakar flamewreath") {}
    };

    // ── Jed Runewatcher ───────────────────────────────────────────────────────────
    class JedRunewatcherEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        JedRunewatcherEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable jed runewatcher fight strategy", "+jed runewatcher") {}
    };

    class JedRunewatcherDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        JedRunewatcherDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable jed runewatcher fight strategy", "-jed runewatcher") {}
    };

    // ── The Beast ─────────────────────────────────────────────────────────────────
    class TheBeastEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        TheBeastEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable the beast fight strategy", "+the beast") {}
    };

    class TheBeastDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        TheBeastDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable the beast fight strategy", "-the beast") {}
    };

    // Conflagration ~10yd AoE splash avoidance — stay >12 yards
    class TheBeastMoveAwayFromConflagrationAction : public MoveAwayFromCreature
    {
    public:
        TheBeastMoveAwayFromConflagrationAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "the beast move away from conflagration", 10430, 12.0f) {}
    };

    // ── General Drakkisath ────────────────────────────────────────────────────────
    class GeneralDrakkisathEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        GeneralDrakkisathEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable general drakkisath fight strategy", "+general drakkisath") {}
    };

    class GeneralDrakkisathDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        GeneralDrakkisathDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable general drakkisath fight strategy", "-general drakkisath") {}
    };

    // Conflagration ~8yd AoE cone avoidance — stay >10 yards
    class DrakkisathMoveAwayFromConflagrationAction : public MoveAwayFromCreature
    {
    public:
        DrakkisathMoveAwayFromConflagrationAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "drakkisath move away from conflagration", 10363, 10.0f) {}
    };
}
