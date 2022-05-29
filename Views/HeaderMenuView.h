#ifndef HEADERMENUVIEW_H
#define HEADERMENUVIEW_H
#include "../Service/SessionService.h"
#include "../Service/CartService.h"
class HeaderMenuView {
    public:
        HeaderMenuView();
        ~HeaderMenuView();
        void printHeader();
    private:
    CartService * cartService;
    SessionService * sessionService;
    string token = "";
};
#endif