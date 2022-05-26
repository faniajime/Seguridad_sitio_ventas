#ifndef QUESTIONSVIEW_H
#define QUESTIONSVIEW_H
#include "../Service/ParserHandler.h"
#include "../Service/QuestionsService.h"
#include "HeaderMenuView.h"
#include "../Models/questionModel.h"
#include<list>

using namespace std;

class questionsView {
    public:
        questionsView();
        ~questionsView();  
        bool getResponse();      
        void printPage();
        bool postResponse();
    
    private:
        list<questionModel> questions;
        ParserHandler* parserHandler;
        HeaderMenuView* headerMenuView;
        QuestionService* questionService;
        QuestionService* questionService2;
        QuestionService* questionService3;

};
#endif