#pragma once
#include "src/Ai/Base/Value.h"

namespace ai
{
    class LogLevelValue : public ManualSetValue<LogLevel>
	{
	public:
        LogLevelValue(PlayerbotAI* ai, std::string name = "log level") :
            ManualSetValue<LogLevel>(ai, LOG_LVL_DEBUG, name) {}
	};
}
