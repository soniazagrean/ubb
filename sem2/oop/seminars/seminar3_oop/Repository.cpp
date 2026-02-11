//
// Created by Zagrean Sonia on 20.03.2025.
//

#include "Repository.h"
#include <iostream>
#include <fstream>


Repository::Repository(const std::string& filename) {
    std::ifstream fin(filename);
    if (!fin.is_open()) {
        std::cout << "error opening the file";
        return;
    }
    int age;
    char name[10];
    while (fin >> age >> name)
        this->students.push_back(Student(age, name));
    fin.close();
}

Repository::~Repository() = default;

void Repository::addStudent(Student &student) {
    this->students.push_back(student);
}

Student Repository::getStudent(int position) {
    return students.at(position);
}

int Repository::getStudentsSize() {
    return students.size();
}

std::vector<Student> Repository::getAll() {
    return this->students;
}



