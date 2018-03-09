#!/bin/bash
# Utilizzato dal sistema di deploy.
# In ambiente di sviluppo va lanciato solo se si aggiunge un nuovo file
set -o allexport
cd $(dirname "$0")
MYSQL_USER="root" #db user'
MYSQL_PASSWORD="secret" # db password
MYSQL_HOST="localhost" #db host
MYSQL_DB="nebbie" #db name
SERVER_PORT=4002 #default server port
environment=${1:-vagrant}
conf="$HOME/Confs/$environment.conf"
if [ -f $conf ] ; then
	. $conf
else
	echo "No Conf file for $environment present, using builtin defaults"
fi
php=$(which php)
if [ -z "$php" ] ; then
	echo "Missing php, skipping autoenum regen"
else
	(
	cd shutils
	$php ./code_generator.php
	cp *.?pp ../src/
	)
fi
rm -f src/release.h
rm -f src/myst src/info
rm -f mudroot/myst
rm -rf build
( PATH="/usr/lib/cache:$PATH" CXX=g++ CC=gcc mkdir -p build && cd build && cmake -U "alarmud*" -U "CMAKE_HOME_DIRECTORY" -U "CMAKE_CACHEFILE_DIR" .. )  
cmake --build build --clean-first
if [ -x src/myst ] ; then
	exit 0
fi
exit 1
