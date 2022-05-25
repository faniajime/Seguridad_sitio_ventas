#ifndef SESSIONSERVICE_H
#define SESSIONSERVICE_H
#include <iostream>
#include <string>
#include <mysql/mysql.h>
#include "Database.h"

using namespace std;
class SessionService{
    public:
    SessionService();
    ~SessionService();
    bool setCookies(string);
    string getCookieKey();
    string getCookieValue();
    bool validateCookie();
    void removeCookie();
    string createSession(string email);
    bool deleteSession(string token);
    bool sessionExists(string token);
    MYSQL *conn;
    
};
#endif