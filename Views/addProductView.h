#ifndef ADDPRODUCTVIEW_H
#define ADDPRODUCTVIEW__H
#include "../Service/ParserHandler.h"
#include "../Service/SessionService.h"
#include "../Service/ProductService.h" 

using namespace std;

class addProductView{

	public:

	addProductView();
	~addProductView();
        bool getResponse();
        bool postResponse();
	void printPage();

	private:
	ParserHandler * parserHandler;
        SessionService * sessionHandler;
        ProductService * productHandler;

};
#endif
