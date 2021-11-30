#include "../src/avl-tree.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

AvlTree tree;

TEST_CASE( "Testing Balancing", "[level-count]" ) {

    tree.insert("ryuan", "12341234");
    

    REQUIRE(tree.printLevelCount() == 1);
}
