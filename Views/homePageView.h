#ifndef HOMEPAGEVIEW_H
#define HOMEPAGEVIEW_H

#include "../Service/ParserHandler.h"
#include "../Service/UserService.h"
//#include "../Service/SessionService.h"
#include "HeaderMenuView.h"
using namespace std;

class homePageView {
    public:
        homePageView();
        ~homePageView();
        bool getResponse();
        bool postResponse();
        void printPage();
    private:
        int refreshCount;
        ParserHandler * parserHandler;
        UserService * userHandler;
        HeaderMenuView * headerMenuView;
        SessionService * sessionService;
        SessionService * sessionService2;
};
#endif