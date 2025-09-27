//
// Created by Sonia Zagrean on 26.05.2025.
//
#pragma once


template<typename TElem>
Node<TElem> * IteratedList<TElem>::getNode(int index) const {
    Node<TElem>* current = head;
    for (int i = 0; i < index; ++i)
        current = current->next;
    return current;
}

template<typename TElem>
IteratedList<TElem>::IteratedList() : head(nullptr), tail(nullptr), count(0) {}

template<typename TElem>
IteratedList<TElem>::~IteratedList() {
    clear();
}

template<typename TElem>
void IteratedList<TElem>::push_back(TElem elem) {
    Node<TElem>* newNode = new Node<TElem>(elem, nullptr);
    if (empty())
        head = tail = newNode;
    else {
        tail->next = newNode;
        tail = newNode;
    }
    count++;
}

template<typename TElem>
void IteratedList<TElem>::push_front(TElem elem) {
    Node<TElem>* newNode = new Node(elem, nullptr);
    head = newNode;
    if (count == 0)
        tail = newNode;
    count++;
}

template<typename TElem>
void IteratedList<TElem>::pop_back() {
    if (count == 1) {
        delete head;
        head = tail = nullptr;
    }
    else {
        Node<TElem>* prev = getNode(count - 2);
        delete tail;
        tail = prev;
        tail->next = nullptr;
    }
    count--;
}

template<typename TElem>
void IteratedList<TElem>::pop_front() {
    Node<TElem>* temp = head;
    head = head->next;
    delete temp;
    --count;
    if (head == nullptr) {
        tail = nullptr;
    }
}

template<typename TElem>
TElem & IteratedList<TElem>::front() {
    return head->data;
}

template<typename TElem>
TElem & IteratedList<TElem>::back() {
    return tail->data;
}

template<typename TElem>
bool IteratedList<TElem>::empty() {
    return count == 0;
}

template<typename TElem>
int IteratedList<TElem>::size() {
    return count;
}

template<typename TElem>
TElem & IteratedList<TElem>::at(int index) {
    return getNode(index)->data;
}

template<typename TElem>
void IteratedList<TElem>::insert(int index, TElem elem) {
    if (index == 0)
        push_front(elem);

    else if (index == count)
        push_back(elem);

    else {
        Node<TElem>* prev = getNode(index - 1);
        prev->next = new Node(elem, prev->next);
        ++count;
    }
}

template<typename TElem>
void IteratedList<TElem>::erase(int index) {
    if (index == 0)
        pop_front();

    else {
        Node<TElem>* prev = getNode(index - 1);
        Node<TElem>* toDelete = prev->next;
        prev->next = toDelete->next;
        if (toDelete == tail)
            tail = prev;

        delete toDelete;
        --count;
    }
}

template<typename TElem>
void IteratedList<TElem>::clear() {
    while (!empty())
        pop_front();
}
