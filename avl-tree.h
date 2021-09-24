#pragma once
#include <iostream>
#include <string>

struct TreeNode {

    std::string name;
    std::string id;
    int height;
    int balanceFactor;
    TreeNode* left;
    TreeNode* right;

    TreeNode(std::string name, std::string id) : name(name), id(id), 
    height(1), balanceFactor(0), left(nullptr), right(nullptr) {}
};

class AvlTree {
    // TreeNode* root;

    // helper functions
    TreeNode* insertHelper(TreeNode* root, std::string name, std::string id);
    void computeHeightandBalance(TreeNode* node);
    TreeNode* rotateLeft(TreeNode* node);
    TreeNode* rotateRight(TreeNode* node);
    TreeNode* rotateLeftRight(TreeNode* node);
    TreeNode* rotateRightLeft(TreeNode* node);
public: 

    TreeNode* root;

    AvlTree() : root(nullptr) {}

    void insert(std::string name, std::string id);
    void remove(std::string id);
    void searchId(std::string id);
    void searchName(std::string name);
    void printInorder();
    void printPreorder();
    void printPostorder();
    void printLevelCount();
    void removeInorder(int n);
};