//
// Created by Sonia Zagrean on 14.05.2025.
//

#pragma once
#include "SortedBagIterator.h"

using Comparator = bool (*)(int, int);

struct ElemPair {
    int value;
    int freq;
};

class SortedBag {
private:
    ElemPair* elems;
    int len;
    int capacity;
    Comparator cmp;

    void resize();

public:
    SortedBag(Comparator cmp);
    ~SortedBag();

    void add(int elem);
    bool remove(int elem);
    bool search(int elem);
    int size();
    int getAt(int pos);
    int nrOccurrences(int elem);
    SortedBagIterator iterator();
};
