#include "avl-tree.h"
#include <iostream>

int main() {

    // AvlTree tree = AvlTree();
    AvlTree tree;

    for (int i = 8; i > 0; i--) 
        tree.insert("name", "0000000" + std::to_string(i));

    // tree.insert("1", "00000001");
    // tree.insert("2", "00000002");
    // tree.insert("3", "00000003");
    // tree.insert("4", "00000004");
    // tree.insert("5", "00000005");
    // tree.insert("6", "00000006");
    // tree.insert("7", "00000007");
    // tree.insert("8", "00000008");

    tree.printLevelCount();


    // std::cout << tree.root->name << std::endl;
    // std::cout << tree.root->left->name << std::endl;
    // std::cout << tree.root->right->name << std::endl;


    // TreeNode* testRoot = new TreeNode("name 1", "1");
    // testRoot->right = new TreeNode("name 2", "2");
    // testRoot->right->right = new TreeNode("name 3", "3");

    // TreeNode* grandchild = testRoot->right->left;
    // TreeNode* newParent = testRoot->right;
    // newParent->left = testRoot;
    // testRoot->right = grandchild;

    // std::cout << newParent->name << std::endl;
    // std::cout << newParent->left->name << std::endl;
    // std::cout << newParent->right->name << std::endl;

    return 0;
}