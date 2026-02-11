//
// Created by Zagrean Sonia on 20.03.2025.
//

#include "tests.h"

#include "Student.h"
#include "operations.h"
#include <cassert>
#include <cstring>
#include "Service.h"

void testStudent() {
    Student student1;
    assert(student1.getAge() == 0);
    assert(student1.getName() == nullptr);
    student1.setAge(1);
    assert(student1.getAge() == 1);
    student1.setName("John");
    assert(strcmp(student1.getName(), "John") == 0);
    Student student2;
    assert(student2.getAge() == 0);
    assert(student2.getName() == nullptr);
    student2.setAge(2);
    assert(student2.getAge() == 2);
    assert(strcmp(student2.getName(), "Mark") == 0);
    Student student3;
    assert(student3.getAge() == 0);
    assert(student3.getName() == nullptr);
    student3.setAge(3);
    assert(student3.getAge() == 3);
    assert(student3.getName() == "Cornel");
    assert(strcmp(student3.getName(), "Cornel") == 0);
    // Student students[3] = {student1, student2, student3};
    // Student result[10];
    // int result_size = 0;
    // filterStudent(students, 3, "Cornel", 1,result, result_size);
    // assert(result_size == 1);
    // assert(strcmp(result[0].getName(), "Cornel") == 0);
    // result_size = 0;
    // Repository repository;
    // repository.addStudent(student1);
    // repository.addStudent(student2);
    // repository.addStudent(student3);
    // filterStudent2(repository, "Cornel", 10, result, result_size);
    // assert(result_size == 1);
    // assert(strcmp(result[0].getName(), "Cornel") == 0);
}

void testRepository() {
    Repository repo("../students.txt");
    assert(repo.getStudentsSize() == 3);
    assert(repo.getStudent(1).getAge() == 14 && strcmp(repo.getStudent(1).getName(), "ana") == 0);
}

void testService() {
    Repository repo("../students.txt");
    Service service(repo);
    std::vector<Student> result = service.getStudents();
    assert(result.size() == 3);
    assert(result.at(0).getAge() == 20 && strcmp(result.at(0).getName(), "mihai") == 0);
}
