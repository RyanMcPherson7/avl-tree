#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define PRP "\e[0;35m"
#define CYN "\e[0;36m"

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
    bool idValid(const string& id);
    bool nameValid(const string& name);
    TreeNode* insertHelper(TreeNode* root, const string& name, const string& id);
    void HeightBalance(TreeNode* node);
    TreeNode* rotateLeft(TreeNode* node);
    TreeNode* rotateRight(TreeNode* node);
    TreeNode* rotateLeftRight(TreeNode* node);
    TreeNode* rotateRightLeft(TreeNode* node);
    TreeNode* removeHelper(TreeNode* node, const string& id);
    void searchIdHelper(TreeNode* node, const string& id);
    void searchNameHelper(TreeNode* node, const string& name, string& output);
    void inorderHelper(TreeNode* node, string& output);
    void preorderHelper(TreeNode* node, string& output);
    void postorderHelper(TreeNode* node, string& output);
    void removeInorderHelper(TreeNode* node, vector<string>& output);
public: 

    AvlTree() : root(nullptr) {}
    void insert(const string& name, const string& id); 
    void remove(const string& id);               
    void searchId(const string& id);             
    void searchName(const string& name);         
    string printInorder();                   
    string printPreorder();                  
    string printPostorder();                 
    int printLevelCount();                
    void removeInorder(int n);             
};


// returns true if input id is valid
bool AvlTree::idValid(const string& id) {

    // if id is not 8 digits
    if (id.length() != 8) {
        cout << RED "unsuccessful" CYN << endl;
        return false;
    }

    // if id contains non-numbers
    for (int i = 0; i < id.length(); i++) {
        if (id[i] < '0' || id[i] > '9') {
            cout << RED "unsuccessful" CYN << endl;
            return false;
        }
    }

    return true;
}

// returns true if input name is valid
bool AvlTree::nameValid(const string& name) {

    // if name contains non-letters
    for (int i = 0; i < name.length(); i++) {
        if (!(name[i] >= 'a' && name[i] <= 'z') && !(name[i] >= 'A' && name[i] <= 'Z') && name[i] != ' ') {
            cout << RED "unsuccessful" CYN << endl;
            return false;
        }
    }

    return true;
}


// recalibrates node's height and balance factor
void AvlTree::HeightBalance(TreeNode* node) {

    if (!node) return;

    if (node->right && node->left) {
        node->height = 1 + max(node->left->height, node->right->height);
        node->balanceFactor = node->left->height - node->right->height;
    }
    else if (node->left) {
        node->height = 1 + node->left->height;
        node->balanceFactor = node->left->height;
    }
    else if (node->right) {
        node->height = 1 + node->right->height;
        node->balanceFactor = -1 * node->right->height;
    }
    else {
        node->height = 1;
        node->balanceFactor = 0;
    }
}



TreeNode* AvlTree::rotateLeft(TreeNode* node) {

    TreeNode* grandchild = node->right->left;
    TreeNode* newParent = node->right;
    newParent->left = node;
    node->right = grandchild;

    // computing node's height and balance factor
    HeightBalance(node);
    HeightBalance(newParent);

    return newParent;
}


TreeNode* AvlTree::rotateRight(TreeNode* node) {

    TreeNode* grandchild = node->left->right;
    TreeNode* newParent = node->left;
    newParent->right = node;
    node->left = grandchild;

    // computing node's height and balance factor
    HeightBalance(node);
    HeightBalance(newParent);

    return newParent;
}


TreeNode* AvlTree::rotateLeftRight(TreeNode* node) {

    node->left = rotateLeft(node->left);
    return rotateRight(node);
}


TreeNode* AvlTree::rotateRightLeft(TreeNode* node) {

    node->right = rotateRight(node->right);
    return rotateLeft(node);
}



TreeNode* AvlTree::insertHelper(TreeNode* node, const string& name, const string& id) {

    if (!node) {
        cout << GRN "successful" CYN << endl;
        return new TreeNode(name, id);
    }

    // inserting node
    if (stoi(id) < stoi(node->id))
        node->left = insertHelper(node->left, name, id);
    else if (stoi(id) > stoi(node->id))  
        node->right = insertHelper(node->right, name, id);
    else {
        cout << RED "unsuccessful" CYN << endl;
        return node;
    }
        

    // computing node's height and balance factor
    HeightBalance(node);


    // balancing tree if necessary
    if (node->balanceFactor == 2) {
        if (node->left->balanceFactor == 1)
            return rotateRight(node);
        else    
            return rotateLeftRight(node);
    }
        
    else if (node->balanceFactor == -2) {
        if (node->right->balanceFactor == -1)
            return rotateLeft(node);
        else 
            return rotateRightLeft(node);
    }


    return node;
}


void AvlTree::insert(const string& name, const string& id) {

    if (!idValid(id)) return;
    if (!nameValid(name)) return;

    // if tree is empty
    if (!root) {
        root = new TreeNode(name, id);
        cout << GRN "successful" CYN << endl;
        return;
    }

    root = insertHelper(root, name, id);
}



TreeNode* AvlTree::removeHelper(TreeNode* node, const string& id) {

    if (!node) {
        cout << RED "unsuccessful" CYN << endl;
        return nullptr;
    }
        
    else if (stoi(id) < stoi(node->id))
        node->left = removeHelper(node->left, id);

    else if (stoi(id) > stoi(node->id))
        node->right = removeHelper(node->right, id);

    // matching node found
    else if (stoi(id) == stoi(node->id)) {
        
        cout << GRN "successful" CYN << endl;

        if (node->left && node->right) {

            // finding inorder successor
            TreeNode* successor = node->right;
            TreeNode* successorParent = node;
            while (successor->left) {
                successorParent = successor;
                successor = successor->left;
            } 
                
            // updating node
            node->name = successor->name;
            node->id = successor->id;

            // placing successor's child
            if (successor = node->right) 
                node->right = successor->right;
            else
                successorParent->left = successor->right;
            
            delete successor;
        }
        // if node to remove does not have 2 children
        else {
            TreeNode* replacement = nullptr;

            if (node->left) 
                replacement = node->left;
            else if (node->right)
                replacement = node->right;

            delete node;
            
            HeightBalance(replacement);
            return replacement;
        }

        
    }
    // matching node not found
    else {
        cout << RED "unsuccessful" CYN << endl;
        return nullptr;
    }


    HeightBalance(node);
    return node;
}


void AvlTree::remove(const string& id) {

    if (!idValid(id)) return;

    root = removeHelper(root, id);
}



void AvlTree::searchIdHelper(TreeNode* node, const string& id) {

    if (!node) 
        cout << RED "unsuccessful" CYN << endl;
    else if (stoi(id) == stoi(node->id))
        cout << PRP << node->name << CYN << endl;
    else if (stoi(id) < stoi(node->id))
        searchIdHelper(node->left, id);
    else
        searchIdHelper(node->right, id);
}


void AvlTree::searchId(const string& id) {

    if (!idValid(id)) return;

    searchIdHelper(root, id);
}



void AvlTree::searchNameHelper(TreeNode* node, const string& name, string& output) {

    if (node) {
        if (node->name == name)
            output += node->id + "\n";
        
        searchNameHelper(node->left, name, output);
        searchNameHelper(node->right, name, output);
    }
}


void AvlTree::searchName(const string& name) {

    if (!nameValid(name)) return;

    string output;
    searchNameHelper(root, name, output);

    if (output.length() == 0)
        cout << RED "unsuccessful" CYN << endl;
    else 
        cout << PRP << output << CYN;
}



void AvlTree::inorderHelper(TreeNode* node, string& output) {

    if (node) {
        inorderHelper(node->left, output);
        output +=  node->name + ", ";
        inorderHelper(node->right, output);
    }
}


string AvlTree::printInorder() {

    string output = "";
    inorderHelper(root, output);
    
    if (output.length() != 0) {
        output = output.substr(0, output.length() - 2);
        cout << PRP << output << CYN << endl;
    }

    return output;
}



void AvlTree::preorderHelper(TreeNode* node, string& output) {

    if (node) {
        output += node->name + ", ";
        preorderHelper(node->left, output);
        preorderHelper(node->right, output);
    }
}


string AvlTree::printPreorder() {
    string output = "";
    preorderHelper(root, output);

    if (output.length() != 0) {
        output = output.substr(0, output.length() - 2);
        cout << PRP << output << CYN << endl;
    }
        
    return output;
}



void AvlTree::postorderHelper(TreeNode* node, string& output) {

    if (node) {
        postorderHelper(node->left, output);
        postorderHelper(node->right, output);
        output += node->name + ", ";
    }
}


string AvlTree::printPostorder() {
    string output = "";
    postorderHelper(root, output);

    if (output.length() != 0) {
        output = output.substr(0, output.length() - 2);
        cout << PRP << output << CYN << endl;
    }

    return output;
}



int AvlTree::printLevelCount() {

    int levelCount = !root ? 0 : root->height;
    
    cout << PRP <<  levelCount << CYN << endl;
    return levelCount;
}



void AvlTree::removeInorderHelper(TreeNode* node, vector<string>& output) {
    
    if (node) {
        removeInorderHelper(node->left, output);
        output.push_back(node->id);
        removeInorderHelper(node->right, output);
    }
}


void AvlTree::removeInorder(int n) {

    vector<string> output;
    removeInorderHelper(root, output);

    if (n > output.size() - 1)
        cout << RED "unsuccessful" CYN << endl;
    else
        remove(output.at(n));
}


// functions for parsing input in main
string parseNoQuotes(string& command) {

    int spaceIndex = command.find(" ");
    string data = command.substr(spaceIndex + 1, command.length() - 1);
    return data;
}


string parseQuotes(string& command) {

    int spaceIndex = command.find(" ");
    command = command.substr(spaceIndex + 2, command.length() - 1);
    int quoteIndex = command.find("\"");
    string data = command.substr(0, quoteIndex);
    return data;
}