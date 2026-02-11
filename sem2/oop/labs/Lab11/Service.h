//
// Created by Sonia Zagrean on 19.05.2025.
//

#ifndef SERVICE_H
#define SERVICE_H
#include "Repository.h"
#include "Validator.h"

struct Money {
    int val;
    int freq;
};

class Service {
private:
    Repository& repo;
    std::vector<Money> stock;
    ProductValidator validator;

public:
    explicit Service(Repository& repo): repo(repo), validator(validator) {
        stock = {{1, 10}, {5, 10}, {10, 10}, {50, 5}, {100, 2}};
    }

    void addProduct(const Product& product);
    void removeProduct(const Product& product);
    void updateProduct(int pos, const Product& product);

    std::vector<Product> getAll();
    std::vector<Money> buyProduct(int code, int money);

};



#endif //SERVICE_H
