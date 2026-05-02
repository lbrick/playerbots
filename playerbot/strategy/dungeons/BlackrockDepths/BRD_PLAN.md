# Blackrock Depths — Implementation Plan

**Map ID:** 230  
**Levels:** 52–60  
**Status:** 🟢 IMPLEMENTED — build verified 2026-05-02  

> **NPC IDs:** Cross-check every entry with `SELECT entry, name FROM creature_template WHERE name LIKE '%...%'` against classicmangos DB before wiring triggers.
>
> **Note:** BRD is the largest dungeon in the game. Many bosses are optional or wing-gated. All are registered for completeness; players/bots may skip sections depending on run objectives.

---

## Boss Reference

### Ring of Law (one random champion + crowd event)

| Boss | NPC ID | Mechanic | Trigger Type | Action |
|------|--------|----------|--------------|--------|
| Gorosh the Dervish | 9027 | Blood Craze (self-heal on hit), Sweeping Strikes. No radial AoE. | None — start/end only | — |
| Grizzle | 9028 | **Ground Tremor** (~10yd AoE physical stun around boss) | `CloseToHostileCreatureHazardTrigger(9028, 10, 3)` | `MoveAwayFromCreature(9028, 12)` |
| Eviscerator | 9029 | Whirlwind (~8yd AoE physical), Cleave. | `CloseToHostileCreatureHazardTrigger(9029, 8, 3)` | `MoveAwayFromCreature(9029, 10)` |
| Ok'thor the Breaker | 9030 | **War Stomp** (~8yd AoE physical), Knockdown | `CloseToHostileCreatureHazardTrigger(9030, 8, 3)` | `MoveAwayFromCreature(9030, 10)` |
| Anub'shiah | 9031 | Curse of Blood (debuff), melee. No positional AoE. | None — start/end only | — |
| Hedrum the Creeper | 9032 | Poison Bolt Volley (AoE ranged), Corrosive Poison. Ranged AoE handled by healer strategy. | None — start/end only | — |

### Main Dungeon

| Boss | NPC ID | Mechanic | Trigger Type | Action |
|------|--------|----------|--------------|--------|
| High Interrogator Gerstahn | 9018 | Mind Blast, Psychic Scream (AoE fear ~10yd). Fear handled by break strategy — no movement trigger needed. | None — start/end only | — |
| Lord Roccor | 9025 | **Earthquake** (~10yd AoE physical), Earth Shock | `CloseToHostileCreatureHazardTrigger(9025, 10, 3)` | `MoveAwayFromCreature(9025, 12)` |
| Houndmaster Grebmar | 9319 | Releases hound packs. No positional AoE. | None — start/end only | — |
| Pyromancer Loregrain | 9024 | **Fire Nova** (~10yd AoE fire), Fireball | `CloseToHostileCreatureHazardTrigger(9024, 10, 3)` | `MoveAwayFromCreature(9024, 12)` |
| Warder Stilgiss | 9041 | Frost Nova (~8yd), Blizzard. Frost Nova = move away. | `CloseToHostileCreatureHazardTrigger(9041, 8, 3)` | `MoveAwayFromCreature(9041, 10)` |
| Verek | 9042 | Veil of Shadow, melee dog. No positional AoE. | None — start/end only | — |
| Plugger Spazzring | 9499 | Gouge, Blind. No positional AoE. | None — start/end only | — |
| Phalanx | 9502 | Mortal Strike, Shield Bash. No positional AoE. | None — start/end only | — |
| Ambassador Flamelash | 9156 | Summons fire elemental waves. No positional AoE (elementals handled by kill logic). | None — start/end only | — |
| The Seven (Dwarven spirits) | 8888 | Multi-mob fight. Various debuffs. No positional AoE. Using Franclorn Forgewright (8888) as canonical NPC — verify in DB. | None — start/end only | — |
| Golem Lord Argelmach | 8983 | **Static Field** (~8yd AoE nature around boss), Shock, summons golems | `CloseToHostileCreatureHazardTrigger(8983, 8, 3)` | `MoveAwayFromCreature(8983, 10)` |
| Bael'Gar | 9016 | **Fire Nova** (~10yd AoE fire), Lava Burst | `CloseToHostileCreatureHazardTrigger(9016, 10, 3)` | `MoveAwayFromCreature(9016, 12)` |
| General Angerforge | 9033 | Mortal Strike, multi-mob adds. No radial AoE. | None — start/end only | — |
| Magmus | 9938 | **War Stomp** (~8yd AoE), Fire Bolt. Blocks emperor's door until dead. | `CloseToHostileCreatureHazardTrigger(9938, 8, 3)` | `MoveAwayFromCreature(9938, 10)` |
| Emperor Dagran Thaurissan | 9019 | Sunder Armor (stacking debuff), Fireball, Hand of Thaurissan (periodic AoE debuff aura). Aura handled by healer; no movement mechanic. | None — start/end only | — |

> **DB verification complete (2026-05-02):** Ring of Law IDs corrected: Grizzle=9028, Eviscerator=9029, Ok'thor=9030, Anub'shiah=9031, Hedrum=9032. Warder Stilgiss=9041, Verek=9042. Pyromancer=9024 (no conflict with Eviscerator). The Seven uses Franclorn Forgewright (8888) — canonical NPC unresolved, flag for future DB check.
>
> **Ring of Law:** Only one champion spawns per run (random). Register all six; only the active one will ever trigger.
>
> **The Seven:** All seven dwarf spirits (Ironhelm, Umbranse, Angerforge, Franclorn, Thaurissan, Corehammer, Fineous) engage together. Use the first spirit NPC ID as the canonical start trigger, or register each separately under the same fight strategy.
>
> **Magmus:** Must die to open the door to Emperor Thaurissan's throne room.

---

## Boss Details

### Ring of Law

> Only one champion spawns per run (random). All six registered; only active one triggers.

---

#### Gorosh the Dervish
**NPC:** 9027 | [Wowhead](https://www.wowhead.com/classic/npc=9027/gorosh-the-dervish)

Orc warrior champion. Self-sustaining melee fighter.

| Ability | Description |
|---------|-------------|
| Blood Craze | Heals Gorosh for ~300 HP on each hit received. |
| Sweeping Strikes | Next 5 attacks hit two targets simultaneously. |

**Bot strategy:** No radial AoE — start/end triggers only. Gorosh self-heals through Blood Craze; DPS pressure important. Sweeping Strikes punishes multiple melee, but no positional response needed.

---

#### Grizzle
**NPC:** 9028 | [Wowhead](https://www.wowhead.com/classic/npc=9028/grizzle)

Ettin champion with a ground slam AoE. Primary hazard in Ring of Law.

| Ability | Description |
|---------|-------------|
| Ground Tremor | ~10yd AoE physical stun around boss. Primary hazard. |
| Hamstring | Slows current melee target. |

**Bot strategy:** `CloseToHostileCreatureHazardTrigger(9028, 10, 3)` → `MoveAwayFromCreature(9028, 12)`. Ground Tremor stuns bots in range — spread >12yd minimizes locked-down healers.

---

#### Eviscerator
**NPC:** 9029 | [Wowhead](https://www.wowhead.com/classic/npc=9029/eviscerator)

Spider champion. Whirlwind makes this one of the more dangerous Ring champions.

| Ability | Description |
|---------|-------------|
| Whirlwind | ~8yd AoE physical spin hitting all nearby players. |
| Cleave | Frontal melee hit on up to 2 targets. |

**Bot strategy:** `CloseToHostileCreatureHazardTrigger(9029, 8, 3)` → `MoveAwayFromCreature(9029, 10)`. Whirlwind is the primary hazard — non-tank bots must stay >10yd during spin.

---

#### Ok'thor the Breaker
**NPC:** 9030 | [Wowhead](https://www.wowhead.com/classic/npc=9030/oktor-the-breaker)

Ogre champion. War Stomp knockback can interrupt healers and casters.

| Ability | Description |
|---------|-------------|
| War Stomp | ~8yd AoE physical knockback. |
| Knockdown | Single-target knockdown on current melee target. |

**Bot strategy:** `CloseToHostileCreatureHazardTrigger(9030, 8, 3)` → `MoveAwayFromCreature(9030, 10)`. War Stomp interrupts casts — spread ensures healers stay active.

---

#### Anub'shiah
**NPC:** 9031 | [Wowhead](https://www.wowhead.com/classic/npc=9031/anubshiah)

Nerubian champion. Debuff-focused fight with no positional hazard.

| Ability | Description |
|---------|-------------|
| Curse of Blood | Increases Physical damage taken by target. |
| Immolate | Fire DoT on random player. |

**Bot strategy:** No radial AoE — start/end triggers only. Curse of Blood makes burst damage dangerous — healers keep priority targets topped.

---

#### Hedrum the Creeper
**NPC:** 9032 | [Wowhead](https://www.wowhead.com/classic/npc=9032/hedrum-the-creeper)

Spider champion with ranged poison volley. AoE is ranged, not proximity.

| Ability | Description |
|---------|-------------|
| Poison Bolt Volley | AoE ranged poison hitting all players in line of sight. |
| Corrosive Poison | Nature DoT on random player. |

**Bot strategy:** No positional AoE — start/end triggers only. Poison Bolt Volley is ranged — healer strategy handles it. No spreading required.

---

### Main Dungeon

---

#### High Interrogator Gerstahn
**NPC:** 9018 | [Wowhead](https://www.wowhead.com/classic/npc=9018/high-interrogator-gerstahn)

Shadow priest boss near the prison wing.

| Ability | Description |
|---------|-------------|
| Psychic Scream | AoE fear ~10yd affecting all nearby players. |
| Mind Blast | Heavy single-target shadow damage. |
| Shadow Word: Pain | Shadow DoT on random player. |

**Bot strategy:** No positional trigger — fear handled by break-fear strategy. Start/end only.

---

#### Lord Roccor
**NPC:** 9025 | [Wowhead](https://www.wowhead.com/classic/npc=9025/lord-roccor)

Earthen elementalist patrolling the Ring of Law outer corridor.

| Ability | Description |
|---------|-------------|
| Earthquake | ~10yd AoE physical knock-down around boss. Primary hazard. |
| Earth Shock | Single-target nature damage + interrupt. |

**Bot strategy:** `CloseToHostileCreatureHazardTrigger(9025, 10, 3)` → `MoveAwayFromCreature(9025, 12)`. Earthquake stuns nearby players — spread minimizes healer downtime.

---

#### Houndmaster Grebmar
**NPC:** 9319 | [Wowhead](https://www.wowhead.com/classic/npc=9319/houndmaster-grebmar)

Dwarf boss near the kennel area. Pack-release encounter.

| Ability | Description |
|---------|-------------|
| Release Hounds | Releases two Core Hound packs that join the fight. |
| Shoot | Ranged attack on random player. |

**Bot strategy:** No positional AoE — start/end only. Adds handled by kill-nearest logic. Hounds may stun/immolate — healer priority.

---

#### Pyromancer Loregrain
**NPC:** 9024 | [Wowhead](https://www.wowhead.com/classic/npc=9024/pyromancer-loregrain)

Dwarf fire mage near the Shrine of Thaurissan.

| Ability | Description |
|---------|-------------|
| Fire Nova | ~10yd AoE fire burst around boss. Primary hazard. |
| Fireball | Heavy single-target fire damage. |
| Fire Shield | Periodic fire absorb shield on self. |

**Bot strategy:** `CloseToHostileCreatureHazardTrigger(9024, 10, 3)` → `MoveAwayFromCreature(9024, 12)`. Fire Nova fires repeatedly — bots must stay >12yd except tank.

---

#### Warder Stilgiss
**NPC:** 9041 | [Wowhead](https://www.wowhead.com/classic/npc=9041/warder-stilgiss)

Undead warder guarding cell block areas. Paired with Verek.

| Ability | Description |
|---------|-------------|
| Frost Nova | ~8yd AoE freeze rooting all nearby players. |
| Blizzard | Ground-targeted AoE frost damage zone. |

**Bot strategy:** `CloseToHostileCreatureHazardTrigger(9041, 8, 3)` → `MoveAwayFromCreature(9041, 10)`. Frost Nova roots bots in place — spread prevents chain-frozen healers.

---

#### Verek
**NPC:** 9042 | [Wowhead](https://www.wowhead.com/classic/npc=9042/verek)

Core Hound pet of Warder Stilgiss. Engaged alongside Stilgiss.

| Ability | Description |
|---------|-------------|
| Veil of Shadow | Reduces healing received by target by 75%. |
| Lava Breath | Frontal cone fire damage. |

**Bot strategy:** No radial AoE — start/end only. Kill Verek before Stilgiss to remove healing debuff pressure.

---

#### Plugger Spazzring
**NPC:** 9499 | [Wowhead](https://www.wowhead.com/classic/npc=9499/plugger-spazzring)

Goblin bartender in the Grim Guzzler tavern. Optional encounter.

| Ability | Description |
|---------|-------------|
| Gouge | Incapacitates current melee target briefly. |
| Blind | Disorients random player. |

**Bot strategy:** No positional AoE — start/end only. Gouge breaks on damage; blind handled by healer. Fighting Plugger aggroes the tavern.

---

#### Phalanx
**NPC:** 9502 | [Wowhead](https://www.wowhead.com/classic/npc=9502/phalanx)

Large golem guarding the bar in the Grim Guzzler.

| Ability | Description |
|---------|-------------|
| Mortal Strike | Heavy melee hit reducing healing received by 50%. |
| Shield Bash | Interrupts casting and silences for 2 sec. |

**Bot strategy:** No radial AoE — start/end only. Mortal Strike makes healing discipline critical. Tank should hold aggro firmly to limit Shield Bash on casters.

---

#### Ambassador Flamelash
**NPC:** 9156 | [Wowhead](https://www.wowhead.com/classic/npc=9156/ambassador-flamelash)

Fire elemental ambassador in the Hall of Crafting.

| Ability | Description |
|---------|-------------|
| Summon Fire Elemental | Summons multiple fire elemental waves throughout fight. |
| Burning Spirit | Empowers summoned elementals, increasing their damage. |

**Bot strategy:** No positional AoE — start/end only. Elemental waves handled by kill-nearest logic. Focus Flamelash while off-bots clear adds.

---

#### The Seven
**NPC:** 8888 (Franclorn Forgewright, canonical) | [Wowhead](https://www.wowhead.com/classic/npc=8888/franclorn-forgewright)

Seven dwarven spirits of the dark iron ancestors. All engage simultaneously.

| Ability | Description |
|---------|-------------|
| Various debuffs | Each spirit has unique curse/debuff abilities. |
| Overwhelming Numbers | Seven simultaneous targets demand AoE and smart kill-ordering. |

**Bot strategy:** No positional AoE — start/end only. Use Franclorn Forgewright (8888) as canonical trigger — verify each spirit's NPC ID in DB if per-spirit strategies needed later.

---

#### Golem Lord Argelmach
**NPC:** 8983 | [Wowhead](https://www.wowhead.com/classic/npc=8983/golem-lord-argelmach)

Dwarf engineer boss in the Manufactory. Controls the golem army.

| Ability | Description |
|---------|-------------|
| Static Field | ~8yd AoE nature damage pulsing around boss. Primary hazard. |
| Shock | Single-target nature damage + knockback. |
| Summon Golems | Summons Iron and Crimson Golems as adds. |

**Bot strategy:** `CloseToHostileCreatureHazardTrigger(8983, 8, 3)` → `MoveAwayFromCreature(8983, 10)`. Static Field damages all bots in melee range continuously — non-tanks must stay out. Golem adds handled by kill-nearest.

---

#### Bael'Gar
**NPC:** 9016 | [Wowhead](https://www.wowhead.com/classic/npc=9016/baelgar)

Ancient fire elemental imprisoned deep in BRD. One of the most dangerous AoE bosses.

| Ability | Description |
|---------|-------------|
| Fire Nova | ~10yd AoE fire burst around boss. Primary hazard. Fires repeatedly. |
| Lava Burst | Targeted fire AoE on a random player. |

**Bot strategy:** `CloseToHostileCreatureHazardTrigger(9016, 10, 3)` → `MoveAwayFromCreature(9016, 12)`. Fire Nova is a primary DoD verification point — bots must spread >12yd during fight.

---

#### General Angerforge
**NPC:** 9033 | [Wowhead](https://www.wowhead.com/classic/npc=9033/general-angerforge)

Dark Iron general in the West Garrison. Summons elite guard adds at low HP.

| Ability | Description |
|---------|-------------|
| Mortal Strike | Heavy melee hit reducing healing received by 50%. |
| Summon Anvilrage Soldiers | Summons Dark Iron soldiers when HP drops low. |

**Bot strategy:** No radial AoE — start/end only. Burn Angerforge before adds overwhelm — Mortal Strike makes extended fights dangerous.

---

#### Magmus
**NPC:** 9938 | [Wowhead](https://www.wowhead.com/classic/npc=9938/magmus)

Fire elemental guarding the door to the Emperor's throne room. Must die to open the door.

| Ability | Description |
|---------|-------------|
| War Stomp | ~8yd AoE physical knockback. Primary hazard. |
| Fire Bolt | Ranged fire damage on random player. |
| Lava Spray | Frontal cone fire damage. |

**Bot strategy:** `CloseToHostileCreatureHazardTrigger(9938, 8, 3)` → `MoveAwayFromCreature(9938, 10)`. Gate behind Magmus stays closed until he dies — required kill on every Emperor run.

---

#### Emperor Dagran Thaurissan
**NPC:** 9019 | [Wowhead](https://www.wowhead.com/classic/npc=9019/emperor-dagran-thaurissan)

Final boss of BRD. Dark Iron emperor and master of fire magic. Moira Bronzebeard is present in the room — do not kill her.

| Ability | Description |
|---------|-------------|
| Sunder Armor | Stacking armor reduction debuff on tank. Resets on boss reset. |
| Fireball | Heavy ranged fire damage on random player. |
| Hand of Thaurissan | Periodic AoE shadow debuff aura — damages all nearby players. |

**Bot strategy:** No positional movement trigger — Hand of Thaurissan aura handled by healer throughput strategy. Start/end only. Sunder Armor stacks demand threat management to avoid tank switches.

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

- [x] `playerbot/strategy/generic/DungeonStrategy.cpp` — enter/leave blackrock depths (combat + noncombat)
- [x] `playerbot/strategy/triggers/TriggerContext.h` — include BrdTriggers.h + all BRD creators
- [x] `playerbot/strategy/actions/ActionContext.h` — include BrdActions.h + all BRD creators
- [x] `playerbot/strategy/StrategyContext.h` — include BrdStrategy.h + all strategy creators
- [x] `CMakeLists.txt` — covered by existing GLOB_RECURSE (no per-dungeon entry needed)

---

## Build Status

- [x] `./build.sh` — clean, no new errors (2026-05-02)

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
