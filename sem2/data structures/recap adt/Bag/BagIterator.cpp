//
// Created by Sonia Zagrean on 14.05.2025.
//

#include "BagIterator.h"

#include <stdexcept>

BagIterator::BagIterator(Bag& bag) : bag(bag), current(0), freqCounter(0) {}

void BagIterator::first() {
    current = 0;
    freqCounter = 0;
}

bool BagIterator::valid() {
    return current < bag.len;
}

void BagIterator::next() {
    if (!valid())
        throw std::runtime_error("out of range");

    freqCounter++;
    if (freqCounter >= bag.elems[current].freq) {
        current++;
        freqCounter = 0;
    }
}

int BagIterator::getAt() {
    if (!valid())
        throw std::runtime_error("out of range");
    return bag.elems[current].value;
}

