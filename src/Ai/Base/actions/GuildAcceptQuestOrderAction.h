
#include "src/Ai/Base/Action.h"
#include "src/Ai/Base/values/GuildValues.h"

namespace ai
{
    // Accepts the specific quest from a guild QuestReward order when near a quest giver.
    class GuildAcceptQuestOrderAction : public Action
    {
    public:
        GuildAcceptQuestOrderAction(PlayerbotAI* ai) : Action(ai, "guild accept quest order") {}

        bool Execute(Event& event) override;
        bool isUseful() override;
    };
}