# Classic / TBC Raid Implementation Plan

**Target:** cmangos-playerbots `playerbot/strategy/raid/`  
**Guide:** `RAID_GUIDE.md` in this directory

---

## Raid Roster — Classic (Vanilla, Level 60)

Map IDs from `worlddb > instance_template > map`.

| # | Raid | Short | Map ID | Size | Status |
|---|------|-------|--------|------|--------|
| 1 | Onyxia's Lair | Ony | 249 | 40 | 🟡 CODED — boss triggers/mechanics present, in-game verify pending |
| 2 | Molten Core | MC | 409 | 40 | 🟡 CODED — multi-boss triggers/AoE mechanics present, in-game verify pending |
| 3 | Blackwing Lair | BWL | 469 | 40 | 🟡 CODED — triggers.cpp present (complex impl), in-game verify pending |
| 4 | Zul'Gurub | ZG | 309 | 20 | 📋 PLANNED — see ZG Boss Reference below |
| 5 | Ruins of Ahn'Qiraj | AQ20 | 509 | 20 | 📋 PLANNED — see AQ20 Boss Reference below |
| 6 | Temple of Ahn'Qiraj | AQ40 | 531 | 40 | 📋 PLANNED — see AQ40 Boss Reference below |
| 7 | Naxxramas | Naxx | 533 | 40 | 🔴 SKELETON — enter/leave triggers only, no boss mechanics |

---

## Raid Roster — The Burning Crusade (Level 70)

| # | Raid | Short | Map ID | Size | Status |
|---|------|-------|--------|------|--------|
| 8 | Karazhan | Kara | 532 | 10 | 🟡 CODED — triggers.cpp + actions.cpp present, in-game verify pending |
| 9 | Gruul's Lair | Gruul | 565 | 25 | 📋 PLANNED |
| 10 | Magtheridon's Lair | Mag | 544 | 25 | 📋 PLANNED |
| 11 | Serpentshrine Cavern | SSC | 548 | 25 | 📋 PLANNED |
| 12 | Tempest Keep: The Eye | TK | 550 | 25 | 📋 PLANNED |
| 13 | Battle for Mount Hyjal | Hyjal | 534 | 25 | 📋 PLANNED |
| 14 | Black Temple | BT | 564 | 25 | 📋 PLANNED |
| 15 | Zul'Aman | ZA | 568 | 10 | 📋 PLANNED |
| 16 | Sunwell Plateau | SWP | 580 | 25 | 📋 PLANNED |

---

## Status Key

| Icon | Meaning |
|------|---------|
| ✅ COMPLETE | Build clean + full combat run verified in-game |
| 🟡 CODED | Files exist with real mechanics, in-game verify pending |
| 🔴 SKELETON | Files exist but boss mechanics are stubs/missing |
| 📋 PLANNED | No implementation yet |

---

## ZG Boss Reference

**Wowhead:** https://www.wowhead.com/classic/guide/wow-classic-zulgurub-overview#overview-of-bosses  
**Map ID:** 309 | **Size:** 20-player

| Boss | NPC ID | Key Mechanic |
|------|--------|-------------|
| High Priestess Jeklik | 14517 | **Swarm** (bats) + **Shadow Word: Pain** — no radial AoE |
| High Priest Venoxis | 14507 | **Holy Nova** ~8yd AoE holy; serpent form |
| High Priestess Mar'li | 14510 | **Web Spray** frontal AoE; spider adds |
| Bloodlord Mandokir | 11382 | **Whirlwind** ~8yd AoE; mounts raptor (speed) |
| Edge of Madness (4 optional) | various | varies per active boss |
| High Priest Thekal | 14509 | Tiger form: **Tiger's Fury** frontal; add phase |
| High Priestess Arlokk | 14515 | **Panther** form; Mark of Arlokk (aggro transfer) |
| Jin'do the Hexxer | 11380 | **Hex** (MC); **Brain Wash Totem** |
| Hakkar the Soulflayer | 14834 | **Corrupted Blood** AoE DoT; **Enervate** |

> High priority boss: **Hakkar** — Corrupted Blood is a raid-wide AoE DoT that requires
> spreading mechanics. Consider implementing first as ZG's canonical AoE mechanic.

---

## AQ20 Boss Reference

**Wowhead:** https://www.wowhead.com/classic/guide/wow-classic-ruins-of-ahnqiraj-overview#overview-of-bosses  
**Map ID:** 509 | **Size:** 20-player

| Boss | NPC ID | Key Mechanic |
|------|--------|-------------|
| Kurinnaxx | 15348 | **Sand Trap** ground GO ~8yd; **Mortal Wound** stacking |
| General Rajaxx | 15341 | Wave event; **Thunderclap** ~8yd AoE |
| Moam | 15340 | **Static Charge** (~8yd AoE); mana drain |
| Buru the Gorger | 15370 | Egg AoE mechanic (run eggs to boss) |
| Ayamiss the Hunter | 15369 | **Paralyze** (ground-target); air phase |
| Ossirian the Unscarred | 15339 | **War Stomp** ~10yd AoE; Crystal vulnerability |

---

## AQ40 Boss Reference

**Wowhead:** https://www.wowhead.com/classic/guide/wow-classic-temple-of-ahnqiraj-overview#overview-of-bosses  
**Map ID:** 531 | **Size:** 40-player

| Boss | NPC ID | Key Mechanic |
|------|--------|-------------|
| The Prophet Skeram | 15263 | **Earth Shock** ~10yd AoE; splits at 75%/50%/25% |
| Silithid Royalty (Kri/Vem/Yauj) | 15276/15275/15274 | Three-boss event; Vem charge knockback |
| Battleguard Sartura | 15516 | **Whirlwind** ~8yd AoE; rotates randomly |
| Fankriss the Unyielding | 15510 | Spawn adds; **Mortal Wound** stacking |
| Viscidus | 15299 | Frost slowdown mechanic — special class reqs |
| Princess Huhuran | 15509 | **Wyvern Sting** targeted AoE; enrage at 30% |
| Twin Emperors (Vek'lor/Vek'nilash) | 15276/15275 | Tank swap mechanic; **Arcane Burst** ~10yd |
| Ouro | 15517 | **Sweep** frontal AoE; submerge phase |
| C'Thun | 15727 | **Eye Beam** targeted; **Dark Glare** frontal; Tentacles |

---

## Registration Checklist (per raid)

Every raid requires changes to 5 files outside its own folder:

- [ ] `playerbot/strategy/generic/DungeonStrategy.cpp` — add enter/leave triggers (both combat + noncombat)
- [ ] `playerbot/strategy/triggers/TriggerContext.h` — include header + register all triggers
- [ ] `playerbot/strategy/actions/ActionContext.h` — include header + register all enable/disable actions
- [ ] `playerbot/strategy/StrategyContext.h` — include header + register instance + boss fight strategies
- [ ] `CMakeLists.txt` — add `GLOB_RECURSE Ai_<RaidName>` entry (see existing raid entries as pattern)

---

## Definition of Done (per raid)

- [ ] `./build.sh` clean with no errors or new warnings
- [ ] Bot enters raid — instance strategy loads (verify via strategy debug log)
- [ ] Each boss engaged — boss fight strategy enables (verify log)
- [ ] Each boss dies/resets — boss fight strategy disables (verify log)
- [ ] Bot leaves instance — instance strategy unloads
- [ ] At least one boss-specific positional mechanic implemented per boss that has one
- [ ] Existing strategies unaffected (no regressions)
