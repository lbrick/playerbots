#pragma once
#include "src/Ai/Base/Value.h"
#include "src/Mgr/PlayerTalentSpec.h"

namespace ai
{
    class TalentSpecValue : public ManualSetValue<PlayerTalentSpec>
    {
    public:
        TalentSpecValue(PlayerbotAI* ai, std::string name = "talent spec") : ManualSetValue<PlayerTalentSpec>(ai, PlayerTalentSpec::TALENT_SPEC_INVALID, name) {}
#ifdef GenerateBotHelp
        virtual std::string GetHelpName() { return "talent spec"; } //Must equal iternal name
        virtual std::string GetHelpTypeName() { return "talent spec"; }
        virtual std::string GetHelpDescription() { return "This value stores the current talent spec for the bot."; }
        virtual std::vector<std::string> GetUsedValues() { return {}; }
#endif 
    };
}
