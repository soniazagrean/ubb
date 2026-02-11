//
// Created by Sonia Zagrean on 03.04.2025.
//

#ifndef SERVICE_H
#define SERVICE_H

#include "Repository.h"

class Service {
private:
    Repository repo;
public:
    explicit Service(Repository& repo);
    ~Service();
    std::vector<Student> getStudents();

};



#endif //SERVICE_H
