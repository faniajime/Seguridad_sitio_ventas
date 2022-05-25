
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
  printPage();
  return true;
}

bool addProductView::postResponse() {
  string name = (string) parserHandler-> GetArg("name");
  //Convertir el precio de string a int
  char* priceText = parserHandler->GetArg("price");
  int price = atoi(priceText);
  //int price = stoi((string) parserHandler->GetArg("price"));
  string description = parserHandler->GetArg("description");
 // string owner = sessionService.getCookieValue("email"); //Conseguir el email de la sesion
    string owner = "test";
  //Se debe crear validacion de los datos para verificar que todo esta correcto o no vacio.
  productHandler->createProduct(name, description, owner, price); 

  cout << "Content-type: text/html\n\n"; 
  cout <<"<marquee> producto ingresado! </marquee>" << endl;



  return true;
}


void addProductView::printPage(){

cout << "Content-type: text/html" << endl << endl;
    cout << "<!DOCTYPE html>" << endl;
    cout << "<html lang = 'en'" <<endl;
    cout << "<head> <link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css'rel='nofollow' integrity='sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm' crossorigin='anonymous'>" <<endl;
    cout<<"<meta charset='utf-8'>"<<endl;
    cout << "<link rel='stylesheet' href='style.css'>" << endl;
    cout << "</head>" << endl;
   cout << "<section class='vh-100 gradient-custom'>" << endl;
  cout << "<div class='container py-5 h-100'>" << endl;
    cout << "<div class='row d-flex justify-content-center align-items-center h-100'>" << endl;
      cout << "<div class='col-12 col-md-8 col-lg-6 col-xl-5'>" << endl;
        cout << "<div class='card bg-dark text-white' style='border-radius: 1rem;'>" << endl;
         cout <<  "<div class='card-body p-5 text-center'>" << endl;
           cout << "<h2>Add Product</h2>";
           cout<<" <p class='hint-text'>Add a new product to sell</p>";
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
        addProductView.printPage();
return 0;
}
