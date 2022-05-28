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
	void totalError();
	void printHead();
	void printSuccess();
	bool checkCardValidity(string card);
	ParserHandler * parserHandler;
    SessionService * sessionHandler;
    ProductService * productHandler;
	HeaderMenuView * headerMenuView;
	SessionService * sessionHandler2;
	CartService * cartService;
	CartService * cartService2;
	CartService * cartService3;
	

	private:
	int total;
	list<productModel> carrito;
};
#endif
