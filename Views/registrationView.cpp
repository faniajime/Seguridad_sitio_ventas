#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <string>
#include "registrationView.h"
using namespace std;


registrationView::registrationView() {

  parserHandler = new ParserHandler();
  userHandler = new UserService();
  userHandler2 = new UserService();
  userHandler3 = new UserService();
  headerMenuView = new HeaderMenuView();
  encrypter = new Encryptor();
  

  char* requestMethod = getenv("REQUEST_METHOD");
  char* queryString = getenv("QUERY_STRING");
  char* contentLength = getenv("CONTENT_LENGTH");
  char* requestAddress = getenv("REMOTE_ADDR");
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

bool registrationView::getResponse() {
  printPage();
  return true;
}

bool registrationView::postResponse() 
{
  char * userName = parserHandler-> GetArg("name");
  char * userEmail = parserHandler->GetArg("email");
  char * userId = parserHandler->GetArg("user");
  char * phoneNumber = parserHandler->GetArg("phone_number");
  char * userDirection = parserHandler->GetArg("direction");
  char * userPassword = parserHandler->GetArg("password");
  char * passwordConfirmation = parserHandler->GetArg("confirm_password");

  string email = userEmail;
  string user = userId;

  if (userEmail != NULL && userPassword != NULL && userId != NULL) 
  {
    bool emailExists = userHandler->checkUserExistByEmail(email);
    bool userExists = userHandler2->checkUserExistByUsername(user);
    if(!emailExists && !userExists)
    {
        string encryptedPassword = encrypter->encrypt(userPassword);
        if(userHandler3->createUser(userName,userId,userEmail,stoi(phoneNumber),encryptedPassword,userDirection))
        {
            printPage();
        }else {
        }  
    } else {
      cout << "Content-type: text/html" << endl << endl;
    cout << "<!DOCTYPE html>" << endl;
    cout << "<html lang = 'en'" <<endl;
    cout << "<head> <link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css'rel='nofollow' integrity='sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm' crossorigin='anonymous'>" <<endl;
    cout<<"<meta charset='utf-8'>"<<endl;
    cout << "<link rel='stylesheet' href='style.css'>" << endl;
    cout << "</head>" << endl;
    headerMenuView->printHeader();
    cout << "<h2 text-align:center> User or email already exists! please try again. </h2> " <<endl; 
    }
  } 

  return true;
}

registrationView::~registrationView() {

} 

void registrationView::printPage() 
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
    cout<< "<h2> Welcome!</h2>" << endl;
    cout<< "<h5> You have been registered succesfully</h5>" << endl; 
          cout << "<a href='login'>" <<endl; 
      cout << "<button class= 'btn btn-outline-success my-2 my-sm-0' type='button'>Go to Log In page</button>" << endl;
      cout << "</a>"<<endl;
    cout << "</body>" << endl;

}

int main () {
  registrationView registrationView;
}
