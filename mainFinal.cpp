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



// recalibrates node's height and balance factor
void AvlTree::computeHeightandBalance(TreeNode* node) {

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



TreeNode* AvlTree::insertHelper(TreeNode* node, string& name, string& id) {

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


void AvlTree::insert(string& name, string& id) {

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




TreeNode* AvlTree::removeHelper(TreeNode* node, string& id) {

    if (!node) {
        cout << "unsuccessful" << endl;
        return nullptr;
    }
        
    else if (stoi(id) < stoi(node->id))
        node->left = removeHelper(node->left, id);

    else if (stoi(id) > stoi(node->id))
        node->right = removeHelper(node->right, id);

    // matching node found
    else if (stoi(id) == stoi(node->id)) {
        
        cout << "successful" << endl;

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
            
            // if we removed the root node
            if (node == root) 
                root = replacement;

            delete node;
            
            computeHeightandBalance(replacement);
            return replacement;
        }

        
    }
    // matching node not found
    else {
        cout << "unsuccessful" << endl;
        return nullptr;
    }


    computeHeightandBalance(node);
    return node;
}


void AvlTree::remove(string& id) {
    removeHelper(root, id);
}




void AvlTree::searchIdHelper(TreeNode* node, string& id) {

    if (!node) 
        cout << "unsuccessful" << endl;
    else if (stoi(id) == stoi(node->id))
        cout << node->name << endl;
    else if (stoi(id) < stoi(node->id))
        searchIdHelper(node->left, id);
    else
        searchIdHelper(node->right, id);
}

void AvlTree::searchId(string& id) {
    searchIdHelper(root, id);
}


void AvlTree::searchNameHelper(TreeNode* node, string& name, string& output) {

    if (node) {
        if (node->name == name)
            output += node->id + "\n";
        
        searchNameHelper(node->left, name, output);
        searchNameHelper(node->right, name, output);
    }
}

void AvlTree::searchName(string& name) {

    string output = "";
    searchNameHelper(root, name, output);

    if (output == "")
        cout << "unsuccessful" << endl;
    else 
        cout << output;
}



void AvlTree::inorderHelper(TreeNode* node, string& output) {

    if (node) {
        inorderHelper(node->left, output);
        output +=  node->name + ", ";
        inorderHelper(node->right, output);
    }
}

void AvlTree::printInorder() {

    string output = "";
    inorderHelper(root, output);
    
    if (output.length() != 0)
        cout << output.substr(0, output.length() - 2) << endl;
}


void AvlTree::preorderHelper(TreeNode* node, string& output) {

    if (node) {
        output += node->name + ", ";
        preorderHelper(node->left, output);
        preorderHelper(node->right, output);
    }
}

void AvlTree::printPreorder() {
    string output = "";
    preorderHelper(root, output);

    if (output.length() != 0)
        cout << output.substr(0, output.length() - 2) << endl;
}


void AvlTree::postorderHelper(TreeNode* node, string& output) {

    if (node) {
        postorderHelper(node->left, output);
        postorderHelper(node->right, output);
        output += node->name + ", ";
    }
}

void AvlTree::printPostorder() {
    string output = "";
    postorderHelper(root, output);

    if (output.length() != 0)
        cout << output.substr(0, output.length() - 2) << endl;
}


void AvlTree::printLevelCount() {

    if (!root)
        cout << 0 << endl;
    else 
        cout << root->height << endl;
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
        cout << "unsuccessful" << endl;
    else
        remove(output.at(n));
}


int main() {

    AvlTree tree;

    string numCommands;
    getline(cin, numCommands);

    // checking each command and executing functions
    for (int i = 0; i < stoi(numCommands); i++) {

        string command;
        getline(cin, command);

        // insert command
        if (command.find("insert") == 0) {

            // extracting data from command
            int spaceIndex = command.find(" ");
            command = command.substr(spaceIndex + 2, command.length() - 1);
            int quoteIndex = command.find("\"");
            string studentName = command.substr(0, quoteIndex);
            string studentId = command.substr(quoteIndex + 2);

            tree.insert(studentName, studentId);

        }
        else if (command.find("remove") == 0) {

            // removeInorder command
            if (command.find("removeInorder") == 0) {
                int spaceIndex = command.find(" ");
                string index = command.substr(spaceIndex + 1, command.length() - 1);

                tree.removeInorder(stoi(index));
            }
            // remove command
            else {
                int spaceIndex = command.find(" ");
                string studentId = command.substr(spaceIndex + 1, command.length() - 1);

                tree.remove(studentId);
            }
        }
        else if (command.find("search") == 0) {

            // search name command
            if (command.find("\"") != -1) {
                int spaceIndex = command.find(" ");
                command = command.substr(spaceIndex + 2, command.length() - 1);
                int quoteIndex = command.find("\"");
                string studentName = command.substr(0, quoteIndex);

                tree.searchName(studentName);                
            }
            // search id command
            else {
                int spaceIndex = command.find(" ");
                string studentId = command.substr(spaceIndex + 1, command.length() - 1);

                tree.searchId(studentId);
            }
        }
        else if (command.find("printInorder") == 0) 
            tree.printInorder();
        else if (command.find("printPreorder") == 0)
            tree.printPreorder();
        else if (command.find("printPostorder") == 0)
            tree.printPostorder();
        else if (command.find("printLevelCount") == 0)
            tree.printLevelCount();
        else 
            cout << "invalid command" << endl;
    }


    return 0;
}