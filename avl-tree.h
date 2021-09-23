#pragma once
#include <iostream>
#include <string>

struct Student {

    int id;
    std::string name;

    Student(int id, std::string name) : id(id), name(name) {}
};

struct TreeNode {

    Student student;
    int height;
    int balanceFactor;
    TreeNode* left;
    TreeNode* right;

    TreeNode(Student& x) : student(x), height(1), balanceFactor(0), left(nullptr), right(nullptr) {}
};

class AvlTree {
    // TreeNode* root;

    // helper functions
    TreeNode* insertHelper(TreeNode* root, Student& newStudent);
public: 

    TreeNode* root;

    AvlTree() : root(nullptr) {}
    AvlTree(int id, std::string name);

    void insert(std::string name, int id);
    void remove(int id);
    void search(int id);
    void search(std::string name);
    void printInorder();
    void printPreorder();
    void printPostorder();
    void printLevelCount();
    void removeInorder(int n);
};