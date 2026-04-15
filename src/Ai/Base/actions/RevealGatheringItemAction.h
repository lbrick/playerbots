#pragma once

#include "src/Ai/Base/Action.h"
#include "MovementActions.h"
#include "src/Ai/Base/values/LastMovementValue.h"

namespace ai
{
    class RevealGatheringItemAction : public Action {
    public:
        RevealGatheringItemAction(PlayerbotAI* ai) : Action(ai, "reveal gathering item") {}

        virtual bool Execute(Event& event) override;
        virtual bool isUsefulWhenStunned() override { return true; }
    };

}
