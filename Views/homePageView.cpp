#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include "homePageView.h"
using namespace std;


homePageView::homePageView() {

  
}

homePageView::~homePageView() {

} 

void homePageView::printPage() 
{
    cout << "Content-type: text/html" << endl << endl;
    cout << "<!DOCTYPE html>"<< endl;
    cout << "<html lang='en'>"<< endl;
    cout << "<head>"<< endl;
    cout << "<title>Bootstrap Example</title>"<< endl;
    cout << "<meta charset='utf-8'>"<< endl;
    cout << "<meta name='viewport' content='width=device-width, initial-scale=1'>"<< endl;
    cout << "<link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css'>"<< endl;
    cout << "<link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css'>"<< endl;
    cout << "<link rel=”stylesheet” href=”https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css”>"<< endl;
    cout << "<script src='https://ajax.googleapis.com/ajax/libs/jquery/3.6.0/jquery.min.js'></script>"<< endl;
    cout << "<script src='https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js'></script>"<< endl;
    cout << "<link rel='stylesheet' href='https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css'>"<< endl;
    cout << "<body>"<< endl;
    cout << "<nav class='navbar navbar-inverse'>"<< endl;
    cout << "<div class='container-fluid'>"<< endl;
        cout << "<div class='navbar-header'>"<< endl;
        cout << "<a class='navbar-brand' href='#'>Hackeques</a>"<< endl;
        cout << "</div>"<< endl;
        cout << "<ul class='nav navbar-nav'>"<< endl;
        cout << "<li class='active'><a href='#'>Home</a></li>"<< endl;
        cout << "<li><a href='http://localhost/cgi-bin/producto9.cgi'>Ver Productos</a></li>"<< endl;
        cout << "<li><a href='#'>Page 2</a></li>"<< endl;
        cout << "<li><a href='#' style='color: red;'><i class='bi bi-cart'></i></a></li>"<< endl;
        cout << "</ul>"<< endl;
    cout << "</div>"<< endl;
    cout << "</nav>"<< endl;
    cout << "<div class='container'>"<< endl;
    cout << "<h3>Hackeques</h3>"<< endl;
    cout << "<p></p>"<< endl;
    cout << "</div>"<< endl;
    cout << "</body>"<< endl;
    cout << "</html>"<< endl;
}

int main () {
  homePageView homePageView;
  homePageView.printPage();
}