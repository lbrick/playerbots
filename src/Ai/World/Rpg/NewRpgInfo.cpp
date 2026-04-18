#include "botpch.h"
#include "NewRpgInfo.h"

#include <sstream>
#include "Util/Timer.h"

using namespace ai;

bool NewRpgInfo::HasStatusPersisted(uint32 maxDuration)
{
    return WorldTimer::getMSTimeDiff(startT, WorldTimer::getMSTime()) > maxDuration;
}

void NewRpgInfo::ChangeToGoGrind(WorldPosition pos)
{
    startT = WorldTimer::getMSTime();
    data = GoGrind{pos};
}

void NewRpgInfo::ChangeToGoCamp(WorldPosition pos)
{
    startT = WorldTimer::getMSTime();
    data = GoCamp{pos};
}

void NewRpgInfo::ChangeToWanderNpc()
{
    startT = WorldTimer::getMSTime();
    data = WanderNpc{};
}

void NewRpgInfo::ChangeToWanderRandom()
{
    startT = WorldTimer::getMSTime();
    data = WanderRandom{};
}

void NewRpgInfo::ChangeToDoQuest(uint32 questId, Quest const* quest)
{
    startT = WorldTimer::getMSTime();
    DoQuest do_quest;
    do_quest.questId = questId;
    do_quest.quest   = quest;
    data = do_quest;
}

void NewRpgInfo::ChangeToTravelFlight(ObjectGuid fromFlightMaster, std::vector<uint32> path)
{
    startT = WorldTimer::getMSTime();
    TravelFlight flight;
    flight.fromFlightMaster = fromFlightMaster;
    flight.path   = std::move(path);
    flight.inFlight = false;
    data = flight;
}

void NewRpgInfo::ChangeToRest()
{
    startT = WorldTimer::getMSTime();
    data = Rest{};
}

void NewRpgInfo::ChangeToChangeZone(WorldPosition dest)
{
    startT = WorldTimer::getMSTime();
    data = ChangeZone{dest};
}

void NewRpgInfo::ChangeToIdle()
{
    startT = WorldTimer::getMSTime();
    data = Idle{};
}

bool NewRpgInfo::CanChangeTo(NewRpgStatus /*status*/)
{
    return true;
}

void NewRpgInfo::Reset()
{
    data   = Idle{};
    startT = WorldTimer::getMSTime();
}

void NewRpgInfo::SetMoveFarTo(WorldPosition pos)
{
    nearestMoveFarDis = FLT_MAX;
    stuckTs           = 0;
    stuckAttempts     = 0;
    moveFarPos        = pos;
}

NewRpgStatus NewRpgInfo::GetStatus()
{
    return std::visit([](auto&& arg) -> NewRpgStatus {
        using T = std::decay_t<decltype(arg)>;
        if constexpr (std::is_same_v<T, Idle>)          return RPG_IDLE;
        if constexpr (std::is_same_v<T, GoGrind>)       return RPG_GO_GRIND;
        if constexpr (std::is_same_v<T, GoCamp>)        return RPG_GO_CAMP;
        if constexpr (std::is_same_v<T, WanderNpc>)     return RPG_WANDER_NPC;
        if constexpr (std::is_same_v<T, WanderRandom>)  return RPG_WANDER_RANDOM;
        if constexpr (std::is_same_v<T, Rest>)          return RPG_REST;
        if constexpr (std::is_same_v<T, DoQuest>)       return RPG_DO_QUEST;
        if constexpr (std::is_same_v<T, TravelFlight>)  return RPG_TRAVEL_FLIGHT;
        if constexpr (std::is_same_v<T, ChangeZone>)    return RPG_CHANGE_ZONE;
        return RPG_IDLE;
    }, data);
}

std::string NewRpgInfo::ToString()
{
    std::stringstream out;
    out << "Status: ";
    std::visit([&out, this](auto&& arg)
    {
        using T = std::decay_t<decltype(arg)>;
        if constexpr (std::is_same_v<T, GoGrind>)
        {
            out << "GO_GRIND";
            out << "\nGrindPos: " << arg.pos.getMapId() << " " << arg.pos.getX() << " "
                << arg.pos.getY() << " " << arg.pos.getZ();
            out << "\nlastGoGrind: " << startT;
        }
        else if constexpr (std::is_same_v<T, GoCamp>)
        {
            out << "GO_CAMP";
            out << "\nCampPos: " << arg.pos.getMapId() << " " << arg.pos.getX() << " "
                << arg.pos.getY() << " " << arg.pos.getZ();
            out << "\nlastGoCamp: " << startT;
        }
        else if constexpr (std::is_same_v<T, WanderNpc>)
        {
            out << "WANDER_NPC";
            out << "\nnpcOrGo: " << arg.npcOrGo.GetCounter();
            out << "\nlastWanderNpc: " << startT;
            out << "\nlastReachNpcOrGo: " << arg.lastReach;
        }
        else if constexpr (std::is_same_v<T, WanderRandom>)
        {
            out << "WANDER_RANDOM";
            out << "\nlastWanderRandom: " << startT;
        }
        else if constexpr (std::is_same_v<T, Idle>)
        {
            out << "IDLE";
        }
        else if constexpr (std::is_same_v<T, Rest>)
        {
            out << "REST";
            out << "\nlastRest: " << startT;
        }
        else if constexpr (std::is_same_v<T, DoQuest>)
        {
            out << "DO_QUEST";
            out << "\nquestId: " << arg.questId;
            out << "\nobjectiveIdx: " << arg.objectiveIdx;
            out << "\npoiPos: " << arg.pos.getMapId() << " " << arg.pos.getX() << " "
                << arg.pos.getY() << " " << arg.pos.getZ();
            out << "\nlastReachPOI: " << (arg.lastReachPOI ? WorldTimer::getMSTimeDiff(arg.lastReachPOI, WorldTimer::getMSTime()) : 0);
        }
        else if constexpr (std::is_same_v<T, TravelFlight>)
        {
            out << "TRAVEL_FLIGHT";
            out << "\nfromFlightMaster: " << arg.fromFlightMaster.GetEntry();
            out << "\nfromNode: " << arg.path[0];
            out << "\ntoNode: " << arg.path[arg.path.size() - 1];
            out << "\ninFlight: " << arg.inFlight;
        }
        else if constexpr (std::is_same_v<T, ChangeZone>)
        {
            out << "CHANGE_ZONE";
            out << "\ndest: " << arg.dest.getMapId() << " " << arg.dest.getX()
                << " " << arg.dest.getY() << " " << arg.dest.getZ();
        }
        else
            out << "UNKNOWN";
    }, data);
    return out.str();
}
