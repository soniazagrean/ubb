#ifndef PRODUSSARAT_H
#define PRODUSSARAT_H
#include <string>
#include "Produs.h"

using namespace std;

class ProdusSarat: public Produs {
private:
    string descriere;
    int pret;
    int grameSare;
public:
    ProdusSarat(const string& d, int p, int s);
    string getDescriere() override;
    int getPret() override;
    void display() override;
    int getGrameSare();
};

#endif
