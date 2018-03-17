/*ALARMUD* (Do not remove *ALARMUD*, used to automagically manage these lines
 *ALARMUD* AlarMUD 2.0
 *ALARMUD* See COPYING for licence information
 *ALARMUD*/
#ifndef __SPEC_PROCS_HPP
#define __SPEC_PROCS_HPP
/***************************  System  include ************************************/
/***************************  Local    include ************************************/
#include "specass2.hpp"
#include "specialproc_other.hpp"
namespace Alarmud {
int AGGRESSIVE(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int AbbarachDragon(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int BiosKaiThanatos( struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int CaravanGuildGuard(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int CarrionCrawler(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int ClericGuildMaster(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int Donation(struct char_data* ch, int cmd, char* arg, struct room_data* rp,int type);
int DracoLich( struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int Drow(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
struct char_data* FindMobInRoomWithFunction( int room,special_proc);
struct char_data* FindMobInRoomWithVNum( int room, int VNum) ;
int Fountain(struct char_data* ch, int cmd, char* arg, struct room_data* rp, int type) ;
int GainLevel(struct char_data* ch, int iClass) ;
int House(struct char_data* ch, int cmd, char* arg, struct room_data* rp, int type);
int Inquisitor(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int Keftab(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int Kraken(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int Leader(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int MageGuildMaster( struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int Manticore(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int MidgaardCitizen(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int MidgaardCityguard(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int MordGuard(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int MordGuildGuard(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int NewThalosCitizen(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int NewThalosGuildGuard(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int NewThalosMayor(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int NudgeNudge(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int PaladinGuildGuard( struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int Pungiglione( struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int Pungiglione_maggiore( struct char_data* ch, int cmd, char* arg,  struct char_data* mob, int type) ;
int Rakda(struct char_data* ch, int cmd, char* arg, struct obj_data* rakda, int type);
void RakdaCast(struct char_data* ch, struct char_data* vict) ;
void RakdaGraphic(struct char_data* ch, struct char_data* vict1) ;
void RakdaMajor(struct char_data* ch, struct char_data* vict) ;
void RakdaMinor(struct char_data* ch, struct char_data* vict) ;
int Ringwraith( struct char_data* ch, int cmd, char* arg,struct char_data* mob, int type );
int RustMonster(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int SaveRoomContens( struct char_data* pChar, int nCmd, char* pchArg,struct room_data* pRoom, int nEvent ) ;
int SporeCloud( struct char_data* pChar, int nCmd, char* szArg, struct char_data* pMob, int nType );
int SputoVelenoso( struct char_data* ch, int cmd, char* arg,struct char_data* mob, int type );
int StatTeller(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int StormGiant(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
void String_mob(struct char_data* ch, struct char_data* vict, char* stringa, int campo) ;
int SultanGuard(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int ThiefGuildMaster( struct char_data* ch, int cmd, char* arg,  struct char_data* mob, int type) ;
void ThrowChar(struct char_data* ch, struct char_data* v, int dir) ;
int ThrowerMob(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int Tsuchigumo( struct char_data* ch, int cmd, char* arg,  struct char_data* mob, int type) ;
int Tyrannosaurus_swallower(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int Tytan( struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int WarrenGuard(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int WarriorGuildMaster(struct char_data* ch, int cmd, char* arg,struct char_data* mob, int type) ;
int WizardGuard(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int andy_wilcox(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type);
int banana(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int bank (struct char_data* ch, int cmd, char* arg, struct room_data* rp, int type) ;
int blink( struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int chalice(struct char_data* ch, int cmd, char* arg) ;
int citizen(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int delivery_beast(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int delivery_elf(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int dump( struct char_data* ch, int cmd, char* arg, struct room_data* rp,int type);
int enter_obj( struct char_data* ch, int cmd, char* arg, struct obj_data* tobj, int type);
int eric_johnson(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type);
void exec_social(struct char_data* npc, char* cmd, int next_line,int* cur_line, void** thing);
int fido(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int fighter(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
struct char_data* find_mobile_here_with_spec_proc(special_proc fcn, int rnumber);
int flame(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int geyser(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int ghoul(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int green_slime( struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type);
int guild_guard(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
char* how_good(int percent) ;
int is_target_room_p(int room, void* tgt_room) ;
int jabberwocky(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int janitor(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int jugglernaut(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int kings_hall(struct char_data* ch, int cmd, char* arg) ;
int magic_user2(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int mayor(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int named_object_on_ground(int room, void* c_data) ;
int nodrop(struct char_data* ch, int cmd, char* arg, struct obj_data* tobj,int type);
void npc_steal(struct char_data* ch,struct char_data* victim) ;
int paramedics(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int pet_shops(struct char_data* ch, int cmd, char* arg, struct room_data* rp, int type) ;
int pray_for_items(struct char_data* ch, int cmd, char* arg, struct room_data* rp, int type) ;
int puff(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int regenerator( struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int replicant( struct char_data* ch, int cmd, char* arg,struct char_data* mob1, int type ) ;
int shadow(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int sisyphus( struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int snake( struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int snake_plus( struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int soap( struct char_data* ch, int cmd, char* arg, struct obj_data* tobj,  int type);
int temple_labrynth_liar(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int temple_labrynth_sentry(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int thief(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int tormentor(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int vampire(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
int wraith(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type) ;
void zm_init_combat(struct char_data* zmaster, struct char_data* target) ;
int zm_kill_aggressor(struct char_data* zmaster) ;
int zm_kill_fidos(struct char_data* zmaster) ;
int zm_stunned_followers(struct char_data* zmaster) ;
int zm_tired(struct char_data* zmaster) ;
int zombie_master(struct char_data* ch, int cmd, char* arg, struct char_data* mob, int type);
int zone_obj( struct char_data* ch, int cmd, char* arg, struct obj_data* tobj,int type);
} // namespace Alarmud
#endif // __SPEC_PROCS_HPP
