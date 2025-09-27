#include <iostream>

#include "BinaryHeap.h"

int main() {
    BinaryHeap<int> heap;

    heap.push(5);
    heap.push(8);
    heap.push(3);
    heap.push(10);
    heap.push(1);

    std::cout << "Priority queue (heap):" << std::endl;
    while (!heap.empty()) {
        std::cout << heap.top() << " ";
        heap.pop();
    }

    std::cout << std::endl;

    return 0;
}
