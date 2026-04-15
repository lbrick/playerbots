#pragma once
#include "src/Ai/Base/Strategy.h"

namespace ai
{
    class PassiveStrategy : public Strategy
    {
    public:
        PassiveStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "passive"; }

    private:
        void InitNonCombatMultipliers(std::list<Multiplier*> &multipliers) override;
        void InitCombatMultipliers(std::list<Multiplier*>& multipliers) override;
    };
}
