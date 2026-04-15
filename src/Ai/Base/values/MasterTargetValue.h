#pragma once
#include "src/Ai/Base/Value.h"

namespace ai
{
    class MasterTargetValue : public UnitCalculatedValue
	{
	public:
        MasterTargetValue(PlayerbotAI* ai, std::string name = "master target") : UnitCalculatedValue(ai, name) {}

        virtual Unit* Calculate() override { return ai->GetGroupMaster(); }
    };
}
