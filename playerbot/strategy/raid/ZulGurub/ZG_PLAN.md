# Zul'Gurub — Implementation Plan

**Map ID:** 309  
**Size:** 20-player  
**Tier:** Classic — Phase 4 raid  
**Status:** 📋 TODO  
**Wowhead:** https://www.wowhead.com/classic/guide/wow-classic-zulgurub-overview#overview-of-bosses

> **NPC IDs:** Cross-check every entry with `SELECT entry, name FROM creature_template WHERE name LIKE '%...%'`
> against classicmangos DB before wiring triggers.

---

## Boss Reference

| Boss | NPC ID | Mechanic | Trigger Type | Action |
|------|--------|----------|--------------|--------|
| High Priestess Jeklik | 14517 | Bat swarm adds; Shadow Word: Pain (DoT) — no radial AoE positional | None — start/end only | — |
| High Priest Venoxis | 14507 | **Holy Nova** ~8yd AoE holy (serpent form); Dispel Magic | `CloseToHostileCreatureHazardTrigger(14507, 8, 3)` | `MoveAwayFromCreature(14507, 10)` |
| High Priestess Mar'li | 14510 | **Web Spray** frontal cone AoE — frontal deferred; spider adds | None — start/end only (frontal deferred) | — |
| Bloodlord Mandokir | 11382 | **Whirlwind** ~8yd AoE physical (raptor mount phase speeds re-engage) | `CloseToHostileCreatureHazardTrigger(11382, 8, 3)` | `MoveAwayFromCreature(11382, 10)` |
| Edge of Madness (4 bosses) | see below | Varies per boss — see Edge of Madness section | Start/end triggers for each | see below |
| High Priest Thekal | 14509 | **Tiger's Fury** frontal cone — frontal deferred; add phase (kill adds before Thekal) | None — start/end only (frontal deferred) | — |
| High Priestess Arlokk | 14515 | Mark of Arlokk (aggro transfer); Panther form spawns panthers | None — start/end only | — |
| Jin'do the Hexxer | 11380 | Hex (MC random player); Brain Wash Totem; Healing Ward totems | None — start/end only | — |
| Hakkar the Soulflayer | 14834 | **Corrupted Blood** — persistent AoE DoT aura; **Enervate** (mana drain) | None — dispel strategy handles (see note) | — |

> **Corrupted Blood (Hakkar):** Spread/stacking mechanic requires players to alternate exposure.
> Too complex for phase 1 implementation. Treat as healers-handle; revisit if dispel strategy
> proves insufficient. Mark as deferred.
>
> **Tiger's Fury / Web Spray:** Frontal cone mechanics. All frontal cones are deferred per
> project convention — `MoveBehindCreature` complexity not yet standardized.
>
> **Mandokir raptor phase:** Mandokir mounts and charges with increased speed after killing
> a raid member. Existing kill-nearest logic handles re-engagement. No bot mechanic needed.

---

## Edge of Madness Bosses

One of these four spawns randomly per reset. Implement all with at minimum start/end triggers.

| Boss | NPC ID | Mechanic | Trigger Type | Action |
|------|--------|----------|--------------|--------|
| Gri'lek | 14527 | Mortal Strike, War Stomp ~8yd AoE | `CloseToHostileCreatureHazardTrigger(14527, 8, 3)` | `MoveAwayFromCreature(14527, 10)` |
| Hazza'rah | 14534 | **Sleep** AoE ~10yd (hits random raid members) | None — start/end only (sleep = CC handled) | — |
| Renataki | 14516 | Ambush, Thousand Blades — no radial AoE | None — start/end only | — |
| Wushoolay | 14321 | **Lightning Cloud** ~8yd AoE nature ground effect | `CloseToHostileCreatureHazardTrigger(14321, 8, 3)` | `MoveAwayFromCreature(14321, 10)` |

> **Edge of Madness NPC IDs:** Highly uncertain — verify all four in DB before implementation.
> These bosses are rarely documented with correct Classic-era IDs.

---

## Files to Create

```
playerbot/strategy/raid/ZulGurub/
  Action/
    RaidZgActions.h      — instance + 13 boss enable/disable + Venoxis/Mandokir/Gri'lek/Wushoolay MoveAway
  Trigger/
    RaidZgTriggers.h     — instance enter/leave + 13 boss start/end + 4 AoE mechanic triggers
  Strategy/
    RaidZgStrategy.h     — class declarations (instance + 13 boss fight strategies)
    RaidZgStrategy.cpp   — all strategy initializers
  ZG_PLAN.md             — this file
```

---

## Strategy String Names

| Thing | String |
|-------|--------|
| Instance strategy | `"zul'gurub"` |
| Enter trigger | `"enter zul'gurub"` |
| Leave trigger | `"leave zul'gurub"` |
| Jeklik fight | `"high priestess jeklik"` |
| Venoxis fight | `"high priest venoxis"` |
| Mar'li fight | `"high priestess mar'li"` |
| Mandokir fight | `"bloodlord mandokir"` |
| Gri'lek fight | `"gri'lek"` |
| Hazza'rah fight | `"hazza'rah"` |
| Renataki fight | `"renataki"` |
| Wushoolay fight | `"wushoolay"` |
| Thekal fight | `"high priest thekal"` |
| Arlokk fight | `"high priestess arlokk"` |
| Jin'do fight | `"jin'do the hexxer"` |
| Hakkar fight | `"hakkar the soulflayer"` |
| Venoxis Holy Nova trigger | `"venoxis holy nova"` |
| Mandokir Whirlwind trigger | `"mandokir whirlwind"` |
| Gri'lek War Stomp trigger | `"gri'lek war stomp"` |
| Wushoolay Lightning Cloud trigger | `"wushoolay lightning cloud"` |
| Venoxis move away | `"venoxis move away from holy nova"` |
| Mandokir move away | `"mandokir move away from whirlwind"` |
| Gri'lek move away | `"gri'lek move away from war stomp"` |
| Wushoolay move away | `"wushoolay move away from lightning cloud"` |

---

## Mechanic Parameters

| Boss | NPC ID | Trigger Radius | Safe Range | Duration |
|------|--------|---------------|------------|----------|
| High Priest Venoxis | 14507 | 8 | 10.0f | 3 |
| Bloodlord Mandokir | 11382 | 8 | 10.0f | 3 |
| Gri'lek | 14527 | 8 | 10.0f | 3 |
| Wushoolay | 14321 | 8 | 10.0f | 3 |

> Verify radii in-game or via spell_template.EffectRadius_1 before finalising.

---

## Registration Checklist

- [ ] `playerbot/strategy/generic/DungeonStrategy.cpp` — enter/leave zul'gurub (combat + noncombat)
- [ ] `playerbot/strategy/triggers/TriggerContext.h` — include RaidZgTriggers.h + all 22 ZG creators
- [ ] `playerbot/strategy/actions/ActionContext.h` — include RaidZgActions.h + all 30 ZG creators
- [ ] `playerbot/strategy/StrategyContext.h` — include RaidZgStrategy.h + 14 ZG strategy creators
- [ ] `CMakeLists.txt` — add `Ai_ZulGurub` GLOB_RECURSE entry alongside other raid entries

---

## Build Status

- [ ] `./build.sh` — clean, no new errors or warnings

---

## Definition of Done

- [ ] Build clean
- [ ] Bot enters ZG → instance strategy loads (log: `enable zul'gurub strategy`)
- [ ] Jeklik engaged → jeklik fight strategy enables; disables on death
- [ ] Venoxis engaged → venoxis fight strategy enables; bots move >10yd during Holy Nova
- [ ] Mar'li engaged → mar'li fight strategy enables; disables on death
- [ ] Mandokir engaged → mandokir fight strategy enables; bots move >10yd during Whirlwind
- [ ] Edge of Madness boss engaged → correct fight strategy enables
- [ ] Gri'lek (if active) — bots move >10yd during War Stomp
- [ ] Wushoolay (if active) — bots move >10yd during Lightning Cloud
- [ ] Thekal engaged → thekal fight strategy enables; disables on death
- [ ] Arlokk engaged → arlokk fight strategy enables; disables on death
- [ ] Jin'do engaged → jin'do fight strategy enables; disables on death
- [ ] Hakkar engaged → hakkar fight strategy enables; disables on death
- [ ] All boss fight strategies disable correctly on death AND reset
- [ ] Bot leaves ZG → instance strategy unloads (log: `disable zul'gurub strategy`)

---

## Verify Commands

With `LogFileLevel = 3`, grep Server.log for:
```
enable zul'gurub strategy
enable high priest venoxis fight strategy
venoxis holy nova
venoxis move away from holy nova
enable bloodlord mandokir fight strategy
mandokir whirlwind
mandokir move away from whirlwind
enable hakkar the soulflayer fight strategy
disable zul'gurub strategy
```

---

## Spell Reference

| Spell | Boss | Approx ID | Notes |
|-------|------|-----------|-------|
| Holy Nova | Venoxis | ~23858 | Serpent-form version — verify in spell_template |
| Whirlwind | Mandokir | ~15576 | Verify — multiple Whirlwind IDs exist |
| War Stomp | Gri'lek | ~11876 | Verify — multiple War Stomp IDs exist |
| Lightning Cloud | Wushoolay | ~25033 | Ground AoE — verify radius in spell_template |
| Corrupted Blood | Hakkar | ~24328 | Raid-wide DoT — no positional trigger needed |

> Verify all spell IDs: `SELECT entry, name, EffectRadius_1 FROM spell_template WHERE name LIKE '%Holy Nova%'` etc.

---

## Implementation Order

1. `RaidZgTriggers.h` — enter/leave + all boss start/end + 4 AoE mechanic triggers
2. `RaidZgActions.h` — instance + all boss enable/disable + 4 MoveAway actions
3. `RaidZgStrategy.h` + `RaidZgStrategy.cpp` — instance strategy (13 boss start triggers) + 13 fight strategies
4. Five registration edits (`DungeonStrategy.cpp`, `TriggerContext.h`, `ActionContext.h`, `StrategyContext.h`, `CMakeLists.txt`)
5. `./build.sh` verify
6. In-game test: enter ZG → pull Venoxis (serpent form AoE) → verify bot movement
