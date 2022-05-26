#include <iostream>
#include "questionModel.h"

using namespace std;

/*Constructor*/
questionModel::questionModel(string email, string question, string id){
    this->email = email;
    this->question = question;
    this->id = id;
}

questionModel::questionModel(){
    this->email = "";
    this->question = "";
    this->id = "";
}