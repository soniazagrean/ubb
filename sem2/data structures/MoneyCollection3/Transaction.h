#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "Collection.h"

struct Date {
    int day, month, year;
    Date() : day(0), month(0), year(0) {}
    Date(int d, int m, int y) : day(d), month(m), year(y) {}
};

class Transaction {
private:
    int id;
    int sum;
    int len;
    Date date;
    pairT<int>* bills;

public:
    Transaction();
    Transaction(int id, int sum, pairT<int>* bills, int len, int day, int month, int year);
    Transaction(const Transaction& other);
    Transaction& operator=(const Transaction& other);
    ~Transaction();

    int getSum() const;
    int getID() const;
    int getBillCount() const;
    Date getDate() const;
    void print() const;

    bool operator==(const Transaction& other) const;
};

#endif