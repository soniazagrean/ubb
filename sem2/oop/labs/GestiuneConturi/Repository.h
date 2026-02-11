//
// Created by Sonia Zagrean on 03.04.2025.
//

#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "Transaction.h"

class Repository {
private:
    Transaction *t;
    int len;
    int capacity;
    void resize();

public:
    Repository();
    ~Repository();

    void createTransaction(const Transaction &transaction);
    Transaction readTransaction(int pos) const;
    void updateTransaction(int index, const Transaction &transaction);
    void deleteTransactionByIndex(int index);
    std::vector<Transaction> getAllTransactions() const;
    void setTransactions(const std::vector<Transaction>& vec);
    int getSize() const;
};




#endif //REPOSITORY_H
