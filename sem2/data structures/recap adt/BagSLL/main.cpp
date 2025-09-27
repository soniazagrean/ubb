#include <iostream>

#include "BagIterator.h"
#include "ExtendedTest.h"
#include "ShortTest.h"

int main() {
    testAll();
    testAllExtended();
    Bag bag;
    BagIterator it(bag);
    bag.add(12);
    bag.add(9);
    bag.add(20);
    bag.add(3);
    bag.add(3);
    it.first();
    while (it.valid()) {
        std::cout << it.getCurrent() << ' ';
        it.next();
    }
    return 0;
}
