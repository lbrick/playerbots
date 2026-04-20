# Cerebrum

> OpenWolf's learning memory. Updated automatically as the AI learns from interactions.
> Do not edit manually unless correcting an error.
> Last updated: 2026-04-18

## User Preferences

- **Raid layout:** Prefers AC-style subdirectory split per raid — Action/, Strategy/, Trigger/ subdirs with Raid{Short}{Type} file naming (e.g. RaidBwlActions.h, RaidMcStrategy.cpp). Trigger IsActive() implementations go in .cpp, not inline in headers. Strategy .cpp keeps inline multiplier classes if they're only used locally. CMakeLists uses GLOB_RECURSE for restructured raids.
- **Plan before code:** Always write the plan document FIRST before making any code changes. For dungeons this means writing `<DUNGEON>_PLAN.md` (boss table, file list, registration checklist, DoD) before creating any source files.

## Key Learnings

- **Project:** cmangos-playerbots
- **Description:** Bot AI Core from ike3 for cmangos classic, tbc and wotlk
- **Repo structure (post-restructure 2026-04-15):** Source under `src/`:
  - `src/Bot/` — flat: PlayerbotAIConfig, PlayerbotLLMInterface only
  - `src/Bot/Engine/` — PlayerbotAI*, BotState, playerbotDefs, playerbot.h
  - `src/Bot/Factory/` — AiFactory, PlayerbotFactory, RandomPlayerbotFactory
  - `src/Bot/Cmd/` — PlayerbotCommandServer
  - `src/Bot/Debug/` — MemoryMonitor, PerformanceMonitor, BotTests
  - `src/Db/` — PlayerbotDbStore
  - `src/Mgr/` — all *Mgr files, FleeManager, LootObjectStack, Talentspec, PlayerTalentSpec, RandomItemMgr, TravelMgr, TravelNode
  - `src/Util/` — GuidPosition, Helpers, WorldPosition, WorldSquare, ServerFacade, BroadcastHelper, ChatHelper, ChatFilter, LazyCalculatedValue
  - `src/Ai/Base/` — strategy engine root + actions/, generic/, triggers/, values/
  - `src/Ai/Class/{class}/` — per-class AI (10 classes, lowercase names)
  - `src/Ai/Raid/{raid}/` — BlackwingLair, Karazhan, MoltenCore, Naxxramas, OnyxiasLair; BWL+MC restructured to AC-style subdirs: Action/, Strategy/, Trigger/ with Raid{Short}{Type}.h/.cpp naming
  - `src/AhBot/` — AH bot source
  - `conf/` — aiplayerbot.conf.dist.in*, ahbot.conf.dist.in
  - `data/sql/` — characters/base, characters/updates, world/{classic,tbc,wotlk}, other/
  - botpch.cpp/.h at root
- **Include convention:** All includes use `src/Bot/`, `src/Ai/Base/`, `src/Ai/Class/{class}/`, `src/AhBot/` prefixes. Repo root is CMake include dir. Relative same-dir includes still used within class subdirs.
- **Dir naming:** New structural dirs (src/Ai/, src/Bot/, src/AhBot/) use PascalCase. Existing strategy subdirs keep lowercase (actions/, generic/, triggers/, values/, druid/, etc.).

## Do-Not-Repeat

<!-- Mistakes made and corrected. Each entry prevents the same mistake recurring. -->
<!-- Format: [YYYY-MM-DD] Description of what went wrong and what to do instead. -->

- **[2026-04-16] NewRpgInfo.h include path:** Uses `src/Util/WorldPosition.h` (with src/ prefix) — matches project include convention. Do NOT use bare `WorldPosition.h`.
- **[2026-04-16] PlayerbotAIConfig.h cannot include headers that pull PathFinder:** Any header that transitively includes `PathFinder.h` → `MoveMapSharedDefines.h` → `Detour/Include/DetourNavMesh.h` will fail in `mangosd` TU (no Detour include path there). Use `namespace ai { enum NewRpgStatus : int; }` forward declaration instead of including `NewRpgInfo.h` in PlayerbotAIConfig.h.
- **[2026-04-16] AC variable name `botAI` is `ai` in cmangos:** All AC code using `botAI->` must use `ai->` in cmangos. When doing bulk replaces, use `replace_all` carefully to avoid substring collision (e.g. `PlayerbotAI` becoming `Playerai`).
- **[2026-04-16] bot->IsInFlight() does not exist in cmangos:** Use `bot->IsTaxiFlying()` instead.
- **[2026-04-16] bot->Dismount() does not exist in cmangos:** Use `bot->Unmount()` instead.
- **[2026-04-16] WorldTimer.h not needed as explicit include:** `WorldTimer` comes via `playerbot.h`. Adding `#include "Server/WorldTimer.h"` directly will fail (wrong path). Just use `WorldTimer::getMSTime()` and `WorldTimer::getMSTimeDiff()` — available through the PCH/playerbot.h chain.
- **[2026-04-16] ObjectAccessor not used in cmangos playerbots:** Use `bot->GetMap()->GetWorldObject(guid)`, `bot->GetMap()->GetCreature(guid)`, `bot->GetMap()->GetGameObject(guid)` instead of `ObjectAccessor::Get*` methods.

## Key Learnings (AC → cmangos API mapping)

- **Timer:** `getMSTime()` → `WorldTimer::getMSTime()`. `GetMSTimeDiffToNow(t)` → `WorldTimer::getMSTimeDiff(t, WorldTimer::getMSTime())`.
- **ObjectMgr:** `sObjectMgr->GetQuestTemplate(id)` → `sObjectMgr.GetQuestTemplate(id)` (no arrow — global instance not pointer in cmangos).
- **Quest status fields:** `q_status.CreatureOrGOCount[i]` → `q_status.m_creatureOrGOcount[i]`. `q_status.ItemCount[i]` → `q_status.m_itemcount[i]`. `quest->RequiredNpcOrGoCount[i]` → `quest->ReqCreatureOrGOCount[i]`. `quest->RequiredItemCount[i]` → `quest->ReqItemCount[i]`.
- **WorldPosition distance:** Use `WorldPosition(bot).distance(dest)` to get distance from bot to a WorldPosition. `WorldPosition::distance(const WorldPosition&)` returns `float`.
- **lowPriorityQuest:** Not in cmangos PlayerbotAI by default — added `std::set<uint32> lowPriorityQuest` to PlayerbotAI.h alongside rpgInfo/rpgStatistic.
- **GetQuestPOIPosAndObjectiveIdx signature:** cmangos version returns single result via `WorldPosition& outPos, int32& outObjIdx` out-params (not a vector). AC returned `std::vector<POIInfo>`.
- **Logging:** `LOG_DEBUG("playerbots", ...)` → `sLog.outDebug(...)` with printf-style format (not fmtlib).
- **Shapeshift removal:** `ai->RemoveShapeshift()` — method exists on PlayerbotAI.
- **ActivateTaxiPathTo:** `bot->ActivateTaxiPathTo(std::vector<uint32> nodes, Creature* npc, uint32 spellid)` — same signature in cmangos. Use `0` for spellid.

## Key Learnings (New RPG runtime behavior — from live log analysis)

- **`zone routing` log fires in `CheckRpgStatusAvailable`**, not at CHANGE_ZONE execution. Pattern for confirming CHANGE_ZONE selected: `zone routing: zone X > zone Y` immediately followed by `zone score cache hit` on same tick.
- **mmap tile loading limitation:** PathFinder only routes through loaded tiles. Cross-continent paths fail → `MoveFarTo` returns false → `MoveRandomNear(10.0f)` → bot barely moves → stuck-teleport fires ~90s. This is expected; cross-continent CHANGE_ZONE always ends via teleport.
- **TravelMgr returns bad-terrain positions:** `select random camp/grind pos` can return positions at Z=300-500 (cliff tops, mountain peaks). Bot pathfinds to these and gets stuck in infinite teleport loop. Any fix must handle this case.
- **Infinite teleport loop pattern:** Bot gets camp/grind pos at bad terrain → `MoveFarTo` fails → teleports to exact pos → arrives, transitions to wander → wander fails → idle → re-scores → same zone wins → same bad pos → repeat every ~2 min forever. Worst observed: Kritholfon 40 teleports, Damaderon 39 teleports in 7-hour session.
- **Short-distance stuck teleports:** `MoveFarTo` triggers stuck detection even for 10-15 yard targets when pathfinder can't navigate a wall/step. Damaderon teleporting 11 yards every ~90s for hours.
- **Zone arrival stats (7-hour session):** 543 teleports, 48 zone routings, 11 arrivals (23%). Low arrival rate due to bad-terrain loop bots consuming all teleports.
- **Quest system healthy:** 537 accepts, 110 abandonments, 309 low-priority marks — working as intended.

## Decision Log

- **[2026-04-16] World/RPG New RPG system Phase 1+2 complete:** All scaffold files created and build verified. Files at src/Ai/World/Rpg/. PlayerbotAI.h has rpgInfo+rpgStatistic members. Config has enableNewRpgStrategy. StrategyContext/ActionContext/TriggerContext all registered. AiFactory.cpp NOT yet wired (Phase 5 todo). All action/base methods are stubs returning false — Phase 3+4 still pending. See WORLD_RPG_MIGRATION_PLAN.md.
- **[2026-04-16] Build infrastructure:** `build.sh` at project root. `./build.sh` does incremental, `./build.sh clean` reconfigures. Build dir at `builddir/`. No ninja — uses make with `$(nproc)` jobs. Build takes ~11s for full playerbots recompile.

- **[2026-04-15] Repo restructure:** Mirrored azerothcore-playerbots layout. playerbot/ → src/Bot/, playerbot/strategy/ → src/Ai/Base/, per-class dirs → src/Ai/Class/{class}/, ahbot/ → src/AhBot/, sql/ → data/sql/, conf files → conf/. ~780 include paths updated via sed. CMakeLists.txt rewritten. Zero logic changes. Lowercase kept for existing subdir names (cMaNGOS convention). PascalCase for new structural dirs.

- **Build setup:** Clone `cmangos/mangos-classic` into playerbots-updates/. Symlink `mangos-classic/src/modules/PlayerBots` → cmangos-playerbots. Builddir at `playerbots-updates/builddir/`. Configure: `CC=clang CXX=clang++ cmake -DBUILD_PLAYERBOTS=ON -DFETCHCONTENT_SOURCE_DIR_PLAYERBOTS=<symlink_path> -DCMAKE_BUILD_TYPE=Release -B builddir -S mangos-classic`. Build: `cmake --build builddir -- -j$(nproc)`.
- **Compat shims:** Core mangos game files include `playerbot/X.h` and `ahbot/AhBot.h` (old paths). Created shim headers at module root `playerbot/` and `ahbot/` that forward to new `src/` paths. Required files: `playerbot/{playerbot.h,PlayerbotAI.h,PlayerbotAIConfig.h,RandomPlayerbotMgr.h}`, `ahbot/AhBot.h`.
- **Angle-bracket include gotcha:** One file (DebugAction.cpp) used `<playerbot/TravelNode.h>` with angle brackets — missed by sed which only targeted double-quote includes. Always check `<playerbot/` pattern too when fixing stale includes.

## Key Learnings (Party join/leave behavior)

- **Free bot + real player master → AiFactory branch bug:** `AddDefaultNonCombatStrategies` line 994 had `if (master->GetPlayerbotAI() || sRandomPlayerbotMgr.IsFreeBot(player))` — caused free bots to take autonomous path (rpg/grind/travel) even with real player master. Fixed to `if (master->GetPlayerbotAI())` — real player master now correctly gets player-follower config.
- **Strategy save/restore pattern:** `m_preGroupStrategies` (string) on PlayerbotAI stores comma-separated non-combat strategies before `HandleGroupAcceptOpcode`. `RestorePreGroupStrategies()` calls `ResetStrategies()` first then `ChangeStrategy("+" + saved)`. Empty-string guard falls back to plain `ResetStrategies()`.
- **AcceptInvitationAction teleport placement:** Teleport must come AFTER `HandleGroupAcceptOpcode` success check (group formed) but BEFORE `SetMaster` + `ResetStrategies`. Only fires if `GetDistance2d(bot, inviter) > 5.0f`.
