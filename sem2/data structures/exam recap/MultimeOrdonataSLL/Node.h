//
// Created by Sonia Zagrean on 26.05.2025.
//

#pragma once


template<typename TElem>
class MultimeOrdonata;

template<typename TElem>
class MultimeOrdonataIterator;

template<typename TElem>
class Node {
private:
    TElem data;
    Node* next;

    friend class MultimeOrdonata<TElem>;
    friend class MultimeOrdonataIterator<TElem>;

public:
    Node(TElem data, Node* next): data(data), next(next) {}
    ~Node()=default;
};


