//#include "../Models/userModel.h"
//#include "UserService.cpp"
#include "../Models/productModel.h"
#include "ProductService.h"
#include "../Service/CartService.h"
#include <iostream>


using namespace std;

int main(){

    CartService* cs = new CartService();
    string user = "fabi";
    string ses = "11acf0fd603ea463895f6103eeded5c0e7ffe7aaa36078d523a1ee1eaa2fe894";
    int total = cs->deleteCart(user);
    cout << total ;
}



