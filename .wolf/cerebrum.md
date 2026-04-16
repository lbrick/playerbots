# Cerebrum

> OpenWolf's learning memory. Updated automatically as the AI learns from interactions.
> Do not edit manually unless correcting an error.
> Last updated: 2026-04-15

## User Preferences

- **Raid layout:** Prefers AC-style subdirectory split per raid — Action/, Strategy/, Trigger/ subdirs with Raid{Short}{Type} file naming (e.g. RaidBwlActions.h, RaidMcStrategy.cpp). Trigger IsActive() implementations go in .cpp, not inline in headers. Strategy .cpp keeps inline multiplier classes if they're only used locally. CMakeLists uses GLOB_RECURSE for restructured raids.

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

## Decision Log

- **[2026-04-16] World/RPG New RPG system Phase 1+2 complete:** All scaffold files created and build verified. Files at src/Ai/World/Rpg/. PlayerbotAI.h has rpgInfo+rpgStatistic members. Config has enableNewRpgStrategy. StrategyContext/ActionContext/TriggerContext all registered. AiFactory.cpp NOT yet wired (Phase 5 todo). All action/base methods are stubs returning false — Phase 3+4 still pending. See WORLD_RPG_MIGRATION_PLAN.md.
- **[2026-04-16] Build infrastructure:** `build.sh` at project root. `./build.sh` does incremental, `./build.sh clean` reconfigures. Build dir at `builddir/`. No ninja — uses make with `$(nproc)` jobs. Build takes ~11s for full playerbots recompile.

- **[2026-04-15] Repo restructure:** Mirrored azerothcore-playerbots layout. playerbot/ → src/Bot/, playerbot/strategy/ → src/Ai/Base/, per-class dirs → src/Ai/Class/{class}/, ahbot/ → src/AhBot/, sql/ → data/sql/, conf files → conf/. ~780 include paths updated via sed. CMakeLists.txt rewritten. Zero logic changes. Lowercase kept for existing subdir names (cMaNGOS convention). PascalCase for new structural dirs.

- **Build setup:** Clone `cmangos/mangos-classic` into playerbots-updates/. Symlink `mangos-classic/src/modules/PlayerBots` → cmangos-playerbots. Builddir at `playerbots-updates/builddir/`. Configure: `CC=clang CXX=clang++ cmake -DBUILD_PLAYERBOTS=ON -DFETCHCONTENT_SOURCE_DIR_PLAYERBOTS=<symlink_path> -DCMAKE_BUILD_TYPE=Release -B builddir -S mangos-classic`. Build: `cmake --build builddir -- -j$(nproc)`.
- **Compat shims:** Core mangos game files include `playerbot/X.h` and `ahbot/AhBot.h` (old paths). Created shim headers at module root `playerbot/` and `ahbot/` that forward to new `src/` paths. Required files: `playerbot/{playerbot.h,PlayerbotAI.h,PlayerbotAIConfig.h,RandomPlayerbotMgr.h}`, `ahbot/AhBot.h`.
- **Angle-bracket include gotcha:** One file (DebugAction.cpp) used `<playerbot/TravelNode.h>` with angle brackets — missed by sed which only targeted double-quote includes. Always check `<playerbot/` pattern too when fixing stale includes.
