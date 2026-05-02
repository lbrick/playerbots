#include "playerbot/playerbot.h"
#include "MaraStrategy.h"

using namespace ai;

// ── MaraudonDungeonStrategy ───────────────────────────────────────────────────

void MaraudonDungeonStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "start noxxion fight",
        NextAction::array(0, new NextAction("enable noxxion fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start razorlash fight",
        NextAction::array(0, new NextAction("enable razorlash fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start lord vyletongue fight",
        NextAction::array(0, new NextAction("enable lord vyletongue fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start celebras the cursed fight",
        NextAction::array(0, new NextAction("enable celebras the cursed fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start landslide fight",
        NextAction::array(0, new NextAction("enable landslide fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start tinkerer gizlock fight",
        NextAction::array(0, new NextAction("enable tinkerer gizlock fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start rotgrip fight",
        NextAction::array(0, new NextAction("enable rotgrip fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start princess theradras fight",
        NextAction::array(0, new NextAction("enable princess theradras fight strategy", 100.0f), NULL)));
}

void MaraudonDungeonStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "start noxxion fight",
        NextAction::array(0, new NextAction("enable noxxion fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start razorlash fight",
        NextAction::array(0, new NextAction("enable razorlash fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start lord vyletongue fight",
        NextAction::array(0, new NextAction("enable lord vyletongue fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start celebras the cursed fight",
        NextAction::array(0, new NextAction("enable celebras the cursed fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start landslide fight",
        NextAction::array(0, new NextAction("enable landslide fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start tinkerer gizlock fight",
        NextAction::array(0, new NextAction("enable tinkerer gizlock fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start rotgrip fight",
        NextAction::array(0, new NextAction("enable rotgrip fight strategy", 100.0f), NULL)));

    triggers.push_back(new TriggerNode(
        "start princess theradras fight",
        NextAction::array(0, new NextAction("enable princess theradras fight strategy", 100.0f), NULL)));
}

// ── NoxxionFightStrategy ──────────────────────────────────────────────────────

void NoxxionFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Noxious Fumes ~8yd AoE — stay >10yd
    triggers.push_back(new TriggerNode(
        "noxxion noxious fumes",
        NextAction::array(0, new NextAction("noxxion move away from noxious fumes", ACTION_MOVE + 5), NULL)));
}

void NoxxionFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end noxxion fight",
        NextAction::array(0, new NextAction("disable noxxion fight strategy", 100.0f), NULL)));
}

void NoxxionFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end noxxion fight",
        NextAction::array(0, new NextAction("disable noxxion fight strategy", 100.0f), NULL)));
}

// ── RazorlashFightStrategy ────────────────────────────────────────────────────

void RazorlashFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end razorlash fight",
        NextAction::array(0, new NextAction("disable razorlash fight strategy", 100.0f), NULL)));
}

void RazorlashFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end razorlash fight",
        NextAction::array(0, new NextAction("disable razorlash fight strategy", 100.0f), NULL)));
}

// ── LordVyletongeFightStrategy ────────────────────────────────────────────────

void LordVyletongeFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end lord vyletongue fight",
        NextAction::array(0, new NextAction("disable lord vyletongue fight strategy", 100.0f), NULL)));
}

void LordVyletongeFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end lord vyletongue fight",
        NextAction::array(0, new NextAction("disable lord vyletongue fight strategy", 100.0f), NULL)));
}

// ── CelebrasTheCursedFightStrategy ────────────────────────────────────────────

void CelebrasTheCursedFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end celebras the cursed fight",
        NextAction::array(0, new NextAction("disable celebras the cursed fight strategy", 100.0f), NULL)));
}

void CelebrasTheCursedFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end celebras the cursed fight",
        NextAction::array(0, new NextAction("disable celebras the cursed fight strategy", 100.0f), NULL)));
}

// ── LandslideFightStrategy ────────────────────────────────────────────────────

void LandslideFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end landslide fight",
        NextAction::array(0, new NextAction("disable landslide fight strategy", 100.0f), NULL)));
}

void LandslideFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end landslide fight",
        NextAction::array(0, new NextAction("disable landslide fight strategy", 100.0f), NULL)));
}

// ── TinkererGizlockFightStrategy ──────────────────────────────────────────────

void TinkererGizlockFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Smoke Bomb ~8yd AoE — stay >10yd
    triggers.push_back(new TriggerNode(
        "gizlock smoke bomb",
        NextAction::array(0, new NextAction("gizlock move away from smoke bomb", ACTION_MOVE + 5), NULL)));
}

void TinkererGizlockFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end tinkerer gizlock fight",
        NextAction::array(0, new NextAction("disable tinkerer gizlock fight strategy", 100.0f), NULL)));
}

void TinkererGizlockFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end tinkerer gizlock fight",
        NextAction::array(0, new NextAction("disable tinkerer gizlock fight strategy", 100.0f), NULL)));
}

// ── RotgripFightStrategy ──────────────────────────────────────────────────────

void RotgripFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end rotgrip fight",
        NextAction::array(0, new NextAction("disable rotgrip fight strategy", 100.0f), NULL)));
}

void RotgripFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end rotgrip fight",
        NextAction::array(0, new NextAction("disable rotgrip fight strategy", 100.0f), NULL)));
}

// ── PrincessTheadrasFightStrategy ─────────────────────────────────────────────

void PrincessTheadrasFightStrategy::InitCombatTriggers(std::list<TriggerNode*>& triggers)
{
    // Dust Field ~10yd AoE — stay >12yd
    triggers.push_back(new TriggerNode(
        "theradras dust field",
        NextAction::array(0, new NextAction("theradras move away from dust field", ACTION_MOVE + 5), NULL)));
}

void PrincessTheadrasFightStrategy::InitNonCombatTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end princess theradras fight",
        NextAction::array(0, new NextAction("disable princess theradras fight strategy", 100.0f), NULL)));
}

void PrincessTheadrasFightStrategy::InitDeadTriggers(std::list<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode(
        "end princess theradras fight",
        NextAction::array(0, new NextAction("disable princess theradras fight strategy", 100.0f), NULL)));
}
