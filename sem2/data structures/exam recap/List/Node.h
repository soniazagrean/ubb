
#pragma once

template <typename TElem>
class IteratedList;

template <typename TElem>
class Iterator;

template <typename TElem>
class Node {
protected:
    TElem data;
    Node<TElem>* next;

    friend class IteratedList<TElem>;
    friend class Iterator<TElem>;

public:
    Node(TElem data, Node<TElem>* next) : data(data), next(next) {}
    ~Node() = default;
};
