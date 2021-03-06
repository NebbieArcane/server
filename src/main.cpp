/*ALARMUD* (Do not remove *ALARMUD*, used to automagically manage these lines
 *ALARMUD* AlarMUD 2.0
 *ALARMUD* See COPYING for licence information
 *ALARMUD*/
//  Original intial comments
/***************************  System  include ************************************/
#include <iostream>
#include <boost/program_options.hpp>
#include <boost/scoped_ptr.hpp>
#include <mutex>
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
#include "main.hpp"
#include "comm.hpp"
#include "interpreter.hpp"
#include "snew.hpp"
#include "Sql.hpp"

namespace Alarmud {

using std::string;
using std::endl;
using std::cout;
int main(int argc, char** argv) {


#ifdef DFLT_PORT
	int port=DFLT_PORT;
#else
	int port=4000;
#endif
#ifdef DFLT_DIR
	string dir(DFLT_DIR);
#else
	string dir("lib");
#endif
	string server_name="starting";
	string comment="";
	unsigned short debug_level=2;
#ifdef env_master
	debug_level=99;
#endif
#ifdef env_devel
	debug_level=99;
	SetTest(true);
#endif
#ifdef env_vagrant
	debug_level=99;
	SetTest(true);
#endif
	namespace po = boost::program_options ;
	po::options_description opt("Allowed options");
	opt.add_options()
	("help,h","Produce help message")
	("demonize,D","Run as daemon")
	("log_players,L","Logs all players' actions")
	("log_mobs,M","Logs all mobs' actions")
	("disable_dns,N","Disables DNS")
	("newbie_approve,R","Requests approvation for new players")
	("ansi_off,A","Disables all colors")
	("test_mode,t","Developer mode, disables password checking")
	("version,V","Display version and terminates")
	("verbose_log,v",po::value<unsigned short> (& debug_level)->default_value(debug_level),"Log verbosity level")
	("directory,d",po::value<string>(&dir)->default_value(dir),"Data directory")
	("nospecials,s",po::value<bool>(&no_specials)->default_value(false),"Disable specials procedures")
//    ;
//    po::options_description hidden("Hidden options");
//    hidden.add_options()
	("port,P",po::value<int> (&port),"Port (can also be given as first parameter)")
	;
	po::positional_options_description positional;
	positional.add("port",1);
	po::options_description all("All");
	all.add(opt);//.add(hidden);
	po::variables_map vm;
	try {
		po::store(po::command_line_parser(argc, argv).
				  options(all).positional(positional).run(), vm);
	}
	catch(po::unknown_option &e) {
		cout << e.what() << endl;
	}
	po::notify(vm);
	if(vm.count("version")) {
		cout << version() << endl;
		exit(0);
	}
	if(vm.count("help") or !vm.count("port")) {
		cout << argv[0] << " <port> <options>" << endl;
		cout << opt << endl;
		exit(0);
	}
	cout << endl;

	if(vm.count("test_mode")) {
		SetTest(true);
	}
	if(vm.count("ansi_off")) {
		SET_BIT(SystemFlags,SYS_NOANSI);
	}
	if(vm.count("disable_DNS")) {
		SET_BIT(SystemFlags,SYS_SKIPDNS);
	}
	if(vm.count("log_players")) {
		SET_BIT(SystemFlags,SYS_LOGALL);
	}
	if(vm.count("newbie_approve")) {
		SET_BIT(SystemFlags,SYS_REQAPPROVE);
	}
	if(vm.count("log_mobs")) {
		SET_BIT(SystemFlags,SYS_LOGMOB);
	}
	log_configure(logger,"alarmud",".log",get_level(debug_level),vm.count("demonize")==0); // If not demonized also logs to console
	log_configure(errlogger,"errors",".log",log4cxx::Level::getError(),false);
	log_configure(buglogger,"bugs","",log4cxx::Level::getAll(),false);
	log_configure(querylogger,"query",".log",log4cxx::Level::getAll(),vm.count("demonize")==0);
	if(vm.count("demonize")) {
		int pid = fork();

		if(pid < 0) {
			LOG4CXX_FATAL(logger,"Error forking sysD daemon.");
		}
		else if(pid > 0) {
			// Parent exit.
			cout << "Demonized " << pid <<endl;
			exit(0);
		}

		if(setsid() < 0) {
			LOG4CXX_FATAL(logger,"ERROR setting session : " << strerror(errno));
		}
		// Inside forked process
		fclose(stdout);
		fclose(stderr);
	}
	fclose(stdin);
	if(chdir(dir.c_str()) < 0) {
		LOG4CXX_FATAL(logger,"Unable to change dir to " << dir);
		LOG4CXX_FATAL(errlogger,"Unable to change dir to " << dir);
		perror("chdir");
		assert(0);
	}
	FILE* fd;
	fd=fopen("../alarmud.pid","w");
	if(fd) {
		fprintf(fd,"%d",getpid());
		fclose(fd);
	}
	LOG4CXX_TRACE(logger,"Boost version " << BOOST_VERSION);
	std::once_flag dbupdateflag;
	std::call_once(dbupdateflag,Sql::dbUpdate);
	run(port,dir.c_str());
	return 0;
}
} // namespace Alarmud
int main(int argc, char** argv) {
	return Alarmud::main(argc,argv);
}
