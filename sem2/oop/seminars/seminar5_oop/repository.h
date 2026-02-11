#ifndef REPOSITORY_H
#define REPOSITORY_H
#include <vector>

#include "produs.h"
using namespace std;
class Repository {
private:
    vector<Produs*> produse;
public:
    ~Repository();
    void add(Produs* produs);
    Produs * getAt(int id) const;
    int getSize() const;
    vector<Produs*> getAll();
};

#endif
