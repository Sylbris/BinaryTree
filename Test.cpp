/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Please write your names here>
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "sources/BinaryTree.hpp"
using namespace ariel;

#include <string>
using namespace std;

TEST_CASE("CHECK STRING TREE") {             

// for(int i=0;i<20;i++){
//     CHECK(true);
// }


//////////////////////////////////////////////////////////////////String tree
BinaryTree<string> tree_of_strings;
CHECK_NOTHROW(tree_of_strings.add_root("1"));     
CHECK_NOTHROW(tree_of_strings.add_left("1", "9"));      // Now 9 is the left child of 1
CHECK_NOTHROW(tree_of_strings.add_left("9", "4"));      // Now 4 is the left child of 9
CHECK_NOTHROW(tree_of_strings.add_right("9", "5"));     // Now 5 is the right child of 9
CHECK_NOTHROW(tree_of_strings.add_right("1", "3"));    // Now 3 is the right child of 1
CHECK_NOTHROW(tree_of_strings.add_left("1", "2"));     // Now 2 is the left child of 1, instead of 9 (the children of 9 remain in place)
//Change root
tree_of_strings.add_root("7");
//CHECK(*(tree_of_strings.begin()) == "7");

std::string tree_str;
for(auto n:tree_of_strings){
    tree_str+= n ;
}
CHECK( tree_str == "42513" );
CHECK( tree_str != "42315");
CHECK( tree_str != "43215");
CHECK( tree_str != "52314");
CHECK( tree_str != "42135");

///////////////////////////////////////////////////////////////////Int tree
BinaryTree<int> tree_of_ints;
CHECK_NOTHROW(tree_of_ints.add_root(1));
CHECK_NOTHROW(tree_of_ints.add_left(1, 9));
CHECK_NOTHROW(tree_of_ints.add_left(9, 4)); 
CHECK_NOTHROW(tree_of_ints.add_right(9, 5));
CHECK_NOTHROW(tree_of_ints.add_right(1, 3));
CHECK_NOTHROW(tree_of_ints.add_left(1, 2));

CHECK_THROWS(tree_of_ints.add_left(6, 2));

//Change root
tree_of_ints.add_root(6);
// CHECK(*(tree_of_strings.begin()) == 6);

//Check adding to a tree without a root.
BinaryTree<int> tree_of_ints_no_root;
CHECK_THROWS(tree_of_ints_no_root.add_left(1, 2));
CHECK_THROWS(tree_of_ints_no_root.add_right(1, 3));



}

