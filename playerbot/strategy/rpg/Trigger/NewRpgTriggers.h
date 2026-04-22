#pragma once

#include "playerbot/strategy/Trigger.h"
#include "playerbot/strategy/rpg/NewRpgInfo.h"

namespace ai
{

class NewRpgStatusTrigger : public Trigger
{
public:
    NewRpgStatusTrigger(PlayerbotAI* ai, NewRpgStatus status = RPG_IDLE)
        : Trigger(ai, "new rpg status"), status(status)
    {
    }
    bool IsActive() override;

protected:
    NewRpgStatus status;
};

} // namespace ai
