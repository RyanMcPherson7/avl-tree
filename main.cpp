#include "avl-tree.h"
#include <iostream>

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


    // for (int i = 100; i < 104; i++) {

    //     string name = to_string(i);
    //     string id = "00000" + to_string(i);
    //     tree.insert(name, id);
    // }

    string theName = "Brandon";
    string theKey = "45674567";
    tree.insert(theName, theKey);
    theName = "Brian";
    theKey = "35455565";
    tree.insert(theName, theKey);
    theName = "Briana";
    theKey = "87878787";
    tree.insert(theName, theKey);
    theName = "Bella";
    theKey = "95462138";
    tree.insert(theName, theKey);

    tree.printInorder();
    theKey = "45674567";
    tree.remove(theKey);
    tree.removeInorder(2);
    tree.printInorder();

    return 0;
}