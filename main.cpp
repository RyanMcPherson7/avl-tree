#include "avl-tree.h"
#include <iostream>

int main() {

    AvlTree tree;

    string numCommands;
    getline(cin, numCommands);

    for (int i = 0; i < stoi(numCommands); i++) {

        string command;
        getline(cin, command);

        // checking input command and running operation
        if (command.find("insert") != -1) {

            // extracting data from command
            int spaceIndex = command.find(" ");
            command = command.substr(spaceIndex + 2, command.length() - 1);
            int quoteIndex = command.find("\"");
            string studentName = command.substr(0, quoteIndex);
            string studentId = command.substr(quoteIndex + 2);

            cout << studentId << endl;


        }
        else 
            cout << "invalid command" << endl;
    }




    // for (int i = 8; i > 0; i--) 
    //     tree.insert("name", "0000000" + to_string(i));

    // tree.insert("1", "00000001");
    // tree.insert("22", "00000022");
    // tree.insert("4", "00000004");
    // tree.insert("62", "00000062");
    // tree.insert("97", "00000097");
    // tree.insert("7", "00000007");
    // tree.insert("98", "00000098");
    // tree.insert("18", "00000018");
    // tree.insert("19", "00000019");

    // tree.printLevelCount();

    return 0;
}