#pragma once

#include "src/Ai/Base/AiObjectContext.h"

namespace ai
{
    class PriestAiObjectContext : public AiObjectContext
    {
    public:
        PriestAiObjectContext(PlayerbotAI* ai);
    };
}