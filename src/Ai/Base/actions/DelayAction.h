#pragma once

#include "src/Bot/PlayerbotAIConfig.h"
#include "src/Mgr/RandomPlayerbotMgr.h"
#include "src/Util/ServerFacade.h"
#include "src/Ai/Base/Action.h"

namespace ai
{
    class DelayAction : public Action
    {
    public:
        DelayAction(PlayerbotAI* ai) : Action(ai, "delay")
        {}

        virtual bool Execute(Event& event) override
        {
            SetDuration(sPlayerbotAIConfig.passiveDelay + sPlayerbotAIConfig.globalCoolDown);
            return true;
        }

        virtual bool isUseful() override
        {
            return !ai->AllowActivity(ALL_ACTIVITY);
        }
    };
}
