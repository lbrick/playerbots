#pragma once

#include "Entities/ObjectGuid.h"
#include "Quests/QuestDef.h"
#include "playerbot/WorldPosition.h"
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
    RPG_CHANGE_ZONE    = 8,
    RPG_STATUS_END     = 9,
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
    // RPG_CHANGE_ZONE
    struct ChangeZone
    {
        WorldPosition dest{};
        struct Waypoint
        {
            WorldPosition pos;
            bool teleport{false};  // true = TeleportTo (transport dock-to-dock), false = MoveFarTo
            WorldPosition from{};  // teleport only: the source dock the bot must reach first
            // Transport legs only (lbrick/cmangos-dev#51): the transport GO entry and the transport's
            // stop positions at the source and destination docks. 0 = no transport (a portal).
            uint32 transportEntry{0};
            WorldPosition boardStop{};
            WorldPosition alightStop{};
            uint32 waitStartT{0};  // when the bot started waiting at the source dock; 0 = not yet
            // Teleport-spell legs only (lbrick/cmangos-dev#76): the hearthstone or class teleport
            // spell the bot casts, when it last cast it, and how many casts it has made.
            uint32 spell{0};
            uint32 castT{0};
            uint32 castTries{0};
        };
        std::vector<Waypoint> waypoints{};   // TravelNode multi-hop path; empty = direct
        bool waypointsBuilt{false};          // true after first TravelNode build — no rebuild
        std::vector<WorldPosition> rejectedTransportDocks{};  // BUG-2: cache bad destDock coords to skip on rebuild
        uint32 progressT{0};  // last completed waypoint or transport leg; the timeout counts from here
        bool noTeleportSpells{false};  // a teleport-spell leg failed: rebuild without them (#76)
    };
    struct Idle
    {
    };

    uint32 startT{0};  // start timestamp of the current status

    // Post-quest routine (lbrick/cmangos-dev#45): a pause, or a vendor or trainer visit, after a
    // quest accept or turn-in. Held beside the status, so a status change does not cut it short.
    struct PostQuest
    {
        enum Kind : uint8 { NONE = 0, ACCEPT = 1, TURN_IN = 2 };
        enum Routine : uint8 { PAUSE = 0, VENDOR = 1, TRAINER = 2 };
        Kind kind{NONE};
        Routine routine{PAUSE};
        ObjectGuid giver{};
        ObjectGuid target{};   // vendor or trainer
        uint32 startT{0};
        uint32 pauseMs{0};
        uint32 reachT{0};      // pause begun, or vendor or trainer reached; 0 = not yet
    };
    PostQuest postQuest;

    // MOVE_FAR
    float nearestMoveFarDis{FLT_MAX};
    uint32 stuckTs{0};
    uint32 stuckAttempts{0};
    WorldPosition moveFarPos;
    // Last stuck teleport, checked once a few seconds later (AiPlayerbot.LogRpgTravelEvents)
    WorldPosition stuckTeleportFrom;
    WorldPosition stuckTeleportTo;
    uint32 stuckTeleportTs{0};
    bool stuckTeleportOk{false};
    // Target of the last transport-leg teleport, logged with the landing position once the
    // teleport completes (AiPlayerbot.LogRpgTravelEvents, lbrick/cmangos-dev#79)
    WorldPosition legTeleportTo;
    // When the pending abandon flag was first set (evidence for lbrick/cmangos-dev#66), and when the
    // status update last ran ("new rpg status due" queues it again after 5 s).
    uint32 abandonFlagTs{0};
    uint32 statusUpdateTs{0};
    // Set when the bot is stuck again on a position it already stuck-teleported to; the status
    // update drops the current status if it is still the one that started at abandonStartT.
    bool abandonMoveFar{false};
    uint32 abandonStartT{0};
    // Set when the move target is on another map than the bot (lbrick/cmangos-dev#67); the status
    // update drops the current status if it is still the one that started at crossMapStartT.
    bool crossMapMoveFar{false};
    // ChangeZoneSampleSeconds diagnostic (lbrick/cmangos-dev#74): MoveFarTo calls since the last
    // sample, and the branch and result of the latest one.
    uint32 moveFarCalls{0};
    const char* moveFarStep{"none"};
    bool moveFarResult{false};
    uint32 crossMapStartT{0};
    // END MOVE_FAR

    using RpgData = std::variant<
        Idle,
        GoGrind,
        GoCamp,
        WanderNpc,
        WanderRandom,
        DoQuest,
        Rest,
        TravelFlight,
        ChangeZone
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
    void ChangeToChangeZone(WorldPosition dest);
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
