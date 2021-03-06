/*ALARMUD* (Do not remove *ALARMUD*, used to automagically manage these lines
 *ALARMUD* AlarMUD 2.0
 *ALARMUD* See COPYING for licence information
 *ALARMUD*/
//  Original intial comments
/*$Id: events.h,v 1.2 2002/02/13 12:30:58 root Exp $
*/
/***************************  System  include ************************************/
/***************************  Local    include ************************************/
namespace Alarmud {
/* ************************************************************************
*  File: events.h                                                         *
*                                                                         *
*  Usage: structures and prototypes for events                            *
*                                                                         *
*  Written by Eric Green (ejg3@cornell.edu)                               *
*                                                                         *
*  Changes:                                                               *
*      3/6/98 ejg:  Changed return type of EVENTFUNC from void to long.   *
*                   Moved struct event definition to events.c.            *
************************************************************************ */
#ifndef __EVENTS_HPP
#define __EVENTS_HPP
#define EVENTFUNC(name) long (name)(void *event_obj)


/* function protos need by other modules */
void event_init(void);
struct event* event_create(EVENTFUNC(*func), void* event_obj, long when);
void event_cancel(struct event* event);
void event_process(void);
long event_time(struct event* event);
void event_free_all(void);

#endif //__EVENTS_HPP
} // namespace Alarmud

