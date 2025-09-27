#include <iostream>

#include "MultimeOrdonata.h"
#include "MultimeOrdonataIterator.h"

bool greater(int a, int b) {
    return a >= b;
}

int main() {
    MultimeOrdonata<int> m(greater);
    MultimeOrdonataIterator<int> it(m);
    m.add(9);
    m.add(40);
    m.add(23);
    m.add(17);
    m.add(97);
    m.add(4);
    it.first();
    while (it.valid()) {
        std::cout << it.getAt() << ' ';
        it.next();
    }
    return 0;
}
