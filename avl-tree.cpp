#include "avl-tree.h"

AvlTree::AvlTree(int id, std::string name) {
    Student newStudent = Student(id, name);
    root = new TreeNode(newStudent); 
}

TreeNode* AvlTree::rotateLeft(TreeNode* node) {
    std::cout << "performing left rotate" << std::endl;
    TreeNode* grandchild = node->right->left;
    TreeNode* newParent = node->right;
    newParent->left = node;
    node->right = grandchild;
    return newParent;
}

TreeNode* AvlTree::rotateRight(TreeNode* node) {
    std::cout << "performing right rotate" << std::endl;
    TreeNode* grandchild = node->left->right;
    TreeNode* newParent = node->left;
    newParent->right = node;
    node->left = grandchild;
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



TreeNode* AvlTree::insertHelper(TreeNode* root, Student& newStudent) {

    if (!root) {
        std::cout << "successful" << std::endl;
        return new TreeNode(newStudent);
    }

    // inserting node
    if (newStudent.id < root->student.id)
        root->left = insertHelper(root->left, newStudent);
    else if (newStudent.id > root->student.id)  
        root->right = insertHelper(root->right, newStudent);
    else {
        std::cout << "unsuccessful" << std::endl;
        return root;
    }
        

    // computing node's height and balance factor
    if (root->right && root->left) {
        root->height = 1 + std::max(root->left->height, root->right->height);
        root->balanceFactor = root->left->height - root->right->height;
    }
    else if (root->left) {
        root->height = 1 + root->left->height;
        root->balanceFactor = root->left->height;
    }
    else {
        root->height = 1 + root->right->height;
        root->balanceFactor = -1 * root->right->height;
    }
        

    // balancing tree if necessary
    // do epic rotations here!
    // we'll have to recalculate the balance factors here again
    
    if (root->balanceFactor == 2) {
        if (root->left->balanceFactor == 1)
            return rotateRight(root);
        else    
            return rotateLeftRight(root);
    }
        
    else if (root->balanceFactor == -2) {
        if (root->right->balanceFactor == -1)
            return rotateLeft(root);
        else 
            return rotateRightLeft(root);
    }
        

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

    Student newStudent = Student(id, name);

    // if tree is empty
    if (!root) {
        root = new TreeNode(newStudent);
        return;
    }

    insertHelper(root, newStudent);
}

