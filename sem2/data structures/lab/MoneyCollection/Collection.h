//
// Created by sonia on 10.03.2025.
//

#ifndef COLLECTION_H
#define COLLECTION_H

#include <iostream>

typedef int TElem;

struct pairT{
    TElem elem;
    int freq;
};

class Collection {
private:
    // elems dynamic vector
    pairT* elems; // elements
    int len;        // dimension
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
    int getAtElem(int position) const;
    int getAtFreq(int position) const;
    void printCollection();
};



#endif //COLLECTION_H
