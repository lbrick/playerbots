# Maraudon — Implementation Plan

**Map ID:** 349  
**Levels:** 46–55  
**Status:** ⬜ TODO  

> **NPC IDs:** Cross-check every entry with `SELECT entry, name FROM creature_template WHERE name LIKE '%...%'` against classicmangos DB before wiring triggers.
>
> **Wings:** Maraudon has three wings (Orange = Foulspore Cavern, Purple = Zaetar's Lair, Pristine = Waterfall/Theradras). All share map ID 349. One instance strategy covers all wings; boss fight strategies differentiate individual bosses.

---

## Boss Reference

| Boss | NPC ID | Mechanic | Trigger Type | Action |
|------|--------|----------|--------------|--------|
| Noxxion (Orange) | 13282 | **Noxious Fumes** (AoE poison cloud ~8yd around boss); splits into smaller adds at ~50% HP | `CloseToHostileCreatureHazardTrigger(13282, 8, 4)` | `MoveAwayFromCreature(13282, 10)` |
| Razorlash (Orange) | 12258 | Puncture (bleed), Cleave (frontal). No radial AoE mechanic. | None — start/end only | — |
| Lord Vyletongue (Purple) | 13280 | Curse of Blood (debuff), Blink (random teleport). No positional AoE. | None — start/end only | — |
| Celebras the Cursed (Purple) | 12519 | Wrath (nature bolt), Entangling Roots (immobilize target). No radial AoE mechanic. | None — start/end only | — |
| Landslide (Purple) | 12565 | Knock Away (knocks tank back), Trample. No radial AoE mechanic — Knock Away is single-target. | None — start/end only | — |
| Tinkerer Gizlock (Pristine) | 13601 | **Goblin Dragon Gun** (frontal fire cone ~45° wide), **Smoke Bomb** (AoE blind ~8yd) | `CloseToHostileCreatureHazardTrigger(13601, 8, 3)` for Smoke Bomb; frontal cone future enhancement | `MoveAwayFromCreature(13601, 10)` |
| Rotgrip (Pristine) | 13596 | Thrash, Cleave, Wrench (single-target bleed). No radial AoE mechanic. | None — start/end only | — |
| Princess Theradras (Pristine) | 12201 | **Dust Field** (AoE nature damage ~10yd aura around boss, ticks every 2s), **Boulder** (targeted knockback), Repulsive Gaze (AoE fear ~15yd) | `CloseToHostileCreatureHazardTrigger(12201, 10, 3)` for Dust Field | `MoveAwayFromCreature(12201, 12)` |

> **Tinkerer Gizlock Mines:** Gizlock also places explosive mines (game object) around the room. A future enhancement could use `CloseToGameObjectHazardTrigger` for mine avoidance. Deferred — Smoke Bomb AoE is sufficient for initial implementation.
>
> **Princess Theradras Repulsive Gaze:** Fear AoE at ~15yd range fires periodically. Existing fear-break logic handles the debuff effect. The Dust Field (melee-range damage aura) is the primary movement mechanic since it punishes melee bots staying in.
>
> **Celebras the Cursed:** Becomes Celebras the Redeemed after a questline event. In combat the cursed version is the encounter. Register under NPC 12519.

---

## Files to Create

```
playerbot/strategy/dungeons/Maraudon/
  Action/
    MaraActions.h      — instance + 8 boss enable/disable + Noxxion/Gizlock/Theradras MoveAway
  Trigger/
    MaraTriggers.h     — instance enter/leave + 8 boss start/end + hazard triggers
  Strategy/
    MaraStrategy.h     — class declarations
    MaraStrategy.cpp   — all strategy initializers
  MARA_PLAN.md         — this file
```

---

## Strategy String Names

| Thing | String |
|-------|--------|
| Instance strategy | `"maraudon"` |
| Enter trigger | `"enter maraudon"` |
| Leave trigger | `"leave maraudon"` |
| Noxxion fight | `"noxxion"` |
| Razorlash fight | `"razorlash"` |
| Lord Vyletongue fight | `"lord vyletongue"` |
| Celebras fight | `"celebras the cursed"` |
| Landslide fight | `"landslide"` |
| Tinkerer Gizlock fight | `"tinkerer gizlock"` |
| Rotgrip fight | `"rotgrip"` |
| Princess Theradras fight | `"princess theradras"` |
| Noxxion Noxious Fumes trigger | `"noxxion noxious fumes"` |
| Gizlock Smoke Bomb trigger | `"gizlock smoke bomb"` |
| Theradras Dust Field trigger | `"theradras dust field"` |
| Noxxion move away action | `"noxxion move away from noxious fumes"` |
| Gizlock move away action | `"gizlock move away from smoke bomb"` |
| Theradras move away action | `"theradras move away from dust field"` |

---

## Registration Checklist

- [ ] `playerbot/strategy/generic/DungeonStrategy.cpp` — enter/leave maraudon (combat + noncombat)
- [ ] `playerbot/strategy/triggers/TriggerContext.h` — include MaraTriggers.h + all Mara creators
- [ ] `playerbot/strategy/actions/ActionContext.h` — include MaraActions.h + all Mara creators
- [ ] `playerbot/strategy/StrategyContext.h` — include MaraStrategy.h + 9 strategy creators
- [ ] `CMakeLists.txt` — `Ai_Dungeon_Mara` GLOB_RECURSE added + included in LIBRARY_SRCS

---

## Build Status

- [ ] `./build.sh` — clean, no new errors

---

## Definition of Done

- [ ] Build clean
- [ ] Bot enters Maraudon → instance strategy loads (log: `enable maraudon strategy`)
- [ ] Noxxion engaged → fight strategy enables; bots move >10yd during Noxious Fumes
- [ ] Razorlash engaged → fight strategy enables
- [ ] Lord Vyletongue engaged → fight strategy enables
- [ ] Celebras the Cursed engaged → fight strategy enables
- [ ] Landslide engaged → fight strategy enables
- [ ] Tinkerer Gizlock engaged → fight strategy enables; bots move >10yd during Smoke Bomb
- [ ] Rotgrip engaged → fight strategy enables
- [ ] Princess Theradras engaged → fight strategy enables; bots move >12yd during Dust Field
- [ ] Each boss dies → fight strategy disables
- [ ] Bot leaves Maraudon → instance strategy unloads (log: `disable maraudon strategy`)

---

## Verify Commands

With `LogFileLevel = 3`, grep Server.log for:
```
enable maraudon strategy
enable noxxion fight strategy
noxxion noxious fumes
noxxion move away from noxious fumes
enable tinkerer gizlock fight strategy
gizlock smoke bomb
gizlock move away from smoke bomb
enable princess theradras fight strategy
theradras dust field
theradras move away from dust field
disable maraudon strategy
```

---

## Spell Reference

| Spell | ID | Radius | Notes |
|-------|----|--------|-------|
| Noxious Fumes (Noxxion) | 13905 | ~8yd | Verify ID in spell_template |
| Smoke Bomb (Gizlock) | 7964 | ~8yd | Verify ID |
| Dust Field (Theradras) | 14704 | ~10yd | Verify ID; ticks every ~2s |
| Repulsive Gaze (Theradras) | 14733 | ~15yd | Fear — handled by debuff strategy; no movement needed |
| Boulder (Theradras) | 21832 | — | Single-target knockback; no movement trigger needed |

---

## Next Step

Implement in order:

1. `MaraTriggers.h`
2. `MaraActions.h`
3. `MaraStrategy.h` + `MaraStrategy.cpp`
4. Four registration edits (DungeonStrategy.cpp, TriggerContext.h, ActionContext.h, StrategyContext.h)
5. `CMakeLists.txt`
6. `./build.sh` verify
