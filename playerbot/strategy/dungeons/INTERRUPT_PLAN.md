# Dungeon Interrupt Implementation Plan

**Pattern (from SFK/WC reference implementations):**
1. Add `TargetCastingSpellTrigger` subclass to `<Dungeon>Triggers.h`
2. Register in `TriggerContext.h`
3. Add `TriggerNode` in boss's `FightStrategy::InitCombatTriggers` → `"interrupt enemy cast"` at `ACTION_HIGH + 5`

No new action classes needed — `"interrupt enemy cast"` is global.

> **All spell IDs in this plan are DB-verified** against `classicmangos.creature_ai_scripts` (DB-scripted bosses)
> and `mangos-classic` C++ ScriptDevAI sources (scripted bosses). Cast time verified via `CastingTimeIndex != 1`
> and `InterruptFlags > 0`. Instant-cast spells (CastingTimeIndex=1) are not interruptible by kick/etc.

---

## Already Implemented

| Dungeon | Boss | Spell | Spell ID | Status |
|---------|------|-------|----------|--------|
| SFK | Commander Springvale | Holy Light | 1026 | ✅ Done |
| WC | Generic trash | Druid's Slumber | 8040 | ✅ Done |

---

## Priority 1 — Critical

### SM: High Inquisitor Whitemane — Heal
**Why:** Whitemane casts Heal (12039) on herself and Mograine after resurrection. Without interrupt the Cathedral fight loops forever.
- Boss NPC: 3977 — fight strategy exists
- Spell ID: **12039** (name `Heal`, CastingTimeIndex=14, InterruptFlags=15 — confirmed interruptible)
- Source: `boss_mograine_and_whitemane.cpp` line `SPELL_HEAL = 12039`
- Trigger class: `WhitemaneHealCastingTrigger : public TargetCastingSpellTrigger`
- Trigger name: `"target casting whitemane heal"`
- Files: `SmTriggers.h`, `TriggerContext.h`, `SmStrategy.cpp` (WhitemaneFightStrategy::InitCombatTriggers)

---

## Priority 2 — Pending (stubs in code, just need spell IDs)

### BFD: Twilight Lord Kelris — Sleep
**Why:** Sleep disables a player for several seconds mid-fight.
- Boss NPC: 4832 — fight strategy exists (stub)
- Spell ID: **8399** (name `Sleep`, CastingTimeIndex=50, InterruptFlags=15 — confirmed interruptible)
- Source: `creature_ai_scripts` action1_param1=8399
- Trigger class: `KelrisSleepCastingTrigger : public TargetCastingSpellTrigger`
- Trigger name: `"target casting kelris sleep"`
- Files: `BfdTriggers.h`, `TriggerContext.h`, `BfdStrategy.cpp`

### BFD: Lorgus Jett — Lightning Bolt
**Note:** He casts Lightning Bolt, NOT Chain Lightning (plan previously wrong).
- Boss NPC: 12902 — fight strategy exists (stub)
- Spell ID: **12167** (name `Lightning Bolt`, CastingTimeIndex=14, InterruptFlags=15 — confirmed interruptible)
- Source: `creature_ai_scripts` action1_param1=12167
- Trigger class: `LorgusJettLightningBoltCastingTrigger : public TargetCastingSpellTrigger`
- Trigger name: `"target casting lorgus jett lightning bolt"`
- Files: `BfdTriggers.h`, `TriggerContext.h`, `BfdStrategy.cpp`

---

## Priority 3 — High Value (CC / trap)

### Strat: Maleki the Pallid — Ice Tomb
**Why:** Ice Tomb (16869) traps a player inside an ice block. High disruptive value.
**Note:** Maleki has NO Frost Nova — previous plan was wrong. His spells are Frostbolt + Ice Tomb + Drain Life/Mana.
- Boss NPC: 10438 — fight strategy exists
- Spell ID: **16869** (name `Ice Tomb`, CastingTimeIndex=16, InterruptFlags=15 — confirmed interruptible)
- Source: `boss_maleki_the_pallid.cpp` `SPELL_ICE_TOMB = 16869`
- Trigger class: `MalekiIceTombCastingTrigger : public TargetCastingSpellTrigger`
- Trigger name: `"target casting maleki ice tomb"`
- Files: `StratTriggers.h`, `TriggerContext.h`, `StratStrategy.cpp`

### Strat: Balnazzar — Sleep
**Note:** Balnazzar's Psychic Scream (13704) is INSTANT — not interruptible. His Sleep IS interruptible.
- Boss NPC: 10813 — fight strategy exists
- Spell ID: **12098** (name `Sleep`, CastingTimeIndex=4, InterruptFlags=15 — confirmed interruptible)
- Source: `boss_dathrohan_balnazzar.cpp` `SPELL_SLEEP = 12098`
- Trigger class: `BalnazzarSleepCastingTrigger : public TargetCastingSpellTrigger`
- Trigger name: `"target casting balnazzar sleep"`
- Files: `StratTriggers.h`, `TriggerContext.h`, `StratStrategy.cpp`

---

## Priority 4 — Medium Value

### Scholo: Ras Frostwhisper — Freeze
**Note:** Ras uses Chill Nova (18099) which is INSTANT — not interruptible. His Freeze IS interruptible (roots/freezes players).
- Boss NPC: 10508 — AoE avoidance already exists
- Spell ID: **18763** (name `Freeze`, CastingTimeIndex=22, InterruptFlags=15 — confirmed interruptible)
- Source: `creature_ai_scripts` action1_param1=18763
- Trigger class: `RasFreezeSpellCastingTrigger : public TargetCastingSpellTrigger`
- Trigger name: `"target casting ras freeze"`
- Files: `ScholoTriggers.h`, `TriggerContext.h`, `ScholoStrategy.cpp`

### Scholo: Vectus — Flamestrike
**Note:** Vectus uses Blast Wave (16046, instant) + Flamestrike. NO Blizzard — previous plan was wrong.
- Boss NPC: 10432 — AoE avoidance exists (avoidance handles Blast Wave; interrupt Flamestrike ground-effect)
- Spell ID: **18399** (name `Flamestrike`, CastingTimeIndex=14, InterruptFlags=15 — confirmed interruptible)
- Source: `creature_ai_scripts` action1_param1=18399
- Trigger class: `VectusFlamestrikeSpellCastingTrigger : public TargetCastingSpellTrigger`
- Trigger name: `"target casting vectus flamestrike"`
- Files: `ScholoTriggers.h`, `TriggerContext.h`, `ScholoStrategy.cpp`

### BRD: High Interrogator Gerstahn — Mana Burn
**Note:** Gerstahn's Psychic Scream (13704) is INSTANT — not interruptible. Mana Burn drains mana from casters.
- Boss NPC: 9018 — fight strategy exists
- Spell ID: **14033** (name `Mana Burn`, CastingTimeIndex=14, InterruptFlags=15 — confirmed interruptible)
- Source: `boss_high_interrogator_gerstahn.cpp` `SPELL_MANABURN = 14033`
- Trigger class: `GersthahnManaBurnCastingTrigger : public TargetCastingSpellTrigger`
- Trigger name: `"target casting gerstahn mana burn"`
- Files: `BrdTriggers.h`, `TriggerContext.h`, `BrdStrategy.cpp`

### Strat: Maleki the Pallid — Frostbolt
Secondary interrupt for Maleki alongside Ice Tomb.
- Boss NPC: 10438
- Spell ID: **17503** (name `Frostbolt`, CastingTimeIndex=5, InterruptFlags=15 — confirmed interruptible)
- Source: `boss_maleki_the_pallid.cpp` `SPELL_FROSTBOLT = 17503`
- Trigger class: `MalekiFrostboltCastingTrigger : public TargetCastingSpellTrigger`
- Trigger name: `"target casting maleki frostbolt"`
- Files: `StratTriggers.h`, `TriggerContext.h`, `StratStrategy.cpp`

---

## Priority 5 — Low Value / Nice to Have

### RFC: Jergosh the Invoker — Immolate
- Boss NPC: 11518 — fight strategy exists
- Spell ID: **20800** (name `Immolate`, CastingTimeIndex=5, InterruptFlags=15 — confirmed interruptible)
- Source: `creature_ai_scripts` action1_param1=20800
- Trigger class: `JergoshImmolateSpellCastingTrigger : public TargetCastingSpellTrigger`
- Trigger name: `"target casting jergosh immolate"`
- Files: `RfcTriggers.h`, `TriggerContext.h`, `RfcStrategy.cpp`

### Mara: Celebras the Cursed — Wrath
**Note:** Celebras NPC ID is **12225**, not 12519 (plan previously wrong).
- Boss NPC: 12225 — fight strategy exists
- Spell ID: **21807** (name `Wrath`, CastingTimeIndex=5, InterruptFlags=15 — confirmed interruptible)
- Also has Entangling Roots **12747** (CastingTimeIndex=16, InterruptFlags=9 — interruptible, roots player)
- Source: `creature_ai_scripts` for NPC 12225
- Trigger classes: `CelebrasWrathCastingTrigger`, `CelebrasRootsCastingTrigger`
- Trigger names: `"target casting celebras wrath"`, `"target casting celebras roots"`
- Files: `MaraTriggers.h`, `TriggerContext.h`, `MaraStrategy.cpp`

---

## Removed from Plan (verified NOT interruptible)

| Boss | Spell | Reason |
|------|-------|--------|
| Jammal'an the Prophet | Hex of Jammal'an (12479) | Instant cast (CastingTimeIndex=1) |
| Shadowpriest Sezz'ziz | Psychic Scream (13704) | Instant cast — he has NO heal spell in AI scripts |
| Balnazzar | Psychic Scream (13704) | Instant cast |
| Ras Frostwhisper | Chill Nova (18099) | Instant cast |
| Vectus | Blast Wave (16046) | Instant cast |
| Gerstahn | Psychic Scream (13704) | Instant cast |
| Instructor Malicia | Poison Nova | Does NOT exist in her AI scripts — uses Renew/Corruption/Call of the Grave |

---

## Implementation Order

- [x] **Step 1:** SM Whitemane Heal 12039 (highest fight impact)
- [x] **Step 2:** BFD Kelris Sleep 8399 + Lorgus Jett Lightning Bolt 12167 (stubbed — easy add)
- [x] **Step 3:** Strat Maleki Ice Tomb 16869 + Frostbolt 17503
- [x] **Step 4:** Strat Balnazzar Sleep 12098
- [x] **Step 5:** Scholo Ras Freeze 18763 + Vectus Flamestrike 18399 (batch — same files)
- [x] **Step 6:** BRD Gerstahn Mana Burn 14033
- [x] **Step 7:** RFC Jergosh Immolate 20800 + Mara Celebras Wrath/Roots (low priority)
- [ ] **Step 8:** Build + in-game verify each dungeon

---

## Checklist per interrupt

- [x] Add trigger class to `<Dungeon>Triggers.h`
- [x] Register in `TriggerContext.h`
- [x] Add `TriggerNode` in boss `FightStrategy::InitCombatTriggers`
- [x] `./build.sh` clean

---

## Party Chat Announce

**Goal:** Bot says in party chat what it's interrupting before it fires.  
**Scope:** All dungeon interrupts — `InterruptEnemyCastAction` is used only by dungeon strategies (class interrupt abilities use separate actions), so modifying it here affects only dungeon context.

### Design

Modify `InterruptEnemyCastAction::Execute` in `DungeonActions.cpp`.  
When the bot finds a valid interrupt spell, broadcast a party message **before** casting.

Message format: `"Interrupting <spell name>!"`  
Spell name: read from `target->GetCurrentSpell(CURRENT_GENERIC_SPELL)` → `m_spellInfo->SpellName[0]`.  
Fall back to `target->GetCurrentSpell(CURRENT_CHANNELED_SPELL)` if generic returns null (channelled cast).  
Fall back to `"the spell"` if neither resolves.

### Implementation — `DungeonActions.cpp`

**File:** `playerbot/strategy/actions/DungeonActions.cpp`  
**Function:** `InterruptEnemyCastAction::Execute`  
No new includes needed — `PlayerbotAI.h` already pulls in `Group`, `ChatHandler`, and `Unit`.

```cpp
bool InterruptEnemyCastAction::Execute(Event& event)
{
    Unit* target = AI_VALUE(Unit*, "current target");
    if (!target)
        return false;

    static const std::vector<std::string> interruptSpells = {
        "kick", "pummel", "shield bash", "counterspell",
        "wind shear", "spell lock", "hammer of justice", "earth shock"
    };

    for (const auto& spell : interruptSpells)
    {
        if (ai->CanCastSpell(spell, target, 0))
        {
            Group* group = bot->GetGroup();
            if (group)
            {
                std::string targetSpellName = "the spell";
                Spell* castingSpell = target->GetCurrentSpell(CURRENT_GENERIC_SPELL);
                if (!castingSpell)
                    castingSpell = target->GetCurrentSpell(CURRENT_CHANNELED_SPELL);
                if (castingSpell && castingSpell->m_spellInfo)
                    targetSpellName = castingSpell->m_spellInfo->SpellName[0];

                std::string msg = std::string("Interrupting ") + targetSpellName + "!";
                WorldPacket data;
                ChatHandler::BuildChatPacket(data, CHAT_MSG_PARTY, msg.c_str(), LANG_UNIVERSAL,
                    CHAT_TAG_NONE, bot->GetObjectGuid(), bot->GetName());
                group->BroadcastPacket(data, true);
            }
            return ai->CastSpell(spell, target);
        }
    }
    return false;
}
```

### Checklist

- [x] Apply change to `DungeonActions.cpp`
- [x] `./build.sh` clean
- [ ] In-game test: bot announces before interrupt fires
- [ ] Verify message appears in party chat (not /say)
- [ ] Verify no double-announce if two bots both have interrupt available (only one fires — first CanCastSpell winner)
