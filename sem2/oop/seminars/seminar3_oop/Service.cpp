//
// Created by Sonia Zagrean on 03.04.2025.
//

#include "Service.h"

Service::Service(Repository &repo): repo(repo) {} // pt ca e transmis prin referinta

Service::~Service() = default;

std::vector<Student> Service::getStudents() {
    return repo.getAll();
}

