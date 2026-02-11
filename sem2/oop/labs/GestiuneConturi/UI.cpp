//
// Created by Sonia Zagrean on 17.04.2025.
//

#include "UI.h"
#include "Tests.h"

void UI::addTransaction() {
    int opt;
    std::cout << "1. add transaction (today)\n";
    std::cout << "2. add custom transaction\n";
    std::cout << "option: ";
    std::cin >> opt;

    history.push(service.getAll());  // for undo

    if (opt == 1) {
        time_t tt;
        time(&tt);
        tm* ti = localtime(&tt);
        unsigned int sum;
        char type[10], description[10];
        std::cout << "enter sum, type, description: ";
        std::cin >> sum >> type >> description;
        Transaction Ts(ti->tm_mday, sum, type, description);
        service.add(Ts);
    }
    else if (opt == 2) {
        Transaction Ts;
        std::cin >> Ts;
        service.add(Ts);
    }
}

void UI::modifyRemoveTransaction() {
    int opt;
    std::cout << "1. remove by day\n";
    std::cout << "2. remove between days\n";
    std::cout << "3. remove by type\n";
    std::cout << "4. replace sum\n";
    std::cout << "option: ";
    std::cin >> opt;

    history.push(service.getAll());

    if (opt == 1) {
        int day;
        std::cout << "enter day: ";
        std::cin >> day;
        service.removeByExactDate(day);
    }
    else if (opt == 2) {
        int day1, day2;
        std::cout << "enter start and end days: ";
        std::cin >> day1 >> day2;
        service.removeByDateRange(day1, day2);
    }
    else if (opt == 3) {
        char type[10];
        std::cout << "enter type: ";
        std::cin >> type;
        service.removeByType(type);
    }
    else if (opt == 4) {
        int date;
        unsigned int sum;
        char type[10], description[20];
        std::cout << "enter date, type, description, new sum: ";
        std::cin >> date >> type >> description >> sum;
        service.replaceTransaction(date, type, description, sum);
    }
}

void UI::filterListTransactions() const {
    int opt;
    std::cout << "1. list all\n";
    std::cout << "2. list by type\n";
    std::cout << "3. list by sum greater than\n";
    std::cout << "4. list by sum equal to\n";
    std::cout << "option: ";
    std::cin >> opt;

    std::vector<Transaction> vec;
    if (opt == 1) {
        vec = service.getAll();
    }
    else if (opt == 2) {
        char type[10];
        std::cout << "enter type: ";
        std::cin >> type;
        vec = service.filterTransactions(type, 0, 0);
    }
    else if (opt == 3) {
        unsigned int sum;
        std::cout << "enter sum: ";
        std::cin >> sum;
        vec = service.filterTransactions("", sum, 0);
    }
    else if (opt == 4) {
        unsigned int sum;
        std::cout << "enter sum: ";
        std::cin >> sum;
        vec = service.filterTransactions("", 0, sum);
    }

    for (const auto& tr : vec)
        std::cout << tr;
}

void UI::showBalanceForDay() const {
    int date;
    std::cout << "enter day: ";
    std::cin >> date;

    std::vector<Transaction> all = service.getAll();
    unsigned int inSum = 0, outSum = 0;

    for (const auto& tr : all) {
        if (tr.getDate() == date) {
            if (strcmp(tr.getType(), "in") == 0) inSum += tr.getSum();
            if (strcmp(tr.getType(), "out") == 0) outSum += tr.getSum();
        }
    }

    std::cout << "balance for day " << date << ": " << (inSum - outSum) << '\n';
}

void UI::undo() {
    if (!history.empty()) {
        std::vector<Transaction> prev = history.top();
        history.pop();
        service.setTransactions(prev);
        std::cout << "undo successful!\n";
    }
    else {
        std::cout << "nothing to undo.\n";
    }
}

void UI::printAllTransactions() const {
    std::vector<Transaction> all = service.getAll();
    for (const auto& tr : all)
        std::cout << tr;
}

void UI::displayMenu() {
    std::cout << "MENU:\n";
    std::cout << "1. add transaction\n";
    std::cout << "2. modify/remove transaction\n";
    std::cout << "3. filter/list transactions\n";
    std::cout << "4. show transaction balance for a day\n";
    std::cout << "5. undo\n";
    std::cout << "6. print all transactions\n";
    std::cout << "7. exit\n";
    std::cout << "option: ";
}

void UI::run() {
    testAll();

    Transaction t;
    std::ifstream fin("../transactions.txt");
    while (fin >> t) {
        service.add(t);
    }

    int option;
    do {
        displayMenu();
        std::cin >> option;

        switch (option) {
            case 1:
                addTransaction();
                break;
            case 2:
                modifyRemoveTransaction();
                break;
            case 3:
                filterListTransactions();
                break;
            case 4:
                showBalanceForDay();
                break;
            case 5:
                undo();
                break;
            case 6:
                printAllTransactions();
                break;
            case 7:
                std::cout << "bye\n";
                break;
            default:
                std::cout << "invalid option!\n";
        }

    } while (option != 7);
}
