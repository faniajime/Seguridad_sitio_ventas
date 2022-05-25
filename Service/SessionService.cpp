#include "SessionService.h"
#include <iostream>
#include <string>
using namespace std;
SessionService::SessionService(){}
SessionService::~SessionService(){}

bool SessionService::setCookies(string cookieString){
    bool success = false;
    if (cookieString != "") {
            // hashear el cookie y despues sustituirlo por "cookieString" en Set-Cookie
            cout << "Set-Cookie:UserID="<<cookieString<<""<< endl;
            //base de datos para meterlo ahi
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
    return cookies.substr(cookies.find("=")+1);
}

bool SessionService::validateCookie() {
    // retrieve cookie from database, and compare it with the cookie value saved on the browser
     //(do getCookieKey to validate there is a UserId, then getCookieValue to compare it with database)
}

void SessionService::removeCookie() {
   cout<< "Set-Cookie:UserID=; path=/; expires=Thu, 01 Jan 1970 00:00:00 GMT" << endl;

}


