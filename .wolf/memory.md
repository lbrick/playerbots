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
| 08:41 | Phase 11 fixes: BUG-1 threshold 500→150, BUG-2 rejectedTransportDocks cache, OBS-5 debug log removed | NewRpgAction.cpp, NewRpgInfo.h | building | ~800 |
| 10:01 | BOAT-4 guard fix: removed z<-5 condition, added elevator teleport log | NewRpgAction.cpp:628 | build OK | ~200 |
| 13:11 | Phase 11 Run 1 complete — manual stop T+184, wrote final findings | PHASE_11_OBSERVATION_RUN1.md | done | ~500 |
| 13:24 | RFC dungeon impl: 4 files created, CMakeLists updated, all 4 registration files updated, build clean | src/Ai/Dungeon/RagefireChasm/* CMakeLists.txt TriggerContext.h ActionContext.h StrategyContext.h DungeonStrategy.cpp | success | ~3500 |
| 13:36 | WC dungeon impl: WC_PLAN.md written first, NPC IDs DB-verified, 4 code files + 5 registrations, build clean | src/Ai/Dungeon/WailingCaverns/* CMakeLists.txt TriggerContext.h ActionContext.h StrategyContext.h DungeonStrategy.cpp | success | ~3000 |
| 13:51 | WC interrupt mechanic: TargetCastingSpellTrigger + InterruptEnemyCastAction added to base; DruidSlumber wired at instance level | DungeonTriggers.h/cpp DungeonActions.h/cpp WcTriggers.h WcStrategy.cpp TriggerContext.h ActionContext.h | build clean | ~1500 |
| 19:30 | party join: teleport+follow+restore impl | AcceptInvitationAction.h, LeaveGroupAction.cpp, PlayerbotAI.h/.cpp, AiFactory.cpp | working — 40 events confirmed in log | ~800 |
| 22:07 | created Deadmines dungeon folder + DM_PLAN.md | src/Ai/Dungeon/Deadmines/ | plan ready, awaiting user confirmation | ~200 |
| 22:20 | DM dungeon impl complete: 4 files created, 5 files registered, build clean | Deadmines/* + DungeonStrategy.cpp + TriggerContext.h + ActionContext.h + StrategyContext.h + CMakeLists.txt | success | ~800 |
| 01:28 | Created BFD dungeon strategy (Steps 2-13) | BlackfathomDeeps/Trigger/BfdTriggers.h, Action/BfdActions.h, Strategy/BfdStrategy.h/.cpp + 5 registration edits | clean build | ~4000 |
| 04:41 | Implemented ZulFarrak (map 209, 7 bosses) + Maraudon (map 349, 8 bosses) dungeon strategies | ZulFarrak/Trigger/ZfTriggers.h, ZulFarrak/Action/ZfActions.h, ZulFarrak/Strategy/ZfStrategy.h/.cpp, Maraudon/Trigger/MaraTriggers.h, Maraudon/Action/MaraActions.h, Maraudon/Strategy/MaraStrategy.h/.cpp + 4 registration files | clean build [100%] Built target mangosd | ~2000 |
| 05:30 | Implemented Temple of Atal'Hakkar (map 109, 12 bosses) + Blackrock Depths (map 230, 21 bosses) dungeon strategies | ST/BRD Triggers.h, Actions.h, Strategy.h/.cpp + 4 registration files | clean build [100%] Built target mangosd | ~3000 |
| 10:30 | Fixed NPC IDs in MaraTriggers.h (Vyletongue 13280→12236, Celebras 12519→12225, Landslide 12565→12203) | MaraTriggers.h | fixed | ~400 |
| 10:31 | Rewrote BrdTriggers.h with all corrected Ring of Law IDs (Grizzle 9028, Eviscerator 9029, Ok'thor 9030, Anub'shiah 9031, Hedrum 9032), Warder Stilgiss 9041, Verek 9042, The Seven 8888 | BrdTriggers.h | fixed | ~600 |
| 10:32 | Fixed MoveAwayFromCreature IDs in BrdActions.h (Grizzle 9028, Eviscerator 9029, Ok'thor 9030, Warder Stilgiss 9041) | BrdActions.h | fixed | ~300 |
| 10:33 | Build clean after all NPC ID fixes | builddir-classic | success | ~200 |
| 10:34 | Updated MARA_PLAN.md and BRD_PLAN.md with verified NPC IDs | MARA_PLAN.md, BRD_PLAN.md | updated | ~300 |
| 01:00 | Implemented Dire Maul dungeon strategy (East/West/North, 15 bosses, 9 AoE triggers) | DireMaul/{Trigger/DmTriggers.h,Action/DmActions.h,Strategy/DmStrategy.h,.cpp} | build clean | ~4000 |
| 01:30 | Implemented Stratholme dungeon strategy (Scarlet+Undead sides, 9 bosses, 5 AoE triggers) | Stratholme/{Trigger/StratTriggers.h,Action/StratActions.h,Strategy/StratStrategy.h,.cpp} | build clean | ~3500 |
| 15:30 | Scholomance dungeon strategy implemented (12 bosses, 6 AoE hazards, map 289) | dungeons/Scholomance/* + TriggerContext.h + ActionContext.h + StrategyContext.h + DungeonStrategy.cpp | build clean [100%] | ~2800 |
