# Cerebrum

> OpenWolf's learning memory. Updated automatically as the AI learns from interactions.
> Do not edit manually unless correcting an error.
> Last updated: 2026-04-15

## User Preferences

<!-- How the user likes things done. Code style, tools, patterns, communication. -->

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
  - `src/Ai/Raid/{raid}/` — BlackwingLair, Karazhan, MoltenCore, Naxxramas, OnyxiasLair
  - `src/AhBot/` — AH bot source
  - `conf/` — aiplayerbot.conf.dist.in*, ahbot.conf.dist.in
  - `data/sql/` — characters/base, characters/updates, world/{classic,tbc,wotlk}, other/
  - botpch.cpp/.h at root
- **Include convention:** All includes use `src/Bot/`, `src/Ai/Base/`, `src/Ai/Class/{class}/`, `src/AhBot/` prefixes. Repo root is CMake include dir. Relative same-dir includes still used within class subdirs.
- **Dir naming:** New structural dirs (src/Ai/, src/Bot/, src/AhBot/) use PascalCase. Existing strategy subdirs keep lowercase (actions/, generic/, triggers/, values/, druid/, etc.).

## Do-Not-Repeat

<!-- Mistakes made and corrected. Each entry prevents the same mistake recurring. -->
<!-- Format: [YYYY-MM-DD] Description of what went wrong and what to do instead. -->

## Decision Log

- **[2026-04-15] Repo restructure:** Mirrored azerothcore-playerbots layout. playerbot/ → src/Bot/, playerbot/strategy/ → src/Ai/Base/, per-class dirs → src/Ai/Class/{class}/, ahbot/ → src/AhBot/, sql/ → data/sql/, conf files → conf/. ~780 include paths updated via sed. CMakeLists.txt rewritten. Zero logic changes. Lowercase kept for existing subdir names (cMaNGOS convention). PascalCase for new structural dirs.
