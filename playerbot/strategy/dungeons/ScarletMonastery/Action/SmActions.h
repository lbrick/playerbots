#pragma once
#include "playerbot/strategy/actions/DungeonActions.h"

namespace ai
{
    // ── Instance strategy enable/disable ────────────────────────────────────────
    class ScarletMonasteryEnableStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        ScarletMonasteryEnableStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable scarlet monastery strategy", "+scarlet monastery") {}
    };

    class ScarletMonasteryDisableStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        ScarletMonasteryDisableStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable scarlet monastery strategy", "-scarlet monastery") {}
    };

    // ── Graveyard Wing ───────────────────────────────────────────────────────────

    class VishasEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        VishasEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable vishas fight strategy", "+vishas") {}
    };

    class VishasDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        VishasDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable vishas fight strategy", "-vishas") {}
    };

    class FallenChampionEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        FallenChampionEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable fallen champion fight strategy", "+fallen champion") {}
    };

    class FallenChampionDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        FallenChampionDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable fallen champion fight strategy", "-fallen champion") {}
    };

    class IronspineEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        IronspineEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable ironspine fight strategy", "+ironspine") {}
    };

    class IronspineDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        IronspineDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable ironspine fight strategy", "-ironspine") {}
    };

    class ThalnosEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        ThalnosEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable thalnos fight strategy", "+thalnos") {}
    };

    class ThalnosDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        ThalnosDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable thalnos fight strategy", "-thalnos") {}
    };

    // Shadowbolt Volley wide AoE avoidance — stay >22 yards
    class ThalnsosMoveAwayFromShadowboltVolleyAction : public MoveAwayFromCreature
    {
    public:
        ThalnsosMoveAwayFromShadowboltVolleyAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "thalnos move away from shadowbolt volley", 4543, 22.0f) {}
    };

    // ── Library Wing ─────────────────────────────────────────────────────────────

    class LokseyEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        LokseyEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable loksey fight strategy", "+loksey") {}
    };

    class LokseyDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        LokseyDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable loksey fight strategy", "-loksey") {}
    };

    class DoanEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        DoanEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable doan fight strategy", "+doan") {}
    };

    class DoanDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        DoanDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable doan fight strategy", "-doan") {}
    };

    // Arcane Explosion ~30yd avoidance — stay >32 yards when Doan is low HP
    class DoanMoveAwayFromArcaneExplosionAction : public MoveAwayFromCreature
    {
    public:
        DoanMoveAwayFromArcaneExplosionAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "doan move away from arcane explosion", 6487, 32.0f) {}
    };

    // ── Armory Wing ──────────────────────────────────────────────────────────────

    class HerodEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        HerodEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable herod fight strategy", "+herod") {}
    };

    class HerodDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        HerodDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable herod fight strategy", "-herod") {}
    };

    // Whirlwind melee AoE avoidance — stay >10 yards during spin
    class HerodMoveAwayFromWhirlwindAction : public MoveAwayFromCreature
    {
    public:
        HerodMoveAwayFromWhirlwindAction(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "herod move away from whirlwind", 3975, 10.0f) {}
    };

    // ── Cathedral Wing ───────────────────────────────────────────────────────────

    class MograineEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        MograineEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable mograine fight strategy", "+mograine") {}
    };

    class MograineDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        MograineDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable mograine fight strategy", "-mograine") {}
    };

    class WhitemaneEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        WhitemaneEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable whitemane fight strategy", "+whitemane") {}
    };

    class WhitemaneDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        WhitemaneDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable whitemane fight strategy", "-whitemane") {}
    };

    class FairbanksEnableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        FairbanksEnableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "enable fairbanks fight strategy", "+fairbanks") {}
    };

    class FairbanksDisableFightStrategyAction : public LoggedChangeAllStrategyAction
    {
    public:
        FairbanksDisableFightStrategyAction(PlayerbotAI* ai)
            : LoggedChangeAllStrategyAction(ai, "disable fairbanks fight strategy", "-fairbanks") {}
    };
}
