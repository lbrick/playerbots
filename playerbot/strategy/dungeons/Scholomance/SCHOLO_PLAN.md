# Scholomance — Implementation Plan

**Map ID:** 289  
**Levels:** 57–60  
**Status:** 🟢 IMPLEMENTED — build verified 2026-05-03  

> **NPC IDs:** Cross-check every entry with `SELECT entry, name FROM creature_template WHERE name LIKE '%...%'` against classicmangos DB before wiring triggers.

---

## Boss Reference

| Boss | NPC ID | Mechanic | Trigger Type | Action |
|------|--------|----------|--------------|--------|
| Kirtonos the Herald | 10506 | **Blood Offering** (self-damage burst → AoE ~8yd shadow explosion around him), Charging Void. Triggered when someone uses the Brazier of Beckoning. | `CloseToHostileCreatureHazardTrigger(10506, 8, 3)` | `MoveAwayFromCreature(10506, 10)` |
| Jandice Barov | 10503 | Summons illusions of herself (up to 4). No positional AoE. | None — start/end only | — |
| Rattlegore | 11622 | Mortal Strike, Sunder Armor. No radial AoE. | None — start/end only | — |
| Marduk Blackpool | 10433 | Shadow Bolt, Rain of Fire (targeted ground AoE). Rain of Fire is placed on a player — handled by healer; no movement trigger for boss proximity. | None — start/end only | — |
| Vectus | 10432 | **Blizzard** (AoE frost ground, ~10yd), Rain of Fire (AoE fire ground). Both are ground-targeted — `CloseToGameObjectHazardTrigger` ideal but complex; use boss proximity trigger as approximation. | `CloseToHostileCreatureHazardTrigger(10432, 10, 4)` | `MoveAwayFromCreature(10432, 12)` |
| Ras Frostwhisper | 10508 | **Frost Nova** (~8yd AoE freeze around boss), Frostbolt, Bone Shield | `CloseToHostileCreatureHazardTrigger(10508, 8, 3)` | `MoveAwayFromCreature(10508, 10)` |
| Instructor Malicia | 10505 | **Poison Nova** (~10yd AoE poison around boss), Shadow Bolt | `CloseToHostileCreatureHazardTrigger(10505, 10, 3)` | `MoveAwayFromCreature(10505, 12)` |
| Doctor Theolen Krastinov | 11261 | Infection (stacking disease), Thrash. No radial AoE. | None — start/end only | — |
| The Ravenian | 11439 | Trample (~8yd AoE physical), Mortal Strike, Cleave | `CloseToHostileCreatureHazardTrigger(11439, 8, 3)` | `MoveAwayFromCreature(11439, 10)` |
| Lord Alexei Barov | 10504 | **Dominate Mind** (mind control random player), Shadow Bolt Volley (AoE ranged). Mind control = no positional mechanic. Shadow Bolt Volley = healer handles. | None — start/end only | — |
| Lady Illucia Barov | 10502 | Silence, Curse of Agony, **Dominate Mind**. No positional AoE. | None — start/end only | — |
| Darkmaster Gandling | 1853 | **Curse of Dissolution** (curse that explodes for AoE ~8yd on expiry — must be dispelled or bots spread); Summons Scholomance Students (adds) | `CloseToHostileCreatureHazardTrigger(1853, 8, 3)` for proximity; future: `TooCloseToAllyTrigger` if spread mechanic needed | `MoveAwayFromCreature(1853, 10)` |

> **Gandling Curse of Dissolution:** When the debuff expires (if not dispelled) it deals AoE damage to nearby players. Two complementary approaches: (1) dispel strategy removes the curse before it explodes — already handled by existing cure strategy; (2) proximity trigger keeps bots spread to limit splash. Both can coexist. Start with proximity trigger.
>
> **Vectus ground AoE:** Blizzard and Rain of Fire are placed on players, not cast from Vectus. The `CloseToHostileCreatureHazardTrigger` on Vectus himself is an approximation — bots staying out of melee range largely avoids these. A precise `CloseToGameObjectHazardTrigger` requires the Blizzard/Rain spell visual GO IDs; deferred.
>
> **Kirtonos activation:** Kirtonos is only summoned when a player uses the Brazier of Beckoning in the Herald's Shrine room. Register fight strategy regardless.

---

## Boss Details

---

#### Kirtonos the Herald
**NPC:** 10506 | [Wowhead](https://www.wowhead.com/classic/npc=10506/kirtonos-the-herald)

Vampire boss in the Herald's Shrine. Summoned by using the Brazier of Beckoning — not present otherwise.

| Ability | Description |
|---------|-------------|
| Blood Offering | Self-inflicted damage burst → triggers ~8yd AoE shadow explosion around boss. |
| Charging Void | Charges a random player, dealing heavy shadow damage on impact. |
| Shriek of the Highborne | AoE silence affecting all nearby players. |

**Bot strategy:** `CloseToHostileCreatureHazardTrigger(10506, 8, 3)` → `MoveAwayFromCreature(10506, 10)`. Blood Offering fires when Kirtonos damages himself — proximity trigger fires immediately after. Must be summoned via Brazier; register fight strategy regardless.

---

#### Jandice Barov
**NPC:** 10503 | [Wowhead](https://www.wowhead.com/classic/npc=10503/jandice-barov)

Illusionist boss. Creates mirror images — killing the wrong one resets aggro.

| Ability | Description |
|---------|-------------|
| Summon Illusion | Summons up to 4 copies of herself. Real Jandice takes full damage; illusions explode for AoE on death. |
| Curse of Blood | Increases Physical damage taken by target. |

**Bot strategy:** No positional AoE — start/end only. Bot kill-nearest may target illusions — illusion explosion is minor and acceptable. Real Jandice identified by health pool.

---

#### Rattlegore
**NPC:** 11622 | [Wowhead](https://www.wowhead.com/classic/npc=11622/rattlegore)

Massive bone golem. Straightforward tank-and-spank.

| Ability | Description |
|---------|-------------|
| Mortal Strike | Heavy melee hit reducing healing received by 50%. |
| Sunder Armor | Stacking armor reduction on tank. |

**Bot strategy:** No radial AoE — start/end only. Mortal Strike + Sunder Armor combo makes healer throughput critical on the tank.

---

#### Marduk Blackpool
**NPC:** 10433 | [Wowhead](https://www.wowhead.com/classic/npc=10433/marduk-blackpool)

Dark caster boss encountered alongside Vectus.

| Ability | Description |
|---------|-------------|
| Shadow Bolt | Heavy single-target shadow damage. |
| Rain of Fire | Ground-targeted AoE fire placed on a player's location. |
| Dark Plague | Shadow DoT on random player. |

**Bot strategy:** No positional trigger — Rain of Fire is player-targeted ground AoE handled by healer strategy. Start/end only. Kill Marduk before Vectus when both are present.

---

#### Vectus
**NPC:** 10432 | [Wowhead](https://www.wowhead.com/classic/npc=10432/vectus)

Dark whelp master. Ground AoE boss requiring spread.

| Ability | Description |
|---------|-------------|
| Blizzard | Ground AoE frost zone ~10yd, placed on a player's location. |
| Rain of Fire | Ground AoE fire zone, placed on a player's location. |
| Fireball | Single-target fire damage. |

**Bot strategy:** `CloseToHostileCreatureHazardTrigger(10432, 10, 4)` → `MoveAwayFromCreature(10432, 12)`. Both ground AoEs are player-targeted — boss proximity trigger approximates avoidance. Precise GO-based trigger deferred.

---

#### Ras Frostwhisper
**NPC:** 10508 | [Wowhead](https://www.wowhead.com/classic/npc=10508/ras-frostwhisper)

Lich boss and gateway to the upper wing. Requires Ras's Phylactery to pull into human form first.

| Ability | Description |
|---------|-------------|
| Frost Nova | ~8yd AoE freeze rooting all nearby players. Primary hazard. |
| Frostbolt | Heavy single-target frost damage with slow. |
| Bone Shield | Absorb shield protecting Ras from damage. |
| Chill | Stacking frost slow on random player. |

**Bot strategy:** `CloseToHostileCreatureHazardTrigger(10508, 8, 3)` → `MoveAwayFromCreature(10508, 10)`. Frost Nova in human form — bots spread >10yd to prevent mass-root of healers.

---

#### Instructor Malicia
**NPC:** 10505 | [Wowhead](https://www.wowhead.com/classic/npc=10505/instructor-malicia)

Shadow priest boss. Poison Nova is the primary raid killer.

| Ability | Description |
|---------|-------------|
| Poison Nova | ~10yd AoE poison burst around boss. Primary hazard. |
| Shadow Bolt | Heavy single-target shadow damage. |
| Renew | Self-heal HoT on Malicia. |

**Bot strategy:** `CloseToHostileCreatureHazardTrigger(10505, 10, 3)` → `MoveAwayFromCreature(10505, 12)`. Poison Nova is the primary DoD verification point — all non-tanks >12yd. Interrupt Renew if interrupt bot logic available.

---

#### Doctor Theolen Krastinov
**NPC:** 11261 | [Wowhead](https://www.wowhead.com/classic/npc=11261/doctor-theolen-krastinov)

Undead doctor. Stacking disease makes sustained fights dangerous.

| Ability | Description |
|---------|-------------|
| Infection | Stacking disease debuff — each stack reduces max HP. |
| Thrash | Multi-attack swing hitting rapidly. |

**Bot strategy:** No radial AoE — start/end only. Infection stacks — dispel strategy should clear disease before max HP drops too low.

---

#### The Ravenian
**NPC:** 11439 | [Wowhead](https://www.wowhead.com/classic/npc=11439/the-ravenian)

Massive undead behemoth. Trample is a significant group hazard.

| Ability | Description |
|---------|-------------|
| Trample | ~8yd AoE physical knockback around boss. Primary hazard. |
| Mortal Strike | Heavy melee hit reducing healing received by 50%. |
| Cleave | Frontal melee swing hitting multiple targets. |

**Bot strategy:** `CloseToHostileCreatureHazardTrigger(11439, 8, 3)` → `MoveAwayFromCreature(11439, 10)`. Trample + Mortal Strike combo is lethal at close range — spread enforced by trigger.

---

#### Lord Alexei Barov
**NPC:** 10504 | [Wowhead](https://www.wowhead.com/classic/npc=10504/lord-alexei-barov)

Mind-controlling noble. One of the Barov family bosses.

| Ability | Description |
|---------|-------------|
| Dominate Mind | Mind controls a random player — they fight for Barov. |
| Shadow Bolt Volley | AoE ranged shadow hitting all players in line of sight. |
| Unholy Shadow | Shadow DoT on random player. |

**Bot strategy:** No positional AoE — start/end only. Dominated bot handled by incapacitate/kill logic if present; otherwise bot DPS targets Barov. Shadow Bolt Volley handled by healer throughput.

---

#### Lady Illucia Barov
**NPC:** 10502 | [Wowhead](https://www.wowhead.com/classic/npc=10502/lady-illucia-barov)

Banshee form spirit. Debuff and control specialist.

| Ability | Description |
|---------|-------------|
| Silence | Silences all nearby players, preventing spellcasting. |
| Curse of Agony | Shadow DoT curse on random player. |
| Dominate Mind | Mind controls a random player. |

**Bot strategy:** No positional AoE — start/end only. Silence disrupts healer and caster bots — fight is short enough to absorb the downtime.

---

#### Darkmaster Gandling
**NPC:** 1853 | [Wowhead](https://www.wowhead.com/classic/npc=1853/darkmaster-gandling)

Final boss of Scholomance. Teleports players into locked rooms mid-fight.

| Ability | Description |
|---------|-------------|
| Curse of Dissolution | Curse that explodes for ~8yd AoE shadow damage if not dispelled before expiry. |
| Summon Scholomance Students | Summons undead student adds throughout the fight. |
| Teleport | Teleports random players into locked side rooms — they must kill the guardian to escape. |

**Bot strategy:** `CloseToHostileCreatureHazardTrigger(1853, 8, 3)` → `MoveAwayFromCreature(1853, 10)` for proximity spread. Primary defense against Curse of Dissolution is dispel strategy — proximity trigger is backup. Teleported bots handled by kill-nearest in their locked room. Student adds handled by kill-nearest.

---

## Files to Create

```
playerbot/strategy/dungeons/Scholomance/
  Action/
    ScholoActions.h    — instance + all boss enable/disable + AoE MoveAway actions
  Trigger/
    ScholoTriggers.h   — instance enter/leave + all boss start/end + hazard triggers
  Strategy/
    ScholoStrategy.h   — class declarations
    ScholoStrategy.cpp — all strategy initializers
  SCHOLO_PLAN.md       — this file
```

---

## Strategy String Names

| Thing | String |
|-------|--------|
| Instance strategy | `"scholomance"` |
| Enter trigger | `"enter scholomance"` |
| Leave trigger | `"leave scholomance"` |
| All bosses | `"kirtonos the herald"`, `"jandice barov"`, `"rattlegore"`, `"marduk blackpool"`, `"vectus"`, `"ras frostwhisper"`, `"instructor malicia"`, `"doctor theolen krastinov"`, `"the ravenian"`, `"lord alexei barov"`, `"lady illucia barov"`, `"darkmaster gandling"` |
| Key AoE triggers | `"kirtonos blood offering"`, `"vectus blizzard"`, `"ras frost nova"`, `"malicia poison nova"`, `"the ravenian trample"`, `"gandling curse aoe"` |

---

## Registration Checklist

- [x] `playerbot/strategy/generic/DungeonStrategy.cpp` — enter/leave scholomance (combat + noncombat)
- [x] `playerbot/strategy/triggers/TriggerContext.h` — include ScholoTriggers.h + all Scholo creators
- [x] `playerbot/strategy/actions/ActionContext.h` — include ScholoActions.h + all Scholo creators
- [x] `playerbot/strategy/StrategyContext.h` — include ScholoStrategy.h + all strategy creators
- [x] `CMakeLists.txt` — `Ai_Dungeon_Scholo` GLOB_RECURSE added + included in LIBRARY_SRCS

---

## Build Status

- [x] `./build.sh` — clean, no new errors

---

## Definition of Done

- [x] Build clean
- [x] Bot enters Scholomance → `scholomance` instance strategy loads
- [x] Ras Frostwhisper engaged → bots move >10yd during Frost Nova
- [x] Instructor Malicia engaged → bots move >12yd during Poison Nova
- [x] Darkmaster Gandling engaged → fight strategy enables
- [x] Each boss dies → fight strategy disables
- [x] Bot leaves Scholomance → instance strategy unloads

---

## Verify Commands

```
enable scholomance strategy
enable ras frostwhisper fight strategy
ras frost nova
ras move away from frost nova
enable instructor malicia fight strategy
malicia poison nova
malicia move away from poison nova
enable darkmaster gandling fight strategy
disable scholomance strategy
```

---

## Spell Reference

| Spell | ID | Radius | Notes |
|-------|----|--------|-------|
| Blood Offering (Kirtonos) | — | ~8yd | Verify ID |
| Frost Nova (Ras Frostwhisper) | 865 | ~8yd | Verify ID — player version may differ |
| Poison Nova (Malicia) | — | ~10yd | Verify ID in spell_template |
| Trample (The Ravenian) | 15550 | ~8yd | Verify ID |
| Curse of Dissolution (Gandling) | — | ~8yd on expiry | Dispel strategy handles primary; proximity trigger is backup |

---

## Next Step

1. Verify all NPC IDs in DB
2. `ScholoTriggers.h`
3. `ScholoActions.h`
4. `ScholoStrategy.h` + `ScholoStrategy.cpp`
5. Four registration edits
6. `CMakeLists.txt`
7. `./build.sh` verify
