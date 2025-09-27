#include <iostream>

#include "dynamic/StackDynamic.h"
#include "SLL/StackSLL.h"
#include "vectorSTL/StackStl.h"

int main() {
    StackStl<int> s;

    std::cout << "Pushing elements onto the stack...\n";
    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "Top element: " << s.top() << std::endl;

    std::cout << "\nPopping elements:\n";
    while (!s.isEmpty()) {
        std::cout << s.pop() << std::endl;
    }

    std::cout << "\nTrying to pop from an empty stack...\n";
    try {
        s.pop();  // Should throw
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\nTrying to access top of an empty stack...\n";
    try {
        s.top();  // Should throw
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }


    StackSLL<int> sl;

    // Verificăm că putem face push
    sl.push(10);
    sl.push(20);
    sl.push(30);

    // Afișăm top-ul
    std::cout << "Top: " << sl.top() << std::endl;

    // Scoatem toate elementele
    while (!sl.isEmpty()) {
        std::cout << "Pop: " << sl.pop() << std::endl;
    }

    // Verificare protecție la pop pe stivă goală
    try {
        sl.pop();  // ar trebui să arunce excepție
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    StackDynamic<int> s2;

    std::cout << "Pushing elements onto the dynamic stack...\n";
    s2.push(10);
    s2.push(20);
    s2.push(30);

    std::cout << "Top element: " << s2.top() << std::endl;

    std::cout << "\nPopping elements:\n";
    while (!s2.isEmpty()) {
        std::cout << s2.pop() << std::endl;
    }

    std::cout << "\nTrying to pop from an empty dynamic stack...\n";
    try {
        s2.pop();  // Should throw
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\nTrying to access top of an empty dynamic stack...\n";
    try {
        s2.top();  // Should throw
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}
