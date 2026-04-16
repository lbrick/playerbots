#include "src/Bot/Engine/playerbot.h"
#include "NewRpgTriggers.h"

using namespace ai;

bool NewRpgStatusTrigger::IsActive()
{
    return status == ai->rpgInfo.GetStatus();
}
