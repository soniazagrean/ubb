//
// Created by Sonia Zagrean on 20.05.2025.
//

#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;


Bag::Bag() {
    head = nullptr;
    len = 0;
}


void Bag::add(TElem elem) {
    Node* newNode = new Node(elem, nullptr);

    if (head == nullptr) {
        head = newNode;
        len++;
        return;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;  // insert at final
    len++;
}


bool Bag::remove(TElem elem) {
    Node* current = head;
    Node* prev = nullptr;

    if (head == nullptr) {   // Check for empty bag
        return false;
    }

    while (current != nullptr) {
        if (current->data == elem) {
            if (prev == nullptr)
                head = current->next; // remove head
            else
                prev->next = current->next;
            delete current;
            len--;
            return true;
        }
        prev = current;
        current = current->next;
    }

    return false;
}


bool Bag::search(TElem elem) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == elem)
            return true;
        current = current->next;
    }
    return false;
}

int Bag::nrOccurrences(TElem elem) const {
    Node* current = head;
    int count = 0;
    while (current != nullptr) {
        if (current->data == elem)
            count++;
        current = current->next;
    }
    return count;
}


int Bag::size() const {
    return len;
}


bool Bag::isEmpty() const {
    return len == 0;
}

BagIterator Bag::iterator() const {
    return BagIterator(*this);
}


Bag::~Bag() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}


