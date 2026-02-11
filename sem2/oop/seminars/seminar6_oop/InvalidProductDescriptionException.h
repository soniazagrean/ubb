#ifndef INVALIDPRODUCTDESCRIPTIONEXCEPTION_H
#define INVALIDPRODUCTDESCRIPTIONEXCEPTION_H

#include "ProductException.h"

class InvalidProductDescriptionException : public ProductException {
public:
    InvalidProductDescriptionException(const string& msg) : ProductException(msg) {}
};

#endif //INVALIDPRODUCTDESCRIPTIONEXCEPTION_H
