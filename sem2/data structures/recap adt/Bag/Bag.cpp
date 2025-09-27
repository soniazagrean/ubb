//
// Created by Sonia Zagrean on 14.05.2025.
//

#include "Bag.h"

#include <stdexcept>

void Bag::resize() {
    if (len == capacity) {
        capacity *= 2;
        ElemPair* newElems = new ElemPair[capacity];
        for (int i = 0; i < len; ++i) {
            newElems[i].value = elems[i].value;
            newElems[i].freq = elems[i].freq;
        }
        delete[] elems;
        elems = newElems;
    }
}

Bag::Bag() {
    capacity = 2;
    elems = new ElemPair[capacity];
    len = 0;
}

Bag::~Bag() {
    delete[] elems;
}

void Bag::add(int elem) {
    if (len == capacity)
        resize();
    for (int i = 0; i < len; ++i)
        if (elems[i].value == elem) {
            elems[i].freq++;
            return;
        }
    elems[len++] = ElemPair{elem, 1};
}

bool Bag::remove(int elem) {
    for (int i = 0; i < len; ++i) {
        if (elems[i].value == elem) {
            elems[i].freq--;
            if (elems[i].freq == 0) {
                for (int j = i; j < len - 1; ++j) {
                    elems[j] = elems[j + 1];
                }
                len--;
            }
            return true;
        }
    }
    return false;
}



bool Bag::search(int elem) {
    for (int i = 0; i < len; ++i)
        if (elems[i].value == elem)
            return true;
    return false;
}

int Bag::size() const {
    return len;
}

int Bag::nrOccurrences(int elem) const {
    for (int i = 0; i < len; ++i)
        if (elems[i].value == elem)
            return elems[i].freq;
    return 0;
}

int Bag::getAt(int pos) {
    if (pos < 0 || pos >= len)
        throw std::runtime_error("invalid position");
    return elems[pos].value;
}
