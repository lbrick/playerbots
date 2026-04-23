#pragma once
#include "playerbot/strategy/triggers/DungeonTriggers.h"

namespace ai
{
    // ── Instance enter/leave (Map ID 33) ────────────────────────────────────────
    class ShadowfangKeepEnterDungeonTrigger : public EnterDungeonTrigger
    {
    public:
        ShadowfangKeepEnterDungeonTrigger(PlayerbotAI* ai)
            : EnterDungeonTrigger(ai, "enter shadowfang keep", "shadowfang keep", 33) {}
    };

    class ShadowfangKeepLeaveDungeonTrigger : public LeaveDungeonTrigger
    {
    public:
        ShadowfangKeepLeaveDungeonTrigger(PlayerbotAI* ai)
            : LeaveDungeonTrigger(ai, "leave shadowfang keep", "shadowfang keep", 33) {}
    };

    // ── Commander Springvale interrupt — Holy Light rank 2 (ID 1026) ───────────
    class SpringvaleHealCastingTrigger : public TargetCastingSpellTrigger
    {
    public:
        SpringvaleHealCastingTrigger(PlayerbotAI* ai)
            : TargetCastingSpellTrigger(ai, "target casting springvale heal", 1026) {}
    };

    // ── Boss: Rethilgore (3914) ─────────────────────────────────────────────────
    class RethilgoreStartFightTrigger : public StartBossFightTrigger
    {
    public:
        RethilgoreStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start rethilgore fight", "rethilgore", 3914) {}
    };

    class RethilgoreEndFightTrigger : public EndBossFightTrigger
    {
    public:
        RethilgoreEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end rethilgore fight", "rethilgore", 3914) {}
    };

    // ── Boss: Razorclaw the Butcher (3886) ──────────────────────────────────────
    class RazorclawStartFightTrigger : public StartBossFightTrigger
    {
    public:
        RazorclawStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start razorclaw fight", "razorclaw", 3886) {}
    };

    class RazorclawEndFightTrigger : public EndBossFightTrigger
    {
    public:
        RazorclawEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end razorclaw fight", "razorclaw", 3886) {}
    };

    // ── Boss: Baron Silverlaine (3887) ──────────────────────────────────────────
    class SilverlaineStartFightTrigger : public StartBossFightTrigger
    {
    public:
        SilverlaineStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start silverlaine fight", "silverlaine", 3887) {}
    };

    class SilverlaineEndFightTrigger : public EndBossFightTrigger
    {
    public:
        SilverlaineEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end silverlaine fight", "silverlaine", 3887) {}
    };

    // ── Boss: Commander Springvale (4278) ───────────────────────────────────────
    class SpringvaleStartFightTrigger : public StartBossFightTrigger
    {
    public:
        SpringvaleStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start springvale fight", "springvale", 4278) {}
    };

    class SpringvaleEndFightTrigger : public EndBossFightTrigger
    {
    public:
        SpringvaleEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end springvale fight", "springvale", 4278) {}
    };

    // ── Boss: Odo the Blindwatcher (4279) ───────────────────────────────────────
    class OdoStartFightTrigger : public StartBossFightTrigger
    {
    public:
        OdoStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start odo fight", "odo", 4279) {}
    };

    class OdoEndFightTrigger : public EndBossFightTrigger
    {
    public:
        OdoEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end odo fight", "odo", 4279) {}
    };

    // ── Boss: Fenrus the Devourer (4274) ────────────────────────────────────────
    class FenrusStartFightTrigger : public StartBossFightTrigger
    {
    public:
        FenrusStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start fenrus fight", "fenrus", 4274) {}
    };

    class FenrusEndFightTrigger : public EndBossFightTrigger
    {
    public:
        FenrusEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end fenrus fight", "fenrus", 4274) {}
    };

    // ── Boss: Wolf Master Nandos (3927) ─────────────────────────────────────────
    class NandosStartFightTrigger : public StartBossFightTrigger
    {
    public:
        NandosStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start nandos fight", "nandos", 3927) {}
    };

    class NandosEndFightTrigger : public EndBossFightTrigger
    {
    public:
        NandosEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end nandos fight", "nandos", 3927) {}
    };

    // ── Boss: Archmage Arugal (4275) ────────────────────────────────────────────
    class ArugalStartFightTrigger : public StartBossFightTrigger
    {
    public:
        ArugalStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start arugal fight", "arugal", 4275) {}
    };

    class ArugalEndFightTrigger : public EndBossFightTrigger
    {
    public:
        ArugalEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end arugal fight", "arugal", 4275) {}
    };
}
