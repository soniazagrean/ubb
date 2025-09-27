//
// Created by Sonia Zagrean on 26.05.2025.
//

// properties : doesnt have positions, unique elements

#pragma once
#include <stdexcept>

template<typename TElem>
class MultimeOrdonataIterator;

template<typename TElem>
using Comparator = bool(*)(TElem, TElem);


template <typename TElem>
class MultimeOrdonata {
private:
    TElem* elems;
    int capacity;
    int len;

    Comparator<TElem> cmp;
    void resize() {
        TElem* newElems = new TElem[capacity];
        for (int i = 0; i < len; ++i)
            newElems[i] = elems[i];
        delete[] elems;
        elems = newElems;
    }

    friend class MultimeOrdonataIterator<TElem>;

public:
    explicit MultimeOrdonata(const Comparator<TElem>& c): capacity(2), len(0), cmp(c) {
        elems = new TElem[capacity];
    }
    ~MultimeOrdonata() {
        delete[] elems;
    }
    void add(TElem elem) {
        int pos = 0;
        if (search(elem))
            return;
        if (len == capacity)
            resize();
        while (cmp(elem, elems[pos]) && pos < len)
            pos++;
        for (int i = len - 1; i >= pos; --i)
            elems[i + 1] = elems[i];
        len++;
        elems[pos] = elem;

    }
    bool remove(TElem elem) {
        if (!search(elem))
            return false;
        for (int i = 0; i < len; ++i)
            if (elems[i] == elem) {
                for (int j = i; j < len - 1; ++j)
                    elems[j] = elems[j + 1];
                len--;
                return true;
            }
        return false;
    }
    bool search(TElem elem) {
        for (int i = 0; i < len; ++i)
            if (elems[i] == elem)
                return true;
        return false;
    }
    TElem getAt(int pos) {
        if (pos < 0 || pos >= len)
            throw std::runtime_error("invalid");
        return elems[pos];
    }
    int size() {
        return len;
    }

};
