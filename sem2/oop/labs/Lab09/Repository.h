//
// Created by Sonia Zagrean on 03.05.2025.
//

#ifndef REPOSITORY_H
#define REPOSITORY_H

/// create, read, update, delete

#include <vector>
#include "Product.h"

class Repository {
protected:
    std::vector<Product> items;

public:
    virtual ~Repository() = default;

    virtual void addItem(const Product& item);
    virtual void removeItem(const Product& item);
    virtual void update(int position, const Product& itemOther);
    virtual int getSize();
    virtual std::vector<Product> getAll();
};


#endif //REPOSITORY_H
