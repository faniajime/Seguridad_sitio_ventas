#ifndef DATABASE_H
#define DATABASE_H
#include <mysql/mysql.h>

class Database {
  public:
    Database();
    ~Database();
    bool connectToDatabase();
    MYSQL* getConnection();
    MYSQL* conn;
   
};

#endif
