#include <iostream>

#include "Set.h"
#include "SetIterator.h"

int main() {
    Set s;
    s.add(1);
    s.add(2);
    s.add(1);
    s.add(5);
    s.add(2);
    s.add(3);
    SetIterator it = s.iterator();
    it.first();
    while (it.valid()) {
        std::cout << it.getCurrent() << ' ';
        it.next();
    }
    return 0;
}

