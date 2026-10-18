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

// The status update is a default action, queued 200 below every trigger action, so it runs only
// on ticks where no status action succeeds. A status action that keeps moving the bot would hold
// it off indefinitely, leaving abandons and status timeouts unapplied (lbrick/cmangos-dev#66).
// This trigger queues it above the status actions when something waits on it.
class NewRpgStatusDueTrigger : public Trigger
{
public:
    NewRpgStatusDueTrigger(PlayerbotAI* ai) : Trigger(ai, "new rpg status due") {}
    bool IsActive() override;

protected:
    static constexpr uint32 statusUpdateInterval = 5 * 1000;
};

} // namespace ai
