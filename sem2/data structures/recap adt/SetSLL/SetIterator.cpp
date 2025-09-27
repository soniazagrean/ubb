//
// Created by Sonia Zagrean on 21.05.2025.
//

#include "SetIterator.h"

#include <exception>

void SetIterator::first() {
    current = set.head;
}

void SetIterator::next() {
    if (!valid())
        throw std::exception();
    current = current->next;
}

bool SetIterator::valid() {
    return current != nullptr;
}

TElem SetIterator::getCurrent() {
    if (!valid())
        throw std::exception();
    return current->data;
}
