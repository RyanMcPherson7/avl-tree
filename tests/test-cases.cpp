#include "../src/avl-tree.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

AvlTree tree;

TEST_CASE( "Testing Balancing", "[level-count]" ) {

    string name = "Ryan";
    string id = "12341234";
    tree.insert(name, id);
    

    REQUIRE(tree.printLevelCount() == 1);
}
