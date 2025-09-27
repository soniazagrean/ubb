//
// Created by Sonia Zagrean on 14.05.2025.
//
#pragma once

struct ElemPair {
    int value;
    int freq;
};

class Bag {
private:
    ElemPair* elems;  // dynamic allocation
    int capacity;
    int len;

    void resize();
    friend class BagIterator;

public:
    Bag();
    ~Bag();

    void add(int elem);
    bool remove(int elem);
    bool search(int elem);
    int size() const;
    int nrOccurrences(int elem) const;
    int getAt(int pos);

};

