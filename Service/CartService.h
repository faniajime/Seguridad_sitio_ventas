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
    bool isInCart(string productID);
    bool addtoCart(string usuario, string productID); // agrega producto al carrito
    list<productModel> getCart(string usuario); // retorna lista de productos que se agregaron al carrito
    bool buyCart(string usuario); // borra todos los productos del carrito + tabla de productos
    bool removeProduct(string usuario, string productID); //quita un producto en especifico del carrito
    bool deleteCart(string usuario); // borra todos los productos en el carrito
    int getTotal(string usuario); // retorna total precio de productos en carrito


};
#endif
