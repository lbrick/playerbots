#pragma once
#include "src/Ai/Base/AiObjectContext.h"

namespace ai
{
    class PaladinAiObjectContext : public AiObjectContext
    {
    public:
        PaladinAiObjectContext(PlayerbotAI* ai);
    };
}