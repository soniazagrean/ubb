//
// Created by Sonia Zagrean on 21.05.2025.
//

#pragma once

typedef int TElem;
typedef int TComp;
const int NULL_TELEM = -111111;

class Node {
private:
    TElem data;
    Node* next;

    friend class SortedSet;
    friend class SortedSetIterator;

public:
    Node(TElem data, Node* next): data(data), next(next) {}
    ~Node()=default;
};
