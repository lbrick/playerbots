#pragma once

#include "Entities/ObjectGuid.h"
#include "Quests/QuestDef.h"
#include "src/Util/WorldPosition.h"
#include <variant>

// NewRpgStatus is declared in PlayerbotAIConfig.h — include order handled via botpch.h

namespace ai
{

enum NewRpgStatus : int
{
    RPG_IDLE           = 0,
    RPG_GO_GRIND       = 1,
    RPG_GO_CAMP        = 2,
    RPG_WANDER_RANDOM  = 3,
    RPG_WANDER_NPC     = 4,
    RPG_DO_QUEST       = 5,
    RPG_TRAVEL_FLIGHT  = 6,
    RPG_REST           = 7,
    RPG_STATUS_END     = 8,
};

using NewRpgStatusTransitionProb = std::vector<std::vector<int>>;

struct NewRpgInfo
{
    NewRpgInfo() : data(Idle{}) {}
    ~NewRpgInfo() = default;

    // RPG_GO_GRIND
    struct GoGrind
    {
        WorldPosition pos{};
    };
    // RPG_GO_CAMP
    struct GoCamp
    {
        WorldPosition pos{};
    };
    // RPG_WANDER_NPC
    struct WanderNpc
    {
        ObjectGuid npcOrGo{};
        uint32 lastReach{0};
    };
    // RPG_WANDER_RANDOM
    struct WanderRandom
    {
        WanderRandom() = default;
    };
    // RPG_DO_QUEST
    struct DoQuest
    {
        Quest const* quest{nullptr};
        uint32 questId{0};
        int32 objectiveIdx{0};
        WorldPosition pos{};
        uint32 lastReachPOI{0};
    };
    // RPG_TRAVEL_FLIGHT
    struct TravelFlight
    {
        ObjectGuid fromFlightMaster{};
        std::vector<uint32> path;
        bool inFlight{false};
    };
    // RPG_REST
    struct Rest
    {
        Rest() = default;
    };
    struct Idle
    {
    };

    uint32 startT{0};  // start timestamp of the current status

    // MOVE_FAR
    float nearestMoveFarDis{FLT_MAX};
    uint32 stuckTs{0};
    uint32 stuckAttempts{0};
    WorldPosition moveFarPos;
    // END MOVE_FAR

    using RpgData = std::variant<
        Idle,
        GoGrind,
        GoCamp,
        WanderNpc,
        WanderRandom,
        DoQuest,
        Rest,
        TravelFlight
    >;
    RpgData data;

    NewRpgStatus GetStatus();
    bool HasStatusPersisted(uint32 maxDuration);
    void ChangeToGoGrind(WorldPosition pos);
    void ChangeToGoCamp(WorldPosition pos);
    void ChangeToWanderNpc();
    void ChangeToWanderRandom();
    void ChangeToDoQuest(uint32 questId, Quest const* quest);
    void ChangeToTravelFlight(ObjectGuid fromFlightMaster, std::vector<uint32> path);
    void ChangeToRest();
    void ChangeToIdle();
    bool CanChangeTo(NewRpgStatus status);
    void Reset();
    void SetMoveFarTo(WorldPosition pos);
    std::string ToString();
};

struct NewRpgStatistic
{
    uint32 questAccepted{0};
    uint32 questCompleted{0};
    uint32 questAbandoned{0};
    uint32 questRewarded{0};
    uint32 questDropped{0};

    NewRpgStatistic operator+(const NewRpgStatistic& other) const
    {
        NewRpgStatistic result;
        result.questAccepted  = questAccepted  + other.questAccepted;
        result.questCompleted = questCompleted + other.questCompleted;
        result.questAbandoned = questAbandoned + other.questAbandoned;
        result.questRewarded  = questRewarded  + other.questRewarded;
        result.questDropped   = questDropped   + other.questDropped;
        return result;
    }
    NewRpgStatistic& operator+=(const NewRpgStatistic& other)
    {
        questAccepted  += other.questAccepted;
        questCompleted += other.questCompleted;
        questAbandoned += other.questAbandoned;
        questRewarded  += other.questRewarded;
        questDropped   += other.questDropped;
        return *this;
    }
};

} // namespace ai
