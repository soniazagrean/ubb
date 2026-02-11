//
// Created by Sonia Zagrean on 03.04.2025.
//

#include "Service.h"


void Service::add(Transaction &t) {
    r.createTransaction(t);
}

void Service::removeByDateRange(int startDate, int endDate) {
    std::vector<Transaction> all = r.getAllTransactions();
    for (int i = all.size() - 1; i >= 0; --i)
        if (all[i].getDate() >= startDate && all[i].getDate() <= endDate)
            r.deleteTransactionByIndex(i);
}

void Service::removeByExactDate(int date) {
    std::vector<Transaction> all = r.getAllTransactions();
    for (int i = all.size() - 1; i >= 0; --i)
        if (all[i].getDate() == date)
            r.deleteTransactionByIndex(i);
}

void Service::removeByType(const char type[]) {
    std::vector<Transaction> all = r.getAllTransactions();
    for (int i = all.size() - 1; i >= 0; --i)
        if (strcmp(all[i].getType(), type) == 0)
            r.deleteTransactionByIndex(i);
}

void Service::replaceTransaction(int date, const char type[], const char description[], unsigned int newSum) {
    std::vector<Transaction> all = r.getAllTransactions();
    for (int i = 0; i < all.size(); ++i) {
        if (all[i].getDate() == date &&
            strcmp(all[i].getType(), type) == 0 &&
            strcmp(all[i].getDescription(), description) == 0) {
                Transaction updated = all[i];
                updated.setSum(newSum);
                r.updateTransaction(i, updated);
                return;
            }
    }
}

std::vector<Transaction> Service::filterTransactions(const char type[], unsigned int minSum, unsigned int exactSum) const {
    std::vector<Transaction> result;
    for (const auto &tr : r.getAllTransactions()) {
        if ((strcmp(type, "") == 0 || strcmp(tr.getType(), type) == 0) &&
            (minSum == 0 || tr.getSum() > minSum) &&
            (exactSum == 0 || tr.getSum() == exactSum))
                result.push_back(tr);
    }
    return result;
}

std::vector<Transaction> Service::getAll() const {
    return r.getAllTransactions();
}

int Service::Size() const {
    return r.getSize();
}

void Service::setTransactions(const std::vector<Transaction> &newList) {
    r.setTransactions(newList);
}

