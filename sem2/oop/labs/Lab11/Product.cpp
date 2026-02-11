//
// Created by Sonia Zagrean on 19.05.2025.
//

#include "Product.h"


Product::Product(int code, std::string name, int price) : code(code), name(name), price(price) {}

int Product::getCode() const {
    return code;
}

void Product::setCode(const int value) {
    code = value;
}

std::string Product::getName() const {
    return name;
}

void Product::setName(const std::string &value) {
    name = value;
}

int Product::getPrice() const {
    return price;
}

void Product::setPrice(const int value) {
    price = value;
}

bool Product::operator==(const Product &product) const {
    return (this->name == product.name && this->code == product.code && this->price == product.price);
}

Product& Product::operator=(const Product& other) {
    if (*this == other)
        return *this;
    name = other.name;
    code = other.code;
    price = other.price;
    return *this;
}
