#include "Collection.h"
#include <fstream>


void Collection::resize() {
    this -> capacity *= 2;
    pairT* temp = new pairT[this->capacity];
    for (int i = 0; i < this->len; i++)
        temp[i] = this->elems[i];
    delete[] this -> elems;
    this -> elems = temp;
}

Collection::Collection() {
    this->len = 0;
    this->capacity = 5;
    this->elems = new pairT[this->capacity];
}

Collection::~Collection() {
    delete[] elems;
}

void Collection::loadBills() {
    this->capacity = 5;
    this->len = 5;
    delete[] this->elems;
    this->elems = new pairT[this->capacity]{{2, 8},
                                            {5, 2},
                                            {10, 4},
                                        {25, 2},
                                        {4, 2}};
}

void Collection::add(TElem elem) {
    for (int i = 0; i < this->len; ++i)
        if (elem == elems[i].elem) {
            elems[i].freq++;
            return;
        }
    if (capacity == this->len)
        resize();
    elems[len] = pairT{elem, 1};
    this->len++;

}

bool Collection::remove(TElem elem, int freq) {
    for (int i = 0; i < this->len; i++) {
        if (elems[i].elem == elem) {
            if (freq > elems[i].freq)
                return false;

            elems[i].freq -= freq;

            if (elems[i].freq == 0) {
                for (int j = i + 1; j < this->len; j++) {
                    elems[j - 1] = elems[j];
                }
                len--;
            }
            return true;
        }
    }
    return false;
}

bool Collection::search(TElem elem) const {
    for (int i = 0; i < this->len; i++)
        if (elem == elems[i].elem)
            return true;
    return false;
}

int Collection::size() const {
    return len;
}

int Collection::nrOccurrences(TElem elem) const {
    for (int i = 0; i < len; i++)
        if (elem == elems[i].elem)
            return elems[i].freq;
    return 0;
}

int Collection::getAtElem(int position) const {
    if (position >= len || position < 0)
        return -1;
    return elems[position].elem;
}

int Collection::getAtFreq(int position) const {
    if (position >= len || position < 0)
        return -1;
    return elems[position].freq;
}

void Collection::printCollection() {
    for (int i = 0; i < this->len; ++i)
        std::cout << elems[i].elem << ' ' << elems[i].freq << '\n';
}
