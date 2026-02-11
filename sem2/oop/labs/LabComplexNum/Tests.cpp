//
// Created by Zagrean Sonia on 20.03.2025.
//

#include "Tests.h"

#include "ComplexNumber.h"
#include <cassert>

void testAll() {
    ComplexNumber c1 = ComplexNumber();
    assert(c1.getImaginary() == 0.0);
    assert(c1.getReal() == 0.0);
    ComplexNumber num1(2.2, 3.6);
    ComplexNumber num2(4.3, 1.2);
    assert(num1.getImaginary() == 3.6);
    assert(num1.getReal() == 2.2);
    assert(num2.getImaginary() == 1.2);
    assert(num2.getReal() == 4.3);
    // std::cout << num2.absoluteValue() << std::endl;
    assert(std::abs(num1.absoluteValue() - 4.219) < 0.001);
    assert(std::abs(num2.absoluteValue() - 4.4643) < 0.001);
    ComplexNumber num3 = num1 + num2;
    assert(num3.getReal() == 6.5);
    assert(num3.getImaginary() == 7.9);
}
