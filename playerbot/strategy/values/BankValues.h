#pragma once
#include "playerbot/strategy/Value.h"
#include "ItemUsageValue.h"

namespace ai
{
    class ShouldBankDepositValue : public BoolCalculatedValue
    {
    public:
        // Recomputed every 5 minutes (half the interval): it rates the bank usage of every bag item,
        // 4.1 ms per check with 400 bots, and bags change slowly (lbrick/cmangos-dev#99).
        ShouldBankDepositValue(PlayerbotAI* ai) : BoolCalculatedValue(ai, "should bank deposit", 600) {}
        virtual bool Calculate() override;
    };

    class ShouldBankWithdrawValue : public BoolCalculatedValue
    {
    public:
        ShouldBankWithdrawValue(PlayerbotAI* ai) : BoolCalculatedValue(ai, "should bank withdraw", 5) {}
        virtual bool Calculate() override;
    };

#ifndef MANGOSBOT_ZERO
    class ShouldGuildBankDepositValue : public BoolCalculatedValue
    {
    public:
        ShouldGuildBankDepositValue(PlayerbotAI* ai) : BoolCalculatedValue(ai, "should guild bank deposit", 5) {}
        virtual bool Calculate() override;
    };

    class ShouldGuildBankWithdrawValue : public BoolCalculatedValue
    {
    public:
        ShouldGuildBankWithdrawValue(PlayerbotAI* ai) : BoolCalculatedValue(ai, "should guild bank withdraw", 5) {}
        virtual bool Calculate() override;
    };
#endif
}
