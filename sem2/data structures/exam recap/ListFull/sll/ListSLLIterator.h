#pragma once
#include "ListSLL.h"
#include <stdexcept>

template<typename TElem>
class ListSLLIterator {
private:
    typename ListSLL<TElem>::Node* current;

public:
    explicit ListSLLIterator(const ListSLL<TElem>& list)
        : current(list.head) {}

    void first() {
    }

    void next() {
        if (!valid())
            throw std::out_of_range("Iterator is not valid.");
        current = current->next;
    }

    bool valid() const {
        return current != nullptr;
    }

    TElem getCurrent() const {
        if (!valid())
            throw std::out_of_range("Iterator is not valid.");
        return current->data;
    }
};
