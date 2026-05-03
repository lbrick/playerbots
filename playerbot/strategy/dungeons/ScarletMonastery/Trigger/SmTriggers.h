#pragma once
#include "playerbot/strategy/triggers/DungeonTriggers.h"

namespace ai
{
    // ── Instance enter/leave (Map ID 189 — all 4 wings) ─────────────────────────
    class ScarletMonasteryEnterDungeonTrigger : public EnterDungeonTrigger
    {
    public:
        ScarletMonasteryEnterDungeonTrigger(PlayerbotAI* ai)
            : EnterDungeonTrigger(ai, "enter scarlet monastery", "scarlet monastery", 189) {}
    };

    class ScarletMonasteryLeaveDungeonTrigger : public LeaveDungeonTrigger
    {
    public:
        ScarletMonasteryLeaveDungeonTrigger(PlayerbotAI* ai)
            : LeaveDungeonTrigger(ai, "leave scarlet monastery", "scarlet monastery", 189) {}
    };

    // ── Graveyard Wing ───────────────────────────────────────────────────────────

    // Interrogator Vishas (3983) — no positional mechanic
    class VishasStartFightTrigger : public StartBossFightTrigger
    {
    public:
        VishasStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start vishas fight", "vishas", 3983) {}
    };

    class VishasEndFightTrigger : public EndBossFightTrigger
    {
    public:
        VishasEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end vishas fight", "vishas", 3983) {}
    };

    // Fallen Champion (6488) — no positional mechanic
    class FallenChampionStartFightTrigger : public StartBossFightTrigger
    {
    public:
        FallenChampionStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start fallen champion fight", "fallen champion", 6488) {}
    };

    class FallenChampionEndFightTrigger : public EndBossFightTrigger
    {
    public:
        FallenChampionEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end fallen champion fight", "fallen champion", 6488) {}
    };

    // Ironspine (6489) — no positional mechanic
    class IronspineStartFightTrigger : public StartBossFightTrigger
    {
    public:
        IronspineStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start ironspine fight", "ironspine", 6489) {}
    };

    class IronspineEndFightTrigger : public EndBossFightTrigger
    {
    public:
        IronspineEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end ironspine fight", "ironspine", 6489) {}
    };

    // Bloodmage Thalnos (4543) — Shadowbolt Volley wide AoE ~22yd
    class ThalnosStartFightTrigger : public StartBossFightTrigger
    {
    public:
        ThalnosStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start thalnos fight", "thalnos", 4543) {}
    };

    class ThalnosEndFightTrigger : public EndBossFightTrigger
    {
    public:
        ThalnosEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end thalnos fight", "thalnos", 4543) {}
    };

    class ThalnsosShadowboltVolleyTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        ThalnsosShadowboltVolleyTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "thalnos shadowbolt volley", 4543, 22.0f, 3) {}
    };

    // ── Library Wing ─────────────────────────────────────────────────────────────

    // Houndmaster Loksey (3974) — no positional mechanic in v1
    class LokseyStartFightTrigger : public StartBossFightTrigger
    {
    public:
        LokseyStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start loksey fight", "loksey", 3974) {}
    };

    class LokseyEndFightTrigger : public EndBossFightTrigger
    {
    public:
        LokseyEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end loksey fight", "loksey", 3974) {}
    };

    // Arcanist Doan (6487) — Arcane Explosion ~30yd when low HP
    class DoanStartFightTrigger : public StartBossFightTrigger
    {
    public:
        DoanStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start doan fight", "doan", 6487) {}
    };

    class DoanEndFightTrigger : public EndBossFightTrigger
    {
    public:
        DoanEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end doan fight", "doan", 6487) {}
    };

    // 32yd gives a 2yd buffer beyond the ~30yd Arcane Explosion radius
    class DoanArcaneExplosionTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        DoanArcaneExplosionTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "doan arcane explosion", 6487, 32.0f, 3) {}
    };

    // ── Armory Wing ──────────────────────────────────────────────────────────────

    // Herod (3975) — Whirlwind melee AoE ~8yd
    class HerodStartFightTrigger : public StartBossFightTrigger
    {
    public:
        HerodStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start herod fight", "herod", 3975) {}
    };

    class HerodEndFightTrigger : public EndBossFightTrigger
    {
    public:
        HerodEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end herod fight", "herod", 3975) {}
    };

    class HerodWhirlwindTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        HerodWhirlwindTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "herod whirlwind", 3975, 10.0f, 3) {}
    };

    // ── Cathedral Wing ───────────────────────────────────────────────────────────

    // Scarlet Commander Mograine (3976) — no positional mechanic in v1
    class MograineStartFightTrigger : public StartBossFightTrigger
    {
    public:
        MograineStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start mograine fight", "mograine", 3976) {}
    };

    class MograineEndFightTrigger : public EndBossFightTrigger
    {
    public:
        MograineEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end mograine fight", "mograine", 3976) {}
    };

    // High Inquisitor Whitemane (3977) — no positional mechanic in v1
    class WhitemaneStartFightTrigger : public StartBossFightTrigger
    {
    public:
        WhitemaneStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start whitemane fight", "whitemane", 3977) {}
    };

    class WhitemaneEndFightTrigger : public EndBossFightTrigger
    {
    public:
        WhitemaneEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end whitemane fight", "whitemane", 3977) {}
    };

    // High Inquisitor Fairbanks (4542) — no positional mechanic
    class FairbanksStartFightTrigger : public StartBossFightTrigger
    {
    public:
        FairbanksStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start fairbanks fight", "fairbanks", 4542) {}
    };

    class FairbanksEndFightTrigger : public EndBossFightTrigger
    {
    public:
        FairbanksEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end fairbanks fight", "fairbanks", 4542) {}
    };

    // ── Whitemane interrupt — Heal (ID 12039, DB-verified) ──────────────────────
    class WhitemaneHealCastingTrigger : public TargetCastingSpellTrigger
    {
    public:
        WhitemaneHealCastingTrigger(PlayerbotAI* ai)
            : TargetCastingSpellTrigger(ai, "target casting whitemane heal", 12039) {}
    };
}
