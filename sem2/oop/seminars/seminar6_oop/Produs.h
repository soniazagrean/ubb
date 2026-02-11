#ifndef PRODUS_H
#define PRODUS_H

#include <string>
using namespace std;

class Produs {
public:
    virtual string getDescriere() = 0;
    virtual int getPret() = 0;
    virtual void display() = 0;
};

#endif
