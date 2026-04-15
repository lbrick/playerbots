#pragma once

#include "Spells/Spell.h"
#include "Server/WorldPacket.h"
#include "Loot/LootMgr.h"
#include "Entities/GossipDef.h"
#include "Chat/Chat.h"
#include "Common.h"
#include "World/World.h"
#include "Spells/SpellMgr.h"
#include "Globals/ObjectMgr.h"
#include "Entities/Unit.h"
#include "Globals/SharedDefines.h"
#include "MotionGenerators/MotionMaster.h"
#include "Spells/SpellAuras.h"
#include "Guilds/Guild.h"

#include "src/Bot/Engine/playerbotDefs.h"
#include "src/Bot/Engine/PlayerbotAIAware.h"
#include "src/Mgr/PlayerbotMgr.h"
#include "src/Mgr/RandomPlayerbotMgr.h"
#include "src/Util/ChatHelper.h"
#include "src/Util/BroadcastHelper.h"
#include "src/Bot/Engine/PlayerbotAI.h"
#include "src/Db/PlayerbotDbStore.h"

#define MANGOSBOT_VERSION 2

std::vector<std::string> split(std::string const& s, char delim);
void split(std::vector<std::string>& dest, std::string const& str, char const* delim);
#ifndef WIN32
int strcmpi(std::string s1, std::string s2);
#endif
