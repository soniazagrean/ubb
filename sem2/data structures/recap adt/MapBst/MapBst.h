//
// Created by Sonia Zagrean on 01.06.2025.
//

#ifndef MAP_H
#define MAP_H
#include <algorithm>
#include <stdexcept>

/// property : unique elements , key-value pairs

template <typename K, typename V>
class MapBst {
private:
    struct Node {
        K key;
        V value;
        Node* left;
        Node* right;
        Node(K key, V value, Node* left, Node* right) : key(key), value(value), left(left), right(right){}
    };

    Node* root;
    void destroy(Node* n) {
        if (!n) return;
        destroy(n->left);
        destroy(n->right);
        delete n;
    }
    Node* copy(Node* n) {
        if (!n) return nullptr;
        return new Node(n->key, n->value, copy(n->left), copy(n->right));
    }

    Node* add(Node* n, const K& key, const V& value) {
        if (n == nullptr)
            return new Node(key, value, nullptr, nullptr);
        if (key < n->key)
            n->left = add(n->left, key, value);
        else if (key > n->key)
            n->right = add(n->right, key, value);
        else
            n->value = value;
        return n;
    }
    Node* remove(Node* n, const K& key) {
        if (n == nullptr)
            return nullptr;
        if (key < n->key)
            n->left = remove(n->left, key);
        else if (key > n->key)
            n->right = remove(n->right, key);
        else {
            if (!n->left && !n->right) {
                delete n;
                return nullptr;
            }
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
            Node* successor = n->right;
            while (successor->left != nullptr) {
                successor = successor->left;
            }
            n->key = successor->key;
            n->right = remove(n->right, successor->key);
        }

    }
    bool search(Node* n, const K& key) {
        if (n == nullptr)
            return false;
        if (n->key == key)
            return true;
        if (key < n->key)
            return search(n->left, key);
        return search(n->right, key);
    }
    Node* find(Node* n, const K& key) {
        if (n == nullptr)
            return nullptr;
        if (n->key == key)
            return n;
        if (key < n->key)
            return find(n->left, key);
        return find(n->right, key);
    }

public:
    MapBst(): root(nullptr) {}
    ~MapBst() {
        destroy(root);
    }

    void insert(const K& key, const V& value) {
        root = add(root, key, value);
    }
    void remove(const K& key) {
        root = remove(root, key);
    }
    bool search(const K& key) {
        return search(root, key);
    }
    bool empty() {
        return root == nullptr;
    }
    bool contains(const K& key) {
        return search(key);
    }

    V get(const K& key) {
        Node* node = find(root, key);
        if (node == nullptr)
            throw std::runtime_error("Key not found!");
        return node->value;
    }
};



#endif //MAP_H
