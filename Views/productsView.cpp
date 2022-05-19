#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include "productsView.h"
using namespace std;


productsView::productsView() {

  //productHandler = new productService();

}

productsView::~productsView() {

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
    cout << "<body>" << endl;
        cout << "<h1>Productos</h1>" << endl;
        cout << "<div class='container mt-5 mb-5'>" << endl;
        cout << "<div class='d-flex justify-content-center row'>" << endl;
            cout << "<div class='col-md-10'>" << endl;
                for(int i = 0; i<5;++i){
                    cout << "<div class='row p-2 bg-white border rounded'>" << endl;
                    cout << "<div class='col-md-6 mt-1'>" << endl;
                        cout << "<h5>Carlota</h5>" << endl;
                        cout << "<div class='d-flex flex-row'>" << endl;
                            cout << "<span>Usuario: kzv</span>" << endl;
                        cout << "</div>" << endl;
                        cout << "<div class='mt-1 mb-1 spec-1'>" << endl;
							cout << "<span>Sabor chocolate con frutas</span><span class='dot'></span></div>" << endl;                        
                    cout << "</div>" << endl;
                    cout << "<div class='align-items-center align-content-center col-md-3 border-left mt-1'>" << endl;
                        cout << "<div class='d-flex flex-row align-items-center'>" << endl;
                            cout << "<h4 class='mr-1'>₡12 000</h4>" << endl;
                        cout << "</div>" << endl;
                        cout << "<div class='d-flex flex-column mt-4'><button class='btn btn-primary btn-sm' type='button'>Agregar al carrito</button><button class='btn btn-outline-primary btn-sm mt-2' type='button'>Comprar</button></div>" << endl;
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
  productsView.printPage();
}