# Blackrock Spire (LBRS + UBRS) — Implementation Plan

**Map ID:** 229 (both wings share the same map)  
**Levels:** 55–60  
**Status:** ⬜ TODO  

> **One map ID, two wings:** LBRS and UBRS share map 229. Use one instance strategy that covers all bosses in both wings. Boss fight strategies distinguish wings by NPC ID.
>
> **NPC IDs:** Cross-check every entry with `SELECT entry, name FROM creature_template WHERE name LIKE '%...%'` against classicmangos DB before wiring triggers.

---

## Boss Reference — LBRS

| Boss | NPC ID | Mechanic | Trigger Type | Action |
|------|--------|----------|--------------|--------|
| Highlord Omokk | 9196 | **War Stomp** (~8yd AoE physical), Blot (single-target stun) | `CloseToHostileCreatureHazardTrigger(9196, 8, 3)` | `MoveAwayFromCreature(9196, 10)` |
| Shadow Hunter Vosh'gajin | 9218 | Hex (random frog polymorph), Curse of Blood. No positional AoE. | None — start/end only | — |
| War Master Voone | 9237 | Cleave, Mortal Strike. No radial AoE. | None — start/end only | — |
| Mother Smolderweb | 10596 | Web (immobilize), Summon Daughter of Smolderweb (adds). No positional AoE mechanic. | None — start/end only | — |
| Urok Doomhowl | 10584 | Summon ogres (event), War Stomp. Event-triggered spawn encounter. | `CloseToHostileCreatureHazardTrigger(10584, 8, 3)` | `MoveAwayFromCreature(10584, 10)` |
| Quartermaster Zigris | 9736 | Shoot (ranged), Gouge. No positional AoE. | None — start/end only | — |
| Halycon | 10220 | Howl (AoE fear), summons Whelps. Fear handled by break strategy. No movement mechanic. | None — start/end only | — |
| Overlord Wyrmthalak | 9568 | **War Stomp** (~8yd AoE), Blizzard (AoE cold ~10yd), summons Spirestone adds | `CloseToHostileCreatureHazardTrigger(9568, 10, 3)` | `MoveAwayFromCreature(9568, 12)` |

---

## Boss Reference — UBRS

| Boss | NPC ID | Mechanic | Trigger Type | Action |
|------|--------|----------|--------------|--------|
| Pyroguard Emberseer | 9816 | Encage (must free him via guards), **Ignite** (AoE fire aura ~8yd after freed) | `CloseToHostileCreatureHazardTrigger(9816, 8, 3)` | `MoveAwayFromCreature(9816, 10)` |
| Solakar Flamewreath | 10264 | Whelp wave event (Father Flame incubators). Standard cleave/melee. No radial AoE. | None — start/end only | — |
| Jed Runewatcher | 10509 | Arcane Missiles, Power Word: Shield. Rare spawn, optional. No positional AoE. | None — start/end only | — |
| The Beast | 10430 | **Conflagration** (targeted AoE fire burst on random player, ~10yd splash), Frenzy, Immolation Trap | `CloseToHostileCreatureHazardTrigger(10430, 10, 4)` | `MoveAwayFromCreature(10430, 12)` |
| General Drakkisath | 10363 | **Conflagration** (AoE fire cone targeting random players, ~8yd), Cleave, War Stomp | `CloseToHostileCreatureHazardTrigger(10363, 8, 3)` | `MoveAwayFromCreature(10363, 10)` |

> **Pyroguard Emberseer activation:** Five Blackhand Incarcerators surround Emberseer. Killing all five frees him and starts the fight. Bot kill-nearest logic handles the trash. Register Emberseer (9816) as the fight strategy trigger.
>
> **The Beast Conflagration:** Targets a random player with a fire blast that splashes to nearby players. The `CloseToHostileCreatureHazardTrigger` ensures bots spread from the boss during the fight.
>
> **General Drakkisath Conflagration:** Drakkisath has two Chromatic Whelp adds (10442) at the start. Existing kill logic handles them. The Conflagration fires on random targets throughout the fight.
>
> **Urok Doomhowl:** Optional ogre event accessed via Roughshod Pike (item summon). May not be present every run. Register regardless.

---

## Files to Create

```
playerbot/strategy/dungeons/BlackrockSpire/
  Action/
    BrsActions.h       — instance + all boss enable/disable + AoE MoveAway actions
  Trigger/
    BrsTriggers.h      — instance enter/leave + all boss start/end + hazard triggers
  Strategy/
    BrsStrategy.h      — class declarations
    BrsStrategy.cpp    — all strategy initializers
  BRS_PLAN.md          — this file
```

---

## Strategy String Names

| Thing | String |
|-------|--------|
| Instance strategy | `"blackrock spire"` |
| Enter trigger | `"enter blackrock spire"` |
| Leave trigger | `"leave blackrock spire"` |
| LBRS bosses | `"highlord omokk"`, `"shadow hunter vosh'gajin"`, `"war master voone"`, `"mother smolderweb"`, `"urok doomhowl"`, `"quartermaster zigris"`, `"halycon"`, `"overlord wyrmthalak"` |
| UBRS bosses | `"pyroguard emberseer"`, `"solakar flamewreath"`, `"jed runewatcher"`, `"the beast"`, `"general drakkisath"` |
| Key AoE triggers | `"omokk war stomp"`, `"urok war stomp"`, `"wyrmthalak blizzard"`, `"emberseer ignite"`, `"the beast conflagration"`, `"drakkisath conflagration"` |

---

## Registration Checklist

- [ ] `playerbot/strategy/generic/DungeonStrategy.cpp` — enter/leave blackrock spire (combat + noncombat)
- [ ] `playerbot/strategy/triggers/TriggerContext.h` — include BrsTriggers.h + all BRS creators
- [ ] `playerbot/strategy/actions/ActionContext.h` — include BrsActions.h + all BRS creators
- [ ] `playerbot/strategy/StrategyContext.h` — include BrsStrategy.h + all strategy creators
- [ ] `CMakeLists.txt` — `Ai_Dungeon_BRS` GLOB_RECURSE added + included in LIBRARY_SRCS

---

## Build Status

- [ ] `./build.sh` — clean, no new errors

---

## Definition of Done

- [ ] Build clean
- [ ] Bot enters BRS (either wing) → `blackrock spire` instance strategy loads
- [ ] Highlord Omokk engaged → bots move >10yd during War Stomp
- [ ] Overlord Wyrmthalak engaged → bots move >12yd during Blizzard/War Stomp
- [ ] Pyroguard Emberseer engaged → bots move >10yd during Ignite
- [ ] The Beast engaged → bots move >12yd during Conflagration
- [ ] General Drakkisath engaged → bots move >10yd during Conflagration
- [ ] Each boss dies → fight strategy disables
- [ ] Bot leaves BRS → instance strategy unloads

---

## Verify Commands

```
enable blackrock spire strategy
enable the beast fight strategy
the beast conflagration
the beast move away from conflagration
enable general drakkisath fight strategy
drakkisath conflagration
drakkisath move away from conflagration
disable blackrock spire strategy
```

---

## Spell Reference

| Spell | ID | Radius | Notes |
|-------|----|--------|-------|
| War Stomp (Omokk, Urok, Drakkisath) | 11876 | ~8yd | Shared spell — verify |
| Blizzard (Wyrmthalak) | — | ~10yd | Verify ID — may be unique NPC spell |
| Ignite (Emberseer) | — | ~8yd | Verify ID |
| Conflagration (The Beast) | 23023 | ~10yd | Verify ID |
| Conflagration (Drakkisath) | 23023 | ~8yd | Same spell likely — verify |

---

## Next Step

1. Verify all NPC IDs in DB
2. `BrsTriggers.h`
3. `BrsActions.h`
4. `BrsStrategy.h` + `BrsStrategy.cpp`
5. Four registration edits
6. `CMakeLists.txt`
7. `./build.sh` verify
