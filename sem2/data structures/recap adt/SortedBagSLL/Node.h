//
// Created by Sonia Zagrean on 20.05.2025.
//

#ifndef NODE_H
#define NODE_H

typedef int TElem;

class Node {
private:
    TElem data;
    Node* next;

    friend class SortedBag;
    friend class SortedBagIterator;

public:
    Node(TElem data, Node* next) : data(data), next(next) {}
    ~Node()=default;
};



#endif //NODE_H
