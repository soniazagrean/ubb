//
// Created by Sonia Zagrean on 21.05.2025.
//

#include "SortedSet.h"

#include "SortedSetIterator.h"

bool SortedSet::add(TElem elem) {
    if (search(elem))
        return false;

    Node* newNode = new Node(elem, nullptr);

    if (head == nullptr || cmp(elem, head->data)) {
        newNode->next = head;
        head = newNode;
    }
    else {
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr && cmp(current->data, elem)) {
            prev = current;
            current = current->next;
        }

        newNode->next = current;
        prev->next = newNode;
    }

    len++;
    return true;
}


bool SortedSet::remove(TElem elem) {
    if (head == nullptr)
        return false;

    if (head->data == elem) {
        Node* temp = head;
        head = head->next;
        delete temp;
        len--;
        return true;
    }
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr && current->data != elem) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr)
        return false;

    prev->next = current->next;
    delete current;
    len--;
    return true;
}

bool SortedSet::search(TElem elem) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == elem)
            return true;
        current = current->next;
    }
    return false;
}

int SortedSet::size() {
    return len;
}

bool SortedSet::isEmpty() {
    return len==0;
}

int SortedSet::nrOccurrences(TElem elem) {
    return (search(elem)) ? 1 : 0;
}

SortedSetIterator SortedSet::iterator() {
    return SortedSetIterator(*this);
}

SortedSet::~SortedSet() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
