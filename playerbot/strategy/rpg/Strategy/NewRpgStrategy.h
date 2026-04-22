#pragma once

#include "playerbot/strategy/Strategy.h"
#include "playerbot/strategy/rpg/NewRpgInfo.h"

namespace ai
{

class NewRpgStrategy : public Strategy
{
public:
    NewRpgStrategy(PlayerbotAI* ai) : Strategy(ai) {}

    std::string getName() override { return "new rpg"; }

protected:
    NextAction** GetDefaultNonCombatActions() override;
    void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
};

} // namespace ai
