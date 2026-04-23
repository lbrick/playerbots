#include "playerbot/playerbot.h"
#include "SfkStrategy.h"

using namespace ai;

void ShadowfangKeepDungeonStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "target casting springvale heal",
        NextAction::array(0, new NextAction("interrupt enemy cast", ACTION_HIGH + 5), NULL)));

    triggers.push_back(new TriggerNode(
        "start rethilgore fight",
        NextAction::array(0, new NextAction("enable rethilgore fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start razorclaw fight",
        NextAction::array(0, new NextAction("enable razorclaw fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start silverlaine fight",
        NextAction::array(0, new NextAction("enable silverlaine fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start springvale fight",
        NextAction::array(0, new NextAction("enable springvale fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start odo fight",
        NextAction::array(0, new NextAction("enable odo fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start fenrus fight",
        NextAction::array(0, new NextAction("enable fenrus fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start nandos fight",
        NextAction::array(0, new NextAction("enable nandos fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start arugal fight",
        NextAction::array(0, new NextAction("enable arugal fight strategy", 100.0f), NULL)));
}

void ShadowfangKeepDungeonStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "start rethilgore fight",
        NextAction::array(0, new NextAction("enable rethilgore fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start razorclaw fight",
        NextAction::array(0, new NextAction("enable razorclaw fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start silverlaine fight",
        NextAction::array(0, new NextAction("enable silverlaine fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start springvale fight",
        NextAction::array(0, new NextAction("enable springvale fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start odo fight",
        NextAction::array(0, new NextAction("enable odo fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start fenrus fight",
        NextAction::array(0, new NextAction("enable fenrus fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start nandos fight",
        NextAction::array(0, new NextAction("enable nandos fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start arugal fight",
        NextAction::array(0, new NextAction("enable arugal fight strategy", 100.0f), NULL)));
}

void RethilgoreFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end rethilgore fight",
        NextAction::array(0, new NextAction("disable rethilgore fight strategy", 100.0f), NULL)));
}

void RethilgoreFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end rethilgore fight",
        NextAction::array(0, new NextAction("disable rethilgore fight strategy", 100.0f), NULL)));
}

void RazorclawFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end razorclaw fight",
        NextAction::array(0, new NextAction("disable razorclaw fight strategy", 100.0f), NULL)));
}

void RazorclawFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end razorclaw fight",
        NextAction::array(0, new NextAction("disable razorclaw fight strategy", 100.0f), NULL)));
}

void SilverlaineFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end silverlaine fight",
        NextAction::array(0, new NextAction("disable silverlaine fight strategy", 100.0f), NULL)));
}

void SilverlaineFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end silverlaine fight",
        NextAction::array(0, new NextAction("disable silverlaine fight strategy", 100.0f), NULL)));
}

void SpringvaleFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "target casting springvale heal",
        NextAction::array(0, new NextAction("interrupt enemy cast", ACTION_HIGH + 5), NULL)));
}

void SpringvaleFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end springvale fight",
        NextAction::array(0, new NextAction("disable springvale fight strategy", 100.0f), NULL)));
}

void SpringvaleFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end springvale fight",
        NextAction::array(0, new NextAction("disable springvale fight strategy", 100.0f), NULL)));
}

void OdoFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end odo fight",
        NextAction::array(0, new NextAction("disable odo fight strategy", 100.0f), NULL)));
}

void OdoFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end odo fight",
        NextAction::array(0, new NextAction("disable odo fight strategy", 100.0f), NULL)));
}

void FenrusFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end fenrus fight",
        NextAction::array(0, new NextAction("disable fenrus fight strategy", 100.0f), NULL)));
}

void FenrusFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end fenrus fight",
        NextAction::array(0, new NextAction("disable fenrus fight strategy", 100.0f), NULL)));
}

void NandosFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end nandos fight",
        NextAction::array(0, new NextAction("disable nandos fight strategy", 100.0f), NULL)));
}

void NandosFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end nandos fight",
        NextAction::array(0, new NextAction("disable nandos fight strategy", 100.0f), NULL)));
}

void ArugalFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end arugal fight",
        NextAction::array(0, new NextAction("disable arugal fight strategy", 100.0f), NULL)));
}

void ArugalFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end arugal fight",
        NextAction::array(0, new NextAction("disable arugal fight strategy", 100.0f), NULL)));
}
