//
// Created by Sonia Zagrean on 20.05.2025.
//

#pragma once
#include "SortedBag.h"

class SortedBag;

class SortedBagIterator
{
    friend class SortedBag;

private:
    const SortedBag& bag;
    Node* current;

public:
    explicit SortedBagIterator(const SortedBag& b);
    TComp getCurrent();
    bool valid();
    void next();
    void first();
};


