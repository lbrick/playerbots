#pragma once
#include "playerbot/strategy/triggers/DungeonTriggers.h"

namespace ai
{
    // ── Instance enter/leave (Map ID 109) ───────────────────────────────────────
    class TempleOfAtalHakkarEnterDungeonTrigger : public EnterDungeonTrigger
    {
    public:
        TempleOfAtalHakkarEnterDungeonTrigger(PlayerbotAI* ai)
            : EnterDungeonTrigger(ai, "enter temple of atal'hakkar", "temple of atal'hakkar", 109) {}
    };

    class TempleOfAtalHakkarLeaveDungeonTrigger : public LeaveDungeonTrigger
    {
    public:
        TempleOfAtalHakkarLeaveDungeonTrigger(PlayerbotAI* ai)
            : LeaveDungeonTrigger(ai, "leave temple of atal'hakkar", "temple of atal'hakkar", 109) {}
    };

    // ── Lower Ring Mini-Bosses ───────────────────────────────────────────────────

    // Zolo (5712) — DB verified
    class ZoloStartFightTrigger : public StartBossFightTrigger
    {
    public:
        ZoloStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start zolo fight", "zolo", 5712) {}
    };

    class ZoloEndFightTrigger : public EndBossFightTrigger
    {
    public:
        ZoloEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end zolo fight", "zolo", 5712) {}
    };

    // Hukku (5715) — DB verified
    class HukkuStartFightTrigger : public StartBossFightTrigger
    {
    public:
        HukkuStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start hukku fight", "hukku", 5715) {}
    };

    class HukkuEndFightTrigger : public EndBossFightTrigger
    {
    public:
        HukkuEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end hukku fight", "hukku", 5715) {}
    };

    // Gasher (5713) — DB verified
    class GasherStartFightTrigger : public StartBossFightTrigger
    {
    public:
        GasherStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start gasher fight", "gasher", 5713) {}
    };

    class GasherEndFightTrigger : public EndBossFightTrigger
    {
    public:
        GasherEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end gasher fight", "gasher", 5713) {}
    };

    // Loro (5714) — DB verified
    class LoroStartFightTrigger : public StartBossFightTrigger
    {
    public:
        LoroStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start loro fight", "loro", 5714) {}
    };

    class LoroEndFightTrigger : public EndBossFightTrigger
    {
    public:
        LoroEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end loro fight", "loro", 5714) {}
    };

    // Mijan (5717) — DB verified
    class MijanStartFightTrigger : public StartBossFightTrigger
    {
    public:
        MijanStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start mijan fight", "mijan", 5717) {}
    };

    class MijanEndFightTrigger : public EndBossFightTrigger
    {
    public:
        MijanEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end mijan fight", "mijan", 5717) {}
    };

    // Zul'Lor (5716) — DB verified
    class ZulLorStartFightTrigger : public StartBossFightTrigger
    {
    public:
        ZulLorStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start zul'lor fight", "zul'lor", 5716) {}
    };

    class ZulLorEndFightTrigger : public EndBossFightTrigger
    {
    public:
        ZulLorEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end zul'lor fight", "zul'lor", 5716) {}
    };

    // ── Upper Temple Bosses ──────────────────────────────────────────────────────

    // Jammal'an the Prophet (5710) — DB verified; no longer shares ID with Zul'Lor
    class JammalanStartFightTrigger : public StartBossFightTrigger
    {
    public:
        JammalanStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start jammal'an the prophet fight", "jammal'an the prophet", 5710) {}
    };

    class JammalanEndFightTrigger : public EndBossFightTrigger
    {
    public:
        JammalanEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end jammal'an the prophet fight", "jammal'an the prophet", 5710) {}
    };

    // Ogom the Wretched (5711) — DB verified
    class OgomStartFightTrigger : public StartBossFightTrigger
    {
    public:
        OgomStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start ogom the wretched fight", "ogom the wretched", 5711) {}
    };

    class OgomEndFightTrigger : public EndBossFightTrigger
    {
    public:
        OgomEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end ogom the wretched fight", "ogom the wretched", 5711) {}
    };

    // Morphaz (5719) — DB verified
    class MorphazStartFightTrigger : public StartBossFightTrigger
    {
    public:
        MorphazStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start morphaz fight", "morphaz", 5719) {}
    };

    class MorphazEndFightTrigger : public EndBossFightTrigger
    {
    public:
        MorphazEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end morphaz fight", "morphaz", 5719) {}
    };

    // Hazzas (5722) — DB verified
    class HazzasStartFightTrigger : public StartBossFightTrigger
    {
    public:
        HazzasStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start hazzas fight", "hazzas", 5722) {}
    };

    class HazzasEndFightTrigger : public EndBossFightTrigger
    {
    public:
        HazzasEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end hazzas fight", "hazzas", 5722) {}
    };

    // Shade of Eranikus (5709) — DB verified; War Stomp ~8yd AoE
    class ShadeOfEranikusStartFightTrigger : public StartBossFightTrigger
    {
    public:
        ShadeOfEranikusStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start shade of eranikus fight", "shade of eranikus", 5709) {}
    };

    class ShadeOfEranikusEndFightTrigger : public EndBossFightTrigger
    {
    public:
        ShadeOfEranikusEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end shade of eranikus fight", "shade of eranikus", 5709) {}
    };

    class EranikusWarStompTrigger : public CloseToHostileCreatureHazardTrigger
    {
    public:
        EranikusWarStompTrigger(PlayerbotAI* ai)
            : CloseToHostileCreatureHazardTrigger(ai, "eranikus war stomp", 5709, 8.0f, 3) {}
    };

    // Avatar of Hakkar (8443) — DB verified; quest-gated
    class AvatarOfHakkarStartFightTrigger : public StartBossFightTrigger
    {
    public:
        AvatarOfHakkarStartFightTrigger(PlayerbotAI* ai)
            : StartBossFightTrigger(ai, "start avatar of hakkar fight", "avatar of hakkar", 8443) {}
    };

    class AvatarOfHakkarEndFightTrigger : public EndBossFightTrigger
    {
    public:
        AvatarOfHakkarEndFightTrigger(PlayerbotAI* ai)
            : EndBossFightTrigger(ai, "end avatar of hakkar fight", "avatar of hakkar", 8443) {}
    };
}
