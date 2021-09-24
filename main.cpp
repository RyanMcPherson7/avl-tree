#include "avl-tree.h"
#include <iostream>

int main() {

    AvlTree tree = AvlTree();

    // for (int i = 1; i < 5; i++) 
    //     tree.insert("name", i);

    // tree.insert("name3", 3);
    // tree.insert("name1", 2);

    // std::cout << tree.root->height;

    // we should prob make id's strings...
    tree.insert("name1", 1);
    
    tree.insert("name3", 3);
    tree.insert("name2", 2);
    
    


    return 0;
}