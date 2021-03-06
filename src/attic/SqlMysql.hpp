/*ALARMUD* (Do not remove *ALARMUD*, used to automagically manage these lines
 *ALARMUD* AlarMUD 2.0
 *ALARMUD* See COPYING for licence information
 *ALARMUD*/
#ifndef __SQLMYSQL_HPP_
#define __SQLMYSQL_HPP_
/***************************  System  include ************************************/
#include "mysql_connection.h"
#include "mysql_driver.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <boost/shared_ptr.hpp>
using namespace sql;
/***************************  Local    include ************************************/
namespace Alarmud {
typedef boost::shared_ptr<PreparedStatement> SqlStatement;
class SqlMysql {
public:
	SqlMysql();
	virtual ~SqlMysql();
	SqlStatement prepare(const string &query);
	ResultSet* execute();
	ResultSet* executeQuery(const PreparedStatement* stm);
	template<typename T>
	void push(SqlStatement stm,int index,T value);
private:
	Driver* driver;
	Connection* db;
	std::map<string,SqlStatement> cache;


};
} // namespace Alarmud


#endif /* __SQLMYSQL_HPP_ */

