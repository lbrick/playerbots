#include "playerbot/playerbot.h"
#include "RaidKaraTriggers.h"
#include "playerbot/strategy/triggers/GenericTriggers.h"
#include "Grids/GridNotifiers.h"
#include "Grids/GridNotifiersImpl.h"
#include "Grids/CellImpl.h"

using namespace ai;

bool NetherspiteBeamsCheatNeedRefreshTrigger::IsActive()
{
    // Check that it is portal phase
    std::list<Unit*> creatures;
    MaNGOS::AllCreaturesOfEntryInRangeCheck u_check(bot, 17369, 100);
    MaNGOS::UnitListSearcher<MaNGOS::AllCreaturesOfEntryInRangeCheck> searcher(creatures, u_check);
    Cell::VisitAllObjects(bot, searcher, 100);

    if (creatures.empty())
        return false;

    // Check that bot is a Netherspite target
    return AI_VALUE2(bool, "has aggro", "current target");
}

bool RemoveNetherPortalPerseverenceTrigger::IsActive()
{
    // Bot is not tank with aggro
    if (ai->IsTank(bot) && AI_VALUE2(bool, "has aggro", "current target"))
        return false;

    return ai->HasAura(30421, bot);
}
