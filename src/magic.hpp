/*ALARMUD* (Do not remove *ALARMUD*, used to automagically manage these lines
 *ALARMUD* AlarMUD 2.0
 *ALARMUD* See COPYING for licence information
 *ALARMUD*/
//  Original intial comments
/* src/magic.cpp */
#ifndef __MAGIC_HPP
#define __MAGIC_HPP
/***************************  System  include ************************************/
/***************************  Local    include ************************************/
namespace Alarmud {
void heat_blind(struct char_data* ch);
void spell_magic_missile(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_chill_touch(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_burning_hands(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_shocking_grasp(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_lightning_bolt(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_colour_spray(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_energy_drain(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_fireball(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_earthquake(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_dispel_evil(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_call_lightning(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_harm(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_armor(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_astral_walk(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_teleport(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_bless(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_blindness(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_clone(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_control_weather(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_create_food(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_create_water(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_cure_blind(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_cure_critic(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_cure_light(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_curse(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_detect_evil(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_detect_invisibility(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_detect_magic(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_detect_poison(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_enchant_weapon(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_heal(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_invisibility(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_locate_object(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_poison(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_protection_from_evil(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_protection_from_evil_group(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_remove_curse(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_remove_poison(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_fireshield(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_sanctuary(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_sleep(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_strength(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_ventriloquate(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_word_of_recall(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_summon(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void RawSummon(struct char_data* v, struct char_data* c);
void spell_charm_person(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_charm_monster(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_sense_life(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_globe_minor_inv(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_globe_major_inv(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_anti_magic_shell(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_prismatic_spray(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_incendiary_cloud(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_comp_languages(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_identify(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_enchant_armor(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_quest(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_fire_breath(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_frost_breath(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_acid_breath(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_gas_breath(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_lightning_breath(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_wizard_eye(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
void spell_disintegrate(byte level, struct char_data* ch, struct char_data* victim, struct obj_data* obj);
#endif
} // namespace Alarmud

