//
// Created by Sonia Zagrean on 21.05.2025.
//

#pragma once
#include "Node.h"

class SetIterator;

class Set {
private:
    Node* head;
    int len;

    friend class SetIterator;

public:
    Set();
    bool add(TElem elem);
    bool remove(TElem elem);
    bool search(TElem elem);
    int size();
    bool isEmpty();
    int nrOccurrences(TElem elem);
    SetIterator iterator();
    ~Set();

};
