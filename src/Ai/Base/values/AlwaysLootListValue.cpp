
#include "AlwaysLootListValue.h"
#include "src/Bot/Engine/playerbot.h"
#include "src/Bot/PlayerbotAIConfig.h"
#include "src/Util/ServerFacade.h"

using namespace ai;

std::string AlwaysLootListValue::Save()
{
    std::ostringstream out;
    bool first = true;
    for (std::set<uint32>::iterator i = value.begin(); i != value.end(); ++i)
    {
        if (!first) out << ",";
        else first = false;
        out << *i;
    }
    return out.str();
}

bool AlwaysLootListValue::Load(std::string text)
{
    value.clear();

    std::vector<std::string> ss = split(text, ',');
    for (std::vector<std::string>::iterator i = ss.begin(); i != ss.end(); ++i)
    {
        value.insert(atoi(i->c_str()));
    }
    return true;
}
