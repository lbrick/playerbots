# Shadowfang Keep — Implementation Plan

**Map ID:** 33  
**Levels:** 22–30  
**Status:** 🟢 ENTER VERIFIED — leave/boss verify pending  
**NPC IDs:** verified against `classicmangos.creature_template` and `instance_template` (2026-04-23)

---

## Resume Protocol

At session start: scan for first `[ ]` — that is the resume point. Mark `[x]` as each step is confirmed done.

---

## Scope

Follow the shared dungeon workflow in `cmangos-playerbots/playerbot/strategy/dungeons/DUNGEON_GUIDE.md`:

- add one instance strategy for Shadowfang Keep
- add one fight strategy per boss
- only layer boss-specific mechanics on top of existing class combat logic
- keep v1 conservative and avoid over-scoping custom movement unless the fight clearly needs it

Recommended delivery split:

- **Pass 1:** full dungeon scaffolding + all start/end boss strategies
- **Pass 2:** only the mechanics that map cleanly onto existing reusable triggers/actions
- **Stretch only if needed:** custom Arugal positioning logic or trash-specific behavior

---

## Boss Reference

> ✅ NPC IDs and map ID verified against local classicmangos DB (2026-04-23)

| Boss | NPC ID | Key Mechanic | Bot Action Needed |
|------|--------|-------------|------------------|
| Rethilgore | 3914 | Soul Drain; otherwise tank-and-spank | start/end triggers only |
| Razorclaw the Butcher | 3886 | Butcher Drain; otherwise tank-and-spank | start/end triggers only |
| Baron Silverlaine | 3887 | Veil of Shadow healing reduction on tank | start/end triggers only |
| Commander Springvale | 4278 | Heal cast must be interrupted; nearby guard silence is dangerous | **Interrupt cast** in v1; guardsman spacing is stretch |
| Odo the Blindwatcher | 4279 | Pulls with bats; disarm/cleave from adds | start/end triggers only |
| Fenrus the Devourer | 4274 | Toxic Saliva DoT; otherwise straightforward | start/end triggers only |
| Wolf Master Nandos | 3927 | Summons worg adds during fight | start/end triggers only in v1; verify if add focus is already sufficient |
| Archmage Arugal | 4275 | Teleports, Void Bolt, curse; fight punishes chase behavior | start/end triggers only in v1; custom positioning is stretch |

### Mechanic Notes

**Commander Springvale**
- Best v1 candidate for a real mechanic.
- Use the existing reusable interrupt path if his heal spell ID can be verified cleanly.
- The guide also flags the nearby Wailing Guardsman silence aura as dangerous, but that is add/trash-adjacent and may be better handled after the first playable version.

**Wolf Master Nandos**
- Core issue is add priority rather than a clear positional hazard.
- Likely acceptable for v1 to rely on current multi-target combat unless testing shows bots ignore summoned worgs.

**Archmage Arugal**
- Hardest boss in the instance, but his real mechanic is room positioning and teleport handling.
- Current dungeon framework supports start/end strategies and simple hazard/interrupt patterns well; it does not automatically imply a good “hold on entry platform and do not chase” behavior.
- Plan v1 without custom movement. If in-game verification shows bots fail here, add a follow-up custom action instead of forcing it into the first patch.

---

## Files to Create

```
src/Ai/Dungeon/ShadowfangKeep/
  Action/
    SfkActions.h
  Trigger/
    SfkTriggers.h
  Strategy/
    SfkStrategy.h
    SfkStrategy.cpp
  SFK_PLAN.md        ← this file
```

---

## Pre-Code Checklist

- [x] Verify all boss NPC IDs against classicmangos DB
- [x] Confirm map ID 33 in `instance_template`
- [ ] Verify Commander Springvale heal spell name and spell ID before promising an interrupt trigger
- [ ] Decide whether Wailing Guardsman silence handling belongs in the first SFK patch or a follow-up
- [ ] Decide whether Arugal needs custom positioning in the first patch or should be deferred until in-game evidence says it is necessary

## Pre-Code DB Queries

```sql
SELECT entry, name FROM creature_template
WHERE name IN ('Rethilgore', 'Razorclaw the Butcher', 'Baron Silverlaine',
               'Commander Springvale', 'Odo the Blindwatcher',
               'Fenrus the Devourer', 'Wolf Master Nandos', 'Archmage Arugal');

SELECT map FROM instance_template WHERE map = 33;
```

---

## Planned Trigger List

| Trigger string | Class | Notes |
|----------------|-------|-------|
| `enter shadowfang keep` | `ShadowfangKeepEnterDungeonTrigger` | map 33 |
| `leave shadowfang keep` | `ShadowfangKeepLeaveDungeonTrigger` | map 33 |
| `start rethilgore fight` | `RethilgoreStartFightTrigger` | NPC 3914 |
| `end rethilgore fight` | `RethilgoreEndFightTrigger` | |
| `start razorclaw fight` | `RazorclawStartFightTrigger` | NPC 3886 |
| `end razorclaw fight` | `RazorclawEndFightTrigger` | |
| `start silverlaine fight` | `SilverlaineStartFightTrigger` | NPC 3887 |
| `end silverlaine fight` | `SilverlaineEndFightTrigger` | |
| `start springvale fight` | `SpringvaleStartFightTrigger` | NPC 4278 |
| `end springvale fight` | `SpringvaleEndFightTrigger` | |
| `target casting springvale heal` | `SpringvaleHealCastingTrigger` | only if spell ID verified |
| `start odo fight` | `OdoStartFightTrigger` | NPC 4279 |
| `end odo fight` | `OdoEndFightTrigger` | |
| `start fenrus fight` | `FenrusStartFightTrigger` | NPC 4274 |
| `end fenrus fight` | `FenrusEndFightTrigger` | |
| `start nandos fight` | `NandosStartFightTrigger` | NPC 3927 |
| `end nandos fight` | `NandosEndFightTrigger` | |
| `start arugal fight` | `ArugalStartFightTrigger` | NPC 4275 |
| `end arugal fight` | `ArugalEndFightTrigger` | |

### Deferred Trigger Candidates

- `close to wailing guardsman silence` — only if local data shows a clean hostile-creature hazard fit
- `arugal teleport pressure` — likely needs custom behavior, not just a stock trigger

---

## Planned Action List

| Action string | Class |
|---------------|-------|
| `enable shadowfang keep strategy` | `ShadowfangKeepEnableStrategyAction` |
| `disable shadowfang keep strategy` | `ShadowfangKeepDisableStrategyAction` |
| `enable rethilgore fight strategy` | `RethilgoreEnableFightStrategyAction` |
| `disable rethilgore fight strategy` | `RethilgoreDisableFightStrategyAction` |
| `enable razorclaw fight strategy` | `RazorclawEnableFightStrategyAction` |
| `disable razorclaw fight strategy` | `RazorclawDisableFightStrategyAction` |
| `enable silverlaine fight strategy` | `SilverlaineEnableFightStrategyAction` |
| `disable silverlaine fight strategy` | `SilverlaineDisableFightStrategyAction` |
| `enable springvale fight strategy` | `SpringvaleEnableFightStrategyAction` |
| `disable springvale fight strategy` | `SpringvaleDisableFightStrategyAction` |
| `interrupt enemy cast` | existing reusable action for Springvale heal |
| `enable odo fight strategy` | `OdoEnableFightStrategyAction` |
| `disable odo fight strategy` | `OdoDisableFightStrategyAction` |
| `enable fenrus fight strategy` | `FenrusEnableFightStrategyAction` |
| `disable fenrus fight strategy` | `FenrusDisableFightStrategyAction` |
| `enable nandos fight strategy` | `NandosEnableFightStrategyAction` |
| `disable nandos fight strategy` | `NandosDisableFightStrategyAction` |
| `enable arugal fight strategy` | `ArugalEnableFightStrategyAction` |
| `disable arugal fight strategy` | `ArugalDisableFightStrategyAction` |

---

## Planned Strategy List

| Strategy string | Class |
|-----------------|-------|
| `shadowfang keep` | `ShadowfangKeepDungeonStrategy` |
| `rethilgore` | `RethilgoreFightStrategy` |
| `razorclaw` | `RazorclawFightStrategy` |
| `silverlaine` | `SilverlaineFightStrategy` |
| `springvale` | `SpringvaleFightStrategy` |
| `odo` | `OdoFightStrategy` |
| `fenrus` | `FenrusFightStrategy` |
| `nandos` | `NandosFightStrategy` |
| `arugal` | `ArugalFightStrategy` |

---

## Registration Checklist

- [x] `src/Ai/Base/generic/DungeonStrategy.cpp` — enter/leave shadowfang keep (combat + noncombat)
- [x] `src/Ai/Base/triggers/TriggerContext.h` — include `SfkTriggers.h` + register all triggers
- [x] `src/Ai/Base/actions/ActionContext.h` — include `SfkActions.h` + register all actions
- [x] `src/Ai/Base/StrategyContext.h` — include `SfkStrategy.h` + register all strategies
- [x] `CMakeLists.txt` — add `Ai_Dungeon_SFK` GLOB_RECURSE + LIBRARY_SRCS entry

---

## Implementation Steps

- [x] Step 1: Verify NPC IDs and map ID locally; update this plan if any IDs differ
- [ ] Step 2: Verify Springvale heal spell ID and decide whether to include that interrupt in v1
- [x] Step 3: Create `SfkTriggers.h` with instance enter/leave and all boss start/end triggers
- [x] Step 4: Add `SpringvaleHealCastingTrigger` if the spell ID is verified and the trigger is clean
- [x] Step 5: Create `SfkActions.h` with instance and boss enable/disable actions
- [x] Step 6: Create `SfkStrategy.h` with one dungeon strategy and one fight strategy per boss
- [x] Step 7: Create `SfkStrategy.cpp` with start/end fight wiring for all bosses
- [x] Step 8: Register Shadowfang Keep in `DungeonStrategy.cpp`
- [x] Step 9: Register all SFK triggers in `TriggerContext.h`
- [x] Step 10: Register all SFK actions in `ActionContext.h`
- [x] Step 11: Register all SFK strategies in `StrategyContext.h`
- [x] Step 12: Add `CMakeLists.txt` entry for `Ai_Dungeon_SFK`
- [x] Step 13: Build cleanly with no new SFK-specific errors; existing project warnings remain
- [ ] Step 14: In-game verify dungeon strategy enable/disable on enter/leave
  Enter verified 2026-04-23 with Trollman + Tultso; leave still pending.
- [ ] Step 15: In-game verify each boss strategy enables on engage and disables on death/reset
- [ ] Step 16: Verify Springvale interrupt behavior if included
- [ ] Step 17: Evaluate Arugal fight behavior; only open a follow-up patch for custom positioning if v1 is insufficient

---

## Definition of Done

- [x] `./build-classic.sh` clean with no new SFK-specific errors
- [x] Bot enters SFK → `enable shadowfang keep strategy` appears in log (verified 2026-04-23 with Trollman + Tultso)
- [ ] Each boss engaged → corresponding fight strategy enables
- [ ] Each boss dies/resets → corresponding fight strategy disables
- [ ] Bot leaves SFK → `disable shadowfang keep strategy` appears in log
- [ ] Springvale heal interrupt works if that mechanic is included in v1
- [ ] Arugal is at least playable in v1, even if advanced positioning is deferred

---

## Current Notes

- Springvale interrupt is implemented with `Holy Light` rank 2 (`spell 1026`) as the working spell ID.
- Local DB verification completed for all SFK boss NPC IDs and for `instance_template.map = 33`.
- Springvale spell rank still needs runtime or spell-data confirmation during in-game verification.
- Arugal custom positioning and Wailing Guardsman silence handling remain intentionally deferred.
- Runtime verification on `2026-04-23`:
  - `04:11:36` Trollman entered SFK instance 5
  - `04:11:39` Tultso entered SFK instance 5
  - `04:11:47` `Bot Tultso: dungeon strategy action [enable shadowfang keep strategy]`

## Verified DB Output

```sql
SELECT entry, name FROM creature_template
WHERE name IN ('Rethilgore', 'Razorclaw the Butcher', 'Baron Silverlaine',
               'Commander Springvale', 'Odo the Blindwatcher',
               'Fenrus the Devourer', 'Wolf Master Nandos', 'Archmage Arugal');

+-------+-----------------------+
| entry | name                  |
+-------+-----------------------+
|  3886 | Razorclaw the Butcher |
|  3887 | Baron Silverlaine     |
|  3914 | Rethilgore            |
|  3927 | Wolf Master Nandos    |
|  4274 | Fenrus the Devourer   |
|  4275 | Archmage Arugal       |
|  4278 | Commander Springvale  |
|  4279 | Odo the Blindwatcher  |
+-------+-----------------------+

SELECT map FROM instance_template WHERE map = 33;

+-----+
| map |
+-----+
|  33 |
+-----+
```
