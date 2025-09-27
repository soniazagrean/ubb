//
// Created by Sonia Zagrean on 27.05.2025.
//

#pragma once
#include "Node.h"

using PFunction = void(*)(int);

class BT {
private:
    Node* root;

    Node* copy(Node* n);
    void destroy(Node* n);
    void visitPreorder(Node* n, PFunction p);
    void visitInorder(Node* n, PFunction p);
    void visitPostorder(Node* n, PFunction p);

public:
    BT();
    ~BT();

    void createLeaf(int elem);
    void createBT(BT& left, int elem, BT& right);
    void addSubtreeLeft(BT& left);
    void addSubtreeRight(BT& right);
    int get();
    bool empty();
    BT left();
    BT right();

    void visitTree(PFunction p, char* mes = "inordine");

};


