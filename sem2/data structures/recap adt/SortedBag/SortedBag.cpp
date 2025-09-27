//
// Created by Sonia Zagrean on 14.05.2025.
//

#include "SortedBag.h"

#include <stdexcept>

void SortedBag::resize() {
    capacity *= 2;
    ElemPair* newElems = new ElemPair[capacity];
    for (int i = 0; i < len; ++i)
        newElems[i] = elems[i];
    delete[] elems;
    elems = newElems;
}

SortedBag::SortedBag(Comparator cmp) : cmp(cmp) {
    capacity = 2;
    elems = new ElemPair[capacity];
    len = 0;
}


SortedBag::~SortedBag() {
    delete[] elems;
}

void SortedBag::add(int elem) {
    for (int i = 0; i < len; ++i)
        if (elems[i].value == elem) {
            elems[i].freq++;
            return;
        }
    if (len == capacity)
        resize();

    int pos = 0;
    while (pos < len && cmp(elems[pos].value, elem))
        pos++;

    for (int i = len; i > pos; --i)
        elems[i] = elems[i - 1];

    elems[pos].value = elem;
    elems[pos].freq = 1;
    len++;

}

bool SortedBag::remove(int elem) {
    for (int i = 0; i < len; ++i) {
        if (elems[i].value == elem) {
            if (elems[i].freq > 1)
                elems[i].freq--;
            else {
                for (int j = i; j < len - 1; ++j)
                    elems[j] = elems[j + 1];
                len--;
            }
            return true;
        }
    }
    return false;
}

bool SortedBag::search(int elem) {
    for (int i = 0; i < len; ++i)
        if (elems[i].value == elem)
            return true;
    return false;
}

int SortedBag::size() {
    int total = 0;
    for (int i = 0; i < len; ++i)
        total += elems[i].freq;
    return total;
}

int SortedBag::getAt(int pos) {
    if (pos < 0 || pos >= len)
        throw std::runtime_error("invalid position");
    return elems[pos].value;
}

int SortedBag::nrOccurrences(int elem) {
    for (int i = 0; i < len; ++i)
        if (elems[i].value == elem)
            return elems[i].freq;
    return 0;
}

SortedBagIterator SortedBag::iterator() {
}
