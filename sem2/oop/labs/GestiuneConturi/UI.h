//
// Created by Sonia Zagrean on 17.04.2025.
//

#ifndef UI_H
#define UI_H


#include <iostream>
#include <fstream>
#include <stack>
#include "Transaction.h"
#include "Service.h"

class UI {
private:
    Service service;
    std::stack<std::vector<Transaction>> history;

    void addTransaction();
    void modifyRemoveTransaction();
    void filterListTransactions() const;
    void showBalanceForDay() const;
    void undo();
    void printAllTransactions() const;
    static void displayMenu();

public:
    void run();
};


#endif //UI_H
