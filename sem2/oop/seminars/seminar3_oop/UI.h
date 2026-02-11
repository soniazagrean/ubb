//
// Created by Sonia Zagrean on 03.04.2025.
//

#ifndef UI_H
#define UI_H

#include "Service.h"

class UI {
private:
    Service& service;
public:
    UI(Service& service): service(service) {};
    ~UI();
    void showAll() const;
};



#endif //UI_H
