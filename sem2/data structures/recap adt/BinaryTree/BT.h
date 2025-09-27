//
// Created by Sonia Zagrean on 02.06.2025.
//

#ifndef BT_H
#define BT_H


template <typename T>
class BT {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(T data, Node* left, Node* right): data(data), left(left), right(right){}
    };

    Node* root;

    void destroy(Node* n) {
        if (n == nullptr)
            return;
        destroy(n->left);
        destroy(n->right);

        delete n;
    }

    Node* copy(Node * n) {
        if (n == nullptr)
            return nullptr;
        return new Node(n->data, copy(n->left), copy(n->right));
    }

    void preorder(Node* n, void (*visit)(T)) {
        if (n == nullptr)
            return;
        visit(n->data);
        preorder(n->left, visit);
        preorder(n->right, visit);
    }

public:
    BT() : root(nullptr){}
    ~BT() {
        destroy(root);
    }

    void createLeaf(const T& elem) {
        destroy(root);
        root = new Node(elem, nullptr, nullptr);
    }

    void createBT(const T& elem, Node* left, Node* right) {
        destroy(root);
        root = new Node(elem, copy(left.root), copy(right.root));
    }

    BT leftSub() {
        BT t;
        t.root = copy(root ? root->left : nullptr);
        return t;
    }

    BT rightSub() {
        BT t;
        t.root = copy(root? root->right : nullptr);
        return t;
    }

    bool empty() {
        return root == nullptr;
    }
    T getData() {
        return root->data;
    }

    void traverse(void (*visit)(T)) {
        preorder(root, visit);
    }
};



#endif //BT_H
