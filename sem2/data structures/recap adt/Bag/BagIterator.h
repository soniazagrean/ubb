//
// Created by Sonia Zagrean on 14.05.2025.
//

#pragma once

#include "Bag.h"

class BagIterator {
private:
    Bag& bag;
    int current;
    int freqCounter;

public:
    explicit BagIterator(Bag& bag);
    void first();
    bool valid();
    void next();
    int getAt();

};

