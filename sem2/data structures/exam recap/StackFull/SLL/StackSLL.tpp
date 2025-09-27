//
// Created by Sonia Zagrean on 29.05.2025.
//

/// FILO = first in last out

#pragma once
#include <stdexcept>


template<typename TElem>
void StackSLL<TElem>::push(TElem elem) {
    Node* newNode = new Node(elem, head);
    head = newNode;
    len++;
}

template<typename TElem>
TElem StackSLL<TElem>::pop() {
    if (isEmpty())
        throw std::runtime_error("empty");
    Node* temp = head;
    TElem val = head->data;
    head = head->next;
    delete temp;
    len--;
    return val;
}

template<typename TElem>
TElem StackSLL<TElem>::top() {
    if (isEmpty())
        throw std::runtime_error("empty");
    return head->data;
}

template<typename TElem>
bool StackSLL<TElem>::isEmpty() {
    return len == 0;
}
