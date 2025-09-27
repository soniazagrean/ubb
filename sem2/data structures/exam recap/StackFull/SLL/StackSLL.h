//
// Created by Sonia Zagrean on 29.05.2025.
//

#pragma once

template <typename TElem>
class StackSLL {
private:
    struct Node {
        Node* next;
        TElem data;

        Node(TElem data, Node* next) : data(data), next(next) {}
    };

    Node* head;
    int len;

public:
    StackSLL() : head(nullptr), len(0) {}
    ~StackSLL() {
        Node* current = head;
        while (current != nullptr) {
            Node* del = current;
            current = current->next;
            delete del;
        }
    }
    void push(TElem elem);
    TElem pop();
    TElem top();
    bool isEmpty();

};



#include "StackSLL.tpp"
