#pragma once

#include "src/Ai/Base/AiObjectContext.h"

namespace ai
{
    class WarlockAiObjectContext : public AiObjectContext
    {
    public:
        WarlockAiObjectContext(PlayerbotAI* ai);
    };
}