# Scholomance — Implementation Plan

**Map ID:** 289  
**Levels:** 57–60  
**Status:** ⬜ TODO  

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

- [ ] `playerbot/strategy/generic/DungeonStrategy.cpp` — enter/leave scholomance (combat + noncombat)
- [ ] `playerbot/strategy/triggers/TriggerContext.h` — include ScholoTriggers.h + all Scholo creators
- [ ] `playerbot/strategy/actions/ActionContext.h` — include ScholoActions.h + all Scholo creators
- [ ] `playerbot/strategy/StrategyContext.h` — include ScholoStrategy.h + all strategy creators
- [ ] `CMakeLists.txt` — `Ai_Dungeon_Scholo` GLOB_RECURSE added + included in LIBRARY_SRCS

---

## Build Status

- [ ] `./build.sh` — clean, no new errors

---

## Definition of Done

- [ ] Build clean
- [ ] Bot enters Scholomance → `scholomance` instance strategy loads
- [ ] Ras Frostwhisper engaged → bots move >10yd during Frost Nova
- [ ] Instructor Malicia engaged → bots move >12yd during Poison Nova
- [ ] Darkmaster Gandling engaged → fight strategy enables
- [ ] Each boss dies → fight strategy disables
- [ ] Bot leaves Scholomance → instance strategy unloads

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
