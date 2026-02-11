//
// Created by Sonia Zagrean on 19.05.2025.
//

#ifndef REPOSITORY_H
#define REPOSITORY_H
#include <vector>

#include "Product.h"


class Repository {
protected:
    std::vector<Product> products;

public:
    Repository() = default;

    virtual ~Repository()=default;
    virtual void add(const Product& product);
    virtual void remove(const Product& product);
    virtual void update(int pos, const Product& product);
    std::vector<Product>& get();
};



#endif //REPOSITORY_H
