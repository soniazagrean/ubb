#include <iostream>
#include <string>
#include <set>
#include "Map.h"

void init_menu(Map<std::string, std::string>& menu) {
    menu.put("File", "nivel 0");
    menu.put("Home", "nivel 0");
    menu.put("View", "nivel 0");
    menu.put("Save", "File");
    menu.put("Print", "File");
    menu.put("One Page", "View");
}

void add(Map<std::string, std::string>& menu) {
    std::string key, value;
    std::cin.ignore();

    std::cout << "type parent option (ex: File, View, nivel 0): ";
    std::getline(std::cin, value);

    std::cout << "type option name (ex: Save, Export, Print): ";
    std::getline(std::cin, key);

    menu.put(key, value);
}

void display(const Map<std::string, std::string>& menu) {
    std::string key;
    std::cin.ignore();
    std::cout << "type option (ex: File, Home, View): ";
    std::getline(std::cin, key);

    bool found = false;
    for (auto& i : menu.get_keys()) {
        if (menu.get(i) == key) {
            std::cout << key << " -> " << i << '\n';
            found = true;
        }
    }

    if (!found)
        std::cout << "there are no submenus for this option\n";
}

int main() {
    int option = 0;
    Map<std::string, std::string> menu;
    init_menu(menu);

    while (option != 3) {
        std::cout << "1. Add\n";
        std::cout << "2. Display\n";
        std::cout << "3. Exit\n";
        std::cout << "option (1, 2 or 3) = ";
        std::cin >> option;

        switch (option) {
            case 1:
                add(menu);
            break;
            case 2:
                display(menu);
            break;
            case 3:
                std::cout << "bye\n";
            break;
            default:
                std::cout << "invalid option\n";
        }
    }

    return 0;
}
