//
// Created by Sonia Zagrean on 15.05.2025.
//

#ifndef INVALIDDESCRIPTIONEXCEPTION_H
#define INVALIDDESCRIPTIONEXCEPTION_H
#include <string>

#include "ProductException.h"


class InvalidDescriptionException : public ProductException {
public:
    InvalidDescriptionException(const std::string msg): ProductException(msg){}
};



#endif //INVALIDDESCRIPTIONEXCEPTION_H
