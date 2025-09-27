//
// Created by Sonia Zagrean on 26.05.2025.
//

#pragma once
#include "Node.h"

template<typename TElem>
using Comparator = bool (*)(TElem, TElem);

template<typename TElem>
class MultimeOrdonata {
private:
    Node<TElem>* head;
    int len;

    Comparator<TElem> cmp;

    friend class MultimeOrdonataIterator<TElem>;

public:
    explicit MultimeOrdonata(Comparator<TElem> c): head(nullptr), len(0), cmp(c) {}
    ~MultimeOrdonata() {
        Node<TElem>* current = head;
        while (current != nullptr) {
            Node<TElem>* del = current;
            current = current->next;
            delete del;
        }
    }
    void add(TElem elem) {
        if (search(elem))
            return;
        Node<TElem>* newNode = new Node<TElem>(elem, nullptr);

        if (head == nullptr || !cmp(head->data, elem)) {
            newNode->next = head;
            head = newNode;
        }
        else {
            Node<TElem>* current = head;
            Node<TElem>* prev = nullptr;
            while (current != nullptr && cmp(current->data, elem)) {
                prev = current;
                current = current->next;
            }

            prev->next = newNode;
            newNode->next = current;
        }
        len++;
    }

    bool remove(TElem elem) {
        if (!search(elem))
            return false;
        Node<TElem>* current = head;
        Node<TElem>* prev = nullptr;
        while (current != nullptr) {
            if (current->data == elem) {
                if (prev == nullptr)
                    head = current->next;
                else
                    prev->next = current->next;
                len--;
                delete current;
                return true;
            }
            prev = current;
            current = current->next;
        }
        return false;
    }
    bool search(TElem elem) {
        Node<TElem>* current = head;
        while (current != nullptr) {
            if (current->data == elem)
                return true;
            current = current->next;
        }
        return false;
    }
    int size() {
        return len;
    }
    TElem getAt(int pos) {
        Node<TElem>* current = head;
        while (current != nullptr && pos != 0) {
            current = current-> next;
            pos--;
        }
        return current->data;
    }
};

