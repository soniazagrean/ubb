//
// Created by Sonia Zagrean on 21.05.2025.
//

#pragma once

typedef int TElem;

class Node {
private:
    TElem data;
    Node* next;

    friend class Set;
    friend class SetIterator;

public:
    Node(TElem data, Node* next): data(data), next(next) {}
    ~Node()=default;
};
