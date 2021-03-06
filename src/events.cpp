/*ALARMUD* (Do not remove *ALARMUD*, used to automagically manage these lines
 *ALARMUD* AlarMUD 2.0
 *ALARMUD* See COPYING for licence information
 *ALARMUD*/
//  Original intial comments
/*$Id: events.c,v 1.2 2002/02/13 12:30:58 root Exp $
*/
/***************************  System  include ************************************/
#include <cstdlib>
/***************************  General include ************************************/
#include "config.hpp"
#include "typedefs.hpp"
#include "flags.hpp"
#include "autoenums.hpp"
#include "structs.hpp"
#include "logging.hpp"
#include "constants.hpp"
#include "utils.hpp"
/***************************  Local    include ************************************/
#include "events.hpp"
#include "hash.hpp"
#include "queue.hpp"
//#include "snew.hpp"
//#include "utility.hpp"
#include "comm.hpp"
namespace Alarmud {
/* ************************************************************************
*  File: events.c                                                         *
*                                                                         *
*  Usage: Contains routines to handle events                              *
*                                                                         *
*  Written by Eric Green (ejg3@cornell.edu)                               *
*                                                                         *
*  Changes:                                                               *
*      3/6/98 ejg:  Changed event_process to check return value on the    *
*                   event function.  If > 0, reenqueue to expire in       *
*                   retval time.                                          *
*                   Added check in event_cancel to make sure event_obj    *
*                   is non-NULL.                                          *
*                   Moved struct event definition from events.h.          *
************************************************************************ */


struct event {
	EVENTFUNC(*func);
	void* event_obj;
	struct q_element* q_el;
};

struct queue* event_q;          /* the event queue */

/* initializes the event queue */
void event_init(void) {
#if !NOEVENTS
	event_q = queue_init();
#endif
}


/* creates an event and returns it */
struct event* event_create(EVENTFUNC(*func), void* event_obj, long when) {
	struct event* new_event;

	if(when < 1) { /* make sure its in the future */
		when = 1;
	}

	CREATE(new_event, struct event, 1);
	new_event->func = func;
	new_event->event_obj = event_obj;
	new_event->q_el = queue_enq(event_q, new_event, when + pulse);

	return new_event;
}


/* removes the event from the system */
void event_cancel(struct event* event) {
#if !NOEVENTS
	if(!event) {
		mudlog(LOG_SYSERR,"Attempted to cancel a NULL event"); // Gaia 2001
		return;
	}

	queue_deq(event_q, event->q_el);

	if(event->event_obj) {
		free(event->event_obj);
	}
	if(event) {
		free(event);
	}
#endif
	return;
}


/* Process any events whose time has come. */
void event_process(void) {
#if !NOEVENTS
	struct event* the_event;
	while((long) pulse >= queue_key(event_q)) {
		if(!(the_event = (struct event*) queue_head(event_q))) {
			mudlog(LOG_SYSERR,"Attempt to get a NULL event");
			return;
		}

		(the_event->func)(the_event->event_obj);
		if(the_event) {
			free(the_event);
		}
	}
#endif
}


/* returns the time remaining before the event */
long event_time(struct event* event) {
	long when;
#if !NOEVENTS
	when = queue_elmt_key(event->q_el);
#else
	when=pulse;
#endif
	return (when - pulse);

}


/* frees all events in the queue */
void event_free_all(void) {
#if !NOEVENTS
	struct event* the_event;
	while((the_event = (struct event*) queue_head(event_q))) {
		if(the_event->event_obj) {
			free(the_event->event_obj);
		}
		if(the_event) {
			free(the_event);
		}
	}

	queue_free(event_q);
#endif
}
} // namespace Alarmud

