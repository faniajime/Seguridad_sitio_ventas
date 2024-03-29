

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include "registerPageView.h"
using namespace std;


registerPageView::registerPageView(){
  headerView = new HeaderMenuView();
}
registerPageView::~registerPageView(){
}

void registerPageView::printPage(){

cout << "Content-type: text/html" << endl << endl;
    cout << "<!DOCTYPE html>" << endl;
    cout << "<html lang = 'en'" <<endl;
    cout << "<head> <link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css'rel='nofollow' integrity='sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm' crossorigin='anonymous'>" <<endl;
    cout<<"<meta charset='utf-8'>"<<endl;
    cout << "<link rel='stylesheet' href='style.css'>" << endl;
    cout << "</head>" << endl;
    headerView->printHeader();
   cout << "<section class='vh-100 gradient-custom'>" << endl;
  cout << "<div class='container py-5 h-100'>" << endl;
    cout << "<div class='row d-flex justify-content-center align-items-center h-100'>" << endl;
      cout << "<div class='col-12 col-md-8 col-lg-6 col-xl-5'>" << endl;
        cout << "<div class='card bg-dark text-white' style='border-radius: 1rem;'>" << endl;
         cout <<  "<div class='card-body p-5 text-center'>" << endl;
           cout << "<h2>Register</h2>";
           cout<<" <p class='hint-text'>Create your account:</p>";
           cout<< "<form action='postRegistration' method= 'POST'>"<<endl;
            cout <<"<div class='form-group'>";
            cout<<"<input type='text' class='form-control' name='name' pattern= '[a-zA-Z]+' title = 'only alphabets are allowed.' placeholder='Name' required='required'>";
            cout<<"</div>";
            cout <<"<div class='form-group'>";
            cout<<"<input type='email' class='form-control' name='email' placeholder='Email' required='required'>";
            cout<<"</div>";
            cout <<"<div class='form-group'>";
            cout<<"<input type='text' class='form-control' name='user' pattern = '[a-zA-Z0-9]+' title = 'only letters and numbers are allowed.' placeholder='User' required='required'>";
            cout<<"</div>";
            cout <<"<div class='form-group'>";
            cout<<"<input type='text' class='form-control' name='phone_number'  pattern='[0-9 ]{6,11}' title='please enter a valid phone number' placeholder='Phone number' required='required'>";
            cout<<"</div>";
            cout <<"<div class='form-group'>";
            cout<<"<input type='text' class='form-control' name='direction' pattern='[a-zA-Z0-9 \.\,\?]+' title='special characters are now allowed.' placeholder='Direction' required='required'>";
            cout<<"</div>";
            cout<<"<div class='form-group'>";
            cout<<"<input type='password' class='form-control' name='password' pattern='(?=.*\\d)(?=.*[a-z])(?=.*[A-Z]).{8,}' title='Must contain at least one number and one uppercase and lowercase letter, and at least 8 or more characters' placeholder='Password' required='required'>";
            cout <<"</div>";
            cout<<"<div class='form-group'>";
            cout<<" <input type='password' class='form-control' name='confirm_password' placeholder='Confirm Password' required='required'>";
            cout<<"</div>";

             cout<<" <div class='form-group'>";
              cout<<"  <button type='submit' class= 'btn btn-success btn-lg btn-block'>Register Now</button>";
           cout<<" </div>";
              cout<<"</form>"<<endl;
             //cout<<"<div class='text-center'>Already have an account?";
           //cout<<" <a href='#'>Sign in</a>";
        //cout<<"</div>";
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
	registerPageView registerPageView;
        registerPageView.printPage();
return 0;
}