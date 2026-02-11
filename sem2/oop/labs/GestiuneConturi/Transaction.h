//
// Created by Sonia Zagrean on 03.04.2025.
//

#ifndef TRANSACTION_H
#define TRANSACTION_H

//  -------------
//  in      pizza   char &
//  0x3558  0x3550  char *
//  -------------

#include <iostream>

class Transaction {
private:
    int date;
    unsigned int sum;
    char *type;
    char *description;

public:
    Transaction();
    Transaction(int date, unsigned int sum, const char *type, const char *description);
    Transaction(const Transaction& transaction);
    bool operator==(Transaction const &transaction) const;
    Transaction& operator=(Transaction const &transaction);
    ~Transaction();

    void setDate(int date);
    void setSum(unsigned int sum);
    void setType(const char* type);
    void setDescription(const char* description);

    int getDate() const;
    unsigned int getSum() const;
    char *getType() const;
    char *getDescription() const;

    friend std::istream& operator>>(std::istream& is, Transaction &transaction);
    friend std::ostream& operator<<(std::ostream& os, Transaction const &transaction);
};



#endif //TRANSACTION_H
