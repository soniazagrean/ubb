#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <vector>

struct pairTransaction {
    int elem;
    int freq;
};

class Transaction {
private:
    int idTransaction;
    int sum;
    std::vector<pairTransaction> used;

public:
    Transaction(int idTransaction, int sum, std::vector<pairTransaction> used);
    void printTransaction();
};

#endif
