#ifndef PRODUCTSVIEW_H
#define PRODUCTSVIEW_H

#include "../Service/ProductService.h"
#include "../Models/productModel.h"
#include "../Service/ParserHandler.h"
#include "HeaderMenuView.h"
#include "../Service/SessionService.h"
#include "../Service/CartService.h"
using namespace std;
#include <vector>

class productsView {
    public:
        productsView();
        ~productsView();        
        void printPage();
        bool getResponse();
        bool postResponse();
        void addProduct(string,string);
    
    private:
        ProductService * productHandler;
        ProductService * productHandler2;
        productModel* product;
        ParserHandler * parserHandler;
        list<productModel> productsList;
        list<productModel> cartList;
        HeaderMenuView * headerView;
        SessionService * sessionService;
        SessionService * sessionService2;
        CartService * cartService;
        CartService * cartService2;
        bool isLoggedIn = false;
        bool isNotAdded = true;
        bool isAlreadyAdded(int id);
        string username = "";
        string token;
};  
#endif