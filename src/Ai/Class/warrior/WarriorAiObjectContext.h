#pragma once

#include "src/Ai/Base/AiObjectContext.h"

namespace ai
{
    class WarriorAiObjectContext : public AiObjectContext
    {
    public:
        WarriorAiObjectContext(PlayerbotAI* ai);
    };
}