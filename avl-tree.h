#pragma once
#include <iostream>
#include <string>
#include <vector>

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
    TreeNode* removeHelper(TreeNode* node, string& id);
    void searchIdHelper(TreeNode* node, string& id);
    void searchNameHelper(TreeNode* node, string& name, string& output);
    void inorderHelper(TreeNode* node, string& output);
    void preorderHelper(TreeNode* node, string& output);
    void postorderHelper(TreeNode* node, string& output);
    void removeInorderHelper(TreeNode* node, vector<string>& output);
public: 

    AvlTree() : root(nullptr) {}
    void insert(string& name, string& id); 
    void remove(string& id);               
    void searchId(string& id);             
    void searchName(string& name);         
    void printInorder();                   
    void printPreorder();                  
    void printPostorder();                 
    void printLevelCount();                
    void removeInorder(int n);             
};