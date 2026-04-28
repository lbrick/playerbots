# Ragefire Chasm — Implementation Plan

**Map ID:** 389  
**Levels:** 13–18  
**Status:** 🟢 COMPLETE — full combat run verified 2026-04-28 (Oggleflint not engaged this run)  

---

## Boss Reference

| Boss | NPC ID | Mechanic | Implemented |
|------|--------|----------|-------------|
| Oggleflint | 11517 | None — simple melee | ✅ start/end triggers |
| Taragaman the Hungerer | 11520 | **Firenova** AoE ~10yd | ✅ CloseToHostileCreatureHazardTrigger + MoveAwayFromCreature (12yd) |
| Jergosh the Invoker | 11518 | Immolate / Curse of Weakness — handled by cure strategy | ✅ start/end triggers |
| Bazzalan | 11519 | Sinister Strike, Poison DoT — handled by cure strategy | ✅ start/end triggers |

---

## Files Created

```
playerbot/strategy/dungeons/RagefireChasm/
  Action/
    RfcActions.h       — instance + all 4 boss enable/disable + Taragaman MoveAway
  Trigger/
    RfcTriggers.h      — instance enter/leave + all 4 boss start/end + Taragaman firenova
  Strategy/
    RfcStrategy.h      — class declarations
    RfcStrategy.cpp    — all strategy initializers
  RFC_PLAN.md          — this file
```

## Registration (all complete)

- [x] `playerbot/strategy/generic/DungeonStrategy.cpp` — enter/leave RFC in combat + noncombat
- [x] `playerbot/strategy/triggers/TriggerContext.h` — include + all 9 RFC trigger creators
- [x] `playerbot/strategy/actions/ActionContext.h` — include + all 11 RFC action creators
- [x] `playerbot/strategy/StrategyContext.h` — include + 5 RFC strategy creators
- [x] `CMakeLists.txt` — `Ai_Dungeon_RFC` GLOB_RECURSE added + included in LIBRARY_SRCS

---

## Build Status

- [x] `./build.sh` — clean, no new errors (2026-04-20)

---

## Definition of Done

- [x] Build clean
- [x] Bot enters RFC → instance strategy loads (verified 2026-04-23 with Trollman + Tultso)
- [ ] Oggleflint engaged → oggleflint fight strategy enables *(not engaged in 2026-04-28 run — skipped or not pathed)*
- [x] Taragaman engaged → taragaman fight strategy enables; bots move >12yd during Firenova (verified 2026-04-28: all 4 bots enabled, 3+ successful move-away actions; Yimech died on final Firenova avoidance attempt)
- [x] Jergosh engaged → jergosh fight strategy enables (verified 2026-04-28: all 4 bots enabled + disabled post-kill)
- [x] Bazzalan engaged → bazzalan fight strategy enables (verified 2026-04-28: all 4 bots enabled + disabled post-kill)
- [x] Each boss dies → fight strategy disables (verified 2026-04-28: Taragaman, Jergosh, Bazzalan all disabled)
- [x] Bot leaves RFC → instance strategy unloads (verified 2026-04-23 with Trollman + Tultso)

---

## Verify Commands

With `LogFileLevel = 3`, grep Server.log for:
```
enable ragefire chasm strategy
enable taragaman fight strategy
taragaman move away from firenova
disable taragaman fight strategy
```

---

## Verified Runtime Notes

### 2026-04-23 — Enter/Leave only
- `04:09:39` Trollman entered RFC instance 3.
- `04:09:42` Tultso entered RFC instance 3.
- `04:09:47` `Bot Tultso: dungeon strategy action [enable ragefire chasm strategy]`
- `04:11:00` `Bot Tultso: dungeon strategy action [disable ragefire chasm strategy]`

### 2026-04-28 — Full combat run (instance 4, ~12.5 min)
- Party: Trollman (player) + Garec, Tisi, Eston, Yimech (bots)
- `07:09:00` All 4 bots entered, RFC strategy enabled
- `07:14:08` All 4 bots enabled taragaman fight strategy
- `07:14:16–07:14:38` Multiple `taragaman move away from firenova - OK` actions
- `07:14:34` Yimech died (final Firenova avoidance attempt returned IMPOSSIBLE — likely out of pathing options)
- `07:14:39` Taragaman disabled; `DungeonPersistentState` confirmed kill at `07:14:50`
- `07:16:02` All 4 bots enabled jergosh fight strategy; disabled post-kill at `07:16:30–07:16:49`; confirmed kill `07:16:30`
- `07:17:49` All 4 bots enabled bazzalan fight strategy; disabled post-kill at `07:18:25`; confirmed kill `07:18:21`
- `07:21:23–07:21:27` All bots exited, RFC strategy disabled; instance unloaded `07:21:39`
- **Oggleflint not engaged** — no fight strategy events, not in DungeonPersistentState

## Next Step

Verify Oggleflint fight strategy triggers by engaging Oggleflint at start of a future run.
