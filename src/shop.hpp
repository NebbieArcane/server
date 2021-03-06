/*ALARMUD* (Do not remove *ALARMUD*, used to automagically manage these lines
 *ALARMUD* AlarMUD 2.0
 *ALARMUD* See COPYING for licence information
 *ALARMUD*/
//  Original intial comments
#ifndef __SHOP_HPP
#define __SHOP_HPP
/***************************  System  include ************************************/
/***************************  Local    include ************************************/
namespace Alarmud {
extern int gevent;
extern struct shop_data* shop_index;
extern int number_of_shops;
extern float  shop_multiplier;
void assign_the_shopkeepers() ;
void boot_the_shops() ;
int is_ok(struct char_data* keeper, struct char_data* ch, int shop_nr) ;
long object_cost(struct obj_data* temp1,struct char_data* ch,int shop_nr,int vende) ;
int shop_keeper(struct char_data* ch, int cmd, char* arg, char* mob, int type) ;
int shop_producing(struct obj_data* item, int shop_nr) ;
void shopping_buy(char* arg, struct char_data* ch,struct char_data* keeper, int shop_nr);
int shopping_kill(char* arg, struct char_data* ch,struct char_data* keeper, int shop_nr);
void shopping_list(char* arg, struct char_data* ch,struct char_data* keeper, int shop_nr);
void shopping_sell(char* arg, struct char_data* ch,struct char_data* keeper,int shop_nr);
void shopping_value(char* arg, struct char_data* ch,struct char_data* keeper, int shop_nr);
int trade_with(struct obj_data* item, int shop_nr) ;
} // namespace Alarmud
#endif // __SHOP_HPP

