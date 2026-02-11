#include <cassert>
#include <iostream>
#include "ProdusDulce.h"
#include "ProdusSarat.h"
#include "Repo.h"
#include "tests.h"

#include "InvalidProductDescriptionException.h"
#include "InvalidProductPriceException.h"
#include "Controller.h"

using namespace std;

void test_ProdusDulce() {
    ProdusDulce pd("Ciocolata", 20);
    assert(pd.getDescriere() == "Produs Dulce: Ciocolata");

    Produs* s = &pd;
    assert(s->getDescriere() == "Produs Dulce: Ciocolata");
}

void test_ProdusSarat() {
    ProdusSarat ps("Covrig", 5, 6);
    assert(ps.getGrameSare() == 6);
    assert(ps.getDescriere() == "Produs Sarat: Covrig");
    Produs* s = &ps;
    assert(s->getDescriere() == "Produs Sarat: Covrig");
}

void test_Repo_Dulce() {
    Repo repo;
    repo.adauga(new ProdusDulce("Tort", 15));
    repo.adauga(new ProdusDulce("Prajitura", 10));

    assert(repo.size() == 2);
    assert(repo.get(0)->getDescriere() == "Produs Dulce: Tort");
    assert(repo.get(1)->getDescriere() == "Produs Dulce: Prajitura");
}

void test_Repo_Sarat() {
    Repo repo;
    repo.adauga(new ProdusSarat("Covrig", 2, 10));
    repo.adauga(new ProdusSarat("Saratele", 18, 20));

    assert(repo.size() == 2);
    assert(repo.get(0)->getDescriere() == "Produs Sarat: Covrig");
    assert(repo.get(1)->getDescriere() == "Produs Sarat: Saratele");
}

void test_Repo_Mix() {
    Repo repo;
    repo.adauga(new ProdusDulce("Ciocolata", 20));
    repo.adauga(new ProdusSarat("Biscuiti Sarati", 15, 45));
    repo.adauga(new ProdusDulce("Tort", 50));

    assert(repo.size() == 3);
    assert(repo.get(0)->getDescriere() == "Produs Dulce: Ciocolata");
    assert(repo.get(1)->getDescriere() == "Produs Sarat: Biscuiti Sarati");
    assert(repo.get(2)->getDescriere() == "Produs Dulce: Tort");
}

void test_Service() {
    Repo repo;
    Controller service(repo);

    service.addProdusDulce("Ciocolata", 20);
    service.addProdusSarat("Biscuiti Sarati", 15, 45);
    service.addProdusDulce("Tort", 50);

    assert(service.size() == 3);
    assert(service.getProdus(0)->getDescriere() == "Produs Dulce: Ciocolata");
    assert(service.getProdus(1)->getDescriere() == "Produs Sarat: Biscuiti Sarati");
    assert(service.getProdus(2)->getDescriere() == "Produs Dulce: Tort");

    try {
        service.addProdusDulce("", 10);
        assert(false);
    } catch (const InvalidProductDescriptionException& e) {
        assert(string(e.what()) == "Description must have more than two characters.");
    }

    try {
        service.addProdusSarat("Chips", -5, 10);
        assert(false);
    } catch (const InvalidProductPriceException& e) {
        assert(string(e.what()) == "Price must be a positive number.");
    }

    try {
        service.addProdusSarat("abc", -5, 10);
        assert(false);
    } catch (const InvalidProductDescriptionException& e) {
        assert(string(e.what()) == "Description must have more than four characters.");
    }

    cout << "All Service tests passed!" << endl;
}