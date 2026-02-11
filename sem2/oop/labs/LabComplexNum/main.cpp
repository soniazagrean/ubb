#include <iostream>

#include "ComplexNumber.h"
#include "Tests.h"

int main() {
    testAll();
    int option;
    ComplexNumber c1, c2;
    do {
        std::cout << "1. read num \n";
        std::cout << "2. write num \n";
        std::cout << "3. absolute value \n";
        std::cout << "4. conjugate value \n";
        std::cout << "5. add \n";
        std::cout << "6. subtract \n";
        std::cout << "7. exit\n";
        std:: cout << "option = ";
        std::cin >> option;
        switch (option) {
            case 1:
                std::cout << "read num1 = ";
                std::cin >> c1;
                std::cout << "read num2 = ";
                std::cin >> c2;
                break;
            case 2:
                std::cout << "num 1 = " << c1 << "\n";
                std::cout << "num 2 = " << c2 << "\n";
                break;
            case 3:
                std::cout << "absolute value = " << c1.absoluteValue() << "\n";
                std::cout << "absolute value = " << c2.absoluteValue() << "\n";
                break;
            case 4:
                std::cout << "conjugate value = " << c1.conjugateValue() << "\n";
                std::cout << "conjugate value = " << c2.conjugateValue() << "\n";
                break;
            case 5:
                std:: cout << "c1 + c2 = " << c1 + c2 << "\n";
                break;
            case 6:
                std::cout << "c1 - c2 = " << c1 - c2 << "\n";
                break;
            case 7:
                std::cout << "bye..";
                exit(0);
        }
    }while (option != 7);

    return 0;
}
