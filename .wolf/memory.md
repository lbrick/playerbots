# Memory

> Chronological action log. Hooks and AI append to this file automatically.
> Old sessions are consolidated by the daemon weekly.
| 00:00 | Restructured repo to mirror azerothcore-playerbots layout | src/, conf/, data/sql/, CMakeLists.txt | complete — all includes updated, old dirs removed | ~4000 |

## Session: 2026-04-16

| Time | Action | File(s) | Outcome | ~Tokens |
|------|--------|---------|---------|--------|
| 14:30 | Verified build of all Phase 1+2 World/RPG files | src/Ai/World/Rpg/**/*.cpp | PASSED — all 5 new files compiled clean, 0 errors 0 warnings | ~300 |
| 14:31 | Updated anatomy.md with World/Rpg section entries | .wolf/anatomy.md | complete | ~150 |
| 14:31 | Updated cerebrum.md Decision Log + Do-Not-Repeat | .wolf/cerebrum.md | complete | ~100 |
| 00:00 | Further restructured src/ — raids to Ai/Raid/, Bot subdirs (Engine/Factory/Cmd/Debug), Db/, Mgr/, Util/ | CMakeLists.txt + all includes | complete | ~3000 |
| 14:20 | Fixed stale <playerbot/TravelNode.h> angle-bracket include in DebugAction.cpp | src/Ai/Base/actions/DebugAction.cpp | fixed → src/Mgr/TravelNode.h | ~50 |
| 14:25 | Fixed ActionContext.h + TriggerContext.h stale raid includes (5 raids each) | src/Ai/Base/actions/ActionContext.h, src/Ai/Base/triggers/TriggerContext.h | fixed | ~100 |
| 14:35 | Set up local build: cloned mangos-classic, symlinked module, created builddir | mangos-classic/, builddir/, src/modules/PlayerBots symlink | cmake configure OK | ~200 |
| 14:45 | Created compatibility shim headers for core game includes at old playerbot/ ahbot/ paths | playerbot/*.h, ahbot/AhBot.h | full build clean — playerbots+game+mangosd all built | ~150 |
| 08:28 | Restructured BWL and MC raids to AC-style Action/Strategy/Trigger subdir layout | src/Ai/Raid/BlackwingLair/, src/Ai/Raid/MoltenCore/ | complete | ~3000 |
| 09:23 | Restructured Karazhan, Naxxramas, OnyxiasLair raids to AC-style Action/Strategy/Trigger subdir layout | src/Ai/Raid/{Karazhan,Naxxramas,OnyxiasLair}/ | complete | ~2500 |
| 22:55 | Phase 4 complete: NewRpgGoChangeZoneAction + timeout + trigger/strategy/context wiring | NewRpgAction.h/.cpp, NewRpgStrategy.cpp, ActionContext.h, TriggerContext.h | built clean | ~800 |
| 23:30 | Created PHASE_4_5_FINDINGS.md — log analysis + 5 issues + fix plan | PHASE_4_5_FINDINGS.md | created | ~600 |
| 23:41 | Phase 4.5 fixes: arrived-zone log unconditional, universal strategy wiring, GO fail loop guard | NewRpgAction.cpp, AiFactory.cpp, PlayerbotAI.h, NewRpgBaseAction.cpp | built clean | ~400 |
| 11:52 | extended log analysis 7h session - found infinite teleport loop bug, short-dist teleport bug, updated PHASE_4_5_FINDINGS with Phase 5 plan | PHASE_4_5_FINDINGS.md, .wolf/cerebrum.md | analysis complete | ~3k |
| 12:19 | created PHASE_5_PLAN.md with 4 phases, 5.1 teleport loop fix (pos-level not zone), 5.2 mount, 5.3 flight, 5.4 waypoints | PHASE_5_PLAN.md | created | ~1k |
| 12:29 | Phase 5.1 impl: badPositions on PlayerbotAI, IsPosBad helper, short-dist guard <20yd, filter in all SelectRandom*/SelectBestZone, cache-hit guard | PlayerbotAI.h, NewRpgBaseAction.h/.cpp | built clean | ~2k |
| 13:47 | Phase 5.2/5.3/5.4 impl: TryMount, flight suppress, TravelNode waypoints | NewRpgInfo.h, NewRpgBaseAction.h/.cpp, NewRpgAction.cpp | build OK zero errors | ~800 |
| 15:48 | Phase 6 plan written from Run1-3 observations | PHASE_6_PLAN.md | created | ~600 |
| 15:53 | Updated Phase 6 plan: replaced Z-height guard with PathFinder+IsMMapIsLoaded approach | PHASE_6_PLAN.md | updated | ~400 |
