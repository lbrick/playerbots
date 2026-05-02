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
| 1 | Ragefire Chasm | RFC | 389 | 13–18 | ✅ COMPLETE — full combat run verified 2026-04-28 (Oggleflint not engaged) |
| 2 | Wailing Caverns | WC | 43 | 15–25 | 🟡 MOSTLY VERIFIED — Cobrahn (basic test) + Mutanus (AoE mechanic) pending |
| 3 | The Deadmines | DM | 36 | 17–26 | 🟡 IN PROGRESS |
| 4 | Shadowfang Keep | SFK | 33 | 22–30 | 🟢 ENTER VERIFIED — leave/boss mechanics pending |
| 5 | Blackfathom Deeps | BFD | 48 | 20–30 | 🟡 IN PROGRESS |
| 6 | The Stockade | Stocks | 34 | 24–32 | 🟢 ENTER/LEAVE + BOSS MECHANICS IMPLEMENTED — in-game verify pending |
| 7 | Gnomeregan | Gnomer | 90 | 29–38 | 🟢 ENTER/LEAVE + BOSS MECHANICS IMPLEMENTED — in-game verify pending |
| 8 | Razorfen Kraul | RFK | 47 | 25–38 | 🟢 ENTER/LEAVE + BOSS MECHANICS IMPLEMENTED — in-game verify pending |
| 9 | Scarlet Monastery | SM | 189 | 28–45 | 🟢 ENTER/LEAVE + BOSS MECHANICS IMPLEMENTED — in-game verify pending |
| 10 | Razorfen Downs | RFD | 129 | 35–50 | 🟢 IMPLEMENTED — build verified 2026-05-02; in-game verify pending |
| 11 | Uldaman | Ulda | 70 | 35–45 | 🟢 IMPLEMENTED — build verified 2026-05-02; in-game verify pending |
| 12 | Zul'Farrak | ZF | 209 | 44–54 | 🟢 IMPLEMENTED — build verified 2026-05-02; in-game verify pending |
| 13 | Maraudon | Mara | 349 | 46–55 | 🟢 IMPLEMENTED — build verified 2026-05-02; in-game verify pending |
| 14 | Temple of Atal'Hakkar | ST | 109 | 50–56 | 🟢 IMPLEMENTED — build verified 2026-05-02; in-game verify pending |
| 15 | Blackrock Depths | BRD | 230 | 52–60 | 🟢 IMPLEMENTED — build verified 2026-05-02; in-game verify pending |
| 16 | Lower Blackrock Spire | LBRS | 229 | 55–60 | 📋 PLANNED — see `BlackrockSpire/BRS_PLAN.md` (combined) |
| 17 | Upper Blackrock Spire | UBRS | 229 | 55–60 | 📋 PLANNED — see `BlackrockSpire/BRS_PLAN.md` (combined) |
| 18 | Dire Maul | DM | 429 | 55–60 | 📋 PLANNED — see `DireMaul/DM_PLAN.md` |
| 19 | Stratholme | Strat | 329 | 56–60 | 📋 PLANNED — see `Stratholme/STRAT_PLAN.md` |
| 20 | Scholomance | Scholo | 289 | 57–60 | 📋 PLANNED — see `Scholomance/SCHOLO_PLAN.md` |

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

## RFD Boss Reference

| Boss | NPC ID | Key Mechanic |
|------|--------|-------------|
| Tuten'kash | 7355 | Summons spider adds at 66%/33% HP — no positional AoE |
| Mordresh Fire Eye | 7357 | **Fire Nova** — AoE fire ~10yd around him |
| Glutton | 7354 | Devour (eats zombie mobs to heal) — no positional AoE |
| Amnennar the Coldbringer | 7358 | **Frost Nova** — AoE freeze ~8yd; Frost Bolt Volley (AoE ranged) |

---

## Ulda Boss Reference

| Boss | NPC ID | Key Mechanic |
|------|--------|-------------|
| Revelosh | 6910 | Chain Lightning — no positional AoE |
| Baelog (Lost Dwarves) | 6913 | Trio event (Olaf 6912, Eric 6911) — melee only |
| Ironaya | 7228 | **War Stomp** — AoE physical ~8yd |
| Obsidian Sentinel | 7023 | Stone Tremor — no directional mechanic |
| Ancient Stone Keeper | 4857 | **War Stomp** — AoE physical ~8yd |
| Galgann Firehammer | 7291 | **Fire Nova** — AoE fire ~10yd |
| Grimlok | 4854 | **War Stomp** — AoE physical ~8yd |
| Archaedas | 2748 | **Earth Tremor** — AoE physical ~15yd; spawns Vault Warden adds |

---

## ZF Boss Reference

| Boss | NPC ID | Key Mechanic |
|------|--------|-------------|
| Theka the Martyr | 7272 | Becomes undead mid-fight (damage immunity ~60s) — no positional AoE |
| Witch Doctor Zum'rah | 7271 | Summons undead adds — no positional AoE |
| Antu'sul | 8127 | Summons sandcrawler adds repeatedly — no positional AoE |
| Shadowpriest Sezz'ziz | 7275 | Shadow Word: Pain, Heal — no positional AoE |
| Sergeant Bly (staircase event) | 7604 | Multi-mob event (crew: 7605–7608) — no positional AoE |
| Gahz'rilla | 7273 | **Freeze** — AoE frost ~10yd; Gahz'rilla Slam knockback |
| Chief Ukorz Sandscalp | 7267 | Melee; Ruuzlu (7268) alongside — no positional AoE |

---

## Mara Boss Reference

| Boss | NPC ID | Wing | Key Mechanic |
|------|--------|------|-------------|
| Noxxion | 13282 | Orange | **Noxious Fumes** — AoE poison ~8yd; splits into adds at ~50% |
| Razorlash | 12258 | Orange | Puncture, Cleave (frontal) — no radial AoE |
| Lord Vyletongue | 13280 | Purple | Curse of Blood, Blink (random teleport) — no positional AoE |
| Celebras the Cursed | 12519 | Purple | Wrath, Entangling Roots — no radial AoE |
| Landslide | 12565 | Purple | Knock Away (single-target) — no radial AoE |
| Tinkerer Gizlock | 13601 | Pristine | **Smoke Bomb** — AoE blind ~8yd; Goblin Dragon Gun (frontal cone) |
| Rotgrip | 13596 | Pristine | Thrash, Cleave, Wrench — no positional AoE |
| Princess Theradras | 12201 | Pristine | **Dust Field** — AoE nature ~10yd aura ticking every ~2s; Repulsive Gaze (AoE fear ~15yd) |

---

## Registration Checklist (per dungeon)

Every dungeon requires changes to 5 files outside its own folder:

- [ ] `playerbot/strategy/generic/DungeonStrategy.cpp` — add enter/leave triggers (both combat + noncombat)
- [ ] `playerbot/strategy/triggers/TriggerContext.h` — include header + register all triggers
- [ ] `playerbot/strategy/actions/ActionContext.h` — include header + register all enable/disable actions
- [ ] `playerbot/strategy/StrategyContext.h` — include header + register instance + boss fight strategies
- [ ] `CMakeLists.txt` — **no per-dungeon entry needed**; single `GLOB_RECURSE Playerbot_Dungeons` at line 121 covers all `.cpp/.h` under `dungeons/`. Touch the file after adding new `.cpp` files to force cmake to rescan the glob.

---

## Definition of Done (per dungeon)

- [ ] `./build.sh` clean with no errors or new warnings
- [ ] Bot enters instance — instance strategy loads (verify via strategy debug log)
- [ ] Each boss engaged — boss fight strategy enables (verify log)
- [ ] Each boss dies/resets — boss fight strategy disables (verify log)
- [ ] Bot leaves instance — instance strategy unloads
- [ ] At least one boss-specific mechanic implemented (not all TODO stubs)
- [ ] Legacy RPG and existing strategies unaffected

---

## ST Boss Reference

| Boss | NPC ID | Key Mechanic |
|------|--------|-------------|
| Zolo | 5707 | War Stomp — no major AoE positional |
| Hukku | 5708 | Summons bat adds |
| Gasher | 5714 | Mortal Strike, melee |
| Loro | 5715 | Summons snake adds |
| Mijan | 5709 | Summons fire elemental |
| Zul'Lor | 5710 | Lightning Bolt — no positional AoE |
| Jammal'an the Prophet | 5710 | Hex (polymorph), Oracle's Touch — no positional AoE |
| Ogom the Wretched | 5711 | Melee add |
| Morphaz | 5712 | Wing Buffet (frontal), Frostbolt Volley — frontal deferred |
| Hazzas | 5713 | **Flame Breath** (frontal cone) — frontal deferred |
| Shade of Eranikus | 5709 | **War Stomp** ~8yd AoE physical |
| Avatar of Hakkar | 8313 | Corrupted Blood AoE DoT, mind control — quest-gated |

> ⚠ Multiple NPC IDs in the 5707–5715 range likely conflict. Verify all in DB before implementation.

---

## BRD Boss Reference

| Boss | NPC ID | Key Mechanic |
|------|--------|-------------|
| Gorosh the Dervish | 9027 | Sweeping Strikes — no radial AoE |
| Grizzle | 9023 | **Ground Tremor** ~10yd AoE stun |
| Eviscerator | 9024 | **Whirlwind** ~8yd AoE |
| Ok'thor the Breaker | 9026 | **War Stomp** ~8yd AoE |
| Anub'shiah | 9028 | Curse of Blood — no positional AoE |
| Hedrum the Creeper | 9029 | Poison Bolt Volley (ranged AoE) |
| High Interrogator Gerstahn | 9018 | Psychic Scream (AoE fear) — break strategy handles |
| Lord Roccor | 9025 | **Earthquake** ~10yd AoE |
| Houndmaster Grebmar | 9319 | Summons hound packs |
| Pyromancer Loregrain | 9024 | **Fire Nova** ~10yd AoE fire |
| Warder Stilgiss | 9017 | **Frost Nova** ~8yd AoE freeze |
| Golem Lord Argelmach | 8983 | **Static Field** ~8yd AoE nature |
| Bael'Gar | 9016 | **Fire Nova** ~10yd AoE fire |
| Magmus | 9938 | **War Stomp** ~8yd AoE |
| Emperor Dagran Thaurissan | 9019 | Hand of Thaurissan aura — healer handles |

---

## BRS Boss Reference (LBRS + UBRS, Map 229)

| Boss | NPC ID | Wing | Key Mechanic |
|------|--------|------|-------------|
| Highlord Omokk | 9196 | LBRS | **War Stomp** ~8yd AoE |
| Shadow Hunter Vosh'gajin | 9218 | LBRS | Hex polymorph — no positional AoE |
| War Master Voone | 9237 | LBRS | Cleave, Mortal Strike — no radial AoE |
| Mother Smolderweb | 10596 | LBRS | Web, summons Daughter adds |
| Urok Doomhowl | 10584 | LBRS | **War Stomp** ~8yd; ogre event spawn |
| Quartermaster Zigris | 9736 | LBRS | Gouge, Shoot — no positional AoE |
| Halycon | 10220 | LBRS | Howl AoE fear — break strategy handles |
| Overlord Wyrmthalak | 9568 | LBRS | **Blizzard** ~10yd AoE cold + War Stomp |
| Pyroguard Emberseer | 9816 | UBRS | **Ignite** ~8yd AoE fire aura |
| Solakar Flamewreath | 10264 | UBRS | Whelp wave event — melee only |
| Jed Runewatcher | 10509 | UBRS | Arcane Missiles — rare spawn, no AoE |
| The Beast | 10430 | UBRS | **Conflagration** ~10yd AoE fire burst |
| General Drakkisath | 10363 | UBRS | **Conflagration** ~8yd AoE fire cone |

---

## DM Boss Reference (3 wings, Map 429)

| Boss | NPC ID | Wing | Key Mechanic |
|------|--------|------|-------------|
| Zevrim Thornhoof | 11490 | East | Sacrifice (lifts player) — no radial AoE |
| Hydrospawn | 13280 | East | Tidal Wave knockback — single target |
| Lethtendris | 14327 | East | Drain Mana — no positional AoE |
| Alzzin the Wildshaper | 11492 | East | **Earthgrip** ~10yd AoE root |
| Tendris Warpwood | 11489 | West | **Entangle** ~8yd AoE root |
| Illyanna Ravenoak | 11488 | West | Strafe (frontal sweep) — deferred |
| Magister Kalendris | 11487 | West | Dominate Mind — no positional AoE |
| Immol'thar | 11496 | West | **Disease Cloud** ~10yd persistent AoE |
| Prince Tortheldrin | 11486 | West | **Arcane Blast** ~8yd AoE |
| Guard Mol'dar | 14326 | North | **War Stomp** ~8yd AoE |
| Stomper Kreeg | 14322 | North | **Knock Away** ~8yd AoE knockback |
| Guard Fengus | 14321 | North | Cleave — no radial AoE |
| Guard Slip'kik | 14323 | North | **Frost Nova** ~8yd AoE freeze |
| Captain Kromcrush | 14325 | North | **War Stomp** ~8yd AoE |
| King Gordok | 11501 | North | **Thunderclap** ~8yd AoE physical |

---

## Strat Boss Reference

| Boss | NPC ID | Side | Key Mechanic |
|------|--------|------|-------------|
| Hearthsinger Forresten | 16779 | Scarlet | Song of Siren (AoE sleep) — rare, break strategy |
| Timmy the Cruel | 10808 | Scarlet | Cleave, Frenzy — rare, no radial AoE |
| Cannon Master Willey | 10811 | Scarlet | Cannon AoE ground fire — GO trigger deferred |
| Archivist Galford | 10812 | Scarlet | **Flame Buffet** ~8yd AoE fire |
| Balnazzar | 10813 | Scarlet | **Thunderclap** ~8yd AoE; Psychic Scream (fear) |
| Magistrate Barthilas | 10435 | Undead | Hammer of Justice stun — no radial AoE |
| Maleki the Pallid | 10438 | Undead | **Frost Nova** ~8yd AoE freeze |
| Ramstein the Gorger | 10439 | Undead | **Trample** ~8yd AoE physical |
| Baron Rivendare | 10440 | Undead | **Unholy Aura** ~10yd persistent shadow AoE |

---

## Scholo Boss Reference

| Boss | NPC ID | Key Mechanic |
|------|--------|-------------|
| Kirtonos the Herald | 10506 | **Blood Offering** ~8yd AoE shadow burst |
| Jandice Barov | 10503 | Illusion copies — no positional AoE |
| Rattlegore | 11622 | Mortal Strike, Sunder — no radial AoE |
| Marduk Blackpool | 10433 | Rain of Fire (ground-placed) — healer handles |
| Vectus | 10432 | **Blizzard** ~10yd AoE frost ground |
| Ras Frostwhisper | 10508 | **Frost Nova** ~8yd AoE freeze |
| Instructor Malicia | 10505 | **Poison Nova** ~10yd AoE poison |
| Doctor Theolen Krastinov | 11261 | Infection stacking disease — no radial AoE |
| The Ravenian | 11439 | **Trample** ~8yd AoE physical |
| Lord Alexei Barov | 10504 | Dominate Mind — no positional AoE |
| Lady Illucia Barov | 10502 | Silence, Curse of Agony — no positional AoE |
| Darkmaster Gandling | 1853 | Curse of Dissolution (AoE on expiry — dispel handles primary) |
