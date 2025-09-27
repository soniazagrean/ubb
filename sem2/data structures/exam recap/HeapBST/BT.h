//
// Created by Sonia Zagrean on 30.05.2025.
//

#pragma once
#include <cstring>
#include <stdexcept>

template <typename TElem>
using PFunction = void (*)(TElem);

template <typename TElem>
class BT {
protected:
    struct Node {
        TElem data;
        Node* left;
        Node* right;

        Node(TElem data, Node* left, Node* right) : data(data), left(left), right(right) {}
    };

    Node* root;

    Node *copy(Node *n) {
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
    void visitPreorder(Node* n, PFunction<TElem> function) {
        if (!n)
            return;
        function(n->data);
        visitPreorder(n->left, function);
        visitPreorder(n->right, function);
    }
    void visitPostorder(Node* n, PFunction<TElem> function) {
        if (!n)
            return;
        visitPostorder(n->left, function);
        visitPostorder(n->right, function);
        function(n->data);
    }
    void visitInorder(Node* n, PFunction<TElem> function) {
        if (!n)
            return;
        visitInorder(n->left, function);
        function(n->data);
        visitInorder(n->right, function);
    }

public:
    BT() : root(nullptr) {}
    ~BT() {
        destroy(root);
    }

    void createLeaf(TElem elem) {
        destroy(root);
        root = new Node(elem, nullptr, nullptr);
    }
    void createBT(BT& left, TElem elem, BT& right) {
        destroy(root);
        root = new Node(elem, copy(left.root), copy(right.root));
    }
    void addSubtreeLeft(BT& left) {
        if (!left)
            return;
        destroy(root->left);
        root->left = copy(left.root);
    }
    void addSubtreeRight(BT& right) {
        if (!right)
            return;
        destroy(root->right);
        root->right = copy(right.root);
    }
    bool empty() {
        return root == nullptr;
    }
    BT left() {
        if (!root || !root->left)
            throw std::runtime_error("no left subtree");
        BT<TElem> result;
        result.root = copy(root->left);
        return result;
    }

    BT right() {
        if (!root || !root->right)
            throw std::runtime_error("no right subtree");
        BT<TElem> result;
        result.root = copy(root->right);
        return result;
    }
    void visitTree(PFunction<TElem> f, const char* order) {
        if (strcmp(order, "preordine") == 0)
            visitPreorder(root, f);
        else if (strcmp(order, "postordine") == 0)
            visitPostorder(root, f);
        else
            visitInorder(root, f);
    }

};

