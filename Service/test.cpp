//#include "../Models/userModel.h"
//#include "UserService.cpp"
#include "../Service/ProductService.h"
#include "../Models/productModel.h"
#include "ProductService.h"
#include "SessionService.h"
#include <iostream>


using namespace std;

int main(){
    //UserService* us = new UserService();
    //us->createUser("Fabiola", "fejimene", "bla", 888888, "asdasd", "asdasd");
    
    //productService* ps = new productService();
    //ps->getProductById(9);
    /*
    if(ps->updateProduct(8,"Queque","zanahoria", "kzv",1000)){
        cout<<"Se actualizo el producto";
    }
    
    if(ps->deleteProduct(8)){
        cout<<"Se elimino el producto";
    }
    */
   SessionService* sesssion = new SessionService();
    string email = "fabij@gmail.com";
    string ses = "3bd0e0b6c1892c739272276ea6bfddc8556f06c432bdbb189892d6e9b382f0f4";
    sesssion->createSession(email);
    if(sesssion->sessionExists(ses)){
        cout << "Sesssion exists" <<endl;
    }
    SessionService* sess = new SessionService();
    sess->deleteSession(ses);

    cout <<"here" <<endl;
    if(!(sess->sessionExists(ses))){
        cout << "Sesssion was deleted" <<endl;
    }
}



