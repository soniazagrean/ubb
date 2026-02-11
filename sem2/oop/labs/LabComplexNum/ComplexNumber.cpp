//
// Created by Zagrean Sonia on 19.03.2025.
//

#include "ComplexNumber.h"
#include <cmath>

ComplexNumber::ComplexNumber() : real(0.0), imaginary(0.0) {}

ComplexNumber::ComplexNumber(double real, double imaginary) : real(real), imaginary(imaginary) {}

ComplexNumber::ComplexNumber(const ComplexNumber &complexNumber) : real(complexNumber.real), imaginary(complexNumber.imaginary) {}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &complexNumber) const {
    return ComplexNumber(this->real + complexNumber.real, this->imaginary + complexNumber.real);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &complexNumber) const {
    return ComplexNumber(this->real - complexNumber.real, this->imaginary - complexNumber.imaginary);
}

double ComplexNumber::absoluteValue() {
    return sqrt(this->real * this->real + this->imaginary * this->imaginary);
}

ComplexNumber ComplexNumber::conjugateValue() {
    return ComplexNumber(this->real, -this->imaginary);
}

double ComplexNumber::getReal() {
    return this->real;
}

double ComplexNumber::getImaginary() {
    return this->imaginary;
}

ComplexNumber::~ComplexNumber() {}


std::istream & operator>>(std::istream &is, ComplexNumber &complexNumber) {
    return is >> complexNumber.real >> complexNumber.imaginary;
}

std::ostream & operator<<(std::ostream &os, const ComplexNumber &complexNumber) {
    if (complexNumber.imaginary > 0)
        os << complexNumber.real << "+" << complexNumber.imaginary << "*i";
    else
        os << complexNumber.real << complexNumber.imaginary << "*i";
    return os;
}
