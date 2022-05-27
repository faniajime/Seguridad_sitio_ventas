#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include "paymentView.h"
using namespace std;


paymentView::paymentView(){
  parserHandler = new ParserHandler();
  sessionHandler = new SessionService();
  productHandler = new ProductService();
  headerMenuView = new HeaderMenuView();
  cartService = new CartService();
  cartService2 = new CartService();
  
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
bool paymentView::getResponse(){
  printHead();
  printPage();
}

bool paymentView::postResponse(){
  char* name = parserHandler->GetArg("name");
  char* card = parserHandler->GetArg("card");
  char* date = parserHandler->GetArg("date");
  char* cvv = parserHandler->GetArg("cvv");
  string token = sessionHandler->getCookieValue();
  string user = sessionHandler->getUserFromToken(token);
  
  if (name != NULL && card != NULL && date != NULL && cvv !=NULL) {
    printHead();
    //int total = cartService->getTotal(user);
    //cout << total <<endl;
    cout << "cmamo" <<endl;
    //if(/*checkCardValidity(card) && */cartService2->buyCart(user,total)){
      //printHead();
      //headerMenuView->printHeader();
      //cout << "<br/> <h1>Your purchase was successful!</h1>" <<endl;
   // }
  }else{
    printError();
    return false;
  }
}
bool paymentView::checkCardValidity(string card){
    int sum = 0;

    for (char ch : card)
    {
        if (isdigit(ch))
        {
            sum += ch - '0';
        }
    }
    if(sum%10==0){
      return true;
    }else{
      return false;
    }
}


void paymentView::printError(){
  printHead();
    cout << "<div class='alert alert-danger' role='alert'>'" <<endl;
    cout << "We could not process your purchase" <<endl;
    cout << "</div>" <<endl;
  printPage();
}

void paymentView::printHead(){
  cout << "Content-type: text/html" << endl << endl;
    cout << "<!DOCTYPE html>" << endl;
    cout << "<html lang = 'en'" <<endl;
    cout << "<head> <link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css'rel='nofollow' integrity='sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm' crossorigin='anonymous'>" <<endl;
    cout<<"<meta charset='utf-8'>"<<endl;
    cout << "<link rel='stylesheet' href='style.css'>" << endl;
    cout << "</head>" << endl;
}
void paymentView::printPage(){


    headerMenuView->printHeader();
   cout << "<section class='vh-100 gradient-custom'>" << endl;
  cout << "<div class='container py-5 h-100'>" << endl;
    cout << "<div class='row d-flex justify-content-center align-items-center h-100'>" << endl;
      cout << "<div class='col-12 col-md-8 col-lg-6 col-xl-5'>" << endl;
        cout << "<div class='card bg-dark text-white' style='border-radius: 1rem;'>" << endl;
         cout <<  "<div class='card-body p-5 text-center'>" << endl;
         cout << "<form action='payPage' method='POST' class='navbar-form pull-left'>" <<endl;
           cout << "<h2>Buy product</h2>";
           cout<<" <p class='hint-text'>Enter your account information:</p>";
            cout <<"<div class='form-group'>";
            cout << "<label for='name'>Name on the Card</label>" <<endl;
            cout<<"<input type='text' class='form-control' name='name' id='name' placeholder='Name' required='required'>";
            cout<<"</div>";
            cout <<"<div class='form-group'>";
            cout << "<label for='card'>Credit Card Number</label>" <<endl;
            cout<<"<input type='text' class='form-control' id='card' name='card' placeholder='1111-2222-3333-4444' required='required'>";
            cout<<"</div>" <<endl;
            cout <<"<div class='form-group'>";
            cout << "<label for='date'>Expiration Date</label>" <<endl;
            cout<<"<input type='text' class='form-control' name='date' placeholder='MM/YYYY' required='required'>";
            cout<<"</div>";
            cout <<"<div class='form-group'>";
            cout << "<label for='cvv'>CVV</label>" <<endl;
            cout<<"<input type='text' class='form-control' name='cvv' placeholder='000' required='required'>";
            cout<<"</div><br/>";
             cout<<" <div class='form-group'>";
              cout<<"  <button type='submit' class= 'btn btn-success btn-lg btn-block'> Buy </button>";
           cout<<" </div>";
           cout << "</form>" <<endl;
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
  paymentView paymentView;
  return 0;
}
