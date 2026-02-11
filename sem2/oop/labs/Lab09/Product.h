//
// Created by Sonia Zagrean on 03.05.2025.
//

#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>

class Product {
private:
    int code;
    std::string name;
    double price;

public:
    Product();
    Product(int code, std::string name, double price);


    int getCode() const;
    void setCode(int value);
    std::string getName() const;
    void setName(const std::string &value);
    double getPrice() const;
    void setPrice(double value);

    bool operator==(const Product& product) const;
    Product& operator=(const Product& other);
};



#endif //PRODUCT_H
