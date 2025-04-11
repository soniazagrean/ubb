#include "ATM.h"
#include <iostream>

int main() {
    ATM atm;
    int option;

    do {
        std::cout << "ATM SIMULATOR\n";
        std::cout << "1. ATM sold\n";
        std::cout << "2. Add new transaction\n";
        std::cout << "3. View all transactions\n";
        std::cout << "4. Sort transactions by date\n";
        std::cout << "5. Sort transactions by amount\n";
        std::cout << "6. Sort transactions by number of bills\n";
        std::cout << "7. Exit\n";
        std::cout << "option: ";

        std::cin >> option;

        switch (option) {
            case 1:
                atm.printSold();
                break;

            case 2:
                int sum, day, month, year;
                std::cout << "withdraw amount: ";
                std::cin >> sum;
                std::cout << "date (day month year): ";
                std::cin >> day >> month >> year;
                atm.addTransaction(sum, day, month, year);
                break;

            case 3:
                atm.printTransactions();
                break;

            case 4:
                atm.sortByDate();
                atm.printTransactions();
                break;

            case 5:
                atm.sortBySum();
                atm.printTransactions();
                break;

            case 6:
                atm.sortByBills();
                atm.printTransactions();
                break;

            case 7:
                std::cout << "bye\n";
                break;
        }

    } while (option != 7);

    return 0;
}