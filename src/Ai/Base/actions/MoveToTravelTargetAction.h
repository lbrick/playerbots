#pragma once

#include "src/Ai/Base/Action.h"
#include "MovementActions.h"
#include "src/Ai/Base/values/LastMovementValue.h"

namespace ai
{
    class MoveToTravelTargetAction : public MovementAction {
    public:
        MoveToTravelTargetAction(PlayerbotAI* ai) : MovementAction(ai, "move to travel target") {}

        virtual bool Execute(Event& event) override;
        virtual bool isUseful() override;
    };

}
