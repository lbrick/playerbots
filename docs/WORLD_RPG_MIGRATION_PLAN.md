# World/RPG System Migration Plan
**Source:** azerothcore-playerbots `src/Ai/World/Rpg/`  
**Target:** cmangos-playerbots `src/Ai/World/Rpg/` (new directory)  
**Date:** 2026-04-15

---

## What We're Porting

The AC "New RPG" system gives random bots an autonomous state machine — they cycle through
7 states (idle, grind, camp, wander NPC, wander random, quest, flight) rather than just
standing around. This is distinct from the **legacy RPG system** (trigger-based sub-actions
for NPC interactions) which cmangos already has.

### Source files (all in `azerothcore-playerbots/src/Ai/World/Rpg/`)

| File | LOC | Role |
|------|-----|------|
| `NewRpgInfo.h/.cpp` | 290 | State container — holds current status + position data via `std::variant` |
| `Action/NewRpgBaseAction.h/.cpp` | 1300 | Base class with shared helpers (pathfinding, quest POI lookup, stuck recovery) |
| `Action/NewRpgAction.h/.cpp` | 590 | 7 concrete state actions (GoGrind, GoCamp, WanderNpc, WanderRandom, DoQuest, TravelFlight, StatusUpdate) |
| `Strategy/NewRpgStrategy.h/.cpp` | 98 | Strategy registering 6 status triggers + default StatusUpdate action |
| `Trigger/NewRpgTriggers.h/.cpp` | ~50 | One trigger: fires when `rpgInfo.GetStatus() == expected_status` |

**Legacy system** (`RpgStrategy`, `RpgSubActions`, `RpgAction`, `RpgValues`) — already present
in cmangos. Not touched by this migration.

---

## What cmangos Already Has (No Re-implementation Needed)

| Component | cmangos location | Notes |
|-----------|-----------------|-------|
| `PathFinder` | `mangos-classic/src/game/MotionGenerators/PathFinder.h` | Direct equivalent to AC `PathGenerator`. Different class name, same `PathType` enum values. |
| `WorldPosition` | `src/Util/WorldPosition.h` | Already exists in cmangos-playerbots |
| `TravelMgr` + quest destinations | `src/Mgr/TravelMgr.h` | `QuestObjectiveTravelDestination`, `QuestRelationTravelDestination` already model quest travel |
| `Quest` struct with objectives | `mangos-classic/src/game/Quests/QuestDef.h` | `ReqCreatureOrGOId[]`, `ReqItemId[]`, `ReqCreatureOrGOCount[]` all present |
| Taxi DBC data | `sTaxiNodesStore` (DBCStores.h) | Available; lookup API differs from AC (see Phase 3) |
| `MovementAction` base | `src/Ai/Base/actions/MovementActions.h` | `MoveTo()`, `MoveNear()`, etc. already present |
| `Action` / `Trigger` / `Strategy` / `Value` | `src/Ai/Base/` | Core framework identical in structure |
| C++20 standard | `mangos-classic/CMakeLists.txt` line 32 | `std::variant` is C++17 — **no blocker** |
| `BroadcastHelper` | `src/Util/BroadcastHelper.h` | Already exists in cmangos-playerbots |
| `ServerFacade` | `src/Util/ServerFacade.h` | Already exists |

---

## API Gap Analysis

These are the AC APIs used in the RPG system that differ or are absent in cMaNGOS. Each
gap has a resolution strategy.

### Gap 1 — `sObjectMgr->GetQuestPOIVector(questId)`
AC uses this to find objective marker positions (map coordinates for quest objectives).
**cMaNGOS Classic does not store quest POI data** — the Vanilla client uses an older system
with no server-side POI table. Instead, objective locations are embedded in
`ReqCreatureOrGOId[]` / `ReqSpell[]` fields and must be found by scanning the world for
matching creature/GO spawns.

**Resolution:** Replace `GetQuestPOIVector()` calls with `TravelMgr::GetDestinations()` using
`QuestObjectiveTravelDestination` — cmangos-playerbots already builds a travel table from
creature/GO spawn data. This is a design improvement over AC's approach for Vanilla.

### Gap 2 — `PathGenerator` → `PathFinder`
AC uses `PathGenerator(bot).CalculatePath(x, y, z)`.
cMaNGOS has `PathFinder(bot).calculate(x, y, z)` with the same `PathType` enum.

**Resolution:** Mechanical rename. `PathGenerator` → `PathFinder`, `.CalculatePath()` →
`.calculate()`, `.GetActualEndPosition()` → `.getEndPosition()`. All `PATHFIND_*` enum
values are identical.

### Gap 3 — `Map::CheckCollisionAndGetValidCoords()` / `CanReachPositionAndGetValidCoords()`
AC map has helpers for terrain collision validation that cMaNGOS may not expose at the
same API level.

**Resolution:** cmangos `Map::GetHeight(x, y, z)` is available. For collision checks,
use `PathFinder` to validate reachability — if `getPathType()` returns `PATHFIND_NOPATH`
the position is unreachable. The stuck-recovery fallback in `NewRpgBaseAction::MoveFarTo()`
(direct teleport after 90s of no progress) already handles mmap failures gracefully.

### Gap 4 — `sObjectMgr->GetNearestTaxiNode(x, y, z, mapId, teamId)`
AC ObjectMgr has a utility to find the nearest flight master.

**Resolution:** Iterate `sTaxiNodesStore` (DBCStores.h) and find minimum distance entry
matching the bot's map. cmangos-playerbots `TravelMgr` may already index flight masters —
check before writing. Wrap in a helper function in the new `NewRpgBaseAction`.

### Gap 5 — `ObjectAccessor::GetWorldObject(bot, guid)` / `GetCreatureOrPetOrVehicle()`
AC object lookup signatures.

**Resolution:** cMaNGOS uses `bot->GetMap()->GetAnyTypeCreature(guid)` and
`bot->GetMap()->GetGameObject(guid)`. Already used extensively throughout
cmangos-playerbots — copy the existing pattern from `RpgSubActions.cpp`.

### Gap 6 — `bot->CanInteractWithQuestGiver(obj)` / `bot->PrepareQuestMenu(guid)`
AC Player methods for gossip/quest interaction readiness.

**Resolution:** cMaNGOS equivalent is `bot->GetGameObjectIfCanInteractWith()` (for GOs) and
NPC flag checks via `HasNpcFlag(UNIT_NPC_FLAG_QUESTGIVER)`. Already used in existing
cmangos RPG sub-actions.

### Gap 7 — `creature->GetReactionTo(bot)` returning `REP_UNFRIENDLY`
AC faction reaction check.

**Resolution:** cMaNGOS uses `bot->IsFriendlyTo(creature)` / `bot->IsHostileTo(creature)`.
Direct substitution.

### Gap 8 — `NewRpgInfo` member on `PlayerbotAI`
AC `PlayerbotAI.h` line 600: `NewRpgInfo rpgInfo; NewRpgStatistic rpgStatistic;`
cmangos `PlayerbotAI.h` has neither.

**Resolution:** Add both members to cmangos `PlayerbotAI.h`. Forward-declare `NewRpgInfo`
to minimize include chain impact. This is the one required change to an engine file.

### Gap 9 — `AiPlayerbot.EnableNewRpgStrategy` config flag
AC config has `bool enableNewRpgStrategy` in `PlayerbotAIConfig`.

**Resolution:** Add `bool enableNewRpgStrategy` to cmangos `PlayerbotAIConfig.h/.cpp` with
default `true`. Add corresponding entry to `aiplayerbot.conf.dist.in`.

### Gap 10 — `QUEST_OBJECTIVES_COUNT` / `QUEST_ITEM_OBJECTIVES_COUNT` constants
Both exist in cmangos `QuestDef.h` with the same values. **No change needed.**

---

## Target Directory Structure

```
cmangos-playerbots/src/Ai/World/
  Rpg/
    NewRpgInfo.h           — state container (std::variant status types)
    NewRpgInfo.cpp
    Action/
      NewRpgBaseAction.h   — shared helpers base class
      NewRpgBaseAction.cpp
      NewRpgAction.h       — 7 concrete state action classes
      NewRpgAction.cpp
    Strategy/
      NewRpgStrategy.h
      NewRpgStrategy.cpp
    Trigger/
      NewRpgTriggers.h
      NewRpgTriggers.cpp
```

Follow the same `Action/Strategy/Trigger` pattern established in the Raid restructure.

---

## Files to Touch Outside the New Directory

| File | Change |
|------|--------|
| `src/Bot/Engine/PlayerbotAI.h` | Add `NewRpgInfo rpgInfo;` and `NewRpgStatistic rpgStatistic;` members + forward-declare / include `NewRpgInfo.h` |
| `src/Bot/PlayerbotAIConfig.h` | Add `bool enableNewRpgStrategy;` |
| `src/Bot/PlayerbotAIConfig.cpp` | Read `AiPlayerbot.EnableNewRpgStrategy` from conf, default `true` |
| `src/Bot/Factory/AiFactory.cpp` | Add `if (sPlayerbotAIConfig.enableNewRpgStrategy) nonCombatEngine->addStrategy("new rpg")` for random bots |
| `src/Ai/Base/StrategyContext.h` | Register `"new rpg"` → `NewRpgStrategy` |
| `src/Ai/Base/actions/ActionContext.h` | Register all 7 new RPG action names |
| `src/Ai/Base/triggers/TriggerContext.h` | Register 6 new RPG status triggers |
| `conf/aiplayerbot.conf.dist.in` | Add `AiPlayerbot.EnableNewRpgStrategy = 1` with comment |
| `CMakeLists.txt` | Add `GLOB_RECURSE` for `src/Ai/World/` |

---

## Migration Phases

### Phase 1 — Directory scaffold + data structures ✅ COMPLETE
**Goal:** Get the new files compiling with no logic.  
**Completed:** 2026-04-15

1. ✅ Create `src/Ai/World/Rpg/` with the target layout above.
2. ✅ Port `NewRpgInfo.h/.cpp` — the `std::variant`-based status container.
   - All status structs (`RpgIdle`, `RpgGoGrind`, `RpgGoCamp`, `RpgWanderNpc`,
     `RpgWanderRandom`, `RpgDoQuest`, `RpgRest`, `RpgTravelFlight`) are plain data —
     no AC API calls. Direct copy.
3. ✅ Add `NewRpgInfo rpgInfo` and `NewRpgStatistic rpgStatistic` to cmangos `PlayerbotAI.h`.
4. ✅ Add `enableNewRpgStrategy` to `PlayerbotAIConfig`.
5. ✅ Update `CMakeLists.txt` — `GLOB_RECURSE` covers `src/Ai/World/`.
6. ✅ **Verified:** `./build.sh` clean — all 5 new files compile with zero errors/warnings (2026-04-16).

**Actual new LOC:** ~350

---

### Phase 2 — Strategy + Trigger (skeleton) ✅ COMPLETE (partial — see note)
**Goal:** "new rpg" strategy loads and registers without crashing.  
**Completed:** 2026-04-15 (context wiring); AiFactory deferred to Phase 5

1. ✅ Port `NewRpgStrategy.h/.cpp` — registers 6 status `TriggerNode`s + default action.
2. ✅ Port `NewRpgTriggers.h/.cpp` — one trigger class checking `rpgInfo.GetStatus()`.
3. ✅ Register `"new rpg"` in `StrategyContext.h` and all 6 status triggers in `TriggerContext.h`.
4. ✅ Register all 7 action names in `ActionContext.h`.
5. ⏸ Wire `AiFactory.cpp` to add `"new rpg"` for random bots — **deferred to Phase 5**
   (strategy is registered and selectable, but not auto-loaded for random bots yet).
6. ⏸ **Verify:** bots load with "new rpg" strategy — blocked on AiFactory wiring.

**Note:** `NewRpgBaseAction.cpp` and `NewRpgAction.cpp` exist as stubs (all `Execute()`
methods return `false`). The strategy compiles and the framework is fully wired; bots will
load the strategy once AiFactory is updated in Phase 5.

---

### Phase 3 — NewRpgBaseAction (core helpers) ✅ COMPLETE
**Goal:** Port the 1300-LOC helper base class, resolving all API gaps.
**Completed:** 2026-04-16

This is the hardest phase. Work through `NewRpgBaseAction.cpp` method by method:

**Key API resolutions made:**
- `PathGenerator` → `PathFinder`, `.CalculatePath()` → `.calculate()`, `.getEndPosition()` returns `Movement::Vector3`
- `sObjectMgr->GetQuestPOIVector()` → `sTravelMgr.GetDestinations()` with `TravelDestinationPurpose::QuestTaker` / `QuestObjective1-4`
- `ObjectAccessor::Get*` → `bot->GetMap()->GetWorldObject/GetCreature/GetGameObject(guid)`
- `getMSTime()` → `WorldTimer::getMSTime()`, `GetMSTimeDiffToNow(t)` → `WorldTimer::getMSTimeDiff(t, WorldTimer::getMSTime())`
- `StatsWeightCalculator` (absent) → simplified ItemUsage-based reward selection
- Flight taxi: iterates NPC flags for `UNIT_NPC_FLAG_FLIGHTMASTER` + `sTaxiPathStore` enumeration
- Grind/camp positions: `sTravelMgr.GetPartitions()` with `TravelDestinationPurpose::Grind` / `GenericRpg`
- `LOG_DEBUG("playerbots", fmt, ...)` → `sLog.outDebug(fmt, ...)` (printf-style)
- `bot->IsInFlight()` → `bot->IsTaxiFlying()`
- `ai->TellPlayerNoFacing(GetMaster(), text)` for quest messages
- `ChatHelper::formatQuest(quest)` (static) not `chat->formatQuest()`
- `GetQuestPOIPosAndObjectiveIdx` returns single position via out-params (not vector)

**Actual new LOC:** ~650

---

### Phase 4 — Concrete state actions ✅ COMPLETE
**Goal:** Port the 7 state-specific action classes.
**Completed:** 2026-04-16

All 7 state action classes implemented in `NewRpgAction.cpp`. Key adaptations:
- `bot->IsInFlight()` → `bot->IsTaxiFlying()`, `bot->Dismount()` → `bot->Unmount()`
- `sObjectMgr->` → `sObjectMgr.`, quest status fields `m_creatureOrGOcount[]` / `m_itemcount[]`
- `ObjectAccessor::GetWorldObject()` → `bot->GetMap()->GetWorldObject(guid)`
- `ObjectAccessor::GetCreature()` → `bot->GetMap()->GetCreature(guid)`
- `WorldPosition(bot).distance(pos)` for bot-to-WorldPosition distance checks
- `ChooseNpcOrGameObjectToInteract()` → `ChooseNpcOrGoToInteract()`
- `InteractWithNpcOrGameObjectForQuest()` → `InteractWithNpcOrGoForQuest()`
- Added `std::set<uint32> lowPriorityQuest` to `PlayerbotAI.h` (tracks abandoned quests)
- `IsWithinInteractionDist(obj)` removed — use `bot->GetDistance(obj) <= INTERACTION_DISTANCE`

**Actual new LOC:** ~280

---

### Phase 5 — Context registration + config ✅ COMPLETE
**Goal:** System fully wired, builds clean, controlled by config flag.
**Completed:** 2026-04-16

1. ✅ Register all action/trigger strings in `ActionContext.h` and `TriggerContext.h`.
2. ✅ Add `AiPlayerbot.EnableNewRpgStrategy` + all `RpgStatusProbWeight.*` entries to `aiplayerbot.conf.dist.in`.
3. ✅ Wire `AiFactory.cpp` — `"new rpg"` added alongside `"rpg"` in both random bot paths (ungrouped leader + grouped bot-master) when `enableNewRpgStrategy` is true. Removed on BG entry. Real-player bots (ChangeStrategy path) never receive it.
4. ✅ No Phase 3/4 stubs remain — all Execute() methods implemented.

---

### Phase 6 — Testing ⬜ TODO
**Goal:** Confirm bots actually behave correctly.

| Test | How |
|------|-----|
| State transitions | Enable debug logging (`debug rpg` strategy), watch bot cycle through states in server console |
| Quest completion | Create random bot near quest-giver NPC; verify it accepts, progresses, and turns in |
| Stuck recovery | Place bot in area with mmap gaps; confirm 90s teleport fires rather than indefinite stuck loop |
| Flight paths | Verify bot discovers and uses flight paths; `bot->IsInFlight()` returns true during travel |
| Wander NPC | Confirm bot approaches and interacts with NPCs in range |
| Config flag off | Set `EnableNewRpgStrategy = 0`; confirm bots fall back to legacy RPG strategy only |

---

## Risk Register

| Risk | Likelihood | Impact | Mitigation |
|------|-----------|--------|-----------|
| Quest POI lookup has no equivalent | High (confirmed) | High | Use TravelMgr — already designed for this |
| `ActivateTaxiPathTo()` API differs | Medium | Medium | Check cmangos Player API; existing TaxiRpg sub-action may already handle this |
| Stuck recovery teleport breaks server rules | Low | Medium | Gate behind `IsRandomBot()` check — same as AC |
| `std::variant` compile issues | **Resolved** | Low | Compiles clean under C++20 |
| `PlayerbotAI.h` change causes rebuild cascade | **Resolved** | Low | Forward-declare used; rebuild was ~11s |
| NewRpg conflicts with legacy RPG triggers | Medium | Medium | Both systems use separate strategy names; test that both can coexist |

---

## What This Does NOT Include

- Porting `RpgStrategy` / `RpgSubActions` / `RpgAction` / `RpgValues` — **already in cmangos**
- Any WotLK-specific RPG states (AC has none specific to WotLK in this system)
- The AC `TravelMgr` rewrite (cmangos already has its own capable TravelMgr)
- Guild petition RPG action (`RpgBuyPetition`) — cmangos already has this in legacy RPG

---

## Definition of Done

- [x] `./build.sh` completes with no errors or new warnings (verified Phases 1–4)
- [x] `NewRpgBaseAction.cpp` — all helpers implemented (Phase 3 ✅)
- [x] `NewRpgAction.cpp` — all 7 state actions implemented (Phase 4 ✅)
- [x] `AiFactory.cpp` wired — random bots auto-load "new rpg" when config enabled (Phase 5 ✅)
- [ ] `enableNewRpgStrategy = 1` → random bots cycle through visible state transitions (Phase 6)
- [ ] `enableNewRpgStrategy = 0` → falls back silently to legacy RPG behavior (Phase 6)
- [ ] No regression in existing RPG sub-actions (quest, vendor, taxi, repair, etc.) (Phase 6)
- [x] `src/Ai/World/Rpg/` follows the `Action/Strategy/Trigger` directory pattern from raids
