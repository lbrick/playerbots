# The Deadmines — Implementation Plan

**Map ID:** 36  
**Levels:** 17–26  
**Status:** 🟡 IN PROGRESS  
**NPC IDs:** ✅ Verified against classicmangos `creature_template` (2026-04-20)

---

## Resume Protocol

At session start: scan for first `[ ]` — that is the resume point. Mark `[x]` as each step is confirmed done.

---

## Boss Reference

> ✅ NPC IDs verified against classicmangos `creature_template` (2026-04-20)
> ⚠️ Greenskin not found in DB — not a killable boss NPC in this build, skip

| Boss | NPC ID | Key Mechanic | Bot Action Needed |
|------|--------|-------------|------------------|
| Rhahk'Zor | 644 | **Rhahk'Zor's Slam** — knockback + physical hit | MoveAwayFromCreature (8yd) |
| Sneed's Shredder | 642 | **Saw Blade** — frontal AoE + knockback | MoveAwayFromCreature (10yd) |
| Sneed | 643 | Spawns on Shredder death — melee only | start/end triggers only |
| Gilnid | 1763 | **Molten Metal** — AoE dot puddle | MoveAwayFromCreature (8yd) |
| Mr. Smite | 646 | **Smite's Slam** stun + weapon switch phases | MoveAwayFromCreature during stun phase |
| Cookie | 645 | **Throw Food** debuffs — no positional | start/end triggers only |
| Edwin VanCleef | 639 | **Enrage** at 50% + **Adds spawn** | Watch for low HP, handle adds |

### Mechanic Detail

**Rhahk'Zor — Rhahk'Zor's Slam:**
- Telegraphed heavy strike with knockback ~5yd
- Bots should stay 8yd back (ranged/healers) to avoid knockback chain

**Sneed's Shredder — Saw Blade:**
- AoE frontal/radial attack, short range ~8yd
- MoveAwayFromCreature (10yd) keeps bots from stacking under shredder
- On shredder death, Sneed (goblin) ejects — separate NPC, simple melee

**Gilnid — Molten Metal:**
- Creates AoE fire puddle at bot's feet
- MoveAwayFromCreature (8yd) prevents bots standing in puddles
- Low-priority boss; many groups skip

**Mr. Smite — Stun + Weapon Switch:**
- Switches weapons twice during fight (at ~66% and ~33% HP)
- Each weapon switch: stuns party for ~3s, then resumes
- On stun break: Smite equips next weapon (dagger → sword → hammer)
- At hammer phase (lowest HP): **Smite's Mighty Blow** = massive knockback 10yd
- MoveAwayFromCreature (12yd) for hammer phase; no movement during earlier phases
- Note: weapon-switch stun is unavoidable — no bot action possible during stun

**Cookie — Throw Food:**
- Applies random food debuffs (slow, stat reduction)
- No positional mechanic — existing cure/dispel strategy handles
- start/end triggers only

**Edwin VanCleef — Enrage + Adds:**
- At ~50% HP: Defias Pirate adds spawn (2x Defias Blackguard, 2x Defias Pirate)
- VanCleef does not enrage in the traditional sense — adds are the real threat
- Bot response: continue DPS on VanCleef, rely on AoE/cleave for adds
- start/end triggers only (add-handling is standard multi-target combat)

---

## Files to Create

```
playerbot/strategy/dungeons/Deadmines/
  Action/
    DmActions.h
  Trigger/
    DmTriggers.h
  Strategy/
    DmStrategy.h
    DmStrategy.cpp
  DM_PLAN.md        ← this file
```

---

## Pre-Code Checklist

- [x] Verify all NPC IDs against classicmangos DB ✅ (2026-04-20)
- [x] Confirm map ID 36 in `instance_template` table ✅

## Pre-Code DB Queries

```sql
SELECT entry, name FROM creature_template 
WHERE name IN ('Rhahk''Zor', 'Sneed''s Shredder', 'Sneed', 'Gilnid',
               'Mr. Smite', 'Cookie', 'Greenskin', 'Edwin VanCleef');

SELECT map FROM instance_template WHERE map = 36;
```

---

## Registration Checklist

- [ ] `playerbot/strategy/generic/DungeonStrategy.cpp` — enter/leave deadmines (combat + noncombat)
- [ ] `playerbot/strategy/triggers/TriggerContext.h` — include `DmTriggers.h` + register all triggers
- [ ] `playerbot/strategy/actions/ActionContext.h` — include `DmActions.h` + register all actions
- [ ] `playerbot/strategy/StrategyContext.h` — include `DmStrategy.h` + register all strategies
- [ ] `CMakeLists.txt` — add `Ai_Dungeon_DM` GLOB_RECURSE + LIBRARY_SRCS entry

---

## Trigger List

| Trigger string | Class | Notes |
|----------------|-------|-------|
| `enter deadmines` | `DeadminesEnterDungeonTrigger` | map 36 |
| `leave deadmines` | `DeadminesLeaveDungeonTrigger` | map 36 |
| `start rhahkzor fight` | `RhahkzorStartFightTrigger` | NPC 644 |
| `end rhahkzor fight` | `RhahkzorEndFightTrigger` | |
| `rhahkzor slam` | `RhahkzorSlamTrigger` | CloseToHostileCreature 8yd |
| `start sneed shredder fight` | `SneedShredderStartFightTrigger` | NPC 642 |
| `end sneed shredder fight` | `SneedShredderEndFightTrigger` | |
| `sneed shredder saw blade` | `SneedShredderSawBladeTrigger` | CloseToHostileCreature 10yd |
| `start sneed fight` | `SneedStartFightTrigger` | NPC 643 |
| `end sneed fight` | `SneedEndFightTrigger` | |
| `start gilnid fight` | `GilnidStartFightTrigger` | NPC 1763 |
| `end gilnid fight` | `GilnidEndFightTrigger` | |
| `gilnid molten metal` | `GilnidMoltenMetalTrigger` | CloseToHostileCreature 8yd |
| `start smite fight` | `SmiteStartFightTrigger` | NPC 646 |
| `end smite fight` | `SmiteEndFightTrigger` | |
| `smite hammer phase` | `SmiteHammerPhaseTrigger` | CloseToHostileCreature 12yd (HP < 33%) |
| `start cookie fight` | `CookieStartFightTrigger` | NPC 645 |
| `end cookie fight` | `CookieEndFightTrigger` | |
| `start vancleef fight` | `VanCleefStartFightTrigger` | NPC 639 |
| `end vancleef fight` | `VanCleefEndFightTrigger` | |

---

## Action List

| Action string | Class |
|---------------|-------|
| `enable deadmines strategy` | `DeadminesEnableStrategyAction` |
| `disable deadmines strategy` | `DeadminesDisableStrategyAction` |
| `enable rhahkzor fight strategy` | `RhahkzorEnableFightStrategyAction` |
| `disable rhahkzor fight strategy` | `RhahkzorDisableFightStrategyAction` |
| `rhahkzor move away from slam` | `RhahkzorMoveAwayFromSlamAction` |
| `enable sneed shredder fight strategy` | `SneedShredderEnableFightStrategyAction` |
| `disable sneed shredder fight strategy` | `SneedShredderDisableFightStrategyAction` |
| `sneed shredder move away from saw blade` | `SneedShredderMoveAwayFromSawBladeAction` |
| `enable sneed fight strategy` | `SneedEnableFightStrategyAction` |
| `disable sneed fight strategy` | `SneedDisableFightStrategyAction` |
| `enable gilnid fight strategy` | `GilnidEnableFightStrategyAction` |
| `disable gilnid fight strategy` | `GilnidDisableFightStrategyAction` |
| `gilnid move away from molten metal` | `GilnidMoveAwayFromMoltenMetalAction` |
| `enable smite fight strategy` | `SmiteEnableFightStrategyAction` |
| `disable smite fight strategy` | `SmiteDisableFightStrategyAction` |
| `smite move away from hammer` | `SmiteMoveAwayFromHammerAction` |
| `enable cookie fight strategy` | `CookieEnableFightStrategyAction` |
| `disable cookie fight strategy` | `CookieDisableFightStrategyAction` |
| `enable vancleef fight strategy` | `VanCleefEnableFightStrategyAction` |
| `disable vancleef fight strategy` | `VanCleefDisableFightStrategyAction` |

---

## Strategy List

| Strategy string | Class |
|-----------------|-------|
| `deadmines` | `DeadminesDungeonStrategy` |
| `rhahkzor` | `RhahkzorFightStrategy` |
| `sneed shredder` | `SneedShredderFightStrategy` |
| `sneed` | `SneedFightStrategy` |
| `gilnid` | `GilnidFightStrategy` |
| `smite` | `SmiteFightStrategy` |
| `cookie` | `CookieFightStrategy` |
| `vancleef` | `VanCleefFightStrategy` |

---

## Implementation Steps

- [x] Step 1: Verify NPC IDs via DB query — update boss table above ✅
- [x] Step 2: Create `DmTriggers.h` — enter/leave + all boss start/end + positional triggers ✅
- [x] Step 3: Create `DmActions.h` — enable/disable + MoveAway actions ✅
- [x] Step 4: Create `DmStrategy.h` — class declarations for all strategies ✅
- [x] Step 5: Create `DmStrategy.cpp` — strategy initializers (InitCombatTriggers, InitNonCombatTriggers, InitDeadTriggers) ✅
- [x] Step 6: Register in `DungeonStrategy.cpp` — enter/leave deadmines triggers ✅
- [x] Step 7: Register in `TriggerContext.h` — include + all trigger creators ✅
- [x] Step 8: Register in `ActionContext.h` — include + all action creators ✅
- [x] Step 9: Register in `StrategyContext.h` — include + all strategy creators ✅
- [x] Step 10: Add CMakeLists.txt entry (`Ai_Dungeon_DM` GLOB_RECURSE) ✅
- [x] Step 11: `./build.sh` — clean with no errors ✅ (237s, 2026-04-20)
- [ ] Step 12: In-game verify — enter DM, check log for `enable deadmines strategy`
- [ ] Step 13: Verify boss fight strategies enable/disable on engage/death
- [ ] Step 14: Verify positional mechanics (MoveAway triggers fire for Smite/VanCleef/Sneed)

---

## Definition of Done

- [ ] `./build.sh` clean
- [ ] Bot enters DM → `enable deadmines strategy` in log
- [ ] Each boss engaged → fight strategy enables
- [ ] Smite → bots retreat >12yd at hammer phase
- [ ] Sneed's Shredder → bots stay >10yd (`sneed shredder move away from saw blade` in log)
- [ ] Each boss dies/resets → fight strategy disables
- [ ] Bot leaves DM → `disable deadmines strategy` in log

---

## Verify Commands

With `LogFileLevel = 3`, grep Server.log for:
```
enable deadmines strategy
enable smite fight strategy
smite move away from hammer
enable vancleef fight strategy
disable vancleef fight strategy
```
