# Dire Maul — Implementation Plan

**Map ID:** 429  
**Levels:** 55–60  
**Status:** ⬜ TODO  

> **Three wings, one map ID:** East (Warpwood Quarter), West (Capital Gardens), North (Gordok Commons) all share map 429. One instance strategy covers all wings; boss fight strategies differentiate by NPC ID.
>
> **Naming note:** "DM" collides with Deadmines (Map 36). Strategy strings use "dire maul" prefix throughout to avoid conflicts.
>
> **NPC IDs:** Cross-check every entry with `SELECT entry, name FROM creature_template WHERE name LIKE '%...%'` against classicmangos DB before wiring triggers.

---

## Boss Reference — East (Warpwood Quarter)

| Boss | NPC ID | Mechanic | Trigger Type | Action |
|------|--------|----------|--------------|--------|
| Zevrim Thornhoof | 11490 | **Sacrifice** (lifts a random player, deals periodic damage while channeled). Player is unreachable during channel. No radial AoE — start/end only. | None — start/end only | — |
| Hydrospawn | 13280 | Tidal Wave (AoE knockback), Enervate. Knockback is single-targeted — no radial AoE. | None — start/end only | — |
| Lethtendris | 14327 | Arcane Missiles, Drain Mana. No positional AoE. | None — start/end only | — |
| Alzzin the Wildshaper | 11492 | Shapeshifts between caster and melee forms; Earthgrip (AoE root ~10yd), Enrage | `CloseToHostileCreatureHazardTrigger(11492, 10, 3)` | `MoveAwayFromCreature(11492, 12)` |

> **Hydrospawn NPC ID 13280:** Verify in DB — this ID was used for Lord Vyletongue in MARA_PLAN.md. One is wrong; check both.

---

## Boss Reference — West (Capital Gardens)

| Boss | NPC ID | Mechanic | Trigger Type | Action |
|------|--------|----------|--------------|--------|
| Tendris Warpwood | 11489 | Entangle (AoE root ~8yd), Thorn Aura (reflects melee damage). Entangle = radial. | `CloseToHostileCreatureHazardTrigger(11489, 8, 3)` | `MoveAwayFromCreature(11489, 10)` |
| Illyanna Ravenoak | 11488 | Strafe (frontal AoE arrow sweep), Multi-Shot, Trueshot Aura. Frontal detection deferred. | None — start/end only | — |
| Magister Kalendris | 11487 | Shadow Word: Pain, **Dominate Mind** (mind control). No positional AoE. | None — start/end only | — |
| Immol'thar | 11496 | **Disease Cloud** (AoE disease ~10yd around boss, ticks continuously); summons Glowing Eye adds | `CloseToHostileCreatureHazardTrigger(11496, 10, 3)` | `MoveAwayFromCreature(11496, 12)` |
| Prince Tortheldrin | 11486 | **Arcane Blast** (AoE arcane ~8yd), Thrash (extra attacks), Whirlwind. Must defeat Immol'thar first. | `CloseToHostileCreatureHazardTrigger(11486, 8, 3)` | `MoveAwayFromCreature(11486, 10)` |

> **Immol'thar prerequisite:** Prince Tortheldrin only activates after Immol'thar is dead (drains power from Immol'thar). Bot kill-nearest logic handles quest sequencing passively.

---

## Boss Reference — North (Gordok Commons)

| Boss | NPC ID | Mechanic | Trigger Type | Action |
|------|--------|----------|--------------|--------|
| Guard Mol'dar | 14326 | **War Stomp** (~8yd AoE physical) | `CloseToHostileCreatureHazardTrigger(14326, 8, 3)` | `MoveAwayFromCreature(14326, 10)` |
| Stomper Kreeg | 14322 | **Knock Away** (AoE knockback ~8yd), drunken melee. Knockback = radial. | `CloseToHostileCreatureHazardTrigger(14322, 8, 3)` | `MoveAwayFromCreature(14322, 10)` |
| Guard Fengus | 14321 | Cleave, Mortal Strike. No radial AoE. | None — start/end only | — |
| Guard Slip'kik | 14323 | Web (immobilize), Frost Nova (~8yd). Frost Nova = move away. | `CloseToHostileCreatureHazardTrigger(14323, 8, 3)` | `MoveAwayFromCreature(14323, 10)` |
| Captain Kromcrush | 14325 | **War Stomp** (~8yd AoE physical), Mortal Strike | `CloseToHostileCreatureHazardTrigger(14325, 8, 3)` | `MoveAwayFromCreature(14325, 10)` |
| King Gordok | 11501 | **Thunderclap** (~8yd AoE physical), Mortal Strike, Knock Away | `CloseToHostileCreatureHazardTrigger(11501, 8, 3)` | `MoveAwayFromCreature(11501, 10)` |

> **Gordok tribute run (optional):** Players can kill the three guards without alerting King Gordok, then kill Gordok for a tribute chest. In a bot context the bot uses standard kill logic — tribute routing is not implemented at this level.

---

## Files to Create

```
playerbot/strategy/dungeons/DireMaul/
  Action/
    DmActions.h        — instance + all boss enable/disable + AoE MoveAway actions
  Trigger/
    DmTriggers.h       — instance enter/leave + all boss start/end + hazard triggers
  Strategy/
    DmStrategy.h       — class declarations
    DmStrategy.cpp     — all strategy initializers
  DM_PLAN.md           — this file
```

---

## Strategy String Names

| Thing | String |
|-------|--------|
| Instance strategy | `"dire maul"` |
| Enter trigger | `"enter dire maul"` |
| Leave trigger | `"leave dire maul"` |
| East bosses | `"zevrim thornhoof"`, `"hydrospawn"`, `"lethtendris"`, `"alzzin the wildshaper"` |
| West bosses | `"tendris warpwood"`, `"illyanna ravenoak"`, `"magister kalendris"`, `"immol'thar"`, `"prince tortheldrin"` |
| North bosses | `"guard mol'dar"`, `"stomper kreeg"`, `"guard fengus"`, `"guard slip'kik"`, `"captain kromcrush"`, `"king gordok"` |
| Key AoE triggers | `"alzzin earthgrip"`, `"tendris entangle"`, `"immol'thar disease cloud"`, `"tortheldrin arcane blast"`, `"mol'dar war stomp"`, `"kreeg knock away"`, `"slip'kik frost nova"`, `"kromcrush war stomp"`, `"gordok thunderclap"` |

---

## Registration Checklist

- [ ] `playerbot/strategy/generic/DungeonStrategy.cpp` — enter/leave dire maul (combat + noncombat)
- [ ] `playerbot/strategy/triggers/TriggerContext.h` — include DmTriggers.h + all DM creators
- [ ] `playerbot/strategy/actions/ActionContext.h` — include DmActions.h + all DM creators
- [ ] `playerbot/strategy/StrategyContext.h` — include DmStrategy.h + all strategy creators
- [ ] `CMakeLists.txt` — `Ai_Dungeon_DM` GLOB_RECURSE added + included in LIBRARY_SRCS

---

## Build Status

- [ ] `./build.sh` — clean, no new errors

---

## Definition of Done

- [ ] Build clean
- [ ] Bot enters Dire Maul (any wing) → `dire maul` instance strategy loads
- [ ] Immol'thar engaged → bots move >12yd during Disease Cloud
- [ ] Prince Tortheldrin engaged → bots move >10yd during Arcane Blast
- [ ] King Gordok engaged → bots move >10yd during Thunderclap
- [ ] Each boss dies → fight strategy disables
- [ ] Bot leaves Dire Maul → instance strategy unloads

---

## Verify Commands

```
enable dire maul strategy
enable immol'thar fight strategy
immol'thar disease cloud
immol'thar move away from disease cloud
enable king gordok fight strategy
gordok thunderclap
gordok move away from thunderclap
disable dire maul strategy
```

---

## Spell Reference

| Spell | ID | Radius | Notes |
|-------|----|--------|-------|
| Earthgrip (Alzzin) | — | ~10yd | Verify ID in spell_template |
| Entangle (Tendris) | 11922 | ~8yd | Verify ID |
| Disease Cloud (Immol'thar) | — | ~10yd | Verify ID |
| Arcane Blast (Tortheldrin) | — | ~8yd | Verify ID |
| War Stomp (Mol'dar, Kromcrush) | 11876 | ~8yd | Shared spell likely |
| Thunderclap (King Gordok) | 15548 | ~8yd | Verify ID |
| Frost Nova (Slip'kik) | 865 | ~8yd | Verify ID |

---

## Next Step

1. Verify all NPC IDs in DB (especially Hydrospawn vs. Vyletongue 13280 conflict)
2. `DmTriggers.h`
3. `DmActions.h`
4. `DmStrategy.h` + `DmStrategy.cpp`
5. Four registration edits
6. `CMakeLists.txt`
7. `./build.sh` verify
