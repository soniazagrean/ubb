//
// Created by Sonia Zagrean on 04.06.2025.
//

#ifndef REPOSITORY_H
#define REPOSITORY_H
#include <vector>

#include "Program.h"


class Repository {
private:
    std::vector<Program> repo;

public:
    Repository()=default;
    ~Repository()=default;
    void add(Program& p) {
        repo.push_back(p);
    }
    std::vector<Program>& get() {
        return repo;
    }
};



#endif //REPOSITORY_H
