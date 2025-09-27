//
// Created by Sonia Zagrean on 29.05.2025.
//

#pragma once

template <typename TElem>
class StackDynamic {
private:
    TElem* elems;
    int capacity;
    int len;

    void resize() {
        capacity *= 2;
        TElem* newElems = new TElem[capacity];
        for (int i = 0; i < len; ++i)
            newElems[i] = elems[i];
        delete[] elems;
        elems = newElems;
    }

public:
    StackDynamic() : capacity(2), len(0) {
        elems = new TElem[capacity];
    }
    ~StackDynamic() {
        delete[] elems;
        elems = nullptr;
    }

    void push(TElem elem);
    TElem pop();
    TElem top();
    bool isEmpty();
};



#include "StackDynamic.tpp"

