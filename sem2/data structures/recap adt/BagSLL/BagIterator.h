//
// Created by Sonia Zagrean on 20.05.2025.
//

#include "Bag.h"

class BagIterator
{
    //DO NOT CHANGE THIS PART
    friend class Bag;

private:
    const Bag& bag;
    Node* current;


public:
    explicit BagIterator(const Bag& c);
    void first();
    void next();
    TElem getCurrent() const;
    bool valid() const;
};

