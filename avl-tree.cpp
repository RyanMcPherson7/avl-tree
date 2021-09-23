#include "avl-tree.h"

AvlTree::AvlTree(int id, std::string name) {
    Student newStudent = Student(id, name);
    root = new TreeNode(newStudent); 
}

TreeNode* AvlTree::insertHelper(TreeNode* root, Student& newStudent) {

    // still need to change node heights and balance tree if necessary

    if (!root) return new TreeNode(newStudent);

    if (newStudent.id < root->student.id)
        root->left = insertHelper(root->left, newStudent);
    else    
        root->right = insertHelper(root->right, newStudent);

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

