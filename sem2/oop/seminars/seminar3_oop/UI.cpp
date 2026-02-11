//
// Created by Sonia Zagrean on 03.04.2025.
//

#include "UI.h"

UI::~UI() = default;

void UI::showAll() const {
    std::vector<Student> students = service.getStudents();
    for (auto& i : students)
        std::cout << i.getAge() << ' ' << i.getName() << '\n';
}
