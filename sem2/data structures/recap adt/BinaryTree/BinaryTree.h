//
// Created by Sonia Zagrean on 01.06.2025.
//

#ifndef BINARYTREE_H
#define BINARYTREE_H


template <typename T>
class BinaryTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(T data, Node* left, Node* right) : data(data), left(left), right(right) {}
    };

    Node* root;
    Node* copy(Node* n) {
        if (n == nullptr)
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

    void preorder(Node* n, void (*visit)(T)) {
        if (!n)
            return;
        visit(n->data);
        preorder(n->left, visit);
        preorder(n->right, visit);
    }

public:
    BinaryTree(): root(nullptr) {}
    ~BinaryTree() {
        destroy(root);
    }
    void createLeaf(const T& elem) {
        destroy(root);
        root = new Node(elem, nullptr, nullptr);
    }
    void createBinaryTree(const BinaryTree& left, const T& elem, const BinaryTree& right) {
        destroy(root);
        root = new Node(elem, copy(left.root), copy(right.root));
    }

    bool isEmpty() {
        return root == nullptr;
    }

    T getData() {
        return root->data;
    }
    BinaryTree getLeftSubtree() {
        BinaryTree t;
        t.root = copy(root ? root->left : nullptr);
        return t;
    }
    BinaryTree getRightSubtree() {
        BinaryTree t;
        t.root = copy(root ? root->right : nullptr);
        return t;
    }
    void traverse(void (*visit)(T)) {
        preorder(root, visit);
    }
};



#endif //BINARYTREE_H
