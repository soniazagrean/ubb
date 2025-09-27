#include "Transaction.h"
#include <iostream>

Transaction::Transaction() : id(0), sum(0), len(0), bills() {}

Transaction::Transaction(int id, int sum, const Bag<Money> &bills, int len, int day, int month, int year) : id(id), sum(sum), bills(bills), len(len), date(day, month, year){}

Transaction::Transaction(int id, int sum, const Bag<Money>& bills, int day, int month, int year)
    : id(id), sum(sum), bills(bills), date(day, month, year) {
    len = bills.size();
}

Transaction::Transaction(const Transaction& other)
    : id(other.id), sum(other.sum), len(other.len), date(other.date), bills(other.bills) {}

Transaction& Transaction::operator=(const Transaction& other) {
    if (this != &other) {
        id = other.id;
        sum = other.sum;
        len = other.len;
        date = other.date;
        bills = other.bills;
    }
    return *this;
}


Transaction::~Transaction() = default;

int Transaction::getSum() const {
    return sum;
}

int Transaction::getID() const {
    return id;
}

int Transaction::getBillCount() const {
    int total = 0;
    for (int i = 0; i < len; i++) {
        total += bills.getAt(i).freq;
    }
    return total;
}

Date Transaction::getDate() const {
    return date;
}

void Transaction::print() const {
    std::cout << "ID: " << id << " Sum: " << sum << " Date: " << date.day << "/" << date.month << "/" << date.year << "\nBills: ";
    for (int i = 0; i < bills.size(); i++)
        if (bills.getAt(i).freq > 0)
            std::cout << bills.getAt(i).freq << "x" << bills.getAt(i).value << " ";

    std::cout << "\n";
}

bool Transaction::operator==(const Transaction& other) const {
    return id == other.id;
}
