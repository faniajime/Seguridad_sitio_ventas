


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include "productsView.h"
using namespace std;
#include <vector>

productsView::productsView() {
  parserHandler = new ParserHandler();
  productHandler = new ProductService();
  productHandler2 = new ProductService();
  headerView = new HeaderMenuView();
  sessionService = new SessionService();
  cartService = new CartService();
  cartService2 = new CartService();
  sessionService2 = new SessionService();
    if (sessionService->sessionExistsAsCookie()) {
    token = sessionService->getCookieValue();
    if(sessionService->sessionExists(token)) {
      isLoggedIn = true;
    }
  }
      username = sessionService2->getUserFromToken(token);
   
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


}
bool productsView::getResponse() {
  this->productsList = productHandler->getProducts();
  printPage();
  return true;
}

bool productsView::postResponse() {
  if (parserHandler->GetArg("keyword")!=NULL) {
    char* keyword = parserHandler->GetArg("keyword");
    string key = keyword;
    if (keyword != NULL) {
      this->productsList = productHandler2->searchProductByKey(keyword);
    }
  }
  if (parserHandler->GetArg("id")!=NULL) {

    char * id = parserHandler->GetArg("id");
    string productStringId = id;
    int productId = atoi(id);

    cartService->addtoCart(username,productStringId);
  }
     printPage();

  return true;
}

productsView::~productsView() {

} 
void productsView::addProduct(string usuario, string productID){
  cartService->addtoCart(usuario, productID);
}

void productsView::printPage() {
    cout << "Content-type: text/html" << endl << endl;
    cout << "<!DOCTYPE html>" << endl;
    cout << "<html lang='en'>" << endl;
    cout << "<head>" << endl;
        cout << "<meta charset='UTF-8'>" << endl;
        cout << "<meta http-equiv='X-UA-Compatible' content='IE=edge'>" << endl;
        cout << "<meta name='viewport' content='width=device-width, initial-scale=1.0'>" << endl;
        cout << "<link rel='stylesheet' href='https://stackpath.bootstrapcdn.com/bootstrap/4.4.1/css/bootstrap.min.css'/>" << endl;
        cout << "<title>Productos</title>" << endl;
    cout << "</head>" << endl;
    headerView->printHeader();
    cout << "<body>" << endl;
        cout << "<h1 style='text-align:center; color:navy;'>Productos</h1><br/>" << endl;
            if(isLoggedIn) {
           cout << "<h1 style='text-align:center; color:navy;'>Products currently in carrito:</h1><br/>" << endl;
           this->cartList = cartService2->getCart(username);
                            cout<<"<div style ='text-align:center'>"<<endl;
          for(const auto& cart : cartList){

                       cout << cart.name+", ";
          }
            cout << endl;
            cout<<"</div>"<<endl;
            } 
          if (!isLoggedIn) {
          cout <<"<h3 style='text-align:center;'>You must start a new session in order to buy products. </h3>"<<endl;  
        }

        cout << "<div class='row' style='text-align:center'><div class='col text-center'>" <<endl;
        cout << "<form action='buyPage' method='POST' class='navbar-form pull-left'>" <<endl;
        cout << "<input type='text' class='span2' name='keyword'>" <<endl;
        cout << "<button type='submit' class='btn btn-secondary btn-sm' >Buscar</button>" <<endl;
        cout << "</form>" <<endl;
        cout << "</div></div>" <<endl;
        cout << "<div class='container mt-5 mb-5'>" << endl;
        cout << "<div class='d-flex justify-content-center row'>" << endl;
            cout << "<div class='col-md-10'>" << endl;

                for(const auto& prod : productsList)
                {

        
                    cout << "<div class='row p-2 bg-white border rounded'>" << endl;
                        cout << "<div class='col-md-6 mt-1'>" << endl;
                            cout << "<h5>"+prod.name+"</h5>" << endl;
                            cout << "<div class='d-flex flex-row'>" << endl;
                                cout << "<span>Usuario: "+prod.owner+"</span>" << endl;
                            cout << "</div>" << endl;
                            cout << "<div class='mt-1 mb-1 spec-1'>" << endl;
                                cout << "<span>"+prod.description+"</span><span class='dot'></span></div>" << endl;                        
                        cout << "</div>" << endl;
                        cout << "<div class='align-items-center align-content-center col-md-3 border-left mt-1'>" << endl;
                            cout << "<div class='d-flex flex-row align-items-center'>" << endl;
                                cout << "<h4 class='mr-1'>₡ "+to_string(prod.cost)+"</h4>" << endl;
                            cout << "</div>" << endl;
                            if (isLoggedIn){
                      cout<< "<form action='buyPage' method= 'POST'>"<<endl;
                      cout <<"<div class='form-group'>";
                             cout<<"<input type='hidden' class='form-control' name='keyword' value=''>" <<endl;
                       cout<<"<input type='hidden' class='form-control' name='id' value='"<<prod.id<<"'>" <<endl;
                        cout << "<div class='d-flex flex-column mt-4'><button type='submit' class='btn btn-primary btn-sm' type='button'>Add to carrito</button></div>" << endl;
                       cout<<"</div>";
                      cout << "</form>"<<endl;
                            } else {
                              cout << "<div class='d-flex flex-column mt-4'><button disabled class='btn btn-primary btn-sm' type='button'>Add to carrito</button></div>" << endl;
                            }
                        cout << "</div>" << endl;
                    cout << "</div>" << endl;
                }
        cout << "</div>" << endl;
        cout << "</div>" << endl;
    cout << "</div>" << endl;
    cout << "</body>" << endl;
    cout << "</html>" << endl;
}

int main () {
  productsView productsView;

}