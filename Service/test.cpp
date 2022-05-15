#include "../Models/userModel.h"
//#include "UserService.cpp"
#include "ProductService.h"
#include <iostream>


using namespace std;

int main(){
    //UserService* us = new UserService();
    //us->createUser("Fabiola", "fejimene", "bla", 888888, "asdasd", "asdasd");
    
    productService* ps = new productService();
    ps->getProductById(9);
    /*
    if(ps->updateProduct(8,"Queque","zanahoria", "kzv",1000)){
        cout<<"Se actualizo el producto";
    }
    
    if(ps->deleteProduct(8)){
        cout<<"Se elimino el producto";
    }
    */
}
