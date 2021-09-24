#pragma once
#include <iostream>
#include <string>
#include <queue>

struct TreeNode {

    std::string name;
    std::string id;
    int height;
    int balanceFactor;
    TreeNode* left;
    TreeNode* right;

    TreeNode(std::string name, std::string id) : name(name), id(id), 
    height(0), balanceFactor(0), left(nullptr), right(nullptr) {}
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
    void searchIdHelper(TreeNode* root, std::string id);
    void searchNameHelper(TreeNode* node, std::string name, std::string& output);
    void inorderHelper(TreeNode* root);
    void preorderHelper(TreeNode* root);
    void postorderHelper(TreeNode* root);
public: 

    TreeNode* root;

    AvlTree() : root(nullptr) {}

    void insert(std::string name, std::string id);  // almost done
    void remove(std::string id);                    // not started
    void searchId(std::string id);                  // done
    void searchName(std::string name);              // done
    void printInorder();                            // done
    void printPreorder();                           // done
    void printPostorder();                          // done
    void printLevelCount();                         // done
    void removeInorder(int n);                      // not started
};