#include <iostream>
#include "Bag.h"
#include "BagIterator.h"

int main() {
    Bag b;
    BagIterator it(b);
    b.add(12);
    b.add(1);
    b.add(7);
    b.add(2);
    b.add(2);
    b.add(18);
    b.add(21);
    it.first();
    while (it.valid()) {
        std::cout << it.getAt() << ' ';
        it.next();
    }
    std::cout << '\n';
    b.remove(2);
    it.first();
    while (it.valid()) {
        std::cout << it.getAt() << ' ';
        it.next();
    }
    std::cout << '\n';
    b.add(18);
    b.add(18);
    b.add(18);
    std::cout << b.nrOccurrences(18) << '\n';
    return 0;
}

