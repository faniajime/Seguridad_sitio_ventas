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
   cout << "hola" <<endl;
   SessionService* sesssion = new SessionService();
    string email = "fabij._@gmail.com";
    string ses = "11acf0fd603ea463895f6103eeded5c0e7ffe7aaa36078d523a1ee1eaa2fe894";
    sesssion->createSession(email);

    SessionService* sess = new SessionService();
    string user = sess->getUserFromToken(ses);

    cout << user<<endl;
}



