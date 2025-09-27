//
// Created by Sonia Zagrean on 29.05.2025.
//

#pragma once
#include <vector>


template <typename TElem>
class StackStl {
private:
    std::vector<TElem> stack;

public:
    StackStl();
    ~StackStl();
    void push(TElem elem);
    TElem pop();
    TElem top();
    bool isEmpty();
};




#include "StackStl.tpp"

