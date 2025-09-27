#include <iostream>
#include "BST.h"
#include "Student.h"

void printStudent(Student s) {
    std::cout << s.name << ' ' << s.age << '\n';
}

int main() {
    BST<Student> students;

    int option = 0;
    while (option != 5) {
        std::cout << "menu \n";
        std::cout << "1. Insert student\n";
        std::cout << "2. Search student\n";
        std::cout << "3. Remove student\n";
        std::cout << "4. Display inorder\n";
        std::cout << "5. Exit\n";
        std::cout << "Option: ";
        std::cin >> option;

        if (option == 1) {
            std::string name;
            int age;
            std::cout << "Student name: ";
            std::cin >> name;
            std::cout << "Student age: ";
            std::cin >> age;
            students.insert(Student(name, age));
            std::cout << "Student inserted!\n";
        }
        else if (option == 2) {
            std::string name;
            int age;
            std::cout << "Student name to search: ";
            std::cin >> name;
            std::cout << "Student age to search: ";
            std::cin >> age;
            if (students.search(Student(name, age))) {
                std::cout << "Student found!\n";
            } else {
                std::cout << "Student not found.\n";
            }
        }
        else if (option == 3) {
            std::string name;
            int age;
            std::cout << "Student name to remove: ";
            std::cin >> name;
            std::cout << "Student age to remove: ";
            std::cin >> age;
            students.remove(Student(name, age));
            std::cout << "Student removed (if existed).\n";
        }
        else if (option == 4) {
            std::cout << "Inorder display:\n";
            students.inorder(printStudent);
        }
        else if (option == 5) {
            std::cout << "Bye!\n";
        }
        else {
            std::cout << "Invalid option! Try again.\n";
        }
    }

    return 0;
}
