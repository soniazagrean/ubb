//
// Created by Sonia Zagrean on 15.05.2025.
//

#include "Controller.h"

#include "InvalidDescriptionException.h"
#include "InvalidPriceException.h"
#include "produs_dulce.h"

void Controller::addProdusDulce(const char *description, int price) {
    if (strlen(description) < 2)
        throw InvalidDescriptionException("invalid length for description. length must be greater than 2");
    if (price < 0)
        throw InvalidPriceException("invalid value for price. price should be positive");
}

void Controller::addProdusSarat(const char *description, int price, int gramsSalt) {
    if (strlen(description) < 4)
        throw InvalidDescriptionException("invalid length for description. length must be greater than 4");
    if (price < 10)
        throw InvalidPriceException("invalid value for price. must be greater than 10");
    if (gramsSalt > 0)
        throw ProductException("invalid value for gramsSalt. must be positive");
}

vector<Produs *> Controller::getAll() {
    return repo.getAll();
}
