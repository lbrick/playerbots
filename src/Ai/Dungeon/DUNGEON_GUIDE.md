# Dungeon Implementation Guide

**For:** cmangos-playerbots Classic dungeon bot strategies  
**Boss research:** https://www.wowhead.com/classic/guide/ragefire-chasm-dungeon-strategy-wow-classic  
  (Swap the dungeon slug for any other dungeon — same URL pattern)

---

## Overview

Each dungeon implementation is a layered strategy system:

1. **Instance strategy** — loads when the group enters the instance map. Registers triggers
   that watch for each boss being engaged and enable the per-boss strategy.
2. **Boss fight strategy** — loads when that boss enters combat. Registers mechanic-specific
   triggers (AoE avoidance, positioning, interrupt cues). Unloads on boss death/reset.

Standard combat (healing, DPS rotations, threat) is handled by existing class strategies.
Dungeon strategies only layer boss-specific behaviour on top.

---

## File Structure

Each dungeon lives in its own subdirectory:

```
src/Ai/Dungeon/
  <DungeonName>/
    Action/
      <Dungeon>Actions.h      — enable/disable strategy actions + boss-specific movement actions
    Trigger/
      <Dungeon>Triggers.h     — enter/leave instance + start/end boss fight + mechanic triggers
    Strategy/
      <Dungeon>Strategy.h     — strategy class declarations
      <Dungeon>Strategy.cpp   — strategy trigger/multiplier initialization
```

**Naming convention:**
- Use the full dungeon name with no spaces: `RagefireChasm`, `WailingCaverns`, `Deadmines`
- File prefix matches: `Rfc`, `Wc`, `Dm` etc.
- Strategy string names use lowercase with spaces: `"ragefire chasm"`, `"taragaman"`

---

## Step 1 — Research the Dungeon

Before writing any code, look up every boss on Wowhead:

```
https://www.wowhead.com/classic/guide/<dungeon-slug>-dungeon-strategy-wow-classic#bosses
```

For each boss record:
- **NPC ID** — from the boss's Wowhead page URL (e.g. `/npc=11520`)
- **Key abilities** — focus on anything that requires player positioning (AoE, knockback,
  frontal cone, ground effects). Pure damage or debuffs that healers/dispellers handle
  automatically do NOT need bot actions.
- **Spell IDs** — needed for aura-based triggers. Find them on the spell's Wowhead page.

Write a boss table like this before touching any code:

```
| Boss              | NPC ID | Mechanic           | Trigger type               | Action              |
|-------------------|--------|---------------------|----------------------------|---------------------|
| Taragaman         | 11520  | Firenova AoE ~10yd  | CloseToHostileCreature     | MoveAwayFromCreature|
| Jergosh           | 11518  | Immolate / CoW      | (handled by cure strategy) | none needed         |
```

---

## Step 2 — Create the Trigger File

**Path:** `src/Ai/Dungeon/<DungeonName>/Trigger/<Dungeon>Triggers.h`

Every dungeon needs at minimum:
- One `EnterDungeonTrigger` and one `LeaveDungeonTrigger` (use the instance map ID)
- One `StartBossFightTrigger` and one `EndBossFightTrigger` per boss (use boss NPC ID)

All four base classes live in `src/Ai/Base/triggers/DungeonTriggers.h`.

```cpp
#pragma once
#include "src/Ai/Base/triggers/DungeonTriggers.h"

namespace ai
{
    // ── Instance enter/leave (Map ID from DUNGEON_PLAN.md) ──────────────────
    class <Dungeon>EnterDungeonTrigger : public EnterDungeonTrigger
    {
    public:
        <Dungeon>EnterDungeonTrigger(PlayerbotAI* ai)
            : EnterDungeonTrigger(ai, "enter <dungeon name>", "<dungeon name>", MAP_ID) {}
    };

    class <Dungeon>LeaveDungeonTrigger : public LeaveDungeonTrigger
    {
    public:
        <Dungeon>LeaveDungeonTrigger(PlayerbotAI* ai)
            : LeaveDungeonTrigger(ai, "leave <dungeon name>", "<dungeon name>", MAP_ID) {}
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

For AoE avoidance based on proximity to a hostile creature:

```cpp
    // Fires when bot is within RADIUS yards of NPC_ID.
    // DURATION (seconds) controls how long the hazard is considered active after last detection.
    class <Boss><Mechanic>Trigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        <Boss><Mechanic>Trigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "<boss> <mechanic>", NPC_ID, RADIUS, DURATION) {}
    };
```

Use `CloseToGameObjectHazardTrigger` instead if the hazard is a spawned game object (fire patch, etc.).

---

## Step 3 — Create the Action File

**Path:** `src/Ai/Dungeon/<DungeonName>/Action/<Dungeon>Actions.h`

Actions only need a `.h` file if all logic is inherited from a base class.  
Only create a `.cpp` if you need custom `Execute()` logic.

**Enable/disable strategy actions** (required for every strategy level):

```cpp
#pragma once
#include "src/Ai/Base/actions/DungeonActions.h"
#include "src/Ai/Base/actions/ChangeStrategyAction.h"

namespace ai
{
    // ── Instance strategy enable/disable ────────────────────────────────────
    class <Dungeon>EnableStrategyAction : public ChangeAllStrategyAction
    {
    public:
        <Dungeon>EnableStrategyAction(PlayerbotAI* ai)
            : ChangeAllStrategyAction(ai, "enable <dungeon name> strategy", "+<dungeon name>") {}
    };

    class <Dungeon>DisableStrategyAction : public ChangeAllStrategyAction
    {
    public:
        <Dungeon>DisableStrategyAction(PlayerbotAI* ai)
            : ChangeAllStrategyAction(ai, "disable <dungeon name> strategy", "-<dungeon name>") {}
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
}
```

**AoE avoidance action** (subclass `MoveAwayFromCreature` — no `.cpp` needed):

```cpp
    class <Boss>MoveAwayFrom<Mechanic>Action : public MoveAwayFromCreature
    {
    public:
        <Boss>MoveAwayFrom<Mechanic>Action(PlayerbotAI* ai)
            : MoveAwayFromCreature(ai, "<boss> move away from <mechanic>", NPC_ID, SAFE_RANGE) {}
    };
```

`SAFE_RANGE` should be the AoE radius plus a small buffer (e.g. Firenova ~10yd → use 12.0f).

---

## Step 4 — Create the Strategy Files

**Path:** `src/Ai/Dungeon/<DungeonName>/Strategy/<Dungeon>Strategy.h` and `.cpp`

### Header

```cpp
#pragma once
#include "src/Ai/Base/Strategy.h"

namespace ai
{
    // Loaded while group is in the instance. Registers boss start triggers.
    class <Dungeon>DungeonStrategy : public Strategy
    {
    public:
        <Dungeon>DungeonStrategy(PlayerbotAI* ai) : Strategy(ai) {}
        std::string getName() override { return "<dungeon name>"; }
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
        void InitCombatTriggers(std::list<TriggerNode*>& triggers) override;    // mechanic triggers
        void InitNonCombatTriggers(std::list<TriggerNode*>& triggers) override; // end fight disable
        void InitDeadTriggers(std::list<TriggerNode*>& triggers) override;      // end fight disable
    };
}
```

### Implementation (.cpp)

The instance strategy's `InitCombatTriggers` and `InitNonCombatTriggers` are identical —
both register start-fight triggers so the boss strategy loads whether the bot was already
in combat when it zoned in or not.

```cpp
#include "src/Bot/Engine/playerbot.h"
#include "<Dungeon>Strategy.h"

using namespace ai;

// ── <Dungeon>DungeonStrategy ─────────────────────────────────────────────────

void <Dungeon>DungeonStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "start <boss> fight",
        NextAction::array(0, new NextAction("enable <boss> fight strategy", 100.0f), NULL)));
    // repeat for each boss
}

void <Dungeon>DungeonStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Same start-fight triggers as InitCombatTriggers (in case bot zones in while boss is being pulled)
    triggers.push_back(new TriggerNode(
        "start <boss> fight",
        NextAction::array(0, new NextAction("enable <boss> fight strategy", 100.0f), NULL)));
}

// ── <Boss>FightStrategy ──────────────────────────────────────────────────────

void <Boss>FightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // AoE avoidance — priority ACTION_MOVE + 5 ensures it interrupts normal combat
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

**Bosses with no special mechanic** only need `InitNonCombatTriggers` + `InitDeadTriggers`
to handle the end-fight disable. Leave `InitCombatTriggers` out (no override needed).

---

## Step 5 — Register Everything (4 file edits)

### 5a — DungeonStrategy.cpp

Add enter/leave for the new dungeon in both `InitCombatTriggers` and `InitNonCombatTriggers`:

```cpp
// InitCombatTriggers — handles bots that zone in already in combat
triggers.push_back(new TriggerNode(
    "enter <dungeon name>",
    NextAction::array(0, new NextAction("enable <dungeon name> strategy", 100.0f), NULL)));

// InitNonCombatTriggers — normal enter + leave
triggers.push_back(new TriggerNode(
    "enter <dungeon name>",
    NextAction::array(0, new NextAction("enable <dungeon name> strategy", 100.0f), NULL)));

triggers.push_back(new TriggerNode(
    "leave <dungeon name>",
    NextAction::array(0, new NextAction("disable <dungeon name> strategy", 100.0f), NULL)));
```

### 5b — TriggerContext.h

Add the `#include` near the other dungeon trigger includes (top of file), then register
each trigger in the constructor body:

```cpp
#include "src/Ai/Dungeon/<DungeonName>/Trigger/<Dungeon>Triggers.h"

// In constructor:
creators["enter <dungeon name>"] = [](PlayerbotAI* ai) { return new <Dungeon>EnterDungeonTrigger(ai); };
creators["leave <dungeon name>"] = [](PlayerbotAI* ai) { return new <Dungeon>LeaveDungeonTrigger(ai); };
creators["start <boss> fight"]   = [](PlayerbotAI* ai) { return new <Boss>StartFightTrigger(ai); };
creators["end <boss> fight"]     = [](PlayerbotAI* ai) { return new <Boss>EndFightTrigger(ai); };
creators["<boss> <mechanic>"]    = [](PlayerbotAI* ai) { return new <Boss><Mechanic>Trigger(ai); };
// repeat per boss
```

### 5c — ActionContext.h

Add the `#include` near the other dungeon action includes, then register:

```cpp
#include "src/Ai/Dungeon/<DungeonName>/Action/<Dungeon>Actions.h"

// In constructor:
creators["enable <dungeon name> strategy"]  = [](PlayerbotAI* ai) { return new <Dungeon>EnableStrategyAction(ai); };
creators["disable <dungeon name> strategy"] = [](PlayerbotAI* ai) { return new <Dungeon>DisableStrategyAction(ai); };
creators["enable <boss> fight strategy"]    = [](PlayerbotAI* ai) { return new <Boss>EnableFightStrategyAction(ai); };
creators["disable <boss> fight strategy"]   = [](PlayerbotAI* ai) { return new <Boss>DisableFightStrategyAction(ai); };
creators["<boss> move away from <mechanic>"] = [](PlayerbotAI* ai) { return new <Boss>MoveAwayFrom<Mechanic>Action(ai); };
// repeat per boss
```

### 5d — StrategyContext.h

Add the `#include` near the other dungeon strategy includes, then register:

```cpp
#include "src/Ai/Dungeon/<DungeonName>/Strategy/<Dungeon>Strategy.h"

// In constructor (under "// Dungeon Strategies"):
creators["<dungeon name>"] = [](PlayerbotAI* ai) { return new <Dungeon>DungeonStrategy(ai); };
creators["<boss>"]         = [](PlayerbotAI* ai) { return new <Boss>FightStrategy(ai); };
// repeat per boss
```

---

## Step 6 — Build and Verify

```bash
./build.sh
```

Expected: clean build, no new errors or warnings.

Then in-game verification (with `LogFileLevel = 3`):
- Enter instance → watch for `enable <dungeon name> strategy` action in log
- Engage boss → watch for `enable <boss> fight strategy` in log
- Kill boss → watch for `disable <boss> fight strategy` in log
- Leave instance → watch for `disable <dungeon name> strategy` in log

---

## Action Priority Reference

| Priority | When to use |
|----------|-------------|
| `ACTION_MOVE + 5` | Movement mechanic (AoE avoidance) — interrupts normal combat |
| `ACTION_HIGH + 5` | Urgent combat action (interrupt, defensive cooldown) |
| `ACTION_NORMAL + 5` | Standard priority combat action |
| `100.0f` | Strategy enable/disable (always fires, one-shot) |

---

## Common Mechanic Patterns

| Mechanic | Trigger class | Action class |
|----------|---------------|--------------|
| AoE circle around boss | `CloseToHostileCreatureHazardTrigger(npcId, radius, 3)` | `MoveAwayFromCreature(npcId, radius+2)` |
| Fire patch on ground (GO) | `CloseToGameObjectHazardTrigger(goId, radius, duration)` | `MoveAwayFromHazard` |
| Frontal cone | position check trigger (custom) | `MoveBehindCreature` or `MovementAction` |
| DoT / curse | existing cure/dispel strategies handle automatically | none |
| Interrupt priority | `SpellBeingCastTrigger` | `InterruptSpellAction` |

---

## Tips

- **Check NPC IDs in the DB**, not just Wowhead. Use `SELECT entry, name FROM creature_template WHERE name LIKE '%Taragaman%'` against classicmangos.
- **Spell IDs differ** between retail and Classic DB. Always verify with `SELECT * FROM spell_template WHERE name = '...'`.
- **Map IDs** are in `worlddb > instance_template.map` — always cross-check before wiring triggers.
- **Bosses with no dangerous mechanics** still need start/end fight triggers for consistency, but `InitCombatTriggers` can be omitted from their fight strategy.
- **Multiple wings sharing a map ID** (SM, LBRS/UBRS): use one instance strategy with all wing bosses registered. The bot strategy enable/disable for each boss is independent.
- When in doubt about how something should look, check the Onyxia implementation as the canonical cmangos pattern:
  - `src/Ai/Raid/OnyxiasLair/` — trigger, action, strategy files
  - `src/Ai/Base/generic/DungeonStrategy.cpp` — how enter/leave is wired
