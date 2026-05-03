#pragma once

#include "CustomStrategy.h"
#include "generic/NonCombatStrategy.h"
#include "generic/RacialsStrategy.h"
#include "generic/ChatCommandHandlerStrategy.h"
#include "generic/WorldPacketHandlerStrategy.h"
#include "generic/DeadStrategy.h"
#include "generic/QuestStrategies.h"
#include "generic/LootNonCombatStrategy.h"
#include "generic/DuelStrategy.h"
#include "generic/KiteStrategy.h"
#include "generic/FleeStrategy.h"
#include "generic/FollowMasterStrategy.h"
#include "generic/RunawayStrategy.h"
#include "generic/StayStrategy.h"
#include "generic/UseFoodStrategy.h"
#include "generic/ConserveManaStrategy.h"
#include "generic/EmoteStrategy.h"
#include "generic/TankAssistStrategy.h"
#include "generic/DpsAssistStrategy.h"
#include "generic/PassiveStrategy.h"
#include "generic/GrindingStrategy.h"
#include "generic/UsePotionsStrategy.h"
#include "generic/GuardStrategy.h"
#include "generic/CastTimeStrategy.h"
#include "generic/ThreatStrategy.h"
#include "generic/TellTargetStrategy.h"
#include "generic/AttackEnemyPlayersStrategy.h"
#include "generic/MarkRtiStrategy.h"
#include "generic/MeleeCombatStrategy.h"
#include "generic/PullStrategy.h"
#include "generic/RangedCombatStrategy.h"
#include "generic/ReturnStrategy.h"
#include "generic/RpgStrategy.h"
#include "generic/TravelStrategy.h"
#include "generic/RTSCStrategy.h"
#include "generic/DebugStrategy.h"
#include "generic/BattlegroundStrategy.h"
#include "generic/LfgStrategy.h"
#include "generic/MaintenanceStrategy.h"
#include "generic/GroupStrategy.h"
#include "generic/GuildStrategy.h"
#include "generic/FocusTargetStrategy.h"
#include "generic/AvoidMobsStrategy.h"
#include "generic/WanderStrategy.h"
#include "generic/ConsumableStrategy.h"
#include "generic/WorldBuffTravelStrategy.h"
#include "playerbot/strategy/rpg/Strategy/NewRpgStrategy.h"
#ifdef GenerateBotTests
#include "tests/TestStrategy.h"
#endif

#include "generic/DungeonStrategy.h"
#include "playerbot/strategy/raid/OnyxiasLair/Strategy/RaidOnyStrategy.h"
#include "playerbot/strategy/dungeons/RagefireChasm/Strategy/RfcStrategy.h"
#include "playerbot/strategy/dungeons/WailingCaverns/Strategy/WcStrategy.h"
#include "playerbot/strategy/dungeons/Deadmines/Strategy/DmStrategy.h"
#include "playerbot/strategy/dungeons/ShadowfangKeep/Strategy/SfkStrategy.h"
#include "playerbot/strategy/dungeons/BlackfathomDeeps/Strategy/BfdStrategy.h"
#include "playerbot/strategy/dungeons/Stockade/Strategy/StocksStrategy.h"
#include "playerbot/strategy/dungeons/Gnomeregan/Strategy/GnomerStrategy.h"
#include "playerbot/strategy/dungeons/RazorfenKraul/Strategy/RfkStrategy.h"
#include "playerbot/strategy/dungeons/ScarletMonastery/Strategy/SmStrategy.h"
#include "playerbot/strategy/dungeons/RazorfenDowns/Strategy/RfdStrategy.h"
#include "playerbot/strategy/dungeons/Uldaman/Strategy/UldaStrategy.h"
#include "playerbot/strategy/dungeons/ZulFarrak/Strategy/ZfStrategy.h"
#include "playerbot/strategy/dungeons/Maraudon/Strategy/MaraStrategy.h"
#include "playerbot/strategy/dungeons/TempleOfAtalHakkar/Strategy/StStrategy.h"
#include "playerbot/strategy/dungeons/BlackrockDepths/Strategy/BrdStrategy.h"
#include "playerbot/strategy/dungeons/BlackrockSpire/Strategy/BrsStrategy.h"
#include "playerbot/strategy/dungeons/DireMaul/Strategy/DmStrategy.h"
#include "playerbot/strategy/dungeons/Stratholme/Strategy/StratStrategy.h"
#include "playerbot/strategy/dungeons/Scholomance/Strategy/ScholoStrategy.h"
#include "playerbot/strategy/raid/MoltenCore/Strategy/RaidMcStrategy.h"
#include "playerbot/strategy/raid/BlackwingLair/Strategy/RaidBwlStrategy.h"
#include "playerbot/strategy/raid/Karazhan/Strategy/RaidKaraStrategy.h"
#include "playerbot/strategy/raid/Naxxramas/Strategy/RaidNaxxStrategy.h"

namespace ai
{
    class StrategyContext : public NamedObjectContext<Strategy>
    {
    public:
        StrategyContext()
        {
            creators["racials"] = [](PlayerbotAI* ai) { return new RacialsStrategy(ai); };
            creators["loot"] = [](PlayerbotAI* ai) { return new LootNonCombatStrategy(ai); };
            creators["gather"] = [](PlayerbotAI* ai) { return new GatherStrategy(ai); };
            creators["roll"] = [](PlayerbotAI* ai) { return new RollStrategy(ai); };
            creators["delayed roll"] = [](PlayerbotAI* ai) { return new DelayedRollStrategy(ai); };
            creators["emote"] = [](PlayerbotAI* ai) { return new EmoteStrategy(ai); };
            creators["passive"] = [](PlayerbotAI* ai) { return new PassiveStrategy(ai); };
            creators["conserve mana"] = [](PlayerbotAI* ai) { return new ConserveManaStrategy(ai); };
            creators["food"] = [](PlayerbotAI* ai) { return new UseFoodStrategy(ai); };
            creators["consumables"] = [](PlayerbotAI* ai) { return new ConsumableStrategy(ai); };
            creators["chat"] = [](PlayerbotAI* ai) { return new ChatCommandHandlerStrategy(ai); };
            creators["default"] = [](PlayerbotAI* ai) { return new WorldPacketHandlerStrategy(ai); };
            creators["ready check"] = [](PlayerbotAI* ai) { return new ReadyCheckStrategy(ai); };
            creators["dead"] = [](PlayerbotAI* ai) { return new DeadStrategy(ai); };
            creators["flee"] = [](PlayerbotAI* ai) { return new FleeStrategy(ai); };
            creators["avoid mobs"] = [](PlayerbotAI* ai) { return new AvoidMobsStrategy(ai); };
            creators["duel"] = [](PlayerbotAI* ai) { return new DuelStrategy(ai); };
            creators["start duel"] = [](PlayerbotAI* ai) { return new StartDuelStrategy(ai); };
            creators["kite"] = [](PlayerbotAI* ai) { return new KiteStrategy(ai); };
            creators["potions"] = [](PlayerbotAI* ai) { return new UsePotionsStrategy(ai); };
            creators["cast time"] = [](PlayerbotAI* ai) { return new CastTimeStrategy(ai); };
            creators["threat"] = [](PlayerbotAI* ai) { return new ThreatStrategy(ai); };
            creators["tell target"] = [](PlayerbotAI* ai) { return new TellTargetStrategy(ai); };
            creators["pvp"] = [](PlayerbotAI* ai) { return new AttackEnemyPlayersStrategy(ai); };
            creators["return"] = [](PlayerbotAI* ai) { return new ReturnStrategy(ai); };
            creators["lfg"] = [](PlayerbotAI* ai) { return new LfgStrategy(ai); };
            creators["custom"] = [](PlayerbotAI* ai) { return new CustomStrategy(ai); };
            creators["reveal"] = [](PlayerbotAI* ai) { return new RevealStrategy(ai); };
            creators["collision"] = [](PlayerbotAI* ai) { return new CollisionStrategy(ai); };
            creators["rpg"] = [](PlayerbotAI* ai) { return new RpgStrategy(ai); };
            creators["rpg quest"] = [](PlayerbotAI* ai) { return new RpgQuestStrategy(ai); };
            creators["rpg vendor"] = [](PlayerbotAI* ai) { return new RpgVendorStrategy(ai); };
            creators["rpg explore"] = [](PlayerbotAI* ai) { return new RpgExploreStrategy(ai); };
            creators["rpg maintenance"] = [](PlayerbotAI* ai) { return new RpgMaintenanceStrategy(ai); };
            creators["rpg guild"] = [](PlayerbotAI* ai) { return new RpgGuildStrategy(ai); };
            creators["rpg bg"] = [](PlayerbotAI* ai) { return new RpgBgStrategy(ai); };
            creators["rpg player"] = [](PlayerbotAI* ai) { return new RpgPlayerStrategy(ai); };
            creators["rpg craft"] = [](PlayerbotAI* ai) { return new RpgCraftStrategy(ai); };
            creators["rpg jump"] = [](PlayerbotAI* ai) { return new RpgJumpStrategy(ai); };
            creators["follow jump"] = [](PlayerbotAI* ai) { return new FollowJumpStrategy(ai); };
            creators["chase jump"] = [](PlayerbotAI* ai) { return new ChaseJumpStrategy(ai); };
			creators["travel"] = [](PlayerbotAI* ai) { return new TravelStrategy(ai); };
            creators["travel once"] = [](PlayerbotAI* ai) { return new TravelOnceStrategy(ai); };
            creators["explore"] = [](PlayerbotAI* ai) { return new ExploreStrategy(ai); };
            creators["map"] = [](PlayerbotAI* ai) { return new MapStrategy(ai); };
            creators["map full"] = [](PlayerbotAI* ai) { return new MapFullStrategy(ai); };
            creators["sit"] = [](PlayerbotAI* ai) { return new SitStrategy(ai); };
            creators["mark rti"] = [](PlayerbotAI* ai) { return new MarkRtiStrategy(ai); };
            creators["ads"] = [](PlayerbotAI* ai) { return new PossibleAdsStrategy(ai); };
            creators["close"] = [](PlayerbotAI* ai) { return new MeleeCombatStrategy(ai); };
            creators["ranged"] = [](PlayerbotAI* ai) { return new RangedCombatStrategy(ai); };
            creators["behind"] = [](PlayerbotAI* ai) { return new SetBehindCombatStrategy(ai); };
            creators["bg"] = [](PlayerbotAI* ai) { return new BGStrategy(ai); };
            creators["battleground"] = [](PlayerbotAI* ai) { return new BattlegroundStrategy(ai); };
            creators["warsong"] = [](PlayerbotAI* ai) { return new WarsongStrategy(ai); };
            creators["alterac"] = [](PlayerbotAI* ai) { return new AlteracStrategy(ai); };
            creators["arathi"] = [](PlayerbotAI* ai) { return new ArathiStrategy(ai); };
            creators["eye"] = [](PlayerbotAI* ai) { return new EyeStrategy(ai); };
            creators["isle"] = [](PlayerbotAI* ai) { return new IsleStrategy(ai); };
            creators["arena"] = [](PlayerbotAI* ai) { return new ArenaStrategy(ai); };
            creators["mount"] = [](PlayerbotAI* ai) { return new MountStrategy(ai); };
            creators["attack tagged"] = [](PlayerbotAI* ai) { return new AttackTaggedStrategy(ai); };
            creators["debug"] = [](PlayerbotAI* ai) { return new DebugStrategy(ai); };
            creators["debug action"] = [](PlayerbotAI* ai) { return new DebugActionStrategy(ai); };
            creators["debug move"] = [](PlayerbotAI* ai) { return new DebugMoveStrategy(ai); };
            creators["debug rpg"] = [](PlayerbotAI* ai) { return new DebugRpgStrategy(ai); };
            creators["debug spell"] = [](PlayerbotAI* ai) { return new DebugSpellStrategy(ai); };
            creators["debug travel"] = [](PlayerbotAI* ai) { return new DebugTravelStrategy(ai); };
            creators["debug threat"] = [](PlayerbotAI* ai) { return new DebugThreatStrategy(ai); };
            creators["debug mount"] = [](PlayerbotAI* ai) { return new DebugMountStrategy(ai); };
            creators["debug grind"] = [](PlayerbotAI* ai) { return new DebugGrindStrategy(ai); };
            creators["debug loot"] = [](PlayerbotAI* ai) { return new DebugLootStrategy(ai); };
            creators["debug log"] = [](PlayerbotAI* ai) { return new DebugLogStrategy(ai); };
            creators["debug llm"] = [](PlayerbotAI* ai) { return new DebugLLMStrategy(ai); };
            creators["debug stuck"] = [](PlayerbotAI* ai) { return new DebugStuckStrategy(ai); };
            creators["debug xp"] = [](PlayerbotAI* ai) { return new DebugXpStrategy(ai); };
            creators["debug equip"] = [](PlayerbotAI* ai) { return new DebugEquipStrategy(ai); };
            creators["debug logname"] = [](PlayerbotAI* ai) { return new DebugLogNameStrategy(ai); };
            creators["rtsc"] = [](PlayerbotAI* ai) { return new RTSCStrategy(ai); };
            creators["rtsc jump"] = [](PlayerbotAI* ai) { return new RTSCSJumptrategy(ai); };
            creators["maintenance"] = [](PlayerbotAI* ai) { return new MaintenanceStrategy(ai); };
            creators["group"] = [](PlayerbotAI* ai) { return new GroupStrategy(ai); };
            creators["guild"] = [](PlayerbotAI* ai) { return new GuildStrategy(ai); };
            creators["grind"] = [](PlayerbotAI* ai) { return new GrindingStrategy(ai); };
            creators["avoid aoe"] = [](PlayerbotAI* ai) { return new AvoidAoeStrategy(ai); };
            creators["wait for attack"] = [](PlayerbotAI* ai) { return new WaitForAttackStrategy(ai); };
            creators["pull back"] = [](PlayerbotAI* ai) { return new PullBackStrategy(ai); };
            creators["focus heal targets"] = [](PlayerbotAI* ai) { return new FocusHealTargetsStrategy(ai); };
            creators["focus rti targets"] = [](PlayerbotAI* ai) { return new FocusRtiTargetsStrategy(ai); };
            creators["heal interrupt"] = [](PlayerbotAI* ai) { return new HealInterruptStrategy(ai); };
            creators["preheal"] = [](PlayerbotAI* ai) { return new PreHealStrategy(ai); };
            creators["wbuff"] = [](PlayerbotAI* ai) { return new WorldBuffStrategy(ai); };
            creators["wbuff travel"] = [](PlayerbotAI* ai) { return new WorldBuffTravelStrategy(ai); };
            creators["silent"] = [](PlayerbotAI* ai) { return new SilentStrategy(ai); };
            creators["nowar"] = [](PlayerbotAI* ai) { return new NoWarStrategy(ai); };
            creators["glyph"] = [](PlayerbotAI* ai) { return new GlyphStrategy(ai); };
            creators["ai chat"] = [](PlayerbotAI* ai) { return new AIChatStrategy(ai); };

            // Dungeon Strategies
            creators["dungeon"] = [](PlayerbotAI* ai) { return new DungeonStrategy(ai); };
            creators["wailing caverns"] = [](PlayerbotAI* ai) { return new WailingCavernsDungeonStrategy(ai); };
            creators["ragefire chasm"] = [](PlayerbotAI* ai) { return new RagefireChasmDungeonStrategy(ai); };
            creators["deadmines"] = [](PlayerbotAI* ai) { return new DeadminesDungeonStrategy(ai); };
            creators["shadowfang keep"] = [](PlayerbotAI* ai) { return new ShadowfangKeepDungeonStrategy(ai); };
            creators["blackfathom deeps"] = [](PlayerbotAI* ai) { return new BlackfathomDeepsDungeonStrategy(ai); };
            creators["stockade"] = [](PlayerbotAI* ai) { return new StocksDungeonStrategy(ai); };
            creators["gnomeregan"] = [](PlayerbotAI* ai) { return new GnomereganDungeonStrategy(ai); };
            creators["razorfen kraul"] = [](PlayerbotAI* ai) { return new RazorfenKraulDungeonStrategy(ai); };
            creators["scarlet monastery"] = [](PlayerbotAI* ai) { return new ScarletMonasteryDungeonStrategy(ai); };
            creators["razorfen downs"] = [](PlayerbotAI* ai) { return new RazorfenDownsDungeonStrategy(ai); };
            creators["uldaman"] = [](PlayerbotAI* ai) { return new UldamanDungeonStrategy(ai); };
            creators["zul'farrak"] = [](PlayerbotAI* ai) { return new ZulFarrakDungeonStrategy(ai); };
            creators["maraudon"] = [](PlayerbotAI* ai) { return new MaraudonDungeonStrategy(ai); };
            creators["temple of atal'hakkar"] = [](PlayerbotAI* ai) { return new TempleOfAtalHakkarDungeonStrategy(ai); };
            creators["blackrock depths"] = [](PlayerbotAI* ai) { return new BlackrockDepthsDungeonStrategy(ai); };
            creators["blackrock spire"] = [](PlayerbotAI* ai) { return new BlackrockSpireDungeonStrategy(ai); };
            creators["onyxia's lair"] = [](PlayerbotAI* ai) { return new OnyxiasLairDungeonStrategy(ai); };
            creators["molten core"] = [](PlayerbotAI* ai) { return new MoltenCoreDungeonStrategy(ai); };
            creators["blackwing lair"] = [](PlayerbotAI* ai) { return new BlackwingLairDungeonStrategy(ai); };
            creators["karazhan"] = [](PlayerbotAI* ai) { return new KarazhanDungeonStrategy(ai); };
            creators["naxxramas"] = [](PlayerbotAI* ai) { return new NaxxramasDungeonStrategy(ai); };
            creators["new rpg"] = [](PlayerbotAI* ai) { return new NewRpgStrategy(ai); };

            // Dungeon Boss Strategies
            creators["kresh"]      = [](PlayerbotAI* ai) { return new KreshFightStrategy(ai); };
            creators["anacondra"]  = [](PlayerbotAI* ai) { return new AnacondraFightStrategy(ai); };
            creators["cobrahn"]    = [](PlayerbotAI* ai) { return new CobrahnFightStrategy(ai); };
            creators["pythas"]     = [](PlayerbotAI* ai) { return new PythasFightStrategy(ai); };
            creators["serpentis"]  = [](PlayerbotAI* ai) { return new SerpenatisFightStrategy(ai); };
            creators["verdan"]     = [](PlayerbotAI* ai) { return new VerdanFightStrategy(ai); };
            creators["mutanus"]    = [](PlayerbotAI* ai) { return new MutanusFightStrategy(ai); };
            creators["rhahkzor"]       = [](PlayerbotAI* ai) { return new RhahkzorFightStrategy(ai); };
            creators["sneed shredder"] = [](PlayerbotAI* ai) { return new SneedShredderFightStrategy(ai); };
            creators["sneed"]          = [](PlayerbotAI* ai) { return new SneedFightStrategy(ai); };
            creators["gilnid"]         = [](PlayerbotAI* ai) { return new GilnidFightStrategy(ai); };
            creators["smite"]          = [](PlayerbotAI* ai) { return new SmiteFightStrategy(ai); };
            creators["cookie"]         = [](PlayerbotAI* ai) { return new CookieFightStrategy(ai); };
            creators["vancleef"]       = [](PlayerbotAI* ai) { return new VanCleefFightStrategy(ai); };
            creators["rethilgore"]     = [](PlayerbotAI* ai) { return new RethilgoreFightStrategy(ai); };
            creators["razorclaw"]      = [](PlayerbotAI* ai) { return new RazorclawFightStrategy(ai); };
            creators["silverlaine"]    = [](PlayerbotAI* ai) { return new SilverlaineFightStrategy(ai); };
            creators["springvale"]     = [](PlayerbotAI* ai) { return new SpringvaleFightStrategy(ai); };
            creators["odo"]            = [](PlayerbotAI* ai) { return new OdoFightStrategy(ai); };
            creators["fenrus"]         = [](PlayerbotAI* ai) { return new FenrusFightStrategy(ai); };
            creators["nandos"]         = [](PlayerbotAI* ai) { return new NandosFightStrategy(ai); };
            creators["arugal"]         = [](PlayerbotAI* ai) { return new ArugalFightStrategy(ai); };
            creators["ghamoo-ra"]      = [](PlayerbotAI* ai) { return new GhamooRaFightStrategy(ai); };
            creators["lady sarevess"]  = [](PlayerbotAI* ai) { return new LadySarevessFightStrategy(ai); };
            creators["gelihast"]       = [](PlayerbotAI* ai) { return new GelihastFightStrategy(ai); };
            creators["lorgus jett"]    = [](PlayerbotAI* ai) { return new LorgusJettFightStrategy(ai); };
            creators["baron aquanis"]  = [](PlayerbotAI* ai) { return new BaronAquanisFightStrategy(ai); };
            creators["kelris"]         = [](PlayerbotAI* ai) { return new KelrisFightStrategy(ai); };
            creators["aku'mai"]        = [](PlayerbotAI* ai) { return new AkuMaiFightStrategy(ai); };
            // Stockade bosses
            creators["targorr"]        = [](PlayerbotAI* ai) { return new TargorrFightStrategy(ai); };
            creators["kam deepfury"]   = [](PlayerbotAI* ai) { return new KamDeepfuryFightStrategy(ai); };
            creators["hamhock"]        = [](PlayerbotAI* ai) { return new HamhockFightStrategy(ai); };
            creators["bazil thredd"]   = [](PlayerbotAI* ai) { return new BazilThreddFightStrategy(ai); };
            creators["dextren ward"]   = [](PlayerbotAI* ai) { return new DextrenWardFightStrategy(ai); };
            // Gnomeregan bosses
            creators["grubbis"]        = [](PlayerbotAI* ai) { return new GrubbisFightStrategy(ai); };
            creators["viscous fallout"] = [](PlayerbotAI* ai) { return new ViscousFalloutFightStrategy(ai); };
            creators["electrocutioner"] = [](PlayerbotAI* ai) { return new ElectrocutionerFightStrategy(ai); };
            creators["crowd pummeler"] = [](PlayerbotAI* ai) { return new CrowdPummelerFightStrategy(ai); };
            creators["thermaplugg"]    = [](PlayerbotAI* ai) { return new ThermapluggFightStrategy(ai); };
            // Razorfen Kraul bosses
            creators["roogug"]                 = [](PlayerbotAI* ai) { return new RoogugFightStrategy(ai); };
            creators["aggem thorncurse"]       = [](PlayerbotAI* ai) { return new AggEmThorncurseFightStrategy(ai); };
            creators["death speaker jargba"]   = [](PlayerbotAI* ai) { return new DeathSpeakerJargbaFightStrategy(ai); };
            creators["overlord ramtusk"]       = [](PlayerbotAI* ai) { return new OverlordRamtuskFightStrategy(ai); };
            creators["agathelos"]              = [](PlayerbotAI* ai) { return new AgathelosFightStrategy(ai); };
            creators["charlga razorflank"]     = [](PlayerbotAI* ai) { return new CharlgaRazorflankFightStrategy(ai); };
            // Razorfen Downs bosses
            creators["tuten'kash"]                   = [](PlayerbotAI* ai) { return new TutenkashFightStrategy(ai); };
            creators["mordresh fire eye"]             = [](PlayerbotAI* ai) { return new MordreshFireEyeFightStrategy(ai); };
            creators["glutton"]                       = [](PlayerbotAI* ai) { return new GluttonFightStrategy(ai); };
            creators["amnennar the coldbringer"]      = [](PlayerbotAI* ai) { return new AmnennarTheColdbringerFightStrategy(ai); };
            // Uldaman bosses
            creators["revelosh"]                      = [](PlayerbotAI* ai) { return new ReveloshFightStrategy(ai); };
            creators["baelog"]                        = [](PlayerbotAI* ai) { return new BaelogFightStrategy(ai); };
            creators["ironaya"]                       = [](PlayerbotAI* ai) { return new IronayaFightStrategy(ai); };
            creators["obsidian sentinel"]             = [](PlayerbotAI* ai) { return new ObsidianSentinelFightStrategy(ai); };
            creators["ancient stone keeper"]          = [](PlayerbotAI* ai) { return new AncientStoneKeeperFightStrategy(ai); };
            creators["galgann firehammer"]            = [](PlayerbotAI* ai) { return new GalgannFirehammerFightStrategy(ai); };
            creators["grimlok"]                       = [](PlayerbotAI* ai) { return new GrimlokFightStrategy(ai); };
            creators["archaedas"]                     = [](PlayerbotAI* ai) { return new ArchaedasFightStrategy(ai); };
            // Zul'Farrak bosses
            creators["theka the martyr"]        = [](PlayerbotAI* ai) { return new ThekaTheMartyrFightStrategy(ai); };
            creators["witch doctor zum'rah"]    = [](PlayerbotAI* ai) { return new WitchDoctorZumrahFightStrategy(ai); };
            creators["antu'sul"]                = [](PlayerbotAI* ai) { return new AntusulFightStrategy(ai); };
            creators["shadowpriest sezz'ziz"]   = [](PlayerbotAI* ai) { return new ShadowpriestSezzizFightStrategy(ai); };
            creators["sergeant bly"]            = [](PlayerbotAI* ai) { return new SergeantBlyFightStrategy(ai); };
            creators["gahz'rilla"]              = [](PlayerbotAI* ai) { return new GahzrillaFightStrategy(ai); };
            creators["chief ukorz sandscalp"]   = [](PlayerbotAI* ai) { return new ChiefUkorzSandscalpFightStrategy(ai); };
            // Maraudon bosses
            creators["noxxion"]                 = [](PlayerbotAI* ai) { return new NoxxionFightStrategy(ai); };
            creators["razorlash"]               = [](PlayerbotAI* ai) { return new RazorlashFightStrategy(ai); };
            creators["lord vyletongue"]         = [](PlayerbotAI* ai) { return new LordVyletongeFightStrategy(ai); };
            creators["celebras the cursed"]     = [](PlayerbotAI* ai) { return new CelebrasTheCursedFightStrategy(ai); };
            creators["landslide"]               = [](PlayerbotAI* ai) { return new LandslideFightStrategy(ai); };
            creators["tinkerer gizlock"]        = [](PlayerbotAI* ai) { return new TinkererGizlockFightStrategy(ai); };
            creators["rotgrip"]                 = [](PlayerbotAI* ai) { return new RotgripFightStrategy(ai); };
            creators["princess theradras"]      = [](PlayerbotAI* ai) { return new PrincessTheadrasFightStrategy(ai); };
            // Temple of Atal'Hakkar bosses
            creators["zolo"]                        = [](PlayerbotAI* ai) { return new ZoloFightStrategy(ai); };
            creators["hukku"]                       = [](PlayerbotAI* ai) { return new HukkuFightStrategy(ai); };
            creators["gasher"]                      = [](PlayerbotAI* ai) { return new GasherFightStrategy(ai); };
            creators["loro"]                        = [](PlayerbotAI* ai) { return new LoroFightStrategy(ai); };
            creators["mijan"]                       = [](PlayerbotAI* ai) { return new MijanFightStrategy(ai); };
            creators["zul'lor"]                     = [](PlayerbotAI* ai) { return new ZulLorFightStrategy(ai); };
            creators["jammal'an the prophet"]       = [](PlayerbotAI* ai) { return new JammalanTheProphetFightStrategy(ai); };
            creators["ogom the wretched"]           = [](PlayerbotAI* ai) { return new OgomTheWretchedFightStrategy(ai); };
            creators["morphaz"]                     = [](PlayerbotAI* ai) { return new MorphazFightStrategy(ai); };
            creators["hazzas"]                      = [](PlayerbotAI* ai) { return new HazzasFightStrategy(ai); };
            creators["shade of eranikus"]           = [](PlayerbotAI* ai) { return new ShadeOfEranikusFightStrategy(ai); };
            creators["avatar of hakkar"]            = [](PlayerbotAI* ai) { return new AvatarOfHakkarFightStrategy(ai); };
            // Blackrock Depths bosses
            creators["gorosh"]                      = [](PlayerbotAI* ai) { return new GoroshFightStrategy(ai); };
            creators["grizzle"]                     = [](PlayerbotAI* ai) { return new GrizzleFightStrategy(ai); };
            creators["eviscerator"]                 = [](PlayerbotAI* ai) { return new EviscerratorFightStrategy(ai); };
            creators["ok'thor the breaker"]         = [](PlayerbotAI* ai) { return new OkthorTheBreakerFightStrategy(ai); };
            creators["anub'shiah"]                  = [](PlayerbotAI* ai) { return new AnubshiahFightStrategy(ai); };
            creators["hedrum the creeper"]          = [](PlayerbotAI* ai) { return new HedrumTheCreepFightStrategy(ai); };
            creators["high interrogator gerstahn"]  = [](PlayerbotAI* ai) { return new HighInterrogatorGerstanFightStrategy(ai); };
            creators["lord roccor"]                 = [](PlayerbotAI* ai) { return new LordRoccorFightStrategy(ai); };
            creators["houndmaster grebmar"]         = [](PlayerbotAI* ai) { return new HoundmasterGrebmarFightStrategy(ai); };
            creators["pyromancer loregrain"]        = [](PlayerbotAI* ai) { return new PyromancerLoregrainFightStrategy(ai); };
            creators["warder stilgiss"]             = [](PlayerbotAI* ai) { return new WarderStiglissFightStrategy(ai); };
            creators["verek"]                       = [](PlayerbotAI* ai) { return new VerekFightStrategy(ai); };
            creators["plugger spazzring"]           = [](PlayerbotAI* ai) { return new PluggerSpazzringFightStrategy(ai); };
            creators["phalanx"]                     = [](PlayerbotAI* ai) { return new PhalanxFightStrategy(ai); };
            creators["ambassador flamelash"]        = [](PlayerbotAI* ai) { return new AmbassadorFlamelashFightStrategy(ai); };
            creators["the seven"]                   = [](PlayerbotAI* ai) { return new TheSevenFightStrategy(ai); };
            creators["golem lord argelmach"]        = [](PlayerbotAI* ai) { return new GolemLordArgelmachFightStrategy(ai); };
            creators["bael'gar"]                    = [](PlayerbotAI* ai) { return new BaelGarFightStrategy(ai); };
            creators["general angerforge"]          = [](PlayerbotAI* ai) { return new GeneralAngerforgeFightStrategy(ai); };
            creators["magmus"]                      = [](PlayerbotAI* ai) { return new MagmusFightStrategy(ai); };
            creators["emperor dagran thaurissan"]   = [](PlayerbotAI* ai) { return new EmperorDagranThaurissanFightStrategy(ai); };
            // Blackrock Spire bosses (LBRS + UBRS)
            creators["highlord omokk"]              = [](PlayerbotAI* ai) { return new HigdlordOmokkFightStrategy(ai); };
            creators["shadow hunter vosh'gajin"]    = [](PlayerbotAI* ai) { return new ShadowHunterVoshgajinFightStrategy(ai); };
            creators["war master voone"]            = [](PlayerbotAI* ai) { return new WarMasterVooneFightStrategy(ai); };
            creators["mother smolderweb"]           = [](PlayerbotAI* ai) { return new MotherSmolderwebFightStrategy(ai); };
            creators["urok doomhowl"]               = [](PlayerbotAI* ai) { return new UrokDoomhowlFightStrategy(ai); };
            creators["quartermaster zigris"]        = [](PlayerbotAI* ai) { return new QuartermasterZigisFightStrategy(ai); };
            creators["halycon"]                     = [](PlayerbotAI* ai) { return new HalyconFightStrategy(ai); };
            creators["overlord wyrmthalak"]         = [](PlayerbotAI* ai) { return new OverlordWyrmthalakFightStrategy(ai); };
            creators["pyroguard emberseer"]         = [](PlayerbotAI* ai) { return new PyroguardEmberseerFightStrategy(ai); };
            creators["solakar flamewreath"]         = [](PlayerbotAI* ai) { return new SolakarFlamewreathFightStrategy(ai); };
            creators["jed runewatcher"]             = [](PlayerbotAI* ai) { return new JedRunewatcherFightStrategy(ai); };
            creators["the beast"]                   = [](PlayerbotAI* ai) { return new TheBeastFightStrategy(ai); };
            creators["general drakkisath"]          = [](PlayerbotAI* ai) { return new GeneralDrakkisathFightStrategy(ai); };
            creators["dire maul"]                   = [](PlayerbotAI* ai) { return new DireMaulDungeonStrategy(ai); };
            // Dire Maul East
            creators["zevrim thornhoof"]            = [](PlayerbotAI* ai) { return new ZevrimThornhoofFightStrategy(ai); };
            creators["hydrospawn"]                  = [](PlayerbotAI* ai) { return new HydrospawnFightStrategy(ai); };
            creators["lethtendris"]                 = [](PlayerbotAI* ai) { return new LehtendrisFightStrategy(ai); };
            creators["alzzin the wildshaper"]       = [](PlayerbotAI* ai) { return new AlzzinTheWildshaperFightStrategy(ai); };
            // Dire Maul West
            creators["tendris warpwood"]            = [](PlayerbotAI* ai) { return new TendrisWarpwoodFightStrategy(ai); };
            creators["illyanna ravenoak"]           = [](PlayerbotAI* ai) { return new IllyannaRavenoakFightStrategy(ai); };
            creators["magister kalendris"]          = [](PlayerbotAI* ai) { return new MagisterKalendrisFightStrategy(ai); };
            creators["immol'thar"]                  = [](PlayerbotAI* ai) { return new ImmoltharFightStrategy(ai); };
            creators["prince tortheldrin"]          = [](PlayerbotAI* ai) { return new PrinceTortheldrinFightStrategy(ai); };
            // Dire Maul North
            creators["guard mol'dar"]               = [](PlayerbotAI* ai) { return new GuardMoldarFightStrategy(ai); };
            creators["stomper kreeg"]               = [](PlayerbotAI* ai) { return new StomperKreegFightStrategy(ai); };
            creators["guard fengus"]                = [](PlayerbotAI* ai) { return new GuardFengusFightStrategy(ai); };
            creators["guard slip'kik"]              = [](PlayerbotAI* ai) { return new GuardSlipkikFightStrategy(ai); };
            creators["captain kromcrush"]           = [](PlayerbotAI* ai) { return new CaptainKromcrushFightStrategy(ai); };
            creators["king gordok"]                 = [](PlayerbotAI* ai) { return new KingGordokFightStrategy(ai); };
            creators["stratholme"]                  = [](PlayerbotAI* ai) { return new StratholmeDungeonStrategy(ai); };
            // Stratholme Scarlet side
            creators["hearthsinger forresten"]      = [](PlayerbotAI* ai) { return new HearthsingerForrestenFightStrategy(ai); };
            creators["timmy the cruel"]             = [](PlayerbotAI* ai) { return new TimmytheCruelFightStrategy(ai); };
            creators["cannon master willey"]        = [](PlayerbotAI* ai) { return new CannonMasterWilleyFightStrategy(ai); };
            creators["archivist galford"]           = [](PlayerbotAI* ai) { return new ArchivistGalfordFightStrategy(ai); };
            creators["balnazzar"]                   = [](PlayerbotAI* ai) { return new BalnazzarFightStrategy(ai); };
            // Stratholme Undead side
            creators["magistrate barthilas"]        = [](PlayerbotAI* ai) { return new MagistrateBarthilasFightStrategy(ai); };
            creators["maleki the pallid"]           = [](PlayerbotAI* ai) { return new MalekithePallidFightStrategy(ai); };
            creators["ramstein the gorger"]         = [](PlayerbotAI* ai) { return new RamsteintheGorgerFightStrategy(ai); };
            creators["baron rivendare"]             = [](PlayerbotAI* ai) { return new BaronRivendareFightStrategy(ai); };
            creators["scholomance"]                 = [](PlayerbotAI* ai) { return new ScholomanceDungeonStrategy(ai); };
            creators["kirtonos the herald"]         = [](PlayerbotAI* ai) { return new KirtonostheHeraldFightStrategy(ai); };
            creators["jandice barov"]               = [](PlayerbotAI* ai) { return new JandiceBarovFightStrategy(ai); };
            creators["rattlegore"]                  = [](PlayerbotAI* ai) { return new RattlegoreFightStrategy(ai); };
            creators["marduk blackpool"]            = [](PlayerbotAI* ai) { return new MardukBlackpoolFightStrategy(ai); };
            creators["vectus"]                      = [](PlayerbotAI* ai) { return new VectusFightStrategy(ai); };
            creators["ras frostwhisper"]            = [](PlayerbotAI* ai) { return new RasFrostwhisperFightStrategy(ai); };
            creators["instructor malicia"]          = [](PlayerbotAI* ai) { return new InstructorMaliciaFightStrategy(ai); };
            creators["doctor theolen krastinov"]    = [](PlayerbotAI* ai) { return new DoctorTheolenKrastinovFightStrategy(ai); };
            creators["the ravenian"]                = [](PlayerbotAI* ai) { return new TheRavenianFightStrategy(ai); };
            creators["lord alexei barov"]           = [](PlayerbotAI* ai) { return new LordAlexeiBarovFightStrategy(ai); };
            creators["lady illucia barov"]          = [](PlayerbotAI* ai) { return new LadyIlluciaBarovFightStrategy(ai); };
            creators["darkmaster gandling"]         = [](PlayerbotAI* ai) { return new DarkmasterGandlingFightStrategy(ai); };
            // Scarlet Monastery bosses
            creators["vishas"]           = [](PlayerbotAI* ai) { return new VishasFightStrategy(ai); };
            creators["fallen champion"]  = [](PlayerbotAI* ai) { return new FallenChampionFightStrategy(ai); };
            creators["ironspine"]        = [](PlayerbotAI* ai) { return new IronspineFightStrategy(ai); };
            creators["thalnos"]          = [](PlayerbotAI* ai) { return new ThalnsosFightStrategy(ai); };
            creators["loksey"]           = [](PlayerbotAI* ai) { return new LokseyFightStrategy(ai); };
            creators["doan"]             = [](PlayerbotAI* ai) { return new DoanFightStrategy(ai); };
            creators["herod"]            = [](PlayerbotAI* ai) { return new HerodFightStrategy(ai); };
            creators["mograine"]         = [](PlayerbotAI* ai) { return new MograineFightStrategy(ai); };
            creators["whitemane"]        = [](PlayerbotAI* ai) { return new WhitemaneFightStrategy(ai); };
            creators["fairbanks"]        = [](PlayerbotAI* ai) { return new FairbanksFightStrategy(ai); };
            creators["oggleflint"] = [](PlayerbotAI* ai) { return new OggleflintFightStrategy(ai); };
            creators["taragaman"] = [](PlayerbotAI* ai) { return new TaragamanFightStrategy(ai); };
            creators["jergosh"] = [](PlayerbotAI* ai) { return new JergoshFightStrategy(ai); };
            creators["bazzalan"] = [](PlayerbotAI* ai) { return new BazzalanFightStrategy(ai); };
            creators["onyxia"] = [](PlayerbotAI* ai) { return new OnyxiaFightStrategy(ai); };
            creators["magmadar"] = [](PlayerbotAI* ai) { return new MagmadarFightStrategy(ai); };
            creators["suppression room"] = [](PlayerbotAI* ai) { return new SuppressionRoomStrategy(ai); };
            creators["netherspite"] = [](PlayerbotAI* ai) { return new NetherspiteFightStrategy(ai); };
            creators["prince malchezaar"] = [](PlayerbotAI* ai) { return new PrinceMalchezaarFightStrategy(ai); };
            creators["four horseman"] = [](PlayerbotAI* ai) { return new FourHorsemanFightStrategy(ai); };

#ifdef GenerateBotTests
            creators["test"] = [](PlayerbotAI* ai) { return new TestStrategy(ai); };
#endif
        }
    };

    class MovementStrategyContext : public NamedObjectContext<Strategy>
    {
    public:
        MovementStrategyContext() : NamedObjectContext<Strategy>(false, true)
        {
            creators["follow"] = [](PlayerbotAI* ai) { return new FollowMasterStrategy(ai); };
            creators["stay"] = [](PlayerbotAI* ai) { return new StayStrategy(ai); };
            creators["runaway"] = [](PlayerbotAI* ai) { return new RunawayStrategy(ai); };
            creators["flee from adds"] = [](PlayerbotAI* ai) { return new FleeFromAddsStrategy(ai); };
            creators["guard"] = [](PlayerbotAI* ai) { return new GuardStrategy(ai); };
            creators["free"] = [](PlayerbotAI* ai) { return new FreeStrategy(ai); };
            creators["wander"] = [](PlayerbotAI* ai) { return new WanderStrategy(ai); };
        }
    };

    class AssistStrategyContext : public NamedObjectContext<Strategy>
    {
    public:
        AssistStrategyContext() : NamedObjectContext<Strategy>(false, true)
        {
            creators["dps assist"] = [](PlayerbotAI* ai) { return new DpsAssistStrategy(ai); };
            creators["dps aoe"] = [](PlayerbotAI* ai) { return new DpsAoeStrategy(ai); };
            creators["tank assist"] = [](PlayerbotAI* ai) { return new TankAssistStrategy(ai); };
        }
    };

    class QuestStrategyContext : public NamedObjectContext<Strategy>
    {
    public:
        QuestStrategyContext() : NamedObjectContext<Strategy>(false, true)
        {
            creators["quest"] = [](PlayerbotAI* ai) { return new DefaultQuestStrategy(ai); };
            creators["accept all quests"] = [](PlayerbotAI* ai) { return new AcceptAllQuestsStrategy(ai); };
        }
    };

    class FishStrategyContext : public NamedObjectContext<Strategy>
    {
    public:
        FishStrategyContext() : NamedObjectContext<Strategy>(false, true)
        {
            creators["fish"] = [](PlayerbotAI* ai) { return new FishStrategy(ai); };
            creators["tfish"] = [](PlayerbotAI* ai) { return new TFishStrategy(ai); };
        }   
    };
};
