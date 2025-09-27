#ifndef ATM_H
#define ATM_H

#include "Collection.h"
#include "Transaction.h"
#include <vector>

class ATM {
private:
    int idTransaction = 0;
    Collection deposit;
    std::vector<Transaction> previousTransactions;

public:
    ATM();
    bool Withdraw(int sum);
    void displayTransaction();
};

#endif
