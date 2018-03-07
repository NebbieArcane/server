/*ALARMUD* (Do not remove *ALARMUD*, used to automagically manage these lines
 *ALARMUD* AlarMUD 2.0
 *ALARMUD* See COPYING for licence information
 *ALARMUD*/
#ifndef __SPECASS2__
#define __SPECASS2__
/***************************  System  include ************************************/
/***************************  Local    include ************************************/
namespace Alarmud {





int FileToArray(char* fname, char* p[]);

/****************************************************************************
*  Room Procedure
****************************************************************************/
int sBlockWay( struct char_data* pChar, int nCmd, char* szArg,
			   struct room_data* pRoom, int nType );
/* SALVO 2006 quest fisse */
int MOBKilled (struct char_data* pChar, int nCmd, char* szArg, struct room_data* pRoom, int nType);
/****************************************************************************
* Mob/Obj Procedure
****************************************************************************/
int sMobBlockWay( struct char_data* pChar, int nCmd, char* szArg,
				  struct char_data* pMob, int nType );
int StatMaster( struct char_data* pChar, int nCmd, char* szArg,
				struct char_data* pMob, int nType );
int XpMaster( struct char_data* pChar, int nCmd, char* szArg,
			  struct char_data* pMob, int nType );
int spTest( struct char_data* pChar, int nCmd, char* szArg,
			struct char_data* pMob, int nType );
int spGeneric( struct char_data* pChar, int nCmd, char* szArg,
			   struct char_data* pMob, int nType );
int ForceMobToAction( struct char_data* pChar, int nCmd, char* szArg,
					  struct char_data* pMob, int nType );
int ModHit( struct char_data* pChar, int nCmd, char* szArg,
			struct obj_data* pMob, int nType );
int TrueDam( struct char_data* pChar, int nCmd, char* szArg,
			 struct obj_data* pMob, int nType );
int trap_obj( struct char_data* pChar, int nCmd, char* szArg,
			  struct obj_data* pMob, int nType );
int Esattore( struct char_data* pChar, int nCmd, char* szArg,
			  struct char_data* pMob, int nType );
int EditMaster( struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type);
int Interact ( struct char_data* pChar, int nCmd, char* szArg, struct char_data* pMob, int nType );
int Capo_Fucina( struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type);
int msg_obj(struct char_data* ch, int cmd, char* arg, struct obj_data* tobj, int type);
int thion_loader(struct char_data* ch, int cmd, char* arg, struct obj_data* tobj, int type);
int SporeCloud( struct char_data* pChar, int nCmd, char* szArg, struct char_data* pMob, int nType );
int ChangeDam( struct char_data* pChar, int nCmd, char* szArg, struct char_data* pMob, int nType );
int LibroEroi(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type);
int MobBlockAlign( struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type );
int Vampire_Summoner( struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type );
int Nightmare( struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type );
int BlockAlign( struct char_data* ch, int cmd, char* arg, struct room_data* pRoom, int type );
int LadroOfferte( struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type );
/* SALVO 2006 quest fisse */
int ItemGiven(struct char_data* pChar, int nCmd, char* szArg, struct char_data* pMmob, int nType);
int ItemPut(struct char_data* pChar, int nCmd, char* szArg, struct obj_data* pObj, int nType);
/* Real internal function */
char* Aggiungi(char* vecchia,char* nuova) ;
int FileToArray(char* fname,char* p[]) ;
void assign_speciales() ;
int is_murdervict(struct char_data* ch) ;
int nomecompare(const void* p1, const void* p2) ;
int xcompare(const void* p1, const void* p2) ;
} // namespace Alarmud
#endif // __SPECASS2_HPP

