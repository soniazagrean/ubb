#include "ATM.h"
#include <iostream>

bool cmpBySum(const Transaction& a, const Transaction& b) {
    if (a.getSum() != b.getSum())
        return a.getSum() < b.getSum();
    return a.getID() < b.getID();
}

bool cmpByBills(const Transaction& a, const Transaction& b) {
    if (a.getBillCount() != b.getBillCount())
        return a.getBillCount() < b.getBillCount();
    return a.getID() < b.getID();
}

bool cmpByDate(const Transaction& a, const Transaction& b) {
    if (a.getDate().year != b.getDate().year)
        return a.getDate().year < b.getDate().year;
    if (a.getDate().month != b.getDate().month)
        return a.getDate().month < b.getDate().month;
    if (a.getDate().day != b.getDate().day)
        return a.getDate().day < b.getDate().day;
    return a.getID() < b.getID();
}


ATM::ATM() {
    transactions = new Set(cmpByDate);
    transactionId = 1;
    loadInitialBills();
}

ATM::~ATM() {
    delete transactions;
}

void ATM::loadInitialBills() {
    collection.loadBills();
}

void ATM::addTransaction(int sum, int day, int month, int year) {
    int remaining = sum;
    pairT<int>* used = new pairT<int>[collection.size()];
    int count = 0;

    int tempSize = collection.size();
    int* tempBills = new int[tempSize];

    for (int i = 0; i < tempSize; i++) {
        tempBills[i] = collection.getAt(i);
    }

    for (int i = 0; i < tempSize; i++) {
        for (int j = i + 1; j < tempSize; j++) {
            if (tempBills[i] < tempBills[j]) {
                std::swap(tempBills[i], tempBills[j]);
            }
        }
    }

    for (int i = 0; i < tempSize; ++i) {
        int bill = tempBills[i];
        int available = collection.nrOccurrences(bill);
        int take = std::min(remaining / bill, available);

        if (take > 0) {
            used[count++] = {bill, take};
            collection.remove(bill, take);
            remaining -= take * bill;
        }
    }

    delete[] tempBills;

    if (remaining == 0) {
        Transaction t(transactionId++, sum, used, count, day, month, year);
        transactions->add(t);
        std::cout << "transaction added successfully!\n";
    }
    else {
        std::cout << "incorrect\n";
        for (int i = 0; i < count; ++i) {
            for (int j = 0; j < used[i].freq; j++) {
                collection.add(used[i].elem);
            }
        }
    }

    delete[] used;
}

void ATM::sortByDate() {
    Set<Transaction>* sorted = new Set(cmpByDate);

    for (int i = 0; i < transactions->size(); i++) {
        sorted->add(transactions->getAt(i));
    }
    delete transactions;
    transactions = sorted;
    std::cout << "sorted by date.\n";
}

void ATM::sortBySum() {
    Set<Transaction>* sorted = new Set(cmpBySum);

    for (int i = 0; i < transactions->size(); i++) {
        sorted->add(transactions->getAt(i));
    }
    delete transactions;
    transactions = sorted;
    std::cout << "sorted by sum.\n";
}

void ATM::sortByBills() {
    Set<Transaction>* sorted = new Set(cmpByBills);

    for (int i = 0; i < transactions->size(); i++) {
        sorted->add(transactions->getAt(i));
    }
    delete transactions;
    transactions = sorted;

    std::cout << "sorted by number of bills.\n";
}

void ATM::printSold() {
    std::cout << "sold:\n";
    collection.printCollection();
}

void ATM::printTransactions() const {
    std::cout << "transactions: \n";
    for (int i = 0; i < transactions->size(); i++) {
        transactions->getAt(i).print();
    }
}