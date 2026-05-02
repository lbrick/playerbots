#include "playerbot/playerbot.h"
#include "BrsStrategy.h"

using namespace ai;

// ── BlackrockSpireDungeonStrategy ─────────────────────────────────────────────

void BlackrockSpireDungeonStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // LBRS bosses
    triggers.push_back(new TriggerNode(
        "start highlord omokk fight",
        NextAction::array(0, new NextAction("enable highlord omokk fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start shadow hunter vosh'gajin fight",
        NextAction::array(0, new NextAction("enable shadow hunter vosh'gajin fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start war master voone fight",
        NextAction::array(0, new NextAction("enable war master voone fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start mother smolderweb fight",
        NextAction::array(0, new NextAction("enable mother smolderweb fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start urok doomhowl fight",
        NextAction::array(0, new NextAction("enable urok doomhowl fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start quartermaster zigris fight",
        NextAction::array(0, new NextAction("enable quartermaster zigris fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start halycon fight",
        NextAction::array(0, new NextAction("enable halycon fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start overlord wyrmthalak fight",
        NextAction::array(0, new NextAction("enable overlord wyrmthalak fight strategy", 100.0f), NULL)));

    // UBRS bosses
    triggers.push_back(new TriggerNode(
        "start pyroguard emberseer fight",
        NextAction::array(0, new NextAction("enable pyroguard emberseer fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start solakar flamewreath fight",
        NextAction::array(0, new NextAction("enable solakar flamewreath fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start jed runewatcher fight",
        NextAction::array(0, new NextAction("enable jed runewatcher fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start the beast fight",
        NextAction::array(0, new NextAction("enable the beast fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start general drakkisath fight",
        NextAction::array(0, new NextAction("enable general drakkisath fight strategy", 100.0f), NULL)));
}

void BlackrockSpireDungeonStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // LBRS bosses
    triggers.push_back(new TriggerNode(
        "start highlord omokk fight",
        NextAction::array(0, new NextAction("enable highlord omokk fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start shadow hunter vosh'gajin fight",
        NextAction::array(0, new NextAction("enable shadow hunter vosh'gajin fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start war master voone fight",
        NextAction::array(0, new NextAction("enable war master voone fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start mother smolderweb fight",
        NextAction::array(0, new NextAction("enable mother smolderweb fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start urok doomhowl fight",
        NextAction::array(0, new NextAction("enable urok doomhowl fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start quartermaster zigris fight",
        NextAction::array(0, new NextAction("enable quartermaster zigris fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start halycon fight",
        NextAction::array(0, new NextAction("enable halycon fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start overlord wyrmthalak fight",
        NextAction::array(0, new NextAction("enable overlord wyrmthalak fight strategy", 100.0f), NULL)));

    // UBRS bosses
    triggers.push_back(new TriggerNode(
        "start pyroguard emberseer fight",
        NextAction::array(0, new NextAction("enable pyroguard emberseer fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start solakar flamewreath fight",
        NextAction::array(0, new NextAction("enable solakar flamewreath fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start jed runewatcher fight",
        NextAction::array(0, new NextAction("enable jed runewatcher fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start the beast fight",
        NextAction::array(0, new NextAction("enable the beast fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start general drakkisath fight",
        NextAction::array(0, new NextAction("enable general drakkisath fight strategy", 100.0f), NULL)));
}

// ── HigdlordOmokkFightStrategy ────────────────────────────────────────────────

void HigdlordOmokkFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // War Stomp ~8yd AoE — stay >10yd
    triggers.push_back(new TriggerNode(
        "omokk war stomp",
        NextAction::array(0, new NextAction("omokk move away from war stomp", ACTION_MOVE + 5), NULL)));
}

void HigdlordOmokkFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end highlord omokk fight",
        NextAction::array(0, new NextAction("disable highlord omokk fight strategy", 100.0f), NULL)));
}

void HigdlordOmokkFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end highlord omokk fight",
        NextAction::array(0, new NextAction("disable highlord omokk fight strategy", 100.0f), NULL)));
}

// ── ShadowHunterVoshgajinFightStrategy ───────────────────────────────────────

void ShadowHunterVoshgajinFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end shadow hunter vosh'gajin fight",
        NextAction::array(0, new NextAction("disable shadow hunter vosh'gajin fight strategy", 100.0f), NULL)));
}

void ShadowHunterVoshgajinFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end shadow hunter vosh'gajin fight",
        NextAction::array(0, new NextAction("disable shadow hunter vosh'gajin fight strategy", 100.0f), NULL)));
}

// ── WarMasterVooneFightStrategy ───────────────────────────────────────────────

void WarMasterVooneFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end war master voone fight",
        NextAction::array(0, new NextAction("disable war master voone fight strategy", 100.0f), NULL)));
}

void WarMasterVooneFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end war master voone fight",
        NextAction::array(0, new NextAction("disable war master voone fight strategy", 100.0f), NULL)));
}

// ── MotherSmolderwebFightStrategy ─────────────────────────────────────────────

void MotherSmolderwebFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end mother smolderweb fight",
        NextAction::array(0, new NextAction("disable mother smolderweb fight strategy", 100.0f), NULL)));
}

void MotherSmolderwebFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end mother smolderweb fight",
        NextAction::array(0, new NextAction("disable mother smolderweb fight strategy", 100.0f), NULL)));
}

// ── UrokDoomhowlFightStrategy ─────────────────────────────────────────────────

void UrokDoomhowlFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // War Stomp ~8yd AoE — stay >10yd
    triggers.push_back(new TriggerNode(
        "urok war stomp",
        NextAction::array(0, new NextAction("urok move away from war stomp", ACTION_MOVE + 5), NULL)));
}

void UrokDoomhowlFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end urok doomhowl fight",
        NextAction::array(0, new NextAction("disable urok doomhowl fight strategy", 100.0f), NULL)));
}

void UrokDoomhowlFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end urok doomhowl fight",
        NextAction::array(0, new NextAction("disable urok doomhowl fight strategy", 100.0f), NULL)));
}

// ── QuartermasterZigisFightStrategy ──────────────────────────────────────────

void QuartermasterZigisFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end quartermaster zigris fight",
        NextAction::array(0, new NextAction("disable quartermaster zigris fight strategy", 100.0f), NULL)));
}

void QuartermasterZigisFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end quartermaster zigris fight",
        NextAction::array(0, new NextAction("disable quartermaster zigris fight strategy", 100.0f), NULL)));
}

// ── HalyconFightStrategy ──────────────────────────────────────────────────────

void HalyconFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end halycon fight",
        NextAction::array(0, new NextAction("disable halycon fight strategy", 100.0f), NULL)));
}

void HalyconFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end halycon fight",
        NextAction::array(0, new NextAction("disable halycon fight strategy", 100.0f), NULL)));
}

// ── OverlordWyrmthalakFightStrategy ──────────────────────────────────────────

void OverlordWyrmthalakFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // War Stomp + Blizzard ~10yd AoE — stay >12yd
    triggers.push_back(new TriggerNode(
        "wyrmthalak blizzard",
        NextAction::array(0, new NextAction("wyrmthalak move away from blizzard", ACTION_MOVE + 5), NULL)));
}

void OverlordWyrmthalakFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end overlord wyrmthalak fight",
        NextAction::array(0, new NextAction("disable overlord wyrmthalak fight strategy", 100.0f), NULL)));
}

void OverlordWyrmthalakFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end overlord wyrmthalak fight",
        NextAction::array(0, new NextAction("disable overlord wyrmthalak fight strategy", 100.0f), NULL)));
}

// ── PyroguardEmberseerFightStrategy ──────────────────────────────────────────

void PyroguardEmberseerFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Ignite ~8yd fire aura — stay >10yd
    triggers.push_back(new TriggerNode(
        "emberseer ignite",
        NextAction::array(0, new NextAction("emberseer move away from ignite", ACTION_MOVE + 5), NULL)));
}

void PyroguardEmberseerFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end pyroguard emberseer fight",
        NextAction::array(0, new NextAction("disable pyroguard emberseer fight strategy", 100.0f), NULL)));
}

void PyroguardEmberseerFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end pyroguard emberseer fight",
        NextAction::array(0, new NextAction("disable pyroguard emberseer fight strategy", 100.0f), NULL)));
}

// ── SolakarFlamewreathFightStrategy ──────────────────────────────────────────

void SolakarFlamewreathFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end solakar flamewreath fight",
        NextAction::array(0, new NextAction("disable solakar flamewreath fight strategy", 100.0f), NULL)));
}

void SolakarFlamewreathFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end solakar flamewreath fight",
        NextAction::array(0, new NextAction("disable solakar flamewreath fight strategy", 100.0f), NULL)));
}

// ── JedRunewatcherFightStrategy ───────────────────────────────────────────────

void JedRunewatcherFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end jed runewatcher fight",
        NextAction::array(0, new NextAction("disable jed runewatcher fight strategy", 100.0f), NULL)));
}

void JedRunewatcherFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end jed runewatcher fight",
        NextAction::array(0, new NextAction("disable jed runewatcher fight strategy", 100.0f), NULL)));
}

// ── TheBeastFightStrategy ─────────────────────────────────────────────────────

void TheBeastFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Conflagration ~10yd AoE splash — stay >12yd
    triggers.push_back(new TriggerNode(
        "the beast conflagration",
        NextAction::array(0, new NextAction("the beast move away from conflagration", ACTION_MOVE + 5), NULL)));
}

void TheBeastFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end the beast fight",
        NextAction::array(0, new NextAction("disable the beast fight strategy", 100.0f), NULL)));
}

void TheBeastFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end the beast fight",
        NextAction::array(0, new NextAction("disable the beast fight strategy", 100.0f), NULL)));
}

// ── GeneralDrakkisathFightStrategy ────────────────────────────────────────────

void GeneralDrakkisathFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Conflagration ~8yd AoE cone — stay >10yd
    triggers.push_back(new TriggerNode(
        "drakkisath conflagration",
        NextAction::array(0, new NextAction("drakkisath move away from conflagration", ACTION_MOVE + 5), NULL)));
}

void GeneralDrakkisathFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end general drakkisath fight",
        NextAction::array(0, new NextAction("disable general drakkisath fight strategy", 100.0f), NULL)));
}

void GeneralDrakkisathFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end general drakkisath fight",
        NextAction::array(0, new NextAction("disable general drakkisath fight strategy", 100.0f), NULL)));
}
