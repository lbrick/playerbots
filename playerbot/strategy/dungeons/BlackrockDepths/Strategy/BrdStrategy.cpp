#include "playerbot/playerbot.h"
#include "BrdStrategy.h"

using namespace ai;

// ── BlackrockDepthsDungeonStrategy ────────────────────────────────────────────

void BlackrockDepthsDungeonStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Ring of Law champions
    triggers.push_back(new TriggerNode(
        "start gorosh fight",
        NextAction::array(0, new NextAction("enable gorosh fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start grizzle fight",
        NextAction::array(0, new NextAction("enable grizzle fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start eviscerator fight",
        NextAction::array(0, new NextAction("enable eviscerator fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start ok'thor the breaker fight",
        NextAction::array(0, new NextAction("enable ok'thor the breaker fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start anub'shiah fight",
        NextAction::array(0, new NextAction("enable anub'shiah fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start hedrum the creeper fight",
        NextAction::array(0, new NextAction("enable hedrum the creeper fight strategy", 100.0f), NULL)));

    // Main dungeon bosses
    triggers.push_back(new TriggerNode(
        "start high interrogator gerstahn fight",
        NextAction::array(0, new NextAction("enable high interrogator gerstahn fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start lord roccor fight",
        NextAction::array(0, new NextAction("enable lord roccor fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start houndmaster grebmar fight",
        NextAction::array(0, new NextAction("enable houndmaster grebmar fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start pyromancer loregrain fight",
        NextAction::array(0, new NextAction("enable pyromancer loregrain fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start warder stilgiss fight",
        NextAction::array(0, new NextAction("enable warder stilgiss fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start verek fight",
        NextAction::array(0, new NextAction("enable verek fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start plugger spazzring fight",
        NextAction::array(0, new NextAction("enable plugger spazzring fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start phalanx fight",
        NextAction::array(0, new NextAction("enable phalanx fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start ambassador flamelash fight",
        NextAction::array(0, new NextAction("enable ambassador flamelash fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start the seven fight",
        NextAction::array(0, new NextAction("enable the seven fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start golem lord argelmach fight",
        NextAction::array(0, new NextAction("enable golem lord argelmach fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start bael'gar fight",
        NextAction::array(0, new NextAction("enable bael'gar fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start general angerforge fight",
        NextAction::array(0, new NextAction("enable general angerforge fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start magmus fight",
        NextAction::array(0, new NextAction("enable magmus fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start emperor dagran thaurissan fight",
        NextAction::array(0, new NextAction("enable emperor dagran thaurissan fight strategy", 100.0f), NULL)));
}

void BlackrockDepthsDungeonStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Ring of Law champions
    triggers.push_back(new TriggerNode(
        "start gorosh fight",
        NextAction::array(0, new NextAction("enable gorosh fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start grizzle fight",
        NextAction::array(0, new NextAction("enable grizzle fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start eviscerator fight",
        NextAction::array(0, new NextAction("enable eviscerator fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start ok'thor the breaker fight",
        NextAction::array(0, new NextAction("enable ok'thor the breaker fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start anub'shiah fight",
        NextAction::array(0, new NextAction("enable anub'shiah fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start hedrum the creeper fight",
        NextAction::array(0, new NextAction("enable hedrum the creeper fight strategy", 100.0f), NULL)));

    // Main dungeon bosses
    triggers.push_back(new TriggerNode(
        "start high interrogator gerstahn fight",
        NextAction::array(0, new NextAction("enable high interrogator gerstahn fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start lord roccor fight",
        NextAction::array(0, new NextAction("enable lord roccor fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start houndmaster grebmar fight",
        NextAction::array(0, new NextAction("enable houndmaster grebmar fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start pyromancer loregrain fight",
        NextAction::array(0, new NextAction("enable pyromancer loregrain fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start warder stilgiss fight",
        NextAction::array(0, new NextAction("enable warder stilgiss fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start verek fight",
        NextAction::array(0, new NextAction("enable verek fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start plugger spazzring fight",
        NextAction::array(0, new NextAction("enable plugger spazzring fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start phalanx fight",
        NextAction::array(0, new NextAction("enable phalanx fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start ambassador flamelash fight",
        NextAction::array(0, new NextAction("enable ambassador flamelash fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start the seven fight",
        NextAction::array(0, new NextAction("enable the seven fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start golem lord argelmach fight",
        NextAction::array(0, new NextAction("enable golem lord argelmach fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start bael'gar fight",
        NextAction::array(0, new NextAction("enable bael'gar fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start general angerforge fight",
        NextAction::array(0, new NextAction("enable general angerforge fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start magmus fight",
        NextAction::array(0, new NextAction("enable magmus fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start emperor dagran thaurissan fight",
        NextAction::array(0, new NextAction("enable emperor dagran thaurissan fight strategy", 100.0f), NULL)));
}

// ── GoroshFightStrategy ───────────────────────────────────────────────────────

void GoroshFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end gorosh fight",
        NextAction::array(0, new NextAction("disable gorosh fight strategy", 100.0f), NULL)));
}

void GoroshFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end gorosh fight",
        NextAction::array(0, new NextAction("disable gorosh fight strategy", 100.0f), NULL)));
}

// ── GrizzleFightStrategy ──────────────────────────────────────────────────────

void GrizzleFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Ground Tremor ~10yd AoE — stay >12yd
    triggers.push_back(new TriggerNode(
        "grizzle ground tremor",
        NextAction::array(0, new NextAction("grizzle move away from ground tremor", ACTION_MOVE + 5), NULL)));
}

void GrizzleFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end grizzle fight",
        NextAction::array(0, new NextAction("disable grizzle fight strategy", 100.0f), NULL)));
}

void GrizzleFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end grizzle fight",
        NextAction::array(0, new NextAction("disable grizzle fight strategy", 100.0f), NULL)));
}

// ── EviscerratorFightStrategy ─────────────────────────────────────────────────

void EviscerratorFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Whirlwind ~8yd AoE — stay >10yd
    triggers.push_back(new TriggerNode(
        "eviscerator whirlwind",
        NextAction::array(0, new NextAction("eviscerator move away from whirlwind", ACTION_MOVE + 5), NULL)));
}

void EviscerratorFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end eviscerator fight",
        NextAction::array(0, new NextAction("disable eviscerator fight strategy", 100.0f), NULL)));
}

void EviscerratorFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end eviscerator fight",
        NextAction::array(0, new NextAction("disable eviscerator fight strategy", 100.0f), NULL)));
}

// ── OkthorTheBreakerFightStrategy ─────────────────────────────────────────────

void OkthorTheBreakerFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // War Stomp ~8yd AoE — stay >10yd
    triggers.push_back(new TriggerNode(
        "ok'thor war stomp",
        NextAction::array(0, new NextAction("ok'thor move away from war stomp", ACTION_MOVE + 5), NULL)));
}

void OkthorTheBreakerFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end ok'thor the breaker fight",
        NextAction::array(0, new NextAction("disable ok'thor the breaker fight strategy", 100.0f), NULL)));
}

void OkthorTheBreakerFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end ok'thor the breaker fight",
        NextAction::array(0, new NextAction("disable ok'thor the breaker fight strategy", 100.0f), NULL)));
}

// ── AnubshiahFightStrategy ────────────────────────────────────────────────────

void AnubshiahFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end anub'shiah fight",
        NextAction::array(0, new NextAction("disable anub'shiah fight strategy", 100.0f), NULL)));
}

void AnubshiahFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end anub'shiah fight",
        NextAction::array(0, new NextAction("disable anub'shiah fight strategy", 100.0f), NULL)));
}

// ── HedrumTheCreepFightStrategy ───────────────────────────────────────────────

void HedrumTheCreepFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end hedrum the creeper fight",
        NextAction::array(0, new NextAction("disable hedrum the creeper fight strategy", 100.0f), NULL)));
}

void HedrumTheCreepFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end hedrum the creeper fight",
        NextAction::array(0, new NextAction("disable hedrum the creeper fight strategy", 100.0f), NULL)));
}

// ── HighInterrogatorGerstanFightStrategy ──────────────────────────────────────

void HighInterrogatorGerstanFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "target casting gerstahn mana burn",
        NextAction::array(0, new NextAction("interrupt enemy cast", ACTION_HIGH + 5), NULL)));
}

void HighInterrogatorGerstanFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end high interrogator gerstahn fight",
        NextAction::array(0, new NextAction("disable high interrogator gerstahn fight strategy", 100.0f), NULL)));
}

void HighInterrogatorGerstanFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end high interrogator gerstahn fight",
        NextAction::array(0, new NextAction("disable high interrogator gerstahn fight strategy", 100.0f), NULL)));
}

// ── LordRoccorFightStrategy ───────────────────────────────────────────────────

void LordRoccorFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Earthquake ~10yd AoE — stay >12yd
    triggers.push_back(new TriggerNode(
        "lord roccor earthquake",
        NextAction::array(0, new NextAction("lord roccor move away from earthquake", ACTION_MOVE + 5), NULL)));
}

void LordRoccorFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end lord roccor fight",
        NextAction::array(0, new NextAction("disable lord roccor fight strategy", 100.0f), NULL)));
}

void LordRoccorFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end lord roccor fight",
        NextAction::array(0, new NextAction("disable lord roccor fight strategy", 100.0f), NULL)));
}

// ── HoundmasterGrebmarFightStrategy ──────────────────────────────────────────

void HoundmasterGrebmarFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end houndmaster grebmar fight",
        NextAction::array(0, new NextAction("disable houndmaster grebmar fight strategy", 100.0f), NULL)));
}

void HoundmasterGrebmarFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end houndmaster grebmar fight",
        NextAction::array(0, new NextAction("disable houndmaster grebmar fight strategy", 100.0f), NULL)));
}

// ── PyromancerLoregrainFightStrategy ──────────────────────────────────────────

void PyromancerLoregrainFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Fire Nova ~10yd AoE — stay >12yd
    triggers.push_back(new TriggerNode(
        "pyromancer fire nova",
        NextAction::array(0, new NextAction("pyromancer move away from fire nova", ACTION_MOVE + 5), NULL)));
}

void PyromancerLoregrainFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end pyromancer loregrain fight",
        NextAction::array(0, new NextAction("disable pyromancer loregrain fight strategy", 100.0f), NULL)));
}

void PyromancerLoregrainFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end pyromancer loregrain fight",
        NextAction::array(0, new NextAction("disable pyromancer loregrain fight strategy", 100.0f), NULL)));
}

// ── WarderStiglissFightStrategy ───────────────────────────────────────────────

void WarderStiglissFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Frost Nova ~8yd AoE — stay >10yd
    triggers.push_back(new TriggerNode(
        "warder stilgiss frost nova",
        NextAction::array(0, new NextAction("warder stilgiss move away from frost nova", ACTION_MOVE + 5), NULL)));
}

void WarderStiglissFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end warder stilgiss fight",
        NextAction::array(0, new NextAction("disable warder stilgiss fight strategy", 100.0f), NULL)));
}

void WarderStiglissFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end warder stilgiss fight",
        NextAction::array(0, new NextAction("disable warder stilgiss fight strategy", 100.0f), NULL)));
}

// ── VerekFightStrategy ────────────────────────────────────────────────────────

void VerekFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end verek fight",
        NextAction::array(0, new NextAction("disable verek fight strategy", 100.0f), NULL)));
}

void VerekFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end verek fight",
        NextAction::array(0, new NextAction("disable verek fight strategy", 100.0f), NULL)));
}

// ── PluggerSpazzringFightStrategy ─────────────────────────────────────────────

void PluggerSpazzringFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end plugger spazzring fight",
        NextAction::array(0, new NextAction("disable plugger spazzring fight strategy", 100.0f), NULL)));
}

void PluggerSpazzringFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end plugger spazzring fight",
        NextAction::array(0, new NextAction("disable plugger spazzring fight strategy", 100.0f), NULL)));
}

// ── PhalanxFightStrategy ──────────────────────────────────────────────────────

void PhalanxFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end phalanx fight",
        NextAction::array(0, new NextAction("disable phalanx fight strategy", 100.0f), NULL)));
}

void PhalanxFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end phalanx fight",
        NextAction::array(0, new NextAction("disable phalanx fight strategy", 100.0f), NULL)));
}

// ── AmbassadorFlamelashFightStrategy ──────────────────────────────────────────

void AmbassadorFlamelashFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end ambassador flamelash fight",
        NextAction::array(0, new NextAction("disable ambassador flamelash fight strategy", 100.0f), NULL)));
}

void AmbassadorFlamelashFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end ambassador flamelash fight",
        NextAction::array(0, new NextAction("disable ambassador flamelash fight strategy", 100.0f), NULL)));
}

// ── TheSevenFightStrategy ─────────────────────────────────────────────────────

void TheSevenFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end the seven fight",
        NextAction::array(0, new NextAction("disable the seven fight strategy", 100.0f), NULL)));
}

void TheSevenFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end the seven fight",
        NextAction::array(0, new NextAction("disable the seven fight strategy", 100.0f), NULL)));
}

// ── GolemLordArgelmachFightStrategy ───────────────────────────────────────────

void GolemLordArgelmachFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Static Field ~8yd AoE — stay >10yd
    triggers.push_back(new TriggerNode(
        "argelmach static field",
        NextAction::array(0, new NextAction("argelmach move away from static field", ACTION_MOVE + 5), NULL)));
}

void GolemLordArgelmachFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end golem lord argelmach fight",
        NextAction::array(0, new NextAction("disable golem lord argelmach fight strategy", 100.0f), NULL)));
}

void GolemLordArgelmachFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end golem lord argelmach fight",
        NextAction::array(0, new NextAction("disable golem lord argelmach fight strategy", 100.0f), NULL)));
}

// ── BaelGarFightStrategy ──────────────────────────────────────────────────────

void BaelGarFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Fire Nova ~10yd AoE — stay >12yd
    triggers.push_back(new TriggerNode(
        "bael'gar fire nova",
        NextAction::array(0, new NextAction("bael'gar move away from fire nova", ACTION_MOVE + 5), NULL)));
}

void BaelGarFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end bael'gar fight",
        NextAction::array(0, new NextAction("disable bael'gar fight strategy", 100.0f), NULL)));
}

void BaelGarFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end bael'gar fight",
        NextAction::array(0, new NextAction("disable bael'gar fight strategy", 100.0f), NULL)));
}

// ── GeneralAngerforgeFightStrategy ────────────────────────────────────────────

void GeneralAngerforgeFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end general angerforge fight",
        NextAction::array(0, new NextAction("disable general angerforge fight strategy", 100.0f), NULL)));
}

void GeneralAngerforgeFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end general angerforge fight",
        NextAction::array(0, new NextAction("disable general angerforge fight strategy", 100.0f), NULL)));
}

// ── MagmusFightStrategy ───────────────────────────────────────────────────────

void MagmusFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // War Stomp ~8yd AoE — stay >10yd
    triggers.push_back(new TriggerNode(
        "magmus war stomp",
        NextAction::array(0, new NextAction("magmus move away from war stomp", ACTION_MOVE + 5), NULL)));
}

void MagmusFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end magmus fight",
        NextAction::array(0, new NextAction("disable magmus fight strategy", 100.0f), NULL)));
}

void MagmusFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end magmus fight",
        NextAction::array(0, new NextAction("disable magmus fight strategy", 100.0f), NULL)));
}

// ── EmperorDagranThaurissanFightStrategy ──────────────────────────────────────

void EmperorDagranThaurissanFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end emperor dagran thaurissan fight",
        NextAction::array(0, new NextAction("disable emperor dagran thaurissan fight strategy", 100.0f), NULL)));
}

void EmperorDagranThaurissanFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end emperor dagran thaurissan fight",
        NextAction::array(0, new NextAction("disable emperor dagran thaurissan fight strategy", 100.0f), NULL)));
}
