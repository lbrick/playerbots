#pragma once

#include "src/Ai/Base/Action.h"
#include "MovementActions.h"
#include "src/Bot/Factory/AiFactory.h"
#include "src/Bot/PlayerbotAIConfig.h"

namespace ai
{
    class EnterVehicleAction : public MovementAction
    {
    public:
        EnterVehicleAction(PlayerbotAI* ai, std::string name = "enter vehicle") : MovementAction(ai, name) {}
        virtual bool Execute(Event& event) override;
        //virtual bool isUseful() override;
    };

    class LeaveVehicleAction : public MovementAction
    {
    public:
        LeaveVehicleAction(PlayerbotAI* ai, std::string name = "leave vehicle") : MovementAction(ai, name) {}
        virtual bool Execute(Event& event) override;
        //virtual bool isUseful() override;
    };
}
