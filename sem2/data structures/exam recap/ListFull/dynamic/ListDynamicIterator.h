//
// Created by Sonia Zagrean on 30.05.2025.
//

#pragma once
#include <stdexcept>

#include "ListDynamic.h"


template <typename TElem>
class ListDynamicIterator {
private:
    ListDynamic<TElem>& l;
    int current;

public:
    explicit ListDynamicIterator(ListDynamic<TElem> &l) : l(l), current(0) {}
    ~ListDynamicIterator()=default;
    void first() {
        if (!valid())
            throw std::out_of_range("Invalid index");
        current = 0;
    }
    void next() {
        if (!valid())
            throw std::out_of_range("Invalid index");
        ++current;
    }
    bool valid() {
        return current >= 0 && current < l.size();
    }
    TElem getAt() {
        if (!valid())
            throw std::out_of_range("Invalid index");
        return l.getAt(current);
    }
};
