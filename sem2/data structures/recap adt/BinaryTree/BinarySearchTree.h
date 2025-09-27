//
// Created by Sonia Zagrean on 01.06.2025.
//

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

template <typename T>
class BinarySearchTree {
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
        if (n == nullptr)
            return;
        destroy(n->left);
        destroy(n->right);
        delete n;
    }
    Node* insert(Node* n, const T& elem) {   // elem din subarborele stang < radacina < elem din subarborele drept
        if (n == nullptr)
            return new Node(elem, nullptr, nullptr);
        if (elem < n->data)
            n->left = insert(n->left, elem);
        else if (elem > n->data)
            n->right = insert(n->right, elem);
        return n;
    }
    bool search(Node* n, const T& elem) {
        if (n == nullptr)
            return false;
        if (n->data == elem)
            return true;
        else if (elem < n->data)
            return search(n->left, elem);
        else if (elem > n->data)
            return search(n->right, elem);

    }
    void inorder(Node* n, void (*visit)(T)) const {
        if (n == nullptr)
            return;
        inorder(n->left, visit);
        visit(n->data);
        inorder(n->right, visit);
    }

public:
    BinarySearchTree(): root(nullptr) {}
    ~BinarySearchTree() {
        destroy(root);
    }
    void add(const T& elem) {
        root = insert(root, elem);
    }
    bool search(const T& elem) {
        return search(root, elem);
    }
    bool isEmpty() {
        return root == nullptr;
    }
    void traverseInorder(void (*visit)(T)) const {
        inorder(root, visit);
    }
};



#endif //BINARYSEARCHTREE_H
