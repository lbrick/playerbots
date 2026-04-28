# Stratholme — Implementation Plan

**Map ID:** 329  
**Levels:** 56–60  
**Status:** ⬜ TODO  

> **Two entrances, one map:** Main Gate (Scarlet/Living side) and Service Entrance (Undead/Baron side) both share map 329. One instance strategy covers both sides.
>
> **NPC IDs:** Cross-check every entry with `SELECT entry, name FROM creature_template WHERE name LIKE '%...%'` against classicmangos DB before wiring triggers.

---

## Boss Reference — Scarlet (Living) Side

| Boss | NPC ID | Mechanic | Trigger Type | Action |
|------|--------|----------|--------------|--------|
| Hearthsinger Forresten | 16779 | Song of the Siren (AoE sleep, ~10yd). Rare spawn. Sleep handled by break strategy — no movement trigger. | None — start/end only | — |
| Timmy the Cruel | 10808 | Cleave, Frenzy. Rare spawn. No radial AoE. | None — start/end only | — |
| Cannon Master Willey | 10811 | **Summons Crimson Cannons** that fire AoE blasts (ground-targeted). Primary mechanic: bot must avoid cannon fire zones. Use `CloseToGameObjectHazardTrigger` for cannon projectile GO if ID available; fall back to start/end only. | None — start/end only (cannon GO deferred) | — |
| Archivist Galford | 10812 | **Flame Buffet** (~8yd AoE fire around boss), summons Burning Servants (fire elemental adds) | `CloseToHostileCreatureHazardTrigger(10812, 8, 3)` | `MoveAwayFromCreature(10812, 10)` |
| Balnazzar | 10813 | **Psychic Scream** (AoE fear ~15yd), Dominate Mind (mind control), Thunderclap (~8yd AoE). Fear handled by break strategy. Thunderclap = movement. | `CloseToHostileCreatureHazardTrigger(10813, 8, 3)` | `MoveAwayFromCreature(10813, 10)` |

---

## Boss Reference — Undead (Baron) Side

| Boss | NPC ID | Mechanic | Trigger Type | Action |
|------|--------|----------|--------------|--------|
| Magistrate Barthilas | 10435 | Hammer of Justice (single-target stun), Shadow Bolt. No radial AoE. | None — start/end only | — |
| Maleki the Pallid | 10438 | Drain Life, Frost Nova (~8yd). Frost Nova = move away. | `CloseToHostileCreatureHazardTrigger(10438, 8, 3)` | `MoveAwayFromCreature(10438, 10)` |
| Ramstein the Gorger | 10439 | **Trample** (~8yd AoE physical), Uppercut (single-target knockback) | `CloseToHostileCreatureHazardTrigger(10439, 8, 3)` | `MoveAwayFromCreature(10439, 10)` |
| Baron Rivendare | 10440 | **Unholy Aura** (AoE shadow damage ~10yd persistent aura around boss), Cleave, Mortal Strike | `CloseToHostileCreatureHazardTrigger(10440, 10, 3)` | `MoveAwayFromCreature(10440, 12)` |

> **Cannon Master Willey cannons:** The cannon fire is ground-targeted AoE projectiles. If the cannon Game Object IDs are available in the DB, a `CloseToGameObjectHazardTrigger` can be added. Deferred for initial implementation — register start/end only for Willey.
>
> **Balnazzar form:** Balnazzar is disguised as Aurius Rivendare until the fight starts. The combat NPC ID (10813) is the relevant one — verify in DB.
>
> **Baron Rivendare Unholy Aura:** Persistent aura that deals shadow damage to all players within ~10yd continuously. This is the primary mechanic that punishes melee bots standing in range. The trigger/action fires repeatedly to push bots out.
>
> **Service Entrance timer:** Starting the undead side triggers a 45-minute timer. No bot mechanic needed — standard kill speed handles it.

---

## Files to Create

```
playerbot/strategy/dungeons/Stratholme/
  Action/
    StratActions.h     — instance + all boss enable/disable + AoE MoveAway actions
  Trigger/
    StratTriggers.h    — instance enter/leave + all boss start/end + hazard triggers
  Strategy/
    StratStrategy.h    — class declarations
    StratStrategy.cpp  — all strategy initializers
  STRAT_PLAN.md        — this file
```

---

## Strategy String Names

| Thing | String |
|-------|--------|
| Instance strategy | `"stratholme"` |
| Enter trigger | `"enter stratholme"` |
| Leave trigger | `"leave stratholme"` |
| Scarlet side | `"hearthsinger forresten"`, `"timmy the cruel"`, `"cannon master willey"`, `"archivist galford"`, `"balnazzar"` |
| Undead side | `"magistrate barthilas"`, `"maleki the pallid"`, `"ramstein the gorger"`, `"baron rivendare"` |
| Key AoE triggers | `"galford flame buffet"`, `"balnazzar thunderclap"`, `"maleki frost nova"`, `"ramstein trample"`, `"baron unholy aura"` |

---

## Registration Checklist

- [ ] `playerbot/strategy/generic/DungeonStrategy.cpp` — enter/leave stratholme (combat + noncombat)
- [ ] `playerbot/strategy/triggers/TriggerContext.h` — include StratTriggers.h + all Strat creators
- [ ] `playerbot/strategy/actions/ActionContext.h` — include StratActions.h + all Strat creators
- [ ] `playerbot/strategy/StrategyContext.h` — include StratStrategy.h + all strategy creators
- [ ] `CMakeLists.txt` — `Ai_Dungeon_Strat` GLOB_RECURSE added + included in LIBRARY_SRCS

---

## Build Status

- [ ] `./build.sh` — clean, no new errors

---

## Definition of Done

- [ ] Build clean
- [ ] Bot enters Stratholme (either entrance) → `stratholme` instance strategy loads
- [ ] Archivist Galford engaged → bots move >10yd during Flame Buffet
- [ ] Baron Rivendare engaged → bots move >12yd during Unholy Aura
- [ ] Ramstein engaged → bots move >10yd during Trample
- [ ] Each boss dies → fight strategy disables
- [ ] Bot leaves Stratholme → instance strategy unloads

---

## Verify Commands

```
enable stratholme strategy
enable archivist galford fight strategy
galford flame buffet
galford move away from flame buffet
enable baron rivendare fight strategy
baron unholy aura
baron move away from unholy aura
disable stratholme strategy
```

---

## Spell Reference

| Spell | ID | Radius | Notes |
|-------|----|--------|-------|
| Flame Buffet (Galford) | — | ~8yd | Verify ID in spell_template |
| Thunderclap (Balnazzar) | 15548 | ~8yd | Verify ID |
| Frost Nova (Maleki) | 865 | ~8yd | Verify ID |
| Trample (Ramstein) | 15550 | ~8yd | Verify ID |
| Unholy Aura (Rivendare) | 17228 | ~10yd | Verify ID — persistent aura, not a cast |

---

## Next Step

1. Verify all NPC IDs in DB (especially Balnazzar's combat form ID)
2. `StratTriggers.h`
3. `StratActions.h`
4. `StratStrategy.h` + `StratStrategy.cpp`
5. Four registration edits
6. `CMakeLists.txt`
7. `./build.sh` verify
