//
// Created by Sonia Zagrean on 14.05.2025.
//

#pragma once
#include "SortedSet.h"

class SortedSetIterator {
private:
    SortedSet& s;
    int current;

public:
    explicit SortedSetIterator(SortedSet& s);
    ~SortedSetIterator();
    void first();
    void next();
    bool valid() const;
    int getAt();
};

