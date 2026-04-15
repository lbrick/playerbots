#pragma once
#include "src/Ai/Base/Strategy.h"

namespace ai
{
    class RunawayStrategy : public Strategy
    {
    public:
        RunawayStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "runaway"; }

    private:
        void InitCombatTriggers(std::list<TriggerNode*> &triggers) override;
    };
}
