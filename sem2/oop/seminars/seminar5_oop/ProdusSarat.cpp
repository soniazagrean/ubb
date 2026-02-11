#include "ProdusSarat.h"
#include <iostream>
#include <ostream>
#include <cstring>

using namespace std;

ProdusSarat::ProdusSarat() {
    this-> name = nullptr;
    this-> price = 0;
    this-> grameSalt = 0;
}

ProdusSarat::ProdusSarat(char *name, int price, int grameSalt) {
    this-> name = new char[strlen(name)+1];
    strcpy(this-> name, name);
    this-> price = price;
    this-> grameSalt = grameSalt;
}

ProdusSarat::~ProdusSarat() {
    if (this-> name != nullptr) {
        delete [] this-> name;
        this-> name = nullptr;
    }
    this->price = 0;
    this-> grameSalt = 0;
}

char *ProdusSarat::getDescription() {
    const auto description = new char[strlen(this->name) + 20];
    strcpy(description, "Produs Sarat: ");
    strcat(description, this->name);
    return description;
}
int ProdusSarat::getPrice() {
    return this->price;
}

int ProdusSarat::getGrameSalt() {
    return this->grameSalt;
}

void ProdusSarat::display() {
    cout << getDescription() << "\n";
}