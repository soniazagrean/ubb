#pragma once
#include "BT.h"

template<typename T>
class BST : public BT<T> {
protected:
    using BT<T>::root;
    using typename BT<T>::Node;

    Node* insert(Node* n, const T& elem) {
        if (!n)
            return new Node(elem, nullptr, nullptr);
        if (elem < n->data)
            n->left = insert(n->left, elem);
        else if (elem > n->data)
            n->right = insert(n->right, elem);
        return n;
    }

    Node* findMin(Node* n) {
        while (n && n->left)
            n = n->left;
        return n;
    }

    Node* remove(Node* n, const T& elem) {
        if (!n)
            return nullptr;

        if (elem < n->data)
            n->left = remove(n->left, elem);
        else if (elem > n->data)
            n->right = remove(n->right, elem);
        else {
            // caz 1: fara copii
            if (!n->left && !n->right) {
                delete n;
                return nullptr;
            }

            // caz 2: un copil
            if (!n->left) {
                Node* temp = n->right;
                delete n;
                return temp;
            }
            if (!n->right) {
                Node* temp = n->left;
                delete n;
                return temp;
            }

            // caz 3: 2 copii
            Node* succ = findMin(n->right);
            n->data = succ->data;
            n->right = remove(n->right, succ->data);
        }

        return n;
    }

    bool search(Node* n, const T& elem) {
        if (!n)
            return false;
        if (n->data == elem)
            return true;
        if (elem < n->data)
            return search(n->left, elem);
        return search(n->right, elem);
    }

public:
    void insert(const T& elem) {
        root = insert(root, elem);
    }

    void remove(const T& elem) {
        root = remove(root, elem);
    }

    bool search(const T& elem) {
        return search(root, elem);
    }
};
