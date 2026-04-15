#pragma once

#include "src/Ai/Base/Action.h"
#include "QuestAction.h"

namespace ai
{
    class CheckValuesAction : public Action
    {
    public:
        CheckValuesAction(PlayerbotAI* ai);
        virtual bool Execute(Event& event) override;
    };
}
