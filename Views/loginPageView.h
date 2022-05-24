#ifndef LOGINPAGEVIEW_H
#define LOGINPAGEVIEW_H

#include "../Service/ParserHandler.h"
//#include "../Service/UserService.h"
using namespace std;

class loginPageView {
    public:
        loginPageView();
        ~loginPageView();
        void parseQuery(char*, int, ParserHandler*); // se deberia quitar tal vez de aqui
        bool getResponse();
        bool postResponse();
        void printPage();
    
    private:
        ParserHandler * parserHandler;
        //UserService * userHandler;


};
#endif