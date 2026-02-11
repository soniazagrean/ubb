//
// Created by Sonia Zagrean on 31.05.2025.
//

#pragma once
#include <vector>

#include "MijlocDeTransport.h"

class Repository {
private:
    std::vector<MijlocDeTransport*> mijloace;

public:
    Repository()=default;
    ~Repository(){
        for (auto mijloc : mijloace) {
            delete mijloc;
        }
    }
    void add(MijlocDeTransport* mijloc) {
        mijloace.push_back(mijloc);
    }
    std::vector<MijlocDeTransport*>& getAll() {
        return mijloace;
    }
};
