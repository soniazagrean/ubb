//
// Created by Sonia Zagrean on 30.05.2025.
//

#pragma once
#include <stdexcept>

template<typename TElem>
class ListSLLIterator;

template<typename TElem>
class ListSLL {
public:
    struct Node {
        TElem data;
        Node* next;

        Node(TElem data, Node* next) : data(data), next(next) {}
    };

    ListSLL() : head(nullptr), len(0) {}
    ~ListSLL(){
        while (head != nullptr) {
            Node* del = head;
            head = head->next;
            delete del;
        }
    }
    void push_front(TElem elem) {
        Node* newNode = new Node(elem, head);
        head = newNode;
        len++;
    }
    void push_back(TElem elem) {
        Node* current = head;
        Node* newNode = new Node(elem, nullptr);
        while (current->next != nullptr)
            current = current->next;
        current->next = newNode;
        len++;
    }
    TElem pop_front() {
        if (head == nullptr)
            throw std::underflow_error("List is empty");

        Node* del = head;
        TElem elem = del->data;
        head = head->next;
        delete del;
        len--;
        return elem;
    }
    TElem pop_back() {
        if (head == nullptr)
            throw std::underflow_error("List is empty");

        Node* current = head;
        while (current->next->next != nullptr)
            current = current->next;
        Node* del = current->next;
        TElem elem = del->data;
        current->next = nullptr;
        delete del;
        len--;
        return elem;
    }
    void insertIndex(int index, TElem elem) {
        if (index < 0 || index > len)
            throw std::out_of_range("Invalid index");

        if (index == 0) {
            push_front(elem);
            return;
        }

        Node* current = head;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next;
        }

        Node* newNode = new Node(elem, current->next);
        current->next = newNode;
        len++;
    }

    void removeIndex(int index) {
        if (index < 0 || index >= len)
            throw std::out_of_range("Index out of range");

        if (index == 0) {
            pop_front();
            return;
        }

        Node* current = head;
        while (current->next != nullptr && index != 0) {
            current = current->next;
            index--;
        }
        Node* del = current->next;
        current->next = del->next;
        delete del;
        len--;
    }
    bool isEmpty() const {
        return len == 0;
    }
    int size() const {
        return len;
    }
    TElem getAt(int index) {
        if (index < 0 || index >= len)
            throw std::out_of_range("Index out of range");

        Node* current = head;
        while (current->next != nullptr && index != 0) {
            current = current->next;
            index--;
        }
        return current->data;
    }
    bool search(TElem elem) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == elem)
                return true;
            current = current->next;
        }
        return false;
    }
    int nrOccurrences(TElem elem) {
        Node* current = head;
        int count = 0;
        while (current != nullptr) {
            if (current->data == elem)
                count++;
            current = current->next;
        }
        return count;
    }
    void setAt(int index, TElem elem) {
        if (index < 0 || index >= len)
            throw std::out_of_range("Index out of range");

        Node* current = head;
        while (current->next != nullptr && index != 0) {
            current = current->next;
            index--;
        }
        current->data = elem;
    }
    TElem front() {
        return head->data;
    }
    TElem back() const {
        if (head == nullptr)
            throw std::underflow_error("List is empty");

        Node* current = head;
        while (current->next != nullptr)
            current = current->next;

        return current->data;
    }


private:
    Node* head;
    int len;

    friend class ListSLLIterator<TElem>;
};

