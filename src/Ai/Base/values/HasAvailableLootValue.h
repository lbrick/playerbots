#pragma once
#include "src/Ai/Base/Value.h"
#include "src/Bot/PlayerbotAIConfig.h"

namespace ai
{
    class HasAvailableLootValue : public BoolCalculatedValue
	{
	public:
        HasAvailableLootValue(PlayerbotAI* ai) : BoolCalculatedValue(ai) {}

    public:
        virtual bool Calculate() override
        {
            return !AI_VALUE(bool, "can loot") &&
                    AI_VALUE(LootObjectStack*, "available loot")->CanLoot(sPlayerbotAIConfig.lootDistance);
        }
    };
}
