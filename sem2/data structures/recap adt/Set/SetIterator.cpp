#include "SetIterator.h"
#include "Set.h"


SetIterator::SetIterator(const Set& m) : set(m)
{
    current = 0;
}


void SetIterator::first() {
    current = 0;
}


void SetIterator::next() {
    if (!valid())
        return;
    current++;
}


TElem SetIterator::getCurrent()
{
    if (valid())
        return set.get(current);
    return NULL_TELEM;
}

bool SetIterator::valid() const {
    if (current >= 0 && current < set.size())
        return true;
    return false;
}



