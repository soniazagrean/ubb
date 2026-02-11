#ifndef PRODUSDULCE_H
#define PRODUSDULCE_H

#include "Produs.h"
using namespace std;

class ProdusDulce : public Produs {
private:
    string descriere;
    int pret;
public:
    ProdusDulce(const string& d, int p);
    string getDescriere() override;
    int getPret() override;
    void display() override;
};

#endif