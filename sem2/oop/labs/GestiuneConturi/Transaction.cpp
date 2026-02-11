//
// Created by Sonia Zagrean on 03.04.2025.
//

#include "Transaction.h"


Transaction::Transaction() {
    type = new char[1];
    type[0] = '\0';
    description = new char[1];
    description[0] = '\0';
}

Transaction::Transaction(int date, unsigned int sum, const char *type, const char *description) : date(date), sum(sum) {
    this->type = new char[strlen(type) + 1];
    strcpy(this->type, type);

    this->description = new char[strlen(description) + 1];
    strcpy(this->description, description);
}

Transaction::Transaction(const Transaction &transaction) {
    this->date = transaction.date;
    this->sum = transaction.sum;

    type = new char[strlen(transaction.type) + 1];
    strcpy(type, transaction.type);

    description = new char[strlen(transaction.description) + 1];
    strcpy(description, transaction.description);
}

Transaction::~Transaction() {
    delete[] type;
    delete[] description;
}

void Transaction::setDate(int date) {
    this->date = date;
}

void Transaction::setSum(unsigned int sum) {
    this->sum = sum;
}

void Transaction::setType(const char *type) {
    delete[] this->type;
    this->type = new char[strlen(type) + 1];
    strcpy(this->type, type);
}

void Transaction::setDescription(const char *description) {
    delete[] this->description;
    this->description = new char[strlen(description) + 1];
    strcpy(this->description, description);
}

int Transaction::getDate() const {
    return this->date;
}

unsigned int Transaction::getSum() const {
    return this->sum;
}


char *Transaction::getType() const {
    return this->type;
}

char *Transaction::getDescription() const {
    return this->description;
}

bool Transaction::operator==(Transaction const &transaction) const {
    return (this->date == transaction.date && this->sum == transaction.sum && strcmp(this->type, transaction.type) == 0 && strcmp(this->description, transaction.description) == 0);
}

Transaction& Transaction::operator=(Transaction const &transaction) {
    if (this == &transaction)
        return *this;

    delete[] type;
    delete[] description;

    this->date = transaction.date;
    this->sum = transaction.sum;

    type = new char[strlen(transaction.type) + 1];
    strcpy(type, transaction.type);

    description = new char[strlen(transaction.description) + 1];
    strcpy(description, transaction.description);

    return *this;
}

std::istream &operator>>(std::istream &is, Transaction &transaction) {
    int date;
    unsigned int sum;
    char tempType[100], tempDescription[256];

    if (is >> date >> sum >> tempType) {
        //is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        is.getline(tempDescription, 256);


        transaction.setDate(date);
        transaction.setSum(sum);
        transaction.setType(tempType);
        transaction.setDescription(tempDescription);
    }
    return is;
}

std::ostream & operator<<(std::ostream &os, Transaction const &transaction) {
    return os << transaction.date << ' ' << transaction.sum << ' ' << transaction.type << ' ' << transaction.description << '\n';
}
