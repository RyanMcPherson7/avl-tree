#include "../src/avl-tree.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE( "Test left rotation", "[Rotation]" ) {

    AvlTree tree;
    tree.insert("Ryan", "11111111");
    tree.insert("Joe", "22222222");
    tree.insert("Sandy", "33333333");
    
    REQUIRE(tree.printLevelCount() == 2);
}

TEST_CASE( "Test right rotation", "[Rotation]" ) {

    AvlTree tree;
    tree.insert("Sandy", "33333333");
    tree.insert("Joe", "22222222");
    tree.insert("Ryan", "11111111");

    REQUIRE(tree.printLevelCount() == 2);
}

TEST_CASE( "Test right left rotation", "[Rotation]" ) {

    AvlTree tree;
    tree.insert("Ryan", "11111111");
    tree.insert("Sandy", "33333333");
    tree.insert("Joe", "22222222");
    
    REQUIRE(tree.printLevelCount() == 2);
}

TEST_CASE( "Test left right rotation", "[Rotation]" ) {

    AvlTree tree;
    tree.insert("Sandy", "33333333");
    tree.insert("Ryan", "11111111");
    tree.insert("Joe", "22222222");
    
    REQUIRE(tree.printLevelCount() == 2);
}

TEST_CASE( "Test 1,000 insertions", "[Insertion]") {

    AvlTree tree;
    for (int i = 10000000; i <= 10001000; i++)
        tree.insert("Ryan", to_string(i));

    REQUIRE(tree.printLevelCount() == 10);
}

TEST_CASE( "Test 10,000 insertions", "[Insertion]") {

    AvlTree tree;
    for (int i = 10000000; i <= 10010000; i++)
        tree.insert("Ryan", to_string(i));

    REQUIRE(tree.printLevelCount() == 14);
}

TEST_CASE( "Test 100,000 insertions", "[Insertion]") {

    AvlTree tree;
    for (int i = 10000000; i <= 10100000; i++)
        tree.insert("Ryan", to_string(i));

    REQUIRE(tree.printLevelCount() == 17);
}

TEST_CASE( "Test base cases", "[Base Case]") {

    AvlTree tree;

    REQUIRE(tree.printInorder() == "");
    REQUIRE(tree.printPreorder() == "");
    REQUIRE(tree.printPostorder() == "");
    REQUIRE(tree.printLevelCount() == 0);
}

TEST_CASE( "Test Inorder", "[Traversal]") {

    AvlTree tree;
    tree.insert("Ryan", "11111111");
    tree.insert("Mihir", "22222222");
    tree.insert("Danny", "33333333");
    tree.insert("Jose", "44444444");

    REQUIRE(tree.printInorder() == "Ryan, Mihir, Danny, Jose");
}

TEST_CASE( "Test Preorder", "[Traversal]") {

    AvlTree tree;
    tree.insert("Ryan", "11111111");
    tree.insert("Mihir", "22222222");
    tree.insert("Danny", "33333333");
    tree.insert("Jose", "44444444");

    REQUIRE(tree.printPreorder() == "Mihir, Ryan, Danny, Jose");
}

TEST_CASE( "Test Postorder", "[Traversal]") {

    AvlTree tree;
    tree.insert("Ryan", "11111111");
    tree.insert("Mihir", "22222222");
    tree.insert("Danny", "33333333");
    tree.insert("Jose", "44444444");

    REQUIRE(tree.printPostorder() == "Ryan, Jose, Danny, Mihir");
}

