//
// Created by Sonia Zagrean on 31.05.2025.
//

#pragma once

struct Student {
    std::string name;
    int age;

    Student(std::string name, int age): name(name), age(age) {}
    bool operator<(const Student& other) const {
        if (name != other.name)
            return name < other.name;
        return age < other.age;
    }

    bool operator==(const Student& other) const {
        return name == other.name && age == other.age;
    }
    bool operator>(const Student& other) const {
        return other < *this;
    }
};
