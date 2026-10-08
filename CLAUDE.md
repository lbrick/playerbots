# playerbots module

Workflow, build, gate and issue rules live in the workspace
[`lbrick/cmangos-dev` `CLAUDE.md`](https://github.com/lbrick/cmangos-dev/blob/main/CLAUDE.md)
(`../CLAUDE.md` when this repo is checked out as `cmangos-dev/cmangos-playerbots/`). This file
adds only module-specific facts.

## Layout

Source sits under `playerbot/` (bot engine, managers, strategies) and `ahbot/` (auction house
bot). Includes carry the directory prefix, double-quoted: `#include "playerbot/WorldPosition.h"`.

## Include Restrictions

- `playerbot/PlayerbotAIConfig.h` must not include any header that reaches `PathFinder.h`.
  That chain ends in `Detour/Include/DetourNavMesh.h`, which the `mangosd` translation units
  cannot resolve. Forward-declare instead, as the file does for
  `namespace ai { enum NewRpgStatus : int; }`.
- Do not include `Server/WorldTimer.h`; the path does not exist. `WorldTimer` is declared in
  the core's `Util/Timer.h` and reaches the module through `World/World.h`.

## Porting From AzerothCore

Code taken from `azerothcore-playerbots` needs these substitutions. Each cMaNGOS form is used
in this module or declared in both cores' headers.

| AzerothCore | cMaNGOS |
|---|---|
| `botAI->` | `ai->` (bulk replace with care: `PlayerbotAI` must not become `Playerai`) |
| `bot->IsInFlight()` | `bot->IsTaxiFlying()` |
| `bot->Dismount()` | `bot->Unmount()` |
| `getMSTime()` | `WorldTimer::getMSTime()` |
| `GetMSTimeDiffToNow(t)` | `WorldTimer::getMSTimeDiff(t, WorldTimer::getMSTime())` |
| `sObjectMgr->` | `sObjectMgr.` |
| `ObjectAccessor::GetCreature` / `GetGameObject` / `GetWorldObject` | `bot->GetMap()->GetCreature(guid)` / `GetGameObject(guid)` / `GetWorldObject(guid)` |
| `q_status.CreatureOrGOCount[i]`, `q_status.ItemCount[i]` | `q_status.m_creatureOrGOcount[i]`, `q_status.m_itemcount[i]` |
| `quest->RequiredNpcOrGoCount[i]`, `quest->RequiredItemCount[i]` | `quest->ReqCreatureOrGOCount[i]`, `quest->ReqItemCount[i]` |
| `LOG_DEBUG("playerbots", ...)` (fmtlib) | `sLog.outDebug(...)` (printf format) |

`ObjectAccessor::FindPlayer` and `ObjectAccessor::FindPlayerByName` exist in cMaNGOS and are
used for player lookups.
