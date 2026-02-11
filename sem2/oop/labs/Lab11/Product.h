//
// Created by Sonia Zagrean on 19.05.2025.
//

#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>


class Product {
private:
    int code;
    std::string name;
    int price;
public:
    Product(int code, std::string name, int price);
    ~Product()=default;

    int getCode() const;
    void setCode(int value);
    std::string getName() const;
    void setName(const std::string &value);
    int getPrice() const;
    void setPrice(int value);

    bool operator==(const Product& product) const;
    Product& operator=(const Product& other);
};



#endif //PRODUCT_H
