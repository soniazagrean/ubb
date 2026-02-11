#ifndef SERVICE_H
#define SERVICE_H
#include "Repo.h"


class Controller {
private: Repo& repo;
public:
    explicit Controller(Repo& repo) : repo(repo) {}
    void addProdusDulce(string d, int p);
    void addProdusSarat(string d, int p, int s);
    vector<Produs*> getProducts();
    int size();
    Produs* getProdus(int index);
};

#endif
