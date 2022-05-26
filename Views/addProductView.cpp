
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
      productHandler->createProduct(name, description, owner, price); 
      printHtmlHeader();
      cout <<"<big>Your product: "<<name<<" is now being sold.</big>" << endl;
      printPage(); 

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
   cout << "<section class='vh-100 gradient-custom'>" << endl;
  cout << "<div class='container py-5 h-100'>" << endl;
    cout << "<div class='row d-flex justify-content-center align-items-center h-100'>" << endl;
      cout << "<div class='col-12 col-md-8 col-lg-6 col-xl-5'>" << endl;
        cout << "<div class='card bg-dark text-white' style='border-radius: 1rem;'>" << endl;
         cout <<  "<div class='card-body p-5 text-center'>" << endl;
           cout << "<h2>Add Product</h2>";
           cout<<" <p class='hint-text'>Add a new product to sell</p>";
           cout<< "<form action='sellPage' method= 'POST'>"<<endl;
            cout <<"<div class='form-group'>";
            cout<<"<input type='text' class='form-control' name='name' placeholder='Name' required='required'>";
            cout<<"</div>";
            cout <<"<div class='form-group'>";
            cout<<"<input type='number' class='form-control' name='price' placeholder='Price' required='required'>";
            cout<<"</div>";
            cout<<" <p class='hint-text'>Description of the product:</p>"<<endl;
            cout<<"<textarea name = 'description' row='20' cols='35'></textarea>"<<endl;
             cout<<" <div class='form-group'>";
              cout<<"  <button type='submit' class= 'btn btn-success btn-lg btn-block'>Add product</button>";
              cout<<" </div>";
              cout<<"</form>"<<endl;
            cout << "</div>" << endl;
          cout << "</div>" << endl;
        cout << "</div>" << endl;
      cout << "</div>" << endl;
    cout << "</div>" << endl;
  cout<< "</div>" << endl;
cout<< "</section>" << endl;

}
int main()
{
	addProductView addProductView;
return 0;
}
