//
// Created by Sonia Zagrean on 29.05.2025.
//

#pragma once


template<typename TElem>
void StackDynamic<TElem>::push(TElem elem) {
    if (len == capacity)
        resize();
    elems[len++] = elem;

}

template<typename TElem>
TElem StackDynamic<TElem>::pop() {
    return elems[--len];
}

template<typename TElem>
TElem StackDynamic<TElem>::top() {
    return elems[len - 1];

}

template<typename TElem>
bool StackDynamic<TElem>::isEmpty() {
    return len == 0;
}
