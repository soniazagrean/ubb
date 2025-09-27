// #include <iostream>
//
// #include "BinaryTree.h"
//
// void printInt(int x) {
//     std::cout << x << ' ';
// }
//
// int main() {
//
//     BinaryTree<int> bt, left, right;
//     left.createLeaf(2);
//     right.createLeaf(3);
//     bt.createBinaryTree(left, 1, right);
//     bt.traverse(printInt);
//     return 0;
// }
//
#include <iostream>
#include "BinarySearchTree.h"

void printInt(int x) {
    std::cout << x << " ";
}

int main() {
    BinarySearchTree<int> bst;

    bst.add(50);
    bst.add(30);
    bst.add(70);
    bst.add(20);
    bst.add(40);
    bst.add(60);
    bst.add(80);

    std::cout << "Inorder traversal: ";
    bst.traverseInorder(printInt);
    std::cout << std::endl;

    std::cout << "Search 40: " << (bst.search(40) ? "Found" : "Not found") << std::endl;
    std::cout << "Search 25: " << (bst.search(25) ? "Found" : "Not found") << std::endl;

    return 0;
}
