#pragma once
#include "GenericActions.h"

namespace ai
{
    class PassLeadershipToMasterAction : public ChatCommandAction
    {
    public:
        PassLeadershipToMasterAction(PlayerbotAI* ai, std::string name = "leader", std::string message = "Passing leader to you!") : ChatCommandAction(ai, name), message(message) {}

        virtual Player* PassLeaderTo(Event& event) { return GetMaster(); };

        virtual bool Execute(Event& event) override
        {
            Player* passLeaderTo = PassLeaderTo(event);
            if (passLeaderTo && passLeaderTo != bot && bot->GetGroup() && bot->GetGroup()->IsMember(passLeaderTo->GetObjectGuid()))
            {
                // CMSG_GROUP_SET_LEADER is PROCESS_THREADUNSAFE: the leader flag moves to a member who
                // can be on another map, so it runs on the world thread (lbrick/cmangos-dev#98).
                // Strategy setup reads whether the bot leads, so a random bot resets after the change.
                ObjectGuid leaderGuid = passLeaderTo->GetObjectGuid();
                bool reset = sRandomPlayerbotMgr.IsRandomBot(bot);
                PlayerbotAI::RunOnWorldThread(bot->GetObjectGuid(), [leaderGuid, reset](Player* p)
                {
                    WorldPacket packet(SMSG_GROUP_SET_LEADER, 8);
                    packet << leaderGuid;
                    p->GetSession()->HandleGroupSetLeaderOpcode(packet);

                    if (reset)
                    {
                        if (PlayerbotAI* botAi = p->GetPlayerbotAI())
                        {
                            botAi->ResetStrategies();
                            botAi->Reset();
                        }
                    }
                });
                
                if (!message.empty())
                    ai->TellPlayerNoFacing(passLeaderTo, message);
                
                return true;
            }

            return false;
        }

        virtual bool isUseful() override
        {
            return ai->IsAlt() && bot->GetGroup() && bot->GetGroup()->IsLeader(bot->GetObjectGuid());
        }

        virtual bool isUsefulWhenStunned() override { return true; }

    protected:
        std::string message;
    };

    class GiveLeaderAction : public PassLeadershipToMasterAction 
    {
    public:
        GiveLeaderAction(PlayerbotAI* ai, std::string message = "Lead the way!") : PassLeadershipToMasterAction(ai, "give leader", message) {}

        virtual Player* PassLeaderTo(Event& event) { return event.getOwner(); };

        virtual bool isUseful() override
        {
            return bot->GetGroup() && bot->GetGroup()->IsLeader(bot->GetObjectGuid());
        }        
    };    
}
