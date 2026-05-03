#pragma once
#include "playerbot/strategy/triggers/DungeonTriggers.h"

namespace ai
{
    // ── Instance enter/leave (Map ID 329) ───────────────────────────────────────
    class StratholmeEnterDungeonTrigger : public EnterDungeonTrigger
    {
    public:
        StratholmeEnterDungeonTrigger(PlayerbotAI* ai)
            : EnterDungeonTrigger(ai, "enter stratholme", "stratholme", 329) {}
    };

    class StratholmeLeaveDungeonTrigger : public LeaveDungeonTrigger
    {
    public:
        StratholmeLeaveDungeonTrigger(PlayerbotAI* ai)
            : LeaveDungeonTrigger(ai, "leave stratholme", "stratholme", 329) {}
    };

    // ── Scarlet: Hearthsinger Forresten (16779) — no positional AoE ─────────────
    class HearthsingerForrestenStartFightTrigger : public StartBossFightTrigger
    {
    public:
        HearthsingerForrestenStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start hearthsinger forresten fight", "hearthsinger forresten", 16779) {}
    };

    class HearthsingerForrestenEndFightTrigger : public EndBossFightTrigger
    {
    public:
        HearthsingerForrestenEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end hearthsinger forresten fight", "hearthsinger forresten", 16779) {}
    };

    // ── Scarlet: Timmy the Cruel (10808) — no radial AoE ────────────────────────
    class TimmytheCruelStartFightTrigger : public StartBossFightTrigger
    {
    public:
        TimmytheCruelStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start timmy the cruel fight", "timmy the cruel", 10808) {}
    };

    class TimmytheCruelEndFightTrigger : public EndBossFightTrigger
    {
    public:
        TimmytheCruelEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end timmy the cruel fight", "timmy the cruel", 10808) {}
    };

    // ── Scarlet: Cannon Master Willey (10811) — cannon GO deferred; start/end only
    class CannonMasterWilleyStartFightTrigger : public StartBossFightTrigger
    {
    public:
        CannonMasterWilleyStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start cannon master willey fight", "cannon master willey", 10811) {}
    };

    class CannonMasterWilleyEndFightTrigger : public EndBossFightTrigger
    {
    public:
        CannonMasterWilleyEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end cannon master willey fight", "cannon master willey", 10811) {}
    };

    // ── Scarlet: Archivist Galford (10812) — Flame Buffet ~8yd AoE fire ─────────
    class ArchivistGalfordStartFightTrigger : public StartBossFightTrigger
    {
    public:
        ArchivistGalfordStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start archivist galford fight", "archivist galford", 10812) {}
    };

    class ArchivistGalfordEndFightTrigger : public EndBossFightTrigger
    {
    public:
        ArchivistGalfordEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end archivist galford fight", "archivist galford", 10812) {}
    };

    class GalfordFlamBuffetTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        GalfordFlamBuffetTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "galford flame buffet", 10812, 8.0f, 3) {}
    };

    // ── Scarlet: Balnazzar (10813) — Thunderclap ~8yd AoE ───────────────────────
    class BalnazzarStartFightTrigger : public StartBossFightTrigger
    {
    public:
        BalnazzarStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start balnazzar fight", "balnazzar", 10813) {}
    };

    class BalnazzarEndFightTrigger : public EndBossFightTrigger
    {
    public:
        BalnazzarEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end balnazzar fight", "balnazzar", 10813) {}
    };

    class BalnazzarThunderclapTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        BalnazzarThunderclapTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "balnazzar thunderclap", 10813, 8.0f, 3) {}
    };

    // ── Undead: Magistrate Barthilas (10435) — no radial AoE ────────────────────
    class MagistrateBarthilasStartFightTrigger : public StartBossFightTrigger
    {
    public:
        MagistrateBarthilasStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start magistrate barthilas fight", "magistrate barthilas", 10435) {}
    };

    class MagistrateBarthilasEndFightTrigger : public EndBossFightTrigger
    {
    public:
        MagistrateBarthilasEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end magistrate barthilas fight", "magistrate barthilas", 10435) {}
    };

    // ── Undead: Maleki the Pallid (10438) — Frost Nova ~8yd AoE freeze ──────────
    class MalekithePallidStartFightTrigger : public StartBossFightTrigger
    {
    public:
        MalekithePallidStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start maleki the pallid fight", "maleki the pallid", 10438) {}
    };

    class MalekithePallidEndFightTrigger : public EndBossFightTrigger
    {
    public:
        MalekithePallidEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end maleki the pallid fight", "maleki the pallid", 10438) {}
    };

    class MalekiFrostNovaTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        MalekiFrostNovaTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "maleki frost nova", 10438, 8.0f, 3) {}
    };

    // ── Undead: Ramstein the Gorger (10439) — Trample ~8yd AoE physical ─────────
    class RamsteintheGorgerStartFightTrigger : public StartBossFightTrigger
    {
    public:
        RamsteintheGorgerStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start ramstein the gorger fight", "ramstein the gorger", 10439) {}
    };

    class RamsteintheGorgerEndFightTrigger : public EndBossFightTrigger
    {
    public:
        RamsteintheGorgerEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end ramstein the gorger fight", "ramstein the gorger", 10439) {}
    };

    class RamsteinTrampleTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        RamsteinTrampleTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "ramstein trample", 10439, 8.0f, 3) {}
    };

    // ── Undead: Baron Rivendare (10440) — Unholy Aura ~10yd persistent shadow ───
    class BaronRivendareStartFightTrigger : public StartBossFightTrigger
    {
    public:
        BaronRivendareStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start baron rivendare fight", "baron rivendare", 10440) {}
    };

    class BaronRivendareEndFightTrigger : public EndBossFightTrigger
    {
    public:
        BaronRivendareEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end baron rivendare fight", "baron rivendare", 10440) {}
    };

    class BaronUnholyAuraTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        BaronUnholyAuraTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "baron unholy aura", 10440, 10.0f, 3) {}
    };
}
