//
// Created by Sonia Zagrean on 21.05.2025.
//

#include "SortedSetIterator.h"

#include <exception>

void SortedSetIterator::first() {
    current = set.head;
}

void SortedSetIterator::next() {
    if (!valid())
        throw std::exception();
    current = current->next;
}

bool SortedSetIterator::valid() {
    return current != nullptr;
}

TElem SortedSetIterator::getCurrent() {
    if (!valid())
        throw std::exception();
    return current->data;
}
