#ifndef PRODUCTSERVICE_H
#define PRODUCTSERVICE_H

#include <string>
#include "Database.h"
#include <mysql/mysql.h>

using namespace std;

class productService
{
    public:
    productService ();
    ~productService();
    MYSQL *con;
    void error();
    bool createProduct(string name, string description, string owner, int cost);

};
#endif
