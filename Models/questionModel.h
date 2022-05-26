#ifndef questionModel_H
#define questionModel_H

#include <string>
using namespace std;

class questionModel
{
    public:
    questionModel();
    questionModel(string email, string question, string id);
    ~questionModel();
    string email, pregunta, id;


};
#endif