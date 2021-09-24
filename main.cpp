#include "avl-tree.h"
#include <iostream>

int main() {

    // AvlTree tree = AvlTree();
    AvlTree tree;

    // for (int i = 1; i < 5; i++) 
    //     tree.insert("name", i);

    tree.insert("3", "00000003");
    tree.insert("2", "00000002");
    tree.insert("1", "00000001");
    tree.insert("8", "00000008");
    tree.insert("5", "00000005");
    tree.insert("4", "00000004");
    tree.insert("7", "00000007");
    
    // std::cout << tree.root->balanceFactor;

    tree.printLevelCount();


    return 0;
}