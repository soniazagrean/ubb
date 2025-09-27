#pragma once
#include "SortedBag.h"
#include <vector>

class SortedBag;

class SortedBagIterator {
    friend class SortedBag;

private:
    const SortedBag& bag;
    std::vector<std::pair<TComp, int>> elements;  // (value, frequency) pairs
    size_t currentIndex;
    int currentFreqIndex;  // current position within the frequency count

    SortedBagIterator(const SortedBag& b);
    void collectElements(Node* node, std::vector<std::pair<TComp, int>>& elements);

public:
    TComp getCurrent();
    bool valid();
    void next();
    void first();
};