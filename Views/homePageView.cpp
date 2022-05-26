#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <string>
#include "homePageView.h"
using namespace std;


homePageView::homePageView() {

  parserHandler = new ParserHandler();
  userHandler = new UserService();
  headerMenuView = new HeaderMenuView();
  sessionService = new SessionService();
  sessionService2 = new SessionService();


  char* requestMethod = getenv("REQUEST_METHOD");
  char* queryString = getenv("QUERY_STRING");
  char* contentLength = getenv("CONTENT_LENGTH");
  int queryLength = 0;
  int accessTokenLength = 0;

  if (contentLength != NULL) {
    queryLength = atoi(contentLength);
    queryString = (char*)malloc(queryLength);
    if(queryString != NULL) {
      for (int pos = 0; pos < queryLength; pos++) {
        queryString[pos] = fgetc(stdin);
      }
    }
  }
  
  //parseQuery(queryString,queryLength,parserHandler);

//  AQUI DEBERIAN IR LOS METODOS DEL PARSE QUERYM STRING, ETC
  if (queryString != NULL && contentLength != NULL) {
    parserHandler->parseQuery(queryLength, queryString);
  }
  if (requestMethod != NULL) {
    if (strcmp(requestMethod,"GET")== 0) {
      getResponse();
    }

    if (strcmp(requestMethod,"POST") ==0) {
      postResponse();
    }

  }
}

bool homePageView::getResponse() {
  printPage();
  return true;
}

bool homePageView::postResponse() {
  char * userEmail = parserHandler->GetArg("userEmail");
  char * userPassword = parserHandler->GetArg("userPassword");
  string email = userEmail;
  string password = userPassword;
  string token;
  if (userEmail != NULL) {
    if (userPassword != NULL) {
      bool passwordExists = userHandler->passwordCorrect(email, password);
      if(passwordExists) {
      if(!sessionService->sessionExistsAsCookie()) {
        string mockToken =sessionService->createToken(email);
        if (!sessionService->sessionExists(mockToken)) {
           string token = sessionService2->createSession(email);
          sessionService->setCookies(token);
        } else {
          sessionService->setCookies(mockToken);
        }
               

      }

      printPage();
      } else {
        cout << "Content-type: text/html\n\n"; 
        cout << "it's not working!" << endl;

      }
  
    } else {
      //password error
    }
  } else {
    //email error
 }

  return true;
}



homePageView::~homePageView() {

} 

void homePageView::printPage() 
{


     cout << "Content-type: text/html" << endl << endl;
    cout << "<!DOCTYPE html>" << endl;
    cout << "<html lang = 'en'" <<endl;
    cout << "<head> <link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css'rel='nofollow' integrity='sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm' crossorigin='anonymous'>" <<endl;
    cout<<"<meta charset='utf-8'>"<<endl;
    cout << "<link rel='stylesheet' href='style.css'>" << endl;
    cout << "</head>" << endl;
    headerMenuView->printHeader();
    cout << "<body>" << endl;
    cout<< "<h2> testing that it works</h2>" << endl; 
        if (sessionService->getCookieKey() == "UserID") {
    string cookieKey = sessionService->getCookieKey();
     string cookieValue = sessionService->getCookieValue();
                 cout << "<h2> printing cookie value:"<< cookieKey <<" and cookie key:"<<cookieValue<<"</h2>"<<endl;
   }


    cout << "</body>" << endl;

}

int main () {
  homePageView homePageView;
}