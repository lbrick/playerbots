#pragma once

#include "src/Ai/Base/AiObjectContext.h"

namespace ai
{
    class DruidAiObjectContext : public AiObjectContext
    {
    public:
        DruidAiObjectContext(PlayerbotAI* ai);
    };
}