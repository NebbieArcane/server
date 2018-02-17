/*
 * act.info.hpp
 *
 *  Created on: 06 feb 2018
 *      Author: giovanni
 *
 * Licensed Material - Property of Hex Keep s.r.l.
 * (c) Copyright Hex Keep s.r.l. 2012-2014
 */

#ifndef SRC_ACT_INFO_HPP_
#define SRC_ACT_INFO_HPP_

void argument_split_2(char* argument, char* first_arg, char* second_arg);
int can_see_linear(struct char_data* ch, struct char_data* targ, int* rng, int* dr);
void do_attribute(struct char_data* ch, char* argument, int cmd);
void do_command_list(struct char_data* ch, char* arg, int cmd);
void do_consider(struct char_data* ch, char* argument, int cmd);
void do_credits(struct char_data* ch, char* argument, int cmd);
void do_display(struct char_data* ch, char* arg, int cmd);
void do_equipment(struct char_data* ch, char* argument, int cmd);
void do_examine(struct char_data* ch, char* argument, int cmd);
void do_exits(struct char_data* ch, char* argument, int cmd);
void do_help(struct char_data* ch, char* argument, int cmd);
void do_immortal(struct char_data* ch, char* argument, int cmd);
void do_info(struct char_data* ch, char* argument, int cmd);
void do_inventory(struct char_data* ch, char* argument, int cmd);
void do_levels(struct char_data* ch, char* argument, int cmd);
void do_look(struct char_data* ch, char* argument, int cmd);
void do_news(struct char_data* ch, char* argument, int cmd);
void do_prince(struct char_data* ch, char* argument, int cmd);
void do_read(struct char_data* ch, char* argument, int cmd);
void do_resize(struct char_data* ch, char* arg, int cmd);
void do_scan(struct char_data* ch, char* argument, int cmd);
void do_score(struct char_data* ch, char* argument, int cmd);
void do_show_skill(struct char_data* ch, char* arg, int cmd);
void do_spells(struct char_data* ch, char* argument, int cmd);
void do_status(struct char_data* ch, char* argument, int cmd );
void do_time(struct char_data* ch, char* argument, int cmd);
void do_users(struct char_data* ch, char* argument, int cmd );
void do_value(struct char_data* ch, char* argument, int cmd);
void do_weather(struct char_data* ch, char* argument, int cmd);
void do_where_object(struct char_data* ch, struct obj_data* obj, int recurse, struct string_block* sb );
void do_where_person(struct char_data* ch, struct char_data* person, struct string_block* sb );
void do_where(struct char_data* ch, char* argument, int cmd);
void do_who(struct char_data* ch, char* argument, int cmd);
void do_wizhelp(struct char_data* ch, char* arg, int cmd);
void do_wizlist(struct char_data* ch, char* argument, int cmd);
void do_wiznews(struct char_data* ch, char* argument, int cmd);
void do_world(struct char_data* ch, char* argument, int cmd);
char* find_ex_description(char* word, struct extra_descr_data* list);
struct char_data* get_char_linear(struct char_data* ch, char* arg, int* rf, int* df );
struct obj_data* get_object_in_equip_vis(struct char_data* ch, char* arg, struct obj_data* equipment[], int* j);
long GetLagIndex();
long GetMediumLag(long lastlag);
int HowManyConnection(int ToAdd);
void list_char_in_room(struct char_data* list, struct char_data* ch);
void list_char_to_char(struct char_data* list, struct char_data* ch, int mode);
void list_exits_in_room(struct char_data* ch);
void list_groups(struct char_data* ch, char* szArg, int iCmd );
void list_obj_in_heap(struct obj_data* list, struct char_data* ch );
void list_obj_in_room(struct obj_data* list, struct char_data* ch );
char* numbered_object(struct char_data* ch, struct obj_data* obj);
char* numbered_person(struct char_data* ch, struct char_data* person);
void ScreenOff(struct char_data* ch);
void show_char_to_char(struct char_data* i, struct char_data* ch, int mode );
void show_mult_char_to_char(struct char_data* i, struct char_data* ch, int mode, int num);
void show_mult_obj_to_char(struct obj_data* object, struct char_data* ch, int mode, int num);
void show_obj_to_char(struct obj_data* object, struct char_data* ch, int mode);
void ShowAltezzaCostituzione(struct char_data* pChar, struct char_data* pTo );
int singular(struct obj_data* o);
int which_number_mobile(struct char_data* ch, struct char_data* mob);
int which_number_object(struct obj_data* obj );
void do_actual_wiz_help(struct char_data* ch, char* argument, int cmd);
void list_obj_to_char(struct obj_data* list,struct char_data* ch, int mode,
					  bool show);
char* DescDamage(float dam);
char* DescRatio(float f);  /* theirs / yours */
char* DescRatioF(float f);  /* theirs / yours */
char* DescArmorf(float f); //GGPATCH
char* SpellfailDesc(int a); //GGPATCH
char* DamRollDesc(int a);
char* HitRollDesc(int a);
char* ArmorDesc(int a);
char* AlignDesc(int a);
char* DescAttacks(float a);
char* EqDesc(float a) ;
int MobLevBonus( struct char_data* ch );


#endif /* SRC_ACT_INFO_HPP_ */