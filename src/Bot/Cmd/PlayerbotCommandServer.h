#ifndef _PlayerbotCommandServer_H
#define _PlayerbotCommandServer_H

#include "Common.h"
#include "src/Bot/Engine/PlayerbotAIBase.h"
#include "src/Mgr/PlayerbotMgr.h"

class PlayerbotCommandServer
{
public:
    PlayerbotCommandServer() {}
    virtual ~PlayerbotCommandServer() {}
    static PlayerbotCommandServer& instance()
    {
        static PlayerbotCommandServer instance;
        return instance;
    }

    void Start();
};

#define sPlayerbotCommandServer PlayerbotCommandServer::instance()

#endif
