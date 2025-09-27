//
// Created by Sonia Zagrean on 27.05.2025.
//

#pragma once

class SortedBag;
class SortedBagIterator;

class Node {
private:
    int data;
    int freq;
    Node* left;
    Node* right;

    friend class SortedBag;
    friend class SortedBagIterator;

public:
    Node(int data, int freq, Node* left, Node* right) : data(data), freq(freq), left(left), right(right) {}
    ~Node()=default;
};



