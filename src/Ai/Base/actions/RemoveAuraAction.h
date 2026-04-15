#pragma once
#include "src/Ai/Base/Action.h"

namespace ai
{
    class RemoveAuraAction : public Action
    {
    public:
        RemoveAuraAction(PlayerbotAI* ai, std::string aura = "") : Action(ai, aura.empty() ? "ra" : "remove" + aura), aura(aura) {}
        virtual bool Execute(Event& event) override;

    private:
        std::string aura;
    };
}
