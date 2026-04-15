#pragma once

#include "src/Ai/Base/Action.h"

namespace ai
{
    class PetitionSignAction : public Action {
    public:
        PetitionSignAction(PlayerbotAI* ai) : Action(ai, "petition sign") {}
        virtual bool Execute(Event& event) override;
    };    
}
