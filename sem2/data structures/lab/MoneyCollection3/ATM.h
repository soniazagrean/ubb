#pragma once
#include "Bag.h"
#include "SortedSet.h"
#include "Transaction.h"

class ATM {
private:
    Bag<int> collection;
    SortedSet<Transaction>* transactions;
    int transactionId;

public:
    ATM();
    ~ATM();

    void loadInitialBills();
    void addTransaction(int sum, int day, int month, int year);

    void sortByDate();
    void sortBySum();
    void sortByBills();

    void printSold();
    void printTransactions() const;
};

