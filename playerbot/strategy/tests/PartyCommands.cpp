#include "playerbot/playerbot.h"
#include "PartyCommands.h"
#include "Grids/GridNotifiers.h"
#include "Grids/GridNotifiersImpl.h"
#include "Grids/CellImpl.h"
#include "TestContext.h"
#include "playerbot/PlayerbotMgr.h"

using namespace ai;

TestResult HandleSpawnBot::Execute(const std::string& params, Player* bot, PlayerbotAI* ai, TestContext& ctx, std::string& error)
{
    if (!ai->GetHolder())
    {
        error = "Failed to spawn bot with params: " + params;
        return TestResult::FAIL;
    }
    std::list<std::string> messages;
    ObjectGuid guid;
    ai->GetHolder()->CreateBot(bot, params, messages, guid);

    if (!guid)
    {
        error = "Failed to spawn bot with params: " + params;
        return TestResult::FAIL;
    }

    ctx.spawnedBots.push_back(guid);

    return TestResult::PASS;
}

TestResult HandleDespawnBot::Execute(const std::string& params, Player* bot,
                    PlayerbotAI* ai, TestContext& ctx, std::string& error)
{
    if (!ai->GetHolder())
    {
        error = "Failed to delete spawned bots";
        return TestResult::FAIL;
    }

    for (auto& guid : ctx.spawnedBots)
    {
        ai->GetHolder()->DeleteBot(guid);
    }
    ctx.spawnedBots.clear();
    return TestResult::PASS;
}

TestResult HandleFormParty::Execute(const std::string& params, Player* bot,
                    PlayerbotAI* ai, TestContext& ctx, std::string& error)
{
    return TestResult::PASS;
}

TestResult HandleSpawnGroup::Execute(const std::string& params, Player* bot,
                    PlayerbotAI* ai, TestContext& ctx, std::string& error)
{
    uint32 groupSize = atoi(params.c_str());
    if (groupSize == 0 || groupSize > 50)
    {
        error = "Invalid group size: " + params + ". Use 1-50.";
        return TestResult::FAIL;
    }

    std::ostringstream paramStr;
    paramStr << "group=" << groupSize;

    sRandomPlayerbotMgr.HandleGroup(bot, paramStr.str(), SEC_PLAYER);

    return TestResult::PASS;
}