
#include "Database.h"
#include <mysql/mysql.h>
#include <iostream>
using namespace std;
Database::Database(){}

Database::~Database(){
  mysql_close(conn);
  delete conn;
}

bool Database::connectToDatabase(){
  bool connected = true;
  const char* MY_HOSTNAME = "localhost";
  const char* MY_DATABASE = "hackeques";
  const char* MY_USERNAME = "root";
  const char* MY_PASSWORD = "holi";
  const char* MY_SOCKET = NULL;
  
  conn = mysql_init(NULL);
  
  if(!mysql_real_connect(conn,MY_HOSTNAME,MY_USERNAME,MY_PASSWORD,MY_DATABASE, 3306, MY_SOCKET, 0)){
    connected = false;
  }
  return connected;
}

MYSQL* Database::getConnection(){
  return conn;
}
