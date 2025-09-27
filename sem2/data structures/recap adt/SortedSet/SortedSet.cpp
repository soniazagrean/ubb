//
// Created by Sonia Zagrean on 14.05.2025.
//

#include "SortedSet.h"

#include <stdexcept>

void SortedSet::resize() {
    capacity *= 2;
    int* newElems = new int[capacity];
    for (int i = 0; i < len; ++i)
        newElems[i] = elems[i];
    delete[] elems;
    elems = newElems;
}

SortedSet::SortedSet(Comparator cmp) : cmp(cmp) {
    len = 0;
    capacity = 2;
    elems = new int[capacity];
}

SortedSet::~SortedSet() {
    delete[] elems;
}

void SortedSet::add(int elem) {
    int pos = 0;
    if (search(elem))
        return;
    if (len == capacity)
        resize();
    while (pos < len && cmp(elem, elems[pos]))
        pos++;
    for (int i = len; i > pos; --i)
        elems[i] = elems[i - 1];
    elems[pos] = elem;
    len++;
}

bool SortedSet::remove(int elem) {
    for (int i = 0; i < len; ++i)
        if (elems[i] == elem) {
            for (int j = i; j < len - 1; ++j)
                elems[j] = elems[j + 1];
            len--;
            return true;
        }
    return false;
}

bool SortedSet::search(int elem) {
    for (int i = 0; i < len; ++i)
        if (elems[i] == elem)
            return true;
    return false;
}

int SortedSet::getAt(int pos) {
    if (pos < 0 || pos >= len)
        throw std::runtime_error("invalid position");
    return elems[pos];
}

int SortedSet::size() {
    return len;
}
