/*ALARMUD* (Do not remove *ALARMUD*, used to automagically manage these lines
 *ALARMUD* AlarMUD 2.0
 *ALARMUD* See COPYING for licence information
 *ALARMUD*/
#ifndef __SPEC_PROCS2_HPP
#define __SPEC_PROCS2_HPP
/***************************  System  include ************************************/
/***************************  Local    include ************************************/
namespace Alarmud {
int AbyssGateKeeper( struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int Demon(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int DemonTeacher(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int Devil(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int DogCatcher( struct char_data* ch, int cmd, char* arg,struct char_data* mob, int type) ;
int DragonHunterLeader( struct char_data* ch, int cmd, char* arg,struct char_data* mob, int type) ;
int DruidAttackSpells(struct char_data* ch, struct char_data* vict, int level) ;
int DruidChallenger(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int DruidGuildMaster(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
void DruidHeal(struct char_data* ch, int level) ;
void DruidMob(struct char_data* ch) ;
void DruidTree(struct char_data* ch) ;
int DwarvenMiners(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int GenericCityguard(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int GenericCityguardHateUndead(struct char_data* ch, int cmd, char* arg, struct char_data* mob,int type) ;
void GreetPeople(struct char_data* ch) ;
int HuntingMercenary( struct char_data* ch, int cmd, char* arg,struct char_data* mob, int type) ;
int Magic_Fountain(struct char_data* ch, int cmd, char* arg, struct room_data* rp, int type) ;
int MakeQuest( struct char_data* ch, struct char_data* gm, int iClass,char* arg, int cmd);
int MonkChallenger(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int PaladinGuildmaster( struct char_data* ch, int cmd, char* arg,struct char_data* mob, int type) ;
int PrisonGuard( struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int PrydainGuard(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int PsiGuildmaster(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int RangerGuildmaster(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int RepairGuy( struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int Samah( struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
void SayHello(struct char_data* ch, struct char_data* t) ;
int SlotMachine( struct char_data* ch, int cmd, char* arg,struct obj_data* mob, int type) ;
int StatMaster(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
void Submit(struct char_data* ch, struct char_data* t) ;
int Summoner(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int XpMaster(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int antioch_grenade(struct char_data* ch, int cmd, char* arg, struct obj_data* obj, int type) ;
int archer_instructor( struct char_data* ch, int cmd, char* arg,struct char_data* mob, int type) ;
int astral_portal( struct char_data* ch, int cmd, char* arg,struct char_data* mob, int type) ;
int attack_rats(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int barbarian_guildmaster(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int camino( struct char_data* ch, int cmd, char* arg,struct char_data* mob, int type) ;
int cleric(struct char_data* ch, int cmd, char* arg, struct char_data* mob,int type) ;
int creeping_death( struct char_data* ch, int cmd, char* arg,struct char_data* mob, int type) ;
int determine_teacher(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int druid( struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int druid_challenge_prep_room(struct char_data* ch, int cmd, char* arg, struct room_data* rp, int type) ;
int druid_challenge_room(struct char_data* ch, int cmd, char* arg, struct room_data* rp, int type) ;
int druid_protector(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int equilibrium_teacher(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int forge_teacher(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int ghost(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int hunter(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
void invert(char* arg1, char* arg2) ;
int jive_box( struct char_data* ch, int cmd, char* arg, struct obj_data* obj, int type);
int loremaster(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int mage_specialist_guildmaster(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int magic_user(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int miner_teacher(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int monk(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int monk_challenge_prep_room(struct char_data* ch, int cmd, char* arg, struct room_data* rp, int type) ;
int monk_challenge_room(struct char_data* ch, int cmd, char* arg, struct room_data* rp, int type) ;
int monk_master(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int ninja_master(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int portal( struct char_data* ch, int cmd, char* arg, struct obj_data* obj, int type);
int real_fox(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int real_rabbit(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int sailor(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int scraps(struct char_data* ch, int cmd, char* arg, struct obj_data* obj, int type) ;
} // namespace Alarmud
#endif // __SPEC_PROCS2_HPP

