#ifndef UI_H
#define UI_H
#include "Controller.h"

class UI {
private:
    Controller& service;

    void addProdusDulce();
    void addProdusSarat();
    void showAllProducts();

public:
    explicit UI(Controller& s) : service(s) {}
    void run();
};

#endif //UI_H
