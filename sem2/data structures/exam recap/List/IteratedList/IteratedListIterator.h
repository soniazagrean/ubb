//
// Created by Sonia Zagrean on 26.05.2025.
//

#pragma once
#include "../Node.h"

template <typename TElem>
class Iterator {
private:
    Node<TElem>* current;

public:
    explicit Iterator(Node<TElem>* node) : current(node) {}

    TElem& operator*() const { return current->data; }

    Iterator& operator++() {
        if (current) current = current->next;
        return *this;
    }

    bool operator!=(const Iterator& other) const {
        return current != other.current;
    }
};


