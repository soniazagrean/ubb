#include <iostream>

#include "BT.h"

void afiseazaInt(int x) {
    std::cout << x << " ";
}

int main() {
    BT tree1, tree2, tree3, tree4, tree5;
    tree1.createLeaf(1);
    tree2.createLeaf(2);
    tree3.createLeaf(3);
    tree4.createLeaf(4);
    tree5.createLeaf(5);

    BT leftSubtree, rightSubtree;
    BT b;
    leftSubtree.createBT(tree1, 2, tree3);
    rightSubtree.createBT(tree4, 5, b);

    BT mainTree;
    mainTree.createBT(leftSubtree, 10, rightSubtree);

    std::cout << "Preorder traversal: ";
    mainTree.visitTree(afiseazaInt, "preordine");
    std::cout << "\n";

    std::cout << "Inorder traversal: ";
    mainTree.visitTree(afiseazaInt, "inordine");
    std::cout << "\n";

    std::cout << "Postorder traversal: ";
    mainTree.visitTree(afiseazaInt, "postordine");
    std::cout << "\n";

    // Example of accessing subtrees
    if (!mainTree.empty()) {
        std::cout << "Root value: " << mainTree.get() << "\n";

        BT leftTree = mainTree.left();
        if (!leftTree.empty())
            std::cout << "Left subtree root: " << leftTree.get() << "\n";


        BT rightTree = mainTree.right();
        if (!rightTree.empty())
            std::cout << "Right subtree root: " << rightTree.get() << "\n";

    }
    return 0;
}
