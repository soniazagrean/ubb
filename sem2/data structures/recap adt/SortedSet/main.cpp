#include <iostream>

#include "SortedSet.h"
#include "SortedSetIterator.h"

bool lower(int a, int b) {
    return a < b;
}

int main() {
    SortedSet s(lower);
    SortedSetIterator it(s);
    s.add(8);
    s.add(2);
    s.add(5);
    s.add(1);
    s.add(3);
    s.add(9);
    s.remove(8);
    it.first();
    while (it.valid()) {
        std:: cout << it.getAt() << ' ';
        it.next();
    }
    return 0;
}
