//
// Created by Sonia Zagrean on 07.04.2025.
//

#include "Tests.h"
#include "Repository.h"
#include "Service.h"
#include "Transaction.h"

void testTransaction() {
    Transaction t1(12, 100, "in", "pizza");
    assert(t1.getDate() == 12);
    assert(t1.getSum() == 100);
    assert(strcmp(t1.getType(), "in") == 0);
    assert(strcmp(t1.getDescription(), "pizza") == 0);
    t1.setDate(31);
    assert(t1.getDate() == 31);
    Transaction t2 = t1;
    assert(t1 == t2);
}

void testRepo() {
    Repository r;
    Transaction t1(12, 100, "in", "pizza");
    Transaction t2(4, 20, "in", "apple");
    Transaction t3(30, 18, "out", "bread");
    Transaction t4(18, 22, "in", "cookies");
    r.createTransaction(t1);
    r.createTransaction(t2);
    r.createTransaction(t3);
    r.createTransaction(t4);
    assert(r.readTransaction(0) == t1);
    assert(r.readTransaction(1) == t2);
    assert(r.readTransaction(2) == t3);
    assert(r.readTransaction(3) == t4);
    r.deleteTransactionByIndex(1); // apple
    assert(r.getSize() == 3);
    assert(r.readTransaction(0) == t1);
    assert(r.readTransaction(1) == t3);
    assert(r.readTransaction(2) == t4);
    r.deleteTransactionByIndex(2); // cookies
    assert(r.getSize() == 2);
}


void testService() {
    Service s;
    Transaction t1(12, 100, "in", "pizza");
    Transaction t2(4, 20, "in", "apple");
    Transaction t3(30, 18, "out", "bread");
    Transaction t4(18, 22, "in", "cookies");
    s.add(t1);
    s.add(t2);
    s.add(t3);
    s.add(t4);
    assert(s.getAll().size() == 4);
    assert(s.getAll()[0] == t1);
    assert(s.getAll()[1] == t2);
    assert(s.getAll()[2] == t3);
    assert(s.getAll()[3] == t4);
    std::vector<Transaction> filtered = s.filterTransactions("in", 0, 0);
    assert(filtered.size() == 3);
    s.removeByExactDate(4);  // apple
    assert(s.getAll().size() == 3);
    assert(s.getAll()[1] == t3); // bread
    s.removeByDateRange(12, 18);  // pizza, cookies
    assert(s.getAll().size() == 1);  // bread
    s.replaceTransaction(30, "out", "bread", 50);
    assert(s.getAll()[0].getSum() == 50);
}

void testAll() {
    testTransaction();
    testRepo();
    testService();
}


