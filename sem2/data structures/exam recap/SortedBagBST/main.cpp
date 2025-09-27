#include <iostream>

#include "SortedBag.h"
#include "SortedBagIterator.h"

bool r(int a, int b){
    return a <= b;
}

void testAllExtended();

int main() {
    testAllExtended();
    SortedBag bag(r); // r is your ordering relation
    bag.add(5);
    bag.add(3);
    bag.add(5);

    SortedBagIterator it = bag.iterator();
    for (it.first(); it.valid(); it.next()) {
        std::cout << it.getCurrent() << " ";
    }
    // Output might be: 3 5 5

    return 0;
}
