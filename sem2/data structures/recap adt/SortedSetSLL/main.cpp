#include <iostream>

#include "ExtendedTest.h"
#include "ShortTest.h"
#include <unistd.h>

#include "SortedSetIterator.h"

void checkMemoryLeaks() {
    std::cout << "\n[INFO] Checking memory leaks...\n";
    char command[64];
    sprintf(command, "leaks %d", getpid());
    system(command);
}

bool cmp(int a, int b) {
    return a < b;
}

int main() {
    atexit(checkMemoryLeaks);
    testAll();
    testAllExtended();
    SortedSet bag(cmp);
    SortedSetIterator it(bag);
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
