//
// Created by Sonia Zagrean on 19.05.2025.
//
#ifndef VALIDATOR_H
#define VALIDATOR_H
#include "Product.h"
#include <exception>
#include <string>
#include <vector>

class ValidationException : public std::exception {
private:
    std::string message;

public:
    explicit ValidationException(const std::string& message) : message(message) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};


class CodeValidationException : public ValidationException {
public:
    CodeValidationException() : ValidationException("Code must be positive.") {}
};

class PriceValidationException : public ValidationException {
public:
    PriceValidationException() : ValidationException("Price must be positive.") {}
};

class NameValidationException : public ValidationException {
public:
    NameValidationException() : ValidationException("Name cannot be empty.") {}
};


class ValidationErrorsException : public ValidationException {
public:
    ValidationErrorsException(const std::vector<std::string>& errors) : ValidationException(combineErrors(errors)) {}

private:
    static std::string combineErrors(const std::vector<std::string>& errors) {
        std::string result;
        for (const auto& error : errors) {
            result += error + "\n";
        }
        return result;
    }
};


class Validator {
public:
    virtual ~Validator() = default;
    virtual void validate(const Product& product) const = 0;
};

class CodeValidator : public Validator {
public:
    void validate(const Product& product) const override {
        if (product.getCode() <= 0)
            throw CodeValidationException();
    }
};

class PriceValidator : public Validator {
public:
    void validate(const Product& product) const override {
        if (product.getPrice() <= 0)
            throw PriceValidationException();
    }
};

class NameValidator : public Validator {
public:
    void validate(const Product& product) const override {
        if (product.getName().empty())
            throw NameValidationException();
    }
};

class ProductValidator {
private:
    std::vector<Validator*> validators;

public:
    ProductValidator() {
        validators.push_back(new CodeValidator());
        validators.push_back(new PriceValidator());
        validators.push_back(new NameValidator());
    }

    ~ProductValidator() {
        for (auto validator : validators) {
            delete validator;
        }
    }

    static void validateStatic(const Product& product);
};

#endif //VALIDATOR_H