#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <string>
#include "loginPageView.h"
using namespace std;

loginPageView::loginPageView() {

  parserHandler = new ParserHandler();
  //userHandler = new UserService();
  userHandler = new UserService();
  headerMenuView = new HeaderMenuView();

  char* requestMethod = getenv("REQUEST_METHOD");
  char* queryString = getenv("QUERY_STRING");
  char* contentLength = getenv("CONTENT_LENGTH");
  char* requestAddress = getenv("REMOTE_ADDR");
  char* accessToken = getenv("HTTP_COOKIE");
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
  char* response = parserHandler->GetArg("hello");
  cout << "hello" << response[0] <<endl;
}
loginPageView::~loginPageView() {

} 
bool loginPageView::getResponse() {
  printPage();
  return true;
}
bool loginPageView::postResponse() {
  char * userEmail = parserHandler-> GetArg("userEmail");
  char * userPassword = parserHandler->GetArg("userPassword");
  if (userEmail != NULL) {
    //if (userPassword != NULL) {
      //if (userHandler-> passwordCorrect(userEmail, userPassword)) {
        //cout << "Content-type: text/html" <<endl <<endl;
        //cout << " user has logged in successfully" << endl;
        
      //} else {
        // error message
      //}
    //} else {
      //password error
    //}
  } else {
    //email error
  }

bool loginPageView::postResponse() {
  return true;
}


/*
void loginPageView::parseQuery(char* queryString, int contentLength, ParserHandler* parserHandler) {

  if (queryString != NULL && contentLength != NULL) {
    parserHandler->parseQuery(contentLength, queryString);
  }
}
*/


void loginPageView::printPage() {

     cout << "Content-type: text/html" << endl << endl;
    cout << "<!DOCTYPE html>" << endl;
    cout << "<html lang = 'en'" <<endl;
    cout << "<head> <link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css'rel='nofollow' integrity='sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm' crossorigin='anonymous'>" <<endl;
    cout<<"<meta charset='utf-8'>"<<endl;
    cout << "<link rel='stylesheet' href='style.css'>" << endl;
    cout << "</head>" << endl;
    headerMenuView->printHeader();
    cout << "<body>" << endl;
   cout << "<section class='vh-100 gradient-custom'>" << endl;
  cout << "<div class='container py-5 h-100'>" << endl;
    cout << "<div class='row d-flex justify-content-center align-items-center h-100'>" << endl;
      cout << "<div class='col-12 col-md-8 col-lg-6 col-xl-5'>" << endl;
        cout << "<div class='card bg-dark text-white' style='border-radius: 1rem;'>" << endl;
         cout <<  "<div class='card-body p-5 text-center'>" << endl;
            cout << "<div class='mb-md-5 mt-md-4 pb-5'>" << endl;
              cout << "<h2 class='fw-bold mb-2 text-uppercase'>Login</h2>" << endl;
              cout << "<p class='text-white-50 mb-5'>Please enter your login and password!</p>" << endl;
            cout<< "<form action='homePage' method= 'POST'>"<<endl;
              cout << "<div class='form-outline form-white mb-4'>" << endl;
                cout << "<input name='userEmail' type='email' id='typeEmailX' class='form-control form-control-lg' />" << endl;
                cout << "<label class='form-label' for='typeEmailX'>Email</label>" << endl;
              cout << "</div>"<< endl;
              cout << "<div class='form-outline form-white mb-4'>" <<endl;
                cout << "<input name='userPassword' type='password' id='typePasswordX' class='form-control form-control-lg' />" << endl;
                cout << "<label class='form-label' for='typePasswordX'>Password</label>" << endl;
             cout << "</div>" << endl;
              cout << "<p class='small mb-5 pb-lg-2'><a class='text-white-50' href='#!'> Forgot password?</a></p>" << endl;
              cout << " <button class='btn btn-outline-light btn-lg px-5' type='submit'>Login</button>" << endl;
              cout<<"</form>"<<endl;
            cout << "</div>" << endl;
            cout << "<div>" << endl;
              cout << "<p class='mb-0'>Don't have an account? <a href='register' class='text-white-50 fw-bold'>Sign Up</a>" << endl;
              cout<< "</p>" << endl;
            cout << "</div>" << endl;
          cout << "</div>" << endl;
        cout << "</div>" << endl;
      cout << "</div>" << endl;
    cout << "</div>" << endl;
  cout<< "</div>" << endl;
cout<< "</section>" << endl;
cout << "</body>" << endl;

}

int main () {
  loginPageView loginPage;
}
