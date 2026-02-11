//
// Created by Sonia Zagrean on 15.05.2025.
//

#include "UI.h"
#include <iostream>

#include "ProductException.h"

void UI::addProdusDulce() {
    char description[10];
    int price;
    std::cout << "enter description: ";
    std::cin >> description;
    std::cout << " enter price: ";
    std::cin >> price;
    try {
        c.addProdusDulce(description, price);
    }
    catch (ProductException& e) {
        std::cout << e.what() << '\n';
    }
}

void UI::addProdusSarat() {
    char description[10];
    int price;
    int gramsSalt;
    std::cout << "enter description: ";
    std::cin >> description;
    std::cout << " enter price: ";
    std::cin >> price;
    std::cout << "enter grams salt: ";
    std::cin >> gramsSalt;
    try {
        c.addProdusSarat(description, price, gramsSalt);
    }
    catch (ProductException& e) {
        std::cout << e.what() << '\n';
    }
}

void UI::showAll() {
    vector<Produs*> produse = c.getAll();
    for (auto &produs: produse)
        std::cout << produs->getDescription() << ' ' << produs->getPrice() << '\n';
}

void UI::run() {
}
