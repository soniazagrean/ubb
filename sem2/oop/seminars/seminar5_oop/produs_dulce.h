#ifndef PRODUS_DULCE_H
#define PRODUS_DULCE_H
#include "produs.h"

class ProdusDulce: public Produs {
private:
    char* name;
    int price;
public:
    ProdusDulce();
    ProdusDulce(const char* name, int price);
    ~ProdusDulce();
    char* getDescription() override;
    int getPrice() override;
    void display() override;
};
#endif
