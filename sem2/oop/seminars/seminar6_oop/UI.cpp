#include "UI.h"
#include <iostream>
#include <string>

#include "ProductException.h"
using namespace std;

void UI::addProdusDulce() {
    string desc;
    int price;

    cout << "Enter description: ";
    cin>>desc;

    cout << "Enter price: ";
    cin >> price;

    try {
        service.addProdusDulce(desc, price);
        cout << "Produs dulce added successfully.\n";
    } catch (const ProductException& e) {
        cout << "Error: " << e.what() << endl;
    }
}

void UI::addProdusSarat() {
    string desc;
    int price, saltiness;

    cout << "Enter description: ";
    cin>>desc;

    cout << "Enter price: ";
    cin >> price;

    cout << "Enter saltiness level: ";
    cin >> saltiness;

    try {
        service.addProdusSarat(desc, price, saltiness);
        cout << "Produs sarat added successfully.\n";
    } catch (const ProductException& e) {
        cout << "Error: " << e.what() << endl;
    }
}

void UI::showAllProducts() {
    auto products = service.getProducts();
    if (products.empty()) {
        cout << "No products available.\n";
        return;
    }

    cout << "Product list:\n";
    for (const auto& produs : products) {
        cout << produs->getDescriere() << endl;
    }
}

void UI::run() {
    while (true) {
        cout << "\n=== Product Menu ===\n";
        cout << "1. Add Produs Dulce\n";
        cout << "2. Add Produs Sarat\n";
        cout << "3. Show All Products\n";
        cout << "0. Exit\n";
        cout << "Choose an option: ";

        int option;
        cin >> option;

        switch (option) {
            case 1:
                addProdusDulce();
            break;
            case 2:
                addProdusSarat();
            break;
            case 3:
                showAllProducts();
            break;
            case 0:
                cout << "Exiting...\n";
            return;
            default:
                cout << "Invalid option. Try again.\n";
        }
    }
}
