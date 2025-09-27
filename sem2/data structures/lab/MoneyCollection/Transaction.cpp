#include "Transaction.h"
#include <iostream>

Transaction::Transaction(int idTransaction, int sum, std::vector<pairTransaction> used)
    : idTransaction(idTransaction), sum(sum), used(used) {}

void Transaction::printTransaction() {
    std::cout << "ID: " << idTransaction << " Sum: " << sum << '\n';
    for (const auto& t : used) {
        std::cout << t.elem << " value x " << t.freq << " cnt \n";
    }
}
