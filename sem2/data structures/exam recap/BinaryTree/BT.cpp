//
// Created by Sonia Zagrean on 27.05.2025.
//

#include "BT.h"

#include <cstring>

Node* BT::copy(Node* n) {
    if (!n)
        return nullptr;
    return new Node(n->data, copy(n->left), copy(n->right));
}

void BT::destroy(Node *n) {
    if (n != nullptr) {
        destroy(n->left);
        destroy(n->right);
        delete n;
    }
}

void BT::visitPreorder(Node *n, PFunction p) {
    if (!n)
        return;
    p(n->data);
    visitPreorder(n->left, p);
    visitPreorder(n->right, p);
}

void BT::visitInorder(Node *n, PFunction p) {
    if (!n)
        return;
    visitInorder(n->left, p);
    p(n->data);
    visitInorder(n->right, p);
}

void BT::visitPostorder(Node *n, PFunction p) {
    if (!n)
        return;
    visitPostorder(n->left, p);
    visitPostorder(n->right, p);
    p(n->data);
}

BT::BT() : root(nullptr) {}

BT::~BT() {
    destroy(root);
}

void BT::createLeaf(int elem) {
    destroy(root);
    root = new Node(elem, nullptr, nullptr);
}

void BT::createBT(BT &left, int elem, BT &right) {
    destroy(root);
    root = new Node(elem,copy(left.root), copy(right.root));
}

void BT::addSubtreeLeft(BT &left) {
    if (root) {
        destroy(root->left);
        root->left = copy(left.root);
    }
}

void BT::addSubtreeRight(BT &right) {
    if (root) {
        destroy(root->right);
        root->right = copy(right.root);
    }
}

int BT::get() {
    return root->data;
}

bool BT::empty() {
    return root == nullptr;
}

BT BT::left() {
    BT st;
    st.root = copy(root->left);
    return st;
}

BT BT::right() {
    BT dr;
    dr.root = copy(root->right);
    return dr;
}

void BT::visitTree(PFunction p, char *mes) {
    if (strcmp(mes, "preordine") == 0)
        visitPreorder(root, p);
    else if (strcmp(mes, "postordine") == 0)
        visitPostorder(root, p);
    else
        visitInorder(root, p);
}
