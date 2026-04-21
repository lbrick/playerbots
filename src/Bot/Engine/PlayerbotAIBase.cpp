
#include "src/Bot/Engine/playerbot.h"
#include "src/Bot/PlayerbotAIConfig.h"

using namespace ai;

PlayerbotAIBase::PlayerbotAIBase() : aiInternalUpdateDelay(0)
{
}

void PlayerbotAIBase::UpdateAIInternal(uint32 elapsed, bool minimal)
{
}

void PlayerbotAIBase::UpdateAI(uint32 elapsed)
{
    totalPmo.reset();
    totalPmo = sPerformanceMonitor.start(PERF_MON_TOTAL, "PlayerbotAIBase::FullTick");
    
    if (aiInternalUpdateDelay > elapsed)
        aiInternalUpdateDelay -= elapsed;
    else
        aiInternalUpdateDelay = 0;

    if (!CanUpdateAIInternal())
        return;

    UpdateAIInternal(elapsed);
    YieldAIInternalThread();
}

void PlayerbotAIBase::SetAIInternalUpdateDelay(const uint32 delay)
{
    if (aiInternalUpdateDelay < delay)
        sLog.outDebug("Setting lesser ai internal update delay %d -> %d", aiInternalUpdateDelay, delay);

    aiInternalUpdateDelay = delay;

    if (aiInternalUpdateDelay > sPlayerbotAIConfig.globalCoolDown)
        sLog.outDebug( "Set ai internal update delay: %d", aiInternalUpdateDelay);
}

void PlayerbotAIBase::IncreaseAIInternalUpdateDelay(uint32 delay)
{
    aiInternalUpdateDelay += delay;

    if (aiInternalUpdateDelay > sPlayerbotAIConfig.globalCoolDown)
        sLog.outDebug( "Increase ai internal update delay: %d", aiInternalUpdateDelay);
}

void PlayerbotAIBase::YieldAIInternalThread(bool minimal, uint32 guidLow)
{
    uint32 base = minimal ? sPlayerbotAIConfig.reactDelay * 10 : sPlayerbotAIConfig.reactDelay;
    uint32 stagger = guidLow % 200;
    if (aiInternalUpdateDelay < base + stagger)
        aiInternalUpdateDelay = base + stagger;
}

bool PlayerbotAIBase::IsActive() const
{
    return (int)aiInternalUpdateDelay < (int)sPlayerbotAIConfig.maxWaitForMove;
}
