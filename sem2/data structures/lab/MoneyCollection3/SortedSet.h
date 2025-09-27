/// SET DOESNT ALLOW DUPLICATED VALUES, ADDED IN A SPECIFIC ORDER

#pragma once
#include "Node.h"

template<typename TElem>
using Comparator = bool (*)(const TElem&, const TElem&);

template<typename TElem>
class SortedSet {
private:
    Node<TElem>* head;
    int len;
    Comparator<TElem> cmp;

    bool search(const TElem &elem) {
        Node<TElem>* current = head;
        while (current != nullptr) {
            if (current->data == elem)
                return true;
            current = current->next;
        }
        return false;
    }

public:
    explicit SortedSet(Comparator<TElem> cmpFunc) : head(nullptr), len(0), cmp(cmpFunc) {}
    ~SortedSet() {
        Node<TElem>* current = head;
        while (current) {
            Node<TElem>* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }


    void add(const TElem& elem) {
        if (search(elem)) return;

        Node<TElem>* newNode = new Node<TElem>(elem, nullptr);
        if (!head || cmp(elem, head->data)) {
            newNode->next = head;
            head = newNode;
        }
        else {
            Node<TElem>* current = head;
            while (current->next && !cmp(elem, current->next->data))
                current = current->next;
            newNode->next = current->next;
            current->next = newNode;
        }
        len++;
    }

    bool remove(const TElem& elem) {
        Node<TElem>* current = head;
        Node<TElem>* previous = nullptr;

        while (current != nullptr) {
            if (current->data == elem) {
                if (previous == nullptr)
                    head = current->next;
                else
                    previous->next = current->next;
                delete current;
                len--;
                return true;
            }
            previous = current;
            current = current->next;
        }
        return false;
    }

    int size() const {
        return len;
    }

    TElem getAt(int position) const {
        if (position < 0 || position >= len)
            throw std::runtime_error("invalid poistion");
        Node<TElem>* current = head;
        int pos = 0;
        while (current != nullptr) {
            if (pos == position)
                return current->data;
            pos++;
            current = current->next;
        }
        throw std::runtime_error("position not found");
    }
};


