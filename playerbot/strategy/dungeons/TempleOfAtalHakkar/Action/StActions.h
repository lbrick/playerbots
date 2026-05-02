#pragma once
#include "playerbot/strategy/actions/DungeonActions.h"

namespace ai
{
    // ── Instance strategy enable/disable ────────────────────────────────────────
    class TempleOfAtalHakkarEnableStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        TempleOfAtalHakkarEnableStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable temple of atal'hakkar strategy", "+temple of atal'hakkar") {}
    };

    class TempleOfAtalHakkarDisableStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        TempleOfAtalHakkarDisableStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable temple of atal'hakkar strategy", "-temple of atal'hakkar") {}
    };

    // ── Zolo ──────────────────────────────────────────────────────────────────────
    class ZoloEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        ZoloEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable zolo fight strategy", "+zolo") {}
    };

    class ZoloDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        ZoloDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable zolo fight strategy", "-zolo") {}
    };

    // ── Hukku ─────────────────────────────────────────────────────────────────────
    class HukkuEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        HukkuEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable hukku fight strategy", "+hukku") {}
    };

    class HukkuDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        HukkuDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable hukku fight strategy", "-hukku") {}
    };

    // ── Gasher ────────────────────────────────────────────────────────────────────
    class GasherEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        GasherEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable gasher fight strategy", "+gasher") {}
    };

    class GasherDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        GasherDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable gasher fight strategy", "-gasher") {}
    };

    // ── Loro ──────────────────────────────────────────────────────────────────────
    class LoroEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        LoroEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable loro fight strategy", "+loro") {}
    };

    class LoroDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        LoroDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable loro fight strategy", "-loro") {}
    };

    // ── Mijan ─────────────────────────────────────────────────────────────────────
    class MijanEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        MijanEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable mijan fight strategy", "+mijan") {}
    };

    class MijanDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        MijanDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable mijan fight strategy", "-mijan") {}
    };

    // ── Zul'Lor ───────────────────────────────────────────────────────────────────
    class ZulLorEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        ZulLorEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable zul'lor fight strategy", "+zul'lor") {}
    };

    class ZulLorDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        ZulLorDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable zul'lor fight strategy", "-zul'lor") {}
    };

    // ── Jammal'an the Prophet ─────────────────────────────────────────────────────
    class JammalanEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        JammalanEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable jammal'an the prophet fight strategy", "+jammal'an the prophet") {}
    };

    class JammalanDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        JammalanDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable jammal'an the prophet fight strategy", "-jammal'an the prophet") {}
    };

    // ── Ogom the Wretched ─────────────────────────────────────────────────────────
    class OgomEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        OgomEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable ogom the wretched fight strategy", "+ogom the wretched") {}
    };

    class OgomDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        OgomDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable ogom the wretched fight strategy", "-ogom the wretched") {}
    };

    // ── Morphaz ───────────────────────────────────────────────────────────────────
    class MorphazEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        MorphazEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable morphaz fight strategy", "+morphaz") {}
    };

    class MorphazDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        MorphazDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable morphaz fight strategy", "-morphaz") {}
    };

    // ── Hazzas ────────────────────────────────────────────────────────────────────
    class HazzasEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        HazzasEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable hazzas fight strategy", "+hazzas") {}
    };

    class HazzasDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        HazzasDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable hazzas fight strategy", "-hazzas") {}
    };

    // ── Shade of Eranikus ─────────────────────────────────────────────────────────
    class ShadeOfEranikusEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        ShadeOfEranikusEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable shade of eranikus fight strategy", "+shade of eranikus") {}
    };

    class ShadeOfEranikusDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        ShadeOfEranikusDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable shade of eranikus fight strategy", "-shade of eranikus") {}
    };

    // War Stomp ~8yd AoE avoidance — stay >10 yards
    class EranikusMoveAwayFromWarStompAction : public MoveAwayFromCreature
    {
    public:
        EranikusMoveAwayFromWarStompAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "eranikus move away from war stomp", 5709, 10.0f) {}
    };

    // ── Avatar of Hakkar ──────────────────────────────────────────────────────────
    class AvatarOfHakkarEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        AvatarOfHakkarEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable avatar of hakkar fight strategy", "+avatar of hakkar") {}
    };

    class AvatarOfHakkarDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        AvatarOfHakkarDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable avatar of hakkar fight strategy", "-avatar of hakkar") {}
    };
}
