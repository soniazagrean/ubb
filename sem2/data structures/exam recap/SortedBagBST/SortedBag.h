#pragma once
#include "Node.h"



typedef int TComp;
typedef TComp TElem;
typedef bool(*Relation)(TComp, TComp);
#define NULL_TCOMP -11111;

class SortedBagIterator;

class SortedBag {
    friend class SortedBagIterator;

private:
    Node* head;
    int len;
    Relation r;

public:
    explicit SortedBag(Relation r);
    void add(TComp e);
    bool remove(TComp e);
    bool search(TComp e) const;
    int nrOccurrences(TComp e) const;
    int size() const;
    SortedBagIterator iterator() const;
    bool isEmpty() const;
    ~SortedBag();
};