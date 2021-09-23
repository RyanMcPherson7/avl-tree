#include "avl-tree.h"
#include <iostream>

int main() {

    AvlTree tree = AvlTree(21, "name2");
    // AvlTree tree = AvlTree();

    // for (int i = 1; i < 5; i++) 
    //     tree.insert("name", i);

    tree.insert("name3", 3);
    tree.insert("name1", 2);


    std::cout << tree.root->student.name << std::endl;


    return 0;
}