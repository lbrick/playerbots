#pragma once

#include "playerbot/strategy/Action.h"

namespace ai
{
    class AcceptInvitationAction : public Action 
    {
    public:
        AcceptInvitationAction(PlayerbotAI* ai) : Action(ai, "accept invitation") {}

        virtual bool Execute(Event& event) override
        {
            Group* grp = bot->GetGroupInvite();
            if (!grp)
                return false;

            Player* inviter = sObjectMgr.GetPlayer(grp->GetLeaderGuid());
            if (!inviter)
                return false;

			if (!ai->GetSecurity()->CheckLevelFor(PlayerbotSecurityLevel::PLAYERBOT_SECURITY_INVITE, false, inviter))
            {
                WorldPacket data(SMSG_GROUP_DECLINE, 10);
                data << bot->GetName();
                sServerFacade.SendPacket(inviter, data);
                bot->UninviteFromGroup();
                return false;
            }

            // CMSG_GROUP_ACCEPT is PROCESS_THREADUNSAFE: Group::Create marks the inviter for client
            // update, and the inviter can be on another map. Accept on the world thread, through this
            // bot's own action looked up again there. Players are passed by guid, since a pointer can
            // go stale before the world thread runs (lbrick/cmangos-dev#98).
            ObjectGuid inviterGuid = inviter->GetObjectGuid();
            ObjectGuid ownerGuid = event.getOwner() ? event.getOwner()->GetObjectGuid() : ObjectGuid();
            std::string source = event.getSource();
            std::string param = event.getParam();
            PlayerbotAI::RunOnWorldThread(bot->GetObjectGuid(), [inviterGuid, ownerGuid, source, param](Player* p)
            {
                if (PlayerbotAI* botAi = p->GetPlayerbotAI())
                    if (AcceptInvitationAction* action = dynamic_cast<AcceptInvitationAction*>(botAi->GetAiObjectContext()->GetAction("accept invitation")))
                        action->Accept(inviterGuid, Event(source, param, ownerGuid ? sObjectMgr.GetPlayer(ownerGuid) : nullptr));
            });

            return true;
        }

        // Runs on the world thread, while every map updater thread is idle.
        void Accept(ObjectGuid inviterGuid, Event event)
        {
            Group* grp = bot->GetGroupInvite();
            if (!grp || grp->GetLeaderGuid() != inviterGuid)
                return;

            Player* inviter = sObjectMgr.GetPlayer(inviterGuid);
            if (!inviter)
                return;

            if (bot->isAFK())
                bot->ToggleAFK();

            ai->SavePreGroupStrategies();

            WorldPacket p;
            uint32 roles_mask = 0;
            p << roles_mask;
            bot->GetSession()->HandleGroupAcceptOpcode(p);

            // The world thread also runs this for a bot between maps: a far teleport has taken it off
            // its old map and not yet added it to the new one. The follow-up teleports and talks, which
            // need the bot's map, so it waits until the bot and the inviter are both on a map
            // (lbrick/cmangos-dev#108).
            ObjectGuid ownerGuid = event.getOwner() ? event.getOwner()->GetObjectGuid() : ObjectGuid();
            AfterAccept(inviterGuid, event.getSource(), event.getParam(), ownerGuid, time(nullptr) + followUpWaitSeconds);
        }

        // Runs on the world thread. While the bot or the inviter is between maps it is posted again,
        // to run on the next world tick, until the deadline passes.
        void AfterAccept(ObjectGuid inviterGuid, std::string source, std::string param, ObjectGuid ownerGuid, time_t deadline)
        {
            Player* inviter = sObjectMgr.GetPlayer(inviterGuid, false);
            if (!inviter)
                return;

            // A leave can run between the accept and a deferred follow-up.
            Group* grp = bot->GetGroup();
            if (!grp || !grp->IsMember(inviterGuid))
                return;

            if (!OnMap(bot) || !OnMap(inviter))
            {
                if (time(nullptr) >= deadline)
                {
                    sLog.outError("AcceptInvitationAction: %s or its inviter %s was still between maps %u s after the group accept; the follow-up is skipped",
                        bot->GetName(), inviter->GetName(), uint32(followUpWaitSeconds));
                    return;
                }

                PlayerbotAI::RunOnWorldThread(bot->GetObjectGuid(), [inviterGuid, source, param, ownerGuid, deadline](Player* p)
                {
                    if (PlayerbotAI* botAi = p->GetPlayerbotAI())
                        if (AcceptInvitationAction* action = dynamic_cast<AcceptInvitationAction*>(botAi->GetAiObjectContext()->GetAction("accept invitation")))
                            action->AfterAccept(inviterGuid, source, param, ownerGuid, deadline);
                });
                return;
            }

            Event event(source, param, ownerGuid ? sObjectMgr.GetPlayer(ownerGuid) : nullptr);

            if (sRandomPlayerbotMgr.IsFreeBot(bot))
            {
                ai->SetMaster(inviter);

                std::string defaultMovementStrategy = ai->GetDefaultMovementStrategy();
                ai->ChangeStrategy("+" + defaultMovementStrategy, BotState::BOT_STATE_NON_COMBAT);
            }

            ai->ResetStrategies();
            
            ai->ChangeStrategy("-lfg,-bg", BotState::BOT_STATE_NON_COMBAT);
            ai->Reset();

            sPlayerbotAIConfig.logEvent(ai, "AcceptInvitationAction", grp->GetLeaderName(), std::to_string(grp->GetMembersCount()));

            Player* master = inviter;

            if (master->GetPlayerbotAI()) //Copy formation from bot master.
            {
                if (sPlayerbotAIConfig.inviteChat && (sRandomPlayerbotMgr.IsFreeBot(bot) || !ai->HasActivePlayerMaster()))
                {
                    std::map<std::string, std::string> placeholders;
                    placeholders["%name"] = master->GetName();
                    std::string reply;
                    if (urand(0, 3))
                        reply = BOT_TEXT2("Send me an invite %name!", placeholders);
                    else
                        reply = BOT_TEXT2("Sure I will join you.", placeholders);

                    Guild* guild = sGuildMgr.GetGuildById(bot->GetGuildId());

                    if (guild && master->IsInGuild(bot))
                        guild->BroadcastToGuild(bot->GetSession(), reply, LANG_UNIVERSAL);
                    else if (sServerFacade.GetDistance2d(bot, master) < sPlayerbotAIConfig.spellDistance * 1.5)
                        bot->Say(reply, (bot->GetTeam() == ALLIANCE ? LANG_COMMON : LANG_ORCISH));
                }

                Formation* masterFormation = MAI_VALUE(Formation*, "formation");
                FormationValue* value = (FormationValue*)context->GetValue<Formation*>("formation");
                value->Load(masterFormation->getName());
            }

            ai->TellPlayer(inviter, BOT_TEXT("hello"), PlayerbotSecurityLevel::PLAYERBOT_SECURITY_ALLOW_ALL, false);

            ai->DoSpecificAction("reset raids", event, true);
            ai->DoSpecificAction("update gear", event, true);

            // Last: a far teleport takes the bot off its map at once, and the steps above need it.
            if (sServerFacade.GetDistance2d(bot, inviter) > 5.0f)
            {
                sLog.outDetail("Bot %s: teleporting to %s on group join", bot->GetName(), inviter->GetName());
                bot->TeleportTo(inviter->GetMapId(), inviter->GetPositionX(), inviter->GetPositionY(), inviter->GetPositionZ(), inviter->GetOrientation());
            }
        }

        // Added to a map, and not leaving it for another
        static bool OnMap(Player* player) { return player->IsInWorld() && !player->IsBeingTeleportedFar(); }

        static constexpr time_t followUpWaitSeconds = 60;

        virtual bool isUsefulWhenStunned() override { return true; }

#ifdef GenerateBotHelp
        virtual std::string GetHelpName() { return "accept invitation"; }
        virtual std::string GetHelpDescription()
        {
            return "This action makes the bot accept group invitations.\n"
                   "It will automatically handle AFK status and update strategies.\n"
                   "For free bots, the inviter becomes the bot's master.";
        }
        virtual std::vector<std::string> GetUsedActions() { return {"reset raids", "update gear"}; }
        virtual std::vector<std::string> GetUsedValues() { return {"formation"}; }
#endif 
    };

}
