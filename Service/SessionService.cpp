#include "SessionService.h"
#include <iostream>
#include <string>
using namespace std;
SessionService::SessionService() {}
SessionService::~SessionService(){}

bool SessionService::setCookies(string cookieString){
    bool success = false;
    if (cookieString != "") {
            cout << "Set-Cookie:UserID="<<cookieString<<""<< endl;
            success = true;
    }
    return success;
}

string SessionService::getCookieKey(){
    char* accessToken = getenv("HTTP_COOKIE");
    string cookies = accessToken;
    string::size_type pos = cookies.find('=');
    if (pos != string::npos)
    {
        return cookies.substr(0, pos);
    } else {
        return cookies;
    }
}
string SessionService::getCookieValue(){
    char* accessToken = getenv("HTTP_COOKIE");
    string cookies = accessToken;
    string tempCookie;
    return cookies.substr(cookies.find("=")+1);
}


