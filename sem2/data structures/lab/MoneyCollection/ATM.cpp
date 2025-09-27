#include "ATM.h"
#include <iostream>

ATM::ATM() {
    deposit.loadBills();
}

bool ATM::Withdraw(int sum) {
    pairT billsCopy[100];
    int billCount = 0;

    // copy bills from deposit
    for (int i = 0; i < deposit.size(); ++i) {
        billsCopy[billCount].elem = deposit.getAtElem(i);
        billsCopy[billCount].freq = deposit.getAtFreq(i);
        billCount++;
    }

    for (int i = 0; i < billCount - 1; ++i) {
        for (int j = 0; j < billCount - i - 1; ++j) {
            if (billsCopy[j].elem < billsCopy[j+1].elem) {
                pairT temp = billsCopy[j];
                billsCopy[j] = billsCopy[j+1];
                billsCopy[j+1] = temp;
            }
        }
    }

    std::vector<pairTransaction> used;
    int remaining = sum;

    for (int i = 0; i < billCount && remaining != 0; ++i) {
        int billValue = billsCopy[i].elem;
        int billFreq = billsCopy[i].freq;

        while (remaining >= billValue && billFreq > 0) {
            int count = remaining / billValue; // how many can we use
            if (count > billFreq) count = billFreq;

            remaining -= count * billValue;
            billFreq -= count;

            if (count > 0) {
                used.push_back({billValue, count});
                deposit.remove(billValue, count);
            }

            if (remaining == 0) break;
        }
    }

    if (remaining > 0) {
        for (const auto& usedBill : used) {
            deposit.add(usedBill.elem); // restore if we cant get the wanted sum
        }
        std::cout << "incorrect\n";
        return false;
    }

    idTransaction++;
    Transaction newTransaction(idTransaction, sum, used);
    previousTransactions.push_back(newTransaction);
    std::cout << "done\n";
    return true;
}

void ATM::displayTransaction() {
    for (auto& t : previousTransactions)
        t.printTransaction();
}
