//
// Created by Sonia Zagrean on 03.05.2025.
//


/// create, read, update, delete

#ifndef SERVICE_H
#define SERVICE_H

#include "Repository.h"
#include "Product.h"

struct Money {
    int val;
    int freq;
};

class Service {
private:
    Repository& products;
    std::vector<Money> stock;

public:
    explicit Service(Repository &repo);
    void add(int code, std::string name, double price);
    void remove(int code, std::string name, double price);
    void update(int position, const Product& other);
    int getSizeOf();
    std::vector<Product> get();

    std::vector<Money> buyProduct(int code, double input);
};



#endif //SERVICE_H
