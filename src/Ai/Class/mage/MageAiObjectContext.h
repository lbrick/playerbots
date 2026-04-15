#pragma once

#include "src/Ai/Base/AiObjectContext.h"

namespace ai
{
    class MageAiObjectContext : public AiObjectContext
    {
    public:
        MageAiObjectContext(PlayerbotAI* ai);
    };
}