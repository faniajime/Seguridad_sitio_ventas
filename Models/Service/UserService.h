#ifndef userService_H
#define userService_H

#include <string>
#include "Database.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <mysql/mysql.h>

using namespace std;

class UserService
{
    public:
    UserService ();
    ~UserService();
    MYSQL *con;
    void error();
    bool createUser(string nombre, string usuario, string email, int telefono, string contrasena, string direccion);

};
#endif
