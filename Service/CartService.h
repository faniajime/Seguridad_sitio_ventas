#ifndef CARTSERVICE_H
#define CARTSERVICE_H

#include <string>
#include <list>
#include "Database.h"
#include <mysql/mysql.h>
#include "../Models/productModel.h" 

using namespace std;

class CartService
{
    public:
    list<productModel> cart;
    CartService ();
    ~CartService();
    MYSQL *conn;
    bool addtoCart(string usuario, string productID);
    list<productModel> getCart(string usuario);
    bool buyCart(string usuario);
    bool removeProduct(string usuario, string productID);
    bool deleteCart(string usuario);
    int getTotal(string usuario);


};
#endif
