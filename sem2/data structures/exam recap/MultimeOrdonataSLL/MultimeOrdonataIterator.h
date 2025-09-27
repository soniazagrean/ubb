//
// Created by Sonia Zagrean on 26.05.2025.
//

#pragma once
#include <stdexcept>

#include "MultimeOrdonata.h"

template<typename TElem>
class MultimeOrdonataIterator {
private:
    MultimeOrdonata<TElem>& m;
    Node<TElem>* current;

public:
    explicit MultimeOrdonataIterator(MultimeOrdonata<TElem>& m) : m(m), current(m.head) {}
    ~MultimeOrdonataIterator()=default;
    void first() {
        current = m.head;
    }
    void next() {
        if (!valid())
            throw std::runtime_error("invalid");
        current = current->next;
    }
    bool valid() {
        return current != nullptr;
    }
    TElem getAt() {
        return current->data;
    }
};


