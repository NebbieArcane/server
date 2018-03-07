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
echo "No Conf file present, using builtin defaults"
rm -f src/release.h
rm -f mudroot/myst
rm -f  CMakeCache.txt
cmake . && make clean && make
if [ -x src/myst ] ; then
	cp src/myst mudroot/myst
	exit 0
fi
exit 1
