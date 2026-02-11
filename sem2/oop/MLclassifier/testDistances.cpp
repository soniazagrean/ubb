#include "testDistances.h"
#include <cassert>
#include "Distance.h"
#define EPS 0.000001

void testHammingDistanceForInts() {
    HammingDistance<int> hd;

    // Test 1: Identical vectors
    assert(hd.evaluate({1, 2, 3}, {1, 2, 3}) == 0);

    // Test 2: Completely different vectors
    assert(hd.evaluate({1, 2, 3}, {4, 5, 6}) == 3);

    // Test 3: Partially different
    assert(hd.evaluate({1, 2, 3}, {1, 5, 3}) == 1);

    // Test 4: Empty vectors
    assert(hd.evaluate({}, {}) == 0);

    //Test 5: Different sizes
    assert(hd.evaluate({1, 2, 3}, {1, 2}) == 1); 
}


void testHammingDistanceForStrings() {
    HammingDistance<string> hd;

    // Test 1: Identical vectors
    assert(abs(hd.evaluate({"ana", "are", "mere"}, {"ana", "are", "mere"}) - 0.0) < EPS);

    // Test 2: Completely different vectors
    assert(abs(hd.evaluate({"ana", "are", "mere"}, {"frezia", "este", "parfumata"}) - 3.0) < EPS);

    // Test 3: Partially different
    assert(abs(hd.evaluate({"ana", "are", "mere"}, {"ana", "culege", "mere"}) - 1) < EPS);

    // Test 4: Empty vectors
    assert(abs(hd.evaluate({}, {}) - 0.0) < EPS);

    //Test 5: Different sizes
    assert(abs(hd.evaluate({"ana", "are", "mere"}, {"ana", "are"}) - 1.0) < EPS); 
}

void testJaccardDistance() {
    JaccardDistance<int> jd;

    // Test 1: Identical vectors
    assert(abs(jd.evaluate({1, 2, 3}, {1, 2, 3}) - 0.0) < EPS);

    // Test 2: No common elements
    assert(abs(jd.evaluate({1, 2, 3}, {4, 5, 6}) - 1.0) < EPS);

    // Test 3: Some common elements
    double result = jd.evaluate({1, 2, 3}, {2, 3, 4});
    assert(abs(result - (1.0 - 2.0 / 4.0)) <EPS); // 2 common, 4 union
}

void testPolymorphism() {
    Distance<int>* d1 = new HammingDistance<int>();
    Distance<int>* d2 = new JaccardDistance<int>();

    assert(abs(d1->evaluate({1, 2, 3}, {1, 2, 4}) - 1.0) < EPS);
    assert(abs(d2->evaluate({1, 2}, {2, 3}) - (1.0 - 1.0 / 3.0)) < EPS);

    delete d1;
    delete d2;
}

void testAll() {
    testHammingDistanceForInts();
    testHammingDistanceForStrings();
    testJaccardDistance();
    testPolymorphism();
}