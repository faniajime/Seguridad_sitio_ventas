#ifndef PAYMENTVIEW_H
#define PAYMENTVIEW_H

#include "../Service/ParserHandler.h"
#include "../Service/SessionService.h"
#include "../Service/ProductService.h" 
#include "../Service/CartService.h" 
#include "../Views/HeaderMenuView.h"

using namespace std;

class paymentView{

	public:

	paymentView();
	bool getResponse();
	bool postResponse();
	void printPage();
	void printError();
	void printHead();
	bool checkCardValidity(string card);
	ParserHandler * parserHandler;
    SessionService * sessionHandler;
    ProductService * productHandler;
	HeaderMenuView * headerMenuView;
	SessionService * sessionHandler2;
	CartService * cartService;
	CartService * cartService2;
	

	private:
	int total;
};
#endif
