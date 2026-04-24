# Classic Dungeon Implementation Plan

**Target:** cmangos-playerbots `playerbot/strategy/dungeons/`  
**Reference implementation:** AC playerbots WotLK dungeons (`azerothcore-playerbots/src/Ai/Dungeon/`)  
**Boss research:** https://www.wowhead.com/classic/guide/ragefire-chasm-dungeon-strategy-wow-classic  
  (Replace `ragefire-chasm` with the dungeon slug for any other dungeon)

---

## Scope

Each dungeon implementation gives bots awareness of boss-specific mechanics: AoE avoidance,
dispel prioritisation, positioning, and enabling/disabling per-boss strategies as encounters
begin and end. Standard combat (healing, threat, DPS rotation) is handled by existing class
strategies — dungeons only layer on top.

---

## Dungeon Roster — Classic (Vanilla)

Priority order: low-level first, then by dungeon tier.  
Map IDs from `worlddb > instance_template > map` or https://wow.tools/dbc/?dbc=map&build=1.12.1.5875

| # | Dungeon | Short | Map ID | Levels | Status |
|---|---------|-------|--------|--------|--------|
| 1 | Ragefire Chasm | RFC | 389 | 13–18 | 🟢 ENTER/LEAVE VERIFIED — boss mechanics pending |
| 2 | Wailing Caverns | WC | 43 | 15–25 | 🟡 IN PROGRESS |
| 3 | The Deadmines | DM | 36 | 17–26 | 🟡 IN PROGRESS |
| 4 | Shadowfang Keep | SFK | 33 | 22–30 | 🟢 ENTER VERIFIED — leave/boss mechanics pending |
| 5 | Blackfathom Deeps | BFD | 48 | 20–30 | 🟡 IN PROGRESS |
| 6 | The Stockade | Stocks | 34 | 24–32 | ⬜ TODO |
| 7 | Gnomeregan | Gnomer | 90 | 29–38 | ⬜ TODO |
| 8 | Razorfen Kraul | RFK | 47 | 25–38 | 🟡 PLANNED — see RazorfenKraul/RFK_PLAN.md |
| 9 | Scarlet Monastery | SM | 189 | 28–45 | ⬜ TODO |
| 10 | Razorfen Downs | RFD | 129 | 35–50 | ⬜ TODO |
| 11 | Uldaman | Ulda | 70 | 35–45 | ⬜ TODO |
| 12 | Zul'Farrak | ZF | 209 | 44–54 | ⬜ TODO |
| 13 | Maraudon | Mara | 349 | 46–55 | ⬜ TODO |
| 14 | Temple of Atal'Hakkar | ST | 109 | 50–56 | ⬜ TODO |
| 15 | Blackrock Depths | BRD | 230 | 52–60 | ⬜ TODO |
| 16 | Lower Blackrock Spire | LBRS | 229 | 55–60 | ⬜ TODO |
| 17 | Upper Blackrock Spire | UBRS | 229 | 55–60 | ⬜ TODO |
| 18 | Dire Maul | DM | 429 | 55–60 | ⬜ TODO |
| 19 | Stratholme | Strat | 329 | 56–60 | ⬜ TODO |
| 20 | Scholomance | Scholo | 289 | 57–60 | ⬜ TODO |

> **Note — LBRS/UBRS share map ID 229.** Use the same Enter/Leave triggers;
> distinguish wings by boss NPC IDs in each fight strategy.
>
> **Note — Scarlet Monastery has 4 wings** (Graveyard, Library, Armory, Cathedral)
> all on map 189. One instance strategy covers all wings; boss fight strategies
> differentiate individual bosses.

---

## RFC Boss Reference

| Boss | NPC ID | Key Mechanic |
|------|--------|-------------|
| Oggleflint | 11517 | Simple melee — no special mechanic |
| Taragaman the Hungerer | 11520 | **Firenova** — AoE fire ~10yd around him |
| Jergosh the Invoker | 11518 | Immolate (fire DoT), Curse of Weakness |
| Bazzalan | 11519 | Sinister Strike, Poison DoT |

---

## Registration Checklist (per dungeon)

Every dungeon requires changes to 5 files outside its own folder:

- [ ] `playerbot/strategy/generic/DungeonStrategy.cpp` — add enter/leave triggers (both combat + noncombat)
- [ ] `playerbot/strategy/triggers/TriggerContext.h` — include header + register all triggers
- [ ] `playerbot/strategy/actions/ActionContext.h` — include header + register all enable/disable actions
- [ ] `playerbot/strategy/StrategyContext.h` — include header + register instance + boss fight strategies
- [ ] `CMakeLists.txt` — add explicit `GLOB_RECURSE Ai_Dungeon_XXX` entry for the new dungeon (each dungeon has its own entry; check existing entries around line 79 as the pattern)

---

## Definition of Done (per dungeon)

- [ ] `./build.sh` clean with no errors or new warnings
- [ ] Bot enters instance — instance strategy loads (verify via strategy debug log)
- [ ] Each boss engaged — boss fight strategy enables (verify log)
- [ ] Each boss dies/resets — boss fight strategy disables (verify log)
- [ ] Bot leaves instance — instance strategy unloads
- [ ] At least one boss-specific mechanic implemented (not all TODO stubs)
- [ ] Legacy RPG and existing strategies unaffected
