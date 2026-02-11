//
// Created by Sonia Zagrean on 19.05.2025.
//

#include "UI.h"

#include <iostream>

void UI::addUi() {
    int c;
    std::string n;
    int p;
    std::cout << "code: "; std::cin >> c;
    std::cout << "name: "; std::cin >> n;
    std::cout << "price: "; std::cin >> p;
    try {
        service.addProduct(Product(c, n, p));
        std::cout << "product added successfully.\n";
    }
    catch (const ValidationErrorsException& e) {
        std::cout << "validation errors:\n" << e.what();
    }
    catch (const ValidationException& e) {
        std::cout << "validation error: " << e.what() << "\n";
    }
    catch (const std::exception& e) {
        std::cout << "error: " << e.what() << "\n";
    }
}

void UI::removeUi() {
    int c;
    std::string n;
    int p;
    std::cout << "code: "; std::cin >> c;
    std::cout << "name: "; std::cin >> n;
    std::cout << "price: "; std::cin >> p;
    try {
        service.removeProduct(Product(c, n, p));
        std::cout << "product removed successfully.\n";
    }
    catch (const ValidationErrorsException& e) {
        std::cout << "validation errors:\n" << e.what();
    }
    catch (const ValidationException& e) {
        std::cout << "validation error: " << e.what() << "\n";
    }
    catch (const std::exception& e) {
        std::cout << "error: " << e.what() << "\n";
    }
}

void UI::updateUi() {
    int position;
    std::cout << "position = ";
    std::cin >> position;
    int c;
    std::string n;
    int p;
    std::cout << "code: "; std::cin >> c;
    std::cout << "name: "; std::cin >> n;
    std::cout << "price: "; std::cin >> p;
    try {
        service.updateProduct(position, Product(c, n, p));
        std::cout << "product updated successfully.\n";
    }
    catch (const ValidationErrorsException& e) {
        std::cout << "validation errors:\n" << e.what();
    }
    catch (const ValidationException& e) {
        std::cout << "validation error: " << e.what() << "\n";
    }
    catch (const std::exception& e) {
        std::cout << "error: " << e.what() << "\n";
    }
}

void UI::buyUi() {
    int code;
    double money;
    std::cout << "Enter product code: ";
    std::cin >> code;
    std::cout << "Insert money: ";
    std::cin >> money;

    try {
        std::vector<Money> change = service.buyProduct(code, money);
        if (change.empty())
            std::cout << "failed\n";
        else {
            std::cout << "done\n";
            for (const auto& m : change)
                std::cout << m.freq << " x " << m.val << " lei\n";
        }
    } catch (std::exception& e) {
        std::cout << "error: " << e.what() << '\n';
    }

}

void UI::getUi() {
    std::vector<Product> result = service.getAll();
    for (auto& i: result)
        std::cout << i.getCode() << ' ' << i.getName() << ' ' << i.getPrice() << '\n';
}


void UI::run() {
    int option;
    while (true) {
        std::cout << "1. add product\n";
        std::cout << "2. remove product\n";
        std::cout << "3. update product\n";
        std::cout << "4. show all\n";
        std::cout << "5. buy\n";
        std::cout << "6. exit\n";
        std::cout << "option = ";
        std::cin >> option;
        switch (option) {
            case 1:
                addUi();
                break;
            case 2:
                removeUi();
                break;
            case 3:
                updateUi();
                break;
            case 4:
                getUi();
                break;
            case 5:
                buyUi();
                break;
            case 6:
                std::cout << "bye";
                exit(0);
        }
    }
}
