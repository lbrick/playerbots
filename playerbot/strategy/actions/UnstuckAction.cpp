#include "playerbot/playerbot.h"
#include "UnstuckAction.h"
#include "playerbot/strategy/rpg/NewRpgInfo.h"

// A hearthstone or repop sends a bot on a change-zone trip back across the map. A trip that
// made progress in the last 5 minutes is not stuck, so it gets a reset instead
// (lbrick/cmangos-dev#93).
bool UnstuckAction::TripProgressing(Event& event)
{
    auto* cz = std::get_if<NewRpgInfo::ChangeZone>(&ai->rpgInfo.data);
    if (!cz)
        return false;

    uint32 progressS = WorldTimer::getMSTimeDiff(cz->progressT, WorldTimer::getMSTime()) / IN_MILLISECONDS;
    bool progressing = progressS < 5 * MINUTE;
    if (sPlayerbotAIConfig.logRpgTravelEvents)
        sLog.outString("[New RPG travel] bot=%s event=unstuck_far source=%s progress_s=%u skipped=%u",
            bot->GetName(), event.getSource().c_str(), progressS, progressing ? 1u : 0u);
    return progressing;
}

bool UnstuckAction::Execute(Event& event)
{
    std::string source = event.getSource();
    Player* bot = ai->GetBot();
    Player* master = ai->GetMaster();

    // Default action if no specific source is matched
    if (source.empty())
    {
        ai->TellDebug(master, "Unstuck: No specific source, resetting.", "debug unstuck");
        return ai->DoSpecificAction("reset", event, true);
    }

    // Handle move stuck scenarios
    if (source.find("move stuck") != std::string::npos)
    {
        ai->TellDebug(master, "Unstuck: Move stuck detected, resetting.", "debug unstuck");
        return ai->DoSpecificAction("reset", event, true);
    }

    // Handle long move stuck scenarios
    if (source.find("move long stuck") != std::string::npos)
    {
        ai->TellDebug(master, "Unstuck: Long move stuck detected, attempting hearthstone or repop.", "debug unstuck");
        if (TripProgressing(event))
            return ai->DoSpecificAction("reset", event, true);
        if (AI_VALUE2(bool, "action useful", "hearthstone") && bot->IsAlive())
        {
            return ai->DoSpecificAction("hearthstone", event, true);
        }
        else
        {
            return ai->DoSpecificAction("repop", event, true);
        }
    }

    // Handle combat stuck scenarios
    if (source.find("combat stuck") != std::string::npos)
    {
        ai->TellDebug(master, "Unstuck: Combat stuck detected, resetting position.", "debug unstuck");
        return ai->DoSpecificAction("reset", event, true);
    }

    // Handle long combat stuck scenarios
    if (source.find("combat long stuck") != std::string::npos)
    {
        ai->TellDebug(master, "Unstuck: Long combat stuck detected, attempting hearthstone or repop.", "debug unstuck");
        if (TripProgressing(event))
            return ai->DoSpecificAction("reset", event, true);
        if (AI_VALUE2(bool, "action useful", "hearthstone") && bot->IsAlive())
        {
            return ai->DoSpecificAction("hearthstone", event, true);
        }
        else
        {
            return ai->DoSpecificAction("repop", event, true);
        }
    }

    // Fallback to reset if no specific condition is met
    ai->TellDebug(master, "Unstuck: Fallback to reset action.", "debug unstuck");
    return ai->DoSpecificAction("reset", event, true);
}
