#include "avl-tree.h"

// recalibrates node's height and balance factor
void AvlTree::computeHeightandBalance(TreeNode* node) {

    if (node->right && node->left) {
        node->height = 1 + std::max(node->left->height, node->right->height);
        node->balanceFactor = node->left->height - node->right->height;
    }
    else if (node->left) {
        node->height = 1 + node->left->height;
        node->balanceFactor = node->left->height;
    }
    else {
        node->height = 1 + node->right->height;
        node->balanceFactor = -1 * node->right->height;
    }
}


TreeNode* AvlTree::rotateLeft(TreeNode* node) {
    std::cout << "performing left rotate" << std::endl;
    TreeNode* grandchild = node->right->left;
    TreeNode* newParent = node->right;
    newParent->left = node;
    node->right = grandchild;

    // // computing node's height and balance factor
    // computeHeightandBalance(node);
    // computeHeightandBalance(newParent);

    return newParent;
}

TreeNode* AvlTree::rotateRight(TreeNode* node) {
    std::cout << "performing right rotate" << std::endl;
    TreeNode* grandchild = node->left->right;
    TreeNode* newParent = node->left;
    newParent->right = node;
    node->left = grandchild;

    // // computing node's height and balance factor
    // computeHeightandBalance(node);
    // computeHeightandBalance(newParent);

    return newParent;
}

TreeNode* AvlTree::rotateLeftRight(TreeNode* node) {
    std::cout << "performing left right rotate" << std::endl;
    return rotateRight(rotateLeft(root));
}

TreeNode* AvlTree::rotateRightLeft(TreeNode* node) {
    std::cout << "performing right left rotate" << std::endl;
    return rotateLeft(rotateRight(root));
}



TreeNode* AvlTree::insertHelper(TreeNode* root, std::string name, int id) {

    if (!root) {
        std::cout << "successful" << std::endl;
        return new TreeNode(name, id);
    }

    // inserting node
    if (id < root->id)
        root->left = insertHelper(root->left, name, id);
    else if (id > root->id)  
        root->right = insertHelper(root->right, name, id);
    else {
        std::cout << "unsuccessful" << std::endl;
        return root;
    }
        

    // computing node's height and balance factor
    computeHeightandBalance(root);

    // balancing tree if necessary
    // do epic rotations here!
    // we'll have to recalculate the balance factors here again
    
    // if (root->balanceFactor == 2) {
    //     if (root->left->balanceFactor == 1)
    //         return rotateRight(root);
    //     else    
    //         return rotateLeftRight(root);
    // }
        
    // else if (root->balanceFactor == -2) {
    //     if (root->right->balanceFactor == -1)
    //         return rotateLeft(root);
    //     else 
    //         return rotateRightLeft(root);
    // }
        

    // if (root->balanceFactor == 2)
    //     if (root->left->balanceFactor == 1)
    //         rotateRight(root);
    //     else    
    //         rotateLeftRight(root);
    // else if (root->balanceFactor == -2)
    //     if (root->right->balanceFactor == -1)
    //         rotateLeft(root);
    //     else 
    //         rotateRightLeft(root);



    return root;
}


void AvlTree::insert(std::string name, int id) {

    // if id is not 8 digits
    if (id % 10000000 == id || id % 100000000 != id) {
        std::cout << "unsuccessful" << std::endl;
        return;
    }

    // if tree is empty
    if (!root) {
        root = new TreeNode(name, id);
        std::cout << "successful" << std::endl;
        return;
    }

    insertHelper(root, name, id);
}

