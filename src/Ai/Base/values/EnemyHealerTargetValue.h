#pragma once
#include "src/Ai/Base/Value.h"

namespace ai
{
    class EnemyHealerTargetValue : public UnitCalculatedValue, public Qualified
	{
	public:
        EnemyHealerTargetValue(PlayerbotAI* ai) : UnitCalculatedValue(ai, "enemy healer target"), Qualified() {}

    protected:
        virtual Unit* Calculate() override;
	};
}
