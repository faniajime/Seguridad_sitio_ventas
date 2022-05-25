
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include "addProductView.h"



using namespace std;


addProductView::addProductView(){
}
addProductView::~addProductView(){
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
