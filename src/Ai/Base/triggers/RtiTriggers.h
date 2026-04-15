#pragma once
#include "src/Ai/Base/Trigger.h"
#include "src/Bot/PlayerbotAIConfig.h"
#include "src/Util/ServerFacade.h"
#include "src/Ai/Base/values/RtiTargetValue.h"

namespace ai
{
    class NoRtiTrigger : public Trigger
    {
    public:
        NoRtiTrigger(PlayerbotAI* ai) : Trigger(ai, "no rti target") {}

        virtual bool IsActive() override
		{
            if (AI_VALUE(Unit*, "rti target"))
            {
                return false;
            }
            else
            {
                // Check for the default rti if the bot is setup to ignore rti targets
                std::string rti = AI_VALUE(std::string, "rti");
                if (rti == "none")
                {
                    Group* group = bot->GetGroup();
                    if (group)
                    {
                        const ObjectGuid guid = group->GetTargetIcon(RtiTargetValue::GetRtiIndex("skull"));
                        if (!guid.IsEmpty())
                        {
                            Unit* unit = ai->GetUnit(ObjectGuid(guid));
                            if (unit && !sServerFacade.UnitIsDead(unit) && bot->IsWithinDistInMap(unit, sPlayerbotAIConfig.sightDistance, false))
                            {
                                return false;
                            }
                        }
                    }
                }
            }

            return true;
        }
    };
}
