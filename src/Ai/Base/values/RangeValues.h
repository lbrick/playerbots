#pragma once
#include "src/Ai/Base/Value.h"

namespace ai
{
    class RangeValue : public ManualSetValue<float>, public Qualified
	{
	public:
        RangeValue(PlayerbotAI* ai);
        virtual std::string Save() override;
        virtual bool Load(std::string value) override;
    };
}
