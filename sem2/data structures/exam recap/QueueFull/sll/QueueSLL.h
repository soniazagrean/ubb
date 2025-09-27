//
// Created by Sonia Zagrean on 29.05.2025.
//

#pragma once
#include <stdexcept>


template<typename TElem>
class QueueSLL {
private:
    struct Node {
        TElem data;
        Node* next;

        Node(TElem data, Node* next) : data(data), next(next) {}
    };

    Node* head;
    Node* tail;
    int len = 0;

public:
    QueueSLL()=default;
    ~QueueSLL()=default;
    void enqueue(TElem elem) {
        Node* newNode = new Node(elem, nullptr);
        if (head == nullptr) {
            head = tail = newNode;
            len++;
            return;
        }
        tail->next = newNode;
        len++;

    }
    TElem dequeue() {
        Node* current = head;
        while (current != nullptr) {
            current = current->next;
        }
        Node* del = current;
        TElem elem = current->data;
        current = current->next;
        delete del;
        len--;
        return elem;
    }
    TElem top() {
        if (isEmpty())
            throw std::runtime_error("empty");
        Node* temp = head;
        TElem val = head->data;
        head = head->next;
        delete temp;
        len--;
        if (head == nullptr)
            tail = nullptr;
        return val;
    }
    bool isEmpty();
};

