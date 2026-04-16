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

# ── Bot ──────────────────────────────────────────────────────────────────────

file(GLOB Bot_Source    ${CMAKE_CURRENT_SOURCE_DIR}/src/Bot/*.cpp     ${CMAKE_CURRENT_SOURCE_DIR}/src/Bot/*.h)
file(GLOB Bot_Engine    ${CMAKE_CURRENT_SOURCE_DIR}/src/Bot/Engine/*.cpp   ${CMAKE_CURRENT_SOURCE_DIR}/src/Bot/Engine/*.h)
file(GLOB Bot_Factory   ${CMAKE_CURRENT_SOURCE_DIR}/src/Bot/Factory/*.cpp  ${CMAKE_CURRENT_SOURCE_DIR}/src/Bot/Factory/*.h)
file(GLOB Bot_Cmd       ${CMAKE_CURRENT_SOURCE_DIR}/src/Bot/Cmd/*.cpp      ${CMAKE_CURRENT_SOURCE_DIR}/src/Bot/Cmd/*.h)
file(GLOB Bot_Debug     ${CMAKE_CURRENT_SOURCE_DIR}/src/Bot/Debug/*.cpp    ${CMAKE_CURRENT_SOURCE_DIR}/src/Bot/Debug/*.h)

source_group("Bot"          FILES ${Bot_Source})
source_group("Bot\\Engine"  FILES ${Bot_Engine})
source_group("Bot\\Factory" FILES ${Bot_Factory})
source_group("Bot\\Cmd"     FILES ${Bot_Cmd})
source_group("Bot\\Debug"   FILES ${Bot_Debug})

# ── AhBot ────────────────────────────────────────────────────────────────────

file(GLOB AHbot_Source ${CMAKE_CURRENT_SOURCE_DIR}/src/AhBot/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/AhBot/*.h)
source_group("AhBot" FILES ${AHbot_Source})

# ── Db / Mgr / Util ──────────────────────────────────────────────────────────

file(GLOB Db_Source   ${CMAKE_CURRENT_SOURCE_DIR}/src/Db/*.cpp   ${CMAKE_CURRENT_SOURCE_DIR}/src/Db/*.h)
file(GLOB Mgr_Source  ${CMAKE_CURRENT_SOURCE_DIR}/src/Mgr/*.cpp  ${CMAKE_CURRENT_SOURCE_DIR}/src/Mgr/*.h)
file(GLOB Util_Source ${CMAKE_CURRENT_SOURCE_DIR}/src/Util/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/Util/*.h)

source_group("Db"   FILES ${Db_Source})
source_group("Mgr"  FILES ${Mgr_Source})
source_group("Util" FILES ${Util_Source})

# ── Ai Base ──────────────────────────────────────────────────────────────────

file(GLOB Ai_Base     ${CMAKE_CURRENT_SOURCE_DIR}/src/Ai/Base/*.cpp     ${CMAKE_CURRENT_SOURCE_DIR}/src/Ai/Base/*.h)
file(GLOB Ai_Actions  ${CMAKE_CURRENT_SOURCE_DIR}/src/Ai/Base/actions/*.cpp  ${CMAKE_CURRENT_SOURCE_DIR}/src/Ai/Base/actions/*.h)
file(GLOB Ai_Generic  ${CMAKE_CURRENT_SOURCE_DIR}/src/Ai/Base/generic/*.cpp  ${CMAKE_CURRENT_SOURCE_DIR}/src/Ai/Base/generic/*.h)
file(GLOB Ai_Triggers ${CMAKE_CURRENT_SOURCE_DIR}/src/Ai/Base/triggers/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/Ai/Base/triggers/*.h)
file(GLOB Ai_Values   ${CMAKE_CURRENT_SOURCE_DIR}/src/Ai/Base/values/*.cpp   ${CMAKE_CURRENT_SOURCE_DIR}/src/Ai/Base/values/*.h)

source_group("Ai\\Base"          FILES ${Ai_Base})
source_group("Ai\\Base\\Actions" FILES ${Ai_Actions})
source_group("Ai\\Base\\Generic" FILES ${Ai_Generic})
source_group("Ai\\Base\\Trigger" FILES ${Ai_Triggers})
source_group("Ai\\Base\\Value"   FILES ${Ai_Values})

# ── Ai Class ─────────────────────────────────────────────────────────────────

file(GLOB Ai_DeathKnight ${CMAKE_CURRENT_SOURCE_DIR}/src/Ai/Class/deathknight/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/Ai/Class/deathknight/*.h)
file(GLOB Ai_Druid       ${CMAKE_CURRENT_SOURCE_DIR}/src/Ai/Class/druid/*.cpp       ${CMAKE_CURRENT_SOURCE_DIR}/src/Ai/Class/druid/*.h)
file(GLOB Ai_Hunter      ${CMAKE_CURRENT_SOURCE_DIR}/src/Ai/Class/hunter/*.cpp      ${CMAKE_CURRENT_SOURCE_DIR}/src/Ai/Class/hunter/*.h)
file(GLOB Ai_Mage        ${CMAKE_CURRENT_SOURCE_DIR}/src/Ai/Class/mage/*.cpp        ${CMAKE_CURRENT_SOURCE_DIR}/src/Ai/Class/mage/*.h)
file(GLOB Ai_Paladin     ${CMAKE_CURRENT_SOURCE_DIR}/src/Ai/Class/paladin/*.cpp     ${CMAKE_CURRENT_SOURCE_DIR}/src/Ai/Class/paladin/*.h)
file(GLOB Ai_Priest      ${CMAKE_CURRENT_SOURCE_DIR}/src/Ai/Class/priest/*.cpp      ${CMAKE_CURRENT_SOURCE_DIR}/src/Ai/Class/priest/*.h)
file(GLOB Ai_Rogue       ${CMAKE_CURRENT_SOURCE_DIR}/src/Ai/Class/rogue/*.cpp       ${CMAKE_CURRENT_SOURCE_DIR}/src/Ai/Class/rogue/*.h)
file(GLOB Ai_Shaman      ${CMAKE_CURRENT_SOURCE_DIR}/src/Ai/Class/shaman/*.cpp      ${CMAKE_CURRENT_SOURCE_DIR}/src/Ai/Class/shaman/*.h)
file(GLOB Ai_Warlock     ${CMAKE_CURRENT_SOURCE_DIR}/src/Ai/Class/warlock/*.cpp     ${CMAKE_CURRENT_SOURCE_DIR}/src/Ai/Class/warlock/*.h)
file(GLOB Ai_Warrior     ${CMAKE_CURRENT_SOURCE_DIR}/src/Ai/Class/warrior/*.cpp     ${CMAKE_CURRENT_SOURCE_DIR}/src/Ai/Class/warrior/*.h)

source_group("Ai\\Class\\DeathKnight" FILES ${Ai_DeathKnight})
source_group("Ai\\Class\\Druid"       FILES ${Ai_Druid})
source_group("Ai\\Class\\Hunter"      FILES ${Ai_Hunter})
source_group("Ai\\Class\\Mage"        FILES ${Ai_Mage})
source_group("Ai\\Class\\Paladin"     FILES ${Ai_Paladin})
source_group("Ai\\Class\\Priest"      FILES ${Ai_Priest})
source_group("Ai\\Class\\Rogue"       FILES ${Ai_Rogue})
source_group("Ai\\Class\\Shaman"      FILES ${Ai_Shaman})
source_group("Ai\\Class\\Warlock"     FILES ${Ai_Warlock})
source_group("Ai\\Class\\Warrior"     FILES ${Ai_Warrior})

# ── Ai World ─────────────────────────────────────────────────────────────────

file(GLOB_RECURSE Ai_World ${CMAKE_CURRENT_SOURCE_DIR}/src/Ai/World/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/Ai/World/*.h)
source_group("Ai\\World" FILES ${Ai_World})

# ── Ai Raid ──────────────────────────────────────────────────────────────────

file(GLOB_RECURSE Ai_BlackwingLair ${CMAKE_CURRENT_SOURCE_DIR}/src/Ai/Raid/BlackwingLair/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/Ai/Raid/BlackwingLair/*.h)
file(GLOB_RECURSE Ai_Karazhan      ${CMAKE_CURRENT_SOURCE_DIR}/src/Ai/Raid/Karazhan/*.cpp      ${CMAKE_CURRENT_SOURCE_DIR}/src/Ai/Raid/Karazhan/*.h)
file(GLOB_RECURSE Ai_MoltenCore    ${CMAKE_CURRENT_SOURCE_DIR}/src/Ai/Raid/MoltenCore/*.cpp    ${CMAKE_CURRENT_SOURCE_DIR}/src/Ai/Raid/MoltenCore/*.h)
file(GLOB_RECURSE Ai_Naxxramas     ${CMAKE_CURRENT_SOURCE_DIR}/src/Ai/Raid/Naxxramas/*.cpp     ${CMAKE_CURRENT_SOURCE_DIR}/src/Ai/Raid/Naxxramas/*.h)
file(GLOB_RECURSE Ai_OnyxiasLair   ${CMAKE_CURRENT_SOURCE_DIR}/src/Ai/Raid/OnyxiasLair/*.cpp   ${CMAKE_CURRENT_SOURCE_DIR}/src/Ai/Raid/OnyxiasLair/*.h)

source_group("Ai\\Raid\\BlackwingLair" FILES ${Ai_BlackwingLair})
source_group("Ai\\Raid\\Karazhan"      FILES ${Ai_Karazhan})
source_group("Ai\\Raid\\MoltenCore"    FILES ${Ai_MoltenCore})
source_group("Ai\\Raid\\Naxxramas"     FILES ${Ai_Naxxramas})
source_group("Ai\\Raid\\OnyxiasLair"   FILES ${Ai_OnyxiasLair})

# ── Library definition ───────────────────────────────────────────────────────

set(LIBRARY_SRCS
    # Bot
    ${Bot_Source}
    ${Bot_Engine}
    ${Bot_Factory}
    ${Bot_Cmd}
    ${Bot_Debug}
    # AhBot
    ${AHbot_Source}
    # Db / Mgr / Util
    ${Db_Source}
    ${Mgr_Source}
    ${Util_Source}
    # Ai Base
    ${Ai_Base}
    ${Ai_Actions}
    ${Ai_Generic}
    ${Ai_Triggers}
    ${Ai_Values}
    # Ai World
    ${Ai_World}
    # Ai Class
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
    # Ai Raid
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
