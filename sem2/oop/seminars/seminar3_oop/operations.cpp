//
// Created by Zagrean Sonia on 20.03.2025.
//

#include "operations.h"

#include <cstring>
#include "Repository.h"

void filterStudent(Student students[], int size, char *name, int age, Student result[], int &result_size) {
    for (int i = 0; i < size; ++i) {
        if (students[i].getName() != nullptr && strcmp(students[i].getName(), name) == 0  && students[i].getAge() > age) {
            result[result_size++] = students[i];
        }
    }
}

void filterStudent2(Repository &studentsRepo, char *name, int age, Student result[], int &result_size) {
    for (int i = 0; i < studentsRepo.getStudentsSize(); i++) {
        if (strcmp(studentsRepo.getStudent(i).getName(), name) == 0 && studentsRepo.getStudent(i).getAge() > age) {
            result[result_size++] = studentsRepo.getStudent(i);
        }

    }
}
