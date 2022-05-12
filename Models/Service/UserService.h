#ifndef USERSERVICE_H
#define USERSERVICE_H

#include <mysql/mysql.h>
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

};
#endif
