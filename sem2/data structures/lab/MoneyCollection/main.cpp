#include <iostream>
#include "ATM.h"
#include <fstream>
#include <filesystem>

int main() {
    ATM atm;
    int option;
    // Collection c;
    // c.printCollection();

    do {
        std::cout << "ATM\n";
        std::cout << "1. Withdraw money\n";
        std::cout << "2. Transaction\n";
        std::cout << "3. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> option;

        switch (option) {
            case 1: {
                int sum;
                std::cout << "sum: ";
                std::cin >> sum;
                atm.Withdraw(sum);
                break;
            }
            case 2:
                atm.displayTransaction();
            break;
        }
    } while (option != 3);




    return 0;
}
