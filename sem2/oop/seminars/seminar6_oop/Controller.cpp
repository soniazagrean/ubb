#include "Controller.h"

#include "InvalidProductDescriptionException.h"
#include "InvalidProductPriceException.h"
#include "ProdusDulce.h"
#include "ProdusSarat.h"

void Controller::addProdusDulce(string d, int p) {
    if (d.size() < 2) {
        throw InvalidProductDescriptionException("Description must have more than two characters.");
    }
    if (p <= 0) {
        throw InvalidProductPriceException("Price must be a positive number.");
    }

    Produs* produs = new ProdusDulce(d, p);
    repo.adauga(produs);
}

void Controller::addProdusSarat(string d, int p, int s) {
    if (d.size() < 4) {
        throw InvalidProductDescriptionException("Description must have more than four characters.");
    }
    if (p <= 0) {
        throw InvalidProductPriceException("Price must be a positive number.");
    }

    Produs* produs = new ProdusSarat(d, p,s);
    repo.adauga(produs);
}

vector<Produs *> Controller::getProducts() {
    return repo.getAll();
}

int Controller::size() {
    return repo.size();
}

Produs * Controller::getProdus(int index) {
    return repo.get(index);
}


