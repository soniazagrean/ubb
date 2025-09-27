//
// Created by Sonia Zagrean on 20.05.2025.
//

#include "SortedBag.h"
#include "SortedBagIterator.h"

SortedBag::SortedBag(Relation r) : cmp(r), head(nullptr), len(0) {
}

void SortedBag::add(TComp e) {
    Node* newNode = new Node(e, nullptr);

    if (head == nullptr || cmp(e, head->data)) {  // at the beginning
        newNode->next = head;
        head = newNode;
        len++;
        return;
    }

    Node* current = head;
    Node* prev = nullptr;
    while (current != nullptr && cmp(current->data, e)) {
        prev = current;
        current = current->next;
    }
    newNode->next = current;
    prev->next = newNode;  // insert between prev current
    len++;
}


bool SortedBag::remove(TComp e) {
    if (head == nullptr)
        return false;

    if (head->data == e) {
        Node* temp = head;
        head = head->next;
        delete temp;
        len--;
        return true;
    }
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr && current->data != e) {
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


bool SortedBag::search(TComp elem) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == elem)
            return true;
        current = current->next;
    }
    return false;
}


int SortedBag::nrOccurrences(TComp elem) const {
    Node* current = head;
    int count = 0;
    while (current != nullptr) {
        if (current->data == elem)
            count++;
        current = current->next;
    }
    return count;
}



int SortedBag::size() const {
    return len;
}


bool SortedBag::isEmpty() const {
    return len==0;
}


SortedBagIterator SortedBag::iterator() const {
    return SortedBagIterator(*this);
}


SortedBag::~SortedBag() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

