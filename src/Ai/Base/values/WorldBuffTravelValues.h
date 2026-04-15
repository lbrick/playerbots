#pragma once
#include "src/Ai/Base/Value.h"

namespace ai
{
    class WorldBuffTravelStepValue : public ManualSetValue<uint8>
    {
    public:
        WorldBuffTravelStepValue(PlayerbotAI* ai)
            : ManualSetValue<uint8>(ai, 0, "world buff travel step") {}
    };
}