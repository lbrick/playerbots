#pragma once

#include "src/Bot/Engine/playerbot.h"
#include "src/Ai/Base/Trigger.h"
#include "src/Ai/Base/triggers/GenericTriggers.h"

namespace ai
{
    class ApplyGlyphTrigger : public RandomTrigger
    {
    public:
        ApplyGlyphTrigger(PlayerbotAI* ai, std::string triggerName = "apply glyphs") : RandomTrigger(ai, triggerName, 60) {}
        virtual bool IsActive() override
        {
            if (bot->GetLevel() < 15)
                return false;

            return RandomTrigger::IsActive();
        }
    };   
}