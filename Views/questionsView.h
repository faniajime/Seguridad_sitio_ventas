#ifndef QUESTIONSVIEW_H
#define QUESTIONSVIEW_H
#include "../Service/ParserHandler.h"

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

};
#endif