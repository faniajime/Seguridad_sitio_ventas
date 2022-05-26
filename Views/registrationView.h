#ifndef REGISTRATIONVIEW_H
#define REGISTRATION_H

#include "../Service/ParserHandler.h"
#include "../Service/UserService.h"
#include "HeaderMenuView.h"
using namespace std;

class registrationView {
    public:
        registrationView();
        ~registrationView();
        bool getResponse();
        bool postResponse();
        void printPage();
    private:
        ParserHandler * parserHandler;
        UserService * userHandler;
        UserService * userHandler2;
        UserService * userHandler3;
        HeaderMenuView * headerMenuView;

};
#endif