#pragma once
#include "src/Ai/Base/Value.h"


namespace ai
{
    class TimeSinceLastChangeValue : public Uint32CalculatedValue, public Qualified
    {
    public:
        TimeSinceLastChangeValue(PlayerbotAI* ai, std::string name = "time since last change") : Uint32CalculatedValue(ai, name), Qualified() {}
        
        virtual uint32 Calculate() override;
    };

    class DistanceMovedSinceValue : public Uint32CalculatedValue, public Qualified
    {
    public:
        DistanceMovedSinceValue(PlayerbotAI* ai, std::string name = "distance moved since") : Uint32CalculatedValue(ai, name) {}
        virtual uint32 Calculate() override;
    };
}
