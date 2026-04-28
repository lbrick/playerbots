# Raid Implementation Guide

**For:** cmangos-playerbots raid bot strategies  
**Boss research — Classic raids:** `https://www.wowhead.com/classic/guide/wow-classic-<raid-slug>-overview#overview-of-bosses`  
**Boss research — TBC raids:** `https://www.wowhead.com/tbc/guide/<raid-slug>-overview#overview-of-bosses`

Examples:
- ZG: `https://www.wowhead.com/classic/guide/wow-classic-zulgurub-overview#overview-of-bosses`
- MC: `https://www.wowhead.com/classic/guide/wow-classic-molten-core-overview#overview-of-bosses`
- Kara: `https://www.wowhead.com/tbc/guide/karazhan-overview#overview-of-bosses`

Individual boss pages: `https://www.wowhead.com/classic/npc=<NPC_ID>`

---

## Overview

Raid strategies follow the same layered system as dungeon strategies:

1. **Instance strategy** — loads on map enter. Registers boss start triggers.
2. **Boss fight strategy** — loads when boss enters combat. Registers mechanic triggers.

Standard combat (healing, DPS, threat) is handled by class strategies. Raid strategies only
layer boss-specific mechanics on top.

---

## File Structure

Each raid lives in its own subdirectory under `playerbot/strategy/raid/`:

```
playerbot/strategy/raid/
  <RaidName>/
    Action/
      Raid<Short>Actions.h        — enable/disable strategy actions + boss movement actions
      Raid<Short>Actions.cpp      — only if custom Execute() logic needed
    Trigger/
      Raid<Short>Triggers.h       — enter/leave instance + start/end boss + mechanic triggers
      Raid<Short>Triggers.cpp     — only if triggers need custom IsActive() logic
    Strategy/
      Raid<Short>Strategy.h       — strategy class declarations
      Raid<Short>Strategy.cpp     — strategy trigger/multiplier initialization
```

**Naming conventions:**
- Directory: full raid name, PascalCase, no spaces: `MoltenCore`, `ZulGurub`, `AhnQirajTemple`
- File prefix: `Raid` + short abbreviation: `RaidMc`, `RaidZg`, `RaidAq40`
- Class names: `<FullName>DungeonStrategy`, `<Boss>FightStrategy`
- Strategy string names: lowercase with spaces/apostrophes: `"molten core"`, `"ragnaros"`, `"zul'gurub"`

---

## Step 1 — Research the Raid

Before writing any code, look up every boss on Wowhead:

```
https://www.wowhead.com/classic/guide/wow-classic-<raid-slug>-overview#overview-of-bosses
```

For each boss record:
- **NPC ID** — from the boss Wowhead page URL (e.g. `/npc=12118`)
- **Key abilities** — focus on positional hazards (AoE circles, frontal cones, ground effects,
  knockbacks). Pure damage or debuffs healers/dispellers handle automatically do NOT need bot actions.
- **Spell IDs** — for aura-based triggers. Find on the spell's Wowhead page.
- **Phases** — some raid bosses have phase transitions; note which phase triggers which mechanic.

Write a boss table before touching any code:

```
| Boss           | NPC ID | Mechanic              | Trigger type                    | Action               |
|----------------|--------|-----------------------|---------------------------------|----------------------|
| Ragnaros       | 11502  | Wrath of Ragnaros ~15yd | CloseToHostileCreatureHazard  | MoveAwayFromCreature |
| Majordomo      | 12018  | Blast Wave ~8yd       | CloseToHostileCreatureHazard    | MoveAwayFromCreature |
| Gehennas       | 12259  | Rain of Fire (GO)     | CloseToGameObjectHazard         | MoveAwayFromHazard   |
```

---

## Step 2 — Create the Trigger File

**Path:** `playerbot/strategy/raid/<RaidName>/Trigger/Raid<Short>Triggers.h`

Every raid needs at minimum:
- One `EnterDungeonTrigger` and one `LeaveDungeonTrigger` (use the instance map ID)
- One `StartBossFightTrigger` and one `EndBossFightTrigger` per boss

All four base classes live in `playerbot/strategy/triggers/DungeonTriggers.h`.

```cpp
#pragma once
#include "playerbot/strategy/triggers/DungeonTriggers.h"

namespace ai
{
    // ── Instance enter/leave ─────────────────────────────────────────────────
    class <RaidName>EnterDungeonTrigger : public EnterDungeonTrigger
    {
    public:
        <RaidName>EnterDungeonTrigger(PlayerbotAI* ai)
            : EnterDungeonTrigger(ai, "enter <raid name>", "<raid name>", MAP_ID) {}
    };

    class <RaidName>LeaveDungeonTrigger : public LeaveDungeonTrigger
    {
    public:
        <RaidName>LeaveDungeonTrigger(PlayerbotAI* ai)
            : LeaveDungeonTrigger(ai, "leave <raid name>", "<raid name>", MAP_ID) {}
    };

    // ── Boss: <BossName> (NPC NPC_ID) ────────────────────────────────────────
    class <Boss>StartFightTrigger : public StartBossFightTrigger
    {
    public:
        <Boss>StartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start <boss> fight", "<boss>", NPC_ID) {}
    };

    class <Boss>EndFightTrigger : public EndBossFightTrigger
    {
    public:
        <Boss>EndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end <boss> fight", "<boss>", NPC_ID) {}
    };
}
```

### Mechanic Triggers

AoE avoidance based on proximity to boss:

```cpp
    class <Boss><Mechanic>Trigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        <Boss><Mechanic>Trigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "<boss> <mechanic>", NPC_ID, RADIUS, DURATION) {}
    };
```

Use `CloseToGameObjectHazardTrigger` for ground-placed fire/void zones (Game Object hazards).

---

## Step 3 — Create the Action File

**Path:** `playerbot/strategy/raid/<RaidName>/Action/Raid<Short>Actions.h`

Only create a `.cpp` if you need custom `Execute()` logic.

```cpp
#pragma once
#include "playerbot/strategy/actions/DungeonActions.h"
#include "playerbot/strategy/actions/ChangeStrategyAction.h"

namespace ai
{
    // ── Instance strategy enable/disable ─────────────────────────────────────
    class <RaidName>EnableStrategyAction : public ChangeAllStrategyAction
    {
    public:
        <RaidName>EnableStrategyAction(PlayerbotAI* ai)
            : ChangeAllStrategyAction(ai, "enable <raid name> strategy", "+<raid name>") {}
    };

    class <RaidName>DisableStrategyAction : public ChangeAllStrategyAction
    {
    public:
        <RaidName>DisableStrategyAction(PlayerbotAI* ai)
            : ChangeAllStrategyAction(ai, "disable <raid name> strategy", "-<raid name>") {}
    };

    // ── Per-boss enable/disable ───────────────────────────────────────────────
    class <Boss>EnableFightStrategyAction : public ChangeAllStrategyAction
    {
    public:
        <Boss>EnableFightStrategyAction(PlayerbotAI* ai)
            : ChangeAllStrategyAction(ai, "enable <boss> fight strategy", "+<boss>") {}
    };

    class <Boss>DisableFightStrategyAction : public ChangeAllStrategyAction
    {
    public:
        <Boss>DisableFightStrategyAction(PlayerbotAI* ai)
            : ChangeAllStrategyAction(ai, "disable <boss> fight strategy", "-<boss>") {}
    };

    // ── AoE avoidance action ─────────────────────────────────────────────────
    class <Boss>MoveAwayFrom<Mechanic>Action : public MoveAwayFromCreature
    {
    public:
        <Boss>MoveAwayFrom<Mechanic>Action(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "<boss> move away from <mechanic>", NPC_ID, SAFE_RANGE) {}
    };
}
```

`SAFE_RANGE` = AoE radius + small buffer (e.g. 15yd AoE → use 17.0f).

---

## Step 4 — Create the Strategy Files

**Path:** `playerbot/strategy/raid/<RaidName>/Strategy/Raid<Short>Strategy.h` and `.cpp`

### Header

```cpp
#pragma once
#include "playerbot/strategy/Strategy.h"

namespace ai
{
    // Loaded while group is in the raid instance. Registers boss start triggers.
    class <RaidName>DungeonStrategy : public Strategy
    {
    public:
        <RaidName>DungeonStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "<raid name>"; }
    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
    };

    // Loaded while <Boss> is in combat.
    class <Boss>FightStrategy : public Strategy
    {
    public:
        <Boss>FightStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "<boss>"; }
    private:
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override;
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;
        // Optional — for phase-based multiplier switching:
        // void InitReactionTriggers(std::list<TriggerNode*>& triggers) override;
        // void InitCombatMultipliers(std::list<Multiplier*>& multipliers) override;
    };
}
```

### Implementation (.cpp)

```cpp
#include "playerbot/playerbot.h"
#include "Raid<Short>Strategy.h"

using namespace ai;

// ── <RaidName>DungeonStrategy ────────────────────────────────────────────────

void <RaidName>DungeonStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "start <boss> fight",
        NextAction::array(0, new NextAction("enable <boss> fight strategy", 100.0f), NULL)));
    // repeat per boss
}

void <RaidName>DungeonStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Mirror InitCombatTriggers (handles bots that zone in while boss is being pulled)
    triggers.push_back(new TriggerNode(
        "start <boss> fight",
        NextAction::array(0, new NextAction("enable <boss> fight strategy", 100.0f), NULL)));
}

// ── <Boss>FightStrategy ──────────────────────────────────────────────────────

void <Boss>FightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "<boss> <mechanic>",
        NextAction::array(0, new NextAction("<boss> move away from <mechanic>", ACTION_MOVE + 5), NULL)));
}

void <Boss>FightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end <boss> fight",
        NextAction::array(0, new NextAction("disable <boss> fight strategy", 100.0f), NULL)));
}

void <Boss>FightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end <boss> fight",
        NextAction::array(0, new NextAction("disable <boss> fight strategy", 100.0f), NULL)));
}
```

---

## Step 5 — Register Everything (5 file edits)

### 5a — DungeonStrategy.cpp

Add in both `InitCombatTriggers` and `InitNonCombatTriggers` (combat handles zone-in-during-pull;
noncombat handles normal enter + leave):

```cpp
// InitCombatTriggers:
triggers.push_back(new TriggerNode(
    "enter <raid name>",
    NextAction::array(0, new NextAction("enable <raid name> strategy", 100.0f), NULL)));

// InitNonCombatTriggers:
triggers.push_back(new TriggerNode(
    "enter <raid name>",
    NextAction::array(0, new NextAction("enable <raid name> strategy", 100.0f), NULL)));
triggers.push_back(new TriggerNode(
    "leave <raid name>",
    NextAction::array(0, new NextAction("disable <raid name> strategy", 100.0f), NULL)));
```

### 5b — TriggerContext.h

```cpp
#include "playerbot/strategy/raid/<RaidName>/Trigger/Raid<Short>Triggers.h"

// In constructor:
creators["enter <raid name>"]     = [](PlayerbotAI* ai) { return new <RaidName>EnterDungeonTrigger(ai); };
creators["leave <raid name>"]     = [](PlayerbotAI* ai) { return new <RaidName>LeaveDungeonTrigger(ai); };
creators["start <boss> fight"]    = [](PlayerbotAI* ai) { return new <Boss>StartFightTrigger(ai); };
creators["end <boss> fight"]      = [](PlayerbotAI* ai) { return new <Boss>EndFightTrigger(ai); };
creators["<boss> <mechanic>"]     = [](PlayerbotAI* ai) { return new <Boss><Mechanic>Trigger(ai); };
```

### 5c — ActionContext.h

```cpp
#include "playerbot/strategy/raid/<RaidName>/Action/Raid<Short>Actions.h"

// In constructor:
creators["enable <raid name> strategy"]   = [](PlayerbotAI* ai) { return new <RaidName>EnableStrategyAction(ai); };
creators["disable <raid name> strategy"]  = [](PlayerbotAI* ai) { return new <RaidName>DisableStrategyAction(ai); };
creators["enable <boss> fight strategy"]  = [](PlayerbotAI* ai) { return new <Boss>EnableFightStrategyAction(ai); };
creators["disable <boss> fight strategy"] = [](PlayerbotAI* ai) { return new <Boss>DisableFightStrategyAction(ai); };
creators["<boss> move away from <mechanic>"] = [](PlayerbotAI* ai) { return new <Boss>MoveAwayFrom<Mechanic>Action(ai); };
```

### 5d — StrategyContext.h

```cpp
#include "playerbot/strategy/raid/<RaidName>/Strategy/Raid<Short>Strategy.h"

// In constructor:
creators["<raid name>"] = [](PlayerbotAI* ai) { return new <RaidName>DungeonStrategy(ai); };
creators["<boss>"]      = [](PlayerbotAI* ai) { return new <Boss>FightStrategy(ai); };
```

### 5e — CMakeLists.txt

Add alongside the other raid GLOB entries:

```cmake
file(GLOB_RECURSE Ai_<RaidName> ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/raid/<RaidName>/*.cpp
                                ${CMAKE_CURRENT_SOURCE_DIR}/playerbot/strategy/raid/<RaidName>/*.h)
```

Then add `${Ai_<RaidName>}` to the `target_sources(...)` or `add_library(...)` call where other
raid globs are listed.

---

## Step 6 — Build and Verify

```bash
./build.sh
```

Expected: clean build with no new errors or warnings.

In-game verification (with `LogFileLevel = 3`):
- Enter raid → log shows `enable <raid name> strategy`
- Engage boss → log shows `enable <boss> fight strategy`
- Kill boss → log shows `disable <boss> fight strategy`
- Leave instance → log shows `disable <raid name> strategy`

---

## Action Priority Reference

| Priority | Use |
|----------|-----|
| `ACTION_MOVE + 5` | AoE avoidance movement — interrupts normal combat |
| `ACTION_HIGH + 5` | Urgent combat action (interrupt, defensive CD) |
| `ACTION_NORMAL + 5` | Standard priority combat action |
| `100.0f` | Strategy enable/disable |

---

## Common Mechanic Patterns

| Mechanic | Trigger class | Action class |
|----------|---------------|--------------|
| AoE circle around boss | `CloseToHostileCreatureHazardTrigger(npcId, radius, 3)` | `MoveAwayFromCreature(npcId, radius+2)` |
| Void zone / fire patch (GO) | `CloseToGameObjectHazardTrigger(goId, radius, duration)` | `MoveAwayFromHazard` |
| Frontal cone / breath | proximity + facing check (custom) | `MoveBehindCreature` |
| DoT / curse | existing cure/dispel strategies handle automatically | none |
| Interrupt | `SpellBeingCastTrigger` | `InterruptSpellAction` |
| Phase transition | `InitReactionTriggers` + HP-threshold check | multiplier swap or strategy reload |

---

## Differences from Dungeons

| | Dungeons | Raids |
|--|---------|-------|
| Directory | `strategy/dungeons/<Name>/` | `strategy/raid/<Name>/` |
| File prefix | `<Name>` (e.g. `RfcStrategy.h`) | `Raid<Short>` (e.g. `RaidMcStrategy.h`) |
| Class name | `<Name>DungeonStrategy` | `<Name>DungeonStrategy` (same) |
| CMakeLists label | `Ai_Dungeon_<Name>` | `Ai_<Name>` |
| Extra hooks | rare | `InitReactionTriggers`, `InitCombatMultipliers` common for phase fights |
| `.cpp` for Triggers/Actions | rarely | sometimes (BWL, Karazhan have them) |

---

## Tips

- **NPC IDs:** Verify in the DB — `SELECT entry, name FROM creature_template WHERE name LIKE '%Ragnaros%'`
- **Spell IDs:** Classic DB differs from retail. Verify — `SELECT * FROM spell_template WHERE name = '...'`
- **Map IDs:** Cross-check with `worlddb > instance_template.map` before wiring triggers
- **Bosses with no positional mechanic** still need start/end fight triggers for strategy lifecycle
- **Phase fights** (Onyxia phase 2, Ragnaros submerge): use `InitReactionTriggers` + `InitCombatMultipliers`
  to swap behaviour between phases. Check `OnyxiasLair/` as the canonical phase-fight pattern
- **Reference implementations:** `OnyxiasLair/` (single boss, phases), `MoltenCore/` (multi-boss, AoE)
