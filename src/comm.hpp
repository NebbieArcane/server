/*$Id: comm.h,v 1.2 2002/02/13 12:30:57 root Exp $
*/
#ifndef __COMM
#define __COMM 1
#include "config.hpp"
#define TO_ROOM    0
#define TO_VICT    1
#define TO_NOTVICT 2
#define TO_CHAR    3
#ifndef BLOCK_WRITE
#define SEND_TO_Q(messg, desc)  write_to_q((messg), &(desc)->output)
#else
#define SEND_TO_Q(messg, desc)  write_to_output((messg), desc)
#endif


#define PLAYER_AUTH 0
#define DFLT_DIR		"lib"				/* default data directory     */


int _affected_by_s(struct char_data* ch, int skill);
void actall(char* s1, char* s2, char* s3, struct char_data* ch, struct char_data* vc);
void act(char* str, int hide_invisible, struct char_data* ch, struct obj_data* obj, void* vict_obj, int type );
void CheckCharAffected(char* msg );
inline void CheckObjectExDesc(char* msg );
void close_socket_fd(int desc);
void close_sockets(int s);
void close_socket(struct descriptor_data* d);
void coma(int s);
void construct_prompt(char* outbuf, struct char_data* ch );
void flush_queues(struct descriptor_data* d);
void game_loop(int s);
int get_from_q(struct txt_q* queue, char* dest);
int init_socket(int port);
void InitScreen(struct char_data* ch);
int main(int argc, char** argv);
int new_connection(int s);
int new_descriptor(int s);
void nonblock(int s );
void ParseAct(const char* str, struct char_data* ch, struct char_data* to, void* vict_obj, struct obj_data* obj, char* buf);
char* ParseAnsiColors(int UsingAnsi, const char* txt );
int process_input(struct descriptor_data* t);
int process_output(struct descriptor_data* t);
void raw_force_all(char* to_force);
void run_the_game(int port);
void save_all();
void send_to_all(const char* messg );
void send_to_arctic(const char* messg);
void send_to_char(const char* messg, struct char_data* ch );
void send_to_desert(const char* messg );
void send_to_except(const char* messg, struct char_data* ch);
void send_to_out_other(const char* messg );
void send_to_outdoor(const char* messg);
void send_to_room_except_two(const char* messg, int room, struct char_data* ch1, struct char_data* ch2);
void send_to_room_except(const char* messg, int room, struct char_data* ch);
void send_to_room(const char* messg, int room);
void send_to_zone(const char* messg, struct char_data* ch);
void str2ansi(const char* p2, char* p1, int start, int stop );
struct timeval timediff(struct timeval* a, struct timeval* b);
int update_max_usage(void);
void UpdateScreen(struct char_data* ch, int update);
int write_to_descriptor(int desc, char* txt);
void write_to_output(char* txt, struct descriptor_data* t);
void write_to_q(char* txt, struct txt_q* queue);



#endif