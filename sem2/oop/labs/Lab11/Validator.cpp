//
// Created by Sonia Zagrean on 19.05.2025.
//

#include "Validator.h"


void ProductValidator::validateStatic(const Product &product) {
    std::vector<std::string> errors;

    if (product.getCode() <= 0)
        errors.push_back("Code must be positive.");

    if (product.getPrice() <= 0)
        errors.push_back("Price must be positive.");

    if (product.getName().empty())
        errors.push_back("Name cannot be empty.");

    if (!errors.empty()) {
        throw ValidationErrorsException(errors);
    }
}
