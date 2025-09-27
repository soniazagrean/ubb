//
// Created by Sonia Zagrean on 31.05.2025.
//

#pragma once
#include <algorithm>

template<typename T>
using functionP = void (*)(T);

template<typename T>
class BT {
protected:
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(T data, Node* left, Node* right): data(data), left(left), right(right) {}
    };

    Node* root;

    Node* copy(Node* n) {
        if (!n)
            return nullptr;
        return new Node(n->data, copy(n->left), copy(n->right));
    }
    void destroy(Node* n) {
        if (!n)
            return;
        destroy(n->left);
        destroy(n->right);
        delete n;
    }

    int height(Node* n) {
        if (!n)
            return 0;
        return 1 + std::max(height(n->left), height(n->right));
    }

    int size(Node* n) {
        if (!n)
            return 0;
        return 1 + size(n->left) + size(n->right);
    }

    bool search(Node* n, T& elem) {
        if (!n)
            return false;
        if (n->data == elem)
            return true;
        return search(n->left, elem) || search(n->right, elem);
    }

    void visitInorder(Node* n, functionP<T> f) {
        if (!n)
            return;
        visitInorder(n->left, f);
        f(n->data);
        visitInorder(n->right, f);
    }

public:
    BT() : root(nullptr) {}
    ~BT() {
        destroy(root);
    }

    void createLeaf(T elem) {
        destroy(root);
        root = new Node(elem, nullptr, nullptr);
    }

    void createBT(BT& left, T elem, BT& right) {
        destroy(root);
        root = new Node(elem, copy(left.root), copy(right.root));
    }

    bool empty() {
        return root == nullptr;
    }

    int height() {
        return height(root);
    }
    int size() {
        return size(root);
    }
    bool search(T elem) {
        return search(root, elem);
    }

    void inorder(functionP<T> f) {
        visitInorder(root, f);
    }
};
