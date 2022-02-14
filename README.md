# MariadbPlusPlus

Get information about a database from MariaDB using C++ with mysql.h

# Requirements:
- MariaDB
- G++ Compiler
- Optional: a Linux istance (You can also use Windows or Mac OS)

# Compile from source
You will need [mariaDB](https://mariadb.com/docs/clients/mariadb-connectors/connector-cpp/) libraries to compile this application:


I use ``libmariadb-dev-compat`` on my Raspberry Pi with Raspberry Pi OS. 

You can get it: ``sudo apt-get install libmariadb-dev-compat``

**Using GNU compiler**

``g++ main.cpp -o mariadbpp -L/usr/include/mariadb/mysql -lmariadbclient``

# Run

``./mariadbpp``
