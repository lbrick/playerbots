# Uldaman — Implementation Plan

**Map ID:** 70  
**Levels:** 35–45  
**Status:** ⬜ TODO  

> **NPC IDs:** Cross-check every entry with `SELECT entry, name FROM creature_template WHERE name LIKE '%...%'` against classicmangos DB before wiring triggers.

---

## Boss Reference

| Boss | NPC ID | Mechanic | Trigger Type | Action |
|------|--------|----------|--------------|--------|
| Revelosh | 6910 | Lightning Bolt, Chain Lightning. No positional AoE. | None — start/end only | — |
| Baelog (Lost Dwarves event) | 6913 | Melee only. Event trio — Olaf (6912), Eric the Swift (6911). No AoE positional. | None — start/end only | — |
| Ironaya | 7228 | **War Stomp** (spell 11876) — ~8yd AoE physical around boss; Arcing Smash (frontal cleave) | `CloseToHostileCreatureHazardTrigger(7228, 8, 3)` | `MoveAwayFromCreature(7228, 10)` |
| Obsidian Sentinel | 7023 | Stone Tremor (AoE periodic). Immune to fire. No directional mechanic. | None — start/end only | — |
| Ancient Stone Keeper | 4857 | War Stomp (~8yd AoE), Trample. Verify NPC ID in DB. | `CloseToHostileCreatureHazardTrigger(4857, 8, 3)` | `MoveAwayFromCreature(4857, 10)` |
| Galgann Firehammer | 7291 | **Fire Nova** (~10yd AoE fire around boss), Flame Shock | `CloseToHostileCreatureHazardTrigger(7291, 10, 3)` | `MoveAwayFromCreature(7291, 12)` |
| Grimlok | 4854 | **War Stomp** (~8yd AoE), Shock, Chain Lightning (no positional) | `CloseToHostileCreatureHazardTrigger(4854, 8, 3)` | `MoveAwayFromCreature(4854, 10)` |
| Archaedas | 2748 | **Earth Tremor** (~15yd AoE physical around boss), spawns Vault Wardens from statues as HP drops | `CloseToHostileCreatureHazardTrigger(2748, 15, 3)` | `MoveAwayFromCreature(2748, 17)` |

> **Lost Dwarves trio:** Olaf, Eric the Swift, Baelog are pulled together as a group. Register all three NPC IDs under the same fight strategy for consistency. Use Baelog (6913) as the canonical start/end trigger since he's the named entry.
>
> **Archaedas Vault Wardens:** Stone Keeper adds spawn from statues as Archaedas loses HP (at ~66%, 33%). Existing kill-nearest logic handles them. No extra bot mechanic needed.
>
> **Ironaya Arcing Smash:** True frontal cone detection requires a custom trigger (not yet in base classes). For now, War Stomp AoE is sufficient — mark Arcing Smash as a future enhancement.

---

## Files to Create

```
playerbot/strategy/dungeons/Uldaman/
  Action/
    UldaActions.h      — instance + 8 boss enable/disable + Ironaya/AncientStoneKeeper/Galgann/Grimlok/Archaedas MoveAway
  Trigger/
    UldaTriggers.h     — instance enter/leave + 8 boss start/end + AoE hazard triggers
  Strategy/
    UldaStrategy.h     — class declarations
    UldaStrategy.cpp   — all strategy initializers
  ULDA_PLAN.md         — this file
```

---

## Strategy String Names

| Thing | String |
|-------|--------|
| Instance strategy | `"uldaman"` |
| Enter trigger | `"enter uldaman"` |
| Leave trigger | `"leave uldaman"` |
| Revelosh fight | `"revelosh"` |
| Baelog fight (Lost Dwarves) | `"baelog"` |
| Ironaya fight | `"ironaya"` |
| Obsidian Sentinel fight | `"obsidian sentinel"` |
| Ancient Stone Keeper fight | `"ancient stone keeper"` |
| Galgann fight | `"galgann firehammer"` |
| Grimlok fight | `"grimlok"` |
| Archaedas fight | `"archaedas"` |
| Ironaya War Stomp trigger | `"ironaya war stomp"` |
| Ancient Stone Keeper War Stomp trigger | `"ancient stone keeper war stomp"` |
| Galgann Fire Nova trigger | `"galgann fire nova"` |
| Grimlok War Stomp trigger | `"grimlok war stomp"` |
| Archaedas Earth Tremor trigger | `"archaedas earth tremor"` |

---

## Registration Checklist

- [ ] `playerbot/strategy/generic/DungeonStrategy.cpp` — enter/leave uldaman (combat + noncombat)
- [ ] `playerbot/strategy/triggers/TriggerContext.h` — include UldaTriggers.h + all RFD creators
- [ ] `playerbot/strategy/actions/ActionContext.h` — include UldaActions.h + all creators
- [ ] `playerbot/strategy/StrategyContext.h` — include UldaStrategy.h + 9 strategy creators
- [ ] `CMakeLists.txt` — `Ai_Dungeon_Ulda` GLOB_RECURSE added + included in LIBRARY_SRCS

---

## Build Status

- [ ] `./build.sh` — clean, no new errors

---

## Definition of Done

- [ ] Build clean
- [ ] Bot enters Uldaman → instance strategy loads (log: `enable uldaman strategy`)
- [ ] Revelosh engaged → revelosh fight strategy enables
- [ ] Baelog (Lost Dwarves) engaged → baelog fight strategy enables
- [ ] Ironaya engaged → ironaya fight strategy enables; bots move >10yd during War Stomp
- [ ] Obsidian Sentinel engaged → obsidian sentinel fight strategy enables
- [ ] Ancient Stone Keeper engaged → fight strategy enables; bots move >10yd during War Stomp
- [ ] Galgann Firehammer engaged → fight strategy enables; bots move >12yd during Fire Nova
- [ ] Grimlok engaged → grimlok fight strategy enables; bots move >10yd during War Stomp
- [ ] Archaedas engaged → archaedas fight strategy enables; bots move >17yd during Earth Tremor
- [ ] Each boss dies → fight strategy disables
- [ ] Bot leaves Uldaman → instance strategy unloads (log: `disable uldaman strategy`)

---

## Verify Commands

With `LogFileLevel = 3`, grep Server.log for:
```
enable uldaman strategy
enable ironaya fight strategy
ironaya war stomp
ironaya move away from war stomp
enable galgann firehammer fight strategy
galgann fire nova
galgann move away from fire nova
enable archaedas fight strategy
archaedas earth tremor
archaedas move away from earth tremor
disable uldaman strategy
```

---

## Spell Reference

| Spell | ID | Radius | Notes |
|-------|----|--------|-------|
| War Stomp (Ironaya) | 11876 | ~8yd | Verify ID |
| War Stomp (Ancient Stone Keeper) | 11876 | ~8yd | Same spell likely — verify |
| War Stomp (Grimlok) | 11876 | ~8yd | Same spell likely — verify |
| Fire Nova (Galgann) | 11831 | ~10yd | Verify ID |
| Earth Tremor (Archaedas) | 6524 | ~15yd | Verify ID |

---

## Next Step

Implement in order:

1. `UldaTriggers.h`
2. `UldaActions.h`
3. `UldaStrategy.h` + `UldaStrategy.cpp`
4. Four registration edits (DungeonStrategy.cpp, TriggerContext.h, ActionContext.h, StrategyContext.h)
5. `CMakeLists.txt`
6. `./build.sh` verify
