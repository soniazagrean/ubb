#include <iostream>

#include "MultimeOrdonata.h"
#include "MultimeOrdonataIterator.h"

bool greater(int a, int b) {
    return a <= b;
}

int main() {

    MultimeOrdonata<int> m(greater);
    MultimeOrdonataIterator<int> it(m);
    m.add(2);
    m.add(2);
    m.add(1);
    m.add(8);
    m.add(4);
    it.first();
    while (it.valid()) {
        std::cout << it.getAt() << ' ';
        it.next();
    }
    return 0;
}
