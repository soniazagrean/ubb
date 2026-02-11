#include <iostream>
#include <fstream>
#include <queue>

#include "ComplexNumber.h"
#include "Operations.h"
#include "Tests.h"

std::ifstream fin("../numbers.in");


using Comparator = bool (*)(const ComplexNumber &, const ComplexNumber &);

bool cmp_absolute1(const ComplexNumber &n1, const ComplexNumber &n2) {
    return n1 < n2;
}

void printPQ(std::priority_queue<ComplexNumber, std::vector<ComplexNumber>, Comparator> pq) {
    std::cout << "pq elems:\n";
    while (!pq.empty()) {
        std::cout << pq.top() << '\n';
        pq.pop();
    }
}


void load(std::priority_queue<ComplexNumber, std::vector<ComplexNumber>, Comparator>& pq) {
    double r, i;
    std::cout << "numbers from file:\n";

    while (fin >> r >> i) {
        std::cout << r << " + " << i << "i\n";
        pq.push(ComplexNumber(r, i));
    }

    // fin.close();
}

int main() {
    test_all();
    std::priority_queue<ComplexNumber, std::vector<ComplexNumber>, Comparator> pq(cmp_absolute1);

    int option;
    do {
        std::cout << "1. Load & Print\n";
        std::cout << "2. Greatest number\n";
        std::cout << "3. Inside dial 1\n";
        std::cout << "4. Longest seq\n";
        std::cout << "5. Exit\n";

        std::cout << "Option: ";
        std::cin >> option;

        switch (option) {
            case 1:
                load(pq);
                printPQ(pq);
                break;
            case 2:
                std::cout << greatestComplexNumber(pq) << '\n';
                break;
            case 3:
                insideDial1(pq);
                break;
            case 4:
                std::cout << longestSeq(pq) << '\n';
                break;
            case 5:
                std::cout << "bye\n";
                break;
        }
    } while (option != 5);

    return 0;
}
