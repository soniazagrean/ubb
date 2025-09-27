//
// Created by Sonia Zagrean on 26.05.2025.
//

#pragma once

template<typename TElem>
class Iterator;

template<typename TElem>
class Node;

template <typename TElem>
class IteratedList {
private:
    Node<TElem>* head;
    Node<TElem>* tail;
    int count;
    Node<TElem>* getNode(int index) const;

    friend class Iterator<TElem>;

public:
    IteratedList();
    ~IteratedList();

    Iterator<TElem> begin() const { return Iterator(head); }
    Iterator<TElem> end() const { return Iterator<TElem>(nullptr); }


    void push_back(TElem elem);
    void push_front(TElem elem);
    void pop_back();
    void pop_front();
    TElem& front();
    TElem& back();
    bool empty();
    int size();
    TElem& at(int index);
    void insert(int index, TElem elem);
    void erase(int index);
    void clear();
};

#include "IteratedList.tpp"



