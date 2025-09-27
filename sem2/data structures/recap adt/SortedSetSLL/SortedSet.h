//
// Created by Sonia Zagrean on 21.05.2025.
//

#pragma once
#include "Node.h"

using Relation = bool (*)(TElem, TElem);
class SortedSetIterator;

class SortedSet {
private:
    Node* head;
    int len;
    Relation cmp;

    friend class SortedSetIterator;

public:
    explicit SortedSet(Relation r) : cmp(r), head(nullptr), len(0) {}
    bool add(TElem elem);
    bool remove(TElem elem);
    bool search(TElem elem);
    int size();
    bool isEmpty();
    int nrOccurrences(TElem elem);
    SortedSetIterator iterator();
    ~SortedSet();
};
