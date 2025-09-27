//
// Created by Sonia Zagrean on 14.05.2025.
//

#pragma once

using Comparator = bool (*)(int, int);

class SortedSet {
private:
    int* elems;
    int len;
    int capacity;
    Comparator cmp;

    void resize();
    friend class SortedSetIterator;

public:
    explicit SortedSet(Comparator cmp);
    ~SortedSet();

    void add(int elem);
    bool remove(int elem);
    bool search(int elem);
    int getAt(int pos);
    int size();

};

