#pragma once
#include "src/Ai/Base/Action.h"
#include "src/Ai/Base/values/GuildValues.h"

namespace ai
{
    class GuildCraftOrderAction : public Action
    {
    public:
        GuildCraftOrderAction(PlayerbotAI* ai) : Action(ai, "guild craft order") {}

        bool Execute(Event& event) override;
        bool isUseful() override;

    private:
        uint32 FindCraftSpell(uint32 itemId);
    };
}