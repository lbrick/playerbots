#pragma once
#include "MovementActions.h"
#include "ChangeStrategyAction.h"
#include "src/Ai/Base/values/HazardsValue.h"

namespace ai
{
    class MoveAwayFromHazard : public MovementAction
    {
    public:
        MoveAwayFromHazard(PlayerbotAI* ai, std::string name = "move away from hazard") : MovementAction(ai, name) {}
        bool Execute(Event& event) override;
        bool isPossible() override;

#ifdef GenerateBotHelp
        virtual std::string GetHelpName() { return "move away from hazard"; }
        virtual std::string GetHelpDescription()
        {
            return "This action makes the bot move away from hazardous areas in dungeons.\n"
                   "It identifies dangerous positions and navigates to a safer location.";
        }
        virtual std::vector<std::string> GetUsedActions() { return {}; }
        virtual std::vector<std::string> GetUsedValues() { return {"hazards"}; }
#endif 

    private:
        bool IsHazardNearby(const WorldPosition& point, const std::list<HazardPosition>& hazards) const;
    };

    class MoveAwayFromCreature : public MovementAction
    {
    public:
        MoveAwayFromCreature(PlayerbotAI* ai, std::string name, uint32 creatureID, float range) : MovementAction(ai, name), creatureID(creatureID), range(range) {}
        bool Execute(Event& event) override;
        bool isPossible() override;

#ifdef GenerateBotHelp
        virtual std::string GetHelpName() { return "move away from creature"; }
        virtual std::string GetHelpDescription()
        {
            return "This action makes the bot move away from a specific creature in dungeons.\n"
                   "It maintains a safe distance from the specified creature ID within a defined range.";
        }
        virtual std::vector<std::string> GetUsedActions() { return {}; }
        virtual std::vector<std::string> GetUsedValues() { return {"hazards"}; }
#endif 

    private:
        bool IsValidPoint(const WorldPosition& point, const std::list<Creature*>& creatures, const std::list<HazardPosition>& hazards);
        bool HasCreaturesNearby(const WorldPosition& point, const std::list<Creature*>& creatures) const;
        bool IsHazardNearby(const WorldPosition& point, const std::list<HazardPosition>& hazards) const;

    private:
        uint32 creatureID;
        float range;
    };

    // Logged wrapper around ChangeAllStrategyAction — logs strategy change to Server.log.
    // All dungeon enable/disable strategy actions should extend this instead of ChangeAllStrategyAction.
    class LoggedChangeAllStrategyAction : public ChangeAllStrategyAction
    {
    public:
        LoggedChangeAllStrategyAction(PlayerbotAI* ai, std::string name, std::string strategy)
            : ChangeAllStrategyAction(ai, name, strategy) {}
        bool Execute(Event& event) override
        {
            sLog.outDetail("Bot %s: dungeon strategy action [%s]", ai->GetBot()->GetName(), getName().c_str());
            return ChangeAllStrategyAction::Execute(event);
        }
    };

    // Class-agnostic interrupt action for dungeon strategies.
    // Tries each known interrupt ability in priority order; casts first available.
    class InterruptEnemyCastAction : public Action
    {
    public:
        InterruptEnemyCastAction(PlayerbotAI* ai) : Action(ai, "interrupt enemy cast") {}
        bool Execute(Event& event) override;
    };
}
