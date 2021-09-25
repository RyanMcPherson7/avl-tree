#pragma once
#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct TreeNode {

    string name;
    string id;
    int height;
    int balanceFactor;
    TreeNode* left;
    TreeNode* right;

    TreeNode(string name, string id) : name(name), id(id), 
    height(1), balanceFactor(0), left(nullptr), right(nullptr) {}
};

class AvlTree {
    TreeNode* root;

    // helper functions
    TreeNode* insertHelper(TreeNode* root, string& name, string& id);
    void computeHeightandBalance(TreeNode* node);
    TreeNode* rotateLeft(TreeNode* node);
    TreeNode* rotateRight(TreeNode* node);
    TreeNode* rotateLeftRight(TreeNode* node);
    TreeNode* rotateRightLeft(TreeNode* node);
    void searchIdHelper(TreeNode* node, string& id);
    void searchNameHelper(TreeNode* node, string& name, string& output);
    void inorderHelper(TreeNode* node, string& output);
    void preorderHelper(TreeNode* node, string& output);
    void postorderHelper(TreeNode* node, string& output);
public: 

    AvlTree() : root(nullptr) {}
    void insert(string& name, string& id); // done
    void remove(string& id);               // not started
    void searchId(string& id);             // done
    void searchName(string& name);         // done
    void printInorder();                   // need to fix (last comma)
    void printPreorder();                  // need to fix (last comma)
    void printPostorder();                 // need to fix (last comma)
    void printLevelCount();                // done
    void removeInorder(int n);             // not started
};