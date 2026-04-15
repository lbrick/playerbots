#pragma once

#include "src/Ai/Base/Action.h"
#include "ChangeStrategyAction.h"

namespace ai
{
    class SwitchToMeleeAction : public ChangeCombatStrategyAction
    {
    public:
        SwitchToMeleeAction(PlayerbotAI* ai) : ChangeCombatStrategyAction(ai, "-ranged,+close") {}
        bool isUseful() override;
        bool Execute(Event& event) override;
    };

    class SwitchToRangedAction : public ChangeCombatStrategyAction
    {
    public:
        SwitchToRangedAction(PlayerbotAI* ai) : ChangeCombatStrategyAction(ai, "-close,+ranged") {}
        bool isUseful() override;
        bool Execute(Event& event) override;
    };
}
