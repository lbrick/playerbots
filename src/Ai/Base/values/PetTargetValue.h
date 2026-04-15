#pragma once
#include "src/Ai/Base/Value.h"

namespace ai
{
    class PetTargetValue : public UnitCalculatedValue
	{
	public:
        PetTargetValue(PlayerbotAI* ai, std::string name = "pet target") : UnitCalculatedValue(ai, name) {}

        virtual Unit* Calculate() override { return (Unit*)(ai->GetBot()->GetPet()); }
    };
}
