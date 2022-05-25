#ifndef HEADERMENUVIEW_H
#define HEADERMENUVIEW_H
#include "../Service/SessionService.h"
class HeaderMenuView {
    public:
        HeaderMenuView();
        ~HeaderMenuView();
        void printHeader();
    private:
        SessionService * sessionService;
};
#endif