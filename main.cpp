#include "avl-tree.h"
#include <iostream>

int main() {

    // AvlTree tree = AvlTree();
    AvlTree tree;

    // for (int i = 8; i > 0; i--) 
    //     tree.insert("name", "0000000" + std::to_string(i));

    tree.insert("1", "00000001");
    tree.insert("22", "00000022");
    tree.insert("4", "00000004");
    tree.insert("62", "00000062");
    tree.insert("97", "00000097");
    tree.insert("7", "00000007");
    tree.insert("98", "00000098");
    tree.insert("18", "00000018");
    tree.insert("19", "00000019");

    // pretty sure rightLeft and leftRight are still broken...

    std::cout << tree.root->right->left->name << std::endl;

    // tree.printLevelCount();

    return 0;
}