#pragma once
#include "playerbot/strategy/actions/DungeonActions.h"

namespace ai
{
    // ── Instance strategy enable/disable ────────────────────────────────────────
    class ShadowfangKeepEnableStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        ShadowfangKeepEnableStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable shadowfang keep strategy", "+shadowfang keep") {}
    };

    class ShadowfangKeepDisableStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        ShadowfangKeepDisableStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable shadowfang keep strategy", "-shadowfang keep") {}
    };

    // ── Rethilgore ───────────────────────────────────────────────────────────────
    class RethilgoreEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        RethilgoreEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable rethilgore fight strategy", "+rethilgore") {}
    };

    class RethilgoreDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        RethilgoreDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable rethilgore fight strategy", "-rethilgore") {}
    };

    // ── Razorclaw the Butcher ────────────────────────────────────────────────────
    class RazorclawEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        RazorclawEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable razorclaw fight strategy", "+razorclaw") {}
    };

    class RazorclawDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        RazorclawDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable razorclaw fight strategy", "-razorclaw") {}
    };

    // ── Baron Silverlaine ────────────────────────────────────────────────────────
    class SilverlaineEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        SilverlaineEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable silverlaine fight strategy", "+silverlaine") {}
    };

    class SilverlaineDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        SilverlaineDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable silverlaine fight strategy", "-silverlaine") {}
    };

    // ── Commander Springvale ────────────────────────────────────────────────────
    class SpringvaleEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        SpringvaleEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable springvale fight strategy", "+springvale") {}
    };

    class SpringvaleDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        SpringvaleDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable springvale fight strategy", "-springvale") {}
    };

    // ── Odo the Blindwatcher ────────────────────────────────────────────────────
    class OdoEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        OdoEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable odo fight strategy", "+odo") {}
    };

    class OdoDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        OdoDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable odo fight strategy", "-odo") {}
    };

    // ── Fenrus the Devourer ─────────────────────────────────────────────────────
    class FenrusEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        FenrusEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable fenrus fight strategy", "+fenrus") {}
    };

    class FenrusDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        FenrusDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable fenrus fight strategy", "-fenrus") {}
    };

    // ── Wolf Master Nandos ──────────────────────────────────────────────────────
    class NandosEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        NandosEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable nandos fight strategy", "+nandos") {}
    };

    class NandosDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        NandosDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable nandos fight strategy", "-nandos") {}
    };

    // ── Archmage Arugal ─────────────────────────────────────────────────────────
    class ArugalEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        ArugalEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable arugal fight strategy", "+arugal") {}
    };

    class ArugalDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        ArugalDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable arugal fight strategy", "-arugal") {}
    };
}
