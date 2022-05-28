#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include "paymentView.h"
using namespace std;


paymentView::paymentView(){
  parserHandler = new ParserHandler();
  sessionHandler = new SessionService();
  sessionHandler2 = new SessionService();
  productHandler = new ProductService();
  headerMenuView = new HeaderMenuView();
  cartService = new CartService();
  cartService2 = new CartService();
  cartService3 = new CartService();
  
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
  try{
    string token = sessionHandler->getCookieValue();
    string user = sessionHandler->getUserFromToken(token);
    this->total = cartService->getTotal(user);
    this->carrito = cartService2->getCart(user);
    printHead();
    printPage();
    return true;
  }catch(const std::exception& e){
      printHead();
      headerMenuView->printHeader();
      totalError();
  }
}

bool paymentView::postResponse(){
  char* name = parserHandler->GetArg("name");
  char* card = parserHandler->GetArg("card");
  char* date = parserHandler->GetArg("date");
  char* cvv = parserHandler->GetArg("cvc");
  string total = parserHandler->GetArg("total");

  try{
      if (name != NULL && card != NULL && date != NULL && cvv !=NULL) {
        
          string token = sessionHandler2->getCookieValue();
          string user = sessionHandler2->getUserFromToken(token);
          cartService2->buyCart(user, total);
          printSuccess();
          return true;
      }else{
        printError();
        return false;
      }
  }catch(...){
      printError();
      return true;
  }

}

void paymentView::printSuccess(){
    printHead();
    headerMenuView->printHeader();
    cout << "<div class='alert alert-success' role='alert'>'" <<endl;
    cout << "Your purchase was successful" <<endl;
    cout << "</div>" <<endl;
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

void paymentView::totalError(){
    cout << "<div class='alert alert-danger' role='alert'>'" <<endl;
    cout << "You need to be logged in to access this page" <<endl;
    cout << "</div>" <<endl;
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
  cout << "<html lang='en'>" << endl;
  cout << "<head>" << endl;
    cout << "<meta charset='UTF-8'>" << endl;
    cout << "<link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css'rel='nofollow' integrity='sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm' crossorigin='anonymous'>" << endl;
    cout << "<style>" << endl;
      cout << "body{" << endl;
      cout << "background: linear-gradient(110deg, #222324 60%,#4b5053  60%);" << endl;
      cout << "}" << endl;
      cout << ".shop{" << endl;
      cout << "font-size: 10px;" << endl;
      cout << "}" << endl;
      cout << ".space{" << endl;
      cout << "letter-spacing: 0.8px !important;" << endl;
      cout << "}" << endl;
      cout << ".second a:hover {" << endl;
      cout << "color: rgb(92, 92, 92) ;" << endl;
      cout << "}" << endl;
      cout << ".active-2 {" << endl;
      cout << "color: rgb(92, 92, 92) " << endl;
      cout << "}" << endl;
      cout << ".breadcrumb>li+li:before {" << endl;
      cout << "content: ' !important" << endl;
      cout << "}" << endl;
      cout << ".breadcrumb {" << endl;
      cout << "padding: 0px;" << endl;
      cout << "font-size: 10px;" << endl;
      cout << "color: #aaa !important;" << endl;
      cout << "}" << endl;
      cout << ".first {" << endl;
      cout << "background-color: white ;" << endl;
      cout << "}" << endl;
      cout << "a {" << endl;
      cout << "text-decoration: none !important;" << endl;
      cout << "color: #aaa ;" << endl;
      cout << "}" << endl;
      cout << ".btn-lg,.form-control-sm:focus," << endl;
      cout << ".form-control-sm:active," << endl;
      cout << "a:focus,a:active {" << endl;
      cout << "outline: none !important;" << endl;
      cout << "box-shadow: none !important" << endl;
      cout << "}" << endl;
      cout << ".form-control-sm:focus{" << endl;
      cout << "border:1.5px solid #4bb8a9 ; " << endl;
      cout << "}" << endl;
      cout << ".btn-group-lg>.btn, .btn-lg {" << endl;
      cout << "padding: .5rem 0.1rem;" << endl;
      cout << "font-size: 1rem;" << endl;
      cout << "border-radius: 0;" << endl;
      cout << "color: white !important;" << endl;
      cout << "background-color: #4b96b8;" << endl;
      cout << "height: 2.8rem !important;" << endl;
      cout << "border-radius: 0.2rem !important;" << endl;
      cout << "}" << endl;
      cout << ".btn-group-lg>.btn:hover, .btn-lg:hover {" << endl;
      cout << "background-color: #266ca6;" << endl;
      cout << "}" << endl;
      cout << ".btn-outline-primary{" << endl;
      cout << "background-color: #fff !important;" << endl;
      cout << "color:#4bb8a9 !important;" << endl;
      cout << "border-radius: 0.2rem !important;   " << endl;
      cout << "border:1px solid #4bb8a9;" << endl;
      cout << "}" << endl;
      cout << ".btn-outline-primary:hover{" << endl;
      cout << "background-color:#4bb8a9  !important;" << endl;
      cout << "color:#fff !important;" << endl;
      cout << "border:1px solid #4bb8a9;" << endl;
      cout << "}" << endl;
      cout << ".card-2{" << endl;
      cout << "margin-top: 40px !important;" << endl;
      cout << "}" << endl;
      cout << ".card-header{" << endl;
      cout << "background-color: #fff;" << endl;
      cout << "border-bottom:0px solid #aaaa !important;" << endl;
      cout << "}" << endl;
      cout << "p{" << endl;
      cout << "font-size: 13px ;" << endl;
      cout << "}" << endl;
      cout << ".small{" << endl;
      cout << "font-size: 9px !important;" << endl;
      cout << "}" << endl;
      cout << ".form-control-sm {" << endl;
      cout << "height: calc(2.2em + .5rem + 2px);" << endl;
      cout << "font-size: .875rem;" << endl;
      cout << "line-height: 1.5;" << endl;
      cout << "border-radius: 0;   " << endl;
      cout << "}" << endl;
      cout << ".cursor-pointer{" << endl;
      cout << "cursor: pointer;" << endl;
      cout << "}" << endl;
      cout << ".boxed {" << endl;
      cout << "padding: 0px 8px 0 8px ;" << endl;
      cout << "background-color: #4bb8a9;" << endl;
      cout << "color: white;" << endl;
      cout << "}" << endl;
      cout << ".boxed-1{" << endl;
      cout << "padding: 0px 8px 0 8px ;" << endl;
      cout << "color: black !important;" << endl;
      cout << "border: 1px solid #aaaa;" << endl;
      cout << "}" << endl;
      cout << ".bell{" << endl;
      cout << "opacity: 0.5;" << endl;
      cout << "cursor: pointer;" << endl;
      cout << "}" << endl;
      cout << "@media (max-width: 767px) {" << endl;
      cout << ".breadcrumb-item+.breadcrumb-item {" << endl;
      cout << "padding-left: 0" << endl;
      cout << "}" << endl;
      cout << "}" << endl;
    cout << "</style>" << endl;
    cout << "<title>Cart Page</title>" << endl;
  cout << "</head>" << endl;
}

void paymentView::printPage(){

    headerMenuView->printHeader();
    cout << "<body>" << endl;
      cout << "<div class=' container-fluid my-5 '>" << endl;
      cout << "<div class='row justify-content-center '>" << endl;
      cout << "<div class='col-xl-10'>" << endl;
      cout << "<div class='card shadow-lg '>" << endl;
      cout << "<div class='row justify-content-around'>" << endl;
      cout << "<div class='col-md-5'>" << endl;
      cout << "<div class='card border-0'>" << endl;
      cout << "<div class='card-header pb-0'>" << endl;
      cout << "<br/>" << endl;
      cout << "<br>" << endl;
      cout << "<h2 class='card-title space '>Checkout</h2>" << endl;
      cout << "</div>" << endl;

      cout << "<form action='payPage' method='POST'>" <<endl;
        cout << "<div class='card-body'>" << endl;
        cout << "<div class='row mt-4'>" << endl;
        cout << "<div class='col'><p class='text-muted mb-2'>PAYMENT DETAILS</p><hr class='mt-0'></div>" << endl;
        cout << "</div>" << endl;
        cout << "<div class='form-group'>" << endl;
        cout << "<label for='NAME' class='small text-muted mb-1'>NAME ON CARD</label>" << endl;
        cout << "<input type='text' class='form-control form-control-sm' name='name' id='NAME' aria-describedby='helpId' placeholder='Name of cardholder'>" << endl;
        cout << "</div>" << endl;
        cout << "<div class='form-group'>" << endl;
        cout << "<label for='NAME' class='small text-muted mb-1'>CARD NUMBER</label>" << endl;
        cout << "<input type='text' class='form-control form-control-sm' name='card' id='NAME' aria-describedby='helpId' placeholder='4534 5555 5555 5555'>" << endl;
        cout << "</div>" << endl;
        cout << "<div class='row no-gutters'>" << endl;
        cout << "<div class='col-sm-6 pr-sm-2'>" << endl;
        cout << "<div class='form-group'>" << endl;
        cout << "<label for='NAME' class='small text-muted mb-1'>VALID THROUGH</label>" << endl;
        cout << "<input type='text' class='form-control form-control-sm' name='date' id='NAME' aria-describedby='helpId' placeholder='06/21'>" << endl;
        cout << "</div>" << endl;
        cout << "</div>" << endl;
        cout << "<div class='col-sm-6'>" << endl;
        cout << "<div class='form-group'>" << endl;
        cout << "<label for='NAME' class='small text-muted mb-1'>CVC CODE</label>" << endl;
        cout << "<input type='text' class='form-control form-control-sm' name='cvc' id='NAME' aria-describedby='helpId' placeholder='183'>" << endl;
        cout << "<input type='hidden' class='form-control form-control-sm' name='total' value='" << this->total << "'>" << endl;
        cout << "</div>" << endl;
        cout << "</div>" << endl;
        cout << "</div>" << endl;
        cout << "<div class='row mb-md-5'>" << endl;
        cout << "<div class='col'>" << endl;
        cout << "<button type='submit' class='btn  btn-lg btn-block '>PURCHASE</button>" << endl;
        cout << "</div>" << endl;
        cout << "</div>    " << endl;
        cout << "</div>" << endl;
        cout << "</div>" << endl;
        cout << "</div>" << endl;
      cout << "</form>" <<endl;

      cout << "<div class='col-md-5'>" << endl;
      cout << "<div class='card border-0 '>" << endl;
      cout << "<div class='card-header card-2'>" << endl;
      cout << "<p class='card-text text-muted mt-md-4  mb-2 space'>YOUR ORDER </p>" << endl;
      cout << "<hr class='my-2'>" << endl;
      cout << "</div>" << endl;
      cout << "<div class='card-body pt-0'>" << endl;
      if(!carrito.empty()){
        for(const auto &product: carrito){
          cout << "<div class='row  justify-content-between'>" << endl;
          cout << "<div class='col-auto col-md-7'>" << endl;
          cout << "<div class='media flex-column flex-sm-row'>" << endl;
          cout << "<div class='media-body  my-auto'>" << endl;
          cout << "<div class='row '>" << endl;
          cout << "<div class='col-auto'><p class='mb-0'><b>" << product.name << "</b></p><small class='text-muted'>" << product.description << "</small></div>" << endl;
          cout << "</div>" << endl;
          cout << "</div>" << endl;
          cout << "</div>" << endl;
          cout << "</div>" << endl;
          cout << "<div class=' pl-0 flex-sm-col col-auto  my-auto '><p><b>₡" << product.cost << "</b></p></div>" << endl;
          cout << "</div>" << endl;
          cout << "<hr class='my-2'>" << endl;
        }
      }else{
        cout << "<b>Cart is emp</b>" <<endl;
      }
      cout << "<div class='row '>" << endl;
      cout << "<div class='col'>" << endl;
      cout << "<div class='row justify-content-between'>" << endl;
      cout << "<div class='col-4'><p ><b>Total</b></p></div>" << endl;
      cout << "<div class='flex-sm-col col-auto'><p  class='mb-1'><b>₡" << this->total <<"</b></p> </div>" << endl;
      cout << "</div><hr class='my-0'>" << endl;
      cout << "</div>" << endl;
      cout << "</div>" << endl;
      cout << "</div>" << endl;
      cout << "</div>" << endl;
      cout << "</div>" << endl;
      cout << "</div>" << endl;
      cout << "</div>" << endl;
      cout << "</div>" << endl;
      cout << "</div>" << endl;
      cout << "</div>" << endl;
    cout << "</body>" << endl;
    cout << "</html>" << endl;
}

int main()
{
  paymentView paymentView;
  return 0;
}
