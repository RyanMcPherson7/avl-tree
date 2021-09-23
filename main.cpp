#include "avl-tree.h"
#include <iostream>

int main() {

    AvlTree tree = AvlTree(12341234, "name");
    // AvlTree tree = AvlTree();

    tree.insert("supa cool name", 44444444);
    tree.insert("other name...", 11111111);

    return 0;
}