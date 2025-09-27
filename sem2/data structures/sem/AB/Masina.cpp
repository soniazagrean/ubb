//
// Created by Sonia Zagrean on 13.05.2025.
//

#include "Masina.h"

Masina::Masina(int id, int an, std::string nume) : id(id), an(an), nume(nume) {}

Masina::~Masina() = default;

int Masina::getID() {
    return id;
}

int Masina::getAn() {
    return an;
}

std::string Masina::getNume() {
    return nume;
}
