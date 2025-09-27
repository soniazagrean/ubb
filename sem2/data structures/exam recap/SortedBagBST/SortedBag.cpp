//
// Created by Sonia Zagrean on 27.05.2025.
//

#include "SortedBag.h"

#include <functional>

#include "SortedBagIterator.h"

SortedBag::SortedBag(Relation r) : head(nullptr), len(0), r(r){
}

void SortedBag::add(TComp e) {
    if (head == nullptr) {
        head = new Node(e, 1, nullptr, nullptr);
        len++;
        return;
    }

    Node* current = head;
    Node* parent = nullptr;
    while (current != nullptr) {
        if (current->data == e) {
            current->freq++;
            len++;
            return;
        }
        parent = current;
        // For BST: go left if e < current->data, right if e > current->data
        // We need to determine strict ordering from the relation
        if (e < current->data)
            current = current->left;
        else
            current = current->right;
    }
    Node* newNode = new Node(e, 1, nullptr, nullptr);
    if (e < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
    len++;
}

bool SortedBag::remove(TComp e) {
    Node* current = head;
    Node* parent = nullptr;

    // Find the node using strict comparison
    while (current != nullptr && current->data != e) {
        parent = current;
        if (e < current->data)
            current = current->left;
        else
            current = current->right;
    }

    if (current == nullptr)
        return false;

    // Frequency case
    if (current->freq > 1) {
        current->freq--;
        len--;
        return true;
    }

    // Now we remove the node from the BST
    Node* replacement = nullptr;

    if (current->left == nullptr) {
        replacement = current->right;
    }
    else if (current->right == nullptr) {
        replacement = current->left;
    } else
        {
        // Find in-order successor (smallest in right subtree)
        Node* succParent = current;
        Node* succ = current->right;

        while (succ->left != nullptr) {
            succParent = succ;
            succ = succ->left;
        }

        // Copy successor data
        current->data = succ->data;
        current->freq = succ->freq;

        // Remove successor
        if (succParent->left == succ)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;

        delete succ;
        len--;
        return true;
    }

    // If we're here, replacement is left or right child (or nullptr)
    if (parent == nullptr) {
        // Removing the root
        delete current;
        head = replacement;
    }
    else if (parent->left == current) {
        delete current;
        parent->left = replacement;
    }
    else {
        delete current;
        parent->right = replacement;
    }

    len--;
    return true;
}


bool SortedBag::search(TComp e) const {
    Node* current = head;
    while (current != nullptr) {
        if (e == current->data)
            return true;
        if (e < current->data)
            current = current->left;
        else
            current = current->right;
    }
    return false;
}


int SortedBag::nrOccurrences(TComp e) const {
    Node* current = head;
    while (current != nullptr) {
        if (e == current->data)
            return current->freq;
        if (e < current->data)
            current = current->left;
        else
            current = current->right;
    }
    return 0;
}

int SortedBag::size() const {
    return len;
}

SortedBagIterator SortedBag::iterator() const {
    return SortedBagIterator(*this);  // Create and return iterator
}

bool SortedBag::isEmpty() const {
    return len == 0;
}

SortedBag::~SortedBag() {
    std::function<void(Node*)> destroy = [&](Node* node) {
        if (!node) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    };
    destroy(head);
}