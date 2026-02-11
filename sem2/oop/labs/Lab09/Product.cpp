//
// Created by Sonia Zagrean on 03.05.2025.
//

#include "Product.h"

Product::Product() : code(0), price(0.0) {}

Product::Product(int code, std::string name, double price) : code(code), name(name), price(price) {}

int Product::getCode() const {
    return code;
}

void Product::setCode(const int value) {
    this->code = value;
}

std::string Product::getName() const {
    return name;
}

void Product::setName(const std::string &value) {
    this->name = value;
}

double Product::getPrice() const {
    return price;
}

void Product::setPrice(const double value) {
    this->price = value;
}

bool Product::operator==(const Product &product) const {
    return (this->name == product.name && this->code == product.code && this->price == product.price);
}

Product& Product::operator=(const Product& other) {
    if (*this == other)
        return *this;
    this->name = other.name;
    this->code = other.code;
    this->price = other.price;
    return *this;
}
