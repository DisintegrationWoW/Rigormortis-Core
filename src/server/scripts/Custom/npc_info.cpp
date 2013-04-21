/*
Disintegration WoW
Information NPC Script!
Progress 50% - Is not Tested!
*/
#include "ScriptPCH.h"

class npc_info : public CreatureScript
{
	public:
		npc_info() : CreatureScript("npc_info")
		{
		}

		bool OnGossipHello(Player * pPlayer, Creature * pCreature)
		{
			pPlayer->ADD_GOSSIP_ITEM(4, "|cffDA70D6|TInterface\\icons\\Temp:30|t|r What Are the Server Rates?", GOSSIP_SENDER_MAIN, 0);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cffDA70D6|TInterface\\icons\\Temp:30|t|r What are Event Tokens?", GOSSIP_SENDER_MAIN, 1);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cffDA70D6|TInterface\\icons\\Temp:30|t|r What do I do if I find a bug?", GOSSIP_SENDER_MAIN, 2);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cffDA70D6|TInterface\\icons\\Temp:30|t|r Do you have gear vendors?", GOSSIP_SENDER_MAIN, 3);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cffDA70D6|TInterface\\icons\\Temp:30|t|r Do you have Any Promotions at the moment?", GOSSIP_SENDER_MAIN, 4);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cffDA70D6|TInterface\\icons\\Temp:30|t|r Are you Recruiting Staff Members?", GOSSIP_SENDER_MAIN, 5);
			pPlayer->ADD_GOSSIP_ITEM(0, "Nevermind...", GOSSIP_SENDER_MAIN, 6);
			pPlayer->PlayerTalkClass->SendGossipMenu(9425, pCreature->GetGUID());
			return true;
		}

		bool OnGossipSelect(Player * Player, Creature * Creature, uint32 /*uiSender*/, uint32 uiAction)
		{
			if(!Player)
				return true;
			
			switch(uiAction)
			{
				case 0:
					{
						ChatHandler(Player->GetSession()).PSendSysMessage("|cff008000The Rates are x40 Quest XP, x30 Kill XP Drops are all x5!|r", Player->GetName());
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 1:
					{

						ChatHandler(Player->GetSession()).PSendSysMessage("|cff008000Event Tokens are used to complete Quest which can award you some nice Items!|r", Player->GetName());
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 2:
					{
						ChatHandler(Player->GetSession()).PSendSysMessage("|cff008000Please report any and all bugs to the bugs section on our forums!|r", Player->GetName());
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 3:
					{
						ChatHandler(Player->GetSession()).PSendSysMessage("|cff008000We have an Heirloom Vendor Located Beside you, and Vendors for levels 60, 70 and 80 in Disintegration Town!|r", Player->GetName());
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 4:
					{
						ChatHandler(Player->GetSession()).PSendSysMessage("|cff008000At the moment we have one Promotion, if you have not yet obtained a level 80 Character on our server you can make a ticket saying PROMO and you will be giving instant 80 and gear to start!|r", Player->GetName());
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 5:
					{
						ChatHandler(Player->GetSession()).PSendSysMessage("|cff008000Yes we are currently looking for Staff, Feel free to Apply on our forums!|r", Player->GetName());
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 6:
					{
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
			}
			return true;
		}

};

void AddSC_npc_info()
{
	new npc_info();
}