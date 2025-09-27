//
// Created by Sonia Zagrean on 20.05.2025.
//

#include <exception>
#include "BagIterator.h"

#include <stdexcept>

#include "Bag.h"

using namespace std;


BagIterator::BagIterator(const Bag& c): bag(c) {current = bag.head;}

void BagIterator::first() {
    current = bag.head;
}


void BagIterator::next() {
    if (!valid())
        throw std::runtime_error("invalid");
    current = current->next;
}


bool BagIterator::valid() const {
    return current != nullptr;
}


TElem BagIterator::getCurrent() const
{
    if (!valid())
        throw std::runtime_error("invalid");
    return current->data;
}

