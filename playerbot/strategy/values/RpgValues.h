#pragma once
#include "playerbot/strategy/Value.h"

namespace ai
{
    class NextRpgActionValue : public ManualSetValue<std::string>
	{
	public:
        NextRpgActionValue(PlayerbotAI* ai, std::string defaultValue = "", std::string name = "next rpg action") : ManualSetValue(ai, defaultValue, name) {};
    };

    // True while new RPG runs the bot in any status but idle. Legacy RPG then neither picks nor
    // walks to targets of its own (lbrick/cmangos-dev#47); its sub-actions stay callable.
    class NewRpgMacroActiveValue : public BoolCalculatedValue
    {
    public:
        NewRpgMacroActiveValue(PlayerbotAI* ai, std::string name = "new rpg macro active") : BoolCalculatedValue(ai, name) {};

        virtual bool Calculate() override;
    };
}
