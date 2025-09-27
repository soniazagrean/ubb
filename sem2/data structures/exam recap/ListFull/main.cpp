#include <iostream>

#include "dynamic/ListDynamic.h"
#include "dynamic/ListDynamicIterator.h"
#include <unistd.h>

#include "PriorityQueue.h"
#include "sll/ListSLL.h"

void checkMemoryLeaks() {
    std::cout << "\n[INFO] Checking memory leaks...\n";
    char command[64];
    sprintf(command, "leaks %d", getpid());
    system(command);
}

bool ascending(int a, int b) {
    return a < b;  // smaller value = higher priority
}

bool descending(int a, int b) {
    return a > b;  // larger value = higher priority
}


int main() {
    atexit(checkMemoryLeaks);
    ListDynamic<int> l1;
    ListDynamicIterator<int> it(l1);
    l1.push_front(1);
    l1.push_front(2);
    l1.push_front(3);
    l1.push_front(4);
    l1.push_back(4);
    l1.push_back(3);
    l1.push_back(2);
    l1.push_back(1);
    it.first();
    while (it.valid()) {
        std::cout << it.getAt() << ' ';
        it.next();
    }



    ListSLL<int> list;

    std::cout << "Pushing elements to front: 10, 20, 30\n";
    list.push_front(10);
    list.push_front(20);
    list.push_front(30);

    std::cout << "Pushing elements to back: 40, 50\n";
    list.push_back(40);
    list.push_back(50);

    std::cout << "Current list size: " << list.size() << "\n";
    std::cout << "Elements in list:\n";
    for (int i = 0; i < list.size(); ++i)
        std::cout << list.getAt(i) << " ";
    std::cout << "\n";

    std::cout << "Removing element at index 2\n";
    list.removeIndex(2);

    std::cout << "Elements after removal:\n";
    for (int i = 0; i < list.size(); ++i)
        std::cout << list.getAt(i) << " ";
    std::cout << "\n";

    std::cout << "Pop front: " << list.pop_front() << "\n";
    std::cout << "Pop back: " << list.pop_back() << "\n";

    std::cout << "Elements after popping:\n";
    for (int i = 0; i < list.size(); ++i)
        std::cout << list.getAt(i) << " ";
    std::cout << "\n";

    std::cout << "Searching for 20: " << (list.search(20) ? "Found" : "Not found") << "\n";
    std::cout << "Occurrences of 10: " << list.nrOccurrences(10) << "\n";

    std::cout << "Setting index 0 to 99\n";
    list.setAt(0, 99);

    std::cout << "Final list contents:\n";
    for (int i = 0; i < list.size(); ++i)
        std::cout << list.getAt(i) << " ";
    std::cout << "\n";


    PriorityQueue<int> pq(ascending);  // Use ascending order (min-heap behavior)

    pq.enqueue(30);
    pq.enqueue(10);
    pq.enqueue(20);

    std::cout << "PriorityQueue contents (ascending priority): ";
    while (!pq.empty()) {
        std::cout << pq.dequeue() << " ";
    }
    return 0;
}
