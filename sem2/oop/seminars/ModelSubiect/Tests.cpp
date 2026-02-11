//
// Created by Sonia Zagrean on 31.05.2025.
//

#include "Tests.h"
#include "Service.h"
#include <cassert>
#include <iostream>

void runTests() {
    std::cout << "--- Running tests ---\n";

    Repository r;
    Service s(r);

    // Test 1: add transports
    s.add(new Autobuz(1, 20));
    s.add(new Tramvai(2, 30));
    s.add(new Autobuz(3, 40));

    assert(s.get().size() == 3);

    // Test 2: filterCap
    auto filtered = s.filterCap(25);
    assert(filtered.size() == 2);  // Tramvai(30), Autobuz(40)

    // Test 3: countTypes
    auto counts = s.countTypes();
    assert(counts.first == 2);  // 2 Autobuze
    assert(counts.second == 1); // 1 Tramvai

    // Test 4: largestCapacity
    auto* largest = s.largestCapacity();
    assert(largest != nullptr);
    assert(largest->getId() == 3);
    assert(largest->getCapacitate() == 40);

    std::cout << "--- All tests passed! ---\n\n";
}
