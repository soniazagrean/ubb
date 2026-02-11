//
// Created by Zagrean Sonia on 20.03.2025.
//

#include "Student.h"

#include <cstring>

Student::Student() : age(0), name(nullptr){}

Student::Student(int age, char *name) {
    this->age = age;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

Student::~Student() {
    delete[] this->name;
    this->name = nullptr;
}

Student & Student::operator=(const Student &student) {
    this->setAge(student.age);
    this->setName(student.name);
    return *this;
}

bool Student::operator==(const Student &student) {
    return this->age == student.age && strcmp(this->name, student.name) == 0;
}

void Student::setAge(int age) {
    this->age = age;
}

void Student::setName(char *name) {
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

int Student::getAge() const {
    return this->age;
}
char *Student::getName() const {
    return this->name;
}

Student::Student(const Student &student) {
    this->age = student.age;
    this->name = new char[strlen(student.name) + 1];
    strcpy(this->name, student.name);
}
