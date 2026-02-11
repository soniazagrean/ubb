//
// Created by Sonia Zagrean on 04.06.2025.
//

#ifndef VALIDATOR_H
#define VALIDATOR_H
#include "Program.h"


class Validator {
public:
    void validate(Program& p) {
        if (p.getZi() < 1 || p.getZi() > 31)
            throw std::runtime_error("invalid day (must be >1 and <= 31)");

        int start = p.getOraStart();
        int stop = p.getOraStop();

        if (start < 0 || start > 23 || stop < 0 || stop > 23)
            throw std::runtime_error("invalid hour");


        if (stop - start != 2)
            throw std::runtime_error("invalid interval - must be exactly 2 hours!");

    }
};



#endif //VALIDATOR_H
