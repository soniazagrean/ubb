//
// Created by Sonia Zagrean on 31.03.2025.
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
    ComplexNumber(const ComplexNumber& num);
    bool operator==(const ComplexNumber& num) const;
    bool operator>(const ComplexNumber& num) const;
    bool operator<(const ComplexNumber& num) const;
    ComplexNumber operator+(const ComplexNumber& num) const;
    ComplexNumber operator-(const ComplexNumber& num) const;

    double absoluteValue() const;
    double getReal();
    double getImag();

    friend std::istream& operator>>(std::istream &is, ComplexNumber& num);
    friend std::ostream& operator<<(std::ostream &os, const ComplexNumber& num);
};



#endif //COMPLEXNUMBER_H
