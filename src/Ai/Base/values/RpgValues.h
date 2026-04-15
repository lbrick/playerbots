#pragma once
#include "src/Ai/Base/Value.h"

namespace ai
{
    class NextRpgActionValue : public ManualSetValue<std::string>
	{
	public:
        NextRpgActionValue(PlayerbotAI* ai, std::string defaultValue = "", std::string name = "next rpg action") : ManualSetValue(ai, defaultValue, name) {};
    };
}
