#include <iostream>

#include "SortedBag.h"

bool greater(int a, int b) {
    return a < b;
}

int main() {
    SortedBag sb(greater);
    sb.add(18);
    sb.add(17);
    sb.add(22);
    sb.add(11);
    sb.add(30);
    sb.add(22);
    sb.add(98);
    sb.add(100);
    for (int i = 0; i < 7; ++i)
        std::cout << sb.getAt(i) << ' ';
    std::cout << '\n';
    sb.remove(22);
    sb.remove(22);
    for (int i = 0; i < 6; ++i)
        std::cout << sb.getAt(i) << ' ';
    return 0;
}

