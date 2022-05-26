#ifndef PRODUCTSERVICE_H
#define PRODUCTSERVICE_H

#include <string>
#include <list>
#include "Database.h"
#include <mysql/mysql.h>
#include "../Models/productModel.h" 

using namespace std;

class ProductService
{
    public:
    list<productModel> productsList;
    ProductService ();
    ~ProductService();
    MYSQL *conn;
    void error();
    bool createProduct(string name, string description, string owner, int cost);
    productModel getProductById(int id);
    list<productModel> getProducts();
    bool updateProduct(int id,string name, string description, string owner, int cost);
    bool deleteProduct(int id);
    list<productModel> searchProductByKey(string keyword); //Gets a list of productos containiing keyword

};
#endif
