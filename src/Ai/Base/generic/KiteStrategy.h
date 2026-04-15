#pragma once
#include "src/Ai/Base/Strategy.h"

namespace ai
{
    class KiteStrategy : public Strategy
    {
    public:
        KiteStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "kite"; }
    
    private:
        void InitCombatTriggers(std::list<TriggerNode*> &triggers) override;
    };
}
