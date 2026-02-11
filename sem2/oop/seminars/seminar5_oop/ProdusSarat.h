#ifndef PRODUSSARAT_H
#define PRODUSSARAT_H
#include "produs.h"
class ProdusSarat: public Produs {
private:
    char* name;
    int price;
    int grameSalt;
public:
    ProdusSarat();
    ProdusSarat(char* name, int price, int grameSalt);
    ~ProdusSarat();
    char* getDescription() override;
    int getPrice() override;
    int getGrameSalt();
    void display() override;
};

#endif
