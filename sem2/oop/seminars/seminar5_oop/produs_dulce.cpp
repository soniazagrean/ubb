#include "produs_dulce.h"
#include <iostream>
#include <cstring>
using namespace std;
ProdusDulce::ProdusDulce() {
    this->price = 0;
    this->name = nullptr;

}

ProdusDulce::ProdusDulce(const char *name, int price) {
    this->price = price;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

ProdusDulce::~ProdusDulce() {
    if (this->name!= nullptr) {
        delete[] this->name;
        this->name = nullptr;
    }
    this->price = 0;

}

char* ProdusDulce::getDescription() {
    const auto description = new char[strlen(this->name) + 15];
    strcpy(description, "Produs Dulce: ");
    strcat(description, this->name);
    return description;
}

int ProdusDulce::getPrice() {
    return this->price;
}

void ProdusDulce::display() {
    cout<<getDescription()<<"\n";
}