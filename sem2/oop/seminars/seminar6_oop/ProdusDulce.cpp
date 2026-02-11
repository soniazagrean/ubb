#include "ProdusDulce.h"

#include <iostream>
#include <ostream>
using namespace std;

ProdusDulce::ProdusDulce(const string& d, int p) {
    this->descriere = d;
    this->pret = p;
}

string ProdusDulce::getDescriere() {
    return "Produs Dulce: " + descriere;
}

int ProdusDulce::getPret() {
    return pret;
}

void ProdusDulce::display() {
    cout << getDescriere() << endl;
}
