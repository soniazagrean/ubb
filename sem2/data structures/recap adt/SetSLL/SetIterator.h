//
// Created by Sonia Zagrean on 21.05.2025.
//

#pragma once

#include "Set.h"

class SetIterator {
private:
    const Set& set;
    Node* current;

public:
    explicit SetIterator(const Set& set): set(set){ current = set.head;}
    void first();
    void next();
    bool valid();
    TElem getCurrent();
    ~SetIterator()=default;
};
