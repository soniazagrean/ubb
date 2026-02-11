//
// Created by Sonia Zagrean on 31.05.2025.
//

#ifndef UI_H
#define UI_H
#include <iostream>

#include "Service.h"


class UI {
private:
    Service& s;

    void add() {
        int id, capacity;
        std::string type;
        std::cout << "id = ";
        std::cin >> id;
        std::cout << "capacity = ";
        std::cin >> capacity;
        std::cout << "type = ";
        std::cin >> type;
        if (type == "Autobuz")
            s.add(new Autobuz(id, capacity));
        else
            s.add(new Tramvai(id, capacity));
        for (auto* i : s.get())
            std::cout << i->getId() << ' ' << i->getCapacitate() << ' ' << i->getTip() << '\n';
    }

    void listCap() {
        int minCap;
        std::cout << "minimum capacity: ";
        std::cin >> minCap;
        auto filtered = s.filterCap(minCap);
        for (auto* i : filtered)
            std::cout << i->getId() << " " << i->getCapacitate() << " " << i->getTip() << '\n';

    }

    void available() {
        auto counts = s.countTypes();
        std::cout << "autobuze: " << counts.first << '\n';
        std::cout << "tramvaie: " << counts.second << '\n';
    }

    void largest() {
        auto* maxMijloc = s.largestCapacity();
        if (maxMijloc)
            std::cout << "largest: " << maxMijloc->getId() << " " << maxMijloc->getCapacitate() << " " << maxMijloc->getTip() << '\n';
        else
            std::cout << "no transport means available.\n";

    }


public:
    UI(Service& s): s(s) {}
    ~UI() =default;
    void run() {
        int option=0;
        while (option != 5) {
            std::cout << "1. add + list\n";
            std::cout << "2. list cap greater than X\n";
            std::cout << "3. available\n";
            std::cout << "4. largest\n";
            std::cout << "5. exit\n";
            std::cout << "option= ";
            std::cin >> option;
            switch (option) {
                case 1:
                    add();
                break;
                case 2:
                    listCap();
                break;
                case 3:
                    available();
                break;
                case 4:
                    largest();
                break;
                case 5:
                    std::cout << "bye";
                exit(0);
            }
        }
    }
};



#endif //UI_H
