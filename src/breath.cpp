/****************************************************************************
 * AlarMUD. Server per MUD.
 *
 * Files: breath.c breath.h
 * Contengono le funzioni per la gestione dei soffi dei draghi.
 *
 * $Id: breath.c,v 1.1.1.1 2002/02/13 11:14:53 root Exp $
 * */
#include "breath.hpp"
#include <stdlib.h>
#include <stdio.h>

#include "protos.hpp"
#include "breath.hpp"
#include "fight.hpp"
#include "snew.hpp"
#include "spells1.hpp"


struct breath_victim* choose_victims(struct char_data* ch,struct char_data* first_victim) {
	/* this is goofy, dopey extraordinaire */
	struct char_data* cons;
	struct breath_victim* head = NULL, *temp=NULL;

	for( cons = real_roomp(ch->in_room)->people; cons;
			cons = cons->next_in_room ) {
		temp = (struct breath_victim*)malloc(sizeof(*temp));
		temp->ch = cons;
		temp->next = head;
		head = temp;
		if (first_victim == cons) {
			temp->yesno = 1;
		}
		else if (ch == cons) {
			temp->yesno = 0;
		}
		else if( ( in_group(first_victim, cons) ||
				   cons == first_victim->master ||
				   cons->master == first_victim) &&
				 (temp->yesno = (3 != dice(1,5))) ) {
			/* group members will get hit 4/5 times */
		}
		else if (cons->specials.fighting == ch) {
			/* people fighting the dragon get hit 4/5 times */
			temp->yesno = (3 != dice(1,5));
		}
		else /* bystanders get his 2/5 times */
		{ temp->yesno = (dice(1,5)<3); }
	}
	return head;
}

void free_victims(struct breath_victim* head) {
	struct  breath_victim* temp;

	while (head) {
		temp = head->next;
		free(head);
		head = temp;
	}
}

void breath_weapon( struct char_data* ch, struct char_data* target,int mana_cost, bfuncp func) {
	struct breath_victim* hitlist, *scan;
	struct char_data* tmp;
	int        victim;

	act("$n rears back and inhales",1,ch,0,ch->specials.fighting,TO_ROOM);
	victim=0;

	for (tmp = real_roomp(ch->in_room)->people; tmp; tmp = tmp->next_in_room) {
		if (tmp == ch || IS_IMMORTAL(tmp)) {
			continue;
		}
		else {
			victim=1;
			cast_fear( GetMaxLevel(ch), ch, "", SPELL_TYPE_SPELL, tmp, 0);
		}
	}

	hitlist = choose_victims(ch, target);

	if (func!=NULL && victim && hitlist) {
		act("$n Breathes...", 1, ch, 0, ch->specials.fighting, TO_ROOM);

		for (scan = hitlist; scan; scan = scan->next) {
			if (!scan->yesno ||
					IS_IMMORTAL(scan->ch) ||
					scan->ch->in_room != ch->in_room /* this could happen if
                                              someone fled, I guess */
			   )
			{ continue; }
			func( GetMaxLevel(ch), ch, "", SPELL_TYPE_SPELL, scan->ch, 0);
		}
		GET_MANA(ch) -=mana_cost;
		alter_mana(ch,0);
	}
	else {
		act( "$n Breathes...coughs and sputters...",
			 1, ch, 0, ch->specials.fighting, TO_ROOM);
		do_flee(ch, "", 0);
	}

	free_victims(hitlist);
}

void use_breath_weapon( struct char_data* ch, struct char_data* target,int cost, bfuncp func) {
	if (GET_MANA(ch)>=0) {
		breath_weapon(ch, target, cost, func);
	}
	else if ((GET_HIT(ch) < GET_MAX_HIT(ch)/2) && (GET_MANA(ch) >= -cost)) {
		breath_weapon(ch, target, cost, func);
	}
	else if ((GET_HIT(ch) < GET_MAX_HIT(ch)/4) && (GET_MANA(ch) >= -2*cost)) {
		breath_weapon(ch, target, cost, func);
	}
	else if (GET_MANA(ch)<=-3*cost) {
		breath_weapon(ch, target, 0, NULL); /* sputter */
	}
}


static bfuncp breaths[] = {
	cast_acid_breath,
	0,
	cast_frost_breath,
	0,
	cast_lightning_breath,
	0,
	cast_fire_breath,
	0,
	cast_acid_breath,
	cast_fire_breath,
	cast_lightning_breath,
	0
};

int BreathWeapon( struct char_data* ch, int cmd, char* arg,struct char_data* mob, int type) {
	int        count;
	char* p;
	char p2[255];
	int cost;
	int tipo;
	if( type != EVENT_TICK )
	{ return FALSE; }


	if( AWAKE( mob ) && mob->specials.fighting &&
			mob->specials.fighting->in_room == mob->in_room ) {

		p=mob_index[mob->nr].specparms;
		p=one_argument(p,p2);
		cost=abs(atoi(p2));
		p=one_argument(p,p2);
		tipo=abs(atoi(p2));
		tipo=tipo>8?8:tipo;
		for (count=tipo; breaths[count]; count++)
			;

		use_breath_weapon(mob, mob->specials.fighting, cost,
						  breaths[dice(1,count-1)]);

	}

	return (FALSE);
}


bfuncp bweapons[] = {
	cast_geyser,
	cast_fire_breath,
	cast_gas_breath,
	cast_frost_breath,
	cast_acid_breath,
	cast_lightning_breath
};

void do_breath(struct char_data* ch, char* argument, int cmd) {
	struct char_data* victim;
	char        name[MAX_STRING_LENGTH];
	int        count, manacost;
	bfuncp weapon;

	if (check_peaceful(ch,"That wouldn't be nice at all.\n\r"))
	{ return; }

	only_argument(argument, name);

	BreathWeapon(ch, CMD_BREATH, (char*) NULL,ch,0);

	WAIT_STATE(ch, PULSE_VIOLENCE*2);
}
extern struct index_data* mob_index;

