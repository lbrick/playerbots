# Memory

> Chronological action log. Hooks and AI append to this file automatically.
> Old sessions are consolidated by the daemon weekly.
| 00:00 | Restructured repo to mirror azerothcore-playerbots layout | src/, conf/, data/sql/, CMakeLists.txt | complete — all includes updated, old dirs removed | ~4000 |
| 00:00 | Further restructured src/ — raids to Ai/Raid/, Bot subdirs (Engine/Factory/Cmd/Debug), Db/, Mgr/, Util/ | CMakeLists.txt + all includes | complete | ~3000 |
| 14:20 | Fixed stale <playerbot/TravelNode.h> angle-bracket include in DebugAction.cpp | src/Ai/Base/actions/DebugAction.cpp | fixed → src/Mgr/TravelNode.h | ~50 |
| 14:25 | Fixed ActionContext.h + TriggerContext.h stale raid includes (5 raids each) | src/Ai/Base/actions/ActionContext.h, src/Ai/Base/triggers/TriggerContext.h | fixed | ~100 |
| 14:35 | Set up local build: cloned mangos-classic, symlinked module, created builddir | mangos-classic/, builddir/, src/modules/PlayerBots symlink | cmake configure OK | ~200 |
| 14:45 | Created compatibility shim headers for core game includes at old playerbot/ ahbot/ paths | playerbot/*.h, ahbot/AhBot.h | full build clean — playerbots+game+mangosd all built | ~150 |
