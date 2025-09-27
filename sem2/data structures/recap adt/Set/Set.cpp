#include "Set.h"
#include "SetITerator.h"

void Set::resize() {
    capacity *= 2;
    int* newElems = new int[capacity];
    for (int i = 0; i < len; ++i)
        newElems[i] = elems[i];
    delete[] elems;
    elems = newElems;
}

Set::Set() {
    capacity = 2;
    len = 0;
    elems = new int[capacity];
}


bool Set::add(TElem e) {
    if (search(e))
        return false;
    if (len == capacity)
        resize();
    elems[len++] = e;
    return true;
}

int Set::get(const int pos) const {
    return elems[pos];
}


bool Set::remove(TElem e) {
    for (int i = 0; i < len; ++i)
        if (elems[i] == e) {
            for (int j = i; j < len - 1; ++j)
                elems[j] = elems[j + 1];
            len--;
            return true;
        }
    return false;
}

bool Set::search(const TElem elem) const {
    for (int i = 0; i < len; ++i)
        if (elems[i] == elem)
            return true;
    return false;
}


int Set::size() const {
    return len;
}


bool Set::isEmpty() const {
    return this->size() == 0;
}


Set::~Set() {
    delete[] elems;
}


SetIterator Set::iterator() const {
    return SetIterator(*this);
}


