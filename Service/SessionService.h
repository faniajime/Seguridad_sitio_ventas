#ifndef SESSIONSERVICE_H
#define SESSIONSERVICE_H
#include <iostream>
#include <string>

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
};
#endif