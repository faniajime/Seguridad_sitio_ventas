
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include "addProductView.h"



using namespace std;


addProductView::addProductView(){
  parserHandler = new ParserHandler();
  sessionHandler = new SessionService();
  productHandler = new ProductService();
  headerMenuView = new HeaderMenuView();
  sessionHandler2 = new SessionService();
  
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
  } else {
    
  }
}
addProductView::~addProductView(){
}

bool addProductView::getResponse() {
  printHtmlHeader();
  printPage();
  return true;
}

bool addProductView::postResponse() {
  bool sessionExists = false;
  string name = parserHandler-> GetArg("name");
  string priceText = parserHandler->GetArg("price");
  int price = stoi(priceText);
  string description = parserHandler->GetArg("description");
  bool cookieExists = sessionHandler->sessionExistsAsCookie();
  if (cookieExists) {
    sessionExists = sessionHandler->sessionExists(sessionHandler->getCookieValue());
    if (sessionExists) {
      string token = sessionHandler->getCookieValue();
      string owner = sessionHandler2->getUserFromToken(token);
      productHandler->createProduct(name, description, price, owner); 
      printHtmlHeader();
      cout <<"<big>Your product: "<<name<<" is now being sold.</big>" << endl;
      printPage(); 

    } else {
      printHtmlHeader();
      printErrorPage();
    }
  } else {
    printHtmlHeader();
    printErrorPage();
  }
  
  return true;
}
void addProductView::printHtmlHeader() {
  cout << "Content-type: text/html" << endl << endl;
    cout << "<!DOCTYPE html>" << endl;
    cout << "<html lang = 'en'" <<endl;
    cout << "<head> <link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css'rel='nofollow' integrity='sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm' crossorigin='anonymous'>" <<endl;
    cout<<"<meta charset='utf-8'>"<<endl;
    cout << "<link rel='stylesheet' href='style.css'>" << endl;
    cout << "</head>" << endl;
}
void addProductView::printErrorPage(){
    headerMenuView->printHeader();
    cout << "<div class = text-center>"<<endl;
    cout <<"<big class ='text-center'> You cannot add a product without starting a session. Please log in to sell products.</big>" <<endl;
    cout << "<a href='login'>" <<endl; 
      cout << "<button class= 'btn btn-outline-success my-2 my-sm-0' type='button'>Go to Log In page</button>" << endl;
      cout << "</div>"<<endl;
}

void addProductView::printPage(){
    headerMenuView->printHeader();
  cout<< "<!DOCTYPE html>" <<endl;
  cout<< "<html lang='en'>" <<endl;
  cout<< "<head>" <<endl;
      cout<< "<meta charset='UTF-8'>" <<endl;
      cout<< "<meta http-equiv='X-UA-Compatible' content='IE=edge'>" <<endl;
      cout<< "<meta name='viewport' content='width=device-width, initial-scale=1.0'>" <<endl;
      cout<< "<title>Document</title>" <<endl;
      cout<< "<link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css'>    " <<endl;
      cout<< "<style>" <<endl;
          cout<< "body {" <<endl;
              cout<< "font-family: 'Lato', sans-serif;" <<endl;
          cout<< "}" <<endl;
          cout<< "h1 {" <<endl;
              cout<< "margin-bottom: 40px;" <<endl;
          cout<< "}" <<endl;
          cout<< "label {" <<endl;
              cout<< "color: #333;" <<endl;
          cout<< "}" <<endl;
          cout<< ".btn-send {" <<endl;
              cout<< "font-weight: 300;" <<endl;
              cout<< "letter-spacing: 0.2em;" <<endl;
              cout<< "width: 80%;" <<endl;
              cout<< "margin-left: 3px;" <<endl;
              cout<< "}" <<endl;
          cout<< ".help-block.with-errors {" <<endl;
              cout<< "color: orange;" <<endl;
              cout<< "margin-top: 5px;" <<endl;
          cout<< "}" <<endl;
          cout<< ".card{" <<endl;
              cout<< "margin-left: 10px;" <<endl;
              cout<< "margin-right: 10px;" <<endl;
          cout<< "}" <<endl;
      cout<< "</style>" <<endl;
  cout<< "</head>" <<endl;
  cout<< "<body>" <<endl;
      cout<< "<div class='container'>" <<endl;
          cout<< "<div class=' text-center mt-5 '>" <<endl;
              cout<< "<h1 >Add a product</h1>   " <<endl;
          cout<< "</div>" <<endl;
      cout<< "<div class='row '>" <<endl;
        cout<< "<div class='col-lg-7 mx-auto'>" <<endl;
          cout<< "<div class='card mt-2 mx-auto p-4 bg-light'>" <<endl;
              cout<< "<div class='card-body bg-light'>" <<endl;
              cout<< "<div class = 'container'>" <<endl;
              cout<< "<form action='sellPage' method= 'POST'>"<<endl;
                              cout<< "<form id='contact-form' role='form'>" <<endl;
              cout<< "<div class='controls'>" <<endl;
                  cout<< "<div class='row'>" <<endl;
                      cout<< "<div class='col-md-6'>" <<endl;
                          cout<< "<div class='form-group'>" <<endl;
                              cout<< "<label for='form_name'>Product name:</label>" <<endl;
                              cout<< "<input id='form_name' type='text' name='name' class='form-control' pattern = '[a-zA-Z]+' title = 'only alphabets are allowed'placeholder='Please enter the product name' required='required' data-error='The name is required.'>                            " <<endl;
                          cout<< "</div>" <<endl;
                      cout<< "</div>                   " <<endl;
                  cout<< "</div>" <<endl;
                  cout<< "<div class='row'>" <<endl;
                      cout<< "<div class='col-md-6'>" <<endl;
                          cout<< "<div class='form-group'>" <<endl;
                              cout<< "<label for='price'>Product price:</label>" <<endl;
                              cout<< "<input id='price' type='text' name='price' class='form-control' pattern = '[0-9]+' title='only numbers are allowed.'placeholder='Please enter the price' required='required' data-error='Price is required.'>" <<endl;
                          cout<< "</div>" <<endl;
                      cout<< "</div>" <<endl;
                  cout<< "</div>" <<endl;
                  cout<< "<div class='row'>" <<endl;
                      cout<< "<div class='col-md-12'>" <<endl;
                          cout<< "<div class='form-group'>" <<endl;
                              cout<< "<label for='desc'>Product description:</label>" <<endl;
                              cout<< "<input label id='desc' type='text' name='description' class='form-control' pattern='[a-zA-Z0-9 \.\,\?]+' title = 'please refrain from using special characters. We know what you are trying to do!' placeholder='Write a description of your product here' style='height:100px;font-size:14pt;' rows ='3' required='required' data-error='Please, write a description'>" <<endl;
                          cout<< "</div>" <<endl;
                      cout<< "<div class='col-md-12'>                        " <<endl;
                          cout<< "<button type='submit' class='btn btn-success btn-send  pt-2 btn-block' >Add product</button>" <<endl;
                  cout<< "</div>           " <<endl;
                  cout<< "</div>" <<endl;
          cout<< "</div>" <<endl;
          cout<< "</form>" <<endl;
          cout<< "</div>" <<endl;
              cout<< "</div>" <<endl;
      cout<< "</div>" <<endl;
      cout<< "</div>" <<endl;
  cout<< "</div>" <<endl;
  cout<< "</div>" <<endl;
  cout<< "</body >" <<endl;
  cout<< "</html >" <<endl;

}
int main()
{
	addProductView addProductView;
return 0;
}
