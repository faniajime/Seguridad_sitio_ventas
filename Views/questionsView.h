#ifndef QUESTIONSVIEW_H
#define QUESTIONSVIEW_H
#include "../Service/ParserHandler.h"
#include "HeaderMenuView.h"

using namespace std;

class questionsView {
    public:
        questionsView();
        ~questionsView();  
        bool getResponse();      
        void printPage();
        bool postResponse();
    
    private:
        ParserHandler* parserHandler;
        HeaderMenuView* headerMenuView;

};
#endif