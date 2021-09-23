#include "avl-tree.h"
#include <iostream>

int main() {

    AvlTree tree = AvlTree(5, "name");
    // AvlTree tree = AvlTree();

    tree.insert("supa cool name", 3);
    tree.insert("other name...", 7);
    tree.insert("other name...", 4);
    tree.insert("other name...", 2);
    tree.insert("other name...", 8);
    tree.insert("other name...", 9);


    std::cout << tree.root->right->balanceFactor;

    return 0;
}