#ifndef USERSERVICE_H
#define USERSERVICE_H

#include <mysql/mysql.h>
#include "Database.h"
#include <string>
#include <vector>
#include "../Models/questionModel.h"
using namespace std;

class QuestionService
{
    public:
    QuestionService();
    ~QuestionService();
    MYSQL *conn;
    bool addQuestion(string email, string question);
    vector<questionModel> getQuestions();

};
#endif
