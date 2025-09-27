#pragma once
#include <iostream>
#include "Bag.h"

struct Date {
    int day, month, year;
    Date() : day(0), month(0), year(0) {}
    Date(int d, int m, int y) : day(d), month(m), year(y) {}
};

struct Money {
    int value;
    int freq;

    bool operator==(const Money& other) const {
        return value == other.value;
    }

    bool operator<(const Money& other) const {
        return value < other.value;
    }
};

inline std::ostream& operator<<(std::ostream& os, const Money& m) {
    os << m.value << "(" << m.freq << ")";
    return os;
}

class Transaction {
private:
    int id;
    int sum;
    int len;
    Date date;
    Bag<Money> bills;

public:
    Transaction();
    Transaction(int id, int sum, const Bag<Money>& bills, int len, int day, int month, int year);
    Transaction(int id, int sum, const Bag<Money>& bills, int day, int month, int year);
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
