#include <iostream>

#include "ExtendedTest.h"
#include "ShortTest.h"
#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <unistd.h>

bool cmp(int a, int b) {
    return a < b;
}
void checkMemoryLeaks() {
    std::cout << "\n[INFO] Checking memory leaks...\n";
    char command[64];
    sprintf(command, "leaks %d", getpid());
    system(command);
}

int main() {
    atexit(checkMemoryLeaks);
    testAll();
    testAllExtended();
    SortedBag bag(cmp);
    SortedBagIterator it(bag);
    bag.add(1);
    bag.add(2);
    bag.add(2);
    bag.add(3);
    bag.add(4);
    bag.add(4);
    it.first();
    while (it.valid()) {
        std::cout << it.getCurrent() << ' ';
        it.next();
    }
    return 0;
}
