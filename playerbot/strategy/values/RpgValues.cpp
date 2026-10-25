
#include "playerbot/playerbot.h"
#include "RpgValues.h"

using namespace ai;

bool NewRpgMacroActiveValue::Calculate()
{
    if (!ai->HasStrategy("new rpg", BotState::BOT_STATE_NON_COMBAT))
        return false;

    return ai->rpgInfo.GetStatus() != RPG_IDLE;
}
