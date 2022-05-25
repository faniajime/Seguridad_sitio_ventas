//#include "../Models/userModel.h"
//#include "UserService.cpp"
#include "../Service/ProductService.h"
#include "../Models/productModel.h"
#include "ProductService.h"
#include "Encryptor.h"
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
   Encryptor* encrypt = new Encryptor();
    string password = "holi";
    string compare = "adios";
    string output = encrypt->encrypt(password);
    cout << "SHA is " << output << endl;
    string output2 = encrypt->encrypt(output);
    if(output ==output2){
        cout << "Passwords are equal" << endl;
    }
    if(encrypt->theSame(password, output)){
        cout << "Yes they are" <<endl;
    }
}
