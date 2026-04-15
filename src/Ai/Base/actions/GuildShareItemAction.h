#pragma once
#include "src/Ai/Base/Action.h"
#include "src/Ai/Base/values/GuildValues.h"

namespace ai
{
    class GuildShareItemAction : public Action
    {
    public:
        GuildShareItemAction(PlayerbotAI* ai) : Action(ai, "guild share item") {}

        bool Execute(Event& event) override;
        bool isUseful() override;
    };
}