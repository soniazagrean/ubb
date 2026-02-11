//
// Created by Zagrean Sonia on 19.03.2025.
//

#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

#include <iostream>

class ComplexNumber {
private:
    double real;
    double imaginary;
public:
    ComplexNumber();
    ComplexNumber(double real, double imaginary);
    ComplexNumber(const ComplexNumber& complexNumber);
    ComplexNumber operator+(const ComplexNumber& complexNumber) const;
    ComplexNumber operator-(const ComplexNumber& complexNumber) const;
    double absoluteValue();
    ComplexNumber conjugateValue();
    double getReal();
    double getImaginary();
    ~ComplexNumber();

    friend std::istream& operator>>(std::istream& is, ComplexNumber& complexNumber);
    friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& complexNumber);
};



#endif //COMPLEXNUMBER_H
