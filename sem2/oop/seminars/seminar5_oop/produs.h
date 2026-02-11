#ifndef PRODUS_H
#define PRODUS_H

class Produs {
public:
    virtual char* getDescription() = 0;
    virtual int getPrice() = 0;
    virtual void display() = 0;
};
#endif
