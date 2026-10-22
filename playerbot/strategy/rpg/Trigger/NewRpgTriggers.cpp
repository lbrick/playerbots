#include "playerbot/playerbot.h"
#include "NewRpgTriggers.h"

using namespace ai;

bool NewRpgStatusTrigger::IsActive()
{
    return status == ai->rpgInfo.GetStatus();
}

bool NewRpgPostQuestTrigger::IsActive()
{
    return ai->rpgInfo.postQuest.kind != NewRpgInfo::PostQuest::NONE;
}

bool NewRpgStatusDueTrigger::IsActive()
{
    NewRpgInfo const& info = ai->rpgInfo;
    if (info.abandonMoveFar || info.crossMapMoveFar)
        return true;

    return !info.statusUpdateTs ||
        WorldTimer::getMSTimeDiff(info.statusUpdateTs, WorldTimer::getMSTime()) >= statusUpdateInterval;
}
