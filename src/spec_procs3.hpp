/*ALARMUD* (Do not remove *ALARMUD*, used to automagically manage these lines
 *ALARMUD* AlarMUD 2.0
 *ALARMUD* See COPYING for licence information
 *ALARMUD*/
#ifndef __SPEC_PROCS3_HPP
#define __SPEC_PROCS3_HPP
/***************************  System  include ************************************/
/***************************  Local    include ************************************/
namespace Alarmud {
int AcidBlob		(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int AcidBreather	(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int AntiSunItem		(struct char_data* ch, int cmd, char* arg, struct obj_data* obj, int type) ;
int Barbarian		(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int Beholder		(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int BerserkerItem	(struct char_data* ch, int cmd, char* arg, struct obj_data* obj, int type) ;
int BlockWay		(struct char_data* ch, int cmd, char* arg, struct room_data* rp, int type) ;
int Capo_Fucina 	(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int ChurchBell		(struct char_data* ch, int cmd, char* arg, struct room_data* rp, int type) ;
int Cockatrice		(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int Esattore		(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int EvilBlade		(struct char_data* ch, int cmd, char* arg, struct obj_data* tobj, int type) ;
int FireBreather	(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int ForceMobToAction(struct char_data* cy, int cmd, char* arg, struct char_data* mob, int type) ;
int FrostBreather	(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int GasBreather		(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int GoodBlade		(struct char_data* ch, int cmd, char* arg,struct obj_data* tobj, int type) ;
int Interact 		(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int ItemGiven		(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int ItemPut			(struct char_data* ch, int cmd, char* arg, struct obj_data* pObj, int nType);
int LegionariV		(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int LightningBreather(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int MOBKilled 		(struct char_data* pChar, int nCmd, char* szArg, struct room_data* pRoom, int nType) ;
int MobBlockWay		(struct char_data* pChar, int nCmd, char* szArg, struct char_data* mob, int type) ;
int ModHit			(struct char_data* ch,int i,char* arg,struct obj_data* obj,int ev) ;
int NeutralBlade	(struct char_data* ch, int cmd, char* arg,struct obj_data* tobj, int type) ;
int ObjIsOnGround	(struct char_data* ch, char* argument ) ;
int Paladin			(struct char_data* ch, int cmd, char* arg, struct char_data* mob,int type) ;
int PostMaster		(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int PrimoAlbero		(struct char_data* ch, int cmd, char* arg,struct char_data* mob, int type) ;
int Psionist		(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int Ranger			(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int Slavalis		(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int TreeThrowerMob	(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int TrueDam			(struct char_data* ch,int i,char* arg,struct obj_data* obj,int ev) ;
int acid_monster	(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int archer			(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int archer_hth		(struct char_data* ch) ;
int archer_sub		(struct char_data* ch) ;
int avatar_celestian(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int baby_bear		(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
struct room_data* back_left_square(struct room_data* room) ;
struct room_data* back_right_square(struct room_data* room) ;
struct room_data* back_square(struct room_data* room) ;
int banshee			(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int banshee_lorelai	(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int chess_game		(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int cleric_imp		(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int cleric_mage		(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int death_knight	(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int fighter_cleric	(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int fighter_mage	(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
struct room_data* forward_left_square(struct room_data* room) ;
struct room_data* forward_right_square(struct room_data* room) ;
struct room_data* forward_square(struct room_data* room) ;
int goblin_sentry	(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
struct room_data* left_square(struct room_data* room) ;
int lich_church		(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int mad_cyrus		(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int mad_gertruda	(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int magic_user_imp	(struct char_data* ch, int cmd, char* arg,struct char_data* mob, int type) ;
int medusa			(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int msg_obj			(struct char_data* ch, int cmd, char* arg, struct obj_data* tobj,int type) ;
int pick_archer_target( struct char_data* ch, int maxr,struct char_data** targ, int* rn, int* dr );
int range_estimate	(struct char_data* ch, struct obj_data* o, int type) ;
int raven_iron_golem(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
struct room_data* right_square(struct room_data* room) ;
int sTeleport		(struct char_data* pChar, int nCmd, char* szArg, struct room_data* pRoom, int nType );
int spGeneric		(struct char_data* pChar, int nCmd, char* szArg, struct char_data* pMob, int nType );
int spTest			(struct char_data* pChar, int nCmd, char* szArg,struct char_data* pMob, int nType );
struct char_data* square_contains_enemy(struct room_data* square) ;
int square_contains_friend(struct room_data* square) ;
int square_empty	(struct room_data* square) ;
int strahd_vampire	(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int strahd_zombie	(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int thion_loader	(struct char_data* ch, int cmd, char* arg, struct obj_data* tobj,int type);
int timnus			(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int trap_obj		(struct char_data* ch,int i,char* arg,struct obj_data* obj,int ev) ;
void trap_obj_damage(struct char_data* v, int damtype, int amnt, struct obj_data* t) ;
int winger			(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
} // namespace Alarmud
#endif // __SPEC_PROCS3_HPP
