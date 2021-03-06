/*ALARMUD* (Do not remove *ALARMUD*, used to automagically manage these lines
 *ALARMUD* AlarMUD 2.0
 *ALARMUD* See COPYING for licence information
 *ALARMUD*/
//  Original intial comments
/* src/magic2.cpp */
#ifndef __MAGIC2_HPP
#define __MAGIC2_HPP
/***************************  System  include ************************************/
/***************************  Local    include ************************************/
namespace Alarmud {
void spell_resurrection(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_cause_light(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_cause_critical(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_cause_serious(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_cure_serious(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_mana(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_second_wind(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_flamestrike(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_dispel_good(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_turn(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_remove_paralysis(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_holy_word(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_unholy_word(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_succor(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_detect_charm(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_true_seeing(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_track(byte level, struct char_data* ch, struct char_data* targ, struct obj_data* obj);
void spell_poly_self(byte level, struct char_data* ch, struct char_data* mob, struct obj_data* obj);
void spell_minor_create(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_stone_skin(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_mirror_images(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_infravision(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_shield(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_weakness(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_invis_group(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_acid_blast(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_cone_of_cold(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_ice_storm(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_poison_cloud(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_major_create(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_sending(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_meteor_swarm(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_Create_Monster(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_light(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_fly(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_fly_group(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_refresh(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_water_breath(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_cont_light(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_animate_dead(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* corpse);
void spell_know_alignment(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_dispel_magic(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_paralyze(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_fear(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_calm(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_web(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_heroes_feast(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_conjure_elemental(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_faerie_fire(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_faerie_fog(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_cacaodemon(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_improved_identify(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_geyser(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_green_slime(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_prot_dragon_breath(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_prot_energy_drain(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_globe_darkness(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_prot_fire(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_prot_cold(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_prot_energy(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_prot_elec(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_prot_dragon_breath_fire(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_prot_dragon_breath_frost(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_prot_dragon_breath_elec(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_prot_dragon_breath_acid(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_prot_dragon_breath_gas(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
} // namespace Alarmud
#endif

