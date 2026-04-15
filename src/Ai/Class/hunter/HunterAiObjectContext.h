#pragma once

#include "src/Ai/Base/AiObjectContext.h"

namespace ai
{
    class HunterAiObjectContext : public AiObjectContext
    {
    public:
        HunterAiObjectContext(PlayerbotAI* ai);
    };
}