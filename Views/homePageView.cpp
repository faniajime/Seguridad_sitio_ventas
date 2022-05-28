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
  printHead();
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
                printHead();
                printPage();
      }

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



void homePageView::printHead() {
  cout << "Content-type: text/html" << endl << endl;
  cout << "<!DOCTYPE html>" << endl;
  cout << "<html lang='en'>" << endl;
  cout << "<head>" << endl;
  cout << "<meta charset='utf-8' />" << endl;
  cout << "<meta name='viewport' content='width=device-width, initial-scale=1, shrink-to-fit=no' />" << endl;
  cout << "<meta name='description' content='' />" << endl;
  cout << "<meta name='author' content='' />" << endl;
  cout << "<head> <link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css'rel='nofollow' integrity='sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm' crossorigin='anonymous'>" <<endl;
  cout << "<link type='text/css' rel='stylesheet' href='stylesheet.css' />" << endl;
  cout << "<title>Homepage</title>" << endl;
  cout << "</head>" << endl;
} 

void homePageView::printPage() 
{

    headerMenuView->printHeader();
    cout << "<body>" << endl;
    cout << "<header class='py-5 bg-dark'>" << endl;
    cout << "<div class='text-center my-5'>" << endl;
    cout << "<br>" << endl;
    cout << "<br>" << endl;
    cout << "<br>" << endl;
    cout << "<h1 class='text-white fw-bolder'  style='font-size:10vh !important; text-shadow: 2px 2px transparent;' >Welcome to Hackeques!</h1>" << endl;
    cout << "<p class='text-white mb-0' style='font-size:4vh !important; '>Your favorite dessert website</p>" << endl;
    cout << "<br>" << endl;
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
    cout << "<br>" << endl;
    cout << "<br>" << endl;
    cout << "</div>" << endl;
    cout << "</header>" << endl;
    cout << "<section class='py-5'>" << endl;
    cout << "<div class='container my-5'>" << endl;
    cout << "<div class='row justify-content-center'>" << endl;
    cout << "<div class='col-lg-6'>" << endl;
    cout << "<h2>Product delivery is not guaranteed.</h2>" << endl;
    cout << "</div>" << endl;
    cout << "</div>" << endl;
    
        
      cout << "</section>" << endl;
    cout << "<footer class='py-5 bg-dark'>" << endl;
    cout << "<div class='container'><p class='m-0 text-center text-white'>Copyright &copy; Hackeques 2022</p></div>" << endl;
    cout << "</footer>" << endl;
    cout << "<script src='https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.bundle.min.js'></script>" << endl;
    cout << "<script src='js/scripts.js'></script>" << endl;

    cout << "</body>" << endl;

}

int main () {
  homePageView homePageView;
}