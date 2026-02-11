//
// Created by Sonia Zagrean on 03.05.2025.
//

#include "UI.h"
#include "Tests.cpp"

void UI::run() {
    testProduct();
    testRepo();
    testService();
    testRepoFile();
    int option;
    do {
        std::cout << "1. add product\n";
        std::cout << "2. show all\n";
        std::cout << "3. buy \n";
        std::cout << "4. update\n";
        std::cout << "5. exit\n";
        std::cout << "option = ";
        std::cin >> option;
        if (option == 1) {
            int c;
            std::string n;
            double p;
            std::cout << "code: "; std::cin >> c;
            std::cout << "name: "; std::cin >> n;
            std::cout << "price: "; std::cin >> p;
            service.add(c, n, p);
        }
        if (option == 2)
            for (const auto& prod : service.get())
                std::cout << prod.getCode() << ": " << prod.getName() << " - " << prod.getPrice() << " lei\n";


        if (option == 3) {
            int code;
            double money;
            std::cout << "Enter product code: ";
            std::cin >> code;
            std::cout << "Insert money: ";
            std::cin >> money;

            std::vector<Money> change = service.buyProduct(code, money);

            if (change.empty())
                std::cout << "failed\n";
            else {
                std::cout << "done\n";
                for (const auto& m : change)
                    std::cout << m.freq << " x " << m.val << " lei\n";
            }
        }

        if (option == 4) {
            int position;
            std::cout << "position = ";
            std::cin >> position;
            int c;
            std::string n;
            double p;
            std::cout << "code: "; std::cin >> c;
            std::cout << "name: "; std::cin >> n;
            std::cout << "price: "; std::cin >> p;
            service.update(position, Product(c, n, p));

        }

    } while (option != 5);
}

