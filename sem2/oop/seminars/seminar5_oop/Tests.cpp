#include "Tests.h"
#include <cassert>
#include <string.h>

#include "Controller.h"
#include "repository.h"
#include "InvalidDescriptionException.h"

void produsDulceTests() {
    ProdusDulce produsDulce("ciocolata", 10 );
    assert(produsDulce.getPrice() == 10);
    assert(strcmp(produsDulce.getDescription(), "Produs Dulce: ciocolata") == 0);
    Produs * p;
    p = &produsDulce;
    assert(strcmp(p->getDescription(), "Produs Dulce: ciocolata") == 0);
    assert(produsDulce.getPrice() == 10);
}

void produsSaratTests() {
    ProdusSarat produsSarat("covrig", 10, 5);
    assert(produsSarat.getPrice() == 10);
    assert(strcmp(produsSarat.getDescription(), "Produs Sarat: covrig") == 0);
    assert(produsSarat.getGrameSalt() == 5);
    ProdusSarat * p;
    p = &produsSarat;
    assert(strcmp(p->getDescription(), "Produs Sarat: covrig") == 0);
    assert(produsSarat.getPrice() == 10);

}

void testController() {
    Repository repo;
    Controller c(repo);
    try {
        c.addProdusDulce("l", 12);
        assert(false);
    }
    catch(InvalidDescriptionException& e) {
        assert(string(e.what()) == "invalid length for description. length must be greater than 2");
    }
    try {
        c.addProdusSarat("lsaead", 4, -2);
        assert(false);
    }
    catch (ProductException& e) {
        assert(string(e.what()) == "invalid value for price. must be greater than 10"); // message for price
    }
}
