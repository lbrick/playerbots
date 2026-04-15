#pragma once
#include "src/Ai/Base/Action.h"
#include "src/Bot/PlayerbotAIConfig.h"
#include "src/Bot/Factory/PlayerbotFactory.h"

namespace ai
{
    class UpdateGearAction : public Action
    {
    public:
        UpdateGearAction(PlayerbotAI* ai);
        virtual bool Execute(Event& event) override;
        virtual bool isUseful() override;

    private:
        uint8 GetProgressionLevel(uint32 itemLevel);
        uint8 GetMasterAverageProgressionLevel();
        uint8 GetMasterItemProgressionLevel(uint8 slot, uint8 avgProgressionLevel);
       
        void EnchantItem(Item* item);

    private:
        std::vector<EnchantTemplate> enchants;
    };
}
