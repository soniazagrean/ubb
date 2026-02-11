//
// Created by Sonia Zagrean on 03.04.2025.
//

#ifndef SERVICE_H
#define SERVICE_H

#include "Repository.h"

class Service {
private:
    Repository r;

public:
    void add(Transaction &t);
    void removeByDateRange(int startDate, int endDate);
    void removeByType(const char type[]);
    void removeByExactDate(int date);
    void replaceTransaction(int date, const char type[], const char description[], unsigned int newSum);
    std::vector<Transaction> filterTransactions(const char type[], unsigned int minSum, unsigned int exactSum) const;
    std::vector<Transaction> getAll() const;
    int Size() const;
    void setTransactions(const std::vector<Transaction>& newList);
};



#endif //SERVICE_H
