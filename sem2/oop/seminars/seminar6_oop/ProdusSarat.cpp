#include "ProdusSarat.h"

#include <iostream>
#include <ostream>
using namespace std;

ProdusSarat::ProdusSarat(const string& d, int p, int s) {
    this->descriere = d;
    this->pret = p;
    this->grameSare = s;
}

string ProdusSarat::getDescriere() {
    return "Produs Sarat: " + descriere;
}

int ProdusSarat::getPret() {
    return pret;
}

void ProdusSarat::display() {
    cout << "Produs Sarat: " << descriere << endl;
}

int ProdusSarat::getGrameSare() {
    return grameSare;
}