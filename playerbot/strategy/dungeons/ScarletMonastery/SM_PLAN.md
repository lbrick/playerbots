# Scarlet Monastery — Implementation Plan

**Map ID:** 189  
**Levels:** 28–45  
**Status:** ⬜ TODO  
**NPC IDs:** verified against `classicmangos.creature_template` and `instance_template` (2026-04-24)

---

## Resume Protocol

At session start: scan for first `[ ]` — that is the resume point. Mark `[x]` as each step is confirmed done.

---

## Scope

Follow the shared dungeon workflow in `cmangos-playerbots/playerbot/strategy/dungeons/DUNGEON_GUIDE.md`:

- add one instance strategy for Scarlet Monastery (covers all 4 wings — they share map 189)
- add one fight strategy per boss
- only layer boss-specific mechanics on top of existing class combat logic
- keep v1 conservative; custom positioning deferred unless in-game evidence requires it

Recommended delivery split:

- **Pass 1:** full dungeon scaffolding + all start/end boss strategies
- **Pass 2:** mechanics that map cleanly onto existing reusable triggers/actions
- **Stretch only if needed:** Mograine/Whitemane resurrection sequence positioning

---

## Boss Reference

> ✅ NPC IDs and map ID verified against local classicmangos DB (2026-04-24)

### Wing: Graveyard (levels 28–32)

| Boss | NPC ID | Key Mechanic | Bot Action Needed |
|------|--------|-------------|------------------|
| Interrogator Vishas | 3983 | Stinging Trauma (DoT); otherwise straightforward | start/end triggers only |
| Fallen Champion | 6488 | Undead; Mortal Strike | start/end triggers only |
| Ironspine | 6489 | Undead; Spine Crack (armor reduce) | start/end triggers only |
| Bloodmage Thalnos | 4543 | Shadowbolt Volley (AoE ~20yd), Fire Nova Totem | **AoE avoidance** for Shadowbolt Volley in v1 |

### Wing: Library (levels 29–38)

| Boss | NPC ID | Key Mechanic | Bot Action Needed |
|------|--------|-------------|------------------|
| Houndmaster Loksey | 3974 | Releases 4 hounds on engage; Blood Fury self-buff | start/end triggers only in v1; hound add focus is stretch |
| Arcanist Doan | 6487 | Arcane Explosion (AoE ~30yd pulsing when low HP), Polymorph, Silence | **AoE avoidance** for Arcane Explosion; Silence handled by existing cure |

### Wing: Armory (levels 32–40)

| Boss | NPC ID | Key Mechanic | Bot Action Needed |
|------|--------|-------------|------------------|
| Herod | 3975 | Whirlwind (frontal cleave ~8yd); spawns Scarlet Trainees on death | **Move away from Whirlwind** in v1; trainee add focus is stretch |

### Wing: Cathedral (levels 35–45)

| Boss | NPC ID | Key Mechanic | Bot Action Needed |
|------|--------|-------------|------------------|
| Scarlet Commander Mograine | 3976 | Holy Strike, Retribution Aura; killed by Whitemane then resurrected | start/end triggers only — resurrection handled by fight sequence (see notes) |
| High Inquisitor Whitemane | 3977 | Heal cast (must be interrupted), Mass Mind Control (must dispel), Deep Sleep | **Interrupt heal** if spell ID verified; Deep Sleep handled by existing stun-break; Mass Mind Control requires dispel coordination (stretch) |
| High Inquisitor Fairbanks | 4542 | Bonus optional boss; Fear, DoTs | start/end triggers only |

---

## Mechanic Notes

**Bloodmage Thalnos — Shadowbolt Volley**
- Best Graveyard candidate for a real mechanic.
- AoE fired in a wide arc. Use `CloseToHostileCreatureHazardTrigger` at ~22yd radius.
- Fire Nova Totem spawns a GO; add a `CloseToGameObjectHazardTrigger` if GO ID is found.

**Arcanist Doan — Arcane Explosion**
- Fires when Doan reaches low HP. Very wide AoE (~30yd).
- Use `CloseToHostileCreatureHazardTrigger` at ~32yd. Large safe range needed — bots must spread significantly.

**Herod — Whirlwind**
- Frontal-ish cleave. Not a full 360° AoE but close-range melee bots take heavy damage.
- Use `CloseToHostileCreatureHazardTrigger` at ~10yd, `MoveAwayFromCreature` at 12.0f safe range.
- Death adds (Scarlet Trainees): v1 relies on existing multi-target combat. Revisit if bots ignore the wave.

**Mograine + Whitemane — Resurrection Sequence**
- Mograine dies → Whitemane enters, resurrects Mograine, both fight simultaneously.
- The fight has two phases but both bosses share the same map encounter.
- v1: two independent start/end strategies (one per NPC). The resurrection is handled by server scripting — bots see Mograine re-enter combat and `StartBossFightTrigger` fires again.
- Custom phase detection is stretch; do not force it into v1.

**High Inquisitor Whitemane — Heal Interrupt**
- Best Cathedral candidate for a real mechanic.
- Verify her heal spell name and ID before promising the interrupt trigger.
- `Mass Mind Control` is dangerous but requires group coordination; defer to v2.

---

## Files to Create

```
playerbot/strategy/dungeons/ScarletMonastery/
  Action/
    SmActions.h
  Trigger/
    SmTriggers.h
  Strategy/
    SmStrategy.h
    SmStrategy.cpp
  SM_PLAN.md        ← this file
```

---

## Pre-Code Checklist

- [x] Verify all boss NPC IDs against classicmangos DB
- [x] Confirm map ID 189 in `instance_template`
- [ ] Verify Whitemane heal spell name and ID before including interrupt trigger in v1
- [ ] Check for Bloodmage Thalnos Fire Nova Totem GO ID if AoE GO trigger is desired
- [ ] Decide whether Whirlwind trigger should be 360° hazard or frontal-only
- [ ] Decide whether Arcanist Doan Polymorph break belongs in v1 or is handled by existing cure strategy
- [ ] Decide whether Mograine resurrection phase needs custom detection in v1 or relies on stock re-engage

## Pre-Code DB Queries

```sql
SELECT entry, name FROM creature_template
WHERE name IN (
  'Interrogator Vishas', 'Fallen Champion', 'Ironspine', 'Bloodmage Thalnos',
  'Houndmaster Loksey', 'Arcanist Doan',
  'Herod',
  'Scarlet Commander Mograine', 'High Inquisitor Whitemane', 'High Inquisitor Fairbanks'
);

SELECT map FROM instance_template WHERE map = 189;

-- Whitemane heal spell (verify name/rank before wiring interrupt):
SELECT id, name, rank FROM spell_template WHERE name LIKE '%Whitemane%' OR name LIKE '%Lesser Heal%' LIMIT 20;
```

---

## Planned Trigger List

| Trigger string | Class | Notes |
|----------------|-------|-------|
| `enter scarlet monastery` | `ScarletMonasteryEnterDungeonTrigger` | map 189 |
| `leave scarlet monastery` | `ScarletMonasteryLeaveDungeonTrigger` | map 189 |
| `start vishas fight` | `VishasStartFightTrigger` | NPC 3983 |
| `end vishas fight` | `VishasEndFightTrigger` | |
| `start fallen champion fight` | `FallenChampionStartFightTrigger` | NPC 6488 |
| `end fallen champion fight` | `FallenChampionEndFightTrigger` | |
| `start ironspine fight` | `IronspineStartFightTrigger` | NPC 6489 |
| `end ironspine fight` | `IronspineEndFightTrigger` | |
| `start thalnos fight` | `ThalnosStartFightTrigger` | NPC 4543 |
| `end thalnos fight` | `ThalnosEndFightTrigger` | |
| `thalnos shadowbolt volley` | `ThalnsosShadowboltVolleyTrigger` | CloseToHostileCreatureHazardTrigger, ~22yd |
| `start loksey fight` | `LokseyStartFightTrigger` | NPC 3974 |
| `end loksey fight` | `LokseyEndFightTrigger` | |
| `start doan fight` | `DoanStartFightTrigger` | NPC 6487 |
| `end doan fight` | `DoanEndFightTrigger` | |
| `doan arcane explosion` | `DoanArcaneExplosionTrigger` | CloseToHostileCreatureHazardTrigger, ~32yd |
| `start herod fight` | `HerodStartFightTrigger` | NPC 3975 |
| `end herod fight` | `HerodEndFightTrigger` | |
| `herod whirlwind` | `HerodWhirlwindTrigger` | CloseToHostileCreatureHazardTrigger, ~10yd |
| `start mograine fight` | `MograineStartFightTrigger` | NPC 3976 |
| `end mograine fight` | `MograineEndFightTrigger` | |
| `start whitemane fight` | `WhitemaneStartFightTrigger` | NPC 3977 |
| `end whitemane fight` | `WhitemaneEndFightTrigger` | |
| `target casting whitemane heal` | `WhitemaneHealCastingTrigger` | only if spell ID verified |
| `start fairbanks fight` | `FairbanksStartFightTrigger` | NPC 4542 |
| `end fairbanks fight` | `FairbanksEndFightTrigger` | |

### Deferred Trigger Candidates

- `thalnos fire nova totem` — only if GO ID found in classicmangos DB
- `whitemane mass mind control` — requires group dispel coordination, v2
- `mograine resurrection phase` — custom phase detection, v2

---

## Planned Action List

| Action string | Class |
|---------------|-------|
| `enable scarlet monastery strategy` | `ScarletMonasteryEnableStrategyAction` |
| `disable scarlet monastery strategy` | `ScarletMonasteryDisableStrategyAction` |
| `enable vishas fight strategy` | `VishasEnableFightStrategyAction` |
| `disable vishas fight strategy` | `VishasDisableFightStrategyAction` |
| `enable fallen champion fight strategy` | `FallenChampionEnableFightStrategyAction` |
| `disable fallen champion fight strategy` | `FallenChampionDisableFightStrategyAction` |
| `enable ironspine fight strategy` | `IronspineEnableFightStrategyAction` |
| `disable ironspine fight strategy` | `IronspineDisableFightStrategyAction` |
| `enable thalnos fight strategy` | `ThalnosEnableFightStrategyAction` |
| `disable thalnos fight strategy` | `ThalnosDisableFightStrategyAction` |
| `thalnos move away from shadowbolt volley` | `ThalnsosMoveAwayFromShadowboltVolleyAction` |
| `enable loksey fight strategy` | `LokseyEnableFightStrategyAction` |
| `disable loksey fight strategy` | `LokseyDisableFightStrategyAction` |
| `enable doan fight strategy` | `DoanEnableFightStrategyAction` |
| `disable doan fight strategy` | `DoanDisableFightStrategyAction` |
| `doan move away from arcane explosion` | `DoanMoveAwayFromArcaneExplosionAction` |
| `enable herod fight strategy` | `HerodEnableFightStrategyAction` |
| `disable herod fight strategy` | `HerodDisableFightStrategyAction` |
| `herod move away from whirlwind` | `HerodMoveAwayFromWhirlwindAction` |
| `enable mograine fight strategy` | `MograineEnableFightStrategyAction` |
| `disable mograine fight strategy` | `MograineDisableFightStrategyAction` |
| `enable whitemane fight strategy` | `WhitemaneEnableFightStrategyAction` |
| `disable whitemane fight strategy` | `WhitemaneDisableFightStrategyAction` |
| `interrupt enemy cast` | existing reusable action for Whitemane heal |
| `enable fairbanks fight strategy` | `FairbanksEnableFightStrategyAction` |
| `disable fairbanks fight strategy` | `FairbanksDisableFightStrategyAction` |

---

## Planned Strategy List

| Strategy string | Class |
|-----------------|-------|
| `scarlet monastery` | `ScarletMonasteryDungeonStrategy` |
| `vishas` | `VishasFightStrategy` |
| `fallen champion` | `FallenChampionFightStrategy` |
| `ironspine` | `IronspineFightStrategy` |
| `thalnos` | `ThalnsosFightStrategy` |
| `loksey` | `LokseyFightStrategy` |
| `doan` | `DoanFightStrategy` |
| `herod` | `HerodFightStrategy` |
| `mograine` | `MograineFightStrategy` |
| `whitemane` | `WhitemaneFightStrategy` |
| `fairbanks` | `FairbanksFightStrategy` |

---

## Registration Checklist

- [ ] `playerbot/strategy/generic/DungeonStrategy.cpp` — enter/leave scarlet monastery (combat + noncombat)
- [ ] `playerbot/strategy/triggers/TriggerContext.h` — include `SmTriggers.h` + register all triggers
- [ ] `playerbot/strategy/actions/ActionContext.h` — include `SmActions.h` + register all actions
- [ ] `playerbot/strategy/StrategyContext.h` — include `SmStrategy.h` + register all strategies
- [ ] `CMakeLists.txt` — add `Ai_Dungeon_SM` GLOB_RECURSE + LIBRARY_SRCS entry

---

## Implementation Steps

- [x] Step 1: Verify NPC IDs and map ID locally; update this plan if any IDs differ
- [ ] Step 2: Verify Whitemane heal spell ID; decide whether to include interrupt in v1
- [ ] Step 3: Check for Fire Nova Totem GO ID; decide whether to include in v1 or defer
- [ ] Step 4: Create `SmTriggers.h` with instance enter/leave and all boss start/end triggers
- [ ] Step 5: Add mechanic triggers (Thalnos Shadowbolt Volley, Doan Arcane Explosion, Herod Whirlwind, and Whitemane heal if spell ID verified)
- [ ] Step 6: Create `SmActions.h` with instance and boss enable/disable actions + AoE move-away actions
- [ ] Step 7: Create `SmStrategy.h` with one dungeon strategy and one fight strategy per boss
- [ ] Step 8: Create `SmStrategy.cpp` with start/end fight wiring for all bosses and mechanic triggers for v1 bosses
- [ ] Step 9: Register Scarlet Monastery in `DungeonStrategy.cpp`
- [ ] Step 10: Register all SM triggers in `TriggerContext.h`
- [ ] Step 11: Register all SM actions in `ActionContext.h`
- [ ] Step 12: Register all SM strategies in `StrategyContext.h`
- [ ] Step 13: Add `CMakeLists.txt` entry for `Ai_Dungeon_SM`
- [ ] Step 14: Build cleanly with no new SM-specific errors
- [ ] Step 15: In-game verify dungeon strategy enable/disable on enter/leave
- [ ] Step 16: In-game verify each boss strategy enables on engage and disables on death/reset
- [ ] Step 17: In-game verify Herod Whirlwind avoidance and Doan Arcane Explosion avoidance
- [ ] Step 18: In-game verify Whitemane heal interrupt if included in v1
- [ ] Step 19: Evaluate Mograine/Whitemane dual-boss phase; open follow-up patch if re-engage detection fails

---

## Definition of Done

- [ ] `./build.sh` clean with no new SM-specific errors
- [ ] Bot enters SM → `enable scarlet monastery strategy` appears in log
- [ ] Each boss engaged → corresponding fight strategy enables
- [ ] Each boss dies/resets → corresponding fight strategy disables
- [ ] Bot leaves SM → `disable scarlet monastery strategy` appears in log
- [ ] At least one mechanic per wing implemented (Thalnos Shadowbolt Volley, Doan Arcane Explosion, Herod Whirlwind, Whitemane heal interrupt)
- [ ] Mograine is at least playable in v1; resurrection phase detection deferred if needed

---

## Verified DB Output

```sql
SELECT entry, name FROM creature_template
WHERE name IN (
  'Interrogator Vishas', 'Fallen Champion', 'Ironspine', 'Bloodmage Thalnos',
  'Houndmaster Loksey', 'Arcanist Doan',
  'Herod',
  'Scarlet Commander Mograine', 'High Inquisitor Whitemane', 'High Inquisitor Fairbanks'
);

+-------+----------------------------+
| entry | name                       |
+-------+----------------------------+
|  3983 | Interrogator Vishas        |
|  6488 | Fallen Champion            |
|  6489 | Ironspine                  |
|  4543 | Bloodmage Thalnos          |
|  3974 | Houndmaster Loksey         |
|  6487 | Arcanist Doan              |
|  3975 | Herod                      |
|  3976 | Scarlet Commander Mograine |
|  3977 | High Inquisitor Whitemane  |
|  4542 | High Inquisitor Fairbanks  |
+-------+----------------------------+

SELECT map FROM instance_template WHERE map = 189;

+-----+
| map |
+-----+
| 189 |
+-----+
```
