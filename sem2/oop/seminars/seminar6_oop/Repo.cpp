#include "Repo.h"

Repo::~Repo() {
    for (auto p : produse) {
        delete p;
    }
}

void Repo::adauga(Produs* p) {
    produse.push_back(p);
}

Produs* Repo::get(int index) const {
    if (index >= 0 && index < produse.size())
        return produse[index];
    return nullptr;
}

int Repo::size() {
    return produse.size();
}

void Repo::deleteProduct(int index) {
    if (index >= 0 && index < produse.size()) {
        delete produse[index];
        produse.erase(produse.begin() + index);
    }
}

vector<Produs*> Repo::getAll() {
    return produse;
}