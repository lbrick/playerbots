# Razorfen Kraul — Implementation Plan

**Map ID:** 47  
**Levels:** 25–38  
**Status:** ⬜ TODO  

---

## Boss Reference

| Boss | NPC ID | Mechanic | Trigger Type | Action |
|------|--------|----------|--------------|--------|
| Roogug | 6168 | Lightning Bolt (ranged), summons Earth Rumbler adds, flees at 15% HP | None — start/end only | — |
| Aggem Thorncurse | 4424 | Summon Boar Spirit (adds), Battle Shout, self-heal | None — add handling by existing targeting | — |
| Death Speaker Jargba | 4428 | Dominate Mind (mind control), Shadow Bolt | None — no positional mechanic | — |
| Overlord Ramtusk | 4420 | **Thunderclap** (spell 15548) — 8yd AoE physical around boss | `CloseToHostileCreatureHazardTrigger(4420, 8, 3)` | `MoveAwayFromCreature(4420, 10)` |
| Agathelos the Raging | 4422 | **Rampage** (spell 8285) — 8yd AoE physical around boss; Rushing Charge (stun target); ward gate mechanic | `CloseToHostileCreatureHazardTrigger(4422, 8, 3)` | `MoveAwayFromCreature(4422, 10)` |
| Charlga Razorflank | 4421 | **Chain Bolt** (spell 8292) — chains between players within ~8yd of each other | `TooCloseToAllyTrigger(8.0f)` *(new base class — see §A)* | `SpreadFromAlliesAction(10.0f)` *(new base class — see §B)* |

> **Agathelos ward gate:** Four Ward Keepers (NPC 4625) guard the gate (GO 21099) before Agathelos.
> Must be killed to open the gate. No bot mechanic needed — existing kill logic handles them.

---

## Files to Create

```
playerbot/strategy/dungeons/RazorfenKraul/
  Action/
    RfkActions.h       — instance + all 6 boss enable/disable + Ramtusk/Agathelos MoveAway + Charlga spread
  Trigger/
    RfkTriggers.h      — instance enter/leave + all 6 boss start/end + Ramtusk/Agathelos AoE + Charlga spread
  Strategy/
    RfkStrategy.h      — class declarations
    RfkStrategy.cpp    — all strategy initializers
  RFK_PLAN.md          — this file
```

New base-class files (shared, not RFK-specific):

```
playerbot/strategy/triggers/DungeonTriggers.h   — add TooCloseToAllyTrigger
playerbot/strategy/triggers/DungeonTriggers.cpp — implement TooCloseToAllyTrigger::IsActive
playerbot/strategy/actions/DungeonActions.h     — add SpreadFromAlliesAction
playerbot/strategy/actions/DungeonActions.cpp   — implement SpreadFromAlliesAction::Execute
```

---

## §A — New Base Trigger: `TooCloseToAllyTrigger`

**File:** `playerbot/strategy/triggers/DungeonTriggers.h`

Chain Bolt and similar "jump between nearby players" spells require bots to maintain spacing.
The trigger fires when the bot is within `spreadRadius` of any living group member.

### Header addition

```cpp
// Fires when bot is within spreadRadius yards of any living group member.
// Used for chain-bounce mechanics (Chain Bolt, Chain Lightning, etc.).
class TooCloseToAllyTrigger : public Trigger
{
public:
    TooCloseToAllyTrigger(PlayerbotAI* ai, std::string name, float spreadRadius)
        : Trigger(ai, name, 1)
        , spreadRadius(spreadRadius) {}

    bool IsActive() override;

protected:
    float spreadRadius;
};
```

### Implementation in `DungeonTriggers.cpp`

```cpp
bool TooCloseToAllyTrigger::IsActive()
{
    if (!bot->IsInWorld() || bot->IsBeingTeleported())
        return false;

    Group* group = bot->GetGroup();
    if (!group)
        return false;

    for (GroupReference* ref = group->GetFirstMember(); ref; ref = ref->next())
    {
        Player* member = ref->getSource();
        if (!member || member == bot || !member->IsAlive())
            continue;
        if (member->GetMapId() != bot->GetMapId())
            continue;
        if (bot->GetDistance(member, true, DIST_CALC_NONE) <= spreadRadius)
            return true;
    }

    return false;
}
```

**Key design choices:**
- `DIST_CALC_NONE` = raw 3D distance, no combat-reach padding. Matches how Chain Bolt range works.
- Skips dead members — no point spreading from a corpse.
- Check interval = 1 (every evaluation tick) — chain jumps fire quickly; we want fast response.
- Does NOT suppress when already moving (unlike `CloseToHazardTrigger`) — if a bot finishes a
  move but lands adjacent to another party member, it should spread again.

---

## §B — New Base Action: `SpreadFromAlliesAction`

**File:** `playerbot/strategy/actions/DungeonActions.h`

Moves the bot to a point at least `targetSpread` yards from the closest ally.
Modeled after `MoveAwayFromCreature` — same angle-sweep search, but allies are the obstacle.

### Header addition

```cpp
// Moves bot to be at least targetSpread yards from the nearest group member.
// Used in response to TooCloseToAllyTrigger for chain-bounce avoidance.
class SpreadFromAlliesAction : public MovementAction
{
public:
    SpreadFromAlliesAction(PlayerbotAI* ai, std::string name, float targetSpread)
        : MovementAction(ai, name)
        , targetSpread(targetSpread) {}

    bool Execute(Event& event) override;
    bool isPossible() override;

private:
    // Returns nullptr if no living ally is within targetSpread.
    Player* FindClosestAlly() const;
    bool IsValidSpreadPoint(const WorldPosition& point, const std::list<HazardPosition>& hazards) const;

    float targetSpread;
};
```

### Implementation in `DungeonActions.cpp`

```cpp
bool SpreadFromAlliesAction::Execute(Event& event)
{
    Player* closest = FindClosestAlly();
    if (!closest)
        return false;

    const std::list<HazardPosition>& hazards = AI_VALUE(std::list<HazardPosition>, "hazards");

    const WorldPosition botPos(bot);
    const WorldPosition allyPos(closest);

    // Starting angle: directly away from the closest ally
    float angle = allyPos.getAngleTo(botPos);

    const uint8 attempts = 20;
    const float angleStep = (float)(M_PI / (attempts * 0.5f));

    for (uint8 i = 0; i < attempts; ++i)
    {
        const float dir = (i % 2 == 0) ? 1.0f : -1.0f;
        const float sweepAngle = angle + dir * (i / 2) * angleStep;

        WorldPosition point = allyPos + WorldPosition(
            0,
            targetSpread * cos(sweepAngle),
            targetSpread * sin(sweepAngle),
            1.0f);
        point.setZ(point.getHeight());

        if (IsValidSpreadPoint(point, hazards))
        {
            if (bot->IsWithinLOS(point.getX(), point.getY(), point.getZ() + bot->GetCollisionHeight())
                && botPos.canPathTo(point, bot))
            {
                if (MoveTo(bot->GetMapId(), point.getX(), point.getY(), point.getZ(),
                           false, IsReaction(), false, true))
                {
                    if (IsReaction())
                        WaitForReach(point.distance(botPos));
                    return true;
                }
            }
        }
    }

    return false;
}

bool SpreadFromAlliesAction::isPossible()
{
    return MovementAction::isPossible() && ai->CanMove();
}

Player* SpreadFromAlliesAction::FindClosestAlly() const
{
    Group* group = bot->GetGroup();
    if (!group)
        return nullptr;

    Player* closest = nullptr;
    float closestDist = targetSpread + 1.0f; // only care about allies inside spread radius

    for (GroupReference* ref = group->GetFirstMember(); ref; ref = ref->next())
    {
        Player* member = ref->getSource();
        if (!member || member == bot || !member->IsAlive())
            continue;
        if (member->GetMapId() != bot->GetMapId())
            continue;

        const float dist = bot->GetDistance(member, true, DIST_CALC_NONE);
        if (dist < closestDist)
        {
            closestDist = dist;
            closest = member;
        }
    }

    return closest;
}

bool SpreadFromAlliesAction::IsValidSpreadPoint(const WorldPosition& point,
                                                 const std::list<HazardPosition>& hazards) const
{
    // Reject if any hazard overlaps the candidate point
    for (const HazardPosition& hazard : hazards)
    {
        if (point.distance(hazard.first) < hazard.second)
            return false;
    }
    return true;
}
```

**Key design choices:**
- Sweeps left-right symmetrically from the "directly away" angle — same pattern as `MoveAwayFromCreature`.
- `targetSpread` sets both the "too close" threshold in the trigger and the escape distance in
  the action. Use the same value (10.0f for Charlga) to guarantee the action resolves the trigger.
- Respects the hazard list — won't spread into Ramtusk's Thunderclap zone.
- `FindClosestAlly` only returns an ally that is still within `targetSpread`; if the trigger
  fires but the ally moved away before the action executes, returns nullptr and yields false.

---

## §C — Charlga-Specific Subclasses (in `RfkTriggers.h` / `RfkActions.h`)

```cpp
// In RfkTriggers.h
class CharlgaChainBoltSpreadTrigger : public TooCloseToAllyTrigger
{
public:
    CharlgaChainBoltSpreadTrigger(PlayerbotAI* ai)
        : TooCloseToAllyTrigger(ai, "charlga chain bolt spread", 8.0f) {}
};

// In RfkActions.h
class CharlgaSpreadAction : public SpreadFromAlliesAction
{
public:
    CharlgaSpreadAction(PlayerbotAI* ai)
        : SpreadFromAlliesAction(ai, "charlga spread from chain bolt", 10.0f) {}
};
```

Register in `CharlgaFightStrategy::InitCombatTriggers`:

```cpp
triggers.push_back(new TriggerNode(
    "charlga chain bolt spread",
    NextAction::array(0, new NextAction("charlga spread from chain bolt", ACTION_MOVE + 5), NULL)));
```

Context registrations (additional lines vs. other bosses):

```cpp
// TriggerContext.h
creators["charlga chain bolt spread"] = [](PlayerbotAI* ai) { return new CharlgaChainBoltSpreadTrigger(ai); };

// ActionContext.h
creators["charlga spread from chain bolt"] = [](PlayerbotAI* ai) { return new CharlgaSpreadAction(ai); };
```

---

## Updated Registration Checklist

- [ ] `playerbot/strategy/triggers/DungeonTriggers.h` — add `TooCloseToAllyTrigger` class
- [ ] `playerbot/strategy/triggers/DungeonTriggers.cpp` — implement `TooCloseToAllyTrigger::IsActive`
- [ ] `playerbot/strategy/actions/DungeonActions.h` — add `SpreadFromAlliesAction` class
- [ ] `playerbot/strategy/actions/DungeonActions.cpp` — implement `SpreadFromAlliesAction` methods
- [ ] `playerbot/strategy/generic/DungeonStrategy.cpp` — enter/leave RFK in combat + noncombat
- [ ] `playerbot/strategy/triggers/TriggerContext.h` — include RfkTriggers.h + all 15 RFK creators
- [ ] `playerbot/strategy/actions/ActionContext.h` — include RfkActions.h + all 14 RFK creators
- [ ] `playerbot/strategy/StrategyContext.h` — include RfkStrategy.h + 7 RFK strategy creators
- [ ] `CMakeLists.txt` — `Ai_Dungeon_RFK` GLOB_RECURSE added + included in LIBRARY_SRCS

---

## Strategy String Names

| Thing | String |
|-------|--------|
| Instance strategy | `"razorfen kraul"` |
| Enter trigger | `"enter razorfen kraul"` |
| Leave trigger | `"leave razorfen kraul"` |
| Roogug fight | `"roogug"` |
| Aggem Thorncurse fight | `"aggem thorncurse"` |
| Death Speaker Jargba fight | `"death speaker jargba"` |
| Overlord Ramtusk fight | `"overlord ramtusk"` |
| Agathelos fight | `"agathelos"` |
| Charlga fight | `"charlga razorflank"` |
| Ramtusk Thunderclap trigger | `"ramtusk thunderclap"` |
| Agathelos Rampage trigger | `"agathelos rampage"` |
| Charlga spread trigger | `"charlga chain bolt spread"` |
| Charlga spread action | `"charlga spread from chain bolt"` |

---

## Build Status

- [ ] `./build.sh` — clean, no new errors

---

## Definition of Done

- [ ] Build clean
- [ ] Bot enters RFK → instance strategy loads (log: `enable razorfen kraul strategy`)
- [ ] Roogug engaged → roogug fight strategy enables
- [ ] Aggem Thorncurse engaged → aggem thorncurse fight strategy enables
- [ ] Death Speaker Jargba engaged → death speaker jargba fight strategy enables
- [ ] Overlord Ramtusk engaged → overlord ramtusk fight strategy enables; bots move >10yd during Thunderclap
- [ ] Agathelos engaged → agathelos fight strategy enables; bots move >10yd during Rampage
- [ ] Charlga engaged → charlga razorflank fight strategy enables; bots spread >10yd apart
- [ ] Each boss dies → fight strategy disables
- [ ] Bot leaves RFK → instance strategy unloads (log: `disable razorfen kraul strategy`)

---

## Verify Commands

With `LogFileLevel = 3`, grep Server.log for:
```
enable razorfen kraul strategy
enable overlord ramtusk fight strategy
ramtusk thunderclap
overlord ramtusk move away from thunderclap
enable agathelos fight strategy
agathelos rampage
agathelos move away from rampage
enable charlga razorflank fight strategy
charlga chain bolt spread
charlga spread from chain bolt
disable razorfen kraul strategy
```

---

## Spell Reference

| Spell | ID | Radius | Source |
|-------|----|--------|--------|
| Rushing Charge (Agathelos) | 8260 | — (targeted charge) | EventAI |
| Rampage (Agathelos) | 8285 | ~8yd (EffectRadiusIndex1=13) | EventAI |
| Left for Dead (Agathelos) | 8555 | — (knockdown) | EventAI |
| Thunderclap (Ramtusk) | 15548 | ~8yd (EffectRadiusIndex1=13) | EventAI |
| Chain Bolt (Charlga) | 8292 | jumps to targets within ~8yd | EventAI |
| Dominate Mind (Jargba) | 14515 | 20yd cast range | EventAI |
| Summon Boar Spirit (Aggem) | 8286 | — (summon) | EventAI |

---

## Next Step

Implement in order:

1. `TooCloseToAllyTrigger` in `DungeonTriggers.h/.cpp`
2. `SpreadFromAlliesAction` in `DungeonActions.h/.cpp`
3. `RfkTriggers.h` (all triggers inc. Charlga subclass)
4. `RfkActions.h` (all actions inc. Charlga subclass)
5. `RfkStrategy.h` + `RfkStrategy.cpp`
6. Four registration edits (DungeonStrategy.cpp, TriggerContext.h, ActionContext.h, StrategyContext.h)
7. CMakeLists.txt
8. `./build.sh` verify
