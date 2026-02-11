//
// Created by Sonia Zagrean on 31.03.2025.
//

#include "ComplexNumber.h"

ComplexNumber::ComplexNumber() : real(0), imaginary(0) {}

ComplexNumber::ComplexNumber(double real, double imaginary) : real(real), imaginary(imaginary) {}

ComplexNumber::ComplexNumber(const ComplexNumber &num) {
    this->real = num.real;
    this->imaginary = num.imaginary;
}

bool ComplexNumber::operator==(const ComplexNumber &num) const {
    return this->real == num.real && this->imaginary == num.imaginary;
}

bool ComplexNumber::operator>(const ComplexNumber &num) const {
    return this->absoluteValue() > num.absoluteValue();
}

bool ComplexNumber::operator<(const ComplexNumber &num) const {
    return this->absoluteValue() < num.absoluteValue();
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &num) const {
    return {this->real + num.real, this->imaginary + num.imaginary};
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &num) const {
    return {this->real - num.real, this->imaginary - num.imaginary};
}

double ComplexNumber::absoluteValue() const {
    return sqrt(this->real * this->real + this->imaginary * this->imaginary);
}

double ComplexNumber::getReal() {
    return this->real;
}

double ComplexNumber::getImag() {
    return this->imaginary;
}

std::istream& operator>>(std::istream &is, ComplexNumber& num) {
    return is >> num.real >> num.imaginary;
}

std::ostream& operator<<(std::ostream &os, const ComplexNumber& num) {
    return os << num.real << "+" << num.imaginary << "*i";
}


