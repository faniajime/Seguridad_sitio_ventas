#ifndef LOGINPAGEVIEW_H
#define LOGINPAGEVIEW_H

#include "../Models/Service/ParserHandler.h"
#include "../Models/Service/UserService.h"
using namespace std;

class loginPageView {
    public:
        loginPageView();
        ~loginPageView();

        bool getResponse();
        bool postResponse();
        void printPage();
    
    private:
        ParserHandler * parserHandler;
        UserService * userHandler;


};
#endif