#include "avl-tree.h"
#include <iostream>

int main() {

    // AvlTree tree = AvlTree(0, "name");
    AvlTree tree = AvlTree();

    for (int i = 1; i < 21; i++) 
        tree.insert("name", i);

    std::cout << tree.root->height;

    return 0;
}