#include "Transaction.h"
#include <iostream>

Transaction::Transaction() : id(0), sum(0), len(0), bills(nullptr) {}

Transaction::Transaction(int id, int sum, pairT<int>* bills, int len, int day, int month, int year) : id(id), sum(sum), len(len), date(day, month, year) {
    this->bills = new pairT<int>[len];
    for (int i = 0; i < len; i++)
        this->bills[i] = bills[i];
}

Transaction::Transaction(const Transaction& other) : id(other.id), sum(other.sum), len(other.len), date(other.date) {
    bills = new pairT<int>[len];
    for (int i = 0; i < len; i++)
        bills[i] = other.bills[i];
}

Transaction& Transaction::operator=(const Transaction& other) {
    if (this != &other) {
        delete[] bills;
        id = other.id;
        sum = other.sum;
        len = other.len;
        date = other.date;
        bills = new pairT<int>[len];
        for (int i = 0; i < len; i++) {
            bills[i] = other.bills[i];
        }
    }
    return *this;
}

Transaction::~Transaction() {
    delete[] bills;
}

int Transaction::getSum() const {
    return sum;
}

int Transaction::getID() const {
    return id;
}

int Transaction::getBillCount() const {
    int total = 0;
    for (int i = 0; i < len; i++) {
        total += bills[i].freq;
    }
    return total;
}

Date Transaction::getDate() const {
    return date;
}

void Transaction::print() const {
    std::cout << "ID: " << id << " Sum: " << sum << " Date: " << date.day << "/" << date.month << "/" << date.year << "\nBills: ";
    for (int i = 0; i < len; i++)
        if (bills[i].freq > 0)
            std::cout << bills[i].freq << "x" << bills[i].elem << " ";

    std::cout << "\n";
}

bool Transaction::operator==(const Transaction& other) const {
    return id == other.id;
}
