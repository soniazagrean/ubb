//
// Created by Sonia Zagrean on 15.05.2025.
//

#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "repository.h"


class Controller {
private:
    Repository& repo;

public:
    Controller(Repository& repo) : repo(repo) {}
    void addProdusDulce(const char* description, int price);
    void addProdusSarat(const char* description, int price, int gramsSalt);
    vector<Produs*> getAll();
};



#endif //CONTROLLER_H
