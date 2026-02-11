//
// Created by Sonia Zagrean on 03.04.2025.
//

#include "Repository.h"

Repository::Repository() {
    len = 0;
    capacity = 10;
    t = new Transaction[capacity];
}

Repository::~Repository() {
    delete[] t;
}


void Repository::resize() {
    capacity *= 2;
    Transaction* newT = new Transaction[capacity];
    for (int i = 0; i < len; ++i)
        newT[i] = t[i];
    delete[] t;
    t = newT;
}

void Repository::createTransaction(const Transaction &transaction) {
    if (len == capacity) resize();
    t[len++] = transaction;
}

Transaction Repository::readTransaction(int pos) const {
    return t[pos];
}

void Repository::updateTransaction(int index, const Transaction &transaction) {
    if (index >= 0 && index < len)
        t[index] = transaction;
}

void Repository::deleteTransactionByIndex(int index) {
    if (index < 0 || index >= len)
        return;
    for (int j = index + 1; j < len; ++j)
        t[j - 1] = t[j];
    len--;
}

std::vector<Transaction> Repository::getAllTransactions() const {
    std::vector<Transaction> vec;
    for (int i = 0; i < len; ++i)
        vec.push_back(t[i]);
    return vec;
}

void Repository::setTransactions(const std::vector<Transaction>& vec) {
    delete[] t;
    capacity = vec.size() + 10;
    len = vec.size();
    t = new Transaction[capacity];
    for (int i = 0; i < len; ++i)
        t[i] = vec[i];
}

int Repository::getSize() const {
    return len;
}

