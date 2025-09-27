//
// Created by Sonia Zagrean on 13.05.2025.
//

#ifndef MASINA_H
#define MASINA_H

#include <string>
#include <iostream>

class Masina {
private:
    int id, an;
    std::string nume;
public:
    Masina(int id, int an, std::string nume);
    ~Masina();
    int getID();
    int getAn();
    std::string getNume();

    friend std::ostream& operator<<(std::ostream& os, Masina& m) {
        return os << m.getID() << ' ' << m.getAn() << ' ' << m.getNume();
    }
};



#endif //MASINA_H
