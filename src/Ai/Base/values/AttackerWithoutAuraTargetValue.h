#pragma once
#include "src/Ai/Base/Value.h"

namespace ai
{
    class AttackerWithoutAuraTargetValue : public UnitCalculatedValue, public Qualified
	{
	public:
        AttackerWithoutAuraTargetValue(PlayerbotAI* ai) : UnitCalculatedValue(ai, "attacker without aura"), Qualified() {}

    protected:
        virtual Unit* Calculate() override;
	};
}
