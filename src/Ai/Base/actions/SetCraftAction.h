#pragma once
#include "src/Ai/Base/values/CraftValues.h"
#include "GenericActions.h"

namespace ai
{
    class SetCraftAction : public ChatCommandAction
    {
    public:
        SetCraftAction(PlayerbotAI* ai) : ChatCommandAction(ai, "craft") {}
        virtual bool Execute(Event& event) override;
        static uint32 GetCraftFee(CraftData&);

    private:
        void TellCraft(Player* requester);

    private:
        static std::map<uint32, SkillLineAbilityEntry const*> skillSpells;
    };
}
