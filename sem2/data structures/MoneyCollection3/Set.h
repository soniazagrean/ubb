#ifndef SET_H
#define SET_H

template<typename TElem>
using Comparator = bool (*)(const TElem&, const TElem&);

template<typename TElem>
class Set {
private:
    TElem* elems;
    int capacity;
    int length;
    Comparator<TElem> cmp;

    void resize();
    int search(const TElem& e) const;

public:
    explicit Set(Comparator<TElem> cmpFunc);
    ~Set();

    void add(const TElem& e);
    bool remove(const TElem& e);
    bool ifExists(const TElem& e) const;
    int size() const;
    TElem getAt(int pos) const;
};

#include "Set.tpp"

#endif
