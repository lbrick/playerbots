# Wailing Caverns — Implementation Plan

**Map ID:** 43  
**Levels:** 15–25  
**Status:** 🟡 IN PROGRESS  
**NPC IDs:** from Classic 1.12 data — verify with `SELECT entry, name FROM creature_template WHERE name LIKE '%<boss>%'` before coding

---

## Boss Reference

> ✅ NPC IDs verified against classicmangos `creature_template` (2026-04-20)

| Boss | NPC ID | Key Mechanic | Bot Action Needed |
|------|--------|-------------|------------------|
| Kresh | 3653 | Shell Spin (knockback) — optional | Low priority; start/end triggers only |
| Lady Anacondra | 3671 | **Druid's Slumber** (ID 8040, InterruptFlags=15) — must interrupt | ✅ `DruidSlumberCastingTrigger` → `interrupt enemy cast` (instance-level, covers trash too) |
| Lord Cobrahn | 3669 | Drain Life (channel) — healer handles | start/end triggers only |
| Lord Pythas | 3670 | Entangling Roots (targeted) — no avoidance | start/end triggers only |
| Lord Serpentis | 3673 | Cause Insanity — fear, not positional | start/end triggers only |
| Verdan the Everliving | 5775 | **Grasping Vines** (root nearby ~8yd) | MoveAwayFromCreature (10yd) |
| Mutanus the Devourer | 3654 | **Thundercrack** AoE ~10yd + **Terrify** AoE fear ~10yd | MoveAwayFromCreature (12yd) |

### Mechanic Detail

**Druid's Slumber (spell ID 8040, InterruptFlags=15, PreventionType=1):**
- Cast by Lady Anacondra and multiple trash mobs (Deviate Dreadfang etc.)
- Registered at INSTANCE level (WailingCavernsDungeonStrategy::InitCombatTriggers) — covers all casters, not just Anacondra
- `TargetCastingSpellTrigger` (new reusable base in DungeonTriggers.h) fires when current target is casting spell ID 8040
- `InterruptEnemyCastAction` (new reusable action in DungeonActions.h) tries: kick → pummel → shield bash → counterspell → wind shear → spell lock → hammer of justice → earth shock
- Priority: `ACTION_HIGH + 5` — fires before normal combat actions
- Note: only fires when caster IS the bot's current target; target-selection gap documented as known limitation

**Verdan the Everliving (5775):**
- Grasping Vines roots any bot within ~8 yards
- MoveAwayFromCreature at 10yd prevents bots stacking close and getting rooted
- Mortal Strike / Ensnaring Moss — existing strategies handle

**Mutanus the Devourer (3654):**
- Thundercrack: AoE nature damage + knockback ~10yd around him
- Terrify: AoE fear ~10yd around him (same radius as Thundercrack)
- Both mechanics = same response: stay >10yd from Mutanus
- Single CloseToHostileCreatureHazardTrigger at 12yd covers both

---

## Files to Create

```
playerbot/strategy/dungeons/WailingCaverns/
  Action/
    WcActions.h
  Trigger/
    WcTriggers.h
  Strategy/
    WcStrategy.h
    WcStrategy.cpp
  WC_PLAN.md        ← this file
```

---

## Registration Checklist

- [x] `playerbot/strategy/generic/DungeonStrategy.cpp` — enter/leave wailing caverns (combat + noncombat)
- [x] `playerbot/strategy/triggers/TriggerContext.h` — include + register all triggers
- [x] `playerbot/strategy/actions/ActionContext.h` — include + register all actions
- [x] `playerbot/strategy/StrategyContext.h` — include + register all strategies
- [x] `CMakeLists.txt` — add `Ai_Dungeon_WC` GLOB_RECURSE + LIBRARY_SRCS entry

---

## Trigger List

| Trigger string | Class | Notes |
|----------------|-------|-------|
| `enter wailing caverns` | `WailingCavernsEnterDungeonTrigger` | map 43 |
| `leave wailing caverns` | `WailingCavernsLeaveDungeonTrigger` | map 43 |
| `start kresh fight` | `KreshStartFightTrigger` | NPC 3653 |
| `end kresh fight` | `KreshEndFightTrigger` | |
| `start anacondra fight` | `AnacondraStartFightTrigger` | NPC 3671 |
| `end anacondra fight` | `AnacondraEndFightTrigger` | |
| `start cobrahn fight` | `CobrahnStartFightTrigger` | NPC 3669 |
| `end cobrahn fight` | `CobrahnEndFightTrigger` | |
| `start pythas fight` | `PythasStartFightTrigger` | NPC 3670 |
| `end pythas fight` | `PythasEndFightTrigger` | |
| `start serpentis fight` | `SerpentisStartFightTrigger` | NPC 3673 |
| `end serpentis fight` | `SerpentisEndFightTrigger` | |
| `start verdan fight` | `VerdanStartFightTrigger` | NPC 5775 |
| `end verdan fight` | `VerdanEndFightTrigger` | |
| `verdan grasping vines` | `VerdanGraspingVinesTrigger` | CloseToHostileCreature 10yd |
| `start mutanus fight` | `MutanusStartFightTrigger` | NPC 3654 |
| `end mutanus fight` | `MutanusEndFightTrigger` | |
| `mutanus aoe` | `MutanusAoeTrigger` | CloseToHostileCreature 12yd |

---

## Action List

| Action string | Class |
|---------------|-------|
| `enable wailing caverns strategy` | `WailingCavernsEnableStrategyAction` |
| `disable wailing caverns strategy` | `WailingCavernsDisableStrategyAction` |
| `enable kresh fight strategy` | `KreshEnableFightStrategyAction` |
| `disable kresh fight strategy` | `KreshDisableFightStrategyAction` |
| `enable anacondra fight strategy` | `AnacondraEnableFightStrategyAction` |
| `disable anacondra fight strategy` | `AnacondraDisableFightStrategyAction` |
| `enable cobrahn fight strategy` | `CobrahnEnableFightStrategyAction` |
| `disable cobrahn fight strategy` | `CobrahnDisableFightStrategyAction` |
| `enable pythas fight strategy` | `PythasEnableFightStrategyAction` |
| `disable pythas fight strategy` | `PythasDisableFightStrategyAction` |
| `enable serpentis fight strategy` | `SerpentisEnableFightStrategyAction` |
| `disable serpentis fight strategy` | `SerpentisDisableFightStrategyAction` |
| `enable verdan fight strategy` | `VerdanEnableFightStrategyAction` |
| `disable verdan fight strategy` | `VerdanDisableFightStrategyAction` |
| `verdan move away from grasping vines` | `VerdanMoveAwayFromGraspingVinesAction` |
| `enable mutanus fight strategy` | `MutanusEnableFightStrategyAction` |
| `disable mutanus fight strategy` | `MutanusDisableFightStrategyAction` |
| `mutanus move away from aoe` | `MutanusMoveAwayFromAoeAction` |

---

## Strategy List

| Strategy string | Class |
|-----------------|-------|
| `wailing caverns` | `WailingCavernsDungeonStrategy` |
| `kresh` | `KreshFightStrategy` |
| `anacondra` | `AnacondraFightStrategy` |
| `cobrahn` | `CobrahnFightStrategy` |
| `pythas` | `PythasFightStrategy` |
| `serpentis` | `SerpenatisFightStrategy` |
| `verdan` | `VerdanFightStrategy` |
| `mutanus` | `MutanusFightStrategy` |

---

## Definition of Done

- [x] `./build.sh` clean ✅ (2026-04-20)
- [ ] Bot enters WC → `enable wailing caverns strategy` in log
- [ ] Each boss engaged → fight strategy enables
- [ ] Verdan → bots stay >10yd (check `verdan move away from grasping vines` in log)
- [ ] Mutanus → bots stay >12yd (check `mutanus move away from aoe` in log)
- [ ] Each boss dies/resets → fight strategy disables
- [ ] Bot leaves WC → `disable wailing caverns strategy` in log

---

## Pre-Code Checklist

- [x] Verify all NPC IDs against classicmangos DB ✅
- [ ] Confirm map ID 43 in `instance_template` table

## Pre-Code DB Queries

```sql
SELECT entry, name FROM creature_template 
WHERE name IN ('Kresh','Lady Anacondra','Lord Cobrahn','Lord Pythas',
               'Lord Serpentis','Verdan the Everliving','Mutanus the Devourer');

SELECT map FROM instance_template WHERE map = 43;
```
