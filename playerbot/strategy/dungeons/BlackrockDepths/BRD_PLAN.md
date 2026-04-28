# Blackrock Depths — Implementation Plan

**Map ID:** 230  
**Levels:** 52–60  
**Status:** ⬜ TODO  

> **NPC IDs:** Cross-check every entry with `SELECT entry, name FROM creature_template WHERE name LIKE '%...%'` against classicmangos DB before wiring triggers.
>
> **Note:** BRD is the largest dungeon in the game. Many bosses are optional or wing-gated. All are registered for completeness; players/bots may skip sections depending on run objectives.

---

## Boss Reference

### Ring of Law (one random champion + crowd event)

| Boss | NPC ID | Mechanic | Trigger Type | Action |
|------|--------|----------|--------------|--------|
| Gorosh the Dervish | 9027 | Blood Craze (self-heal on hit), Sweeping Strikes. No radial AoE. | None — start/end only | — |
| Grizzle | 9023 | **Ground Tremor** (~10yd AoE physical stun around boss) | `CloseToHostileCreatureHazardTrigger(9023, 10, 3)` | `MoveAwayFromCreature(9023, 12)` |
| Eviscerator | 9024 | Whirlwind (~8yd AoE physical), Cleave. | `CloseToHostileCreatureHazardTrigger(9024, 8, 3)` | `MoveAwayFromCreature(9024, 10)` |
| Ok'thor the Breaker | 9026 | **War Stomp** (~8yd AoE physical), Knockdown | `CloseToHostileCreatureHazardTrigger(9026, 8, 3)` | `MoveAwayFromCreature(9026, 10)` |
| Anub'shiah | 9028 | Curse of Blood (debuff), melee. No positional AoE. | None — start/end only | — |
| Hedrum the Creeper | 9029 | Poison Bolt Volley (AoE ranged), Corrosive Poison. Ranged AoE handled by healer strategy. | None — start/end only | — |

### Main Dungeon

| Boss | NPC ID | Mechanic | Trigger Type | Action |
|------|--------|----------|--------------|--------|
| High Interrogator Gerstahn | 9018 | Mind Blast, Psychic Scream (AoE fear ~10yd). Fear handled by break strategy — no movement trigger needed. | None — start/end only | — |
| Lord Roccor | 9025 | **Earthquake** (~10yd AoE physical), Earth Shock | `CloseToHostileCreatureHazardTrigger(9025, 10, 3)` | `MoveAwayFromCreature(9025, 12)` |
| Houndmaster Grebmar | 9319 | Releases hound packs. No positional AoE. | None — start/end only | — |
| Pyromancer Loregrain | 9024 | **Fire Nova** (~10yd AoE fire), Fireball | `CloseToHostileCreatureHazardTrigger(9024, 10, 3)` | `MoveAwayFromCreature(9024, 12)` |
| Warder Stilgiss | 9017 | Frost Nova (~8yd), Blizzard. Frost Nova = move away. | `CloseToHostileCreatureHazardTrigger(9017, 8, 3)` | `MoveAwayFromCreature(9017, 10)` |
| Verek | 9216 | Veil of Shadow, melee dog. No positional AoE. | None — start/end only | — |
| Plugger Spazzring | 9499 | Gouge, Blind. No positional AoE. | None — start/end only | — |
| Phalanx | 9502 | Mortal Strike, Shield Bash. No positional AoE. | None — start/end only | — |
| Ambassador Flamelash | 9156 | Summons fire elemental waves. No positional AoE (elementals handled by kill logic). | None — start/end only | — |
| The Seven (Dwarven spirits) | 8903 | Multi-mob fight. Various debuffs. No positional AoE. | None — start/end only | — |
| Golem Lord Argelmach | 8983 | **Static Field** (~8yd AoE nature around boss), Shock, summons golems | `CloseToHostileCreatureHazardTrigger(8983, 8, 3)` | `MoveAwayFromCreature(8983, 10)` |
| Bael'Gar | 9016 | **Fire Nova** (~10yd AoE fire), Lava Burst | `CloseToHostileCreatureHazardTrigger(9016, 10, 3)` | `MoveAwayFromCreature(9016, 12)` |
| General Angerforge | 9033 | Mortal Strike, multi-mob adds. No radial AoE. | None — start/end only | — |
| Magmus | 9938 | **War Stomp** (~8yd AoE), Fire Bolt. Blocks emperor's door until dead. | `CloseToHostileCreatureHazardTrigger(9938, 8, 3)` | `MoveAwayFromCreature(9938, 10)` |
| Emperor Dagran Thaurissan | 9019 | Sunder Armor (stacking debuff), Fireball, Hand of Thaurissan (periodic AoE debuff aura). Aura handled by healer; no movement mechanic. | None — start/end only | — |

> **Eviscerator + Pyromancer Loregrain NPC ID 9024:** These may share an ID — verify in DB. One of these is likely wrong.
>
> **Ring of Law:** Only one champion spawns per run (random). Register all six; only the active one will ever trigger.
>
> **The Seven:** All seven dwarf spirits (Ironhelm, Umbranse, Angerforge, Franclorn, Thaurissan, Corehammer, Fineous) engage together. Use the first spirit NPC ID as the canonical start trigger, or register each separately under the same fight strategy.
>
> **Magmus:** Must die to open the door to Emperor Thaurissan's throne room.

---

## Files to Create

```
playerbot/strategy/dungeons/BlackrockDepths/
  Action/
    BrdActions.h       — instance + all boss enable/disable + AoE MoveAway actions
  Trigger/
    BrdTriggers.h      — instance enter/leave + all boss start/end + AoE hazard triggers
  Strategy/
    BrdStrategy.h      — class declarations
    BrdStrategy.cpp    — all strategy initializers
  BRD_PLAN.md          — this file
```

---

## Strategy String Names

| Thing | String |
|-------|--------|
| Instance strategy | `"blackrock depths"` |
| Enter trigger | `"enter blackrock depths"` |
| Leave trigger | `"leave blackrock depths"` |
| Ring of Law champions | `"gorosh"`, `"grizzle"`, `"eviscerator"`, `"ok'thor the breaker"`, `"anub'shiah"`, `"hedrum the creeper"` |
| Main bosses | `"high interrogator gerstahn"`, `"lord roccor"`, `"houndmaster grebmar"`, `"pyromancer loregrain"`, `"warder stilgiss"`, `"verek"`, `"plugger spazzring"`, `"phalanx"`, `"ambassador flamelash"`, `"the seven"`, `"golem lord argelmach"`, `"bael'gar"`, `"general angerforge"`, `"magmus"`, `"emperor dagran thaurissan"` |
| Key AoE triggers | `"grizzle ground tremor"`, `"eviscerator whirlwind"`, `"ok'thor war stomp"`, `"lord roccor earthquake"`, `"pyromancer fire nova"`, `"warder stilgiss frost nova"`, `"argelmach static field"`, `"bael'gar fire nova"`, `"magmus war stomp"` |

---

## Registration Checklist

- [ ] `playerbot/strategy/generic/DungeonStrategy.cpp` — enter/leave blackrock depths (combat + noncombat)
- [ ] `playerbot/strategy/triggers/TriggerContext.h` — include BrdTriggers.h + all BRD creators
- [ ] `playerbot/strategy/actions/ActionContext.h` — include BrdActions.h + all BRD creators
- [ ] `playerbot/strategy/StrategyContext.h` — include BrdStrategy.h + all strategy creators
- [ ] `CMakeLists.txt` — `Ai_Dungeon_BRD` GLOB_RECURSE added + included in LIBRARY_SRCS

---

## Build Status

- [ ] `./build.sh` — clean, no new errors

---

## Definition of Done

- [ ] Build clean
- [ ] Bot enters BRD → instance strategy loads
- [ ] Ring of Law champion (any of 6) engaged → correct fight strategy enables; AoE bots move if applicable
- [ ] Bael'Gar engaged → bots move >12yd during Fire Nova
- [ ] Argelmach engaged → bots move >10yd during Static Field
- [ ] Magmus engaged → bots move >10yd during War Stomp
- [ ] Each boss dies → fight strategy disables
- [ ] Bot leaves BRD → instance strategy unloads

---

## Verify Commands

```
enable blackrock depths strategy
enable bael'gar fight strategy
bael'gar fire nova
bael'gar move away from fire nova
enable magmus fight strategy
magmus war stomp
magmus move away from war stomp
disable blackrock depths strategy
```

---

## Spell Reference

| Spell | ID | Radius | Notes |
|-------|----|--------|-------|
| Ground Tremor (Grizzle) | 6524 | ~10yd | Verify ID |
| War Stomp (Ok'thor, Magmus) | 11876 | ~8yd | Shared spell likely |
| Earthquake (Lord Roccor) | 3716 | ~10yd | Verify ID |
| Fire Nova (Pyromancer, Bael'Gar) | 11831 | ~10yd | Shared spell likely |
| Frost Nova (Warder Stilgiss) | 865 | ~8yd | Verify ID |
| Static Field (Argelmach) | — | ~8yd | Verify name + ID in spell_template |
| Whirlwind (Eviscerator) | 15576 | ~8yd | Verify ID |

---

## Next Step

1. Verify all NPC IDs in DB (especially Eviscerator/Loregrain conflict at 9024)
2. `BrdTriggers.h`
3. `BrdActions.h`
4. `BrdStrategy.h` + `BrdStrategy.cpp`
5. Four registration edits
6. `CMakeLists.txt`
7. `./build.sh` verify
