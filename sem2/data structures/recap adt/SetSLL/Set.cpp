//
// Created by Sonia Zagrean on 21.05.2025.
//

#include "Set.h"

#include "SetIterator.h"

Set::Set() {
    head = nullptr;
    len = 0;
}

bool Set::add(TElem elem) {
    Node* newNode = new Node(elem, nullptr);

    if (search(elem))
        return false;

    if (head == nullptr) {  // one elem
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;   // last elem
        }
        current->next = newNode;
    }
    len++;
    return true;
}

bool Set::remove(TElem elem) {
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current->data == elem) {
            if (prev == nullptr)
                head = current->next;
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

bool Set::search(TElem elem) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == elem)
            return true;
        current = current->next;
    }
    return false;
}

int Set::size() {
    return len;
}

bool Set::isEmpty() {
    return len==0;
}

int Set::nrOccurrences(TElem elem) {
    return search(elem) ? 1 : 0;
}

SetIterator Set::iterator() {
    return SetIterator(*this);
}

Set::~Set() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
