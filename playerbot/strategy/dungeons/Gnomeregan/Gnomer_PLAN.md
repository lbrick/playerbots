# Gnomeregan — Implementation Plan

**Map ID:** 90  
**Levels:** 29–38  
**Status:** ⬜ TODO  
**NPC IDs:** ✅ Verified against classicmangos `creature_template` (2026-04-27)

---

## Resume Protocol

At session start: scan for first `[ ]` — that is the resume point. Mark `[x]` as each step is confirmed done.

---

## Boss Reference

> ⚠️ NPC IDs from Wowhead — verify against classicmangos `creature_template` before coding

| Boss | NPC ID | Key Mechanic | Bot Action Needed |
|------|--------|-------------|------------------|
| Grubbis | 7361 | **Grubbis charges** — simple melee; Chomper (pet) is the real threat | start/end triggers only |
| Viscous Fallout | 7079 | **Acid Splash** — targeted AoE spit ~8yd; **Corrosive Aura** — passive DoT | MoveAwayFromCreature (10yd) |
| Electrocutioner 6000 | 6235 | **Lightning Arc** — frontal AoE chain ~10yd; **Megavolt** — AoE stun | MoveAwayFromCreature (12yd) |
| Crowd Pummeler 9-60 | 6229 | **Arcing Smash** — frontal AoE ~8yd; **Trample** — knockback | MoveAwayFromCreature (10yd) |
| Mekgineer Thermaplugg | 7800 | **Activate Bombs** — Leper Gnome bombs run to players and explode (~8yd radius); **Sapper Charge** — targeted explosion | MoveAwayFromCreature (10yd); spread to isolate bombs |

### Mechanic Detail

**Grubbis — Chomper:**
- Grubbis himself is unremarkable melee
- Chomper (Gnomeregan Chomper, NPC ~7361-range) spawns with Grubbis as his "pet"
- Both share combat — treat as single encounter with dual NPC
- No positional mechanic that requires bot movement
- start/end triggers only (wire on Grubbis NPC ID — Chomper dies when Grubbis dies)

**Viscous Fallout — Acid Splash / Corrosive Aura:**
- Acid Splash: targeted AoE puddle at a player's location, ~8yd radius, nature damage
- Bots must move off splash landing zones — MoveAwayFromCreature (10yd) prevents standing in puddles
- Corrosive Aura: passive nature damage aura in melee range — same trigger keeps bots at range
- Ranged/healer bots stay >10yd; tank ignored (unavoidable)

**Electrocutioner 6000 — Lightning Arc / Megavolt:**
- Lightning Arc: frontal chain lightning ~10yd, jumps to nearby targets
- Bots must spread — MoveAwayFromCreature (12yd) breaks chain jump
- Megavolt: AoE stun affecting all nearby players ~12yd — unavoidable if bots are close
- Same spread trigger (12yd) also reduces Megavolt coverage
- Note: Electrocutioner drops the Electrocutioner Leg — not relevant to strategy

**Crowd Pummeler 9-60 — Arcing Smash / Trample:**
- Arcing Smash: wide frontal AoE cone ~8yd — melee range threat
- Trample: knockback, short range, affects bots standing in melee
- MoveAwayFromCreature (10yd) keeps non-tanks out of cone + trample range
- Tank is expected to take both — no action possible for tank

**Mekgineer Thermaplugg — Bombs / Sapper Charge:**
- Key mechanic: periodically activates a Leper Gnome Sapper who runs toward a random player
- Sapper explodes on reach for ~1500 fire damage in ~8yd radius
- Bot response: MoveAwayFromCreature on Thermaplugg (10yd) to avoid bomb clusters near boss
- Sapper Charge: targeted fire explosion on random player — existing spread posture reduces splash
- Note: Thermaplugg activates bomb machines around the room — focus fire on Thermaplugg, not machines
- start/end triggers handle the fight; positional trigger on Thermaplugg keeps bots spread

---

## Files to Create

```
playerbot/strategy/dungeons/Gnomeregan/
  Action/
    GnomerActions.h
  Trigger/
    GnomerTriggers.h
  Strategy/
    GnomerStrategy.h
    GnomerStrategy.cpp
  Gnomer_PLAN.md        ← this file
```

---

## Pre-Code DB Queries

```sql
-- Verify NPC IDs
SELECT entry, name FROM creature_template 
WHERE name IN ('Grubbis', 'Viscous Fallout', 'Electrocutioner 6000',
               'Crowd Pummeler 9-60', 'Mekgineer Thermaplugg');

-- Verify map ID
SELECT map FROM instance_template WHERE map = 90;

-- Chomper NPC ID (Grubbis pet)
SELECT entry, name FROM creature_template WHERE name LIKE '%Chomper%';

-- Leper Gnome Sapper (Thermaplugg bomb mechanic)
SELECT entry, name FROM creature_template WHERE name LIKE '%Sapper%' AND name LIKE '%Leper%';
```

---

## Pre-Code Checklist

- [ ] Verify all NPC IDs against classicmangos DB
- [ ] Confirm map ID 90 in `instance_template` table
- [ ] Confirm Chomper NPC ID (wire on Grubbis ID or Chomper ID — whichever is cleaner)
- [ ] Check if Leper Gnome Sapper has its own NPC entry for trigger purposes

---

## Registration Checklist

- [ ] `playerbot/strategy/generic/DungeonStrategy.cpp` — enter/leave gnomeregan (combat + noncombat)
- [ ] `playerbot/strategy/triggers/TriggerContext.h` — include `GnomerTriggers.h` + register all triggers
- [ ] `playerbot/strategy/actions/ActionContext.h` — include `GnomerActions.h` + register all actions
- [ ] `playerbot/strategy/StrategyContext.h` — include `GnomerStrategy.h` + register all strategies
- [ ] `CMakeLists.txt` — add `Ai_Dungeon_Gnomer` GLOB_RECURSE + LIBRARY_SRCS entry

---

## Trigger List

| Trigger string | Class | Notes |
|----------------|-------|-------|
| `enter gnomeregan` | `GnomereganEnterDungeonTrigger` | map 90 |
| `leave gnomeregan` | `GnomereganLeaveDungeonTrigger` | map 90 |
| `start grubbis fight` | `GrubbisStartFightTrigger` | NPC 7361 |
| `end grubbis fight` | `GrubbisEndFightTrigger` | |
| `start viscous fallout fight` | `ViscousFalloutStartFightTrigger` | NPC 7079 |
| `end viscous fallout fight` | `ViscousFalloutEndFightTrigger` | |
| `viscous fallout acid splash` | `ViscousFalloutAcidSplashTrigger` | CloseToHostileCreature 10yd |
| `start electrocutioner fight` | `ElectrocutionerStartFightTrigger` | NPC 6235 |
| `end electrocutioner fight` | `ElectrocutionerEndFightTrigger` | |
| `electrocutioner lightning arc` | `ElectrocutionerLightningArcTrigger` | CloseToHostileCreature 12yd |
| `start crowd pummeler fight` | `CrowdPummelerStartFightTrigger` | NPC 6229 |
| `end crowd pummeler fight` | `CrowdPummelerEndFightTrigger` | |
| `crowd pummeler arcing smash` | `CrowdPummelerArcingSmashTrigger` | CloseToHostileCreature 10yd |
| `start thermaplugg fight` | `ThermapluggStartFightTrigger` | NPC 7800 |
| `end thermaplugg fight` | `ThermapluggEndFightTrigger` | |
| `thermaplugg bomb spread` | `ThermapluggBombSpreadTrigger` | CloseToHostileCreature 10yd |

---

## Action List

| Action string | Class |
|---------------|-------|
| `enable gnomeregan strategy` | `GnomereganEnableStrategyAction` |
| `disable gnomeregan strategy` | `GnomereganDisableStrategyAction` |
| `enable grubbis fight strategy` | `GrubbisEnableFightStrategyAction` |
| `disable grubbis fight strategy` | `GrubbisDisableFightStrategyAction` |
| `enable viscous fallout fight strategy` | `ViscousFalloutEnableFightStrategyAction` |
| `disable viscous fallout fight strategy` | `ViscousFalloutDisableFightStrategyAction` |
| `viscous fallout move away from acid splash` | `ViscousFalloutMoveAwayFromAcidSplashAction` |
| `enable electrocutioner fight strategy` | `ElectrocutionerEnableFightStrategyAction` |
| `disable electrocutioner fight strategy` | `ElectrocutionerDisableFightStrategyAction` |
| `electrocutioner move away from lightning arc` | `ElectrocutionerMoveAwayFromLightningArcAction` |
| `enable crowd pummeler fight strategy` | `CrowdPummelerEnableFightStrategyAction` |
| `disable crowd pummeler fight strategy` | `CrowdPummelerDisableFightStrategyAction` |
| `crowd pummeler move away from arcing smash` | `CrowdPummelerMoveAwayFromArcingSmashAction` |
| `enable thermaplugg fight strategy` | `ThermapluggEnableFightStrategyAction` |
| `disable thermaplugg fight strategy` | `ThermapluggDisableFightStrategyAction` |
| `thermaplugg move away from bombs` | `ThermapluggMoveAwayFromBombsAction` |

---

## Strategy List

| Strategy string | Class |
|-----------------|-------|
| `gnomeregan` | `GnomereganDungeonStrategy` |
| `grubbis` | `GrubbisFightStrategy` |
| `viscous fallout` | `ViscousFalloutFightStrategy` |
| `electrocutioner` | `ElectrocutionerFightStrategy` |
| `crowd pummeler` | `CrowdPummelerFightStrategy` |
| `thermaplugg` | `ThermapluggFightStrategy` |

---

## Implementation Steps

- [ ] Step 1: Verify NPC IDs via DB query — update boss table above
- [ ] Step 2: Create `GnomerTriggers.h` — enter/leave + all boss start/end + positional triggers
- [ ] Step 3: Create `GnomerActions.h` — enable/disable + MoveAway actions
- [ ] Step 4: Create `GnomerStrategy.h` — class declarations for all strategies
- [ ] Step 5: Create `GnomerStrategy.cpp` — strategy initializers (InitCombatTriggers, InitNonCombatTriggers, InitDeadTriggers)
- [ ] Step 6: Register in `DungeonStrategy.cpp` — enter/leave gnomeregan triggers
- [ ] Step 7: Register in `TriggerContext.h` — include + all trigger creators
- [ ] Step 8: Register in `ActionContext.h` — include + all action creators
- [ ] Step 9: Register in `StrategyContext.h` — include + all strategy creators
- [ ] Step 10: Add CMakeLists.txt entry (`Ai_Dungeon_Gnomer` GLOB_RECURSE)
- [ ] Step 11: `./build.sh` — clean with no errors
- [ ] Step 12: In-game verify — enter Gnomeregan, check log for `enable gnomeregan strategy`
- [ ] Step 13: Verify boss fight strategies enable/disable on engage/death
- [ ] Step 14: Verify spread mechanic fires for Electrocutioner and Thermaplugg
- [ ] Step 15: Verify Viscous Fallout bots stay >10yd

---

## Definition of Done

- [ ] `./build.sh` clean
- [ ] Bot enters Gnomeregan → `enable gnomeregan strategy` in log
- [ ] Each boss engaged → fight strategy enables
- [ ] Viscous Fallout → bots stay >10yd (`viscous fallout move away from acid splash` in log)
- [ ] Electrocutioner → bots spread >12yd (`electrocutioner move away from lightning arc` in log)
- [ ] Crowd Pummeler → bots stay >10yd (`crowd pummeler move away from arcing smash` in log)
- [ ] Thermaplugg → bots spread >10yd (`thermaplugg move away from bombs` in log)
- [ ] Each boss dies/resets → fight strategy disables
- [ ] Bot leaves Gnomeregan → `disable gnomeregan strategy` in log

---

## Verify Commands

With `LogFileLevel = 3`, grep Server.log for:
```
enable gnomeregan strategy
enable viscous fallout fight strategy
viscous fallout move away from acid splash
enable electrocutioner fight strategy
electrocutioner move away from lightning arc
enable thermaplugg fight strategy
thermaplugg move away from bombs
disable gnomeregan strategy
```

---

## Notes

- **Radiation debuff** (Radioactive Fallout) is applied throughout the instance by Irradiated trash — not a boss mechanic, existing dispel/cure strategies handle.
- **Thermaplugg bomb machines** around the room activate periodically — bot should NOT attack machines, focus Thermaplugg. No explicit action needed; bots default to highest threat target.
- **Electrocutioner 6000** may drop the Electrocutioner Leg (BiS warrior item in early Classic) — no strategic relevance.
- If Grubbis NPC ID is wrong in classicmangos (some builds use different entry), check `WHERE name LIKE '%Grubbis%'`.
