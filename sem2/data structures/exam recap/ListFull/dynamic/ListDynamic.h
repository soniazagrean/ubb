//
// Created by Sonia Zagrean on 30.05.2025.
//

#pragma once
#include <stdexcept>


template <typename TElem>
class ListDynamic {
private:
    TElem* elems;
    int len;
    int capacity;

    void resize() {
        capacity *= 2;
        TElem* newElems = new TElem[capacity];
        for (int i = 0; i < len; ++i)
            newElems[i] = elems[i];
        delete[] elems;
        elems = newElems;
    }

public:
    ListDynamic(): len(0), capacity(2) {
        elems = new TElem[capacity];
    }
    ~ListDynamic() {
        delete[] elems;
    }
    void push_front(TElem elem) {
        if (len == capacity)
            resize();
        for (int i = len - 1; i >= 0; --i)
            elems[i + 1] = elems[i];
        len++;
        elems[0] = elem;
    }
    void push_back(TElem elem) {
        if (len == capacity)
            resize();
        elems[len++] = elem;
    }
    TElem pop_front() {
        TElem elem = elems[0];
        for (int i = 0; i < len - 1; ++i)
            elems[i] = elems[i + 1];
        len--;
        return elem;
    }
    TElem pop_back() {
        return elems[--len];
    }
    void removeIndex(int index) {
        if (index < 0 || index >= len)
            return;
        for (int i = index; i < len - 1; ++i)
            elems[i] = elems[i + 1];
        len--;
    }
    bool isEmpty() const {
        return len == 0;
    }
    int size() const {
        return len;
    }
    TElem getAt(int index) {
        if (index < 0 || index >= len)
            throw std::out_of_range("Invalid index");
        return elems[index];
    }
    bool search(TElem elem) {
        for (int i = 0; i < len; ++i)
            if (elems[i] == elem)
                return true;
        return false;
    }
    int nrOccurrences(TElem elem) {
        int count = 0;
        for (int i = 0; i < len; ++i)
            if (elems[i] == elem)
                count++;
        return count;
    }
    void setAt(int index, TElem elem) {
        if (index < 0 || index >= len)
            throw std::out_of_range("Invalid index");
        elems[index] = elem;
    }
};

