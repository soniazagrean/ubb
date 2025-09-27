#include <iostream>

#include "BST.h"
#include "BT.h"

void printInt(int x) {
    std::cout << x << ' ';
}

int main() {

    BT<int> treeLeft, treeRight, tree;
    BT<int> treeLeft1, treeRight1, tree1;
    BT<int> tree2;

    treeLeft.createLeaf(2);
    treeRight.createLeaf(3);

    treeLeft1.createLeaf(5);
    treeRight1.createLeaf(6);

    tree.createBT(treeLeft, 1, treeRight);
    tree1.createBT(treeLeft1, 4, treeRight1);

    tree2.createBT(tree, 7, tree1);


    std::cout << "Preordine: ";
    tree2.visitTree(printInt, "preordine");
    std::cout << "\nInordine: ";
    tree2.visitTree(printInt, "inordine");
    std::cout << "\nPostordine: ";
    tree2.visitTree(printInt, "postordine");
    std::cout << '\n';


    BST<int> bst;
    bst.add(50);
    bst.add(30);
    bst.add(70);
    bst.add(20);
    bst.add(40);
    bst.add(60);
    bst.add(80);

    std::cout << "Inorder traversal: ";
    bst.visitTree(printInt, "inordine");  // should print sorted values
    std::cout << "\n";

    std::cout << "Search 60: " << (bst.search(60) ? "found" : "not found") << "\n";

    bst.remove(50); // remove root node
    std::cout << "After deleting 50: ";
    bst.visitTree(printInt, "inordine");
    std::cout << "\n";
    return 0;
}
