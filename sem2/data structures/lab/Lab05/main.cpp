#include <iostream>
#include "BT.h"

struct Masina {
    int id;
    int an;
    int pret;

    Masina() : id(0), an(0), pret(0) {}
    Masina(int i, int a, int p) : id(i), an(a), pret(p) {}

    friend std::ostream& operator<<(std::ostream& os, const Masina& m) {
        os << "ID: " << m.id << ", year: " << m.an << ", price: " << m.pret << " lei";
        return os;
    }
};

void printString(std::string s) {
    std::cout << s << " ";
}

void printMasina(Masina m) {
    std::cout << "\n[" << m << "]";
}

int main() {
    std::cout << "strings\n";

    BT<std::string> android, iphone, telefoane, laptopuri, electronice;

    android.createLeaf("Android");
    iphone.createLeaf("iPhone");

    telefoane.createLeaf("Telefoane");
    telefoane.addSubtreeLeft(android);
    telefoane.addSubtreeRight(iphone);

    laptopuri.createLeaf("Laptopuri");

    electronice.createLeaf("Electronice");
    electronice.addSubtreeLeft(laptopuri);
    electronice.addSubtreeRight(telefoane);

    std::cout << "strings preorder: \n";
    electronice.visitTree(printString);
    std::cout << "\n";

    std::cout << "masina\n";

    BT<Masina> m102, m109, m101, m104, m100;

    m102.createLeaf(Masina(102, 2021, 13000));
    m109.createLeaf(Masina(109, 2019, 14000));

    m104.createLeaf(Masina(104, 2022, 25000));
    m104.addSubtreeLeft(m102);
    m104.addSubtreeRight(m109);

    m101.createLeaf(Masina(101, 2020, 15000));

    m100.createLeaf(Masina(100, 2018, 20000));
    m100.addSubtreeLeft(m101);
    m100.addSubtreeRight(m104);

    std::cout << "masina preorder: ";
    m100.visitTree(printMasina);
    std::cout << "\n";

    return 0;
}
