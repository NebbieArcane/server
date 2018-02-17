/* AlarMUD
 * $Id: signals.c,v 1.2 2002/03/23 16:43:20 Thunder Exp $ */
#include <signal.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include "protos.hpp"
#include "status.hpp"
/* La ridefinizione di funzioni di memoria qui causerebbe ricorsione
 * */
#define LOG_CRASH 1 // SALVO rimetto il controllo dei crash
#define MAX_FNAME_LEN 32
#define STACK_SIZE 15
int HowManyConnection(int ToAdd);
int gnPtr =-1;

char currentfile[MAX_FNAME_LEN+1]="";
int  currentline=0;
char gszMudStatus[ 150 ] = "";
char gszName[ 150 ] = "";
char gszStack[STACK_SIZE][150]= {
	"","","","","","","","","","","","","","",""
};


void* gpGeneric = NULL;


extern struct descriptor_data* descriptor_list;

void checkpointing( int dummy );
void shutdown_request( int dummy );
void logsig( int dummy );
void hupsig( int dummy );
void badcrash( int dummy );
void buscrash( int dummy );
void PrintStatus();
void PrintStatus(int level);



void PrintStatus() {
	PrintStatus(0);
}
void PrintStatus(int level) {
	int i=0;
	mudlog( LOG_SYSERR | LOG_SILENT, "Connections from start: %d",
			HowManyConnection(0));
	if (level==1) {
		mudlog(LOG_SYSERR | LOG_SILENT,"CurrentTrack %s at %d",currentfile,currentline);
		mudlog( LOG_SYSERR | LOG_SILENT, "Mud status: '%s'",
				gszMudStatus );
	}
	else {

		mudlog(LOG_SYSERR | LOG_SILENT,"LastTrack %s at %d",currentfile,currentline);
		mudlog( LOG_SYSERR | LOG_SILENT, "Mud status when crashed: '%s'",
				gszMudStatus );
	}
	mudlog( LOG_SYSERR | LOG_SILENT, "  Last Name '%s'", gszName );
	if (gnPtr>=0) {
		mudlog(LOG_SYSERR | LOG_SILENT,    " Calling Stack");
		for (i=0; i<=gnPtr; i++) {
			mudlog(LOG_SYSERR | LOG_SILENT, "       %2d.%s",i,gszStack[i]);
		}
	}
}
void SetLine(char* srcfile,int srcline) {
	int i;
	i=MIN(strlen(srcfile)+1,MAX_FNAME_LEN);
	memcpy(currentfile,srcfile,i);
	currentfile[i-1]=0;
	currentline=srcline;
}

void SetStatus( char* szStatus, char* szString, void* pGeneric ) {
	int i;
	if( szStatus ) {
		i=MIN(strlen(szStatus)+1,sizeof(gszMudStatus));
		memcpy( gszMudStatus, szStatus, i);
		gszMudStatus[ i - 1 ] = 0;
	}

	if( szString ) {
		i=MIN(strlen(szString)+1,sizeof(gszName));
		memcpy( gszName, szString, i );
		gszName[ i - 1 ] = 0;
	}

	if( pGeneric ) {
		gpGeneric = pGeneric;
	}
}
void SetStatus( char* szStatus) {
	SetStatus(szStatus,NULL,NULL);
}
void SetStatus( char* szStatus, char* szString) {
	SetStatus(szStatus,szString,NULL);
}

void PushStatus( const char* szStatus, const char* szNome ) {
	int i;

	gnPtr++;
	if (gnPtr>=STACK_SIZE)
	{ return; }
	if (gnPtr<0)
	{ return; }
	snprintf(gszStack[gnPtr],149,"%s %s",
			 szStatus?szStatus:"",
			 szNome?szNome:"");
	gszStack[gnPtr][ 149 ] = 0;

	return;
}

void PushStatus( const char* szStatus ) {
	PushStatus(szStatus, (char*) NULL);
	return;
}

void PopStatus( ) {
	if (gnPtr>=0)
	{ gnPtr--; }

	return;
}

void signal_setup() {
	struct itimerval itime;
	struct timeval interval;

	signal(SIGUSR2, shutdown_request);

	/* just to be on the safe side: */

	signal(SIGHUP, hupsig);
	signal(SIGPIPE, SIG_IGN);
	signal(SIGINT, hupsig);
	signal(SIGALRM, logsig);
	signal(SIGTERM, hupsig);
#if LOG_CRASH
	signal( SIGSEGV, badcrash );
	signal( SIGBUS, buscrash );

#endif

	/* set up the deadlock-protection */

	interval.tv_sec = 300;    /* 5 minutes */
	interval.tv_usec = 0;
	itime.it_interval = interval;
	itime.it_value = interval;
	if( setitimer( ITIMER_VIRTUAL, &itime, 0 ) < 0 )
	{ perror( "Setting Virtual timer in signal_setup" ); }
	else if( signal( SIGVTALRM, checkpointing ) == SIG_ERR )
	{ perror( "Calling 'signal' in signal_setup" ); }
}

void checkpointing( int dummy ) {
	extern int tics;

	if (!tics) {
		mudlog( LOG_SYSERR, "CHECKPOINT shutdown: tics not updated" );
		PrintStatus();

		abort();
	}
	else {
		mudlog( LOG_CHECK, "CHECKPOINT: tics updated" );
		tics = 0;
	}
	if( signal( SIGVTALRM, checkpointing ) == SIG_ERR ) {
		perror( "Calling 'signal' in checkpointing" );
		abort();
	}

}

void shutdown_request( int dummy ) {
	extern int mudshutdown;

	mudlog( LOG_CHECK, "Received USR2 - shutdown request");
	mudshutdown = 1;
}


/* kick out players etc */
void hupsig( int dummy ) {
	int i;
	extern int mudshutdown, rebootgame;

	mudlog( LOG_CHECK, "Received SIGHUP, SIGINT, or SIGTERM. Shutting down");

	raw_force_all("return");
	raw_force_all("save");
	for (i=0; i<30; i++) {
		SaveTheWorld();
	}
	mudshutdown = rebootgame = 1;
}

void logsig( int dummy ) {
	mudlog( LOG_CHECK, "Signal logsig received. Ignoring." );
	signal( SIGALRM, logsig );
}

#if LOG_CRASH
void badcrash( int dummy ) {
	static int graceful_tried = 0;
	struct descriptor_data* desc;

	mudlog( LOG_CHECK,
			"SIGSEGV received. Trying to shut down gracefully.");

	PrintStatus();

	if( !graceful_tried ) {
#if 0
		close(mother_desc);
#endif
		mudlog( LOG_CHECK, "Trying to close all sockets.");
		graceful_tried = 1;
		for( desc = descriptor_list; desc; desc = desc->next )
		{ close( desc->descriptor ); }
	}
	abort();
}
void buscrash( int dummy ) {
	static int graceful_tried = 0;
	struct descriptor_data* desc;

	mudlog( LOG_CHECK,
			"SIGBUS received. Trying to shut down gracefully.");

	PrintStatus();

	if( !graceful_tried ) {
#if 0
		close(mother_desc);
#endif
		mudlog( LOG_CHECK, "Trying to close all sockets.");
		graceful_tried = 1;
		for( desc = descriptor_list; desc; desc = desc->next )
		{ close( desc->descriptor ); }
	}
	abort();
}
#endif
float AverageEqIndex(float toadd) {
	static float curmedia=0.0;
	static float numerocasi=0.0;
	float modifier;
	if (toadd<100) { return(curmedia); }
	modifier=numerocasi;
	numerocasi++;
	modifier=modifier /numerocasi;
	curmedia*=modifier;
	curmedia+=toadd/numerocasi;
	return(curmedia);
}