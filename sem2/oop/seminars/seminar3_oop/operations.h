//
// Created by Zagrean Sonia on 20.03.2025.
//

#ifndef OPERATIONS_H
#define OPERATIONS_H
#include "Student.h"
#include "Repository.h"


void filterStudent(Student students[], int size, char *name, int age, Student result[], int &result_size);
void filterStudent2(Repository &studentsRepo, char *name, int age, Student result[], int &result_size);


#endif //OPERATIONS_H
