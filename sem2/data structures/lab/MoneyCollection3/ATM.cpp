#include "ATM.h"

#include <iostream>

#include "Transaction.h"
#include <map>

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
    transactions = new SortedSet<Transaction>(cmpByDate);
    transactionId = 1;

    loadInitialBills();
}

ATM::~ATM() {
    delete transactions;
}

void ATM::loadInitialBills() {
    collection.add(50);
    collection.add(50);
    collection.add(20);
    collection.add(20);
    collection.add(10);
    collection.add(10);
    collection.add(10);
    collection.add(10);
    collection.add(5);
    collection.add(5);
    collection.add(2);
    collection.add(2);
    collection.add(2);
    collection.add(2);
    collection.add(2);
    collection.add(2);
    collection.add(2);
    collection.add(2);
}

void ATM::addTransaction(int sum, int day, int month, int year) {
    const int MAX_BILLS = 100;
    int bills[MAX_BILLS];
    int billCount = collection.size();

    for (int i = 0; i < billCount; i++) {
        bills[i] = collection.getAt(i);
    }

    for (int i = 0; i < billCount - 1; i++) {
        for (int j = i + 1; j < billCount; j++) {
            if (bills[j] > bills[i]) {
                int temp = bills[i];
                bills[i] = bills[j];
                bills[j] = temp;
            }
        }
    }

    int usedValues[MAX_BILLS];
    int usedFreqs[MAX_BILLS];
    int usedSize = 0;

    int remaining = sum;

    for (int i = 0; i < billCount && remaining > 0; i++) {
        int val = bills[i];

        bool alreadyUsed = false;
        for (int j = 0; j < usedSize; j++) {
            if (usedValues[j] == val) {
                alreadyUsed = true;
                break;
            }
        }
        if (alreadyUsed) continue;

        int available = collection.nrOccurrences(val);
        int toUse = 0;

        while (available > 0 && remaining >= val) {
            remaining -= val;
            available--;
            toUse++;
        }

        if (toUse > 0) {
            usedValues[usedSize] = val;
            usedFreqs[usedSize] = toUse;
            usedSize++;
        }
    }

    if (remaining == 0) {
        for (int i = 0; i < usedSize; i++) {
            for (int j = 0; j < usedFreqs[i]; j++) {
                collection.remove(usedValues[i]);
            }
        }

        Bag<Money> usedBag;
        for (int i = 0; i < usedSize; i++) {
            Money m = {usedValues[i], usedFreqs[i]};
            usedBag.add(m);
        }

        Transaction t(transactionId++, sum, usedBag, usedSize, day, month, year);
        transactions->add(t);
        std::cout << "ok\n";
    }
    else {
        std::cout << "failed\n";
    }
}



void ATM::sortByDate() {
    SortedSet<Transaction>* sorted = new SortedSet<Transaction>(cmpByDate);
    for (int i = 0; i < transactions->size(); i++) {
        sorted->add(transactions->getAt(i));
    }
    delete transactions;
    transactions = sorted;
    std::cout << "transactions sorted by date.\n";
}

void ATM::sortBySum() {
    SortedSet<Transaction>* sorted = new SortedSet<Transaction>(cmpBySum);
    for (int i = 0; i < transactions->size(); i++) {
        sorted->add(transactions->getAt(i));
    }
    delete transactions;
    transactions = sorted;
    std::cout << "transactions sorted by sum.\n";
}

void ATM::sortByBills() {
    SortedSet<Transaction>* sorted = new SortedSet<Transaction>(cmpByBills);
    for (int i = 0; i < transactions->size(); i++) {
        sorted->add(transactions->getAt(i));
    }
    delete transactions;
    transactions = sorted;
    std::cout << "transactions sorted by number of bills.\n";
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