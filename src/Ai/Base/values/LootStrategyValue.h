#pragma once
#include "src/Mgr/LootObjectStack.h"
#include "src/Ai/Base/Value.h"
#include "SubStrategyValue.h"

namespace ai
{
    class LootStrategyValue : public SubStrategyValue
	{
	public:
        LootStrategyValue(PlayerbotAI* ai, std::string defaultValue = "equip,quest,skill,disenchant,use,vendor", std::string name = "loot strategy", std::string allowedValues = "equip,quest,skill,disenchant,use,vendor,trash") : SubStrategyValue(ai, defaultValue, name, allowedValues) {}

        virtual void Set(std::string newValue) override;

        static bool CanLoot(ItemQualifier& itemQualifier, PlayerbotAI* ai);
    };
}
