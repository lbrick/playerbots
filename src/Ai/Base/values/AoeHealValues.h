#pragma once
#include "src/Ai/Base/Value.h"

namespace ai
{
    class AoeHealValue : public Uint8CalculatedValue, public Qualified
	{
	public:
    	AoeHealValue(PlayerbotAI* ai, std::string name = "aoe heal") : Uint8CalculatedValue(ai, name, 3), Qualified() {}

    public:
    	virtual uint8 Calculate() override;
    };
}
