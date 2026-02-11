#ifndef INVALIDPRODUCTPRICEEXCEPTION_H
#define INVALIDPRODUCTPRICEEXCEPTION_H

class InvalidProductPriceException : public ProductException {
public:
    explicit InvalidProductPriceException(const string& msg) : ProductException(msg) {}
};

#endif //INVALIDPRODUCTPRICEEXCEPTION_H
