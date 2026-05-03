# Dire Maul — Implementation Plan

**Map ID:** 429  
**Levels:** 55–60  
**Status:** 🟢 IMPLEMENTED — build verified 2026-05-03; in-game verify pending  

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

## Boss Details

### East (Warpwood Quarter)

---

#### Zevrim Thornhoof
**NPC:** 11490 | [Wowhead](https://www.wowhead.com/classic/npc=11490/zevrim-thornhoof)

Satyr boss at the entrance to DM East. Sacrifice mechanic removes a player from the fight temporarily.

| Ability | Description |
|---------|-------------|
| Sacrifice | Lifts a random player, dealing periodic shadow damage while channeled. Target is unreachable. |
| Corrupt | Shadow DoT on random player. |

**Bot strategy:** No radial AoE — start/end only. Sacrificed bot is handled by waiting out the channel. Healers maintain HoTs on targeted player.

---

#### Hydrospawn
**NPC:** 13280 | [Wowhead](https://www.wowhead.com/classic/npc=13280/hydrospawn)

Water elemental boss. **Verify NPC ID in DB** — 13280 was used for Lord Vyletongue in MARA_PLAN; one is wrong.

| Ability | Description |
|---------|-------------|
| Tidal Wave | Single-target knockback on current melee target. |
| Enervate | Reduces a target's attack and cast speed. |

**Bot strategy:** No radial AoE — start/end only. Tidal Wave is single-target knockback; no spreading required.

---

#### Lethtendris
**NPC:** 14327 | [Wowhead](https://www.wowhead.com/classic/npc=14327/lethtendris)

Blood elf sorceress with imp companion (Pimgib). Mana drain caster.

| Ability | Description |
|---------|-------------|
| Arcane Missiles | Channeled arcane damage on random player. |
| Drain Mana | Drains mana from a random player. |
| Enveloping Web | Immobilizes current target. |

**Bot strategy:** No positional AoE — start/end only. Pimgib (imp companion) handled by kill-nearest. Interrupt Arcane Missiles if interrupt logic available.

---

#### Alzzin the Wildshaper
**NPC:** 11492 | [Wowhead](https://www.wowhead.com/classic/npc=11492/alzzin-the-wildshaper)

Final East wing boss. Shapeshifter with a radial root AoE and enrage at low HP.

| Ability | Description |
|---------|-------------|
| Earthgrip | ~10yd AoE root around boss. Primary hazard. |
| Enrage | Enrages at low HP, increasing attack speed and damage. |
| Shapeshift | Alternates between druid caster and melee bear form. |

**Bot strategy:** `CloseToHostileCreatureHazardTrigger(11492, 10, 3)` → `MoveAwayFromCreature(11492, 12)`. Earthgrip roots bots in place — spread minimizes healer lockdown. Burns boss fast after Enrage.

---

### West (Capital Gardens)

---

#### Tendris Warpwood
**NPC:** 11489 | [Wowhead](https://www.wowhead.com/classic/npc=11489/tendris-warpwood)

Ancient treant boss. Entangle roots all nearby players — primary group hazard.

| Ability | Description |
|---------|-------------|
| Entangle | ~8yd AoE root around boss. Primary hazard. |
| Thorn Aura | Reflects a portion of melee damage back to attacker. |
| War Stomp | ~8yd AoE knockback. |

**Bot strategy:** `CloseToHostileCreatureHazardTrigger(11489, 8, 3)` → `MoveAwayFromCreature(11489, 10)`. Entangle roots bots — spread prevents chain-rooted healers. Thorn Aura punishes rapid melee; tank awareness important.

---

#### Illyanna Ravenoak
**NPC:** 11488 | [Wowhead](https://www.wowhead.com/classic/npc=11488/illyanna-ravenoak)

Blood elf ranger boss. Frontal AoE sweep attack; bear companion Ferra (11489-family) engages alongside.

| Ability | Description |
|---------|-------------|
| Strafe | Frontal AoE arrow sweep hitting all in front of her. |
| Multi-Shot | AoE ranged hit on multiple players. |
| Trueshot Aura | Passive aura increasing her ranged attack power. |

**Bot strategy:** No positional trigger — frontal sweep detection deferred. Start/end only. Ferra companion handled by kill-nearest.

---

#### Magister Kalendris
**NPC:** 11487 | [Wowhead](https://www.wowhead.com/classic/npc=11487/magister-kalendris)

Blood elf shadow mage. Mind control is the primary danger — no positional AoE.

| Ability | Description |
|---------|-------------|
| Dominate Mind | Mind controls a random player for ~10 sec. |
| Shadow Word: Pain | Shadow DoT on random player. |
| Psychic Scream | AoE fear ~10yd — handled by break-fear strategy. |

**Bot strategy:** No positional AoE — start/end only. Dominated bot handled by nearest-kill or wait logic. Psychic Scream handled by break-fear strategy.

---

#### Immol'thar
**NPC:** 11496 | [Wowhead](https://www.wowhead.com/classic/npc=11496/immolthar)

Massive eyeball demon imprisoned in the west wing. Disease Cloud is a continuous persistent aura — the primary West wing hazard.

| Ability | Description |
|---------|-------------|
| Disease Cloud | Persistent ~10yd disease AoE aura around boss. Ticks continuously on all nearby players. Primary hazard. |
| Summon Glowing Eyes | Summons floating eye adds during fight. |
| Tentacle | Spawns tentacle adds. |

**Bot strategy:** `CloseToHostileCreatureHazardTrigger(11496, 10, 3)` → `MoveAwayFromCreature(11496, 12)`. Disease Cloud is persistent — non-tank bots must stay >12yd at all times. Primary DoD verification point. Eye adds handled by kill-nearest.

---

#### Prince Tortheldrin
**NPC:** 11486 | [Wowhead](https://www.wowhead.com/classic/npc=11486/prince-tortheldrin)

Final West wing boss. Only activates after Immol'thar is dead. Arcane Blast is a radial burst AoE.

| Ability | Description |
|---------|-------------|
| Arcane Blast | ~8yd AoE arcane burst around boss. Primary hazard. |
| Thrash | Multi-attack swing — extra hits on current target. |
| Whirlwind | ~8yd AoE physical spin. |

**Bot strategy:** `CloseToHostileCreatureHazardTrigger(11486, 8, 3)` → `MoveAwayFromCreature(11486, 10)`. Arcane Blast + Whirlwind both ~8yd — single trigger covers both. Kill Immol'thar first to activate him.

---

### North (Gordok Commons)

---

#### Guard Mol'dar
**NPC:** 14326 | [Wowhead](https://www.wowhead.com/classic/npc=14326/guard-moldar)

Ogre guard. First North wing boss. War Stomp knocks back nearby players.

| Ability | Description |
|---------|-------------|
| War Stomp | ~8yd AoE physical knockback. Primary hazard. |
| Sunder Armor | Stacking armor reduction on tank. |

**Bot strategy:** `CloseToHostileCreatureHazardTrigger(14326, 8, 3)` → `MoveAwayFromCreature(14326, 10)`. Kill him to prevent Gordok from being reinforced.

---

#### Stomper Kreeg
**NPC:** 14322 | [Wowhead](https://www.wowhead.com/classic/npc=14322/stomper-kreeg)

Drunken ogre guard. Knock Away scatters nearby players and can interrupt healer positioning.

| Ability | Description |
|---------|-------------|
| Knock Away | ~8yd AoE knockback around boss. Primary hazard. |
| Drunken Stupor | Occasionally stumbles, reducing hit chance. |

**Bot strategy:** `CloseToHostileCreatureHazardTrigger(14322, 8, 3)` → `MoveAwayFromCreature(14322, 10)`. Knock Away scatters group — spread ensures healers stay in range after knockback.

---

#### Guard Fengus
**NPC:** 14321 | [Wowhead](https://www.wowhead.com/classic/npc=14321/guard-fengus)

Ogre guard. Melee-focused, no radial AoE.

| Ability | Description |
|---------|-------------|
| Cleave | Frontal melee swing hitting up to 2 targets. |
| Mortal Strike | Heavy melee hit reducing healing received by 50%. |

**Bot strategy:** No radial AoE — start/end only. Mortal Strike makes healer throughput critical on tank. Can be skipped on tribute runs.

---

#### Guard Slip'kik
**NPC:** 14323 | [Wowhead](https://www.wowhead.com/classic/npc=14323/guard-slipkik)

Ogre guard with frost abilities. Frost Nova is the key hazard.

| Ability | Description |
|---------|-------------|
| Frost Nova | ~8yd AoE freeze rooting all nearby players. Primary hazard. |
| Web | Immobilizes current melee target. |

**Bot strategy:** `CloseToHostileCreatureHazardTrigger(14323, 8, 3)` → `MoveAwayFromCreature(14323, 10)`. Frost Nova roots bots — spread prevents healer lockdown. Can be frozen before fight on tribute runs (statue mechanic).

---

#### Captain Kromcrush
**NPC:** 14325 | [Wowhead](https://www.wowhead.com/classic/npc=14325/captain-kromcrush)

Elite ogre captain. War Stomp and Mortal Strike make him dangerous to unprepared groups.

| Ability | Description |
|---------|-------------|
| War Stomp | ~8yd AoE physical knockback. Primary hazard. |
| Mortal Strike | Heavy melee hit reducing healing received by 50%. |
| Bash | Single-target stun on current target. |

**Bot strategy:** `CloseToHostileCreatureHazardTrigger(14325, 8, 3)` → `MoveAwayFromCreature(14325, 10)`. War Stomp interrupts casters — spread ensures healers stay active. Can be dismissed by players with Gordok Ogre Suit; bot ignores this.

---

#### King Gordok
**NPC:** 11501 | [Wowhead](https://www.wowhead.com/classic/npc=11501/king-gordok)

Final North wing boss. Thunderclap is the primary group hazard; Mortal Strike + Knock Away make him the most dangerous North boss.

| Ability | Description |
|---------|-------------|
| Thunderclap | ~8yd AoE physical damage and slow around boss. Primary hazard. |
| Mortal Strike | Heavy melee hit reducing healing received by 50%. |
| Knock Away | Single-target knockback on current melee target. |

**Bot strategy:** `CloseToHostileCreatureHazardTrigger(11501, 8, 3)` → `MoveAwayFromCreature(11501, 10)`. Thunderclap drives spread requirement. Primary DoD verification point for North wing. Gordok tribute run (skipping guards) not implemented — bot uses standard kill logic.

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

- [x] `playerbot/strategy/generic/DungeonStrategy.cpp` — enter/leave dire maul (combat + noncombat)
- [x] `playerbot/strategy/triggers/TriggerContext.h` — include DmTriggers.h + all DM creators
- [x] `playerbot/strategy/actions/ActionContext.h` — include DmActions.h + all DM creators
- [x] `playerbot/strategy/StrategyContext.h` — include DmStrategy.h + all strategy creators
- [x] `CMakeLists.txt` — GLOB_RECURSE auto-picks up DmStrategy.cpp (touched CMakeLists.txt to rescan)

---

## Build Status

- [x] `./build-classic.sh` — clean, no errors (2026-05-03)

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
