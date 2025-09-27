//
// Created by Sonia Zagrean on 26.05.2025.
//

#pragma once
#include "MultimeOrdonata.h"

template <typename TElem>
class MultimeOrdonataIterator {
private:
    MultimeOrdonata<TElem>& m;
    int current;

public:
    explicit MultimeOrdonataIterator(MultimeOrdonata<TElem>& m) : m(m), current(0) {}
    ~MultimeOrdonataIterator()=default;
    void first() {
        current = 0;
    }
    void next() {
        if (!valid())
            throw std::runtime_error("invalid");
        current++;
    }
    bool valid() {
        return current >= 0 && current < m.size();
    }
    TElem getAt() {
        if (!valid())
            throw std::runtime_error("invalid");
        return m.getAt(current);
    }
};


