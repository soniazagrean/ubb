//
// Created by Sonia Zagrean on 27.05.2025.
//

#pragma once

class BT;

class Node {
private:
    Node* left;
    Node* right;
    int data;

    friend class BT;

public:
    Node(int data, Node* left, Node* right) : data(data), left(left), right(right) {}
    ~Node()=default;
};

