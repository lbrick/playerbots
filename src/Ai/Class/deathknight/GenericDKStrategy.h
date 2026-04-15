#pragma once
#include "src/Ai/Base/generic/MeleeCombatStrategy.h"

namespace ai
{
    class GenericDKStrategy : public CombatStrategy
    {
    public:
        GenericDKStrategy(PlayerbotAI* ai);
        virtual std::string getName() override { return "DK"; }

    protected:
        virtual void InitCombatTriggers(std::list<TriggerNode*> &triggers) override;
    };
}
