# Razorfen Downs — Implementation Plan

**Map ID:** 129  
**Levels:** 35–50  
**Status:** 🟢 IMPLEMENTED — build verified 2026-05-02  

> **NPC IDs:** Cross-check every entry with `SELECT entry, name FROM creature_template WHERE name LIKE '%...%'` against classicmangos DB before wiring triggers.

---

## Boss Reference

| Boss | NPC ID | Mechanic | Trigger Type | Action |
|------|--------|----------|--------------|--------|
| Tuten'kash | 7355 | Summons adds (spiders) at 66%/33% HP; Web Explosion (single target). No AoE positional mechanic. | None — start/end only | — |
| Mordresh Fire Eye | 7357 | **Fire Nova** (spell 11831) — ~10yd AoE fire around boss | `CloseToHostileCreatureHazardTrigger(7357, 10, 3)` | `MoveAwayFromCreature(7357, 12)` |
| Glutton | 7354 | Devour (eats nearby zombies to self-heal), Retching Blow (single target). No AoE positional mechanic. | None — start/end only | — |
| Amnennar the Coldbringer | 7358 | **Frost Nova** (spell 11831 variant) — ~8yd AoE freeze around boss; Frost Bolt Volley (AoE ranged) | `CloseToHostileCreatureHazardTrigger(7358, 8, 3)` | `MoveAwayFromCreature(7358, 10)` |

> **Frost Bolt Volley:** Ranged AoE handled by healing strategy automatically. Only Frost Nova (melee-range freeze) requires bot movement.
>
> **Mordresh adds:** Mordresh enters via a skeleton mob event. Existing kill-nearest logic handles the adds. No bot mechanic needed.

---

## Files to Create

```
playerbot/strategy/dungeons/RazorfenDowns/
  Action/
    RfdActions.h       — instance + 4 boss enable/disable + Mordresh/Amnennar MoveAway
  Trigger/
    RfdTriggers.h      — instance enter/leave + 4 boss start/end + Mordresh Fire Nova + Amnennar Frost Nova
  Strategy/
    RfdStrategy.h      — class declarations
    RfdStrategy.cpp    — all strategy initializers
  RFD_PLAN.md          — this file
```

---

## Strategy String Names

| Thing | String |
|-------|--------|
| Instance strategy | `"razorfen downs"` |
| Enter trigger | `"enter razorfen downs"` |
| Leave trigger | `"leave razorfen downs"` |
| Tuten'kash fight | `"tuten'kash"` |
| Mordresh fight | `"mordresh fire eye"` |
| Glutton fight | `"glutton"` |
| Amnennar fight | `"amnennar the coldbringer"` |
| Mordresh Fire Nova trigger | `"mordresh fire nova"` |
| Amnennar Frost Nova trigger | `"amnennar frost nova"` |
| Mordresh move away action | `"mordresh move away from fire nova"` |
| Amnennar move away action | `"amnennar move away from frost nova"` |

---

## Registration Checklist

- [x] `playerbot/strategy/generic/DungeonStrategy.cpp` — enter/leave razorfen downs (combat + noncombat)
- [x] `playerbot/strategy/triggers/TriggerContext.h` — include RfdTriggers.h + all 10 RFD creators
- [x] `playerbot/strategy/actions/ActionContext.h` — include RfdActions.h + all 10 RFD creators
- [x] `playerbot/strategy/StrategyContext.h` — include RfdStrategy.h + 5 RFD strategy creators
- [x] `CMakeLists.txt` — covered by existing GLOB_RECURSE (no per-dungeon entry needed)

---

## Build Status

- [x] `./build.sh` — clean, no new errors (2026-05-02)

---

## Definition of Done

- [ ] Build clean
- [ ] Bot enters RFD → instance strategy loads (log: `enable razorfen downs strategy`)
- [ ] Tuten'kash engaged → tuten'kash fight strategy enables
- [ ] Mordresh Fire Eye engaged → mordresh fire eye fight strategy enables; bots move >12yd during Fire Nova
- [ ] Glutton engaged → glutton fight strategy enables
- [ ] Amnennar engaged → amnennar the coldbringer fight strategy enables; bots move >10yd during Frost Nova
- [ ] Each boss dies → fight strategy disables
- [ ] Bot leaves RFD → instance strategy unloads (log: `disable razorfen downs strategy`)

---

## Verify Commands

With `LogFileLevel = 3`, grep Server.log for:
```
enable razorfen downs strategy
enable mordresh fire eye fight strategy
mordresh fire nova
mordresh move away from fire nova
enable amnennar the coldbringer fight strategy
amnennar frost nova
amnennar move away from frost nova
disable razorfen downs strategy
```

---

## Spell Reference

| Spell | ID | Radius | Notes |
|-------|----|--------|-------|
| Fire Nova (Mordresh) | 11831 | ~10yd | Verify ID in spell_template |
| Frost Nova (Amnennar) | 865 | ~8yd | Verify ID — may differ from player version |

> Verify spell IDs with `SELECT entry, name, EffectRadius_1 FROM spell_template WHERE name LIKE '%Fire Nova%'` etc.

---

## Next Step

Implement in order:

1. `RfdTriggers.h`
2. `RfdActions.h`
3. `RfdStrategy.h` + `RfdStrategy.cpp`
4. Four registration edits (DungeonStrategy.cpp, TriggerContext.h, ActionContext.h, StrategyContext.h)
5. `CMakeLists.txt`
6. `./build.sh` verify
