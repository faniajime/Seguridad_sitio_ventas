#ifndef PRODUCTSVIEW_H
#define PRODUCTSVIEW_H

#include "../Service/ProductService.h"
#include "../Models/productModel.h"


using namespace std;

class productsView {
    public:
        productsView();
        ~productsView();        
        void printPage();
    
    private:
        ProductService * productHandler;
        productModel* product;
        list<productModel> productsList;
};
#endif