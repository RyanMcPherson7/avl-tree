#include "avl-tree.h"

AvlTree::AvlTree(int id, std::string name) {
    Student newStudent = Student(id, name);
    root = new TreeNode(newStudent); 
}

TreeNode* AvlTree::insertHelper(TreeNode* root, Student& newStudent) {

    if (!root) return new TreeNode(newStudent);

    // inserting node
    if (newStudent.id < root->student.id)
        root->left = insertHelper(root->left, newStudent);
    else if (newStudent.id > root->student.id)  
        root->right = insertHelper(root->right, newStudent);
    else
        std::cout << "unsuccessful";


    // computing new height
    if (root->right && root->left)
        root->height = 1 + std::max(root->left->height, root->right->height);
    else if (root->left)
        root->height = 1 + root->left->height;
    else 
        root->height = 1 + root->right->height;


    // computing new balance factor
    if (root->right && root->left)
        root->balanceFactor = root->left->height - root->right->height;
    else if (root->left)
        root->balanceFactor = root->left->height;
    else  
        root->balanceFactor = -1 * root->right->height;


    // balancing tree if necessary
    // do epic rotations here!

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

