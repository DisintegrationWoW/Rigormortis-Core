/*
<--------------------------------------------------------------------------->
 - Developer(s): Ghostcrawler336
 - Complete: %100
 - ScriptName: 'Buff Master / Remover'
 - Comment: untested.
<--------------------------------------------------------------------------->
*/
 
#include "ScriptPCH.h"
     
enum spells
{
        KINGS_BUFF = 43223,
        MARK_OF_THE_WILD = 48469,
        Resurrection_Sickness = 15007,
        Deserter = 26013
};
     
class buff_npc : public CreatureScript
{
        public:
                buff_npc() : CreatureScript("buff_npc"){}
     
                bool OnGossipHello(Player * pPlayer, Creature * pCreature)
                {
                        pPlayer->ADD_GOSSIP_ITEM(4, "Buff Me!", GOSSIP_SENDER_MAIN, 1);
                                                pPlayer->ADD_GOSSIP_ITEM(4, "Remove Sickness", GOSSIP_SENDER_MAIN, 2);
                                                pPlayer->ADD_GOSSIP_ITEM(4, "Remove Deserter", GOSSIP_SENDER_MAIN, 3);
                                                pPlayer->ADD_GOSSIP_ITEM(4, "Never Mind", GOSSIP_SENDER_MAIN, 100);
                        pPlayer->PlayerTalkClass->SendGossipMenu(9425, pCreature->GetGUID());
                                                                       
                        return true;
                }
     
                bool OnGossipSelect(Player * pPlayer, Creature * pCreature, uint32 /*uiSender*/, uint32 uiAction)
                {
                                        pPlayer->PlayerTalkClass->ClearMenus();
                                       
                                            switch(uiAction)
                        {
                                                case 1:
                                                        {
                                                        pPlayer->CastSpell(pPlayer, KINGS_BUFF, true);
                                                        pPlayer->CastSpell(pPlayer, MARK_OF_THE_WILD, true);
                                                        }break;
 
                                                case 2:
                                                        {
                                                                pPlayer->RemoveAura(Resurrection_Sickness);
                                                        }break;
 
                                                case 3:
                                                        {
                                                                pPlayer->RemoveAura(Deserter);
                                                        }break;
 
                                                                case 100:
                                                                {
                                                                                pPlayer->CLOSE_GOSSIP_MENU();
                                                                }break;
                                     
                                                }
                        return true;
                }
};
     
void AddSC_buff_npc()
{
        new buff_npc();
}