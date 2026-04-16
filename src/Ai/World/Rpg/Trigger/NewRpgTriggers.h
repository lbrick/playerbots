#pragma once

#include "src/Ai/Base/Trigger.h"
#include "src/Ai/World/Rpg/NewRpgInfo.h"

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
