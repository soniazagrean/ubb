//
// Created by Sonia Zagrean on 04.06.2025.
//

#ifndef PROGRAM_H
#define PROGRAM_H
#include <string>


class Program {
private:
    std::string nume, producator;
    int oraStart, oraStop;
    int zi;
public:
    Program(std::string nume, std::string producator, int oraStart, int oraStop, int zi):
        nume(nume), producator(producator), oraStart(oraStart), oraStop(oraStop), zi(zi) {}
    ~Program()=default;
    std::string getNume() {
        return nume;
    }
    std::string getProducator() {
        return producator;
    }
    int getOraStart() {
        return oraStart;
    }
    int getOraStop() {
        return oraStop;
    }
    int getZi() {
        return zi;
    }

};



#endif //PROGRAM_H
