#include "SortedBagIterator.h"
#include <exception>
#include <stdexcept>
#include <vector>
#include <algorithm>

SortedBagIterator::SortedBagIterator(const SortedBag& b) : bag(b) {
    first();
}

void SortedBagIterator::collectElements(Node* node, std::vector<std::pair<TComp, int>>& elements) {
    if (node == nullptr) return;

    collectElements(node->left, elements);
    elements.push_back({node->data, node->freq});
    collectElements(node->right, elements);
}

void SortedBagIterator::first() {
    elements.clear();
    currentIndex = 0;
    currentFreqIndex = 0;

    collectElements(bag.head, elements);
    std::sort(elements.begin(), elements.end(),
        [this](const std::pair<TComp, int>& a, const std::pair<TComp, int>& b) {
            return bag.r(a.first, b.first) && a.first != b.first;
        });
}

bool SortedBagIterator::valid() {
    return currentIndex < elements.size();
}

TComp SortedBagIterator::getCurrent() {
    if (!valid())
        throw std::runtime_error("Iterator is not valid");
    return elements[currentIndex].first;
}

void SortedBagIterator::next() {
    if (!valid())
        throw std::runtime_error("Iterator is not valid");

    currentFreqIndex++;
    if (currentFreqIndex >= elements[currentIndex].second) {
        currentIndex++;
        currentFreqIndex = 0;
    }
}