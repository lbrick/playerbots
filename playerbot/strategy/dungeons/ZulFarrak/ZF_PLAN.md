# Zul'Farrak — Implementation Plan

**Map ID:** 209  
**Levels:** 44–54  
**Status:** ⬜ TODO  

> **NPC IDs:** Cross-check every entry with `SELECT entry, name FROM creature_template WHERE name LIKE '%...%'` against classicmangos DB before wiring triggers.

---

## Boss Reference

| Boss | NPC ID | Mechanic | Trigger Type | Action |
|------|--------|----------|--------------|--------|
| Theka the Martyr | 7272 | Rabies (disease DoT), becomes Undead mid-fight (immune to normal damage for ~60s). No positional mechanic. | None — start/end only | — |
| Witch Doctor Zum'rah | 7271 | Summons undead adds, Shadow Bolt, Voodoo Hex. No positional AoE. | None — start/end only | — |
| Antu'sul | 8127 | Summons Sul'lithuz Sandcrawlers (adds) repeatedly; Chain Lightning. No positional AoE mechanic. | None — start/end only | — |
| Shadowpriest Sezz'ziz | 7275 | Shadow Word: Pain, Heal (interrupts desired but no positional mechanic). | None — start/end only | — |
| Sergeant Bly (staircase event) | 7604 | Multi-mob event: Bly + Oro Eyegor (7605) + Murta Grimgut (7606) + Raven (7607) + Witch Doctor Zum'rah (re-engage). Standard AoE combat — no positional mechanic. | None — start/end only | — |
| Gahz'rilla | 7273 | **Freeze** (spell 11836) — ~10yd AoE frost around boss; Gahz'rilla Slam (knockback). | `CloseToHostileCreatureHazardTrigger(7273, 10, 3)` | `MoveAwayFromCreature(7273, 12)` |
| Chief Ukorz Sandscalp | 7267 | Melee boss; Ruuzlu (7268) activates alongside. No AoE positional mechanic. | None — start/end only | — |

> **Staircase event:** Bly's crew ambush from the staircase top after the prisoner wave event. All crew are melee + ranged combatants. Register under Sergeant Bly (7604) as the canonical trigger since he's the named entry that defines start/end.
>
> **Gahz'rilla summon:** Requires the Carrot on a Stick quest (Gong of Zul'Farrak). In a bot context Gahz'rilla may not be present every run. The fight strategy still registers — it simply never triggers if Gahz'rilla isn't summoned.
>
> **Chief Ukorz + Ruuzlu:** Register both NPC IDs so either can start the fight strategy. Use Ukorz (7267) for the canonical start/end trigger; add a second StartFightTrigger for Ruuzlu (7268) inside the Ukorz fight strategy.

---

## Files to Create

```
playerbot/strategy/dungeons/ZulFarrak/
  Action/
    ZfActions.h        — instance + 7 boss enable/disable + Gahz'rilla MoveAway
  Trigger/
    ZfTriggers.h       — instance enter/leave + 7 boss start/end + Gahz'rilla Freeze
  Strategy/
    ZfStrategy.h       — class declarations
    ZfStrategy.cpp     — all strategy initializers
  ZF_PLAN.md           — this file
```

---

## Strategy String Names

| Thing | String |
|-------|--------|
| Instance strategy | `"zul'farrak"` |
| Enter trigger | `"enter zul'farrak"` |
| Leave trigger | `"leave zul'farrak"` |
| Theka fight | `"theka the martyr"` |
| Zum'rah fight | `"witch doctor zum'rah"` |
| Antu'sul fight | `"antu'sul"` |
| Sezz'ziz fight | `"shadowpriest sezz'ziz"` |
| Sergeant Bly fight | `"sergeant bly"` |
| Gahz'rilla fight | `"gahz'rilla"` |
| Chief Ukorz fight | `"chief ukorz sandscalp"` |
| Gahz'rilla Freeze trigger | `"gahz'rilla freeze"` |
| Gahz'rilla move away action | `"gahz'rilla move away from freeze"` |

---

## Registration Checklist

- [ ] `playerbot/strategy/generic/DungeonStrategy.cpp` — enter/leave zul'farrak (combat + noncombat)
- [ ] `playerbot/strategy/triggers/TriggerContext.h` — include ZfTriggers.h + all ZF creators
- [ ] `playerbot/strategy/actions/ActionContext.h` — include ZfActions.h + all ZF creators
- [ ] `playerbot/strategy/StrategyContext.h` — include ZfStrategy.h + 8 strategy creators
- [ ] `CMakeLists.txt` — `Ai_Dungeon_ZF` GLOB_RECURSE added + included in LIBRARY_SRCS

---

## Build Status

- [ ] `./build.sh` — clean, no new errors

---

## Definition of Done

- [ ] Build clean
- [ ] Bot enters ZF → instance strategy loads (log: `enable zul'farrak strategy`)
- [ ] Theka the Martyr engaged → fight strategy enables
- [ ] Witch Doctor Zum'rah engaged → fight strategy enables
- [ ] Antu'sul engaged → fight strategy enables
- [ ] Shadowpriest Sezz'ziz engaged → fight strategy enables
- [ ] Sergeant Bly engaged → fight strategy enables
- [ ] Gahz'rilla engaged (if summoned) → gahz'rilla fight strategy enables; bots move >12yd during Freeze
- [ ] Chief Ukorz Sandscalp engaged → fight strategy enables
- [ ] Each boss dies → fight strategy disables
- [ ] Bot leaves ZF → instance strategy unloads (log: `disable zul'farrak strategy`)

---

## Verify Commands

With `LogFileLevel = 3`, grep Server.log for:
```
enable zul'farrak strategy
enable gahz'rilla fight strategy
gahz'rilla freeze
gahz'rilla move away from freeze
disable zul'farrak strategy
```

---

## Spell Reference

| Spell | ID | Radius | Notes |
|-------|----|--------|-------|
| Freeze (Gahz'rilla) | 11836 | ~10yd | Verify ID in spell_template |

---

## Next Step

Implement in order:

1. `ZfTriggers.h`
2. `ZfActions.h`
3. `ZfStrategy.h` + `ZfStrategy.cpp`
4. Four registration edits (DungeonStrategy.cpp, TriggerContext.h, ActionContext.h, StrategyContext.h)
5. `CMakeLists.txt`
6. `./build.sh` verify
