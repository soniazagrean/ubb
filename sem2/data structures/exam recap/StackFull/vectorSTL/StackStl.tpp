//
// Created by Sonia Zagrean on 29.05.2025.
//

#pragma once

template<typename TElem>
StackStl<TElem>::StackStl() = default;

template<typename TElem>
StackStl<TElem>::~StackStl() = default;

template<typename TElem>
void StackStl<TElem>::push(TElem elem) {
    stack.push_back(elem);
}

template<typename TElem>
TElem StackStl<TElem>::pop() {
    if (isEmpty())
        throw std::runtime_error("empty");
    TElem elem = stack.back();
    stack.pop_back();
    return elem;
}

template<typename TElem>
TElem StackStl<TElem>::top() {
    if (isEmpty())
        throw std::runtime_error("empty");
    TElem elem = stack.back();
    return elem;
}

template<typename TElem>
bool StackStl<TElem>::isEmpty() {
    return stack.size() == 0;
}
