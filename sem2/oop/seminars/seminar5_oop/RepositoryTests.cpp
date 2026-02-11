

#include "RepositoryTests.h"
#include <cassert>
#include "ProdusSarat.h"
#include "produs_dulce.h"
#include "repository.h"
#include <cstring>

void RepositoryTests() {
    Repository repository;
    assert(repository.getSize() == 0);

    repository.add(new ProdusDulce("ciocolata", 15));
    assert(repository.getSize() == 1);

    repository.add(new ProdusSarat("covrig", 10, 5));
    assert(repository.getSize() == 2);

    vector<Produs *> v = repository.getAll();
    //assert(repository.getAt(0) == ProdusDulce("ciocolata", 15));
    //assert(repository.getAt(1) == ProdusSarat("covrig", 10, 5));

}

void RepositoryTestsGetter() {
    Repository repository;
    ProdusSarat* produsSarat = new ProdusSarat("covrig", 10, 5);
    ProdusDulce* produsDulce = new ProdusDulce("ciocolata", 15);

    repository.add(produsSarat);
    repository.add(produsDulce);

    assert(strcmp(repository.getAt(0)->getDescription(), "Produs Sarat: covrig") == 0);
    assert(repository.getAt(0)->getPrice() == 10);
    assert(strcmp(repository.getAt(1)->getDescription(), "Produs Dulce: ciocolata") == 0);
    assert(repository.getAt(1)->getPrice() == 15);
}