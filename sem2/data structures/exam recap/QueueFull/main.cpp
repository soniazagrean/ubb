#include <iostream>
#include "stl/QueueStl.h"

int main() {
    QueueStl<int> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    std::cout << "Front: " << q.top() << "\n";

    while (!q.isEmpty()) {
        std::cout << "Dequeued: " << q.dequeue() << "\n";
    }

    try {
        q.dequeue();
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << "\n";
    }

    return 0;
}
