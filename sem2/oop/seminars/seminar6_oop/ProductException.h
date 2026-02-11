#ifndef PRODUCTEXCEPTION_H
#define PRODUCTEXCEPTION_H
#include <stdexcept>
using namespace std;

class ProductException : public runtime_error {
public:
    explicit ProductException(const string& msg) : runtime_error(msg) {}
};

#endif //PRODUCTEXCEPTION_H
