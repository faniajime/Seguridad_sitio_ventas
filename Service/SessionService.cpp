#include "SessionService.h"
#include <iostream>
#include <string>
#include "encryptionService.h"

using namespace std;

SessionService::SessionService(){
    Database* db = new Database();
    if(db->connectToDatabase()){
        conn = db->getConnection();
    }
    accessToken = getenv("HTTP_COOKIE");

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

string SessionService::getCookieValue(){
    string cookies = accessToken;
    return cookies.substr(cookies.find("=")+1);
}



void SessionService::removeCookie() {
   cout<< "Set-Cookie:UserID=deleted; path=/cgi-bin; expires=Thu, 01 Jan 1970 00:00:00 GMT"<< endl;

}


string SessionService::createSession(string email){
    
    Encryptor* encryptor = new Encryptor();
    if (conn==NULL){
        return NULL;
    }
    string token = encryptor->encrypt(email + "pelos");
    string query = "CALL crear_sesion( '" +email+ "','" +token+ "','" + to_string(true)+"')";

    if (mysql_query(conn,query.c_str())){
      return NULL;
    }
    return token;
}
    
bool SessionService::deleteSession(string token){
    if (conn==NULL){
        return false;
    }
    string query = "CALL borrar_sesion( '" + token + "')"  ;
    if (mysql_query(conn,query.c_str())){
      return false;
    }
    return true;
}
bool SessionService::sessionExistsAsCookie(){
    if (accessToken != NULL) {
        return true;
    } else {
        return false;
    }
}
bool SessionService::sessionExists(string token){
    MYSQL_ROW row;
    MYSQL_RES* res;
    char* response = 0;
    bool exists = false;
    string query = "CALL get_sesion( '" + token + "')"  ;
    if(!mysql_query(conn,query.c_str())){
      res = mysql_use_result(conn);
      if((row=mysql_fetch_row(res))!=NULL){
        response = row[0];
      }
      if(response[0] >= '1'){
        exists = true;
      }
    }
    mysql_free_result(res);
    return exists;
}

