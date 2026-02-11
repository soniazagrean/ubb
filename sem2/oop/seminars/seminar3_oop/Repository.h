//
// Created by Zagrean Sonia on 20.03.2025.
//

#ifndef REPOSITORY_H
#define REPOSITORY_H
#include "Student.h"
#include <iostream>

class Repository {
private:
    std::vector<Student> students;

public:
    explicit Repository(const std::string& filename);
    ~Repository();


    std::vector<Student> getAll();
    void addStudent(Student &student);
    Student getStudent(int position);
    int getStudentsSize();
};



#endif //REPOSITORY_H
