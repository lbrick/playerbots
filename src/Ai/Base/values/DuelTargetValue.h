#pragma once
#include "src/Ai/Base/Value.h"
#include "TargetValue.h"

namespace ai
{
    class DuelTargetValue : public TargetValue
	{
	public:
        DuelTargetValue(PlayerbotAI* ai, std::string name = "duel target") : TargetValue(ai, name) {}

    public:
        Unit* Calculate() override;
    };
}
