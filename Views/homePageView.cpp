#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <string>
#include "homePageView.h"
using namespace std;


homePageView::homePageView() {
  refreshCount = 0;
  parserHandler = new ParserHandler();
  userHandler = new UserService();
  headerMenuView = new HeaderMenuView();
  sessionService = new SessionService();
  sessionService2 = new SessionService();
  encrypter = new Encryptor();


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
  string password = encrypter->encrypt(userPassword);
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
        if (refreshCount == 0) {
          refreshCount++;
          cout << "Content-type: text/html\n\n"; 
          cout <<"<meta http-equiv='refresh' content='0'>" << endl;
      }
      printPage();
      } else {
        cout << "Content-type: text/html\n\n"; 
        cout << "oops, something went wrong!" << endl;

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
    cout<<" <div class='col-xs-1 text-center'>"<< endl;
    cout<< "<h1> Welcome to our Virtual Market! Product delivery is not guaranteed.</h1>" << endl; 
    if (sessionService->sessionExistsAsCookie()) {
      cout << "<a href='sellPage'>" <<endl; 
      cout << "<button class= 'btn btn-outline-success my-2 my-sm-0' type='button'>Start Selling</button>" << endl;
      cout << "</a>"<<endl;          
   } else {
       cout << "<a href='login'>" <<endl; 
      cout << "<button class= 'btn btn-outline-success my-2 my-sm-0' type='button'>Log In to start selling products</button>" << endl;
      cout << "</a>"<<endl;
   }
        cout << "<a href='buyPage'>" <<endl; 
      cout << "<button class= 'btn btn-outline-success my-2 my-sm-0' type='button'>Browse product catalog</button>" << endl;
      cout << "</a>"<<endl;
    cout<<"</div>"<<endl;
        


    cout << "</body>" << endl;

}

int main () {
  homePageView homePageView;
}