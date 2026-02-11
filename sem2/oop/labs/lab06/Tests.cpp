//
// Created by Sonia Zagrean on 01.04.2025.
//

#include "Tests.h"
#include "ComplexNumber.h"
#include "Operations.h"
#include <cassert>

bool cmp_absolute(const ComplexNumber &n1, const ComplexNumber &n2) {
    return n1 < n2;
}

void test_greatestComplexNumber() {
    std::priority_queue<ComplexNumber, std::vector<ComplexNumber>, Comparator> pq(cmp_absolute);

    pq.push(ComplexNumber(1, 1));
    pq.push(ComplexNumber(3, 4));
    pq.push(ComplexNumber(2, -2));

    ComplexNumber greatest = greatestComplexNumber(pq);
    assert(greatest.getReal() == 3 && greatest.getImag() == 4);
}

void test_insideDial1() {
    std::priority_queue<ComplexNumber, std::vector<ComplexNumber>, Comparator> pq(cmp_absolute);

    pq.push(ComplexNumber(0.5, 0.5));
    pq.push(ComplexNumber(0.9, 0.3));
    pq.push(ComplexNumber(2, 2));
    pq.push(ComplexNumber(-0.5, 0.5));
    pq.push(ComplexNumber(0.5, -0.5));

    insideDial1(pq);
}

void test_longestSeq() {
    std::priority_queue<ComplexNumber, std::vector<ComplexNumber>, Comparator> pq(cmp_absolute);

    pq.push(ComplexNumber(1, 1));
    pq.push(ComplexNumber(1, 1));
    pq.push(ComplexNumber(2, 2));
    pq.push(ComplexNumber(2, 2));
    pq.push(ComplexNumber(2, 2));
    pq.push(ComplexNumber(3, 3));
    pq.push(ComplexNumber(3, 3));

    longestSeq(pq);
}

void test_all() {
    test_greatestComplexNumber();
    test_insideDial1();
    test_longestSeq();
}


