#pragma once

#include "src/Ai/Base/Action.h"
#include "RpgAction.h"
#include "src/Ai/Base/values/LastMovementValue.h"

namespace ai
{
    class ChooseRpgTargetAction : public Action {
    public:
        ChooseRpgTargetAction(PlayerbotAI* ai, std::string name = "choose rpg target") : Action(ai, name) {}

        virtual bool Execute(Event& event);
        virtual bool isUseful();

        std::unordered_map<ObjectGuid, float> GetTargets(Player* requester, bool debug = false);

        std::string GetRpgActionReason(ObjectGuid target) { auto reason = rgpActionReason.find(target); if (reason != rgpActionReason.end())  return reason->second; return ""; }
    private:        
        float getMaxRelevance(GuidPosition guidP);
        bool HasSameTarget(ObjectGuid guid, uint32 max, std::list<ObjectGuid>& nearGuids);

        std::unordered_map <ObjectGuid, std::string> rgpActionReason;
    };

    class ClearRpgTargetAction : public ChooseRpgTargetAction {
    public:
        ClearRpgTargetAction(PlayerbotAI* ai) : ChooseRpgTargetAction(ai, "clear rpg target") {}
    };

}