#pragma once
#include "Masina.h"

template <typename TElem>
using PFunctie = void(*)(TElem);

template <typename TElem>
class AB {
private:
    struct Nod {
        TElem e;
        Nod* st;
        Nod* dr;

        Nod(const TElem& elem, Nod* s = nullptr, Nod* d = nullptr);
    };

    Nod* rad;

    Nod* copiaza(Nod* n);
    void distruge(Nod* n);
    void viziteaza(Nod* n, PFunctie<TElem> f) const;
 
public:
    AB();
    AB(const AB& other);
    ~AB();
 
    void creeazaFrunza(TElem elem);
    void creeazaAB(const AB& st, TElem elem, const AB& dr);
    void adaugaSubSt(const AB& st);
    void adaugaSubDr(const AB& dr);
    bool vid() const;
    TElem element() const;
    AB stang() const;
    AB drept() const;
    void visitTree(PFunctie<TElem> f);
};


#include "AB.tpp"
