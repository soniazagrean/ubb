//
// Created by Sonia Zagrean on 14.05.2025.
//

#include "SortedSetIterator.h"

#include <stdexcept>

SortedSetIterator::SortedSetIterator(SortedSet& s) : s(s), current(0) {
}

SortedSetIterator::~SortedSetIterator() = default;

void SortedSetIterator::first() {
    current = 0;
}

void SortedSetIterator::next() {
    if (!valid())
        return;
    current++;
}

bool SortedSetIterator::valid() const {
    return current >= 0 && current < s.size();
}


int SortedSetIterator::getAt() {
    return s.getAt(current);
}
