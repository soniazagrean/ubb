//
// Created by Sonia Zagrean on 13.05.2025.
//

#pragma once

template <typename TElem>
class Bag;

template <typename TElem>
class SortedSet;

template <typename TElem>
class Node {
private:
    TElem data;
    Node<TElem>* next;

public:
    Node(TElem data, Node<TElem>* next) : data(data), next(next) {}
    ~Node() = default;

    template <typename T> friend class Bag;
    template <typename T> friend class SortedSet;

};
