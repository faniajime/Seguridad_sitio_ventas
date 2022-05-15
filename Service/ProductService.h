#ifndef PRODUCTSERVICE_H
#define PRODUCTSERVICE_H

#include <string>
#include "Database.h"
#include <mysql/mysql.h>
#include "productModel.h" 

using namespace std;

class productService
{
    public:
    productService ();
    ~productService();
    MYSQL *con;
    void error();
    bool createProduct(string name, string description, string owner, int cost);
    productModel getProductById(int id);
    bool updateProduct(int id,string name, string description, string owner, int cost);
    bool deleteProduct(int id);

};
#endif
