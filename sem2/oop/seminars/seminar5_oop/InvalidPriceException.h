//
// Created by Sonia Zagrean on 15.05.2025.
//

#ifndef INVALIDPRICEEXCEPTION_H
#define INVALIDPRICEEXCEPTION_H
#include <string>

#include "ProductException.h"


class InvalidPriceException : public ProductException {
public:
    InvalidPriceException(const std::string msg) : ProductException(msg) {}

};



#endif //INVALIDPRICEEXCEPTION_H
