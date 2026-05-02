#pragma once

#include "HealthTriggers.h"
#include "GenericTriggers.h"
#include "LootTriggers.h"
#include "GenericTriggers.h"
#include "LfgTriggers.h"
#include "PvpTriggers.h"
#include "RpgTriggers.h"
#include "TravelTriggers.h"
#include "RtiTriggers.h"
#include "CureTriggers.h"
#include "GuildTriggers.h"
#include "StuckTriggers.h"
#include "BotStateTriggers.h"
#include "PullTriggers.h"
#include "playerbot/strategy/raid/OnyxiasLair/Trigger/RaidOnyTriggers.h"
#include "playerbot/strategy/raid/MoltenCore/Trigger/RaidMcTriggers.h"
#include "playerbot/strategy/raid/BlackwingLair/Trigger/RaidBwlTriggers.h"
#include "playerbot/strategy/raid/Karazhan/Trigger/RaidKaraTriggers.h"
#include "playerbot/strategy/raid/Naxxramas/Trigger/RaidNaxxTriggers.h"
#include "playerbot/strategy/rpg/Trigger/NewRpgTriggers.h"
#include "GlyphTriggers.h"
#include "playerbot/strategy/dungeons/RazorfenDowns/Trigger/RfdTriggers.h"
#include "playerbot/strategy/dungeons/Uldaman/Trigger/UldaTriggers.h"
#include "playerbot/strategy/dungeons/ZulFarrak/Trigger/ZfTriggers.h"
#include "playerbot/strategy/dungeons/Maraudon/Trigger/MaraTriggers.h"
#include "playerbot/strategy/dungeons/TempleOfAtalHakkar/Trigger/StTriggers.h"
#include "playerbot/strategy/dungeons/BlackrockDepths/Trigger/BrdTriggers.h"
#include "playerbot/strategy/dungeons/BlackrockSpire/Trigger/BrsTriggers.h"
#include "WorldBuffTravelTriggers.h"

#ifdef GenerateBotTests
#include "../tests/TestTriggers.h"
#endif

namespace ai
{
    class TriggerContext : public NamedObjectContext<Trigger>
    {
    public:
        TriggerContext()
        {
            creators["return"] = [](PlayerbotAI* ai) { return new ReturnTrigger(ai); };
            creators["sit"] = [](PlayerbotAI* ai) { return new SitTrigger(ai); };
            creators["return to stay position"] = [](PlayerbotAI* ai) { return new ReturnToStayPositionTrigger(ai); };
            creators["return to pull position"] = [](PlayerbotAI* ai) { return new ReturnToPullPositionTrigger(ai); };
            creators["collision"] = [](PlayerbotAI* ai) { return new CollisionTrigger(ai); };

            creators["timer"] = [](PlayerbotAI* ai) { return new TimerTrigger(ai); };
            creators["random"] = [](PlayerbotAI* ai) { return new RandomTrigger(ai, "random", 20); };
            creators["seldom"] = [](PlayerbotAI* ai) { return new RandomTrigger(ai, "seldom", 300); };
            creators["often"] = [](PlayerbotAI* ai) { return new RandomTrigger(ai, "often", 5); };
            creators["very often"] = [](PlayerbotAI* ai) { return new TimeTrigger(ai, "very often", 5); };

            creators["target critical health"] = [](PlayerbotAI* ai) { return new TargetCriticalHealthTrigger(ai); };

            creators["critical health"] = [](PlayerbotAI* ai) { return new CriticalHealthTrigger(ai); };
            creators["low health"] = [](PlayerbotAI* ai) { return new LowHealthTrigger(ai); };
            creators["medium health"] = [](PlayerbotAI* ai) { return new MediumHealthTrigger(ai); };
            creators["almost full health"] = [](PlayerbotAI* ai) { return new AlmostFullHealthTrigger(ai); };

            creators["no mana"] = [](PlayerbotAI* ai) { return new NoManaTrigger(ai); };
            creators["low mana"] = [](PlayerbotAI* ai) { return new LowManaTrigger(ai); };
            creators["medium mana"] = [](PlayerbotAI* ai) { return new MediumManaTrigger(ai); };
            creators["high mana"] = [](PlayerbotAI* ai) { return new HighManaTrigger(ai); };
            creators["almost full mana"] = [](PlayerbotAI* ai) { return new AlmostFullManaTrigger(ai); };

            creators["party member critical health"] = [](PlayerbotAI* ai) { return new PartyMemberCriticalHealthTrigger(ai); };
            creators["party member low health"] = [](PlayerbotAI* ai) { return new PartyMemberLowHealthTrigger(ai); };
            creators["party member medium health"] = [](PlayerbotAI* ai) { return new PartyMemberMediumHealthTrigger(ai); };
            creators["party member almost full health"] = [](PlayerbotAI* ai) { return new PartyMemberAlmostFullHealthTrigger(ai); };

            creators["protect party member"] = [](PlayerbotAI* ai) { return new ProtectPartyMemberTrigger(ai); };

            creators["light rage available"] = [](PlayerbotAI* ai) { return new LightRageAvailableTrigger(ai); };
            creators["medium rage available"] = [](PlayerbotAI* ai) { return new MediumRageAvailableTrigger(ai); };
            creators["high rage available"] = [](PlayerbotAI* ai) { return new HighRageAvailableTrigger(ai); };

            creators["no energy available"] = [](PlayerbotAI* ai) { return new NoEnergyAvailableTrigger(ai); };
            creators["light energy available"] = [](PlayerbotAI* ai) { return new LightEnergyAvailableTrigger(ai); };
            creators["medium energy available"] = [](PlayerbotAI* ai) { return new MediumEnergyAvailableTrigger(ai); };
            creators["high energy available"] = [](PlayerbotAI* ai) { return new HighEnergyAvailableTrigger(ai); };

            creators["loot available"] = [](PlayerbotAI* ai) { return new LootAvailableTrigger(ai); };
            creators["no attackers"] = [](PlayerbotAI* ai) { return new NoAttackersTrigger(ai); };
            creators["no target"] = [](PlayerbotAI* ai) { return new NoTargetTrigger(ai); };
            creators["target in sight"] = [](PlayerbotAI* ai) { return new TargetInSightTrigger(ai); };
            creators["not dps target active"] = [](PlayerbotAI* ai) { return new NotDpsTargetActiveTrigger(ai); };
            creators["not dps aoe target active"] = [](PlayerbotAI* ai) { return new NotDpsAoeTargetActiveTrigger(ai); };
            creators["has nearest adds"] = [](PlayerbotAI* ai) { return new HasNearestAddsTrigger(ai); };
            creators["enemy player near"] = [](PlayerbotAI* ai) { return new EnemyPlayerNear(ai); };

            creators["combat start"] = [](PlayerbotAI* ai) { return new CombatStartTrigger(ai); };
            creators["combat end"] = [](PlayerbotAI* ai) { return new CombatEndTrigger(ai); };
            creators["death"] = [](PlayerbotAI* ai) { return new DeathTrigger(ai); };
            creators["resurrect"] = [](PlayerbotAI* ai) { return new ResurrectTrigger(ai); };

            creators["pull start"] = [](PlayerbotAI* ai) { return new PullStartTrigger(ai); };
            creators["pull end"] = [](PlayerbotAI* ai) { return new PullEndTrigger(ai); };

            creators["tank assist"] = [](PlayerbotAI* ai) { return new TankAssistTrigger(ai); };
            creators["lose aggro"] = [](PlayerbotAI* ai) { return new LoseAggroTrigger(ai); };
            creators["has aggro"] = [](PlayerbotAI* ai) { return new HasAggroTrigger(ai); };

            creators["ranged light aoe"] = [](PlayerbotAI* ai) { return new RangedLightAoeTrigger(ai); };
            creators["ranged medium aoe"] = [](PlayerbotAI* ai) { return new RangedMediumAoeTrigger(ai); };
            creators["ranged high aoe"] = [](PlayerbotAI* ai) { return new RangedHighAoeTrigger(ai); };
            creators["ranged very high aoe"] = [](PlayerbotAI* ai) { return new RangedVeryHighAoeTrigger(ai); };
            creators["melee light aoe"] = [](PlayerbotAI* ai) { return new RangedLightAoeTrigger(ai); };
            creators["melee medium aoe"] = [](PlayerbotAI* ai) { return new RangedMediumAoeTrigger(ai); };
            creators["melee high aoe"] = [](PlayerbotAI* ai) { return new RangedHighAoeTrigger(ai); };
            creators["melee very high aoe"] = [](PlayerbotAI* ai) { return new RangedVeryHighAoeTrigger(ai); };

            creators["has area debuff"] = [](PlayerbotAI* ai) { return new HasAreaDebuffTrigger(ai); };
            creators["has aura"] = [](PlayerbotAI* ai) { return new HasAuraTrigger(ai); };

            creators["potion cooldown"] = [](PlayerbotAI* ai) { return new PotionCooldownTrigger(ai); };

            creators["enemy out of melee"] = [](PlayerbotAI* ai) { return new EnemyOutOfMeleeTrigger(ai); };
            creators["enemy out of spell"] = [](PlayerbotAI* ai) { return new EnemyOutOfSpellRangeTrigger(ai); };
            creators["enemy too close for spell"] = [](PlayerbotAI* ai) { return new EnemyTooCloseForSpellTrigger(ai); };
            creators["enemy too close for shoot"] = [](PlayerbotAI* ai) { return new EnemyTooCloseForShootTrigger(ai); };
            creators["enemy too close for melee"] = [](PlayerbotAI* ai) { return new EnemyTooCloseForMeleeTrigger(ai); };
            creators["enemy is close"] = [](PlayerbotAI* ai) { return new EnemyIsCloseTrigger(ai); };
            creators["party member to heal out of spell range"] = [](PlayerbotAI* ai) { return new PartyMemberToHealOutOfSpellRangeTrigger(ai); };
            creators["enemy fifteen yards"] = [](PlayerbotAI* ai) { return new EnemyInRangeTrigger(ai, "enemy fifteen yards", 15.0f); };
            creators["enemy ten yards"] = [](PlayerbotAI* ai) { return new EnemyInRangeTrigger(ai, "enemy ten yards", 10.0f); };
            creators["enemy five yards"] = [](PlayerbotAI* ai) { return new EnemyInRangeTrigger(ai, "enemy five yards", 5.0f); };
            creators["wait for attack safe distance"] = [](PlayerbotAI* ai) { return new WaitForAttackSafeDistanceTrigger(ai); };
            creators["enemy player ten yards"] = [](PlayerbotAI* ai) { return new EnemyInRangeTrigger(ai, "enemy player ten yards", 10.0f, true); };
            creators["combo points available"] = [](PlayerbotAI* ai) { return new ComboPointsAvailableTrigger(ai); };
            creators["multiple attackers"] = [](PlayerbotAI* ai) { return new MultipleAttackersTrigger(ai); };
            creators["high threat"] = [](PlayerbotAI* ai) { return new HighThreatTrigger(ai); };
            creators["medium threat"] = [](PlayerbotAI* ai) { return new MediumThreatTrigger(ai); };
            creators["some threat"] = [](PlayerbotAI* ai) { return new SomeThreatTrigger(ai); };
            creators["no threat"] = [](PlayerbotAI* ai) { return new NoThreatTrigger(ai); };
            creators["dead"] = [](PlayerbotAI* ai) { return new DeadTrigger(ai); };
            creators["corpse near"] = [](PlayerbotAI* ai) { return new CorpseNearTrigger(ai); };
            creators["party member dead"] = [](PlayerbotAI* ai) { return new PartyMemberDeadTrigger(ai); };
            creators["no pet"] = [](PlayerbotAI* ai) { return new NoPetTrigger(ai); };
            creators["has attackers"] = [](PlayerbotAI* ai) { return new HasAttackersTrigger(ai); };
            creators["no possible targets"] = [](PlayerbotAI* ai) { return new NoPossibleTargetsTrigger(ai); };
            creators["possible adds"] = [](PlayerbotAI* ai) { return new PossibleAddsTrigger(ai); };
            creators["panic"] = [](PlayerbotAI* ai) { return new PanicTrigger(ai); };
            creators["outnumbered"] = [](PlayerbotAI* ai) { return new OutNumberedTrigger(ai); };
            creators["behind target"] = [](PlayerbotAI* ai) { return new IsBehindTargetTrigger(ai); };
            creators["not behind target"] = [](PlayerbotAI* ai) { return new IsNotBehindTargetTrigger(ai); };
            creators["not facing target"] = [](PlayerbotAI* ai) { return new IsNotFacingTargetTrigger(ai); };
            creators["far from master"] = [](PlayerbotAI* ai) { return new FarFromMasterTrigger(ai); };
            creators["not near master"] = [](PlayerbotAI* ai) { return new NotNearMasterTrigger(ai); };
            creators["out of react range"] = [](PlayerbotAI* ai) { return new OutOfReactRangeTrigger(ai); };
            creators["out of free move range"] = [](PlayerbotAI* ai) { return new OutOfFreeMoveRangeTrigger(ai); };
            creators["update follow"] = [](PlayerbotAI* ai) { return new UpdateFollowTrigger(ai); };
            creators["stop follow"] = [](PlayerbotAI* ai) { return new StopFollowTrigger(ai); };

            // Register freefollow triggers
            creators["wander far"] = [](PlayerbotAI* ai) { return new WanderFarTrigger(ai); };
            creators["wander medium"] = [](PlayerbotAI* ai) { return new WanderMediumTrigger(ai); };
            creators["wander near"] = [](PlayerbotAI* ai) { return new WanderNearTrigger(ai); };

            creators["far from loot target"] = [](PlayerbotAI* ai) { return new FarFromCurrentLootTrigger(ai); };
            creators["can loot"] = [](PlayerbotAI* ai) { return new CanLootTrigger(ai); };
            creators["swimming"] = [](PlayerbotAI* ai) { return new IsSwimmingTrigger(ai); };
            creators["target changed"] = [](PlayerbotAI* ai) { return new TargetChangedTrigger(ai); };

            creators["critical aoe heal"] = [](PlayerbotAI* ai) { return new AoeHealTrigger(ai, "critical aoe heal", "critical", 2); };
            creators["low aoe heal"] = [](PlayerbotAI* ai) { return new AoeHealTrigger(ai, "low aoe heal", "low", 2); };
            creators["medium aoe heal"] = [](PlayerbotAI* ai) { return new AoeHealTrigger(ai, "medium aoe heal", "medium", 2); };
            creators["invalid target"] = [](PlayerbotAI* ai) { return new InvalidTargetTrigger(ai); };
            creators["lfg proposal active"] = [](PlayerbotAI* ai) { return new LfgProposalActiveTrigger(ai); };

            creators["unknown dungeon"] = [](PlayerbotAI* ai) { return new UnknownDungeonTrigger(ai); };

            creators["random bot update"] = [](PlayerbotAI* ai) { return new RandomBotUpdateTrigger(ai); };
            creators["no non bot players around"] = [](PlayerbotAI* ai) { return new NoNonBotPlayersAroundTrigger(ai); };
            creators["new player nearby"] = [](PlayerbotAI* ai) { return new NewPlayerNearbyTrigger(ai); };
            creators["no rpg target"] = [](PlayerbotAI* ai) { return new NoRpgTargetTrigger(ai); };
            creators["has rpg target"] = [](PlayerbotAI* ai) { return new HasRpgTargetTrigger(ai); };
            creators["far from rpg target"] = [](PlayerbotAI* ai) { return new FarFromRpgTargetTrigger(ai); };
            creators["near rpg target"] = [](PlayerbotAI* ai) { return new NearRpgTargetTrigger(ai); };
            creators["no rti target"] = [](PlayerbotAI* ai) { return new NoRtiTrigger(ai); };

            creators["give food"] = [](PlayerbotAI* ai) { return new GiveFoodTrigger(ai); };
            creators["give water"] = [](PlayerbotAI* ai) { return new GiveWaterTrigger(ai); };

            creators["bg waiting"] = [](PlayerbotAI* ai) { return new BgWaitingTrigger(ai); };
            creators["bg active"] = [](PlayerbotAI* ai) { return new BgActiveTrigger(ai); };
            creators["bg ended"] = [](PlayerbotAI* ai) { return new BgEndedTrigger(ai); };
            creators["bg invite active"] = [](PlayerbotAI* ai) { return new BgInviteActiveTrigger(ai); };
            creators["player has no flag"] = [](PlayerbotAI* ai) { return new PlayerHasNoFlag(ai); };
            creators["player has flag"] = [](PlayerbotAI* ai) { return new PlayerHasFlag(ai); };
            creators["team has flag"] = [](PlayerbotAI* ai) { return new TeamHasFlag(ai); };
            creators["enemy team has flag"] = [](PlayerbotAI* ai) { return new EnemyTeamHasFlag(ai); };
            creators["enemy flagcarrier near"] = [](PlayerbotAI* ai) { return new EnemyFlagCarrierNear(ai); };
            creators["in battleground"] = [](PlayerbotAI* ai) { return new PlayerIsInBattleground(ai); };
            creators["in battleground without flag"] = [](PlayerbotAI* ai) { return new PlayerIsInBattlegroundWithoutFlag(ai); };
            creators["wants in bg"] = [](PlayerbotAI* ai) { return new PlayerWantsInBattlegroundTrigger(ai); };
            creators["use trinket"] = [](PlayerbotAI* ai) { return new UseTrinketTrigger(ai); };
            creators["has blessing of salvation"] = [](PlayerbotAI* ai) { return new HasBlessingOfSalvationTrigger(ai); };
            creators["has greater blessing of salvation"] = [](PlayerbotAI* ai) { return new HasGreaterBlessingOfSalvationTrigger(ai); };
            creators["target of attacker"] = [](PlayerbotAI* ai) { return new TargetOfAttacker(ai); };
            creators["target of attacker close"] = [](PlayerbotAI* ai) { return new TargetOfAttackerClose(ai); };
            creators["target of fear cast"] = [](PlayerbotAI* ai) { return new TargetOfFearCastTrigger(ai); };
            creators["heal target full health"] = [](PlayerbotAI* ai) { return new HealTargetFullHealthTrigger(ai); };
            creators["dispel enrage"] = [](PlayerbotAI* ai) { return new DispelEnrageOnTargetTrigger(ai); };
            creators["has poison debuff"] = [](PlayerbotAI* ai) { return new HasPoisonDebuffTrigger(ai); };
            creators["at war"] = [](PlayerbotAI* ai) { return new AtWarTrigger(ai); };

            creators["mounted"] = [](PlayerbotAI* ai) { return new IsMountedTrigger(ai); };
            creators["rooted"] = [](PlayerbotAI* ai) { return new RootedTrigger(ai); };
            creators["party member rooted"] = [](PlayerbotAI* ai) { return new PartyMemberRootedTrigger(ai); };
            creators["feared"] = [](PlayerbotAI* ai) { return new FearedTrigger(ai); };
            creators["charmed"] = [](PlayerbotAI* ai) { return new CharmedTrigger(ai); };
            creators["stunned"] = [](PlayerbotAI* ai) { return new StunnedTrigger(ai); };

            // move to/enter dark portal if near
            creators["near dark portal"] = [](PlayerbotAI* ai) { return new NearDarkPortalTrigger(ai); };
            creators["at dark portal azeroth"] = [](PlayerbotAI* ai) { return new AtDarkPortalAzerothTrigger(ai); };
            creators["at dark portal outland"] = [](PlayerbotAI* ai) { return new AtDarkPortalOutlandTrigger(ai); };

            creators["vehicle near"] = [](PlayerbotAI* ai) { return new VehicleNearTrigger(ai); };
            creators["in vehicle"] = [](PlayerbotAI* ai) { return new InVehicleTrigger(ai); };

            creators["need world buff"] = [](PlayerbotAI* ai) { return new NeedWorldBuffTrigger(ai); };

            // World Buff Travel triggers
            creators["world buff travel zone reached"] = [](PlayerbotAI* ai) { return new WorldBuffTravelZoneReachedTrigger(ai); };
            creators["world buff travel need move"] = [](PlayerbotAI* ai) { return new WorldBuffTravelNeedMoveTrigger(ai); };
            creators["world buff travel portal step"] = [](PlayerbotAI* ai) { return new WorldBuffTravelPortalStepTrigger(ai); };
            creators["world buff travel use portal"] = [](PlayerbotAI* ai) { return new WorldBuffTravelUsePortalTrigger(ai); };
            creators["world buff travel done"] = [](PlayerbotAI* ai) { return new WorldBuffTravelDoneTrigger(ai); };
            creators["world buff travel dm buffed"] = [](PlayerbotAI* ai) { return new WorldBuffTravelDMBuffedTrigger(ai); };
            creators["world buff travel dm exited"] = [](PlayerbotAI* ai) { return new WorldBuffTravelDMExitedTrigger(ai); };
            creators["world buff travel dm portal cast"] = [](PlayerbotAI* ai) { return new WorldBuffTravelDMPortalCastTrigger(ai); };
            creators["world buff travel dm portal use"] = [](PlayerbotAI* ai) { return new WorldBuffTravelDMPortalUseTrigger(ai); };

            creators["falling"] = [](PlayerbotAI* ai) { return new IsFallingTrigger(ai); };
            creators["falling far"] = [](PlayerbotAI* ai) { return new IsFallingFarTrigger(ai); };
            creators["move stuck"] = [](PlayerbotAI* ai) { return new MoveStuckTrigger(ai); };
            creators["move long stuck"] = [](PlayerbotAI* ai) { return new MoveLongStuckTrigger(ai); };
            creators["combat stuck"] = [](PlayerbotAI* ai) { return new CombatStuckTrigger(ai); };
            creators["combat long stuck"] = [](PlayerbotAI* ai) { return new CombatLongStuckTrigger(ai); };
            creators["leader is afk"] = [](PlayerbotAI* ai) { return new LeaderIsAfkTrigger(ai); };

            creators["petition signed"] = [](PlayerbotAI* ai) { return new PetitionTurnInTrigger(ai); };
            creators["buy tabard"] = [](PlayerbotAI* ai) { return new BuyTabardTrigger(ai); };
            creators["leave large guild"] = [](PlayerbotAI* ai) { return new LeaveLargeGuildTrigger(ai); };
            creators["in pvp"] = [](PlayerbotAI* ai) { return new InPvpTrigger(ai); };
            creators["in pve"] = [](PlayerbotAI* ai) { return new InPveTrigger(ai); };
            creators["in raid fight"] = [](PlayerbotAI* ai) { return new InRaidFightTrigger(ai); };

            creators["val"] = [](PlayerbotAI* ai) { return new ValueTrigger(ai); };

            creators["go grind status"] = [](PlayerbotAI* ai) { return new NewRpgStatusTrigger(ai, RPG_GO_GRIND); };
            creators["go camp status"] = [](PlayerbotAI* ai) { return new NewRpgStatusTrigger(ai, RPG_GO_CAMP); };
            creators["wander random status"] = [](PlayerbotAI* ai) { return new NewRpgStatusTrigger(ai, RPG_WANDER_RANDOM); };
            creators["wander npc status"] = [](PlayerbotAI* ai) { return new NewRpgStatusTrigger(ai, RPG_WANDER_NPC); };
            creators["do quest status"] = [](PlayerbotAI* ai) { return new NewRpgStatusTrigger(ai, RPG_DO_QUEST); };
            creators["travel flight status"] = [](PlayerbotAI* ai) { return new NewRpgStatusTrigger(ai, RPG_TRAVEL_FLIGHT); };
            creators["change zone status"] = [](PlayerbotAI* ai) { return new NewRpgStatusTrigger(ai, RPG_CHANGE_ZONE); };
            creators["rpg"] = [](PlayerbotAI* ai) { return new RpgTrigger(ai); };
            creators["rpg wander"] = [](PlayerbotAI* ai) { return new RpgWanderTrigger(ai); };
            creators["rpg taxi"] = [](PlayerbotAI* ai) { return new RpgTaxiTrigger(ai); };
            creators["rpg discover"] = [](PlayerbotAI* ai) { return new RpgDiscoverTrigger(ai); };
            creators["rpg start quest"] = [](PlayerbotAI* ai) { return new RpgStartQuestTrigger(ai); };
            creators["rpg end quest"] = [](PlayerbotAI* ai) { return new RpgEndQuestTrigger(ai); };
            creators["rpg repeat quest"] = [](PlayerbotAI* ai) { return new RpgRepeatQuestTrigger(ai); };
            creators["rpg buy"] = [](PlayerbotAI* ai) { return new RpgBuyTrigger(ai); };
            creators["rpg sell"] = [](PlayerbotAI* ai) { return new RpgSellTrigger(ai); };
            creators["rpg ah sell"] = [](PlayerbotAI* ai) { return new RpgAHSellTrigger(ai); };
            creators["rpg ah buy"] = [](PlayerbotAI* ai) { return new RpgAHBuyTrigger(ai); };
            creators["rpg get mail"] = [](PlayerbotAI* ai) { return new RpgGetMailTrigger(ai); };
            creators["rpg repair"] = [](PlayerbotAI* ai) { return new RpgRepairTrigger(ai); };
            creators["rpg train"] = [](PlayerbotAI* ai) { return new RpgTrainTrigger(ai); };
            creators["rpg heal"] = [](PlayerbotAI* ai) { return new RpgHealTrigger(ai); };
            creators["rpg home bind"] = [](PlayerbotAI* ai) { return new RpgHomeBindTrigger(ai); };
            creators["rpg queue bg"] = [](PlayerbotAI* ai) { return new RpgQueueBGTrigger(ai); };
            creators["rpg buy petition"] = [](PlayerbotAI* ai) { return new RpgBuyPetitionTrigger(ai); };
            creators["rpg use"] = [](PlayerbotAI* ai) { return new RpgUseTrigger(ai); };
            creators["rpg quest use"] = [](PlayerbotAI* ai) { return new RpgQuestUseTrigger(ai); };
            creators["rpg ai chat"] = [](PlayerbotAI* ai) { return new RpgAIChatTrigger(ai); };
            creators["rpg spell"] = [](PlayerbotAI* ai) { return new RpgSpellTrigger(ai); };
            creators["rpg spell click"] = [](PlayerbotAI* ai) { return new RpgSpellClickTrigger(ai); };
            creators["rpg craft"] = [](PlayerbotAI* ai) { return new RpgCraftTrigger(ai); };
            creators["rpg trade useful"] = [](PlayerbotAI* ai) { return new RpgTradeUsefulTrigger(ai); };
            creators["rpg enchant"] = [](PlayerbotAI* ai) { return new RpgEnchantTrigger(ai); };
            creators["rpg duel"] = [](PlayerbotAI* ai) { return new RpgDuelTrigger(ai); };
            creators["rpg item"] = [](PlayerbotAI* ai) { return new RpgItemTrigger(ai); };
            creators["rpg gossip talk"] = [](PlayerbotAI* ai) { return new RpgGossipTalkTrigger(ai); };

            creators["random jump"] = [](PlayerbotAI* ai) { return new RandomJumpTrigger(ai); };
            creators["rtsc jump active"] = [](PlayerbotAI* ai) { return new RtscJumpTrigger(ai); };

            creators["apply glyphs"] = [](PlayerbotAI* ai) { return new ApplyGlyphTrigger(ai); };

            // racials
            creators["berserking"] = [](PlayerbotAI* ai) { return new BerserkingTrigger(ai); };
            creators["blood fury"] = [](PlayerbotAI* ai) { return new BloodFuryTrigger(ai); };
            creators["cannibalize"] = [](PlayerbotAI* ai) { return new CannibalizeTrigger(ai); };
            creators["will of the forsaken"] = [](PlayerbotAI* ai) { return new WOtFTrigger(ai); };
            creators["stoneform"] = [](PlayerbotAI* ai) { return new StoneformTrigger(ai); };
            creators["shadowmeld"] = [](PlayerbotAI* ai) { return new ShadowmeldTrigger(ai); };
            creators["mana tap"] = [](PlayerbotAI* ai) { return new ManaTapTrigger(ai); };
            creators["arcane torrent"] = [](PlayerbotAI* ai) { return new ArcanetorrentTrigger(ai); };
            creators["war stomp"] = [](PlayerbotAI* ai) { return new WarStompTrigger(ai); };
            creators["perception"] = [](PlayerbotAI* ai) { return new PerceptionTrigger(ai); };

            // Dungeon Triggers
            creators["enter razorfen downs"] = [](PlayerbotAI* ai) { return new RazorfenDownsEnterDungeonTrigger(ai); };
            creators["leave razorfen downs"] = [](PlayerbotAI* ai) { return new RazorfenDownsLeaveDungeonTrigger(ai); };
            creators["start tuten'kash fight"] = [](PlayerbotAI* ai) { return new TutenkashStartFightTrigger(ai); };
            creators["end tuten'kash fight"] = [](PlayerbotAI* ai) { return new TutenkashEndFightTrigger(ai); };
            creators["start mordresh fire eye fight"] = [](PlayerbotAI* ai) { return new MordreshStartFightTrigger(ai); };
            creators["end mordresh fire eye fight"] = [](PlayerbotAI* ai) { return new MordreshEndFightTrigger(ai); };
            creators["mordresh fire nova"] = [](PlayerbotAI* ai) { return new MordreshFireNovaTrigger(ai); };
            creators["start glutton fight"] = [](PlayerbotAI* ai) { return new GluttonStartFightTrigger(ai); };
            creators["end glutton fight"] = [](PlayerbotAI* ai) { return new GluttonEndFightTrigger(ai); };
            creators["start amnennar the coldbringer fight"] = [](PlayerbotAI* ai) { return new AmnennarStartFightTrigger(ai); };
            creators["end amnennar the coldbringer fight"] = [](PlayerbotAI* ai) { return new AmnennarEndFightTrigger(ai); };
            creators["amnennar frost nova"] = [](PlayerbotAI* ai) { return new AmnennarFrostNovaTrigger(ai); };

            creators["enter uldaman"] = [](PlayerbotAI* ai) { return new UldamanEnterDungeonTrigger(ai); };
            creators["leave uldaman"] = [](PlayerbotAI* ai) { return new UldamanLeaveDungeonTrigger(ai); };
            creators["start revelosh fight"] = [](PlayerbotAI* ai) { return new ReveloshStartFightTrigger(ai); };
            creators["end revelosh fight"] = [](PlayerbotAI* ai) { return new ReveloshEndFightTrigger(ai); };
            creators["start baelog fight"] = [](PlayerbotAI* ai) { return new BaelogStartFightTrigger(ai); };
            creators["end baelog fight"] = [](PlayerbotAI* ai) { return new BaelogEndFightTrigger(ai); };
            creators["start ironaya fight"] = [](PlayerbotAI* ai) { return new IronayaStartFightTrigger(ai); };
            creators["end ironaya fight"] = [](PlayerbotAI* ai) { return new IronayaEndFightTrigger(ai); };
            creators["ironaya war stomp"] = [](PlayerbotAI* ai) { return new IronayaWarStompTrigger(ai); };
            creators["start obsidian sentinel fight"] = [](PlayerbotAI* ai) { return new ObsidianSentinelStartFightTrigger(ai); };
            creators["end obsidian sentinel fight"] = [](PlayerbotAI* ai) { return new ObsidianSentinelEndFightTrigger(ai); };
            creators["start ancient stone keeper fight"] = [](PlayerbotAI* ai) { return new AncientStoneKeeperStartFightTrigger(ai); };
            creators["end ancient stone keeper fight"] = [](PlayerbotAI* ai) { return new AncientStoneKeeperEndFightTrigger(ai); };
            creators["ancient stone keeper war stomp"] = [](PlayerbotAI* ai) { return new AncientStoneKeeperWarStompTrigger(ai); };
            creators["start galgann firehammer fight"] = [](PlayerbotAI* ai) { return new GalgannFirehammerStartFightTrigger(ai); };
            creators["end galgann firehammer fight"] = [](PlayerbotAI* ai) { return new GalgannFirehammerEndFightTrigger(ai); };
            creators["galgann fire nova"] = [](PlayerbotAI* ai) { return new GalgannFireNovaTrigger(ai); };
            creators["start grimlok fight"] = [](PlayerbotAI* ai) { return new GrimlokStartFightTrigger(ai); };
            creators["end grimlok fight"] = [](PlayerbotAI* ai) { return new GrimlokEndFightTrigger(ai); };
            creators["grimlok war stomp"] = [](PlayerbotAI* ai) { return new GrimlokWarStompTrigger(ai); };
            creators["start archaedas fight"] = [](PlayerbotAI* ai) { return new ArchaedasStartFightTrigger(ai); };
            creators["end archaedas fight"] = [](PlayerbotAI* ai) { return new ArchaedasEndFightTrigger(ai); };
            creators["archaedas earth tremor"] = [](PlayerbotAI* ai) { return new ArchaedasEarthTremorTrigger(ai); };

            creators["enter zul'farrak"] = [](PlayerbotAI* ai) { return new ZulFarrakEnterDungeonTrigger(ai); };
            creators["leave zul'farrak"] = [](PlayerbotAI* ai) { return new ZulFarrakLeaveDungeonTrigger(ai); };
            creators["start theka the martyr fight"] = [](PlayerbotAI* ai) { return new ThekaStartFightTrigger(ai); };
            creators["end theka the martyr fight"] = [](PlayerbotAI* ai) { return new ThekaEndFightTrigger(ai); };
            creators["start witch doctor zum'rah fight"] = [](PlayerbotAI* ai) { return new ZumrahStartFightTrigger(ai); };
            creators["end witch doctor zum'rah fight"] = [](PlayerbotAI* ai) { return new ZumrahEndFightTrigger(ai); };
            creators["start antu'sul fight"] = [](PlayerbotAI* ai) { return new AntusulStartFightTrigger(ai); };
            creators["end antu'sul fight"] = [](PlayerbotAI* ai) { return new AntusulEndFightTrigger(ai); };
            creators["start shadowpriest sezz'ziz fight"] = [](PlayerbotAI* ai) { return new SezzizStartFightTrigger(ai); };
            creators["end shadowpriest sezz'ziz fight"] = [](PlayerbotAI* ai) { return new SezzizEndFightTrigger(ai); };
            creators["start sergeant bly fight"] = [](PlayerbotAI* ai) { return new SergeantBlyStartFightTrigger(ai); };
            creators["end sergeant bly fight"] = [](PlayerbotAI* ai) { return new SergeantBlyEndFightTrigger(ai); };
            creators["start gahz'rilla fight"] = [](PlayerbotAI* ai) { return new GahzrillaStartFightTrigger(ai); };
            creators["end gahz'rilla fight"] = [](PlayerbotAI* ai) { return new GahzrillaEndFightTrigger(ai); };
            creators["gahz'rilla freeze"] = [](PlayerbotAI* ai) { return new GahzrillaFreezeTrigger(ai); };
            creators["start chief ukorz sandscalp fight"] = [](PlayerbotAI* ai) { return new ChiefUkorzStartFightTrigger(ai); };
            creators["end chief ukorz sandscalp fight"] = [](PlayerbotAI* ai) { return new ChiefUkorzEndFightTrigger(ai); };

            creators["enter maraudon"] = [](PlayerbotAI* ai) { return new MaraudonEnterDungeonTrigger(ai); };
            creators["leave maraudon"] = [](PlayerbotAI* ai) { return new MaraudonLeaveDungeonTrigger(ai); };
            creators["start noxxion fight"] = [](PlayerbotAI* ai) { return new NoxxionStartFightTrigger(ai); };
            creators["end noxxion fight"] = [](PlayerbotAI* ai) { return new NoxxionEndFightTrigger(ai); };
            creators["noxxion noxious fumes"] = [](PlayerbotAI* ai) { return new NoxxionNoxiousFumesTrigger(ai); };
            creators["start razorlash fight"] = [](PlayerbotAI* ai) { return new RazorlashStartFightTrigger(ai); };
            creators["end razorlash fight"] = [](PlayerbotAI* ai) { return new RazorlashEndFightTrigger(ai); };
            creators["start lord vyletongue fight"] = [](PlayerbotAI* ai) { return new LordVyletongueStartFightTrigger(ai); };
            creators["end lord vyletongue fight"] = [](PlayerbotAI* ai) { return new LordVyletongueEndFightTrigger(ai); };
            creators["start celebras the cursed fight"] = [](PlayerbotAI* ai) { return new CelebrasStartFightTrigger(ai); };
            creators["end celebras the cursed fight"] = [](PlayerbotAI* ai) { return new CelebrasEndFightTrigger(ai); };
            creators["start landslide fight"] = [](PlayerbotAI* ai) { return new LandslideStartFightTrigger(ai); };
            creators["end landslide fight"] = [](PlayerbotAI* ai) { return new LandslideEndFightTrigger(ai); };
            creators["start tinkerer gizlock fight"] = [](PlayerbotAI* ai) { return new GizlockStartFightTrigger(ai); };
            creators["end tinkerer gizlock fight"] = [](PlayerbotAI* ai) { return new GizlockEndFightTrigger(ai); };
            creators["gizlock smoke bomb"] = [](PlayerbotAI* ai) { return new GizlockSmokeBombTrigger(ai); };
            creators["start rotgrip fight"] = [](PlayerbotAI* ai) { return new RotgripStartFightTrigger(ai); };
            creators["end rotgrip fight"] = [](PlayerbotAI* ai) { return new RotgripEndFightTrigger(ai); };
            creators["start princess theradras fight"] = [](PlayerbotAI* ai) { return new TheradrasStartFightTrigger(ai); };
            creators["end princess theradras fight"] = [](PlayerbotAI* ai) { return new TheradrasEndFightTrigger(ai); };
            creators["theradras dust field"] = [](PlayerbotAI* ai) { return new TheradrasDustFieldTrigger(ai); };

            creators["enter temple of atal'hakkar"] = [](PlayerbotAI* ai) { return new TempleOfAtalHakkarEnterDungeonTrigger(ai); };
            creators["leave temple of atal'hakkar"] = [](PlayerbotAI* ai) { return new TempleOfAtalHakkarLeaveDungeonTrigger(ai); };
            creators["start zolo fight"] = [](PlayerbotAI* ai) { return new ZoloStartFightTrigger(ai); };
            creators["end zolo fight"] = [](PlayerbotAI* ai) { return new ZoloEndFightTrigger(ai); };
            creators["start hukku fight"] = [](PlayerbotAI* ai) { return new HukkuStartFightTrigger(ai); };
            creators["end hukku fight"] = [](PlayerbotAI* ai) { return new HukkuEndFightTrigger(ai); };
            creators["start gasher fight"] = [](PlayerbotAI* ai) { return new GasherStartFightTrigger(ai); };
            creators["end gasher fight"] = [](PlayerbotAI* ai) { return new GasherEndFightTrigger(ai); };
            creators["start loro fight"] = [](PlayerbotAI* ai) { return new LoroStartFightTrigger(ai); };
            creators["end loro fight"] = [](PlayerbotAI* ai) { return new LoroEndFightTrigger(ai); };
            creators["start mijan fight"] = [](PlayerbotAI* ai) { return new MijanStartFightTrigger(ai); };
            creators["end mijan fight"] = [](PlayerbotAI* ai) { return new MijanEndFightTrigger(ai); };
            creators["start zul'lor fight"] = [](PlayerbotAI* ai) { return new ZulLorStartFightTrigger(ai); };
            creators["end zul'lor fight"] = [](PlayerbotAI* ai) { return new ZulLorEndFightTrigger(ai); };
            creators["start jammal'an the prophet fight"] = [](PlayerbotAI* ai) { return new JammalanStartFightTrigger(ai); };
            creators["end jammal'an the prophet fight"] = [](PlayerbotAI* ai) { return new JammalanEndFightTrigger(ai); };
            creators["start ogom the wretched fight"] = [](PlayerbotAI* ai) { return new OgomStartFightTrigger(ai); };
            creators["end ogom the wretched fight"] = [](PlayerbotAI* ai) { return new OgomEndFightTrigger(ai); };
            creators["start morphaz fight"] = [](PlayerbotAI* ai) { return new MorphazStartFightTrigger(ai); };
            creators["end morphaz fight"] = [](PlayerbotAI* ai) { return new MorphazEndFightTrigger(ai); };
            creators["start hazzas fight"] = [](PlayerbotAI* ai) { return new HazzasStartFightTrigger(ai); };
            creators["end hazzas fight"] = [](PlayerbotAI* ai) { return new HazzasEndFightTrigger(ai); };
            creators["start shade of eranikus fight"] = [](PlayerbotAI* ai) { return new ShadeOfEranikusStartFightTrigger(ai); };
            creators["end shade of eranikus fight"] = [](PlayerbotAI* ai) { return new ShadeOfEranikusEndFightTrigger(ai); };
            creators["eranikus war stomp"] = [](PlayerbotAI* ai) { return new EranikusWarStompTrigger(ai); };
            creators["start avatar of hakkar fight"] = [](PlayerbotAI* ai) { return new AvatarOfHakkarStartFightTrigger(ai); };
            creators["end avatar of hakkar fight"] = [](PlayerbotAI* ai) { return new AvatarOfHakkarEndFightTrigger(ai); };

            creators["enter blackrock depths"] = [](PlayerbotAI* ai) { return new BlackrockDepthsEnterDungeonTrigger(ai); };
            creators["leave blackrock depths"] = [](PlayerbotAI* ai) { return new BlackrockDepthsLeaveDungeonTrigger(ai); };
            creators["start gorosh fight"] = [](PlayerbotAI* ai) { return new GoroshStartFightTrigger(ai); };
            creators["end gorosh fight"] = [](PlayerbotAI* ai) { return new GoroshEndFightTrigger(ai); };
            creators["start grizzle fight"] = [](PlayerbotAI* ai) { return new GrizzleStartFightTrigger(ai); };
            creators["end grizzle fight"] = [](PlayerbotAI* ai) { return new GrizzleEndFightTrigger(ai); };
            creators["grizzle ground tremor"] = [](PlayerbotAI* ai) { return new GrizzleGroundTremorTrigger(ai); };
            creators["start eviscerator fight"] = [](PlayerbotAI* ai) { return new EviscerratorStartFightTrigger(ai); };
            creators["end eviscerator fight"] = [](PlayerbotAI* ai) { return new EviscerratorEndFightTrigger(ai); };
            creators["eviscerator whirlwind"] = [](PlayerbotAI* ai) { return new EviscerratorWhirlwindTrigger(ai); };
            creators["start ok'thor the breaker fight"] = [](PlayerbotAI* ai) { return new OkthorStartFightTrigger(ai); };
            creators["end ok'thor the breaker fight"] = [](PlayerbotAI* ai) { return new OkthorEndFightTrigger(ai); };
            creators["ok'thor war stomp"] = [](PlayerbotAI* ai) { return new OkthorWarStompTrigger(ai); };
            creators["start anub'shiah fight"] = [](PlayerbotAI* ai) { return new AnubshiahStartFightTrigger(ai); };
            creators["end anub'shiah fight"] = [](PlayerbotAI* ai) { return new AnubshiahEndFightTrigger(ai); };
            creators["start hedrum the creeper fight"] = [](PlayerbotAI* ai) { return new HedrumStartFightTrigger(ai); };
            creators["end hedrum the creeper fight"] = [](PlayerbotAI* ai) { return new HedrumEndFightTrigger(ai); };
            creators["start high interrogator gerstahn fight"] = [](PlayerbotAI* ai) { return new GerstanStartFightTrigger(ai); };
            creators["end high interrogator gerstahn fight"] = [](PlayerbotAI* ai) { return new GerstanEndFightTrigger(ai); };
            creators["start lord roccor fight"] = [](PlayerbotAI* ai) { return new LordRoccorStartFightTrigger(ai); };
            creators["end lord roccor fight"] = [](PlayerbotAI* ai) { return new LordRoccorEndFightTrigger(ai); };
            creators["lord roccor earthquake"] = [](PlayerbotAI* ai) { return new LordRoccorEarthquakeTrigger(ai); };
            creators["start houndmaster grebmar fight"] = [](PlayerbotAI* ai) { return new GrebmarStartFightTrigger(ai); };
            creators["end houndmaster grebmar fight"] = [](PlayerbotAI* ai) { return new GrebmarEndFightTrigger(ai); };
            creators["start pyromancer loregrain fight"] = [](PlayerbotAI* ai) { return new PyromancerLoregrainStartFightTrigger(ai); };
            creators["end pyromancer loregrain fight"] = [](PlayerbotAI* ai) { return new PyromancerLoregrainEndFightTrigger(ai); };
            creators["pyromancer fire nova"] = [](PlayerbotAI* ai) { return new PyromancerFireNovaTrigger(ai); };
            creators["start warder stilgiss fight"] = [](PlayerbotAI* ai) { return new WarderStiglissStartFightTrigger(ai); };
            creators["end warder stilgiss fight"] = [](PlayerbotAI* ai) { return new WarderStiglissEndFightTrigger(ai); };
            creators["warder stilgiss frost nova"] = [](PlayerbotAI* ai) { return new WarderStiglissFrostNovaTrigger(ai); };
            creators["start verek fight"] = [](PlayerbotAI* ai) { return new VerekStartFightTrigger(ai); };
            creators["end verek fight"] = [](PlayerbotAI* ai) { return new VerekEndFightTrigger(ai); };
            creators["start plugger spazzring fight"] = [](PlayerbotAI* ai) { return new PluggerSpazzringStartFightTrigger(ai); };
            creators["end plugger spazzring fight"] = [](PlayerbotAI* ai) { return new PluggerSpazzringEndFightTrigger(ai); };
            creators["start phalanx fight"] = [](PlayerbotAI* ai) { return new PhalanxStartFightTrigger(ai); };
            creators["end phalanx fight"] = [](PlayerbotAI* ai) { return new PhalanxEndFightTrigger(ai); };
            creators["start ambassador flamelash fight"] = [](PlayerbotAI* ai) { return new FlamelashStartFightTrigger(ai); };
            creators["end ambassador flamelash fight"] = [](PlayerbotAI* ai) { return new FlamelashEndFightTrigger(ai); };
            creators["start the seven fight"] = [](PlayerbotAI* ai) { return new TheSevenStartFightTrigger(ai); };
            creators["end the seven fight"] = [](PlayerbotAI* ai) { return new TheSevenEndFightTrigger(ai); };
            creators["start golem lord argelmach fight"] = [](PlayerbotAI* ai) { return new ArgelmachStartFightTrigger(ai); };
            creators["end golem lord argelmach fight"] = [](PlayerbotAI* ai) { return new ArgelmachEndFightTrigger(ai); };
            creators["argelmach static field"] = [](PlayerbotAI* ai) { return new ArgelmachStaticFieldTrigger(ai); };
            creators["start bael'gar fight"] = [](PlayerbotAI* ai) { return new BaelGarStartFightTrigger(ai); };
            creators["end bael'gar fight"] = [](PlayerbotAI* ai) { return new BaelGarEndFightTrigger(ai); };
            creators["bael'gar fire nova"] = [](PlayerbotAI* ai) { return new BaelGarFireNovaTrigger(ai); };
            creators["start general angerforge fight"] = [](PlayerbotAI* ai) { return new GeneralAngerforgeStartFightTrigger(ai); };
            creators["end general angerforge fight"] = [](PlayerbotAI* ai) { return new GeneralAngerforgeEndFightTrigger(ai); };
            creators["start magmus fight"] = [](PlayerbotAI* ai) { return new MagmusStartFightTrigger(ai); };
            creators["end magmus fight"] = [](PlayerbotAI* ai) { return new MagmusEndFightTrigger(ai); };
            creators["magmus war stomp"] = [](PlayerbotAI* ai) { return new MagmusWarStompTrigger(ai); };
            creators["start emperor dagran thaurissan fight"] = [](PlayerbotAI* ai) { return new EmperorThaurissanStartFightTrigger(ai); };
            creators["end emperor dagran thaurissan fight"] = [](PlayerbotAI* ai) { return new EmperorThaurissanEndFightTrigger(ai); };

            // Blackrock Spire (LBRS + UBRS, map 229)
            creators["enter blackrock spire"] = [](PlayerbotAI* ai) { return new BlackrockSpireEnterDungeonTrigger(ai); };
            creators["leave blackrock spire"] = [](PlayerbotAI* ai) { return new BlackrockSpireLeaveDungeonTrigger(ai); };
            creators["start highlord omokk fight"] = [](PlayerbotAI* ai) { return new HigdlordOmokkStartFightTrigger(ai); };
            creators["end highlord omokk fight"] = [](PlayerbotAI* ai) { return new HigdlordOmokkEndFightTrigger(ai); };
            creators["omokk war stomp"] = [](PlayerbotAI* ai) { return new OmokkWarStompTrigger(ai); };
            creators["start shadow hunter vosh'gajin fight"] = [](PlayerbotAI* ai) { return new VoshgajinStartFightTrigger(ai); };
            creators["end shadow hunter vosh'gajin fight"] = [](PlayerbotAI* ai) { return new VoshgajinEndFightTrigger(ai); };
            creators["start war master voone fight"] = [](PlayerbotAI* ai) { return new WarMasterVooneStartFightTrigger(ai); };
            creators["end war master voone fight"] = [](PlayerbotAI* ai) { return new WarMasterVooneEndFightTrigger(ai); };
            creators["start mother smolderweb fight"] = [](PlayerbotAI* ai) { return new MotherSmolderwebStartFightTrigger(ai); };
            creators["end mother smolderweb fight"] = [](PlayerbotAI* ai) { return new MotherSmolderwebEndFightTrigger(ai); };
            creators["start urok doomhowl fight"] = [](PlayerbotAI* ai) { return new UrokDoomhowlStartFightTrigger(ai); };
            creators["end urok doomhowl fight"] = [](PlayerbotAI* ai) { return new UrokDoomhowlEndFightTrigger(ai); };
            creators["urok war stomp"] = [](PlayerbotAI* ai) { return new UrokWarStompTrigger(ai); };
            creators["start quartermaster zigris fight"] = [](PlayerbotAI* ai) { return new QuartermasterZigrisStartFightTrigger(ai); };
            creators["end quartermaster zigris fight"] = [](PlayerbotAI* ai) { return new QuartermasterZigrisEndFightTrigger(ai); };
            creators["start halycon fight"] = [](PlayerbotAI* ai) { return new HalyconStartFightTrigger(ai); };
            creators["end halycon fight"] = [](PlayerbotAI* ai) { return new HalyconEndFightTrigger(ai); };
            creators["start overlord wyrmthalak fight"] = [](PlayerbotAI* ai) { return new OverlordWyrmthalakStartFightTrigger(ai); };
            creators["end overlord wyrmthalak fight"] = [](PlayerbotAI* ai) { return new OverlordWyrmthalakEndFightTrigger(ai); };
            creators["wyrmthalak blizzard"] = [](PlayerbotAI* ai) { return new WyrmthalakBlizzardTrigger(ai); };
            creators["start pyroguard emberseer fight"] = [](PlayerbotAI* ai) { return new PyroguardEmberseerStartFightTrigger(ai); };
            creators["end pyroguard emberseer fight"] = [](PlayerbotAI* ai) { return new PyroguardEmberseerEndFightTrigger(ai); };
            creators["emberseer ignite"] = [](PlayerbotAI* ai) { return new EmberseerIgniteTrigger(ai); };
            creators["start solakar flamewreath fight"] = [](PlayerbotAI* ai) { return new SolakarFlamewreathStartFightTrigger(ai); };
            creators["end solakar flamewreath fight"] = [](PlayerbotAI* ai) { return new SolakarFlamewreathEndFightTrigger(ai); };
            creators["start jed runewatcher fight"] = [](PlayerbotAI* ai) { return new JedRunewatcherStartFightTrigger(ai); };
            creators["end jed runewatcher fight"] = [](PlayerbotAI* ai) { return new JedRunewatcherEndFightTrigger(ai); };
            creators["start the beast fight"] = [](PlayerbotAI* ai) { return new TheBeastStartFightTrigger(ai); };
            creators["end the beast fight"] = [](PlayerbotAI* ai) { return new TheBeastEndFightTrigger(ai); };
            creators["the beast conflagration"] = [](PlayerbotAI* ai) { return new TheBeastConflagrationTrigger(ai); };
            creators["start general drakkisath fight"] = [](PlayerbotAI* ai) { return new GeneralDrakkisathStartFightTrigger(ai); };
            creators["end general drakkisath fight"] = [](PlayerbotAI* ai) { return new GeneralDrakkisathEndFightTrigger(ai); };
            creators["drakkisath conflagration"] = [](PlayerbotAI* ai) { return new DrakkisathConflagrationTrigger(ai); };

            creators["enter onyxia's lair"] = [](PlayerbotAI* ai) { return new OnyxiasLairEnterDungeonTrigger(ai); };
            creators["leave onyxia's lair"] = [](PlayerbotAI* ai) { return new OnyxiasLairLeaveDungeonTrigger(ai); };
            creators["enter molten core"] = [](PlayerbotAI* ai) { return new MoltenCoreEnterDungeonTrigger(ai); };
            creators["leave molten core"] = [](PlayerbotAI* ai) { return new MoltenCoreLeaveDungeonTrigger(ai); };
            creators["enter karazhan"] = [](PlayerbotAI* ai) { return new KarazhanEnterDungeonTrigger(ai); };
            creators["leave karazhan"] = [](PlayerbotAI* ai) { return new KarazhanLeaveDungeonTrigger(ai); };
            creators["enter naxxramas"] = [](PlayerbotAI* ai) { return new NaxxramasEnterDungeonTrigger(ai); };
            creators["leave naxxramas"] = [](PlayerbotAI* ai) { return new NaxxramasLeaveDungeonTrigger(ai); };
            creators["enter blackwing lair"] = [](PlayerbotAI* ai) { return new BlackwingLairEnterDungeonTrigger(ai); };
            creators["leave blackwing lair"] = [](PlayerbotAI* ai) { return new BlackwingLairLeaveDungeonTrigger(ai); };

            // Dungeon Boss Triggers
            creators["start onyxia fight"] = [](PlayerbotAI* ai) { return new OnyxiaStartFightTrigger(ai); };
            creators["end onyxia fight"] = [](PlayerbotAI* ai) { return new OnyxiaEndFightTrigger(ai); };

            creators["start magmadar fight"] = [](PlayerbotAI* ai) { return new MagmadarStartFightTrigger(ai); };
            creators["end magmadar fight"] = [](PlayerbotAI* ai) { return new MagmadarEndFightTrigger(ai); };
            creators["magmadar lava bomb"] = [](PlayerbotAI* ai) { return new MagmadarLavaBombTrigger(ai); };
            creators["magmadar too close"] = [](PlayerbotAI* ai) { return new MagmadarTooCloseTrigger(ai); };

            creators["fire protection potion ready"] = [](PlayerbotAI* ai) { return new FireProtectionPotionReadyTrigger(ai); };

            creators["mc rune in sight"] = [](PlayerbotAI* ai) { return new MCRuneInSightTrigger(ai); };
            creators["mc rune close"] = [](PlayerbotAI* ai) { return new MCRuneCloseTrigger(ai); };

            creators["suppression device need stealth"] = [](PlayerbotAI* ai) { return new SuppressionDeviceNeedStealthTrigger(ai); };
            creators["suppression device in sight"] = [](PlayerbotAI* ai) { return new SuppressionDeviceInSightTrigger(ai); };
            creators["suppression device close"] = [](PlayerbotAI* ai) { return new SuppressionDeviceCloseTrigger(ai); };

            creators["start netherspite fight"] = [](PlayerbotAI* ai) { return new NetherspiteStartFightTrigger(ai); };
            creators["end netherspite fight"] = [](PlayerbotAI* ai) { return new NetherspiteEndFightTrigger(ai); };
            creators["void zone too close"] = [](PlayerbotAI* ai) { return new VoidZoneTooCloseTrigger(ai); };
            creators["add nether portal - perseverence for tank"] = [](PlayerbotAI* ai) { return new NetherspiteBeamsCheatNeedRefreshTrigger(ai, 2); };
            creators["remove nether portal buffs from netherspite"] = [](PlayerbotAI* ai) { return new NetherspiteBeamsCheatNeedRefreshTrigger(ai); };
            creators["remove nether portal - dominance"] = [](PlayerbotAI* ai) { return new RemoveNetherPortalDominanceTrigger(ai); };
            creators["remove nether portal - perseverence"] = [](PlayerbotAI* ai) { return new RemoveNetherPortalPerseverenceTrigger(ai); };
            creators["remove nether portal - serenity"] = [](PlayerbotAI* ai) { return new RemoveNetherPortalSerenityTrigger(ai); };

            creators["start prince malchezaar fight"] = [](PlayerbotAI* ai) { return new PrinceMalchezaarStartFightTrigger(ai); };
            creators["end prince malchezaar fight"] = [](PlayerbotAI* ai) { return new PrinceMalchezaarEndFightTrigger(ai); };
            creators["netherspite infernal too close"] = [](PlayerbotAI* ai) { return new NetherspiteInfernalTooCloseTrigger(ai); };

            creators["start four horseman fight"] = [](PlayerbotAI* ai) { return new FourHorsemanStartFightTrigger(ai); };
            creators["end four horseman fight"] = [](PlayerbotAI* ai) { return new FourHorsemanEndFightTrigger(ai); };

            // Test framework triggers
#ifdef GenerateBotTests
            creators["test ready"] = [](PlayerbotAI* ai) { return new TestReadyTrigger(ai); };
#endif
        }
    };
};
