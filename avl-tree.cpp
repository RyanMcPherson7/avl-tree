#include "avl-tree.h"

// recalibrates node's height and balance factor
void AvlTree::computeHeightandBalance(TreeNode* node) {

    if (node->right && node->left) {
        node->height = 1 + std::max(node->left->height, node->right->height);
        node->balanceFactor = node->left->height - node->right->height;
    }
    else if (node->left) {
        node->height = 1 + node->left->height;
        node->balanceFactor = node->left->height;
    }
    else {
        node->height = 1 + node->right->height;
        node->balanceFactor = -1 * node->right->height;
    }
}


TreeNode* AvlTree::rotateLeft(TreeNode* node) {
    std::cout << "performing left rotate" << std::endl;
    TreeNode* grandchild = node->right->left;
    TreeNode* newParent = node->right;
    newParent->left = node;
    node->right = grandchild;

    // // computing node's height and balance factor
    // computeHeightandBalance(node);
    // computeHeightandBalance(newParent);

    return newParent;
}

TreeNode* AvlTree::rotateRight(TreeNode* node) {
    std::cout << "performing right rotate" << std::endl;
    TreeNode* grandchild = node->left->right;
    TreeNode* newParent = node->left;
    newParent->right = node;
    node->left = grandchild;

    // // computing node's height and balance factor
    // computeHeightandBalance(node);
    // computeHeightandBalance(newParent);

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



TreeNode* AvlTree::insertHelper(TreeNode* root, std::string name, std::string id) {

    if (!root) {
        std::cout << "successful" << std::endl;
        return new TreeNode(name, id);
    }

    // inserting node
    if (id < root->id)
        root->left = insertHelper(root->left, name, id);
    else if (id > root->id)  
        root->right = insertHelper(root->right, name, id);
    else {
        std::cout << "unsuccessful" << std::endl;
        return root;
    }
        

    // computing node's height and balance factor
    computeHeightandBalance(root);


    // =====================
    // TODO: insertion is correct until self balancing portion

    // balancing tree if necessary
    // do epic rotations here!
    // we'll have to recalculate the balance factors here again
    
    // if (root->balanceFactor == 2) {
    //     if (root->left->balanceFactor == 1)
    //         return rotateRight(root);
    //     else    
    //         return rotateLeftRight(root);
    // }
        
    // else if (root->balanceFactor == -2) {
    //     if (root->right->balanceFactor == -1)
    //         return rotateLeft(root);
    //     else 
    //         return rotateRightLeft(root);
    // }
        

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


void AvlTree::insert(std::string name, std::string id) {

    // if id is not 8 digits
    if (id.length() != 8) {
        std::cout << "unsuccessful" << std::endl;
        return;
    }

    // if tree is empty
    if (!root) {
        root = new TreeNode(name, id);
        std::cout << "successful" << std::endl;
        return;
    }

    insertHelper(root, name, id);
}














void AvlTree::searchIdHelper(TreeNode* root, std::string id) {

    if (!root) 
        std::cout << "unsuccessful" << std::endl;
    else if (id == root->id)
        std::cout << root->name << std::endl;
    else if (id < root->id)
        searchIdHelper(root->left, id);
    else
        searchIdHelper(root->right, id);
}

void AvlTree::searchId(std::string id) {
    searchIdHelper(root, id);
}




// void AvlTree::searchName(std::string name) {

//     std::queue<TreeNode*> q;
//     if (root) q.push(root);
//     std::string output = "";

//     while (!q.empty()) {

//         int size = q.size();
        
//         for (int i = 0; i < size; i++) {

//             TreeNode* curr = q.front();
//             if (curr->name == name)
//                 output += curr->id + " ";

//             if (curr->left) q.push(curr->left);
//             if (curr->right) q.push(curr->right);
//             q.pop();
//         }   
//     }

//     if (output == "")
//         std::cout << "unsuccessful" << std::endl;
//     else 
//         std::cout << output << std::endl;
// }


void AvlTree::searchNameHelper(TreeNode* node, std::string name) {

    if (node) {
        if (node->name == name)
            std::cout << node->id << std::endl;
        
        searchNameHelper(node->left, name);
        searchNameHelper(node->right, name);
    }

    // TODO: does NOT print "unsuccessful if cannot be found"
}

void AvlTree::searchName(std::string name) {
    searchNameHelper(root, name);
}



void AvlTree::inorderHelper(TreeNode* root) {

    if (root) {
        inorderHelper(root->left);
        std::cout << root->name << ", ";
        inorderHelper(root->right);
    }
}

void AvlTree::printInorder() {
    inorderHelper(root);
    std::cout << std::endl;
}


void AvlTree::preorderHelper(TreeNode* root) {

    if (root) {
        std::cout << root->name << ", ";
        preorderHelper(root->left);
        preorderHelper(root->right);
    }
}

void AvlTree::printPreorder() {
    preorderHelper(root);
    std::cout << std::endl;
}


void AvlTree::postorderHelper(TreeNode* root) {

    if (root) {
        postorderHelper(root->left);
        postorderHelper(root->right);
        std::cout << root->name << ", ";
    }
}

void AvlTree::printPostorder() {
    postorderHelper(root);
    std::cout << std::endl;
}


void AvlTree::printLevelCount() {

    if (!root)
        std::cout << 0 << std::endl;
    else 
        std::cout << root->height + 1 << std::endl;
}