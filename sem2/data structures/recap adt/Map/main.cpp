#include <iostream>

#include "Map.h"

int main() {
    Map mp;
    mp.add(11, "ion");
    mp.add(20, "ana");
    mp.add(8, "min");
    mp.add(3, "don");
    mp.add(32, "ili");
    for (int i = 0; i < 5; ++i)
        mp.printMap(i);
    std::cout << '\n';
    mp.remove(32);
    for (int i = 0; i < 4; ++i)
        mp.printMap(i);
    return 0;
}

