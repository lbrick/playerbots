# Temple of Atal'Hakkar (Sunken Temple) — Implementation Plan

**Map ID:** 109  
**Levels:** 50–56  
**Status:** ⬜ TODO  

> **NPC IDs:** ALL IDs here are approximate — verify every entry with `SELECT entry, name FROM creature_template WHERE name LIKE '%...%'` against classicmangos DB before wiring triggers.

---

## Boss Reference

### Lower Ring (6 troll mini-bosses — kill all to unlock Jammal'an's altar)

| Boss | NPC ID | Mechanic | Trigger Type | Action |
|------|--------|----------|--------------|--------|
| Zolo | 5707 | War Stomp, Fireblast. No radial AoE of concern. | None — start/end only | — |
| Hukku | 5708 | Summons bat adds. No positional AoE. | None — start/end only | — |
| Gasher | 5714 | Mortal Strike, melee. No positional AoE. | None — start/end only | — |
| Loro | 5715 | Summons snake adds. No positional AoE. | None — start/end only | — |
| Mijan | 5709 | Summons fire elemental. No positional AoE. | None — start/end only | — |
| Zul'Lor | 5710 | Lightning Bolt, Chain Lightning. No positional AoE. | None — start/end only | — |

> **All six mini-bosses must die to open the altar and spawn Jammal'an.** Verify all NPC IDs in DB — the six troll IDs are tightly clustered and easily mis-mapped.

### Upper Temple

| Boss | NPC ID | Mechanic | Trigger Type | Action |
|------|--------|----------|--------------|--------|
| Jammal'an the Prophet | 5710 | Hex of Jammal'an (random polymorph), Oracle's Touch. No positional AoE. | None — start/end only | — |
| Ogom the Wretched | 5711 | Melee add alongside Jammal'an. No positional AoE. | None — start/end only | — |
| Morphaz | 5712 | **Wing Buffet** (frontal knockback cone), Frostbolt Volley (AoE ranged). Frontal cone detection deferred — start/end only for now. | None — start/end only | — |
| Hazzas | 5713 | **Flame Breath** (frontal fire cone ~8yd), Wing Buffet. Frontal cone detection deferred. | None — start/end only | — |
| Shade of Eranikus | 5709 | **War Stomp** (~8yd AoE physical), Deep Slumber (sleep), Tail Swipe (behind). War Stomp = primary mechanic. | `CloseToHostileCreatureHazardTrigger(5709, 8, 3)` | `MoveAwayFromCreature(5709, 10)` |
| Avatar of Hakkar | 8313 | Cause Insanity (mind control), Corrupted Blood (AoE DoT debuff). Quest-gated boss — may not be present. Healing strategy handles Corrupted Blood. | None — start/end only | — |

> **Morphaz + Hazzas frontal cones:** Both have directional breath/buffet attacks. A future enhancement can add `MoveBehindCreature` once a frontal-cone trigger base class exists. Deferred for now.
>
> **Avatar of Hakkar:** Only spawns if a player has completed the Essence of Eranikus questline. Register the fight strategy regardless — it simply never triggers if the Avatar isn't summoned.
>
> **Jammal'an NPC ID collision:** Jammal'an (5710) may conflict with Zul'Lor (5710 above). Verify both in DB — one of those IDs is wrong. This is the most likely error in the plan.

---

## Files to Create

```
playerbot/strategy/dungeons/TempleOfAtalHakkar/
  Action/
    StActions.h        — instance + 11 boss enable/disable + Eranikus MoveAway
  Trigger/
    StTriggers.h       — instance enter/leave + 11 boss start/end + Eranikus War Stomp
  Strategy/
    StStrategy.h       — class declarations
    StStrategy.cpp     — all strategy initializers
  ST_PLAN.md           — this file
```

---

## Strategy String Names

| Thing | String |
|-------|--------|
| Instance strategy | `"temple of atal'hakkar"` |
| Enter trigger | `"enter temple of atal'hakkar"` |
| Leave trigger | `"leave temple of atal'hakkar"` |
| Zolo fight | `"zolo"` |
| Hukku fight | `"hukku"` |
| Gasher fight | `"gasher"` |
| Loro fight | `"loro"` |
| Mijan fight | `"mijan"` |
| Zul'Lor fight | `"zul'lor"` |
| Jammal'an fight | `"jammal'an the prophet"` |
| Ogom fight | `"ogom the wretched"` |
| Morphaz fight | `"morphaz"` |
| Hazzas fight | `"hazzas"` |
| Shade of Eranikus fight | `"shade of eranikus"` |
| Avatar of Hakkar fight | `"avatar of hakkar"` |
| Eranikus War Stomp trigger | `"eranikus war stomp"` |
| Eranikus move away action | `"eranikus move away from war stomp"` |

---

## Registration Checklist

- [ ] `playerbot/strategy/generic/DungeonStrategy.cpp` — enter/leave temple of atal'hakkar (combat + noncombat)
- [ ] `playerbot/strategy/triggers/TriggerContext.h` — include StTriggers.h + all ST creators
- [ ] `playerbot/strategy/actions/ActionContext.h` — include StActions.h + all ST creators
- [ ] `playerbot/strategy/StrategyContext.h` — include StStrategy.h + 15 strategy creators
- [ ] `CMakeLists.txt` — `Ai_Dungeon_ST` GLOB_RECURSE added + included in LIBRARY_SRCS

---

## Build Status

- [ ] `./build.sh` — clean, no new errors

---

## Definition of Done

- [ ] Build clean
- [ ] Bot enters ST → instance strategy loads (log: `enable temple of atal'hakkar strategy`)
- [ ] Each of the 6 lower-ring trolls engaged → fight strategies enable
- [ ] Jammal'an engaged → jammal'an fight strategy enables
- [ ] Shade of Eranikus engaged → fight strategy enables; bots move >10yd during War Stomp
- [ ] Each boss dies → fight strategy disables
- [ ] Bot leaves ST → instance strategy unloads (log: `disable temple of atal'hakkar strategy`)

---

## Verify Commands

```
enable temple of atal'hakkar strategy
enable shade of eranikus fight strategy
eranikus war stomp
eranikus move away from war stomp
disable temple of atal'hakkar strategy
```

---

## Spell Reference

| Spell | ID | Radius | Notes |
|-------|----|--------|-------|
| War Stomp (Eranikus) | 11876 | ~8yd | Verify ID |
| Flame Breath (Hazzas) | — | frontal cone | Deferred — no base trigger class yet |
| Wing Buffet (Morphaz/Hazzas) | — | frontal | Deferred |

---

## Next Step

1. Verify all NPC IDs in DB (especially lower-ring trolls — IDs likely off)
2. `StTriggers.h`
3. `StActions.h`
4. `StStrategy.h` + `StStrategy.cpp`
5. Four registration edits
6. `CMakeLists.txt`
7. `./build.sh` verify
