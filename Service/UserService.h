#ifndef USERSERVICE_H
#define USERSERVICE_H

#include <mysql/mysql.h>
#include "Database.h"
#include <string>
using namespace std;

class UserService
{
    public:
    UserService();
    ~UserService();
    MYSQL *conn;
    void error();
    bool createUser(string nombre, string usuario, string email, int telefono, string contrasena, string direccion);
    bool checkUserExistByUsername(string username);
    bool checkUserExistByEmail(string email);
    bool passwordCorrect(string username, string password);

};
#endif
