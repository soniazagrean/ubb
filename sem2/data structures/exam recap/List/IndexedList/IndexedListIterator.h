//
// Created by Sonia Zagrean on 26.05.2025.
//

#pragma once

template <typename TElem>
class IndexedIterator {
private:
    TElem* ptr;
public:
    explicit IndexedIterator(TElem* p) : ptr(p) {}

    TElem& operator*() const { return *ptr; }

    IndexedIterator& operator++() {
        ++ptr;
        return *this;
    }

    bool operator!=(const IndexedIterator& other) const {
        return ptr != other.ptr;
    }
};
