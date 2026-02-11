//
// Created by Sonia Zagrean on 19.05.2025.
//

#ifndef UI_H
#define UI_H
#include "Service.h"


class UI {
private:
    Service service;
    void addUi();
    void removeUi();
    void updateUi();
    void buyUi();
    void getUi();

public:
    explicit UI(Service& service) : service(service) {}
    void run();
};



#endif //UI_H
