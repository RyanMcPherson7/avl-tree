#include "avl-tree.h"

// recalibrates node's height and balance factor
void AvlTree::computeHeightandBalance(TreeNode* node) {

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

    if (node == root) root = newParent;

    // computing node's height and balance factor
    computeHeightandBalance(node);
    computeHeightandBalance(newParent);

    return newParent;
}

TreeNode* AvlTree::rotateRight(TreeNode* node) {

    TreeNode* grandchild = node->left->right;
    TreeNode* newParent = node->left;
    newParent->right = node;
    node->left = grandchild;

    if (node == root) root = newParent;

    // computing node's height and balance factor
    computeHeightandBalance(node);
    computeHeightandBalance(newParent);

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



TreeNode* AvlTree::insertHelper(TreeNode* node, string name, string id) {

    if (!node) {
        cout << "successful" << endl;
        return new TreeNode(name, id);
    }

    // inserting node
    if (stoi(id) < stoi(node->id))
        node->left = insertHelper(node->left, name, id);
    else if (stoi(id) > stoi(node->id))  
        node->right = insertHelper(node->right, name, id);
    else {
        cout << "unsuccessful" << endl;
        return node;
    }
        

    // computing node's height and balance factor
    computeHeightandBalance(node);


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


void AvlTree::insert(string name, string id) {

    // if id is not 8 digits
    if (id.length() != 8) {
        cout << "unsuccessful" << endl;
        return;
    }

    // if tree is empty
    if (!root) {
        root = new TreeNode(name, id);
        cout << "successful" << endl;
        return;
    }

    insertHelper(root, name, id);
}














void AvlTree::searchIdHelper(TreeNode* node, string id) {

    if (!node) 
        cout << "unsuccessful" << endl;
    else if (stoi(id) == stoi(node->id))
        cout << node->name << endl;
    else if (stoi(id) < stoi(node->id))
        searchIdHelper(node->left, id);
    else
        searchIdHelper(node->right, id);
}

void AvlTree::searchId(string id) {
    searchIdHelper(root, id);
}


void AvlTree::searchNameHelper(TreeNode* node, string name, string& output) {

    if (node) {
        if (node->name == name)
            output += node->id + "\n";
        
        searchNameHelper(node->left, name, output);
        searchNameHelper(node->right, name, output);
    }
}

void AvlTree::searchName(string name) {

    string output = "";
    searchNameHelper(root, name, output);

    if (output == "")
        cout << "unsuccessful" << endl;
    else 
        cout << output;
}



void AvlTree::inorderHelper(TreeNode* node) {

    if (node) {
        inorderHelper(node->left);
        cout << node->name << ", ";
        inorderHelper(node->right);
    }
}

void AvlTree::printInorder() {
    inorderHelper(root);
    cout << endl;
}


void AvlTree::preorderHelper(TreeNode* node) {

    if (node) {
        cout << node->name << ", ";
        preorderHelper(node->left);
        preorderHelper(node->right);
    }
}

void AvlTree::printPreorder() {
    preorderHelper(root);
    cout << endl;
}


void AvlTree::postorderHelper(TreeNode* node) {

    if (node) {
        postorderHelper(node->left);
        postorderHelper(node->right);
        cout << node->name << ", ";
    }
}

void AvlTree::printPostorder() {
    postorderHelper(root);
    cout << endl;
}


void AvlTree::printLevelCount() {

    if (!root)
        cout << 0 << endl;
    else 
        cout << root->height << endl;
}