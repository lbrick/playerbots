#pragma once

#include "src/Ai/Base/AiObjectContext.h"

namespace ai
{
    class DKAiObjectContext : public AiObjectContext
    {
    public:
        DKAiObjectContext(PlayerbotAI* ai);
    };
}