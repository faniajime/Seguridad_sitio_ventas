#ifndef USUARIO_H
#define USUARIO_H

using namespace std;

class loginPageView {
    public:
        loginPageView();
        ~loginPageView();
        bool responseGET();
        bool responsePOST();
        void printPage();


};
#endif