# Ragefire Chasm — Implementation Plan

**Map ID:** 389  
**Levels:** 13–18  
**Status:** 🟡 IN PROGRESS  

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
src/Ai/Dungeon/RagefireChasm/
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

- [x] `src/Ai/Base/generic/DungeonStrategy.cpp` — enter/leave RFC in combat + noncombat
- [x] `src/Ai/Base/triggers/TriggerContext.h` — include + all 9 RFC trigger creators
- [x] `src/Ai/Base/actions/ActionContext.h` — include + all 11 RFC action creators
- [x] `src/Ai/Base/StrategyContext.h` — include + 5 RFC strategy creators
- [x] `CMakeLists.txt` — `Ai_Dungeon_RFC` GLOB_RECURSE added + included in LIBRARY_SRCS

---

## Build Status

- [x] `./build.sh` — clean, no new errors (2026-04-20)

---

## Definition of Done

- [x] Build clean
- [ ] Bot enters RFC → instance strategy loads (verify via strategy debug log)
- [ ] Oggleflint engaged → oggleflint fight strategy enables
- [ ] Taragaman engaged → taragaman fight strategy enables; bots move >12yd during Firenova
- [ ] Jergosh engaged → jergosh fight strategy enables
- [ ] Bazzalan engaged → bazzalan fight strategy enables
- [ ] Each boss dies → fight strategy disables
- [ ] Bot leaves RFC → instance strategy unloads

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

## Next Step

In-game verification run. Enter RFC with a bot group, observe log lines above. Then move to WC (Wailing Caverns, Map 43).
