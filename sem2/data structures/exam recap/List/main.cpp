#include <iostream>

#include "IndexedList/IndexedList.h"
#include "IteratedList/IteratedList.h"
#include "IteratedList/IteratedListIterator.h"

int main() {
    IteratedList<int> l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    for (auto it = l1.begin(); it != l1.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';
    IndexedList<int> l2;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    for (auto it = l1.begin(); it != l1.end(); ++it) {
        std::cout << *it << ' ';
    }
    return 0;
}
