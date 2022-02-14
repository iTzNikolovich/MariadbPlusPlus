#include <iostream>
#include <mariadb/mysql.h>

using namespace std;

struct connection_details
{
    const char *server, *user, *password, *database;
};

MYSQL* mysql_connection_setup(struct connection_details mysql_details){
    MYSQL *connection = mysql_init(NULL);
    
    if(!mysql_real_connect(connection, mysql_details.server, mysql_details.user, mysql_details.password, mysql_details.database, 0, NULL, 0)){
        cout << "Connection Error: " << mysql_error(connection) << endl;
        exit(1); 
    }
    return connection;
}


MYSQL_RES* mysql_perform_query(MYSQL *connection, const char *sql_query){

    if(mysql_query(connection, sql_query)){
        cout << "MySQL Query Error: " << mysql_error(connection) << endl;
        exit(1);
    }
    return mysql_use_result(connection);
}

int main(){
    MYSQL *con;
    MYSQL_RES *res;
    MYSQL_ROW row;

    struct connection_details mysqlD;
    //PARAMETRI CONFIGURABILI
    mysqlD.server = "localhost";    // Istanza mySQL
    mysqlD.user = "myuser"; //usernamedb
    mysqlD.password = "mypassword"; //passworddb
    mysqlD.database = "mydatabase"; //database

    con = mysql_connection_setup(mysqlD);

    res = mysql_perform_query(con, "select * from tblUsers;");

    cout << ("Database Output:\n") << endl;

    while ((row = mysql_fetch_row(res)) != NULL){
        cout << row[0] << " | " << row[1] << " | " << row[2] << " | " << row[3] << " | " << row[4] << endl << endl;
    }
    mysql_free_result(res);
    mysql_close(con);
    return 0;
}
