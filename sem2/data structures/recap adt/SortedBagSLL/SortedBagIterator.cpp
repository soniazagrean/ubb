//
// Created by Sonia Zagrean on 20.05.2025.
//

#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>
#include <stdexcept>

using namespace std;

SortedBagIterator::SortedBagIterator(const SortedBag& b) : bag(b) {
    first();
}

TComp SortedBagIterator::getCurrent() {
    if (!valid())
        throw exception();
    return current->data;
}

bool SortedBagIterator::valid() {
    return current != nullptr;
}

void SortedBagIterator::next() {
    if (!valid())
        throw exception();
    current = current->next;
}

void SortedBagIterator::first() {
    current = bag.head;
}