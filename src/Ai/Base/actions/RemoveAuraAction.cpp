
#include "src/Bot/Engine/playerbot.h"
#include "RemoveAuraAction.h"
#include "src/Util/ServerFacade.h"

using namespace ai;

bool RemoveAuraAction::Execute(Event& event)
{
    std::string spell = aura;
    if (spell.empty())
    {
        spell = event.getParam();
    }
    
    return ai->RemoveAura(spell);
}
