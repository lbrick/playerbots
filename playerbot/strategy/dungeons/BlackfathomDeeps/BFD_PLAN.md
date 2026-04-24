# Blackfathom Deeps — Implementation Plan

**Map ID:** 48  
**Levels:** 20–30  
**Status:** 🟡 IN PROGRESS  
**NPC IDs:** ✅ Verified against classicmangos `creature_template` and `instance_template` (2026-04-23)

---

## Resume Protocol

At session start: scan for first `[ ]` — that is the resume point. Mark `[x]` as each step is confirmed done.

---

## Scope

Follow the shared dungeon workflow in `cmangos-playerbots/playerbot/strategy/dungeons/DUNGEON_GUIDE.md`:

- add one instance strategy for Blackfathom Deeps
- add one fight strategy per boss
- keep v1 conservative: prefer start/end boss strategies first, then add only mechanics that fit existing reusable triggers/actions cleanly
- avoid custom movement or event scripting unless runtime evidence says the basic implementation is not enough

Recommended delivery split:

- **Pass 1:** full dungeon scaffolding + all start/end boss strategies + v1 mechanics for Ghamoo-ra, Lady Sarevess, and Aku'mai
- **Pass 2:** add one or two mechanics that map well onto reusable interrupt or MoveAway patterns
- **Stretch only if needed:** event-room logic (Baron Aquanis) or custom handling for Kelris/Aku'mai if basic strategies prove insufficient

---

## Boss Reference

> ✅ NPC IDs verified against classicmangos DB (2026-04-23)
> ✅ Encounter flow and boss mechanics reviewed against Wowhead Classic BFD guide (2024-11-19)
> ⚠️ Spell IDs and final mechanic selections still need spell-data/runtime verification before coding interrupt or hazard triggers

| Boss | NPC ID | Key Mechanic | Bot Action Needed |
|------|--------|-------------|------------------|
| Ghamoo-ra | 4887 | High armor; periodic **Trample** means party should not stack tightly | include a conservative spread/MoveAway-style v1 mechanic if it maps cleanly |
| Lady Sarevess | 4831 | Patrols with **2 naga adds**; pull control matters more than boss spell kit | include v1 encounter handling focused on add-aware pull/target behavior |
| Gelihast | 6243 | Boss is simple, but his room is packed with murlocs and **Net** can cause chain pulls | start/end triggers only; clear-room requirement is the real mechanic |
| Lorgus Jett | 12902 | Shaman-style caster; likely strongest interrupt candidate in early BFD | pending spell verification; likely `interrupt enemy cast` in v1 |
| Baron Aquanis | 12876 | Event-spawn elemental boss; simple combat once active | start/end triggers only; event-room handling deferred |
| Twilight Lord Kelris | 4832 | **Sleep** on healer/support plus shadow damage | pending spell verification; likely `interrupt enemy cast` in v1 |
| Aku'mai | 4829 | **Poison Cloud** positioning + **Frenzied Rage** tank damage spike | include `Poison Cloud` avoidance in v1 after spell/radius confirmation |

### Mechanic Notes

**Dungeon-wide**
- BFD includes underwater traversal and an underwater optional boss area, so breath/pathing is part of the dungeon burden even before boss mechanics.
- Trash is not individually special according to the guide, but the dungeon wants slow pulls, crowd control on larger packs, and interrupts/stuns for casters.

**Lorgus Jett**
- Best candidate for a reusable interrupt-based mechanic in BFD.
- Likely cast-driven rather than positional.
- Do not promise a custom trigger until the exact heal/lightning/totem spell IDs are verified from spell data or runtime logs.

**Twilight Lord Kelris**
- Sleep is the main mechanic players actually notice in Classic.
- If Kelris exposes a clean interruptable cast with stable spell ID(s), use `TargetCastingSpellTrigger` + `interrupt enemy cast`.
- If the spell cannot be cleanly targeted in the current framework, keep Kelris v1 to start/end only and document the gap.

**Baron Aquanis**
- Spawned through the shrine/event sequence rather than a standard always-present boss.
- Boss strategy itself is still straightforward, but encounter-start timing may require checking whether the stock start-fight trigger is sufficient once the event summons him.

**Ghamoo-ra**
- Wowhead describes him as a simple tank-and-spank with very high armor.
- The only meaningful fight note is not stacking too tightly because of `Trample`.
- BFD v1 should still include a conservative anti-stack response here so the first boss is not pure start/end scaffolding.
- Preferred implementation shape: `CloseToHostileCreatureHazardTrigger` + `MoveAwayFromCreature` if radius/runtime behavior is stable enough.

**Lady Sarevess**
- The important mechanic is the pull setup: she comes with two naga bodyguards.
- The guide recommendation is to clear the cave first, crowd control at least one add, kill an add, then switch to Sarevess.
- That suggests encounter difficulty here is mostly target selection / add control, not a boss-specific movement script.
- BFD v1 should explicitly include encounter handling for this pull rather than treating Sarevess as start/end only.
- Exact implementation may be strategy priority/target-selection oriented rather than a positional trigger.

**Gelihast**
- The boss itself is simple.
- The dangerous part is that his room is full of murlocs, and `Net` can pin the tank and cause accidental extra pulls.
- This is a dungeon-pathing / pull-discipline mechanic more than a boss-strategy mechanic, so keep v1 at start/end only.

**Twilight Lord Kelris**
- Wowhead specifically calls out `Sleep` as the real danger because it can disable the healer.
- The tactical answer is keeping the tank stable and having hybrids cover healing during healer sleep.
- If a clean spell trigger exists, Kelris is a strong interrupt candidate for v1.

**Fire of Aku'mai event**
- This event is mandatory after Kelris to open Aku'mai's door.
- Four braziers around the statue pedestal each trigger one enemy wave.
- The first turtle wave is specifically called out as the hardest and may require an off-tank, pet tank, or equivalent split pickup.
- This is the main non-boss dungeon mechanic in BFD and should be tracked separately from boss strategy work.

**Aku'mai**
- Wowhead calls this a simple final fight structurally, but with heavy single-target tank damage from `Frenzied Rage`.
- `Poison Cloud` is the positional mechanic that matters; party members should stay out so the healer can stay focused on the tank.
- This makes Aku'mai the best candidate in BFD for a real hazard/MoveAway action once spell/radius data is confirmed.
- Aku'mai poison handling is part of the required BFD v1 scope, not a deferred nice-to-have.

---

## Files to Create

```
playerbot/strategy/dungeons/BlackfathomDeeps/
  Action/
    BfdActions.h
  Trigger/
    BfdTriggers.h
  Strategy/
    BfdStrategy.h
    BfdStrategy.cpp
  BFD_PLAN.md       ← this file
```

---

## Pre-Code Checklist

- [x] Verify all boss NPC IDs against classicmangos DB ✅
- [x] Confirm map ID 48 in `instance_template` ✅
- [ ] Verify which BFD boss casts are worth interrupting in v1 (likely Lorgus Jett and/or Twilight Lord Kelris)
- [ ] Verify exact spell IDs for any interrupt triggers before adding them
- [ ] Verify Ghamoo-ra `Trample` behavior/radius well enough to choose a safe v1 spacing mechanic
- [ ] Decide what the simplest reliable v1 handling is for Lady Sarevess's two-add pull
- [ ] Decide whether Baron Aquanis event timing needs anything beyond stock start/end fight triggers
- [ ] Verify whether Aku'mai `Poison Cloud` maps cleanly to an existing hazard trigger
- [ ] Decide whether the Fire of Aku'mai event needs its own follow-up implementation plan beyond boss strategies

## Pre-Code DB Queries

```sql
SELECT entry, name FROM creature_template
WHERE name IN ('Ghamoo-ra', 'Lady Sarevess', 'Gelihast', 'Lorgus Jett',
               'Baron Aquanis', 'Twilight Lord Kelris', 'Aku''mai');

SELECT map FROM instance_template WHERE map = 48;
```

Verified output:

```sql
+-------+----------------------+
| entry | name                 |
+-------+----------------------+
|  4829 | Aku'mai              |
|  4831 | Lady Sarevess        |
|  4832 | Twilight Lord Kelris |
|  4887 | Ghamoo-ra            |
|  6243 | Gelihast             |
| 12876 | Baron Aquanis        |
| 12902 | Lorgus Jett          |
+-------+----------------------+

+-----+
| map |
+-----+
|  48 |
+-----+
```

---

## Registration Checklist

- [ ] `playerbot/strategy/generic/DungeonStrategy.cpp` — enter/leave blackfathom deeps (combat + noncombat)
- [ ] `playerbot/strategy/triggers/TriggerContext.h` — include `BfdTriggers.h` + register all triggers
- [ ] `playerbot/strategy/actions/ActionContext.h` — include `BfdActions.h` + register all actions
- [ ] `playerbot/strategy/StrategyContext.h` — include `BfdStrategy.h` + register all strategies
- [ ] `CMakeLists.txt` — add `Ai_Dungeon_BFD` GLOB_RECURSE + LIBRARY_SRCS entry

---

## Planned Trigger List

| Trigger string | Class | Notes |
|----------------|-------|-------|
| `enter blackfathom deeps` | `BlackfathomDeepsEnterDungeonTrigger` | map 48 |
| `leave blackfathom deeps` | `BlackfathomDeepsLeaveDungeonTrigger` | map 48 |
| `start ghamoo-ra fight` | `GhamooRaStartFightTrigger` | NPC 4887 |
| `end ghamoo-ra fight` | `GhamooRaEndFightTrigger` | |
| `ghamoo-ra trample` | `GhamooRaTrampleTrigger` | likely CloseToHostileCreature, radius TBD |
| `start lady sarevess fight` | `LadySarevessStartFightTrigger` | NPC 4831 |
| `end lady sarevess fight` | `LadySarevessEndFightTrigger` | |
| `lady sarevess adds active` | `LadySarevessAddsTrigger` | if a clean add-aware trigger can be expressed |
| `start gelihast fight` | `GelihastStartFightTrigger` | NPC 6243 |
| `end gelihast fight` | `GelihastEndFightTrigger` | |
| `start lorgus jett fight` | `LorgusJettStartFightTrigger` | NPC 12902 |
| `end lorgus jett fight` | `LorgusJettEndFightTrigger` | |
| `start baron aquanis fight` | `BaronAquanisStartFightTrigger` | NPC 12876 |
| `end baron aquanis fight` | `BaronAquanisEndFightTrigger` | |
| `start kelris fight` | `KelrisStartFightTrigger` | NPC 4832 |
| `end kelris fight` | `KelrisEndFightTrigger` | |
| `start aku'mai fight` | `AkuMaiStartFightTrigger` | NPC 4829 |
| `end aku'mai fight` | `AkuMaiEndFightTrigger` | |
| `aku'mai poison cloud` | `AkuMaiPoisonCloudTrigger` | hazard trigger after spell/radius confirmation |

### Deferred Trigger Candidates

- `target casting lorgus jett <spell>` — add only after spell verification
- `target casting kelris sleep` — add only after spell verification
- `lady sarevess adds active` — add only if the add-handling behavior needs a dedicated trigger
- `fire of aku'mai wave` / turtle-wave specific handling — only if the event proves unreliable with stock combat AI

---

## Planned Action List

| Action string | Class |
|---------------|-------|
| `enable blackfathom deeps strategy` | `BlackfathomDeepsEnableStrategyAction` |
| `disable blackfathom deeps strategy` | `BlackfathomDeepsDisableStrategyAction` |
| `enable ghamoo-ra fight strategy` | `GhamooRaEnableFightStrategyAction` |
| `disable ghamoo-ra fight strategy` | `GhamooRaDisableFightStrategyAction` |
| `ghamoo-ra move away from trample` | `GhamooRaMoveAwayFromTrampleAction` |
| `enable lady sarevess fight strategy` | `LadySarevessEnableFightStrategyAction` |
| `disable lady sarevess fight strategy` | `LadySarevessDisableFightStrategyAction` |
| `lady sarevess focus add` | `LadySarevessFocusAddAction` or equivalent target-selection action |
| `enable gelihast fight strategy` | `GelihastEnableFightStrategyAction` |
| `disable gelihast fight strategy` | `GelihastDisableFightStrategyAction` |
| `enable lorgus jett fight strategy` | `LorgusJettEnableFightStrategyAction` |
| `disable lorgus jett fight strategy` | `LorgusJettDisableFightStrategyAction` |
| `enable baron aquanis fight strategy` | `BaronAquanisEnableFightStrategyAction` |
| `disable baron aquanis fight strategy` | `BaronAquanisDisableFightStrategyAction` |
| `enable kelris fight strategy` | `KelrisEnableFightStrategyAction` |
| `disable kelris fight strategy` | `KelrisDisableFightStrategyAction` |
| `enable aku'mai fight strategy` | `AkuMaiEnableFightStrategyAction` |
| `disable aku'mai fight strategy` | `AkuMaiDisableFightStrategyAction` |
| `aku'mai move away from poison cloud` | `AkuMaiMoveAwayFromPoisonCloudAction` |
| `interrupt enemy cast` | existing reusable action if Lorgus/Kelris interrupt triggers are added |

---

## Planned Strategy List

| Strategy string | Class |
|-----------------|-------|
| `blackfathom deeps` | `BlackfathomDeepsDungeonStrategy` |
| `ghamoo-ra` | `GhamooRaFightStrategy` |
| `lady sarevess` | `LadySarevessFightStrategy` |
| `gelihast` | `GelihastFightStrategy` |
| `lorgus jett` | `LorgusJettFightStrategy` |
| `baron aquanis` | `BaronAquanisFightStrategy` |
| `kelris` | `KelrisFightStrategy` |
| `aku'mai` | `AkuMaiFightStrategy` |

---

## Implementation Steps

- [x] Step 1: Verify NPC IDs and map ID locally; update plan with confirmed DB output ✅
- [x] Step 2: Verify Ghamoo-ra `Trample`, Lady Sarevess add-handling shape, and Aku'mai `Poison Cloud` so those three mechanics are included in v1
  - Trample: spell_template Id 5568/15550, EffectRadiusIndex1=13 (~5yd). Trigger radius 8yd.
  - Lady Sarevess: no clean add-aware trigger exists in codebase — v1 is start/end only; add targeting deferred.
  - Poison Cloud: spell_template Id 3815, EffectRadiusIndex1=14 (~8yd). Trigger radius 10yd.
- [x] Step 3: Verify Lorgus Jett and Twilight Lord Kelris cast/spell IDs to decide whether interrupt triggers belong in v1
  - creature_template_spells returned no entries for either boss — spells are C++-scripted. Interrupt triggers deferred to post-runtime verification.
- [x] Step 4: Create `BfdTriggers.h` with instance enter/leave + all boss start/end triggers ✅
- [x] Step 5: Add verified v1 mechanic triggers for Ghamoo-ra and Aku'mai (Lady Sarevess deferred) ✅
- [x] Step 6: Create `BfdActions.h` with instance and boss enable/disable actions plus v1 mechanic actions ✅
- [x] Step 6b: Create `BfdStrategy.h` with one dungeon strategy and one fight strategy per boss ✅
- [x] Step 7: Create `BfdStrategy.cpp` with start/end fight wiring for all bosses ✅
- [x] Step 8: Register Blackfathom Deeps in `DungeonStrategy.cpp` ✅
- [x] Step 9: Register all BFD triggers in `TriggerContext.h` ✅
- [x] Step 10: Register all BFD actions in `ActionContext.h` ✅
- [x] Step 11: Register all BFD strategies in `StrategyContext.h` ✅
- [x] Step 12: Add `CMakeLists.txt` entry for `Ai_Dungeon_BFD` ✅
- [x] Step 13: Build cleanly with no new BFD-specific errors ✅
- [ ] Step 14: In-game verify dungeon strategy enable/disable on enter/leave
- [ ] Step 15: In-game verify each boss strategy enables on engage and disables on death/reset
- [ ] Step 16: Verify Ghamoo-ra, Lady Sarevess, and Aku'mai v1 mechanics in-game
- [ ] Step 17: Verify any Lorgus/Kelris interrupt mechanics added to v1
- [ ] Step 18: Observe the Fire of Aku'mai event and decide whether it needs dedicated event logic

---

## Definition of Done

- [ ] `./build-classic.sh` clean with no new BFD-specific errors
- [ ] Bot enters BFD → `enable blackfathom deeps strategy` appears in log
- [ ] Each boss engaged → corresponding fight strategy enables
- [ ] Each boss dies/resets → corresponding fight strategy disables
- [ ] Bot leaves BFD → `disable blackfathom deeps strategy` appears in log
- [ ] Ghamoo-ra spacing mechanic is active and acceptable in combat
- [ ] Lady Sarevess pull/add-handling mechanic is active and acceptable in combat
- [ ] Aku'mai poison handling works acceptably in combat
- [ ] Any chosen Lorgus/Kelris interrupt trigger works reliably if included
- [ ] Baron Aquanis event-spawn encounter is at least playable with the stock start/end trigger path
- [ ] Fire of Aku'mai event is at least playable without custom event logic, or a follow-up plan is opened

---

## Current Notes

- BFD should be implemented conservatively first. The boss roster is clear, but the best reusable mechanics depend on verifying actual cast IDs and whether those casts surface cleanly through the existing interrupt trigger path.
- BFD v1 now explicitly includes mechanics for:
  - Ghamoo-ra
  - Lady Sarevess
  - Aku'mai
- The safest v1 is now: full dungeon scaffolding + start/end boss strategies for all seven bosses, plus those three concrete boss mechanics, with Lorgus/Kelris interrupt work added only after spell verification.
- `Baron Aquanis` is the only encounter here with obvious event-driven timing risk; this should be tested early once scaffolding exists.
- The guide suggests the biggest real gameplay pain points are not raw boss complexity, but:
  - Lady Sarevess add pull control
  - Gelihast room clearing before pull
  - Kelris healer sleep coverage
  - Fire of Aku'mai brazier waves
  - Aku'mai poison cloud + frenzy tank pressure

## Verify Commands

With `LogFileLevel = 3`, grep `Server.log` for:

```text
enable blackfathom deeps strategy
disable blackfathom deeps strategy
enable kelris fight strategy
enable lorgus jett fight strategy
disable aku'mai fight strategy
```
