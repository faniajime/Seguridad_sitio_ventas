#ifndef PRODUCTSVIEW_H
#define PRODUCTSVIEW_H

#include "../Service/ProductService.h"
#include "../Models/productModel.h"
#include "../Service/ParserHandler.h"
#include "HeaderMenuView.h"
#include "../Service/SessionService.h"


using namespace std;

class productsView {
    public:
        productsView();
        ~productsView();        
        void printPage();
        bool getResponse();
        bool postResponse();
    
    private:
        ProductService * productHandler;
        ProductService * productHandler2;
        productModel* product;
        ParserHandler * parserHandler;
        list<productModel> productsList;
        HeaderMenuView * headerView;
        SessionService * sessionService;
        bool isLoggedIn = false;
};  
#endif