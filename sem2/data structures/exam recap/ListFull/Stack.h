//
// Created by Sonia Zagrean on 30.05.2025.
//

#pragma once
#include "sll/ListSLL.h"

template<typename TElem>
class Stack {
private:
    ListSLL<TElem> stack;

public:
    Stack() = default;
    ~Stack() = default;
    void push(TElem elem) {
        stack.push_back(elem);
    }
    void pop() {
        if (empty())
            throw std::underflow_error("Stack is empty");
        stack.pop_back();
    }
    // TElem top() {
    //     return stack.back();
    // }
    TElem top() {
        return stack.getAt(stack.size() - 1);
    }

    bool empty() {
        return stack.isEmpty();
    }
};

