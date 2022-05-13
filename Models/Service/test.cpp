#include "../userModel.h"
#include "UserService.cpp"
#include <iostream>


using namespace std;

int main(){
    UserService* us = new UserService();
    us->createUser("Fabiola", "fejimene", "bla", 888888, "asdasd", "asdasd");

}
