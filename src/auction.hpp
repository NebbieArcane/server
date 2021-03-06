/*ALARMUD* (Do not remove *ALARMUD*, used to automagically manage these lines
 *ALARMUD* AlarMUD 2.0
 *ALARMUD* See COPYING for licence information
 *ALARMUD*/
//  Original intial comments
/*$Id: auction.h,v 1.3 2002/03/17 16:48:47 Thunder Exp $
*/
/***************************  System  include ************************************/
/***************************  Local    include ************************************/
#ifndef H_AUCTION
#define H_AUCTION 1
namespace Alarmud {
#define PULSE_AUCTION             (6 * PULSE_PER_SEC) /* 10 seconds */ //ACIDUS 2003, ridotto tempo
#define CHAR_DATA struct char_data
#define OBJ_DATA struct obj_data
struct  auction_data {
	OBJ_DATA*   item;   /* a pointer to the item */
	CHAR_DATA* seller;  /* a pointer to the seller - which may NOT quit */
	CHAR_DATA* buyer;   /* a pointer to the buyer - which may NOT quit */
	char real_seller[20]; // SALVO metto il reale venditore
	char real_buyer[20]; // SALVO metto il reale compratore
	int         bet;    /* last bet - or 0 if noone has bet anything */
	int      going;  /* 1,2, sold */
	int      pulse;  /* how many pulses (.25 sec) until another call-out ? */
};
typedef struct  auction_data AUCTION_DATA; /* auction data */
extern  AUCTION_DATA*  auction;
void auction_update();
ACTION_FUNC(do_auction_int);
} // namespace Alarmud
#endif

