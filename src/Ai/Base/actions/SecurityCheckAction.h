#pragma once

#include "src/Ai/Base/Action.h"

namespace ai
{
    class SecurityCheckAction : public Action
    {
    public:
        SecurityCheckAction(PlayerbotAI* ai) : Action(ai, "security check") {}
        virtual bool isUseful() override;
        virtual bool Execute(Event& event) override;
        virtual bool isUsefulWhenStunned() override { return true; }
    };
}
