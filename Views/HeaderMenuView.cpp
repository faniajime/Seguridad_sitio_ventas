#include <iostream>
#include "HeaderMenuView.h"

using namespace std;

HeaderMenuView::HeaderMenuView (){
}
HeaderMenuView::~HeaderMenuView () {

}
void HeaderMenuView::printHeader() {

   cout<< "<nav class='navbar navbar-expand-lg navbar-light bg-light'>" <<endl;
  cout<< "<a class='navbar-brand' href='homePage'>Home</a>" <<endl;
  cout<< "<button class='navbar-toggler' type='button' data-toggle='collapse' data-target='#navbarSupportedContent' aria-controls='navbarSupportedContent' aria-expanded='false' aria-label='Toggle navigation'>"<<endl;
    cout<< "<span class='navbar-toggler-icon'></span>" <<endl;
  cout << "</button>"<< endl;
  cout<< "<div class='collapse navbar-collapse' id='navbarSupportedContent'>" <<endl;
   cout<<  "<ul class='navbar-nav mr-auto'>" <<endl;
      cout<< "<li class='nav-item'>" <<endl;
        cout<< "<a class='nav-link' href='buyPage'>Compra</a>" <<endl;
      cout << "</li>" <<endl;
   cout<<   "<li class='nav-item'>" << endl;
        cout << "<a class='nav-link' href='sellPage'>Venta</a>" << endl;
     cout << "</li>" << endl;
      cout << "<li class='nav-item'>" <<endl;
        cout << "<a class='nav-link' href='QA'>Need help?</a>" << endl;
      cout << "</li>" << endl;
       cout << "<li class='nav-item'>" <<endl;
        cout << "<a class='nav-link' href='#'>Need help?</a>" << endl;
      cout << "</li>" << endl;
    cout << "</ul>" << endl;
    cout << "<form class='form-inline my-2 my-lg-0'>" <<endl;
      cout << "<a href='login'>" <<endl; 
      cout << "<button class= 'btn btn-outline-success my-2 my-sm-0' type='button'>Log Out/Log In</button>" << endl;
      cout << "</a>"<<endl;
      cout << "<button class='btn btn-outline-success my-2 my-sm-0' type='submit'>Carrito</button>"<<endl;
    cout << "</form>"<<endl;
  cout << "</div>"<<endl;
  cout << "</nav>" <<endl;

}