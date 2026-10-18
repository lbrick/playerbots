#pragma once

#include "TestComponent.h"

namespace ai
{
    // =====================================================
    // MonitorMovement - movement-related monitors
    // =====================================================
    class MonitorMovementDistance : public TestMonitor
    {
    protected:
        bool IsConditionMet(const std::string& monitorStr, Player* bot, TestContext& ctx) const override;
    private:
        std::string GetName() const override { return "distance to"; }
    };

    // "distance to" that only holds while the bot has never been a transport passenger in this test:
    // placed before the pass check, it fails a transport test the bot completed by teleporting.
    class MonitorMovementDistanceWithoutRiding : public MonitorMovementDistance
    {
    private:
        bool IsConditionMet(const std::string& monitorStr, Player* bot, TestContext& ctx) const override;
        std::string GetName() const override { return "distance without riding to"; }
    };

    class MonitorNotOnMap : public TestMonitor
    {
    private:
        bool IsConditionMet(const std::string& monitorStr, Player* bot, TestContext& ctx) const override;
        std::string GetName() const override { return "not on map"; }
    };

    class MonitorMovementUnderground : public TestMonitor
    {
    private:
        bool IsConditionMet(const std::string& monitorStr, Player* bot, TestContext& ctx) const override;
        std::string GetName() const override { return "underground"; }
    };

    class MonitorMovementCanNotReachNodes : public TestMonitor
    {
    private:
        bool IsConditionMet(const std::string& monitorStr, Player* bot, TestContext& ctx) const override;
        std::string GetName() const override { return "can not reach nodes"; }
    };

    class MonitorMovementSpeed : public TestMonitor
    {
    private:
        bool IsConditionMet(const std::string& monitorStr, Player* bot, TestContext& ctx) const override;
        std::string GetName() const override { return "speed"; }
    };

    class MonitorMovementSpawnDistance : public TestMonitor
    {
    private:
        bool IsConditionMet(const std::string& monitorStr, Player* bot, TestContext& ctx) const override;
        std::string GetName() const override { return "spawn distance"; }
    };
}