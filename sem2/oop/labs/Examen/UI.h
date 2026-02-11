//
// Created by Sonia Zagrean on 04.06.2025.
//

#ifndef UI_H
#define UI_H
#include <iostream>

#include "Service.h"


class UI {
private:
    Service& s;
    void add(Service& s) {
        std::string nume, prod;
        int oraStart, oraStop, zi;
        std::cout << "nume = ";
        std::cin.ignore();
        std::getline(std::cin, nume);

        std::cout << "producator = ";
        std::getline(std::cin, prod);

        std::cout << "ora start = " ; std::cin >> oraStart;
        std::cout << "ora stop = " ; std::cin >> oraStop;
        std::cout << "zi = " ; std::cin >> zi;
        try {
            Program p(nume, prod, oraStart, oraStop, zi);
            s.add(p);
            std::cout << "ok!\n";
        } catch (std::runtime_error& ex) {
            std::cout << "error: " << ex.what() << "\n";
        }
    }
    void remove(Service& s) {
        int zi, start, stop;
        std::cout << "zi: ";  std::cin >> zi;
        std::cout << "ora start: "; std::cin >> start;
        std::cout << "ora stop: "; std::cin >> stop;

        try {
            s.deleteProgram(zi, start, stop);
            std::cout << "ok!\n";
        } catch (std::runtime_error& ex) {
            std::cout << "error: " << ex.what() << "\n";
        }
    }

    void mostWatched(Service& s) {
        auto result = s.getMostWatched();
        if (result.second == 0) {
            std::cout << "doesnt exist!\n";
        }
        else
            std::cout << "most watched program: " << result.first
                      << " with " << result.second << " total hours\n";

    }


    void list(Service& s) {
        for (auto& i : s.get())
            std::cout << i.getNume() << ' ' << i.getProducator()
                        << ' ' << i.getOraStart() << ' ' << i.getOraStop() << ' ' << i.getZi() << '\n';
    }

public:
    explicit UI(Service& s): s(s){}
    ~UI()=default;
    void run() {
        int option = 0;
        while (option != 5) {
            std::cout << "1. add\n";
            std::cout << "2. list all\n";
            std::cout << "3. remove program\n";
            std::cout << "4. list most watched\n";
            std::cout << "5. exit\n";
            std::cout << "option = ";
            std::cin >> option;
            if (option == 1)
                add(s);
            else if (option == 2)
                list(s);
            else if (option == 3)
                remove(s);
            else if (option == 4)
                mostWatched(s);
            else if (option == 5) {
                std::cout << "bye";
                exit(0);
            }
        }
    }
};



#endif //UI_H
