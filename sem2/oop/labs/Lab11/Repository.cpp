//
// Created by Sonia Zagrean on 19.05.2025.
//

#include "Repository.h"

void Repository::add(const Product &product) {
    products.push_back(product);
}

void Repository::remove(const Product &product) {
    products.erase(std::remove(products.begin(), products.end(), product), products.end());
}

void Repository::update(int pos, const Product &product) {
    if (pos < 0 || pos >= products.size())
        throw std::runtime_error("out of range pos");

    products[pos] = product;
}

std::vector<Product>& Repository::get() {
    return products;
}

