//
// Created by Sonia Zagrean on 21.05.2025.
//

#pragma once
#include "SortedSet.h"

class SortedSetIterator {
private:
    const SortedSet& set;
    Node* current;

    friend class SortedSet;

public:
    explicit SortedSetIterator(const SortedSet& m): set(m) {current = set.head;}
    void first();
    void next();
    bool valid();
    TElem getCurrent();
};
