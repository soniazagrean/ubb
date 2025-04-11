#ifndef ATM_H
#define ATM_H

#include "Collection.h"
#include "Set.h"
#include "Transaction.h"

class ATM {
private:
    Collection<int> collection;
    Set<Transaction>* transactions;
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

#endif
