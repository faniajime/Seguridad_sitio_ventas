#include "SessionService.h"
#include <iostream>
#include <string>
using namespace std;
SessionService::SessionService(){
        char* accessToken = getenv("HTTP_COOKIE");
}
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
    string cookies = accessToken;
    string::size_type pos = cookies.find('=');
    if (pos != string::npos)
    {
        return cookies.substr(0, pos);
    } else {
        return cookies;
    }
}
bool SessionService::sessionExists(){
    if (accessToken != NULL) {
        return true;
    } else {
        return false;
    }
}
string SessionService::getCookieValue(){
    string cookies = accessToken;
    return cookies.substr(cookies.find("=")+1);
}



void SessionService::removeCookie() {
   cout<< "Set-Cookie:UserID=deleted; path=/cgi-bin; expires=Thu, 01 Jan 1970 00:00:00 GMT"<< endl;

}


