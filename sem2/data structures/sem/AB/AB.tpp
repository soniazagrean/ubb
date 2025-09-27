//
// Created by Sonia Zagrean on 12.05.2025.
//
#pragma once


template<typename TElem>
AB<TElem>::Nod::Nod(const TElem &elem, Nod *s, Nod *d) : e(elem), st(s), dr(d) {}

template<typename TElem>
typename AB<TElem>::Nod * AB<TElem>::copiaza(Nod *n) {
    if (!n)
        return nullptr;
    return new Nod(n->e, copiaza(n->st), copiaza(n->dr));

}

template<typename TElem>
void AB<TElem>::distruge(Nod *n) {
    if (!n) return;
    distruge(n->st);
    distruge(n->dr);
    delete n;
}

template<typename TElem>
void AB<TElem>::viziteaza(Nod* n, const PFunctie<TElem> f) const {
    if (!n) return;
    f(n->e);
    viziteaza(n->st, f);
    viziteaza(n->dr, f);
}

template<typename TElem>
AB<TElem>::AB() {
    rad = nullptr;
}

template<typename TElem>
AB<TElem>::AB(const AB &other) {
    rad = copiaza(other.rad);
}

template<typename TElem>
AB<TElem>::~AB() {
    distruge(rad);
}

template<typename TElem>
void AB<TElem>::creeazaFrunza(TElem elem) {
    distruge(rad);
    rad = new Nod(elem);
}

template<typename TElem>
void AB<TElem>::creeazaAB(const AB &st, TElem elem, const AB &dr) {
    distruge(rad);
    rad = new Nod(elem, copiaza(st.rad), copiaza(dr.rad));
}

template<typename TElem>
void AB<TElem>::adaugaSubSt(const AB &st) {
    if (!rad)
        throw std::runtime_error("invalid");

}

template<typename TElem>
void AB<TElem>::adaugaSubDr(const AB &dr) {
}

template<typename TElem>
bool AB<TElem>::vid() const {
}

template<typename TElem>
TElem AB<TElem>::element() const {
}

template<typename TElem>
AB<TElem> AB<TElem>::stang() const {
}

template<typename TElem>
AB<TElem> AB<TElem>::drept() const {
}

template<typename TElem>
void AB<TElem>::visitTree(PFunctie<TElem> f) {
    viziteaza(rad, f);
}

