//
// Created by Sonia Zagrean on 15.05.2025.
//

#ifndef PRODUCTEXCEPTION_H
#define PRODUCTEXCEPTION_H
#include <stdexcept>


class ProductException : public std::runtime_error {
public:
    explicit ProductException(const std::string& msg) : std::runtime_error(msg){}
};



#endif //PRODUCTEXCEPTION_H
