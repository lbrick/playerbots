# Blackrock Spire (LBRS + UBRS) — Implementation Plan

**Map ID:** 229 (both wings share the same map)  
**Levels:** 55–60  
**Status:** 🟢 IMPLEMENTED — build verified 2026-05-02  

> **One map ID, two wings:** LBRS and UBRS share map 229. Use one instance strategy that covers all bosses in both wings. Boss fight strategies distinguish wings by NPC ID.
>
> **NPC IDs:** Cross-check every entry with `SELECT entry, name FROM creature_template WHERE name LIKE '%...%'` against classicmangos DB before wiring triggers.

---

## Boss Reference — LBRS

| Boss | NPC ID | Mechanic | Trigger Type | Action |
|------|--------|----------|--------------|--------|
| Highlord Omokk | 9196 | **War Stomp** (~8yd AoE physical), Blot (single-target stun) | `CloseToHostileCreatureHazardTrigger(9196, 8, 3)` | `MoveAwayFromCreature(9196, 10)` |
| Shadow Hunter Vosh'gajin | 9236 | Hex (random frog polymorph), Curse of Blood. No positional AoE. | None — start/end only | — |
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

## Boss Details

### LBRS

---

#### Highlord Omokk
**NPC:** 9196 | [Wowhead](https://www.wowhead.com/classic/npc=9196/highlord-omokk)

Ogre lord at the entrance of LBRS. First real boss encountered.

| Ability | Description |
|---------|-------------|
| War Stomp | ~8yd AoE physical knockback. Primary hazard. |
| Blot | Single-target stun on random player. |

**Bot strategy:** `CloseToHostileCreatureHazardTrigger(9196, 8, 3)` → `MoveAwayFromCreature(9196, 10)`. Bots spread >10yd when War Stomp fires.

---

#### Shadow Hunter Vosh'gajin
**NPC:** 9236 | [Wowhead](https://www.wowhead.com/classic/npc=9236/shadow-hunter-voshgajin)

Troll shadow hunter. Curses and transforms players mid-fight.

| Ability | Description |
|---------|-------------|
| Hex | Polymorphs random player into a frog (incapacitate). |
| Curse of Blood | DoT curse on random player, increases Physical damage taken. |

**Bot strategy:** No positional AoE — start/end triggers only. Hex breaks on damage so bot auto-attack handles it.

---

#### War Master Voone
**NPC:** 9237 | [Wowhead](https://www.wowhead.com/classic/npc=9237/war-master-voone)

Orc warrior boss. Straightforward melee fight.

| Ability | Description |
|---------|-------------|
| Cleave | Frontal AoE melee swing hitting up to 2 targets. |
| Mortal Strike | Heavy melee hit reducing healing received by 50%. |

**Bot strategy:** No radial AoE — start/end triggers only. Tanks should be solo in front; Mortal Strike makes healing discipline important.

---

#### Mother Smolderweb
**NPC:** 10596 | [Wowhead](https://www.wowhead.com/classic/npc=10596/mother-smolderweb)

Undead spider matriarch. Add-heavy encounter.

| Ability | Description |
|---------|-------------|
| Web | Immobilizes target, preventing movement. |
| Summon Daughter of Smolderweb | Spawns spider adds during the fight. |
| Crystallize | Encases a player in crystal (secondary effect). |

**Bot strategy:** No positional AoE — start/end triggers only. Adds handled by kill-nearest logic. Web immobilize does not require movement response.

---

#### Urok Doomhowl
**NPC:** 10584 | [Wowhead](https://www.wowhead.com/classic/npc=10584/urok-doomhowl)

Optional ogre event boss. Requires Roughshod Pike item to summon.

| Ability | Description |
|---------|-------------|
| War Stomp | ~8yd AoE physical knockback. |
| Summon Ogres | Event-based wave spawns of ogre adds during fight. |

**Bot strategy:** `CloseToHostileCreatureHazardTrigger(10584, 8, 3)` → `MoveAwayFromCreature(10584, 10)`. Optional — may not be present every run. Register regardless.

---

#### Quartermaster Zigris
**NPC:** 9736 | [Wowhead](https://www.wowhead.com/classic/npc=9736/quartermaster-zigris)

Goblin ranged attacker guarding LBRS loot room.

| Ability | Description |
|---------|-------------|
| Shoot | Ranged attack at random players. |
| Gouge | Incapacitates current melee target briefly. |

**Bot strategy:** No positional AoE — start/end triggers only. Pure ranged/melee fight, no spreading required.

---

#### Halycon
**NPC:** 10220 | [Wowhead](https://www.wowhead.com/classic/npc=10220/halycon)

Wolf boss before Wyrmthalak. Paired with Gizrul the Slavener who activates on Halycon's death.

| Ability | Description |
|---------|-------------|
| Howl | AoE fear affecting all nearby players. |
| Summon Whelps | Spawns wolf whelp adds during fight. |

**Bot strategy:** No movement mechanic — start/end triggers only. AoE fear handled by existing break-fear strategy. Kill Halycon fast before Gizrul activates.

---

#### Overlord Wyrmthalak
**NPC:** 9568 | [Wowhead](https://www.wowhead.com/classic/npc=9568/overlord-wyrmthalak)

Final LBRS boss. Dragonkin overlord with multiple AoE abilities and add summons.

| Ability | Description |
|---------|-------------|
| War Stomp | ~8yd AoE physical knockback. |
| Blizzard | ~10yd AoE frost damage zone. |
| Summon Spirestone Warlords | Summons Spirestone orc adds mid-fight. |

**Bot strategy:** `CloseToHostileCreatureHazardTrigger(9568, 10, 3)` → `MoveAwayFromCreature(9568, 12)`. Both War Stomp and Blizzard fire during the fight — 12yd spread clears both. Adds handled by kill-nearest.

---

### UBRS

---

#### Pyroguard Emberseer
**NPC:** 9816 | [Wowhead](https://www.wowhead.com/classic/npc=9816/pyroguard-emberseer)

First UBRS boss. Caged at start — five Blackhand Incarcerators must be killed to free him.

| Ability | Description |
|---------|-------------|
| Ignite | ~8yd fire aura active after being freed. Continuous AoE damage to nearby players. |
| Fire Shield | Periodically envelops himself in a fire shield. |

**Bot strategy:** `CloseToHostileCreatureHazardTrigger(9816, 8, 3)` → `MoveAwayFromCreature(9816, 10)`. Emberseer (9816) registered as fight trigger. Kill five Incarcerators first — bot kill-nearest handles them.

---

#### Solakar Flamewreath
**NPC:** 10264 | [Wowhead](https://www.wowhead.com/classic/npc=10264/solakar-flamewreath)

Drake rider boss. Wave-based whelp event before engaging the boss.

| Ability | Description |
|---------|-------------|
| Father Flame Incubators | Egg waves that spawn whelps — must be killed before boss activates. |
| Cleave | Standard frontal melee cleave. |

**Bot strategy:** No radial AoE — start/end triggers only. Whelp wave handled by kill-nearest. Standard cleave fight once waves clear.

---

#### Jed Runewatcher
**NPC:** 10509 | [Wowhead](https://www.wowhead.com/classic/npc=10509/jed-runewatcher)

Rare spawn in UBRS. Optional — not present every run.

| Ability | Description |
|---------|-------------|
| Arcane Missiles | Channeled arcane damage on random target. |
| Power Word: Shield | Self-shields to absorb incoming damage. |

**Bot strategy:** No positional AoE — start/end triggers only. Optional rare — register anyway. Interrupt Arcane Missiles if interrupt logic available.

---

#### The Beast
**NPC:** 10430 | [Wowhead](https://www.wowhead.com/classic/npc=10430/the-beast)

Core hound boss. One of the most dangerous UBRS encounters due to random-target Conflagration.

| Ability | Description |
|---------|-------------|
| Conflagration | Targets random player with a fire blast; ~10yd splash to nearby players. Primary hazard. |
| Frenzy | Enrages at low HP, massively increasing attack speed and damage. |
| Immolation Trap | Places fire trap on the ground. |
| Unbalancing Strike | Reduces target's defense skill. |

**Bot strategy:** `CloseToHostileCreatureHazardTrigger(10430, 10, 4)` → `MoveAwayFromCreature(10430, 12)`. Spread ensures Conflagration splash hits fewer players. Frenzy countered by Tranquilizing Shot if hunter logic available.

---

#### General Drakkisath
**NPC:** 10363 | [Wowhead](https://www.wowhead.com/classic/npc=10363/general-drakkisath)

Final UBRS boss. Chromatic dragonkin general with two Chromatic Whelp adds (10442) at pull.

| Ability | Description |
|---------|-------------|
| Conflagration | AoE fire cone targeting random players, ~8yd radius. Fires throughout fight. |
| Cleave | Frontal melee cleave hitting multiple targets. |
| War Stomp | AoE knockback hitting nearby players. |
| Chromatic Whelp adds | Two whelps (NPC 10442) active at pull. |

**Bot strategy:** `CloseToHostileCreatureHazardTrigger(10363, 8, 3)` → `MoveAwayFromCreature(10363, 10)`. Whelp adds (10442) handled by kill-nearest before switching to Drakkisath. Conflagration fires on random targets throughout — spread is critical.

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

- [x] `./build.sh` — clean, no new errors (2026-05-02)

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
