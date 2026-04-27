#pragma once
#include "playerbot/strategy/triggers/DungeonTriggers.h"

namespace ai
{
    // ── Instance enter/leave (Map ID 90) ────────────────────────────────────────
    class GnomereganEnterDungeonTrigger : public EnterDungeonTrigger
    {
    public:
        GnomereganEnterDungeonTrigger(PlayerbotAI* ai)
            : EnterDungeonTrigger(ai, "enter gnomeregan", "gnomeregan", 90) {}
    };

    class GnomereganLeaveDungeonTrigger : public LeaveDungeonTrigger
    {
    public:
        GnomereganLeaveDungeonTrigger(PlayerbotAI* ai)
            : LeaveDungeonTrigger(ai, "leave gnomeregan", "gnomeregan", 90) {}
    };

    // ── Boss: Grubbis (7361) — simple melee, no positional mechanic ──────────────
    class GrubbisStartFightTrigger : public StartBossFightTrigger
    {
    public:
        GrubbisStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start grubbis fight", "grubbis", 7361) {}
    };

    class GrubbisEndFightTrigger : public EndBossFightTrigger
    {
    public:
        GrubbisEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end grubbis fight", "grubbis", 7361) {}
    };

    // ── Boss: Viscous Fallout (7079) — Acid Splash AoE puddle ~8yd ──────────────
    class ViscousFalloutStartFightTrigger : public StartBossFightTrigger
    {
    public:
        ViscousFalloutStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start viscous fallout fight", "viscous fallout", 7079) {}
    };

    class ViscousFalloutEndFightTrigger : public EndBossFightTrigger
    {
    public:
        ViscousFalloutEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end viscous fallout fight", "viscous fallout", 7079) {}
    };

    class ViscousFalloutAcidSplashTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        ViscousFalloutAcidSplashTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "viscous fallout acid splash", 7079, 10.0f, 3) {}
    };

    // ── Boss: Electrocutioner 6000 (6235) — Lightning Arc chain ~10yd ───────────
    class ElectrocutionerStartFightTrigger : public StartBossFightTrigger
    {
    public:
        ElectrocutionerStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start electrocutioner fight", "electrocutioner", 6235) {}
    };

    class ElectrocutionerEndFightTrigger : public EndBossFightTrigger
    {
    public:
        ElectrocutionerEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end electrocutioner fight", "electrocutioner", 6235) {}
    };

    class ElectrocutionerLightningArcTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        ElectrocutionerLightningArcTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "electrocutioner lightning arc", 6235, 12.0f, 3) {}
    };

    // ── Boss: Crowd Pummeler 9-60 (6229) — Arcing Smash frontal ~8yd ────────────
    class CrowdPummelerStartFightTrigger : public StartBossFightTrigger
    {
    public:
        CrowdPummelerStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start crowd pummeler fight", "crowd pummeler", 6229) {}
    };

    class CrowdPummelerEndFightTrigger : public EndBossFightTrigger
    {
    public:
        CrowdPummelerEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end crowd pummeler fight", "crowd pummeler", 6229) {}
    };

    class CrowdPummelerArcingSmashTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        CrowdPummelerArcingSmashTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "crowd pummeler arcing smash", 6229, 10.0f, 3) {}
    };

    // ── Boss: Mekgineer Thermaplugg (7800) — Leper Gnome bombs, spread ──────────
    class ThermapluggStartFightTrigger : public StartBossFightTrigger
    {
    public:
        ThermapluggStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start thermaplugg fight", "thermaplugg", 7800) {}
    };

    class ThermapluggEndFightTrigger : public EndBossFightTrigger
    {
    public:
        ThermapluggEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end thermaplugg fight", "thermaplugg", 7800) {}
    };

    class ThermapluggBombSpreadTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        ThermapluggBombSpreadTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "thermaplugg bomb spread", 7800, 10.0f, 3) {}
    };
}
