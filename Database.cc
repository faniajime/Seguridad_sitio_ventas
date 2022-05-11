
#include "Database.h"

Database::Database(){}

Database::~Database(){
  mysql_close(conn);
  delete conn;
}

bool Database::connectToDatabase(){
  bool connected = true;
  string MY_HOSTNAME = "localhost";
  string MY_DATABASE = "server";
  string MY_USERNAME = "admin";
  string MY_PASSWORD = "admin";
  string MY_SOCKET = NULL;
  
  conn = mysql_init(NULL);
  
  if(!mysql_real_connect(conn,MY_HOSTNAME,MY_USERNAME,MY_PASSWORD,MY_DATABASE, 3306, MY_SOCKET, 0)){
    connected = false;
  }
  return connected;
}

MYSQL* Database::getConnection(){
  return conn;
}
