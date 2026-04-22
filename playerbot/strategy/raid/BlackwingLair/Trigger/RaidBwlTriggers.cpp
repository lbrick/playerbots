#include "playerbot/playerbot.h"
#include "RaidBwlTriggers.h"

using namespace ai;

bool SuppressionDeviceNeedStealthTrigger::IsActive()
{
    if (bot->getClass() != CLASS_ROGUE)
        return false;

    if (ai->HasAura("stealth", bot))
        return false;

    std::list<GuidPosition> gos = AI_VALUE(std::list<GuidPosition>, "go usable filter::go trapped filter::entry filter::{gos in sight,suppression devices}");
    return !gos.empty();
}

bool SuppressionDeviceInSightTrigger::IsActive()
{
    if (bot->getClass() != CLASS_ROGUE)
        return false;

    std::list<GuidPosition> gosInSight = AI_VALUE(std::list<GuidPosition>, "go usable filter::go trapped filter::entry filter::{gos in sight,suppression devices}");
    std::list<GuidPosition> gosClose = AI_VALUE(std::list<GuidPosition>, "entry filter::{gos close,suppression devices}");

    return !gosInSight.empty() && gosClose.empty();
}

bool SuppressionDeviceCloseTrigger::IsActive()
{
    if (bot->getClass() != CLASS_ROGUE)
        return false;

    std::list<GuidPosition> gos = AI_VALUE(std::list<GuidPosition>, "go usable filter::go trapped filter::entry filter::{gos close,suppression devices}");
    return !gos.empty();
}
