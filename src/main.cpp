#include "avl-tree.hpp"

#define NC "\e[0m"
#define CYN "\e[0;36m"

int main() {

    AvlTree tree;

    string numCommands;
    cout << CYN "# of queries: ";
    getline(cin, numCommands);

    // checking each command and executing functions
    for (int i = 0; i < stoi(numCommands); i++) {

        string command;
        getline(cin, command);

        if (command.find("insert") == 0) {
            string studentName = parseQuotes(command);
            string studentId = command.substr(command.find("\"") + 2);
            tree.insert(studentName, studentId);
        }
        else if (command.find("remove") == 0) {

            if (command.find("removeInorder") == 0) {
                string index = parseNoQuotes(command);
                tree.removeInorder(stoi(index));
            }
            else {
                string studentId = parseNoQuotes(command);
                tree.remove(studentId);
            }
        }
        else if (command.find("search") == 0) {

            if (command.find("\"") != -1) {
                string studentName = parseQuotes(command);
                tree.searchName(studentName);                
            }
            else {
                string studentId = parseNoQuotes(command);
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

    cout << NC;

    return 0;
}