
#include "src/Bot/Engine/playerbot.h"
#include "MoveStyleAction.h"
#include "src/Ai/Base/values/SubStrategyValue.h"
#include "src/Ai/Base/values/MoveStyleValue.h"
#include "src/Bot/Engine/PlayerbotAIAware.h"

using namespace ai;

bool MoveStyleAction::Execute(Event& event)
{
    std::string strategy = event.getParam();
    Player* requester = event.getOwner() ? event.getOwner() : GetMaster();

    MoveStyleValue* value = (MoveStyleValue*)context->GetValue<std::string>("move style");

    if (strategy == "?")
    {
        {
            std::ostringstream out;
            out << "Move style: " << value->Get();
            ai->TellPlayer(requester, out);
        }
    }
    else
    {
        value->Set(strategy);
        
        {
            std::ostringstream out;
            out << "Move style set to: " << value->Get();
            ai->TellPlayer(requester, out);
        }
    }

    return true;
}

