# The Stockade — Implementation Plan

**Map ID:** 34  
**Levels:** 24–32  
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
| Targorr the Dread | 1696 | **Slam** — heavy physical hit, minor knockback | MoveAwayFromCreature (8yd) |
| Kam Deepfury | 1666 | **Earthbolt** — high nature bolt; **Earth Shock** — interrupt | start/end triggers only (spell damage, no positional) |
| Hamhock | 1717 | **Chain Lightning** — AoE arc ~10yd, jumps targets | MoveAwayFromCreature (12yd) to break chain |
| Bazil Thredd | 1716 | **Backstab** — targets cloth wearers; **Sprint** — repositions | start/end triggers only |
| Dextren Ward | 1663 | **Intimidating Shout** — AoE fear 10yd radius | MoveAwayFromCreature (12yd) |

### Mechanic Detail

**Targorr the Dread — Slam:**
- Melee swing with knockback ~3yd and bonus physical damage
- Bots within ~6yd risk knockback into patrol paths
- MoveAwayFromCreature (8yd) keeps non-tanks at safe range

**Kam Deepfury — Earthbolt / Earth Shock:**
- Earthbolt: targeted nature bolt, high single-target damage
- Earth Shock: nature damage + interrupt — existing interrupt strategy handles
- No positional mechanic — cure/dispel + interrupt strategies sufficient
- start/end triggers only

**Hamhock — Chain Lightning:**
- Jumps between targets within ~10yd of each other
- Bots must spread to break chain — MoveAwayFromCreature (12yd) prevents chain bouncing
- Bloodlust (self-buff): increases attack speed, no bot positional response possible

**Bazil Thredd — Backstab / Sprint:**
- Backstab targets cloth wearers from behind — existing threat/positioning handles
- Sprint: briefly resets position, targets a new player
- No reliable positional response possible — start/end triggers only

**Dextren Ward — Intimidating Shout:**
- AoE fear in ~10yd radius, affects all nearby players
- Feared bots run into surrounding trash packs → wipes
- MoveAwayFromCreature (12yd) ensures bots are outside fear range during fight
- Note: fear itself is unavoidable if bot is caught close; objective is pre-positioning

---

## Files to Create

```
playerbot/strategy/dungeons/Stockade/
  Action/
    StocksActions.h
  Trigger/
    StocksTriggers.h
  Strategy/
    StocksStrategy.h
    StocksStrategy.cpp
  Stocks_PLAN.md        ← this file
```

---

## Pre-Code DB Queries

```sql
-- Verify NPC IDs
SELECT entry, name FROM creature_template 
WHERE name IN ('Targorr the Dread', 'Kam Deepfury', 'Hamhock',
               'Bazil Thredd', 'Dextren Ward');

-- Verify map ID
SELECT map FROM instance_template WHERE map = 34;
```

---

## Pre-Code Checklist

- [ ] Verify all NPC IDs against classicmangos DB
- [ ] Confirm map ID 34 in `instance_template` table

---

## Registration Checklist

- [ ] `playerbot/strategy/generic/DungeonStrategy.cpp` — enter/leave stockade (combat + noncombat)
- [ ] `playerbot/strategy/triggers/TriggerContext.h` — include `StocksTriggers.h` + register all triggers
- [ ] `playerbot/strategy/actions/ActionContext.h` — include `StocksActions.h` + register all actions
- [ ] `playerbot/strategy/StrategyContext.h` — include `StocksStrategy.h` + register all strategies
- [ ] `CMakeLists.txt` — add `Ai_Dungeon_Stocks` GLOB_RECURSE + LIBRARY_SRCS entry

---

## Trigger List

| Trigger string | Class | Notes |
|----------------|-------|-------|
| `enter stockade` | `StocksEnterDungeonTrigger` | map 34 |
| `leave stockade` | `StocksLeaveDungeonTrigger` | map 34 |
| `start targorr fight` | `TargorrStartFightTrigger` | NPC 1696 |
| `end targorr fight` | `TargorrEndFightTrigger` | |
| `targorr slam` | `TargorrSlamTrigger` | CloseToHostileCreature 8yd |
| `start kam deepfury fight` | `KamDeepfuryStartFightTrigger` | NPC 1695 |
| `end kam deepfury fight` | `KamDeepfuryEndFightTrigger` | |
| `start hamhock fight` | `HamhockStartFightTrigger` | NPC 1717 |
| `end hamhock fight` | `HamhockEndFightTrigger` | |
| `hamhock chain lightning` | `HamhockChainLightningTrigger` | CloseToHostileCreature 12yd |
| `start bazil thredd fight` | `BazilThreddStartFightTrigger` | NPC 1716 |
| `end bazil thredd fight` | `BazilThreddEndFightTrigger` | |
| `start dextren ward fight` | `DextrenWardStartFightTrigger` | NPC 1718 |
| `end dextren ward fight` | `DextrenWardEndFightTrigger` | |
| `dextren ward intimidating shout` | `DextrenWardIntimidatingShoutTrigger` | CloseToHostileCreature 12yd |

---

## Action List

| Action string | Class |
|---------------|-------|
| `enable stockade strategy` | `StocksEnableStrategyAction` |
| `disable stockade strategy` | `StocksDisableStrategyAction` |
| `enable targorr fight strategy` | `TargorrEnableFightStrategyAction` |
| `disable targorr fight strategy` | `TargorrDisableFightStrategyAction` |
| `targorr move away from slam` | `TargorrMoveAwayFromSlamAction` |
| `enable kam deepfury fight strategy` | `KamDeepfuryEnableFightStrategyAction` |
| `disable kam deepfury fight strategy` | `KamDeepfuryDisableFightStrategyAction` |
| `enable hamhock fight strategy` | `HamhockEnableFightStrategyAction` |
| `disable hamhock fight strategy` | `HamhockDisableFightStrategyAction` |
| `hamhock move away from chain lightning` | `HamhockMoveAwayFromChainLightningAction` |
| `enable bazil thredd fight strategy` | `BazilThreddEnableFightStrategyAction` |
| `disable bazil thredd fight strategy` | `BazilThreddDisableFightStrategyAction` |
| `enable dextren ward fight strategy` | `DextrenWardEnableFightStrategyAction` |
| `disable dextren ward fight strategy` | `DextrenWardDisableFightStrategyAction` |
| `dextren ward move away from intimidating shout` | `DextrenWardMoveAwayFromIntimidatingShoutAction` |

---

## Strategy List

| Strategy string | Class |
|-----------------|-------|
| `stockade` | `StocksDungeonStrategy` |
| `targorr` | `TargorrFightStrategy` |
| `kam deepfury` | `KamDeepfuryFightStrategy` |
| `hamhock` | `HamhockFightStrategy` |
| `bazil thredd` | `BazilThreddFightStrategy` |
| `dextren ward` | `DextrenWardFightStrategy` |

---

## Implementation Steps

- [ ] Step 1: Verify NPC IDs via DB query — update boss table above
- [ ] Step 2: Create `StocksTriggers.h` — enter/leave + all boss start/end + positional triggers
- [ ] Step 3: Create `StocksActions.h` — enable/disable + MoveAway actions
- [ ] Step 4: Create `StocksStrategy.h` — class declarations for all strategies
- [ ] Step 5: Create `StocksStrategy.cpp` — strategy initializers (InitCombatTriggers, InitNonCombatTriggers, InitDeadTriggers)
- [ ] Step 6: Register in `DungeonStrategy.cpp` — enter/leave stockade triggers
- [ ] Step 7: Register in `TriggerContext.h` — include + all trigger creators
- [ ] Step 8: Register in `ActionContext.h` — include + all action creators
- [ ] Step 9: Register in `StrategyContext.h` — include + all strategy creators
- [ ] Step 10: Add CMakeLists.txt entry (`Ai_Dungeon_Stocks` GLOB_RECURSE)
- [ ] Step 11: `./build.sh` — clean with no errors
- [ ] Step 12: In-game verify — enter Stockade, check log for `enable stockade strategy`
- [ ] Step 13: Verify boss fight strategies enable/disable on engage/death
- [ ] Step 14: Verify Hamhock spread (bots >12yd apart during chain lightning)
- [ ] Step 15: Verify Dextren Ward pre-positioning (bots >12yd before Intimidating Shout)

---

## Definition of Done

- [ ] `./build.sh` clean
- [ ] Bot enters Stockade → `enable stockade strategy` in log
- [ ] Each boss engaged → fight strategy enables
- [ ] Hamhock → bots spread >12yd (`hamhock move away from chain lightning` in log)
- [ ] Dextren Ward → bots stay >12yd before fight (`dextren ward move away from intimidating shout` in log)
- [ ] Each boss dies/resets → fight strategy disables
- [ ] Bot leaves Stockade → `disable stockade strategy` in log

---

## Verify Commands

With `LogFileLevel = 3`, grep Server.log for:
```
enable stockade strategy
enable hamhock fight strategy
hamhock move away from chain lightning
enable dextren ward fight strategy
dextren ward move away from intimidating shout
disable stockade strategy
```
