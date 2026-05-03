#pragma once
#include "playerbot/strategy/actions/DungeonActions.h"

namespace ai
{
    // ── Instance strategy enable/disable ────────────────────────────────────────
    class StratholmeEnableStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        StratholmeEnableStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable stratholme strategy", "+stratholme") {}
    };

    class StratholmeDisableStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        StratholmeDisableStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable stratholme strategy", "-stratholme") {}
    };

    // ── Scarlet: Hearthsinger Forresten ───────────────────────────────────────────
    class HearthsingerForrestenEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        HearthsingerForrestenEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable hearthsinger forresten fight strategy", "+hearthsinger forresten") {}
    };

    class HearthsingerForrestenDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        HearthsingerForrestenDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable hearthsinger forresten fight strategy", "-hearthsinger forresten") {}
    };

    // ── Scarlet: Timmy the Cruel ──────────────────────────────────────────────────
    class TimmytheCruelEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        TimmytheCruelEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable timmy the cruel fight strategy", "+timmy the cruel") {}
    };

    class TimmytheCruelDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        TimmytheCruelDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable timmy the cruel fight strategy", "-timmy the cruel") {}
    };

    // ── Scarlet: Cannon Master Willey ─────────────────────────────────────────────
    class CannonMasterWilleyEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        CannonMasterWilleyEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable cannon master willey fight strategy", "+cannon master willey") {}
    };

    class CannonMasterWilleyDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        CannonMasterWilleyDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable cannon master willey fight strategy", "-cannon master willey") {}
    };

    // ── Scarlet: Archivist Galford ────────────────────────────────────────────────
    class ArchivistGalfordEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        ArchivistGalfordEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable archivist galford fight strategy", "+archivist galford") {}
    };

    class ArchivistGalfordDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        ArchivistGalfordDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable archivist galford fight strategy", "-archivist galford") {}
    };

    // Flame Buffet ~8yd AoE fire — stay >10yd
    class GalfordMoveAwayFromFlameBuffetAction : public MoveAwayFromCreature
    {
    public:
        GalfordMoveAwayFromFlameBuffetAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "galford move away from flame buffet", 10812, 10.0f) {}
    };

    // ── Scarlet: Balnazzar ───────────────────────────────────────────────────────
    class BalnazzarEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        BalnazzarEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable balnazzar fight strategy", "+balnazzar") {}
    };

    class BalnazzarDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        BalnazzarDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable balnazzar fight strategy", "-balnazzar") {}
    };

    // Thunderclap ~8yd AoE — stay >10yd
    class BalnazzarMoveAwayFromThunderclapAction : public MoveAwayFromCreature
    {
    public:
        BalnazzarMoveAwayFromThunderclapAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "balnazzar move away from thunderclap", 10813, 10.0f) {}
    };

    // ── Undead: Magistrate Barthilas ──────────────────────────────────────────────
    class MagistrateBarthilasEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        MagistrateBarthilasEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable magistrate barthilas fight strategy", "+magistrate barthilas") {}
    };

    class MagistrateBarthilasDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        MagistrateBarthilasDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable magistrate barthilas fight strategy", "-magistrate barthilas") {}
    };

    // ── Undead: Maleki the Pallid ─────────────────────────────────────────────────
    class MalekithePallidEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        MalekithePallidEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable maleki the pallid fight strategy", "+maleki the pallid") {}
    };

    class MalekithePallidDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        MalekithePallidDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable maleki the pallid fight strategy", "-maleki the pallid") {}
    };

    // Frost Nova ~8yd AoE freeze — stay >10yd
    class MalekiMoveAwayFromFrostNovaAction : public MoveAwayFromCreature
    {
    public:
        MalekiMoveAwayFromFrostNovaAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "maleki move away from frost nova", 10438, 10.0f) {}
    };

    // ── Undead: Ramstein the Gorger ───────────────────────────────────────────────
    class RamsteintheGorgerEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        RamsteintheGorgerEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable ramstein the gorger fight strategy", "+ramstein the gorger") {}
    };

    class RamsteintheGorgerDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        RamsteintheGorgerDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable ramstein the gorger fight strategy", "-ramstein the gorger") {}
    };

    // Trample ~8yd AoE physical knockback — stay >10yd
    class RamsteinMoveAwayFromTrampleAction : public MoveAwayFromCreature
    {
    public:
        RamsteinMoveAwayFromTrampleAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "ramstein move away from trample", 10439, 10.0f) {}
    };

    // ── Undead: Baron Rivendare ───────────────────────────────────────────────────
    class BaronRivendareEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        BaronRivendareEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable baron rivendare fight strategy", "+baron rivendare") {}
    };

    class BaronRivendareDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        BaronRivendareDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable baron rivendare fight strategy", "-baron rivendare") {}
    };

    // Unholy Aura ~10yd persistent shadow AoE — stay >12yd
    class BaronMoveAwayFromUnholyAuraAction : public MoveAwayFromCreature
    {
    public:
        BaronMoveAwayFromUnholyAuraAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "baron move away from unholy aura", 10440, 12.0f) {}
    };
}
