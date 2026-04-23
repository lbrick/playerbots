#
# Copyright (C) 2005-2018 MaNGOS project <http://getmangos.com/>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
#

set(LIBRARY_NAME playerbots)

#Add PCH Files
set(bots_PCH "${CMAKE_CURRENT_SOURCE_DIR}/botpch.h")

# ── Bot (playerbot/ flat) ─────────────────────────────────────────────────────

file(GLOB Bot_Source ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/*.h)
source_group("Bot" FILES ${Bot_Source})

# ── AhBot ────────────────────────────────────────────────────────────────────

file(GLOB AHbot_Source ${CMAKE_CURRENT_SOURCE_DIR}/ahbot/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/ahbot/*.h)
source_group("AhBot" FILES ${AHbot_Source})

# ── Strategy Base ─────────────────────────────────────────────────────────────

file(GLOB Ai_Base     ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/*.cpp     ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/*.h)
file(GLOB Ai_Actions  ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/actions/*.cpp  ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/actions/*.h)
file(GLOB Ai_Generic  ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/generic/*.cpp  ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/generic/*.h)
file(GLOB Ai_Triggers ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/triggers/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/triggers/*.h)
file(GLOB Ai_Values   ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/values/*.cpp   ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/values/*.h)

source_group("Strategy"           FILES ${Ai_Base})
source_group("Strategy\\Actions"  FILES ${Ai_Actions})
source_group("Strategy\\Generic"  FILES ${Ai_Generic})
source_group("Strategy\\Triggers" FILES ${Ai_Triggers})
source_group("Strategy\\Values"   FILES ${Ai_Values})

# ── Strategy Class ────────────────────────────────────────────────────────────

file(GLOB Ai_DeathKnight ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/deathknight/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/deathknight/*.h)
file(GLOB Ai_Druid       ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/druid/*.cpp       ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/druid/*.h)
file(GLOB Ai_Hunter      ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/hunter/*.cpp      ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/hunter/*.h)
file(GLOB Ai_Mage        ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/mage/*.cpp        ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/mage/*.h)
file(GLOB Ai_Paladin     ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/paladin/*.cpp     ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/paladin/*.h)
file(GLOB Ai_Priest      ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/priest/*.cpp      ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/priest/*.h)
file(GLOB Ai_Rogue       ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/rogue/*.cpp       ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/rogue/*.h)
file(GLOB Ai_Shaman      ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/shaman/*.cpp      ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/shaman/*.h)
file(GLOB Ai_Warlock     ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/warlock/*.cpp     ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/warlock/*.h)
file(GLOB Ai_Warrior     ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/warrior/*.cpp     ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/warrior/*.h)

source_group("Strategy\\DeathKnight" FILES ${Ai_DeathKnight})
source_group("Strategy\\Druid"       FILES ${Ai_Druid})
source_group("Strategy\\Hunter"      FILES ${Ai_Hunter})
source_group("Strategy\\Mage"        FILES ${Ai_Mage})
source_group("Strategy\\Paladin"     FILES ${Ai_Paladin})
source_group("Strategy\\Priest"      FILES ${Ai_Priest})
source_group("Strategy\\Rogue"       FILES ${Ai_Rogue})
source_group("Strategy\\Shaman"      FILES ${Ai_Shaman})
source_group("Strategy\\Warlock"     FILES ${Ai_Warlock})
source_group("Strategy\\Warrior"     FILES ${Ai_Warrior})

# ── Strategy RPG ─────────────────────────────────────────────────────────────

file(GLOB_RECURSE Ai_Rpg ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/rpg/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/rpg/*.h)
source_group("Strategy\\Rpg" FILES ${Ai_Rpg})

# ── Strategy Dungeon ─────────────────────────────────────────────────────────

file(GLOB_RECURSE Ai_Dungeon_DM  ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/dungeons/Deadmines/*.cpp    ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/dungeons/Deadmines/*.h)
file(GLOB_RECURSE Ai_Dungeon_RFC ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/dungeons/RagefireChasm/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/dungeons/RagefireChasm/*.h)
file(GLOB_RECURSE Ai_Dungeon_SFK ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/dungeons/ShadowfangKeep/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/dungeons/ShadowfangKeep/*.h)
file(GLOB_RECURSE Ai_Dungeon_WC  ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/dungeons/WailingCaverns/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/dungeons/WailingCaverns/*.h)

source_group("Strategy\\Dungeons\\Deadmines"      FILES ${Ai_Dungeon_DM})
source_group("Strategy\\Dungeons\\RagefireChasm"  FILES ${Ai_Dungeon_RFC})
source_group("Strategy\\Dungeons\\ShadowfangKeep" FILES ${Ai_Dungeon_SFK})
source_group("Strategy\\Dungeons\\WailingCaverns" FILES ${Ai_Dungeon_WC})

# ── Strategy Raid ─────────────────────────────────────────────────────────────

file(GLOB_RECURSE Ai_BlackwingLair ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/raid/BlackwingLair/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/raid/BlackwingLair/*.h)
file(GLOB_RECURSE Ai_Karazhan      ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/raid/Karazhan/*.cpp      ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/raid/Karazhan/*.h)
file(GLOB_RECURSE Ai_MoltenCore    ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/raid/MoltenCore/*.cpp    ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/raid/MoltenCore/*.h)
file(GLOB_RECURSE Ai_Naxxramas     ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/raid/Naxxramas/*.cpp     ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/raid/Naxxramas/*.h)
file(GLOB_RECURSE Ai_OnyxiasLair   ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/raid/OnyxiasLair/*.cpp   ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/raid/OnyxiasLair/*.h)

source_group("Strategy\\Raid\\BlackwingLair" FILES ${Ai_BlackwingLair})
source_group("Strategy\\Raid\\Karazhan"      FILES ${Ai_Karazhan})
source_group("Strategy\\Raid\\MoltenCore"    FILES ${Ai_MoltenCore})
source_group("Strategy\\Raid\\Naxxramas"     FILES ${Ai_Naxxramas})
source_group("Strategy\\Raid\\OnyxiasLair"   FILES ${Ai_OnyxiasLair})

# ── Library definition ───────────────────────────────────────────────────────

set(LIBRARY_SRCS
    # Bot
    ${Bot_Source}
    # AhBot
    ${AHbot_Source}
    # Strategy Base
    ${Ai_Base}
    ${Ai_Actions}
    ${Ai_Generic}
    ${Ai_Triggers}
    ${Ai_Values}
    # Strategy Class
    ${Ai_DeathKnight}
    ${Ai_Druid}
    ${Ai_Hunter}
    ${Ai_Mage}
    ${Ai_Paladin}
    ${Ai_Priest}
    ${Ai_Rogue}
    ${Ai_Shaman}
    ${Ai_Warlock}
    ${Ai_Warrior}
    # Strategy RPG
    ${Ai_Rpg}
    # Strategy Dungeon
    ${Ai_Dungeon_DM}
    ${Ai_Dungeon_RFC}
    ${Ai_Dungeon_SFK}
    ${Ai_Dungeon_WC}
    # Strategy Raid
    ${Ai_BlackwingLair}
    ${Ai_Karazhan}
    ${Ai_MoltenCore}
    ${Ai_Naxxramas}
    ${Ai_OnyxiasLair}
    # PCH
    ${bots_PCH}
    ${CMAKE_CURRENT_SOURCE_DIR}/botpch.cpp
)

# ── Build flags ──────────────────────────────────────────────────────────────

if (BUILD_PLAYERBOTS)
  add_definitions(-DENABLE_PLAYERBOTS)
endif()

if ( ${CMAKE_PROJECT_NAME} MATCHES "CMaNGOS")
  add_definitions(-DCMANGOS)
else()
  if ( ${CMAKE_PROJECT_NAME} MATCHES "MaNGOS")
    add_definitions(-DMANGOS)
  endif()
endif()

if ( ${CMAKE_PROJECT_NAME} MATCHES "Classic")
  add_definitions(-DMANGOSBOT_ZERO)
endif()
if ( ${CMAKE_PROJECT_NAME} MATCHES "TBC")
  add_definitions(-DMANGOSBOT_ONE)
endif()
if ( ${CMAKE_PROJECT_NAME} MATCHES "WoTLK")
  add_definitions(-DMANGOSBOT_TWO)
endif()

if (BUILD_MODULES)
  add_definitions(-DENABLE_MODULES)
endif()

if (BUILD_AHBOT)
  add_definitions(-DBUILD_AHBOT)
endif()

if(PCH)
  include_directories(${CMAKE_CURRENT_BINARY_DIR})
endif()

# ── Target ───────────────────────────────────────────────────────────────────

add_library(${LIBRARY_NAME} STATIC ${LIBRARY_SRCS})

target_link_libraries(${LIBRARY_NAME}
  PRIVATE shared
  PRIVATE Detour
  PRIVATE g3dlite
  PRIVATE zlib
)
if(WIN32)
  target_link_libraries(${LIBRARY_NAME}
    PRIVATE ws2_32
  )
endif()

target_include_directories(${LIBRARY_NAME}
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

# ── Config install ───────────────────────────────────────────────────────────

if ( ${CMAKE_PROJECT_NAME} MATCHES "Classic")
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/conf/aiplayerbot.conf.dist.in ${CMAKE_CURRENT_BINARY_DIR}/aiplayerbot.conf.dist)
endif()
if ( ${CMAKE_PROJECT_NAME} MATCHES "TBC")
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/conf/aiplayerbot.conf.dist.in.tbc ${CMAKE_CURRENT_BINARY_DIR}/aiplayerbot.conf.dist)
endif()
if ( ${CMAKE_PROJECT_NAME} MATCHES "WoTLK")
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/conf/aiplayerbot.conf.dist.in.wotlk ${CMAKE_CURRENT_BINARY_DIR}/aiplayerbot.conf.dist)
endif()
if (NOT CONF_INSTALL_DIR)
  set(CONF_INSTALL_DIR ${CONF_DIR})
endif()
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/aiplayerbot.conf.dist DESTINATION ${CONF_INSTALL_DIR})

set_target_properties(${LIBRARY_NAME} PROPERTIES PROJECT_LABEL "PlayerBots")

if(PCH)
  target_precompile_headers(${LIBRARY_NAME} PRIVATE ${bots_PCH})
endif()
