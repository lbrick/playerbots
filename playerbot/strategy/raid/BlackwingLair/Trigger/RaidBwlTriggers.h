#pragma once
#include "playerbot/strategy/triggers/DungeonTriggers.h"
#include "playerbot/strategy/triggers/GenericTriggers.h"

namespace ai
{
    class BlackwingLairEnterDungeonTrigger : public EnterDungeonTrigger
    {
    public:
        BlackwingLairEnterDungeonTrigger(PlayerbotAI* ai) : EnterDungeonTrigger(ai, "enter blackwing lair", "blackwing lair", 469) {}
    };

    class BlackwingLairLeaveDungeonTrigger : public LeaveDungeonTrigger
    {
    public:
        BlackwingLairLeaveDungeonTrigger(PlayerbotAI* ai) : LeaveDungeonTrigger(ai, "leave blackwing lair", "blackwing lair", 469) {}
    };

    class SuppressionDeviceNeedStealthTrigger : public Trigger
    {
    public:
        SuppressionDeviceNeedStealthTrigger(PlayerbotAI* ai) : Trigger(ai, "suppression device need stealth", 1) {}
        bool IsActive() override;
    };

    class SuppressionDeviceInSightTrigger : public Trigger
    {
    public:
        SuppressionDeviceInSightTrigger(PlayerbotAI* ai) : Trigger(ai, "suppression device in sight", 1) {}
        bool IsActive() override;
    };

    class SuppressionDeviceCloseTrigger : public Trigger
    {
    public:
        SuppressionDeviceCloseTrigger(PlayerbotAI* ai) : Trigger(ai, "suppression device close", 1) {}
        bool IsActive() override;
    };
}
