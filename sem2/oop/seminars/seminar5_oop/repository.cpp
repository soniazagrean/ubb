#include "repository.h"
Repository::~Repository() {
    for (auto produs : produse) {
        delete produs;
    }
}
void Repository::add(Produs* produs) {
    produse.push_back(produs);
}

Produs *Repository::getAt(const int id) const {
    return produse.at(id);
}

int Repository::getSize() const {
    return produse.size();
}

vector<Produs *> Repository::getAll() {
    return produse;
}
