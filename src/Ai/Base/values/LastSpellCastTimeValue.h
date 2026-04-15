#pragma once
#include "src/Ai/Base/Value.h"

namespace ai
{
    class LastSpellCastTimeValue : public ManualSetValue<time_t>, public Qualified
	{
	public:
        LastSpellCastTimeValue(PlayerbotAI* ai) : ManualSetValue<time_t>(ai, 0), Qualified() {}
    };
}
