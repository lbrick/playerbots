#pragma once
#include "playerbot/strategy/actions/DungeonActions.h"

namespace ai
{
    // ── Instance strategy enable/disable ────────────────────────────────────────
    class GnomereganEnableStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        GnomereganEnableStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable gnomeregan strategy", "+gnomeregan") {}
    };

    class GnomereganDisableStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        GnomereganDisableStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable gnomeregan strategy", "-gnomeregan") {}
    };

    // ── Grubbis ───────────────────────────────────────────────────────────────────
    class GrubbisEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        GrubbisEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable grubbis fight strategy", "+grubbis") {}
    };

    class GrubbisDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        GrubbisDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable grubbis fight strategy", "-grubbis") {}
    };

    // ── Viscous Fallout ───────────────────────────────────────────────────────────
    class ViscousFalloutEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        ViscousFalloutEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable viscous fallout fight strategy", "+viscous fallout") {}
    };

    class ViscousFalloutDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        ViscousFalloutDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable viscous fallout fight strategy", "-viscous fallout") {}
    };

    // Acid Splash puddle avoidance — stay >10 yards
    class ViscousFalloutMoveAwayFromAcidSplashAction : public MoveAwayFromCreature
    {
    public:
        ViscousFalloutMoveAwayFromAcidSplashAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "viscous fallout move away from acid splash", 7079, 10.0f) {}
    };

    // ── Electrocutioner 6000 ──────────────────────────────────────────────────────
    class ElectrocutionerEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        ElectrocutionerEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable electrocutioner fight strategy", "+electrocutioner") {}
    };

    class ElectrocutionerDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        ElectrocutionerDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable electrocutioner fight strategy", "-electrocutioner") {}
    };

    // Lightning Arc chain avoidance — spread >12 yards to break chain
    class ElectrocutionerMoveAwayFromLightningArcAction : public MoveAwayFromCreature
    {
    public:
        ElectrocutionerMoveAwayFromLightningArcAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "electrocutioner move away from lightning arc", 6235, 12.0f) {}
    };

    // ── Crowd Pummeler 9-60 ───────────────────────────────────────────────────────
    class CrowdPummelerEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        CrowdPummelerEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable crowd pummeler fight strategy", "+crowd pummeler") {}
    };

    class CrowdPummelerDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        CrowdPummelerDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable crowd pummeler fight strategy", "-crowd pummeler") {}
    };

    // Arcing Smash frontal avoidance — stay >10 yards
    class CrowdPummelerMoveAwayFromArcingSmashAction : public MoveAwayFromCreature
    {
    public:
        CrowdPummelerMoveAwayFromArcingSmashAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "crowd pummeler move away from arcing smash", 6229, 10.0f) {}
    };

    // ── Mekgineer Thermaplugg ─────────────────────────────────────────────────────
    class ThermapluggEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        ThermapluggEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable thermaplugg fight strategy", "+thermaplugg") {}
    };

    class ThermapluggDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        ThermapluggDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable thermaplugg fight strategy", "-thermaplugg") {}
    };

    // Bomb spread — maintain >10 yards to reduce Leper Gnome Sapper splash overlap
    class ThermapluggMoveAwayFromBombsAction : public MoveAwayFromCreature
    {
    public:
        ThermapluggMoveAwayFromBombsAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "thermaplugg move away from bombs", 7800, 10.0f) {}
    };
}
