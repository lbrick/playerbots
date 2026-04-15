#pragma once
#include "src/Ai/Base/Value.h"

namespace ai
{
    class SnareTargetValue : public UnitCalculatedValue, public Qualified
	{
	public:
        SnareTargetValue(PlayerbotAI* ai) :
            UnitCalculatedValue(ai, "snare target"), Qualified() {}

    protected:
        virtual Unit* Calculate() override;
	};
}
