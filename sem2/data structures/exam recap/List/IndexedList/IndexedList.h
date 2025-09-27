//
// Created by Sonia Zagrean on 26.05.2025.
//


#pragma once
#include <stdexcept>

#include "IndexedListIterator.h"

template <typename TElem>
class IndexedList {
private:
    TElem* elems;
    int capacity;
    int length;

    void resize() {
        capacity *= 2;
        TElem* newElems = new TElem[capacity];
        for (int i = 0; i < length; ++i)
            newElems[i] = elems[i];
        delete[] elems;
        elems = newElems;
    }

public:
    IndexedList() : capacity(10), length(0) {
        elems = new TElem[capacity];
    }

    ~IndexedList() {
        delete[] elems;
    }

    TElem& at(int index) {
        if (index < 0 || index >= length)
            throw std::out_of_range("index out of bounds");
        return elems[index];
    }

    TElem& operator[](int index) {
        return at(index);
    }

    void insert(int index, const TElem& value) {
        if (index < 0 || index > length)
            throw std::out_of_range("index out of bounds");

        if (length == capacity)
            resize();

        for (int i = length; i > index; --i)
            elems[i] = elems[i - 1];

        elems[index] = value;
        length++;
    }

    void remove(int index) {
        if (index < 0 || index >= length)
            throw std::out_of_range("index out of bounds");

        for (int i = index; i < length - 1; ++i)
            elems[i] = elems[i + 1];

        length--;
    }

    void push_back(const TElem& value) {
        insert(length, value);
    }

    int size() const {
        return length;
    }

    bool empty() const {
        return length == 0;
    }

    IndexedIterator<TElem> begin() const { return Iterator(elems); }
    IndexedIterator<TElem> end() const { return Iterator(elems + length); }
};


