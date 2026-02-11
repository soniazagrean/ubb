//
// Created by Sonia Zagrean on 15.05.2025.
//

#ifndef UI_H
#define UI_H
#include "Controller.h"


class UI {
private:
    Controller& c;
    void addProdusDulce();
    void addProdusSarat();
    void showAll();

public:
    void run();
};



#endif //UI_H
