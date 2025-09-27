//
// Created by Sonia Zagrean on 30.05.2025.
//

#pragma once
#include "BT.h"

template <typename TElem>
class BST : public BT<TElem> {
private:
    using typename BT<TElem>::Node;
    using BT<TElem>::root;

    void add(Node*& n, TElem& elem) {
        if (!n)
            n = new Node(elem, nullptr, nullptr);
        else if (elem < n->data)
            add(n->left, elem);
        else
            add(n->right, elem);
    }
    bool search(Node*& n, TElem& elem) {
        if (!n)
            return false;
        if (n->data == elem)
            return true;
        return (elem < n->data) ? search(n->left, elem) : search(n->right, elem);
    }
    Node* remove(Node* n, TElem elem) {
        if (!n)
            return nullptr;
        if (elem < n->data)
            n->left = remove(n->left, elem);
        else if (elem > n->data)
            n->right = remove(n->right, elem);
        else {
            if (!n->left) {
                Node* temp = n->right;
                delete n;
                return temp;
            }
            else if (!n->right) {
                Node* temp = n->left;
                delete n;
                return temp;
            }
            else {
                Node* successor = minNode(n->right);
                n->data = successor->data;
                n->right = remove(n->right, successor->data);
            }
        }
        return n;
    }
    Node* minNode(Node* n) {
        while (n && n->left)
            n = n->left;
        return n;
    }

public:
    BST() : BT<TElem>() {}
    void add(TElem elem) {
        add(root, elem);
    }
    bool search(TElem elem) {
        return search(root, elem);
    }
    void remove(TElem elem) {
        root = remove(root, elem);
    }
};
