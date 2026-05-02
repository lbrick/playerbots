#pragma once

#include "GenericActions.h"
#include "EmoteAction.h"
#include "AddLootAction.h"
#include "LootAction.h"
#include "AddLootAction.h"
#include "LootRollAction.h"
#include "StayActions.h"
#include "FollowActions.h"
#include "ChangeStrategyAction.h"
#include "ChooseTargetActions.h"
#include "SuggestWhatToDoAction.h"
#include "PositionAction.h"
#include "AttackAction.h"
#include "CheckMailAction.h"
#include "CheckValuesAction.h"
#include "ChooseRpgTargetAction.h"
#include "ChooseTravelTargetAction.h"
#include "DelayAction.h"
#include "GiveItemAction.h"
#include "GreetAction.h"
#include "ImbueAction.h"
#include "MovementActions.h"
#include "MoveToRpgTargetAction.h"
#include "MoveToTravelTargetAction.h"
#include "OutfitAction.h"
#include "RevealGatheringItemAction.h"
#include "SayAction.h"
#include "OutfitAction.h"
#include "RandomBotUpdateAction.h"
#include "RemoveAuraAction.h"
#include "RpgAction.h"
#include "TravelAction.h"
#include "RtiAction.h"
#include "BattleGroundTactics.h"
#include "CheckMountStateAction.h"
#include "ChangeTalentsAction.h"
#include "AutoLearnSpellAction.h"
#include "XpGainAction.h"
#include "HonorGainAction.h"
#include "InviteToGroupAction.h"
#include "LeaveGroupAction.h"
#include "ReleaseSpiritAction.h"
#include "CombatActions.h"
#include "WorldBuffAction.h"
#include "CastCustomSpellAction.h"
#include "BattleGroundJoinAction.h"
#include "DestroyItemAction.h"
#include "ResetInstancesAction.h"
#include "BuyAction.h"
#include "GuildCreateActions.h"
#include "GuildManagementActions.h"
#include "GuildAcceptAction.h"
#include "GuildAcceptQuestOrderAction.h"
#include "GuildShareItemAction.h"
#include "GuildShareAhBuyAction.h"
#include "RpgSubActions.h"
#include "VehicleActions.h"
#include "UseTrinketAction.h"
#include "BotStateActions.h"
#include "WaitForAttackAction.h"
#include "PullActions.h"
#include "ResetAiAction.h"
#include "ShareQuestAction.h"
#include "UpdateGearAction.h"
#include "SetAvoidAreaAction.h"
#include "GlyphAction.h"
#include "FishAction.h"
#include "AutoCompleteQuestAction.h"
#include "UnstuckAction.h"
#include "RangeAction.h"
#include "UseConsumableAction.h"
#include "WorldBuffTravelActions.h"

#include "playerbot/strategy/raid/OnyxiasLair/Action/RaidOnyActions.h"
#include "playerbot/strategy/raid/MoltenCore/Action/RaidMcActions.h"
#include "playerbot/strategy/raid/BlackwingLair/Action/RaidBwlActions.h"
#include "playerbot/strategy/raid/Karazhan/Action/RaidKaraActions.h"
#include "playerbot/strategy/raid/Naxxramas/Action/RaidNaxxActions.h"
#include "playerbot/strategy/rpg/Action/NewRpgAction.h"
#include "playerbot/strategy/dungeons/RazorfenDowns/Action/RfdActions.h"
#include "playerbot/strategy/dungeons/Uldaman/Action/UldaActions.h"
#include "playerbot/strategy/dungeons/ZulFarrak/Action/ZfActions.h"
#include "playerbot/strategy/dungeons/Maraudon/Action/MaraActions.h"
#include "playerbot/strategy/dungeons/TempleOfAtalHakkar/Action/StActions.h"
#include "playerbot/strategy/dungeons/BlackrockDepths/Action/BrdActions.h"
#include "playerbot/strategy/dungeons/BlackrockSpire/Action/BrsActions.h"

#ifdef GenerateBotTests
#include "../tests/TestAction.h"
#endif

#ifdef GenerateBotTests
#include "../tests/TestAction.h"
#endif

namespace ai
{
    class ActionContext : public NamedObjectContext<Action>
    {
    public:
        ActionContext()
        {
            creators["mark rti"] = [](PlayerbotAI* ai) { return new MarkRtiAction(ai); };
            creators["set return position"] = [](PlayerbotAI* ai) { return new SetReturnPositionAction(ai); };
            creators["rpg"] = [](PlayerbotAI* ai) { return new RpgAction(ai); };
            creators["crpg"] = [](PlayerbotAI* ai) { return new CRpgAction(ai); };
            creators["choose rpg target"] = [](PlayerbotAI* ai) { return new ChooseRpgTargetAction(ai); };
            creators["move to rpg target"] = [](PlayerbotAI* ai) { return new MoveToRpgTargetAction(ai); };
            creators["new rpg status update"] = [](PlayerbotAI* ai) { return new NewRpgStatusUpdateAction(ai); };
            creators["new rpg go grind"] = [](PlayerbotAI* ai) { return new NewRpgGoGrindAction(ai); };
            creators["new rpg go camp"] = [](PlayerbotAI* ai) { return new NewRpgGoCampAction(ai); };
            creators["new rpg wander random"] = [](PlayerbotAI* ai) { return new NewRpgWanderRandomAction(ai); };
            creators["new rpg wander npc"] = [](PlayerbotAI* ai) { return new NewRpgWanderNpcAction(ai); };
            creators["new rpg do quest"] = [](PlayerbotAI* ai) { return new NewRpgDoQuestAction(ai); };
            creators["new rpg travel flight"] = [](PlayerbotAI* ai) { return new NewRpgTravelFlightAction(ai); };
            creators["new rpg go change zone"] = [](PlayerbotAI* ai) { return new NewRpgGoChangeZoneAction(ai); };
			creators["travel"] = [](PlayerbotAI* ai) { return new TravelAction(ai); };
			creators["choose travel target"] = [](PlayerbotAI* ai) { return new ChooseTravelTargetAction(ai); };
            creators["choose group travel target"] = [](PlayerbotAI* ai) { return new ChooseGroupTravelTargetAction(ai); };
            creators["refresh travel target"] = [](PlayerbotAI* ai) { return new RefreshTravelTargetAction(ai); };
            creators["request travel target"] = [](PlayerbotAI* ai) { return new RequestTravelTargetAction(ai); };
            creators["request named travel target"] = [](PlayerbotAI* ai) { return new RequestNamedTravelTargetAction(ai); };
            creators["request quest travel target"] = [](PlayerbotAI* ai) { return new RequestQuestTravelTargetAction(ai); };
            creators["reset travel target"] = [](PlayerbotAI* ai) { return new ResetTargetAction(ai); };
            creators["move to travel target"] = [](PlayerbotAI* ai) { return new MoveToTravelTargetAction(ai); };
            creators["move out of collision"] = [](PlayerbotAI* ai) { return new MoveOutOfCollisionAction(ai); };
            creators["move random"] = [](PlayerbotAI* ai) { return new MoveRandomAction(ai); };
            creators["attack"] = [](PlayerbotAI* ai) { return new MeleeAction(ai); };
            creators["melee"] = [](PlayerbotAI* ai) { return new MeleeAction(ai); };
            creators["switch to melee"] = [](PlayerbotAI* ai) { return new SwitchToMeleeAction(ai); };
            creators["switch to ranged"] = [](PlayerbotAI* ai) { return new SwitchToRangedAction(ai); };
            creators["reach spell"] = [](PlayerbotAI* ai) { return new ReachSpellAction(ai); };
            creators["reach melee"] = [](PlayerbotAI* ai) { return new ReachMeleeAction(ai); };
            creators["reach pull"] = [](PlayerbotAI* ai) { return new ReachPullAction(ai); };
            creators["reach party member to heal"] = [](PlayerbotAI* ai) { return new ReachPartyMemberToHealAction(ai); };
            creators["reach party member for totem"] = [](PlayerbotAI* ai) { return new ReachPartyMemberForTotemAction(ai); };
            creators["flee"] = [](PlayerbotAI* ai) { return new FleeAction(ai); };
            creators["flee with pet"] = [](PlayerbotAI* ai) { return new FleeWithPetAction(ai); };
            creators["wait for attack keep safe distance"] = [](PlayerbotAI* ai) { return new WaitForAttackKeepSafeDistanceAction(ai); };
            creators["shoot"] = [](PlayerbotAI* ai) { return new CastShootAction(ai); };
            creators["whipper root tuber"] = [](PlayerbotAI* ai) { return new UseWhipperRootTuberAction(ai); };
            creators["healthstone"] = [](PlayerbotAI* ai) { return new UseHealthstoneAction(ai); };
            creators["healing potion"] = [](PlayerbotAI* ai) { return new UseHealingPotionAction(ai); };
            creators["mana potion"] = [](PlayerbotAI* ai) { return new UseManaPotionAction(ai); };
            creators["food"] = [](PlayerbotAI* ai) { return new EatAction(ai); };
            creators["drink"] = [](PlayerbotAI* ai) { return new DrinkAction(ai); };
            creators["tank assist"] = [](PlayerbotAI* ai) { return new TankAssistAction(ai); };
            creators["dps assist"] = [](PlayerbotAI* ai) { return new DpsAssistAction(ai); };
            creators["dps aoe"] = [](PlayerbotAI* ai) { return new DpsAoeAction(ai); };
            creators["attack rti target"] = [](PlayerbotAI* ai) { return new AttackRTITargetAction(ai); };
            creators["loot"] = [](PlayerbotAI* ai) { return new LootAction(ai); };
            creators["add loot"] = [](PlayerbotAI* ai) { return new AddLootAction(ai); };
            creators["add gathering loot"] = [](PlayerbotAI* ai) { return new AddGatheringLootAction(ai); };
            creators["add all loot"] = [](PlayerbotAI* ai) { return new AddAllLootAction(ai); };
            creators["release loot"] = [](PlayerbotAI* ai) { return new ReleaseLootAction(ai); };
            creators["auto loot roll"] = [](PlayerbotAI* ai) { return new AutoLootRollAction(ai); };
            creators["follow"] = [](PlayerbotAI* ai) { return new FollowAction(ai); };
            creators["stop follow"] = [](PlayerbotAI* ai) { return new StopFollowAction(ai); };
            creators["flee to master"] = [](PlayerbotAI* ai) { return new FleeToMasterAction(ai); };
            creators["runaway"] = [](PlayerbotAI* ai) { return new RunAwayAction(ai); };
            creators["stay"] = [](PlayerbotAI* ai) { return new StayAction(ai); };
            creators["sit"] = [](PlayerbotAI* ai) { return new SitAction(ai); };
            creators["attack anything"] = [](PlayerbotAI* ai) { return new AttackAnythingAction(ai); };
            creators["attack least hp target"] = [](PlayerbotAI* ai) { return new AttackLeastHpTargetAction(ai); };
            creators["attack enemy player"] = [](PlayerbotAI* ai) { return new AttackEnemyPlayerAction(ai); };
            creators["pull my target"] = [](PlayerbotAI* ai) { return new PullMyTargetAction(ai); };
            creators["pull rti target"] = [](PlayerbotAI* ai) { return new PullRTITargetAction(ai); };
            creators["pull start"] = [](PlayerbotAI* ai) { return new PullStartAction(ai); };
            creators["pull action"] = [](PlayerbotAI* ai) { return new PullAction(ai); };
            creators["return to pull position"] = [](PlayerbotAI* ai) { return new ReturnToPullPositionAction(ai); };
            creators["pull end"] = [](PlayerbotAI* ai) { return new PullEndAction(ai); };
            creators["emote"] = [](PlayerbotAI* ai) { return new EmoteAction(ai); };
            creators["talk"] = [](PlayerbotAI* ai) { return new TalkAction(ai); };
            creators["mount anim"] = [](PlayerbotAI* ai) { return new MountAnimAction(ai); };
            creators["suggest what to do"] = [](PlayerbotAI* ai) { return new SuggestWhatToDoAction(ai); };
            creators["suggest trade"] = [](PlayerbotAI* ai) { return new SuggestTradeAction(ai); };
            creators["return"] = [](PlayerbotAI* ai) { return new ReturnAction(ai); };
            creators["move to loot"] = [](PlayerbotAI* ai) { return new MoveToLootAction(ai); };
            creators["open loot"] = [](PlayerbotAI* ai) { return new OpenLootAction(ai); };
            creators["guard"] = [](PlayerbotAI* ai) { return new GuardAction(ai); };
            creators["return to stay position"] = [](PlayerbotAI* ai) { return new ReturnToStayPositionAction(ai); };
            creators["move out of enemy contact"] = [](PlayerbotAI* ai) { return new MoveOutOfEnemyContactAction(ai); };
            creators["set facing"] = [](PlayerbotAI* ai) { return new SetFacingTargetAction(ai); };
            creators["set behind"] = [](PlayerbotAI* ai) { return new SetBehindTargetAction(ai); };
            creators["attack duel opponent"] = [](PlayerbotAI* ai) { return new AttackDuelOpponentAction(ai); };
            creators["select new target"] = [](PlayerbotAI* ai) { return new SelectNewTargetAction(ai); };
            creators["check mail"] = [](PlayerbotAI* ai) { return new CheckMailAction(ai); };
            creators["say"] = [](PlayerbotAI* ai) { return new SayAction(ai); };
            creators["reveal gathering item"] = [](PlayerbotAI* ai) { return new RevealGatheringItemAction(ai); };
            creators["outfit"] = [](PlayerbotAI* ai) { return new OutfitAction(ai); };
            creators["random bot update"] = [](PlayerbotAI* ai) { return new RandomBotUpdateAction(ai); };
            creators["delay"] = [](PlayerbotAI* ai) { return new DelayAction(ai); };
            creators["greet"] = [](PlayerbotAI* ai) { return new GreetAction(ai); };
            creators["check values"] = [](PlayerbotAI* ai) { return new CheckValuesAction(ai); };
            creators["set avoid area"] = [](PlayerbotAI* ai) { return new SetAvoidAreaAction(ai); };
            creators["ra"] = [](PlayerbotAI* ai) { return new RemoveAuraAction(ai); };
            creators["remove blessing of salvation"] = [](PlayerbotAI* ai) { return new RemoveBlessingOfSalvationAction(ai); };
            creators["remove greater blessing of salvation"] = [](PlayerbotAI* ai) { return new RemoveGreaterBlessingOfSalvationAction(ai); };
            creators["apply stone"] = [](PlayerbotAI* ai) { return new ImbueWithStoneAction(ai); };
            creators["apply oil"] = [](PlayerbotAI* ai) { return new ImbueWithOilAction(ai); };
            creators["try emergency"] = [](PlayerbotAI* ai) { return new TryEmergencyAction(ai); };
            creators["give food"] = [](PlayerbotAI* ai) { return new GiveFoodAction(ai); };
            creators["give water"] = [](PlayerbotAI* ai) { return new GiveWaterAction(ai); };
            creators["mount"] = [](PlayerbotAI* ai) { return new CastSpellAction(ai, "mount"); };
            creators["auto talents"] = [](PlayerbotAI* ai) { return new AutoSetTalentsAction(ai); };
			creators["auto learn spell"] = [](PlayerbotAI* ai) { return new AutoLearnSpellAction(ai); };
            creators["auto share quest"] = [](PlayerbotAI* ai) { return new AutoShareQuestAction(ai); };
            creators["xp gain"] = [](PlayerbotAI* ai) { return new XpGainAction(ai); };
            creators["honor gain"] = [](PlayerbotAI* ai) { return new HonorGainAction(ai); };
            creators["invite nearby"] = [](PlayerbotAI* ai) { return new InviteNearbyToGroupAction(ai); };
            creators["invite guild"] = [](PlayerbotAI* ai) { return new InviteGuildToGroupAction(ai); };
            creators["leave far away"] = [](PlayerbotAI* ai) { return new LeaveFarAwayAction(ai); };
            creators["move to dark portal"] = [](PlayerbotAI* ai) { return new MoveToDarkPortalAction(ai); };
            creators["move from dark portal"] = [](PlayerbotAI* ai) { return new MoveFromDarkPortalAction(ai); };
            creators["use dark portal azeroth"] = [](PlayerbotAI* ai) { return new DarkPortalAzerothAction(ai); };
            creators["world buff"] = [](PlayerbotAI* ai) { return new WorldBuffAction(ai); };
            creators["world buff travel apply"] = [](PlayerbotAI* ai) { return new WorldBuffTravelApplyAction(ai); };
            creators["world buff travel cast portal"] = [](PlayerbotAI* ai) { return new WorldBuffTravelCastPortalAction(ai); };
            creators["world buff travel take portal"] = [](PlayerbotAI* ai) { return new WorldBuffTravelTakePortalAction(ai); };
            creators["world buff travel finish"] = [](PlayerbotAI* ai) { return new WorldBuffTravelFinishAction(ai); };
            creators["world buff travel set target"] = [](PlayerbotAI* ai) { return new WorldBuffTravelSetTargetAction(ai); };
            creators["world buff travel dm buffed"] = [](PlayerbotAI* ai) { return new WorldBuffTravelDMBuffedAction(ai); };
            creators["world buff travel dm exited"] = [](PlayerbotAI* ai) { return new WorldBuffTravelDMExitedAction(ai); };
            creators["world buff travel dm cast portal"] = [](PlayerbotAI* ai) { return new WorldBuffTravelDMCastPortalAction(ai); };
            creators["world buff travel dm take portal"] = [](PlayerbotAI* ai) { return new WorldBuffTravelDMTakePortalAction(ai); };
            creators["hearthstone"] = [](PlayerbotAI* ai) { return new UseHearthStoneAction(ai); };
            creators["cast random spell"] = [](PlayerbotAI* ai) { return new CastRandomSpellAction(ai); };
            creators["free bg join"] = [](PlayerbotAI* ai) { return new FreeBGJoinAction(ai); };
            creators["use random recipe"] = [](PlayerbotAI* ai) { return new UseRandomRecipeAction(ai); };
            creators["open random item"] = [](PlayerbotAI* ai) { return new OpenRandomItemAction(ai); };
            creators["use random quest item"] = [](PlayerbotAI* ai) { return new UseRandomQuestItemAction(ai); };
            creators["craft random item"] = [](PlayerbotAI* ai) { return new CraftRandomItemAction(ai); };
            creators["smart destroy item"] = [](PlayerbotAI* ai) { return new SmartDestroyItemAction(ai); };
            creators["disenchant random item"] = [](PlayerbotAI* ai) { return new DisenchantRandomItemAction(ai); };
            creators["enchant random item"] = [](PlayerbotAI* ai) { return new EnchantRandomItemAction(ai); };
            creators["reset instances"] = [](PlayerbotAI* ai) { return new ResetInstancesAction(ai); };
            creators["reset raids"] = [](PlayerbotAI* ai) { return new ResetRaidsAction(ai); };
            creators["update gear"] = [](PlayerbotAI* ai) { return new UpdateGearAction(ai); };
            creators["buy petition"] = [](PlayerbotAI* ai) { return new BuyPetitionAction(ai); };
            creators["offer petition"] = [](PlayerbotAI* ai) { return new PetitionOfferAction(ai); };
            creators["offer petition nearby"] = [](PlayerbotAI* ai) { return new PetitionOfferNearbyAction(ai); };
            creators["turn in petition"] = [](PlayerbotAI* ai) { return new PetitionTurnInAction(ai); };
            creators["buy tabard"] = [](PlayerbotAI* ai) { return new BuyTabardAction(ai); };
            creators["guild manage nearby"] = [](PlayerbotAI* ai) { return new GuildManageNearbyAction(ai); };
            creators["guild share item"] = [](PlayerbotAI* ai) { return new GuildShareItemAction(ai); };
            creators["guild ah buy"] = [](PlayerbotAI* ai) { return new GuildShareAhBuyAction(ai); };
            creators["guild accept quest order"] = [](PlayerbotAI* ai) { return new GuildAcceptQuestOrderAction(ai); };
            creators["use trinket"] = [](PlayerbotAI* ai) { return new UseTrinketAction(ai); };
            creators["unstuck"] = [](PlayerbotAI* ai) { return new UnstuckAction(ai); };
            creators["reset"] = [](PlayerbotAI* ai) { return new ResetAction(ai); };
            creators["interrupt current spell"] = [](PlayerbotAI* ai) { return new InterruptCurrentSpellAction(ai); };
            creators["initialize pet"] = [](PlayerbotAI* ai) { return new InitializePetAction(ai); };

            // item helpers
            creators["goblin sapper"] = [](PlayerbotAI* ai) { return new UseGoblinSapperChargeAction(ai); };
            creators["oil of immolation"] = [](PlayerbotAI* ai) { return new UseOilOfImmolationAction(ai); };
            creators["stoneshield potion"] = [](PlayerbotAI* ai) { return new UseStoneshieldPotionAction(ai); };
            creators["dark rune"] = [](PlayerbotAI* ai) { return new UseDarkRuneAction(ai); };
            creators["throw grenade"] = [](PlayerbotAI* ai) { return new ThrowGrenadeAction(ai); };
            creators["bg banner"] = [](PlayerbotAI* ai) { return new UseBgBannerAction(ai); };
            creators["use bandage"] = [](PlayerbotAI* ai) { return new UseBandageAction(ai); };
            creators["rocket boots"] = [](PlayerbotAI* ai) { return new UseRocketBootsAction(ai); };
            creators["fire protection potion"] = [](PlayerbotAI* ai) { return new UseFireProtectionPotionAction(ai); };
            creators["free action potion"] = [](PlayerbotAI* ai) { return new UseFreeActionPotionAction(ai); };
            creators["use consumable"] = [](PlayerbotAI* ai) { return new UseConsumableAction(ai); };
            creators["anti-venom"] = [](PlayerbotAI* ai) { return new UseAntiVenomAction(ai); };

            // BG Tactics
            creators["bg tactics"] = [](PlayerbotAI* ai) { return new BGTactics(ai); };
            creators["bg move to start"] = [](PlayerbotAI* ai) { return new BGTactics(ai, "move to start"); };
            creators["bg move to objective"] = [](PlayerbotAI* ai) { return new BGTactics(ai, "move to objective"); };
            creators["bg select objective"] = [](PlayerbotAI* ai) { return new BGTactics(ai, "select objective"); };
            creators["bg check objective"] = [](PlayerbotAI* ai) { return new BGTactics(ai, "check objective"); };
            creators["bg attack fc"] = [](PlayerbotAI* ai) { return new BGTactics(ai, "attack fc"); };
            creators["bg protect fc"] = [](PlayerbotAI* ai) { return new BGTactics(ai, "protect fc"); };
            creators["bg use buff"] = [](PlayerbotAI* ai) { return new BGTactics(ai, "use buff"); };
            creators["attack enemy flag carrier"] = [](PlayerbotAI* ai) { return new AttackEnemyFlagCarrierAction(ai); };
            creators["bg check flag"] = [](PlayerbotAI* ai) { return new BGTactics(ai, "check flag"); };

            // lightwell
            creators["use lightwell"] = [](PlayerbotAI* ai) { return new UseLightwellAction(ai); };

            // Vehicles
            creators["enter vehicle"] = [](PlayerbotAI* ai) { return new EnterVehicleAction(ai); };
            creators["leave vehicle"] = [](PlayerbotAI* ai) { return new LeaveVehicleAction(ai); };
            creators["hurl boulder"] = [](PlayerbotAI* ai) { return new CastHurlBoulderAction(ai); };
            creators["ram"] = [](PlayerbotAI* ai) { return new CastRamAction(ai); };
            creators["steam rush"] = [](PlayerbotAI* ai) { return new CastSteamRushAction(ai); };
            creators["steam blast"] = [](PlayerbotAI* ai) { return new CastSteamBlastAction(ai); };
            creators["napalm"] = [](PlayerbotAI* ai) { return new CastNapalmAction(ai); };
            creators["fire cannon"] = [](PlayerbotAI* ai) { return new CastFireCannonAction(ai); };
            creators["incendiary rocket"] = [](PlayerbotAI* ai) { return new CastIncendiaryRocketAction(ai); };
            creators["rocket blast"] = [](PlayerbotAI* ai) { return new CastRocketBlastAction(ai); };
            creators["blade salvo"] = [](PlayerbotAI* ai) { return new CastBladeSalvoAction(ai); };
            creators["glaive throw"] = [](PlayerbotAI* ai) { return new CastGlaiveThrowAction(ai); };

            // Quest vehicles
            creators["deliver stolen horse"] = [](PlayerbotAI* ai) { return new CastDeliverStolenHorseAction(ai); };
            creators["horsemans call"] = [](PlayerbotAI* ai) { return new CastHorsemansCallAction(ai); };

            creators["scarlet cannon"] = [](PlayerbotAI* ai) { return new CastScarletCannonAction(ai); };
            creators["electro - magnetic pulse"] = [](PlayerbotAI* ai) { return new CastElectroMagneticPulseAction(ai); };            
            creators["skeletal gryphon escape"] = [](PlayerbotAI* ai) { return new CastSkeletalGryphonEscapeAction(ai); };
            
            creators["frozen deathbolt"] = [](PlayerbotAI* ai) { return new CastFrozenDeathboltAction(ai); };
            creators["devour humanoid"] = [](PlayerbotAI* ai) { return new CastDevourHumanoidAction(ai); };            
            

            //Rpg
            creators["rpg stay"] = [](PlayerbotAI* ai) { return new RpgStayAction(ai); };
            creators["rpg work"] = [](PlayerbotAI* ai) { return new RpgWorkAction(ai); };
            creators["rpg emote"] = [](PlayerbotAI* ai) { return new RpgEmoteAction(ai); };
            creators["rpg cancel"] = [](PlayerbotAI* ai) { return new RpgCancelAction(ai); };
            creators["rpg taxi"] = [](PlayerbotAI* ai) { return new RpgTaxiAction(ai); };
            creators["rpg discover"] = [](PlayerbotAI* ai) { return new RpgDiscoverAction(ai); };
            creators["rpg start quest"] = [](PlayerbotAI* ai) { return new RpgStartQuestAction(ai); };
            creators["rpg end quest"] = [](PlayerbotAI* ai) { return new RpgEndQuestAction(ai); };
            creators["rpg buy"] = [](PlayerbotAI* ai) { return new RpgBuyAction(ai); };
            creators["rpg sell"] = [](PlayerbotAI* ai) { return new RpgSellAction(ai); };
            creators["rpg ah sell"] = [](PlayerbotAI* ai) { return new RpgAHSellAction(ai); };
            creators["rpg ah buy"] = [](PlayerbotAI* ai) { return new RpgAHBuyAction(ai); };
            creators["rpg get mail"] = [](PlayerbotAI* ai) { return new RpgGetMailAction(ai); };
            creators["rpg repair"] = [](PlayerbotAI* ai) { return new RpgRepairAction(ai); };
            creators["rpg train"] = [](PlayerbotAI* ai) { return new RpgTrainAction(ai); };
            creators["rpg heal"] = [](PlayerbotAI* ai) { return new RpgHealAction(ai); };
            creators["rpg home bind"] = [](PlayerbotAI* ai) { return new RpgHomeBindAction(ai); };
            creators["rpg queue bg"] = [](PlayerbotAI* ai) { return new RpgQueueBgAction(ai); };
            creators["rpg buy petition"] = [](PlayerbotAI* ai) { return new RpgBuyPetitionAction(ai); };
            creators["rpg use"] = [](PlayerbotAI* ai) { return new RpgUseAction(ai); };
            creators["rpg ai chat"] = [](PlayerbotAI* ai) { return new RpgAIChatAction(ai); };
            creators["rpg spell"] = [](PlayerbotAI* ai) { return new RpgSpellAction(ai); };
            creators["rpg spell click"] = [](PlayerbotAI* ai) { return new RpgSpellClickAction(ai); };
            creators["rpg craft"] = [](PlayerbotAI* ai) { return new RpgCraftAction(ai); };
            creators["rpg trade useful"] = [](PlayerbotAI* ai) { return new RpgTradeUsefulAction(ai); };
            creators["rpg enchant"] = [](PlayerbotAI* ai) { return new RpgEnchantAction(ai); };
            creators["rpg duel"] = [](PlayerbotAI* ai) { return new RpgDuelAction(ai); };
            creators["rpg item"] = [](PlayerbotAI* ai) { return new RpgItemAction(ai); };
            creators["rpg gossip talk"] = [](PlayerbotAI* ai) { return new RpgGossipTalkAction(ai); };

            creators["auto set glyph"] = [](PlayerbotAI* ai) { return new AutoSetGlyphAction(ai); };
            creators["auto complete quest"] = [](PlayerbotAI* ai) { return new AutoCompleteQuestAction(ai); };

            creators["move to fish"] = [](PlayerbotAI* ai) { return new MoveToFishAction(ai); };
            creators["fish"] = [](PlayerbotAI* ai) { return new FishAction(ai); };
            creators["use fishing bobber"] = [](PlayerbotAI* ai) { return new UseFishingBobberAction(ai); };

            // Bot States
            creators["set combat state"] = [](PlayerbotAI* ai) { return new SetCombatStateAction(ai); };
            creators["set non combat state"] = [](PlayerbotAI* ai) { return new SetNonCombatStateAction(ai); };
            creators["set dead state"] = [](PlayerbotAI* ai) { return new SetDeadStateAction(ai); };

            //racials
            creators["war stomp"] = [](PlayerbotAI* ai) { return new CastWarStompAction(ai); };
            creators["berserking"] = [](PlayerbotAI* ai) { return new CastBerserkingAction(ai); };
            creators["blood fury"] = [](PlayerbotAI* ai) { return new CastBloodFuryAction(ai); };
            creators["cannibalize"] = [](PlayerbotAI* ai) { return new CastCannibalizeAction(ai); };
            creators["escape artist"] = [](PlayerbotAI* ai) { return new CastEscapeArtistAction(ai); };
            creators["shadowmeld"] = [](PlayerbotAI* ai) { return new CastShadowmeldAction(ai); };
            creators["stoneform"] = [](PlayerbotAI* ai) { return new CastStoneformAction(ai); };
            creators["perception"] = [](PlayerbotAI* ai) { return new CastPerceptionAction(ai); };
            creators["will of the forsaken"] = [](PlayerbotAI* ai) { return new CastWillOfTheForsakenAction(ai); };
#ifndef MANGOSBOT_ZERO
            creators["mana tap"] = [](PlayerbotAI* ai) { return new CastManaTapAction(ai); };
            creators["arcane torrent"] = [](PlayerbotAI* ai) { return new CastArcaneTorrentAction(ai); };
            creators["gift of the naaru"] = [](PlayerbotAI* ai) { return new CastGiftOfTheNaaruAction(ai); };
#endif
#ifdef MANGOSBOT_TWO
            creators["every_man_for_himself"] = [](PlayerbotAI* ai) { return new CastEveryManforHimselfAction(ai); };
#endif

            creators["use id"] = [](PlayerbotAI* ai) { return new UseItemIdAction(ai); };
            creators["move to"] = [](PlayerbotAI* ai) { return new MoveToAction(ai); };

            // Dungeon Actions
            creators["enable razorfen downs strategy"] = [](PlayerbotAI* ai) { return new RazorfenDownsEnableStrategyAction(ai); };
            creators["disable razorfen downs strategy"] = [](PlayerbotAI* ai) { return new RazorfenDownsDisableStrategyAction(ai); };
            creators["enable tuten'kash fight strategy"] = [](PlayerbotAI* ai) { return new TutenkashEnableFightStrategyAction(ai); };
            creators["disable tuten'kash fight strategy"] = [](PlayerbotAI* ai) { return new TutenkashDisableFightStrategyAction(ai); };
            creators["enable mordresh fire eye fight strategy"] = [](PlayerbotAI* ai) { return new MordreshEnableFightStrategyAction(ai); };
            creators["disable mordresh fire eye fight strategy"] = [](PlayerbotAI* ai) { return new MordreshDisableFightStrategyAction(ai); };
            creators["mordresh move away from fire nova"] = [](PlayerbotAI* ai) { return new MordreshMoveAwayFromFireNovaAction(ai); };
            creators["enable glutton fight strategy"] = [](PlayerbotAI* ai) { return new GluttonEnableFightStrategyAction(ai); };
            creators["disable glutton fight strategy"] = [](PlayerbotAI* ai) { return new GluttonDisableFightStrategyAction(ai); };
            creators["enable amnennar the coldbringer fight strategy"] = [](PlayerbotAI* ai) { return new AmnennarEnableFightStrategyAction(ai); };
            creators["disable amnennar the coldbringer fight strategy"] = [](PlayerbotAI* ai) { return new AmnennarDisableFightStrategyAction(ai); };
            creators["amnennar move away from frost nova"] = [](PlayerbotAI* ai) { return new AmnennarMoveAwayFromFrostNovaAction(ai); };

            creators["enable uldaman strategy"] = [](PlayerbotAI* ai) { return new UldamanEnableStrategyAction(ai); };
            creators["disable uldaman strategy"] = [](PlayerbotAI* ai) { return new UldamanDisableStrategyAction(ai); };
            creators["enable revelosh fight strategy"] = [](PlayerbotAI* ai) { return new ReveloshEnableFightStrategyAction(ai); };
            creators["disable revelosh fight strategy"] = [](PlayerbotAI* ai) { return new ReveloshDisableFightStrategyAction(ai); };
            creators["enable baelog fight strategy"] = [](PlayerbotAI* ai) { return new BaelogEnableFightStrategyAction(ai); };
            creators["disable baelog fight strategy"] = [](PlayerbotAI* ai) { return new BaelogDisableFightStrategyAction(ai); };
            creators["enable ironaya fight strategy"] = [](PlayerbotAI* ai) { return new IronayaEnableFightStrategyAction(ai); };
            creators["disable ironaya fight strategy"] = [](PlayerbotAI* ai) { return new IronayaDisableFightStrategyAction(ai); };
            creators["ironaya move away from war stomp"] = [](PlayerbotAI* ai) { return new IronayaMoveAwayFromWarStompAction(ai); };
            creators["enable obsidian sentinel fight strategy"] = [](PlayerbotAI* ai) { return new ObsidianSentinelEnableFightStrategyAction(ai); };
            creators["disable obsidian sentinel fight strategy"] = [](PlayerbotAI* ai) { return new ObsidianSentinelDisableFightStrategyAction(ai); };
            creators["enable ancient stone keeper fight strategy"] = [](PlayerbotAI* ai) { return new AncientStoneKeeperEnableFightStrategyAction(ai); };
            creators["disable ancient stone keeper fight strategy"] = [](PlayerbotAI* ai) { return new AncientStoneKeeperDisableFightStrategyAction(ai); };
            creators["ancient stone keeper move away from war stomp"] = [](PlayerbotAI* ai) { return new AncientStoneKeeperMoveAwayFromWarStompAction(ai); };
            creators["enable galgann firehammer fight strategy"] = [](PlayerbotAI* ai) { return new GalgannFirehammerEnableFightStrategyAction(ai); };
            creators["disable galgann firehammer fight strategy"] = [](PlayerbotAI* ai) { return new GalgannFirehammerDisableFightStrategyAction(ai); };
            creators["galgann move away from fire nova"] = [](PlayerbotAI* ai) { return new GalgannMoveAwayFromFireNovaAction(ai); };
            creators["enable grimlok fight strategy"] = [](PlayerbotAI* ai) { return new GrimlokEnableFightStrategyAction(ai); };
            creators["disable grimlok fight strategy"] = [](PlayerbotAI* ai) { return new GrimlokDisableFightStrategyAction(ai); };
            creators["grimlok move away from war stomp"] = [](PlayerbotAI* ai) { return new GrimlokMoveAwayFromWarStompAction(ai); };
            creators["enable archaedas fight strategy"] = [](PlayerbotAI* ai) { return new ArchaedasEnableFightStrategyAction(ai); };
            creators["disable archaedas fight strategy"] = [](PlayerbotAI* ai) { return new ArchaedasDisableFightStrategyAction(ai); };
            creators["archaedas move away from earth tremor"] = [](PlayerbotAI* ai) { return new ArchaedasMoveAwayFromEarthTremorAction(ai); };

            creators["enable zul'farrak strategy"] = [](PlayerbotAI* ai) { return new ZulFarrakEnableStrategyAction(ai); };
            creators["disable zul'farrak strategy"] = [](PlayerbotAI* ai) { return new ZulFarrakDisableStrategyAction(ai); };
            creators["enable theka the martyr fight strategy"] = [](PlayerbotAI* ai) { return new ThekaEnableFightStrategyAction(ai); };
            creators["disable theka the martyr fight strategy"] = [](PlayerbotAI* ai) { return new ThekaDisableFightStrategyAction(ai); };
            creators["enable witch doctor zum'rah fight strategy"] = [](PlayerbotAI* ai) { return new ZumrahEnableFightStrategyAction(ai); };
            creators["disable witch doctor zum'rah fight strategy"] = [](PlayerbotAI* ai) { return new ZumrahDisableFightStrategyAction(ai); };
            creators["enable antu'sul fight strategy"] = [](PlayerbotAI* ai) { return new AntusulEnableFightStrategyAction(ai); };
            creators["disable antu'sul fight strategy"] = [](PlayerbotAI* ai) { return new AntusulDisableFightStrategyAction(ai); };
            creators["enable shadowpriest sezz'ziz fight strategy"] = [](PlayerbotAI* ai) { return new SezzizEnableFightStrategyAction(ai); };
            creators["disable shadowpriest sezz'ziz fight strategy"] = [](PlayerbotAI* ai) { return new SezzizDisableFightStrategyAction(ai); };
            creators["enable sergeant bly fight strategy"] = [](PlayerbotAI* ai) { return new SergeantBlyEnableFightStrategyAction(ai); };
            creators["disable sergeant bly fight strategy"] = [](PlayerbotAI* ai) { return new SergeantBlyDisableFightStrategyAction(ai); };
            creators["enable gahz'rilla fight strategy"] = [](PlayerbotAI* ai) { return new GahzrillaEnableFightStrategyAction(ai); };
            creators["disable gahz'rilla fight strategy"] = [](PlayerbotAI* ai) { return new GahzrillaDisableFightStrategyAction(ai); };
            creators["gahz'rilla move away from freeze"] = [](PlayerbotAI* ai) { return new GahzrillaMoveAwayFromFreezeAction(ai); };
            creators["enable chief ukorz sandscalp fight strategy"] = [](PlayerbotAI* ai) { return new ChiefUkorzEnableFightStrategyAction(ai); };
            creators["disable chief ukorz sandscalp fight strategy"] = [](PlayerbotAI* ai) { return new ChiefUkorzDisableFightStrategyAction(ai); };

            creators["enable maraudon strategy"] = [](PlayerbotAI* ai) { return new MaraudonEnableStrategyAction(ai); };
            creators["disable maraudon strategy"] = [](PlayerbotAI* ai) { return new MaraudonDisableStrategyAction(ai); };
            creators["enable noxxion fight strategy"] = [](PlayerbotAI* ai) { return new NoxxionEnableFightStrategyAction(ai); };
            creators["disable noxxion fight strategy"] = [](PlayerbotAI* ai) { return new NoxxionDisableFightStrategyAction(ai); };
            creators["noxxion move away from noxious fumes"] = [](PlayerbotAI* ai) { return new NoxxionMoveAwayFromNoxiousFumesAction(ai); };
            creators["enable razorlash fight strategy"] = [](PlayerbotAI* ai) { return new RazorlashEnableFightStrategyAction(ai); };
            creators["disable razorlash fight strategy"] = [](PlayerbotAI* ai) { return new RazorlashDisableFightStrategyAction(ai); };
            creators["enable lord vyletongue fight strategy"] = [](PlayerbotAI* ai) { return new LordVyletongueEnableFightStrategyAction(ai); };
            creators["disable lord vyletongue fight strategy"] = [](PlayerbotAI* ai) { return new LordVyletongueDisableFightStrategyAction(ai); };
            creators["enable celebras the cursed fight strategy"] = [](PlayerbotAI* ai) { return new CelebrasEnableFightStrategyAction(ai); };
            creators["disable celebras the cursed fight strategy"] = [](PlayerbotAI* ai) { return new CelebrasDisableFightStrategyAction(ai); };
            creators["enable landslide fight strategy"] = [](PlayerbotAI* ai) { return new LandslideEnableFightStrategyAction(ai); };
            creators["disable landslide fight strategy"] = [](PlayerbotAI* ai) { return new LandslideDisableFightStrategyAction(ai); };
            creators["enable tinkerer gizlock fight strategy"] = [](PlayerbotAI* ai) { return new GizlockEnableFightStrategyAction(ai); };
            creators["disable tinkerer gizlock fight strategy"] = [](PlayerbotAI* ai) { return new GizlockDisableFightStrategyAction(ai); };
            creators["gizlock move away from smoke bomb"] = [](PlayerbotAI* ai) { return new GizlockMoveAwayFromSmokeBombAction(ai); };
            creators["enable rotgrip fight strategy"] = [](PlayerbotAI* ai) { return new RotgripEnableFightStrategyAction(ai); };
            creators["disable rotgrip fight strategy"] = [](PlayerbotAI* ai) { return new RotgripDisableFightStrategyAction(ai); };
            creators["enable princess theradras fight strategy"] = [](PlayerbotAI* ai) { return new TheradrasEnableFightStrategyAction(ai); };
            creators["disable princess theradras fight strategy"] = [](PlayerbotAI* ai) { return new TheradrasDisableFightStrategyAction(ai); };
            creators["theradras move away from dust field"] = [](PlayerbotAI* ai) { return new TheradrasMoveAwayFromDustFieldAction(ai); };

            creators["enable temple of atal'hakkar strategy"] = [](PlayerbotAI* ai) { return new TempleOfAtalHakkarEnableStrategyAction(ai); };
            creators["disable temple of atal'hakkar strategy"] = [](PlayerbotAI* ai) { return new TempleOfAtalHakkarDisableStrategyAction(ai); };
            creators["enable zolo fight strategy"] = [](PlayerbotAI* ai) { return new ZoloEnableFightStrategyAction(ai); };
            creators["disable zolo fight strategy"] = [](PlayerbotAI* ai) { return new ZoloDisableFightStrategyAction(ai); };
            creators["enable hukku fight strategy"] = [](PlayerbotAI* ai) { return new HukkuEnableFightStrategyAction(ai); };
            creators["disable hukku fight strategy"] = [](PlayerbotAI* ai) { return new HukkuDisableFightStrategyAction(ai); };
            creators["enable gasher fight strategy"] = [](PlayerbotAI* ai) { return new GasherEnableFightStrategyAction(ai); };
            creators["disable gasher fight strategy"] = [](PlayerbotAI* ai) { return new GasherDisableFightStrategyAction(ai); };
            creators["enable loro fight strategy"] = [](PlayerbotAI* ai) { return new LoroEnableFightStrategyAction(ai); };
            creators["disable loro fight strategy"] = [](PlayerbotAI* ai) { return new LoroDisableFightStrategyAction(ai); };
            creators["enable mijan fight strategy"] = [](PlayerbotAI* ai) { return new MijanEnableFightStrategyAction(ai); };
            creators["disable mijan fight strategy"] = [](PlayerbotAI* ai) { return new MijanDisableFightStrategyAction(ai); };
            creators["enable zul'lor fight strategy"] = [](PlayerbotAI* ai) { return new ZulLorEnableFightStrategyAction(ai); };
            creators["disable zul'lor fight strategy"] = [](PlayerbotAI* ai) { return new ZulLorDisableFightStrategyAction(ai); };
            creators["enable jammal'an the prophet fight strategy"] = [](PlayerbotAI* ai) { return new JammalanEnableFightStrategyAction(ai); };
            creators["disable jammal'an the prophet fight strategy"] = [](PlayerbotAI* ai) { return new JammalanDisableFightStrategyAction(ai); };
            creators["enable ogom the wretched fight strategy"] = [](PlayerbotAI* ai) { return new OgomEnableFightStrategyAction(ai); };
            creators["disable ogom the wretched fight strategy"] = [](PlayerbotAI* ai) { return new OgomDisableFightStrategyAction(ai); };
            creators["enable morphaz fight strategy"] = [](PlayerbotAI* ai) { return new MorphazEnableFightStrategyAction(ai); };
            creators["disable morphaz fight strategy"] = [](PlayerbotAI* ai) { return new MorphazDisableFightStrategyAction(ai); };
            creators["enable hazzas fight strategy"] = [](PlayerbotAI* ai) { return new HazzasEnableFightStrategyAction(ai); };
            creators["disable hazzas fight strategy"] = [](PlayerbotAI* ai) { return new HazzasDisableFightStrategyAction(ai); };
            creators["enable shade of eranikus fight strategy"] = [](PlayerbotAI* ai) { return new ShadeOfEranikusEnableFightStrategyAction(ai); };
            creators["disable shade of eranikus fight strategy"] = [](PlayerbotAI* ai) { return new ShadeOfEranikusDisableFightStrategyAction(ai); };
            creators["eranikus move away from war stomp"] = [](PlayerbotAI* ai) { return new EranikusMoveAwayFromWarStompAction(ai); };
            creators["enable avatar of hakkar fight strategy"] = [](PlayerbotAI* ai) { return new AvatarOfHakkarEnableFightStrategyAction(ai); };
            creators["disable avatar of hakkar fight strategy"] = [](PlayerbotAI* ai) { return new AvatarOfHakkarDisableFightStrategyAction(ai); };

            creators["enable blackrock depths strategy"] = [](PlayerbotAI* ai) { return new BlackrockDepthsEnableStrategyAction(ai); };
            creators["disable blackrock depths strategy"] = [](PlayerbotAI* ai) { return new BlackrockDepthsDisableStrategyAction(ai); };
            creators["enable gorosh fight strategy"] = [](PlayerbotAI* ai) { return new GoroshEnableFightStrategyAction(ai); };
            creators["disable gorosh fight strategy"] = [](PlayerbotAI* ai) { return new GoroshDisableFightStrategyAction(ai); };
            creators["enable grizzle fight strategy"] = [](PlayerbotAI* ai) { return new GrizzleEnableFightStrategyAction(ai); };
            creators["disable grizzle fight strategy"] = [](PlayerbotAI* ai) { return new GrizzleDisableFightStrategyAction(ai); };
            creators["grizzle move away from ground tremor"] = [](PlayerbotAI* ai) { return new GrizzleMoveAwayFromGroundTremorAction(ai); };
            creators["enable eviscerator fight strategy"] = [](PlayerbotAI* ai) { return new EviscerratorEnableFightStrategyAction(ai); };
            creators["disable eviscerator fight strategy"] = [](PlayerbotAI* ai) { return new EviscerratorDisableFightStrategyAction(ai); };
            creators["eviscerator move away from whirlwind"] = [](PlayerbotAI* ai) { return new EviscerratorMoveAwayFromWhirlwindAction(ai); };
            creators["enable ok'thor the breaker fight strategy"] = [](PlayerbotAI* ai) { return new OkthorEnableFightStrategyAction(ai); };
            creators["disable ok'thor the breaker fight strategy"] = [](PlayerbotAI* ai) { return new OkthorDisableFightStrategyAction(ai); };
            creators["ok'thor move away from war stomp"] = [](PlayerbotAI* ai) { return new OkthorMoveAwayFromWarStompAction(ai); };
            creators["enable anub'shiah fight strategy"] = [](PlayerbotAI* ai) { return new AnubshiahEnableFightStrategyAction(ai); };
            creators["disable anub'shiah fight strategy"] = [](PlayerbotAI* ai) { return new AnubshiahDisableFightStrategyAction(ai); };
            creators["enable hedrum the creeper fight strategy"] = [](PlayerbotAI* ai) { return new HedrumEnableFightStrategyAction(ai); };
            creators["disable hedrum the creeper fight strategy"] = [](PlayerbotAI* ai) { return new HedrumDisableFightStrategyAction(ai); };
            creators["enable high interrogator gerstahn fight strategy"] = [](PlayerbotAI* ai) { return new GerstanEnableFightStrategyAction(ai); };
            creators["disable high interrogator gerstahn fight strategy"] = [](PlayerbotAI* ai) { return new GerstanDisableFightStrategyAction(ai); };
            creators["enable lord roccor fight strategy"] = [](PlayerbotAI* ai) { return new LordRoccorEnableFightStrategyAction(ai); };
            creators["disable lord roccor fight strategy"] = [](PlayerbotAI* ai) { return new LordRoccorDisableFightStrategyAction(ai); };
            creators["lord roccor move away from earthquake"] = [](PlayerbotAI* ai) { return new LordRoccorMoveAwayFromEarthquakeAction(ai); };
            creators["enable houndmaster grebmar fight strategy"] = [](PlayerbotAI* ai) { return new GrebmarEnableFightStrategyAction(ai); };
            creators["disable houndmaster grebmar fight strategy"] = [](PlayerbotAI* ai) { return new GrebmarDisableFightStrategyAction(ai); };
            creators["enable pyromancer loregrain fight strategy"] = [](PlayerbotAI* ai) { return new PyromancerLoregrainEnableFightStrategyAction(ai); };
            creators["disable pyromancer loregrain fight strategy"] = [](PlayerbotAI* ai) { return new PyromancerLoregrainDisableFightStrategyAction(ai); };
            creators["pyromancer move away from fire nova"] = [](PlayerbotAI* ai) { return new PyromancerMoveAwayFromFireNovaAction(ai); };
            creators["enable warder stilgiss fight strategy"] = [](PlayerbotAI* ai) { return new WarderStiglissEnableFightStrategyAction(ai); };
            creators["disable warder stilgiss fight strategy"] = [](PlayerbotAI* ai) { return new WarderStiglissDisableFightStrategyAction(ai); };
            creators["warder stilgiss move away from frost nova"] = [](PlayerbotAI* ai) { return new WarderStiglissMoveAwayFromFrostNovaAction(ai); };
            creators["enable verek fight strategy"] = [](PlayerbotAI* ai) { return new VerekEnableFightStrategyAction(ai); };
            creators["disable verek fight strategy"] = [](PlayerbotAI* ai) { return new VerekDisableFightStrategyAction(ai); };
            creators["enable plugger spazzring fight strategy"] = [](PlayerbotAI* ai) { return new PluggerSpazzringEnableFightStrategyAction(ai); };
            creators["disable plugger spazzring fight strategy"] = [](PlayerbotAI* ai) { return new PluggerSpazzringDisableFightStrategyAction(ai); };
            creators["enable phalanx fight strategy"] = [](PlayerbotAI* ai) { return new PhalanxEnableFightStrategyAction(ai); };
            creators["disable phalanx fight strategy"] = [](PlayerbotAI* ai) { return new PhalanxDisableFightStrategyAction(ai); };
            creators["enable ambassador flamelash fight strategy"] = [](PlayerbotAI* ai) { return new FlamelashEnableFightStrategyAction(ai); };
            creators["disable ambassador flamelash fight strategy"] = [](PlayerbotAI* ai) { return new FlamelashDisableFightStrategyAction(ai); };
            creators["enable the seven fight strategy"] = [](PlayerbotAI* ai) { return new TheSevenEnableFightStrategyAction(ai); };
            creators["disable the seven fight strategy"] = [](PlayerbotAI* ai) { return new TheSevenDisableFightStrategyAction(ai); };
            creators["enable golem lord argelmach fight strategy"] = [](PlayerbotAI* ai) { return new ArgelmachEnableFightStrategyAction(ai); };
            creators["disable golem lord argelmach fight strategy"] = [](PlayerbotAI* ai) { return new ArgelmachDisableFightStrategyAction(ai); };
            creators["argelmach move away from static field"] = [](PlayerbotAI* ai) { return new ArgelmachMoveAwayFromStaticFieldAction(ai); };
            creators["enable bael'gar fight strategy"] = [](PlayerbotAI* ai) { return new BaelGarEnableFightStrategyAction(ai); };
            creators["disable bael'gar fight strategy"] = [](PlayerbotAI* ai) { return new BaelGarDisableFightStrategyAction(ai); };
            creators["bael'gar move away from fire nova"] = [](PlayerbotAI* ai) { return new BaelGarMoveAwayFromFireNovaAction(ai); };
            creators["enable general angerforge fight strategy"] = [](PlayerbotAI* ai) { return new GeneralAngerforgeEnableFightStrategyAction(ai); };
            creators["disable general angerforge fight strategy"] = [](PlayerbotAI* ai) { return new GeneralAngerforgeDisableFightStrategyAction(ai); };
            creators["enable magmus fight strategy"] = [](PlayerbotAI* ai) { return new MagmusEnableFightStrategyAction(ai); };
            creators["disable magmus fight strategy"] = [](PlayerbotAI* ai) { return new MagmusDisableFightStrategyAction(ai); };
            creators["magmus move away from war stomp"] = [](PlayerbotAI* ai) { return new MagmusMoveAwayFromWarStompAction(ai); };
            creators["enable emperor dagran thaurissan fight strategy"] = [](PlayerbotAI* ai) { return new EmperorThaurissanEnableFightStrategyAction(ai); };
            creators["disable emperor dagran thaurissan fight strategy"] = [](PlayerbotAI* ai) { return new EmperorThaurissanDisableFightStrategyAction(ai); };

            // Blackrock Spire (LBRS + UBRS, map 229)
            creators["enable blackrock spire strategy"] = [](PlayerbotAI* ai) { return new BlackrockSpireEnableStrategyAction(ai); };
            creators["disable blackrock spire strategy"] = [](PlayerbotAI* ai) { return new BlackrockSpireDisableStrategyAction(ai); };
            creators["enable highlord omokk fight strategy"] = [](PlayerbotAI* ai) { return new HigdlordOmokkEnableFightStrategyAction(ai); };
            creators["disable highlord omokk fight strategy"] = [](PlayerbotAI* ai) { return new HigdlordOmokkDisableFightStrategyAction(ai); };
            creators["omokk move away from war stomp"] = [](PlayerbotAI* ai) { return new OmokkMoveAwayFromWarStompAction(ai); };
            creators["enable shadow hunter vosh'gajin fight strategy"] = [](PlayerbotAI* ai) { return new VoshgajinEnableFightStrategyAction(ai); };
            creators["disable shadow hunter vosh'gajin fight strategy"] = [](PlayerbotAI* ai) { return new VoshgajinDisableFightStrategyAction(ai); };
            creators["enable war master voone fight strategy"] = [](PlayerbotAI* ai) { return new WarMasterVooneEnableFightStrategyAction(ai); };
            creators["disable war master voone fight strategy"] = [](PlayerbotAI* ai) { return new WarMasterVooneDisableFightStrategyAction(ai); };
            creators["enable mother smolderweb fight strategy"] = [](PlayerbotAI* ai) { return new MotherSmolderwebEnableFightStrategyAction(ai); };
            creators["disable mother smolderweb fight strategy"] = [](PlayerbotAI* ai) { return new MotherSmolderwebDisableFightStrategyAction(ai); };
            creators["enable urok doomhowl fight strategy"] = [](PlayerbotAI* ai) { return new UrokDoomhowlEnableFightStrategyAction(ai); };
            creators["disable urok doomhowl fight strategy"] = [](PlayerbotAI* ai) { return new UrokDoomhowlDisableFightStrategyAction(ai); };
            creators["urok move away from war stomp"] = [](PlayerbotAI* ai) { return new UrokMoveAwayFromWarStompAction(ai); };
            creators["enable quartermaster zigris fight strategy"] = [](PlayerbotAI* ai) { return new QuartermasterZigrisEnableFightStrategyAction(ai); };
            creators["disable quartermaster zigris fight strategy"] = [](PlayerbotAI* ai) { return new QuartermasterZigrisDisableFightStrategyAction(ai); };
            creators["enable halycon fight strategy"] = [](PlayerbotAI* ai) { return new HalyconEnableFightStrategyAction(ai); };
            creators["disable halycon fight strategy"] = [](PlayerbotAI* ai) { return new HalyconDisableFightStrategyAction(ai); };
            creators["enable overlord wyrmthalak fight strategy"] = [](PlayerbotAI* ai) { return new OverlordWyrmthalakEnableFightStrategyAction(ai); };
            creators["disable overlord wyrmthalak fight strategy"] = [](PlayerbotAI* ai) { return new OverlordWyrmthalakDisableFightStrategyAction(ai); };
            creators["wyrmthalak move away from blizzard"] = [](PlayerbotAI* ai) { return new WyrmthalakMoveAwayFromBlizzardAction(ai); };
            creators["enable pyroguard emberseer fight strategy"] = [](PlayerbotAI* ai) { return new PyroguardEmberseerEnableFightStrategyAction(ai); };
            creators["disable pyroguard emberseer fight strategy"] = [](PlayerbotAI* ai) { return new PyroguardEmberseerDisableFightStrategyAction(ai); };
            creators["emberseer move away from ignite"] = [](PlayerbotAI* ai) { return new EmberseerMoveAwayFromIgniteAction(ai); };
            creators["enable solakar flamewreath fight strategy"] = [](PlayerbotAI* ai) { return new SolakarFlamewreathEnableFightStrategyAction(ai); };
            creators["disable solakar flamewreath fight strategy"] = [](PlayerbotAI* ai) { return new SolakarFlamewreathDisableFightStrategyAction(ai); };
            creators["enable jed runewatcher fight strategy"] = [](PlayerbotAI* ai) { return new JedRunewatcherEnableFightStrategyAction(ai); };
            creators["disable jed runewatcher fight strategy"] = [](PlayerbotAI* ai) { return new JedRunewatcherDisableFightStrategyAction(ai); };
            creators["enable the beast fight strategy"] = [](PlayerbotAI* ai) { return new TheBeastEnableFightStrategyAction(ai); };
            creators["disable the beast fight strategy"] = [](PlayerbotAI* ai) { return new TheBeastDisableFightStrategyAction(ai); };
            creators["the beast move away from conflagration"] = [](PlayerbotAI* ai) { return new TheBeastMoveAwayFromConflagrationAction(ai); };
            creators["enable general drakkisath fight strategy"] = [](PlayerbotAI* ai) { return new GeneralDrakkisathEnableFightStrategyAction(ai); };
            creators["disable general drakkisath fight strategy"] = [](PlayerbotAI* ai) { return new GeneralDrakkisathDisableFightStrategyAction(ai); };
            creators["drakkisath move away from conflagration"] = [](PlayerbotAI* ai) { return new DrakkisathMoveAwayFromConflagrationAction(ai); };

            creators["enable onyxia's lair strategy"] = [](PlayerbotAI* ai) { return new OnyxiasLairEnableDungeonStrategyAction(ai); };
            creators["disable onyxia's lair strategy"] = [](PlayerbotAI* ai) { return new OnyxiasLairDisableDungeonStrategyAction(ai); };
            creators["enable molten core strategy"] = [](PlayerbotAI* ai) { return new MoltenCoreEnableDungeonStrategyAction(ai); };
            creators["disable molten core strategy"] = [](PlayerbotAI* ai) { return new MoltenCoreDisableDungeonStrategyAction(ai); };
            creators["enable blackwing lair strategy"] = [](PlayerbotAI* ai) { return new BlackwingLairEnableDungeonStrategyAction(ai); };
            creators["disable blackwing lair strategy"] = [](PlayerbotAI* ai) { return new BlackwingLairDisableDungeonStrategyAction(ai); };
            creators["enable karazhan strategy"] = [](PlayerbotAI* ai) { return new KarazhanEnableDungeonStrategyAction(ai); };
            creators["disable karazhan strategy"] = [](PlayerbotAI* ai) { return new KarazhanDisableDungeonStrategyAction(ai); };
            creators["enable naxxramas strategy"] = [](PlayerbotAI* ai) { return new NaxxramasEnableDungeonStrategyAction(ai); };
            creators["disable naxxramas strategy"] = [](PlayerbotAI* ai) { return new NaxxramasDisableDungeonStrategyAction(ai); };

            // Dungeon Boss Actions
            creators["enable onyxia fight strategy"] = [](PlayerbotAI* ai) { return new OnyxiaEnableFightStrategyAction(ai); };
            creators["disable onyxia fight strategy"] = [](PlayerbotAI* ai) { return new OnyxiaDisableFightStrategyAction(ai); };

            creators["enable magmadar fight strategy"] = [](PlayerbotAI* ai) { return new MagmadarEnableFightStrategyAction(ai); };
            creators["disable magmadar fight strategy"] = [](PlayerbotAI* ai) { return new MagmadarDisableFightStrategyAction(ai); };
            creators["move away from magmadar"] = [](PlayerbotAI* ai) { return new MagmadarMoveAwayAction(ai); };

            creators["move away from hazard"] = [](PlayerbotAI* ai) { return new MoveAwayFromHazard(ai); };
            creators["move to mc rune"] = [](PlayerbotAI* ai) { return new MoveToMCRuneAction(ai); };
            creators["douse mc rune aqual"] = [](PlayerbotAI* ai) { return new DouseMCRuneActionAqual(ai); };
            creators["douse mc rune eternal"] = [](PlayerbotAI* ai) { return new DouseMCRuneActionEternal(ai); };

            creators["move to suppression device"] = [](PlayerbotAI* ai) { return new MoveToSuppressionDeviceAction(ai); };
            creators["stealth for suppression device"] = [](PlayerbotAI* ai) { return new StealthForSuppressionDeviceAction(ai); };
            creators["disarm suppression device"] = [](PlayerbotAI* ai) { return new DisarmSuppressionDeviceAction(ai); };

            creators["enable netherspite fight strategy"] = [](PlayerbotAI* ai) { return new NetherspiteEnableFightStrategyAction(ai); };
            creators["disable netherspite fight strategy"] = [](PlayerbotAI* ai) { return new NetherspiteDisableFightStrategyAction(ai); };
            creators["move away from void zone"] = [](PlayerbotAI* ai) { return new VoidZoneMoveAwayAction(ai); };
            creators["add nether portal - perseverence for tank"] = [](PlayerbotAI* ai) { return new AddNetherPortalPerseverenceForTankAction(ai); };
            creators["remove nether portal buffs from netherspite"] = [](PlayerbotAI* ai) { return new RemoveNetherPortalBuffsFromNetherspiteAction(ai); };
            creators["remove nether portal - perseverence"] = [](PlayerbotAI* ai) { return new RemoveNetherPortalPerseverenceAction(ai); };
            creators["remove nether portal - serenity"] = [](PlayerbotAI* ai) { return new RemoveNetherPortalSerenityAction(ai); };
            creators["remove nether portal - dominance"] = [](PlayerbotAI* ai) { return new RemoveNetherPortalDominanceAction(ai); };

            creators["enable prince malchezaar fight strategy"] = [](PlayerbotAI* ai) { return new PrinceMalchezaarEnableFightStrategyAction(ai); };
            creators["disable prince malchezaar fight strategy"] = [](PlayerbotAI* ai) { return new PrinceMalchezaarDisableFightStrategyAction(ai); };
            creators["move away from netherspite infernal"] = [](PlayerbotAI* ai) { return new NetherspiteInfernalMoveAwayAction(ai); };

            creators["enable four horseman fight strategy"] = [](PlayerbotAI* ai) { return new FourHorsemanEnableFightStrategyAction(ai); };
            creators["disable four horseman fight strategy"] = [](PlayerbotAI* ai) { return new FourHorsemanDisableFightStrategyAction(ai); };

#ifdef GenerateBotTests
            creators["test"] = [](PlayerbotAI* ai) { return new TestAction(ai); };
#endif
        }    
    };
};
