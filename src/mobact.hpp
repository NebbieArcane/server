/*ALARMUD* (Do not remove *ALARMUD*, used to automagically manage these lines
 *ALARMUD* AlarMUD 2.0
 *ALARMUD* See COPYING for licence information
 *ALARMUD*/
#ifndef __MOBACT_HPP
#define __MOBACT_HPP
//  Original intial comments
/***************************  System  include ************************************/
/***************************  Local    include ************************************/
namespace Alarmud {
int AssistFriend(struct char_data* ch) ;
void CommandAssign(const char* arg, void (*p)(char*, struct char_data*)) ;
int CommandSearch(const char* arg) ;
void CommandSetup() ;
void DoScript(struct char_data* ch) ;
void FindABetterWeapon(struct char_data* mob) ;
int GetDamBonus(struct obj_data* w) ;
int GetDamage(struct obj_data* w, struct char_data* ch) ;
int GetHandDamage(struct char_data* ch) ;
int IsMobStartRoom(int room, struct char_data* pMob) ;
int MobFriend(struct char_data* ch, struct char_data* f) ;
void MobHit(struct char_data* ch, struct char_data* v, int type) ;
void MobHunt(struct char_data* ch) ;
void MobScavenge(struct char_data* ch) ;
void PulseMobiles(int type) ;
int SameRace(struct char_data* ch1, struct char_data* ch2) ;
int SentinelBackHome(struct char_data* pMob) ;
int UseViolentHeldItem(struct char_data* ch) ;
void check_mobile_activity(unsigned long pulse) ;
void mobile_activity(struct char_data* ch);
void mobile_guardian(struct char_data* ch);
void mobile_wander(struct char_data* ch);
SCRIPT_FUNC(do_act);
SCRIPT_FUNC(do_jmp);
SCRIPT_FUNC(do_jsr);
SCRIPT_FUNC(do_rts);
SCRIPT_FUNC(end2);
SCRIPT_FUNC(noop);
SCRIPT_FUNC(sgoto);
} // namespace Alarmud
#endif // __MOBACT_HPP

