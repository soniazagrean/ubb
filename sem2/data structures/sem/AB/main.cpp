#include <iostream>
#include "AB.h"
#include <vector>
#include "Masina.h"

void afiseazaInt(int x) {
    std::cout << x << " ";
}

void afiseazaString(std::string s) {
    std::cout << s << ' ';
}

void afiseazaMasina(Masina m) {
    std::cout << m << '\n';
}

int main() {
    AB<int> a, st, dr;
    st.creeazaFrunza(2);
    dr.creeazaFrunza(3);
    a.creeazaAB(st, 1, dr);

    std::cout << "Elementele arborelui in preordine: ";
    a.visitTree(afiseazaInt);  // va afisa: 1 2 3
    std::cout << std::endl;

    std::vector<std::string> v;
    v.push_back("Electronice");
    v.push_back("Laptopuri");
    v.push_back("Telefoane");
    v.push_back("Android");
    v.push_back("Iphone");
    AB<std::string> d1, d2, d3, d4, d5;
    d2.creeazaFrunza(v[1]);
    d4.creeazaFrunza(v[3]);
    d5.creeazaFrunza(v[4]);
    d3.creeazaAB(d4, v[2], d5);
    d1.creeazaAB(d2, v[0], d3);

    std::cout << "Elementele arborelui in preordine: ";
    d1.visitTree(afiseazaString);
    std::cout << std::endl;

    Masina m1(1, 2019, "volvo");
    Masina m2(2, 2005, "ford");
    Masina m3(3, 2017, "bmw");
    AB<Masina> l, r, ab;
    l.creeazaFrunza(m2);
    r.creeazaFrunza(m3);
    ab.creeazaAB(l, m1, r);

    std::cout << "Elementele arborelui in preordine: ";
    ab.visitTree(afiseazaMasina);
    std::cout << std::endl;

    return 0;
}