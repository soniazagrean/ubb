#ifndef REPO_H
#define REPO_H

#include <vector>
#include "Produs.h"

class Repo {
private:
    std::vector<Produs*> produse;
public:
    ~Repo();
    void adauga(Produs* p);
    Produs* get(int index) const;
    void deleteProduct(int index);
    int size();
    vector<Produs*> getAll();
};

#endif
