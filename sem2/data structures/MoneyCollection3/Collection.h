#ifndef COLLECTION_H
#define COLLECTION_H

#include <iostream>

template <typename TElem>
struct pairT {
    TElem elem;
    int freq;
};

template <typename TElem>
class Collection {
private:
    pairT<TElem>* elems;
    int len;
    int capacity;
    void resize();

public:
    Collection();
    ~Collection();

    void loadBills();
    void add(TElem elem);
    bool remove(TElem elem, int freq);
    bool search(TElem elem) const;
    int size() const;
    int nrOccurrences(TElem elem) const;
    TElem getAt(int position) const;
    void printCollection();
};

#include "Collection.tpp"

#endif
