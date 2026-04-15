#pragma once

#include "src/Ai/Base/AiObjectContext.h"

namespace ai
{
    class RogueAiObjectContext : public AiObjectContext
    {
    public:
        RogueAiObjectContext(PlayerbotAI* ai);
    };
}